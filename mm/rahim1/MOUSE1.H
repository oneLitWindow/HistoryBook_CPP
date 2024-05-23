/* -------------------------------------------------------------------- */
/* Mouse++ Version 4.0             mouse.h             Revised 10/05/92 */
/*                                                                      */
/* General mouse class for Turbo C++/Borland C++.                       */
/* Copyright 1991, 1992 by Carl W. Moreland                             */
/* -------------------------------------------------------------------- */

#ifndef MOUSEdotH
#define MOUSEdotH

const unsigned char MOUSE_BUFFER_SIZE = 8;

const unsigned char LEFTBUTTON   = 1;	// mouse button assignments
const unsigned char RIGHTBUTTON  = 2;
const unsigned char CENTERBUTTON = 4;

const unsigned char CURSORSOFT = 0;	// used in struct TextCursor
const unsigned char CURSORHARD = 1;

const unsigned char MOUSE_MOVED = 0x01;	// event masks for event handler
const unsigned char LB_PRESSED  = 0x02;
const unsigned char LB_RELEASED = 0x04;
const unsigned char RB_PRESSED  = 0x08;
const unsigned char RB_RELEASED = 0x10;
const unsigned char CB_PRESSED  = 0x20;
const unsigned char CB_RELEASED = 0x40;

const unsigned char LB_EVENT    = 0x06;
const unsigned char RB_EVENT    = 0x18;
const unsigned char CB_EVENT    = 0x60;
const unsigned char MB_PRESSED  = 0x2A;
const unsigned char MB_RELEASED = 0x54;
const unsigned char MB_EVENT    = 0x7E;

const unsigned char SHIFT_PRESSED  = 0x08; // key shift masks
const unsigned char RSHIFT_PRESSED = 0x10;
const unsigned char LSHIFT_PRESSED = 0x20;
const unsigned char CTRL_PRESSED   = 0x40;
const unsigned char ALT_PRESSED    = 0x80;

#define EventExit() __emit__(0x5D,	/* pop bp */ \
			     0x5F,	/* pop di */ \
                             0x5E,	/* pop si */ \
                             0x1F,	/* pop ds */ \
                             0x07,	/* pop es */ \
                             0x5A,	/* pop dx */ \
                             0x59,	/* pop cx */ \
                             0x5B,	/* pop bx */ \
                             0x58,	/* pop ax */ \
                             0xCB);	/* retf   */

class Mouse;
void far interrupt MouseHandler(void);

/* -------------------------------------------------------------------- */

class TextCursor
{
  unsigned char type;			// hard or soft cursor
  unsigned sMask, cMask;		// screen and cursor masks

public:
  TextCursor(unsigned sMask, unsigned cMask, int type=0);
  friend Mouse;
};					// see cursor.h for predefined cursors

/* -------------------------------------------------------------------- */

class GraphicsCursor
{
  unsigned char hotx, hoty;     	// hot spot; (0,0) = top left corner
  unsigned *cImage;              	// 16 x 16 pixel screen & cursor masks
  unsigned char cWidth, cHeight;	// image dimensions in pixels
  unsigned char cWords;			// cursor width (words)
  unsigned char type;			// 0 = normal size, 1 = arbitrary size

public:
  GraphicsCursor(unsigned char hotx, unsigned char hoty,
                 unsigned image[],
                 unsigned char width, unsigned char height,
                 unsigned char type=0);
  friend Mouse;
};					// see cursor.h for predefined cursors

/* -------------------------------------------------------------------- */

class ColorGraphicsCursor
{
  static void *tmpImage;		// temp storage for video
  static int tmpImageSize;		// size of temp storage
  static int x, y;			// current cursor location
  static unsigned char *videoAddress;   // video location of image
  static int  videoLeftMask,  videoRightMask;
  static int screenLeftMask, screenRightMask;
  static unsigned char xStart, yStart, xEnd, yEnd;
  static unsigned char iWidth, iHeight;	// image dimensions (bytes*pixels)

  unsigned char hotx, hoty;     	// hot spot; (0,0) = topleft corner
  void *cImage; 		  	// n x m pixel cursor mask
  void *cMask;				// n x m pixel screen mask
  unsigned char cWidth, cHeight;	// cursor dimensions (pixels)
  unsigned char cBytes;			// cursor width (bytes)

  void Hide(void)
  {
    if(x == -1) return;
    VideoWrite();
  }
  void Show(void)
  {
    if(x == -1) return;
    VideoRead();
    CursorWrite();
  }
  void Move(void)
  {
    if(x != -1) VideoWrite();
    VideoRead();
    CursorWrite();
  }
  void VideoRead(void);
  void VideoWrite(void);
  void CursorWrite(void);

public:
  ColorGraphicsCursor(unsigned char hotx, unsigned char hoty,
                      unsigned char image[],
                      unsigned char width=16, unsigned char height=16);
  friend Mouse;
};					// see cursor.h for predefined cursors

/* -------------------------------------------------------------------- */

class MouseEventHandler			// structure to store handlers
{
  unsigned char mask;			// event mask
  unsigned segment, offset;		// address of event handler

public:
  MouseEventHandler(void);
  MouseEventHandler(unsigned char mask,
                    void interrupt (*handler)(void) = MouseHandler);
  void Install(void);

  friend Mouse;
};

/* -------------------------------------------------------------------- */

struct MouseEvent
{
  unsigned char event;			// trigger event
  unsigned char button;			// button status
  unsigned x, y;			// cursor coordinates
  unsigned xcount, ycount;		// mickeys moved since last event
  unsigned long time;			// time event occurred
};

class EventBuffer			// event buffer structure
{
  unsigned char headPtr;		// buffer pointer
  unsigned char tailPtr;		// buffer pointer
  MouseEvent buffer[MOUSE_BUFFER_SIZE];

public:
  int  IsFull(void);
  int  HasEvent(void);
  void Clear(void);
  void PutEvent(unsigned char event, unsigned char button,
                unsigned x, unsigned y,
                unsigned xcount, unsigned ycount,
		unsigned long time);
  MouseEvent GetEvent(void);
};

class Mouse
{
  unsigned char exists;			// 1 if mouse found, 0 if not
  unsigned char enabled;		// 1 if mouse enabled, 0 if not
  unsigned char visible;		// keeps track of Hide() & Show()
  unsigned char buttons; 		// number of buttons
  GraphicsCursor *gc;			// current graphics cursor
  ColorGraphicsCursor *cgc;		// current color graphics cursor
  unsigned char cgcActive;		// color graphics cursor flag

  MouseEvent current;			// current event info
  EventBuffer buffer;			// event buffer
  MouseEventHandler oldHandler;		// handler found at start-up
  MouseEventHandler currentHandler;	// current event handler
  unsigned char handlerInstalled;	// event handler flag
  unsigned char handlerActive;		// event handler active flag

  struct MouseClick			// MultiClick/Repeater structure
  {
    unsigned char count;		// number of clicks
    unsigned long time;			// time of last click
  } Click[3], Repeat[3];

  unsigned clickThreshold;		// MultiClick threshold
  unsigned char repeatMask;		// button mask for Repeater
  unsigned repeatDelay;			// delay time for Repeater
  unsigned repeatRate;			// repeat rate for Repeater

  friend EventBuffer;

public:
  Mouse(void);
 ~Mouse(void);

  unsigned char Exists()  { return exists;  }
  unsigned char Visible() { return visible; }
  unsigned char Buttons() { return buttons; }

  int  x()	    	  { return current.x; }
  int  y() 		  { return current.y; }
  int  xPos()    	  { return current.x; }
  int  yPos() 		  { return current.y; }
  int  xCount()  	  { return current.xcount; }
  int  yCount()  	  { return current.ycount; }
  unsigned char Button()  { return current.button; }
  unsigned char LB_Dn()   { return (0x01 & current.button); }
  unsigned char RB_Dn()   { return (0x02 & current.button); }
  unsigned char CB_Dn()   { return (0x04 & current.button); }
  unsigned char Event()   { return current.event; }

  void Enable(void);
  void Disable(void);
  void Show(void);
  void Hide(void);
  void Move(int x, int y);
  void Position(void);
  void Motion(void);
  int  Pressed(int button);
  int  Released(int button);
  int  InBox(int left, int top, int right, int bottom);
  void Exclude(int left, int top, int right, int bottom);
  int  MultiClick(int button);
  int  DoubleClick(int button);
  void ClearClick(int button = 7);

  void xLimit(int min, int max);
  void yLimit(int min, int max);
  void xyLimit(int xmin, int xmax, int ymin, int ymax);
  void MickToPix(int horiz, int vert);
  int  GetVideoPage(void);
  void SetVideoPage(int page);

  void SetCursor(TextCursor& cursor);
  void SetCursor(GraphicsCursor& cursor);
  void SetCursor(ColorGraphicsCursor& cursor);

  void SetSpeedThreshold(unsigned speed);
  void SetClickThreshold(unsigned time);
  void SetRepeatRate(unsigned char button=LEFTBUTTON,
                     unsigned delay=250, unsigned rate=150);
  void Repeater(void);

  void InstallHandler(void);
  void InstallHandler(unsigned char mask,
                      void interrupt (*handler)(void) = MouseHandler);
  void InstallHandler(MouseEventHandler& handler);
  void ClearHandler(void);
  void Save(int event, int button, int x, int y, int xcount, int ycount);
  void GetEvent(void);
  void ClearEvent(void);
  void ClearBuffer(void);

  struct MouseInfo		// structure to store mouse data
  {
    unsigned char type;		// bus=1, serial=2, InPort=3, PS/2=4, HP=5
    unsigned char majorvers;	// software major version
    unsigned char minorvers;	// software minor version
    unsigned char irq;		// IRQ used (2-7), 0 for PS/2
  } Info;
};

extern Mouse mouse;

#endif