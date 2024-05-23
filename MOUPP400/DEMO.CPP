/* -------------------------------------------------------------------- */
/* Mouse++ Version 4.0             demo.cpp            Revised 10/05/92 */
/*                                                                      */
/* General mouse class for Turbo C++/Borland C++.                       */
/* Copyright 1991, 1992 by Carl W. Moreland                             */
/* -------------------------------------------------------------------- */
/* Demonstration of Mouse++ in text mode and graphics mode.             */
/* -------------------------------------------------------------------- */

#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include "mouse.h"
#include "cursor.h"

void textdemo(void);
int  textscreen(void);
void alttextscreen(void);
void nexttdemo(char *);
void graphicdemo(void);
int  graphicscreen(void);
void nextgdemo(char *);

int maxx, maxy;
int text_width, text_height;
struct text_info t_info;
int done = 0;

MouseEventHandler myHandler(MB_PRESSED|MB_RELEASED, MouseHandler);

main()
{
  if(mouse.Exists())	    		// check for mouse
  {
    mouse.InstallHandler(0xFF);		// install event handler
    mouse.Enable();			// enable mouse
    textdemo();				// run text mode demo

    mouse.SetRepeatRate(CENTERBUTTON,	// set the center button to repeat
                        500, 200);
    graphicdemo();			// run graphics mode demo
    return(0);				// normal termination
  }
  return(1);				// abnormal termination
}

/* ----- text mode demo ----------------------------------------------- */

void textdemo()				// main routine for text mode demo
{
  textmode(C80);			// 80x25 color text mode
  if(textscreen() == 0)			// draw the screen
  {
    alttextscreen();			// draw the alt screen
    textcolor(13);
    gotoxy(1,3);

    if(mouse.Info.type == 1) cprintf(" Bus mouse found\n");
    if(mouse.Info.type == 2) cprintf(" Serial mouse found\n");
    if(mouse.Info.type == 3) cprintf(" InPort mouse found\n");
    if(mouse.Info.type == 4) cprintf(" PS/2 mouse found\n");
    if(mouse.Info.type == 5) cprintf(" HP mouse found\n");
    gotoxy(1,4);
    cprintf(" Software version is %d.%d\n", (int)mouse.Info.majorvers,
    	      (int)mouse.Info.minorvers);

    mouse.yLimit(0, 199);		// set y limit
    mouse.Show();			// initial turn-on

    if(!done) { mouse.SetCursor(tdef); nexttdemo("     Default Cursor      "); }
    if(!done) { mouse.SetCursor(txt1); nexttdemo(" 0000h 0E0Fh Soft Cursor "); }
    if(!done) { mouse.SetCursor(txt2); nexttdemo(" 7000h 0E0Fh Soft Cursor "); }
    if(!done) { mouse.SetCursor(txt3); nexttdemo(" 7F00h FF0Fh Soft Cursor "); }
    mouse.xLimit(16, 623);
    if(!done) { mouse.SetCursor(txt4); nexttdemo(" 00FFh 0FD4h Soft Cursor "); }

    mouse.Hide();
    textmode(C4350);			// 43/50 line mode
    _setcursortype(_NOCURSOR);		// turn the hardware cursor off
    mouse.xLimit(0, 639);		// set x limit
    gettextinfo(&t_info);
    if(t_info.screenheight == 43)
      mouse.yLimit(0, 349);		// set y limit to EGA 43 line
    else
      mouse.yLimit(0, 399);		// set y limit to VGA 50 line
    mouse.Show();
    if(!done) { mouse.SetCursor(txt4); nexttdemo("     Default Cursor      "); }
  }
}

int textscreen(void)			// draws screen for demo
{
  register int i, j;
  char far *video = (char far *)MK_FP(0xB800, 0x0000);

  _setcursortype(_NOCURSOR);		// turn the hardware cursor off

  for(i=0; i<50; i++)			// draw the text screen background
  {
    for(j=0; j<80; j++)
    {
      *video++ = 0xDB+2*(j/10);		// write the character to video memory
      *video++ = 16*(j/10)+j/10+1;	// write the color
    }
  }

  gotoxy(27,1);
  textattr(4);
  cprintf(" Text Mode Demonstration ");

  textattr(LIGHTGRAY);
  for(i=5; i<13; i++)
  {
    gotoxy(5, i);
    cprintf("лллллллллл");
  }
  textattr(DARKGRAY);
  for(i=6; i<8; i++)
  {
    gotoxy(6, i);
    cprintf("лл");
    gotoxy(9, i);
    cprintf("лл");
    gotoxy(12, i);
    cprintf("лл");
  }
  textattr(WHITE);
  gotoxy(6,9);
  cprintf("Position");

  textattr(LIGHTBLUE);
  gotoxy(37,22); cprintf("ЩЭЭЭЭЭЭЛ");
  gotoxy(37,23); cprintf("К Next К");
  gotoxy(37,24); cprintf("ШЭЭЭЭЭЭМ");

  return(0);
}

void alttextscreen(void)		// copies page0 to page2
{
  register int i, j;

  char far *page0 = (char far *)MK_FP(0xB800, 0x0000);
  char far *page2 = (char far *)MK_FP(0xBA00, 0x0000);

  for(i=0; i<50; i++)			// draw the text screen background
  {
    for(j=0; j<80; j++)
    {
      *page2++ = *page0++;		// copy the characters
      *page2++ = (*page0++ << 1);	// copy the color*2
    }
  }
}

void nexttdemo(char *str)
{
  static int page = 0;

  textattr(4);
  gotoxy(27,2);
  cprintf(str);				// print title
  textattr(13);
  for(;;)
  {
    mouse.GetEvent();
    textattr(WHITE);
    gotoxy(6,10);
    cprintf(" %2d  %2d ", mouse.xPos() >> 3, mouse.yPos() >> 3);

    (mouse.LB_Dn()) ? textattr(RED) :
                      textattr(DARKGRAY);
    gotoxy(6,6);
    cprintf("лл");
    gotoxy(6,7);
    cprintf("лл");
    (mouse.CB_Dn()) ? textattr(RED) :
                      textattr(DARKGRAY);
    gotoxy(9,6);
    cprintf("лл");
    gotoxy(9,7);
    cprintf("лл");

    (mouse.RB_Dn()) ? textattr(RED) :
                      textattr(DARKGRAY);
    gotoxy(12,6);
    cprintf("лл");
    gotoxy(12,7);
    cprintf("лл");

    if(mouse.Released(LEFTBUTTON))	// check for LB release
      if(mouse.InBox(36*8, 21*8, 43*8, 23*8))
        return;

    if(mouse.DoubleClick(RIGHTBUTTON))
    {
      mouse.ClearClick(RIGHTBUTTON);
      return;
    }

    if(mouse.DoubleClick(CENTERBUTTON))
    {
      mouse.Disable();
      textattr(4);
      gotoxy(1,1);
      cprintf("Hit any key...");
      while(!getch());
      textattr(DARKGRAY);
      gotoxy(1,1);
      cprintf("лллллллллллллл");
      mouse.Enable();
      mouse.Show();
    }

    if(mouse.Pressed(LEFTBUTTON) && (mouse.Button() & CTRL_PRESSED))
    {
      done = 1;
      return;
    }

    if(mouse.Pressed(LEFTBUTTON) && (mouse.Button() & SHIFT_PRESSED))
    {
      mouse.Hide();
      page = (page == 0 ? 2 : 0);

      _AH = 0x05;
      _AL = page;
      geninterrupt(0x10);

      mouse.SetVideoPage(page);
      mouse.Show();
    }
  }
}

/* ----- graphics mode demo ------------------------------------------- */

void graphicdemo()			// main routine for graphics demo
{
  mouse.Hide();
  if(graphicscreen() == 0)		// draw the screen
  {
    done = 0;
    mouse.yLimit(0, maxy);		// set y limit (EGA=350, VGA=480)
    mouse.Move(maxx/2, maxy/2);
    mouse.Show();			// initial turn on

    mouse.SetSpeedThreshold(32);
    mouse.MickToPix(8, 8);
    if(!done) { mouse.SetCursor(gcDefault);   nextgdemo(" Default "); }
    if(!done) { mouse.SetCursor(gcCross);     nextgdemo("  Cross  "); }
    if(!done) { mouse.SetCursor(gcCheck);     nextgdemo("  Check  "); }
    if(!done) { mouse.SetCursor(gcPlus);      nextgdemo("  Plus   "); }
    if(!done) { mouse.SetCursor(gcGun);       nextgdemo("   Gun   "); }
    if(!done) { mouse.SetCursor(gcHand);      nextgdemo("  Hand   "); }
    if(!done) { mouse.SetCursor(gcHourglass); nextgdemo("Hourglass"); }
    if(!done) { mouse.SetCursor(gcBullseye);  nextgdemo(" Bullseye"); }

    mouse.MickToPix(4, 4);
    if(!done) { mouse.SetCursor(gcIbeam);     nextgdemo("  IBeam  "); }

    mouse.MickToPix(2, 2);
    if(!done) { mouse.SetCursor(gcJet);       nextgdemo("   Jet   "); }

    mouse.MickToPix(16, 16);
    mouse.Move(maxx/2, maxy/2);
    if(!done) { mouse.SetCursor(gcFace);      nextgdemo("  Face   "); }

    if(!done) { mouse.SetCursor(cgcMousepp);  nextgdemo("cMousepp "); }

    mouse.InstallHandler(myHandler);	// turn off the motion counter

    if(!done) { mouse.SetCursor(gcDefault);   nextgdemo(" Default "); }
    closegraph();
  }
}

int graphicscreen()
{
  int x, y;
  int driver = EGA, mode = EGAHI;

  initgraph(&driver, &mode, "");
  if(graphresult() == grOk)
  {
    maxx = getmaxx();
    maxy = getmaxy();
    text_width  = textwidth("O");
    text_height = textheight("O");
    setviewport(0, 0, maxx, maxy, 1);

    setcolor(RED);			// paint background
    rectangle(0, 0, maxx/3, maxy);
    setfillstyle(SOLID_FILL, RED);
    floodfill(maxx/6, maxy/2, RED);
    setcolor(GREEN);
    rectangle(maxx/3, 0, 2*maxx/3, maxy);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(maxx/2, maxy/2, GREEN);
    setcolor(BLUE);
    rectangle(2*maxx/3, 0, maxx, maxy);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(5*maxx/6, maxy/2, BLUE);
    x = (maxx/2)-75;			// center white block
    y = (maxy/2)-75;
    setcolor(WHITE);
    rectangle(x, y, x+150, y+150);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x+10, y+10, WHITE);

    x = (maxx/2)-40;                    // center black box
    y = (maxy/2)-40;
    setcolor(BLACK);
    rectangle(x, y, x+80, y+80);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(maxx/2, maxy/2, BLACK);

    setcolor(BLACK);			// "Next" box
    moveto(37*text_width, 40*text_height); outtext("лллллллл");
    moveto(37*text_width, 41*text_height); outtext("лллллллл");
    moveto(37*text_width, 42*text_height); outtext("лллллллл");
    setcolor(WHITE);
    moveto(37*text_width, 40*text_height); outtext("ЩЭЭЭЭЭЭЛ");
    moveto(37*text_width, 41*text_height); outtext("К Next К");
    moveto(37*text_width, 42*text_height); outtext("ШЭЭЭЭЭЭМ");

    setfillstyle(SOLID_FILL, LIGHTGRAY);// draw mouse and buttons
    setcolor(LIGHTGRAY);
    rectangle(40, 40, 140, 140);
    floodfill(90, 90, LIGHTGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    setcolor(DARKGRAY);
    rectangle(50, 60, 70, 80);
    floodfill(60, 70, DARKGRAY);
    rectangle(80, 60, 100, 80);
    floodfill(90, 70, DARKGRAY);
    rectangle(110, 60, 130, 80);
    floodfill(120, 70, DARKGRAY);
    setcolor(BLACK);
    moveto(60, 100);
    outtext("Position");

    return(0);
  }
  return(1);
}

void nextgdemo(char *str)
{
  char mpos[10];
  int color;

  setcolor(BLACK);			// print label
  moveto((maxx/2-5*text_width),text_height);
  outtext("ллллллллл");
  setcolor(WHITE);
  moveto((maxx/2-5*text_width),text_height);
  outtext(str);

  mouse.ClearBuffer();
  mouse.ClearEvent();

  for(;;)
  {
    mouse.GetEvent();
					// set exclusion area
    mouse.Exclude(40, 40, 140, 140);
                      			// see if mouse has moved
    if(mouse.xCount() || mouse.yCount())
    {
      sprintf(mpos, "%3d %3d", mouse.xPos(), mouse.yPos());
      setcolor(LIGHTGRAY);
      moveto(60, 108);
      outtext("ллллллл");
      moveto(60, 108);
      outtext("ллллллл");
      setcolor(BLACK);
      moveto(60, 108);
      outtext(mpos);			// print cursor position
    }
					// check all button status for change
    if(mouse.Pressed(LEFTBUTTON) || mouse.Released(LEFTBUTTON))
    {
      color = mouse.LB_Dn() ? RED : DARKGRAY;
      if(mouse.MultiClick(LEFTBUTTON) == 2) color = BLUE;
      if(mouse.MultiClick(LEFTBUTTON) == 3) color = GREEN;
      if(mouse.MultiClick(LEFTBUTTON) >= 4) color = YELLOW;

      setcolor(color);
      setfillstyle(SOLID_FILL, color);
      rectangle(50, 60, 70, 80);
      floodfill(60, 70, color);
    }
    if(mouse.Pressed(CENTERBUTTON) || mouse.Released(CENTERBUTTON))
    {
      color = mouse.CB_Dn() ? RED : DARKGRAY;
      if(mouse.MultiClick(CENTERBUTTON) == 2)
      {
        if(mouse.CB_Dn())
          color = BLUE;
      }
      if(mouse.MultiClick(CENTERBUTTON) == 3)
      {
        if(mouse.CB_Dn())
          color = GREEN;
      }
      if(mouse.MultiClick(CENTERBUTTON) == 4)
      {
        color = YELLOW;
        mouse.ClearClick(CENTERBUTTON);
      }

      setcolor(color);
      setfillstyle(SOLID_FILL, color);
      rectangle(80, 60, 100, 80);
      floodfill(90, 70, color);
    }
    if(mouse.Pressed(RIGHTBUTTON) || mouse.Released(RIGHTBUTTON))
    {
      color = mouse.RB_Dn() ? RED : DARKGRAY;
      if(mouse.MultiClick(RIGHTBUTTON) == 2) color = BLUE;
      if(mouse.MultiClick(RIGHTBUTTON) == 3) color = GREEN;
      if(mouse.MultiClick(RIGHTBUTTON) >= 4) color = YELLOW;

      setcolor(color);
      setfillstyle(SOLID_FILL, color);
      rectangle(110, 60, 130, 80);
      floodfill(120, 70, color);
    }

    if(mouse.Released(LEFTBUTTON))	// check for LB release
    {
      if(mouse.InBox(37*text_width, 40*text_height,
      		     45*text_width, 43*text_height))
      {
        setcolor(DARKGRAY);		// dehilite mouse button
        setfillstyle(SOLID_FILL, DARKGRAY);
        rectangle(50, 60, 70, 80);
        floodfill(60, 70, DARKGRAY);

        return;
      }
    }

    if(mouse.MultiClick(RIGHTBUTTON) == 3)
    {
      mouse.ClearClick(RIGHTBUTTON);
      return;
    }

    if(mouse.Pressed(LEFTBUTTON) && (mouse.Button() & CTRL_PRESSED))
    {
      done = 1;
      return;
    }
  }
}
