/* -------------------------------------------------------------------- */
/* Mouse++ Version 4.0            mouse.cpp            Revised 10/05/92 */
/*                                                                      */
/* General mouse class for Turbo C++/Borland C++.                       */
/* Copyright 1991, 1992 by Carl W. Moreland                             */
/* -------------------------------------------------------------------- */

#include <dos.h>
#include "mouse.h"

Mouse mouse;
void interrupt RepeatHandler(...);
void interrupt far (*oldInterrupt_1C)(...);

/* -------------------------------------------------------------------- */

Mouse::Mouse(void)			// reset mouse - constructor
{
  int found;
  unsigned seg, off;

  exists  = 0;				// initialize everything
  enabled = 0;
  visible = 0;
  current.button = 0;
  current.x      = 0;
  current.y      = 0;
  current.xcount = 0;
  current.ycount = 0;
  clickThreshold = 250;
  repeatDelay    = 1000;
  repeatRate     = 200;
  handlerInstalled = 0;
  handlerActive = 0;
  current.event = 0x00;
  buffer.Clear();

  _AX = 0x00;				// check for the existance of
  geninterrupt(0x33);			//   a mouse
  found   = _AX;
  buttons = _BX;			// also returns # of buttons

  if(found)
    exists = 1;
  if(!exists) return;

  _ES = 0;
  _DX = 0;
  _CX = 0;				// clear the event handler
  _AX = 0x14;
  geninterrupt(0x33);
  oldHandler.mask    = _CX;		// save the old event handler
  off = _DX;
  seg = _ES;
  oldHandler.offset  = off;
  oldHandler.segment = seg;

  _AX = 0x24;				// get some mouse info
  geninterrupt(0x33);
  Info.majorvers = _BH;
  Info.minorvers = _BL;
  Info.type      = _CH;
  Info.irq       = _CL;

  oldInterrupt_1C = getvect(0x1C);
  setvect(0x1C, RepeatHandler);
}

Mouse::~Mouse(void)			// restore mouse - destructor
{
  if(!exists) return;

  _AX = 0x00;				// reset mouse
  geninterrupt(0x33);

  if(oldHandler.mask)			// restore old event handler
    InstallHandler(oldHandler);

  setvect(0x1C, oldInterrupt_1C);
}

void Mouse::Enable(void)		// enable the mouse
{
  if(!exists || enabled) return;

  if(currentHandler.mask && !handlerInstalled)
    InstallHandler();			// re-install event handler

  enabled = 1;
}

void Mouse::Disable(void)		// disable the mouse
{
  if(!exists || !enabled) return;

  if(handlerInstalled)
  {
    ClearHandler();			// disable the event handler
    ClearClick();			// clear the multi-click buffers
  }
  Hide();				// turn the cursor off
  enabled = 0;
}

void Mouse::Show(void)		    	// show mouse cursor
{
  if(!exists || !enabled) return;
  if(visible) return;

  if(cgcActive)
    cgc->Show();
  else
  {
    _AX = 0x01;
    geninterrupt(0x33);
  }
  visible = 1;
}

void Mouse::Hide(void)			// hide mouse cursor
{
  if(!exists || !enabled) return;
  if(visible < 1) return;

  if(cgcActive)
    cgc->Hide();
  else
  {
    _AX = 0x02;
    geninterrupt(0x33);
  }
  visible = 0;
}

void Mouse::Move(int x, int y)		// move cursor to col, row
{					// col & row are pixel coordinates
  if(!exists || !enabled) return;

  _DX = y;
  _CX = x;
  _AX = 0x04;
  geninterrupt(0x33);
}

void Mouse::xLimit(int min, int max)	// set min/max column range
{					// min & max are pixel coordinates
  if(!exists) return;

  _DX = max;
  _CX = min;
  _AX = 0x07;
  geninterrupt(0x33);
}

void Mouse::yLimit(int min, int max)	// set min/max row range
{					// min & max are pixel coordinates
  if(!exists) return;

  _DX = max;
  _CX = min;
  _AX = 0x08;
  geninterrupt(0x33);
}

void Mouse::xyLimit(int xmin, int xmax, int ymin, int ymax)
{
  xLimit(xmin, xmax);
  yLimit(ymin, ymax);
}

int Mouse::GetVideoPage(void)		// get the cursor's display page
{
  if(!exists) return 0;

  _AX = 0x1E;
  geninterrupt(0x33);
  return _BX;
}

void Mouse::SetVideoPage(int page)	// set the cursor's display page
{
  if(!exists) return;

  _BX = page;
  _AX = 0x1D;
  geninterrupt(0x33);
}

void Mouse::MickToPix(int horiz, int vert)
{                 			// set the mickey to pixel ratio
  if(!exists) return;

  _DX = vert;
  _CX = horiz;
  _AX = 0x0F;
  geninterrupt(0x33);
}

void Mouse::SetSpeedThreshold(unsigned speed)
{					// set speed change threshold
  if(!exists) return;

  _DX = speed;
  _AX = 0x13;
  geninterrupt(0x33);
}

void Mouse::SetCursor(TextCursor& cursor)
{					// change the text cursor
  int wasVisible = 0;

  if(!exists) return;
  if(visible)
  {
    wasVisible = 1;
    Hide();
  }

  _DX = cursor.cMask;
  _CX = cursor.sMask;
  _BX = cursor.type;
  _AX = 0x0A;
  geninterrupt(0x33);
  cgcActive = 0;

  if(wasVisible)
    Show();
}

void Mouse::SetCursor(GraphicsCursor& cursor)
{					// change the graphics cursor
  int wasVisible = 0;

  if(!exists) return;
  if(visible)
  {
    wasVisible = 1;
    Hide();
  }

  if(cursor.type == 0)			// std 16x16 cursor
  {
    _ES = FP_SEG(cursor.cImage);
    _DX = FP_OFF(cursor.cImage);
    _CX = cursor.hoty;
    _BX = cursor.hotx;
    _AX = 0x09;
    geninterrupt(0x33);
  }
  else					// arbitrary cursor size
  {
    _ES = FP_SEG(cursor.cImage);
    _DX = FP_OFF(cursor.cImage);
    _CH = cursor.cHeight;
    _CL = cursor.hoty;
    _BH = cursor.cWords;
    _BL = cursor.hotx;
    _AX = 0x12;
    geninterrupt(0x33);
  }

  gc   = &cursor;
  cgcActive = 0;

  if(handlerInstalled)			// reinstall the current handler
    InstallHandler();

  if(wasVisible)
    Show();
}

void Mouse::SetCursor(ColorGraphicsCursor& cursor)
{
  int wasVisible = 0;

  if(!exists) return;
  if(visible)
  {
    wasVisible = 1;
    Hide();
  }

  cgc  = &cursor;
  cgcActive = 1;

  if(handlerInstalled)			// reinstall the current handler
    InstallHandler();

  if(wasVisible)			// need to get the current coords
  {
    _AX = 0x03;
    geninterrupt(0x33);
    cursor.x = _CX;
    cursor.y = _DX;
    Show();
  }
}

void Mouse::Position(void)		// update cursor position &
{					// button status
  if(!exists || !enabled) return;

  _AX = 0x03;
  geninterrupt(0x33);
  current.button = _BX;
  current.x = _CX;
  current.y = _DX;
}

int Mouse::Pressed(int button)		// check press status of button
{
  if(!exists || !enabled) return(0);

  if(handlerInstalled)
  {
    if(button == LEFTBUTTON)
      return(current.event & LB_PRESSED);
    else if(button == RIGHTBUTTON)
      return(current.event & RB_PRESSED);
    else if(button == CENTERBUTTON)
      return(current.event & CB_PRESSED);
  }

  _BX = button;
  _AX = 0x05;
  geninterrupt(0x33);
  current.button = _AX;
  int BX = _BX;
  if(BX)
  {
    current.x = _CX;
    current.y = _DX;
  }
  return(BX);
}

int Mouse::Released(int button)		// check release status of button
{
  if(!exists || !enabled) return(0);

  if(handlerInstalled)
  {
    if(button == LEFTBUTTON)
      return(current.event & LB_RELEASED);
    else if(button == RIGHTBUTTON)
      return(current.event & RB_RELEASED);
    else if(button == CENTERBUTTON)
      return(current.event & CB_RELEASED);
  }

  _AX = 0x06;
  _BX = button;
  geninterrupt(0x33);
  current.button = _AX;
  int BX = _BX;
  if(BX)
  {
    current.x = _CX;
    current.y = _DX;
  }
  return(BX);
}

void Mouse::Motion(void)		// get # of mickeys moved
{
  if(!exists || !enabled) return;

  _AX = 0x0B;
  geninterrupt(0x33);
  current.xcount = _CX;
  current.ycount = _DX;
}

int Mouse::InBox(int left,  int top,	// see if mouse is in a box
                 int right, int bottom)
{
  if(!exists || !enabled) return(0);

  if((current.x >= left)  && (current.y >= top) &&
     (current.x <= right) && (current.y <= bottom))
    return(1);
  return(0);
}

void Mouse::Exclude(int left,  int top,	// set up exclusion area
                    int right, int bottom)
{
  static unsigned char hotx, hoty, height, width;

  if(!exists || !enabled) return;

  if(cgcActive)
  {
    hotx   = cgc->hotx;
    hoty   = cgc->hoty;
    height = cgc->cHeight - 1;
    width  = cgc->cWidth  - 1;
  }
  else
  {
    hotx   = gc->hotx;
    hoty   = gc->hoty;
    height = gc->cHeight - 1;
    width  = gc->cWidth  - 1;
  }

  if((current.x >= (left-width+hotx)) && (current.y >= (top-height+hoty)) &&
     (current.x <= (right+hotx)) && (current.y <= (bottom+hoty)))
    Hide();
  else
    Show();
}

void Mouse::SetClickThreshold(unsigned time)
{
  clickThreshold = time;		// time is in milliseconds
}

int Mouse::MultiClick(int button)	// check for multiple clicks
{
  if(!exists || !enabled) return(0);

  return Click[button >> 1].count;
}

int Mouse::DoubleClick(int button)     // check for double clicks
{
  if(!exists || !enabled) return(0);

  return (Click[button >> 1].count == 2);
}

void Mouse::ClearClick(int button)	// clear the MultiClick buffer
{					//   button = 7 is the default
  if(!exists || !enabled) return;	//   which clears all the buttons

  if(button & LEFTBUTTON)
    Click[0].count = 0;
  if(button & RIGHTBUTTON)
    Click[1].count = 0;
  if(button & CENTERBUTTON)
    Click[2].count = 0;
}

/* ----- Event Handler routines --------------------------------------- */

void interrupt MouseHandler(void)	// default event handler
{
  mouse.Save(_AX,_BX,_CX,_DX,_DI,_SI);  // save the normal stuff
  EventExit();				// required for interrupt function
}

void Mouse::InstallHandler(void)
{
  unsigned seg, off;

  if(!exists) return;

  unsigned char mask = currentHandler.mask;
  if(cgcActive)
    mask |= MOUSE_MOVED;		// ColorGraphicsCursors require this

  seg = currentHandler.segment;
  off = currentHandler.offset;
  _ES = seg;
  _DX = off;
  _CX = mask;
  _AX = 0x14;
  geninterrupt(0x33);

  handlerInstalled = 1;
  buffer.Clear();
}

void Mouse::InstallHandler(unsigned char mask,
                           void interrupt (*handler)(void))
{
  if(!exists) return;

  currentHandler.mask    = mask;
  currentHandler.segment = FP_SEG(handler);
  currentHandler.offset  = FP_OFF(handler);

  InstallHandler();
}

void Mouse::InstallHandler(MouseEventHandler& handler)
{					// install an event handler
  currentHandler = handler;
  InstallHandler();
}

void Mouse::ClearHandler(void)		// clear the event handler
{
  if(!exists) return;

  _ES = 0;
  _DX = 0;
  _CX = 0;
  _AX = 0x14;
  geninterrupt(0x33);

  handlerInstalled = 0;
  buffer.Clear();
}
					// save an event to the buffer
void Mouse::Save(int event, int button,
                 int x, int y, int xcount, int ycount)
{
  static unsigned char keymask;
  static unsigned long time;

  if(cgcActive && (event & MOUSE_MOVED))
  {
    cgc->x = x;
    cgc->y = y;

    if(visible)
      cgc->Move();

    if(!(currentHandler.mask & MOUSE_MOVED))
      return;
  }

  if(buffer.IsFull())
    return;

  if(event & MB_PRESSED)
  {
    time = *(unsigned long far *)MK_FP(0x0040, 0x006C)*55;
    keymask = *(char far *)MK_FP(0x0040, 0x0017);

    button += (keymask << 4);
    if(keymask & 0x03)
      button += 0x08;

    if(event & LB_PRESSED)
    {
      Repeat[0].count = 0;
      Repeat[0].time  = time;
    }
    if(event & RB_PRESSED)
    {
      Repeat[1].count = 0;
      Repeat[1].time  = time;
    }
    if(event & CB_PRESSED)
    {
      Repeat[2].count = 0;
      Repeat[2].time  = time;
    }
  }
  else
    time = 0;				// no button press so time not needed

  buffer.PutEvent(event, button, x, y, xcount, ycount, time);
}

void Mouse::GetEvent(void)		// get an event from the buffer
{
  if(!exists || !enabled) return;

  if(buffer.HasEvent())			// if an event is available...
  {
    current = buffer.GetEvent();

    if(current.time)			// store info for MultiClick()
    {
      if(current.event & LB_PRESSED)
      {
        if((current.time - Click[0].time) < clickThreshold)
          Click[0].count++;
        else
          Click[0].count = 1;

        Click[0].time = current.time;
      }
      if(current.event & RB_PRESSED)
      {
        if((current.time - Click[1].time) < clickThreshold)
          Click[1].count++;
        else
          Click[1].count = 1;

        Click[1].time = current.time;
      }
      if(current.event & CB_PRESSED)
      {
        if((current.time - Click[2].time) < clickThreshold)
          Click[2].count++;
        else
          Click[2].count = 1;

        Click[2].time = current.time;
      }
    }
  }
  else
  {
    current.event  = 0;
    current.xcount = 0;
    current.ycount = 0;
  }
}

void Mouse::ClearEvent(void)		// clear the current event
{
  current.event  = 0;
  current.button = 0;
  current.x      = 0;
  current.y      = 0;
  current.xcount = 0;
  current.ycount = 0;
}

void Mouse::ClearBuffer(void)		// clear the event buffer
{
  buffer.Clear();
}

/* ----- Repeater routines -------------------------------------------- */

void interrupt RepeatHandler(...)
{
  (*oldInterrupt_1C)();
  mouse.Repeater();
}

void Mouse::Repeater(void)
{
  static int x, y;
  static unsigned char event, button, mbutton, keymask;
  static long time, dtime;

  if(repeatRate == 0)			// repeat feature is off
    return;
  if(buffer.IsFull())
    return;

  time = *(long far *)MK_FP(0x0040, 0x006C)*55;

  _AX = 0x03;				// get the current mouse position
  geninterrupt(0x33);			//  & button status
  button = _BL;
  x = _CX;
  y = _DX;

  if(button & LEFTBUTTON & repeatMask)
  {
    mbutton = 0;
    event = LB_PRESSED;
  }
  else if(button & RIGHTBUTTON & repeatMask)
  {
    mbutton = 1;
    event = RB_PRESSED;
  }
  else if(button & CENTERBUTTON & repeatMask)
  {
    mbutton = 2;
    event = CB_PRESSED;
  }
  else
    return;

  dtime = time - Repeat[mbutton].time;	// time since the last repeat

  if((!Repeat[mbutton].count && (dtime >= repeatDelay)) ||
      (Repeat[mbutton].count && (dtime >= repeatRate)))
  {
    keymask = *(char far *)MK_FP(0x0040, 0x0017);

    button += (keymask << 4);		// add it to the button mask
    if(keymask & 0x03)
      button += 0x08;

    buffer.PutEvent(event, button, x, y, 0, 0, time);

    Repeat[mbutton].count++;		// increment the click count
    Repeat[mbutton].time = time;
  }
}

void Mouse::SetRepeatRate(unsigned char button,
                          unsigned delay, unsigned rate)
{
  repeatMask  = button;
  repeatDelay = delay;
  repeatRate  = rate;
}

/* ----- EventBuffer methods ------------------------------------------ */

int EventBuffer::IsFull(void)
{
  if(headPtr == tailPtr-1)
    return 1;
  if(headPtr == MOUSE_BUFFER_SIZE-1 && tailPtr == 0)
    return 1;
  return 0;
}

int EventBuffer::HasEvent(void)
{
  return (headPtr != tailPtr);
}

void EventBuffer::PutEvent(unsigned char event, unsigned char button,
                           unsigned x, unsigned y,
	                   unsigned xcount, unsigned ycount,
		           unsigned long time)
{
  buffer[headPtr].event  = event;	// store the info in the event buffer
  buffer[headPtr].button = button;
  buffer[headPtr].x      = x;
  buffer[headPtr].y      = y;
  buffer[headPtr].xcount = xcount;
  buffer[headPtr].ycount = ycount;
  buffer[headPtr].time   = time;

  if(++headPtr >= MOUSE_BUFFER_SIZE)	// increment the head ptr
    headPtr = 0;
}

MouseEvent EventBuffer::GetEvent(void)
{
  MouseEvent event = buffer[tailPtr];

  if(++tailPtr >= MOUSE_BUFFER_SIZE)
    tailPtr = 0;

  return event;
}

void EventBuffer::Clear(void)
{
  headPtr = 0;
  tailPtr = 0;
}

/* ----- MouseEventHandler methods ------------------------------------ */

MouseEventHandler::MouseEventHandler(void)
{
  mask = 0;
  segment = 0;
  offset  = 0;
}

MouseEventHandler::MouseEventHandler(unsigned char mask,
                                     void interrupt (*handler)(void))
{
  this->mask = mask;
  segment = FP_SEG(handler);
  offset  = FP_OFF(handler);
}

void MouseEventHandler::Install(void)
{
  mouse.InstallHandler(*this);
}

/* ----- Cursor constructors ------------------------------------------ */

TextCursor::TextCursor(unsigned sMask, unsigned cMask, int type)
{
  this->sMask = sMask;
  this->cMask = cMask;
  this->type  = type;
}

GraphicsCursor::GraphicsCursor(unsigned char hotx, unsigned char hoty,
                               unsigned image[],
                               unsigned char width, unsigned char height,
                               unsigned char type)
{
  cImage     = image;
  this->hotx = hotx;
  this->hoty = hoty;
  cWidth     = width;
  cHeight    = height;
  cWords     = width/16 + (width%16 ? 1 : 0);
  this->type = type;
}

