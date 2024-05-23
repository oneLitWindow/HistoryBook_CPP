/* -------------------------------------------------------------------- */
/* Mouse++ Version 4.0            cgc_bgi.cpp          Revised 10/05/92 */
/*                                                                      */
/* General mouse class for Turbo C++/Borland C++.                       */
/* Copyright 1991, 1992 by Carl W. Moreland                             */
/* -------------------------------------------------------------------- */
/* This module demonstrates how to use the BGI to draw cursor images to */
/* the screen. It is incomplete in two areas. First, it does not pro-   */
/* perly mask the cursor image at the edges of the screen such that the */
/* image is partially shown. Second, it assumes that the current view-  */
/* port is the entire screen, which might not be true.                  */
/* -------------------------------------------------------------------- */

#include <stdlib.h>
#include <graphics.h>
#include "mouse.h"

const int screenWidth  = 640;		// VGA/EGA = 640
const int screenHeight = 350;           // VGA = 480, EGA = 350
static int new_x, new_y;

int            ColorGraphicsCursor::x = -1;
int            ColorGraphicsCursor::y = -1;
void*          ColorGraphicsCursor::tmpImage = NULL;
int            ColorGraphicsCursor::tmpImageSize = 0;
unsigned char* ColorGraphicsCursor::videoAddress;
int            ColorGraphicsCursor::videoLeftMask;
int            ColorGraphicsCursor::videoRightMask;
int            ColorGraphicsCursor::screenLeftMask;
int            ColorGraphicsCursor::screenRightMask;
unsigned char  ColorGraphicsCursor::xStart;
unsigned char  ColorGraphicsCursor::yStart;
unsigned char  ColorGraphicsCursor::xEnd;
unsigned char  ColorGraphicsCursor::yEnd;
unsigned char  ColorGraphicsCursor::iWidth;
unsigned char  ColorGraphicsCursor::iHeight;


ColorGraphicsCursor::ColorGraphicsCursor(unsigned char hotx,
                                         unsigned char hoty,
                                         unsigned char image[],
                                         unsigned char width,
                                         unsigned char height)
{
  register int i, j, k;
  unsigned imageSize, nBytes;
  unsigned char *plane0, *plane1, *plane2, *plane3, *plane4;
  unsigned char *cursorImage, *cursorMask;

  this->hotx = hotx;
  this->hoty = hoty;
  cWidth     = width;
  cHeight    = height;
  cBytes     = width/8 + (width%8 ? 1 : 0);

  nBytes = cHeight * cBytes;

  imageSize = 4*cBytes*cHeight + 4;

  if(imageSize > tmpImageSize)		// resize the tmp image if
  {					//  necessary
    if(tmpImage)
      free(tmpImage);
    tmpImage = malloc(imageSize);
    tmpImageSize = imageSize;
  }
  cursorMask  = (unsigned char *)malloc(imageSize);
  cursorImage = (unsigned char *)malloc(imageSize);
  cImage = (void *)cursorImage;
  cMask  = (void *)cursorMask;

  plane0 = image;
  plane1 = plane0 + nBytes;
  plane2 = plane1 + nBytes;
  plane3 = plane2 + nBytes;
  plane4 = plane3 + nBytes;

  cursorMask[0]  = cWidth-1;
  cursorMask[1]  = 0;
  cursorMask[2]  = cHeight-1;
  cursorMask[3]  = 0;
  cursorMask += 4;

  cursorImage[0] = cWidth-1;
  cursorImage[1] = 0;
  cursorImage[2] = cHeight-1;
  cursorImage[3] = 0;
  cursorImage += 4;

  for(i = 0; i < cHeight; i++)		// convert the mask to BGI format
  {
    for(j = 0; j < 4; j++)
    {
      for(k = 0; k < cBytes; k++)
      {
        *cursorMask = *plane0;
        cursorMask++; plane0++;
      }
      plane0 -= cBytes;
    }
    plane0 += cBytes;
  }

  for(i = 0; i < cHeight; i++)		// convert the cursor to BGI format
  {
    for(j = 0; j < cBytes; j++)
    {
      *cursorImage = *plane4;
      cursorImage++; plane4++;
    }
    for(j = 0; j < cBytes; j++)
    {
      *cursorImage = *plane1;
      cursorImage++; plane1++;
    }
    for(j = 0; j < cBytes; j++)
    {
      *cursorImage = *plane2;
      cursorImage++; plane2++;
    }
    for(j = 0; j < cBytes; j++)
    {
      *cursorImage = *plane3;
      cursorImage++; plane3++;
    }
  }
}

void ColorGraphicsCursor::VideoRead(void)
{
  new_x = x - hotx;
  xEnd  = (cBytes<<3) - 1;
  new_y = y - hoty;
  yEnd  = cHeight - 1;

  if(new_x < 0)
    new_x = 0;

  if(new_y < 0)
    new_y = 0;

  if(new_x+xEnd > screenWidth-1)
    new_x = screenWidth - (cBytes<<3);

  if(new_y+yEnd > screenHeight-1)
    new_y = screenHeight - cHeight;

  getimage(new_x, new_y, new_x+xEnd, new_y+yEnd, tmpImage);
}

void ColorGraphicsCursor::VideoWrite(void)
{
  putimage(new_x, new_y, tmpImage, COPY_PUT);
}

void ColorGraphicsCursor::CursorWrite(void)
{
  putimage(new_x, new_y, cMask,  AND_PUT);
  putimage(new_x, new_y, cImage, XOR_PUT);
}

