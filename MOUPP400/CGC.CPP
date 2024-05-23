/* -------------------------------------------------------------------- */
/* Mouse++ Version 4.0            cgc.cpp              Revised 10/05/92 */
/*                                                                      */
/* General mouse class for Turbo C++/Borland C++.                       */
/* Copyright 1991, 1992 by Carl W. Moreland                             */
/* -------------------------------------------------------------------- */
/* This module contains the ColorGraphicsCursor routines for displaying */
/* the color images. It is written entirely in C++ (no assembly) to de- */
/* monstrate exactly how the image is written to video memory and how   */
/* the cursor is masked at the screen edges.                            */
/* -------------------------------------------------------------------- */

#include <dos.h>
#include <mem.h>
#include "mouse.h"

const int screenWidth  = 640;		// VGA/EGA = 640
const int screenHeight = 350;           // VGA = 480, EGA = 350

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
  this->hotx = hotx;
  this->hoty = hoty;
  cWidth     = width;
  cHeight    = height;
  cBytes     = width/8 + (width%8 ? 1 : 0);

  int nBytes = cHeight * cBytes;	// total # of bytes in each plane

  cMask  = (void *)image;		// screen mask is the first plane
  cImage = (void *)(image + nBytes);	// cursor starts with second plane

  for(int i = 0; i < nBytes; i++)	// invert the screen mask
    image[i] = ~image[i];

  if(5*nBytes > tmpImageSize)		// resize the tmp buffer if
  {					//  necessary
    if(tmpImage)
      delete tmpImage;
    tmpImage = new unsigned char[5*nBytes];
    tmpImageSize = 5*nBytes;
  }
}

void ColorGraphicsCursor::VideoRead(void)
{
  static unsigned char *image, *address;
  static int new_x, new_y;
  register int i, j, k;

  xStart = 0;
  xEnd   = cBytes;
  yStart = 0;
  yEnd   = cHeight;
  new_x  = x - hotx;			// left edge of the image
  new_y  = y - hoty;			// top edge of the image

  videoLeftMask  = 0xFF >> (new_x&7);
  videoRightMask = ~videoLeftMask;

  if(new_x < 0)				// if the left edge < 0
  {
    xStart = -(new_x>>3);		// shift xStart n bytes
    new_x  = 0;
  }                                 	// if the right edge > screenWidth-1
  else if(new_x+(cBytes<<3) > screenWidth-1)
    xEnd = (screenWidth-new_x-1)>>3;	// shift xEnd n bytes

  if(new_y < 0)				// if the top edge < 0
  {
    yStart = -new_y+1;			// shift yStart n rows
    new_y  = 0;
  }                                     // if the bottom edge>screenHeight-1
  else if(new_y+cHeight > screenHeight-1)
    yEnd = screenHeight-new_y;		// shift yEnd n rows

  iWidth  = xEnd - xStart;		// width in bytes
  iHeight = yEnd - yStart;		// height in bytes

  videoAddress = (unsigned char*)MK_FP(0xA000, (new_y*80 + (new_x>>3)));

  image = (unsigned char *)tmpImage;

  outp(0x3CE, 5);			// select read mode 0
  outp(0x3CF, 0);

  for(i = 0; i < 4; i++)		// for each bitplane...
  {
    address = videoAddress;
    outp(0x3CE, 4);			// select the bit plane...
    outp(0x3CF, i);

    for(j = yStart; j < yEnd; j++)	// for each cursor line...
    {
      for(k = xStart; k <= xEnd; k++)	// for each byte...
      {
        *image = *address;		// save the byte
        image++;
        address++;
      }
      address += 79-iWidth;		// go to the next line
    }
  }
}

void ColorGraphicsCursor::VideoWrite(void)
{
  static unsigned char *image, *address, vByte=0;
  register int i, j, k;

  image = (unsigned char *)tmpImage;

  outp(0x3CE, 5);			// select write mode 0
  outp(0x3CF, 0);
  outp(0x3CE, 3);
  outp(0x3CF, 0);

  for(i=0; i<4; i++)			// for each bitplane...
  {
    address = videoAddress;
    outp(0x3C4, 2);			// select the bit plane...
    outp(0x3C5, 1<<i);
    outp(0x3CE, 8);

    for(j = yStart; j < yEnd; j++)	// for each cursor line...
    {
      for(k = xStart; k <= xEnd; k++)	// for each byte...
      {
        vByte = *address;

        if(k == 0)
        {
          outp(0x3CF, videoLeftMask);	// mask off the left byte
        }
        else if(k == cBytes)
        {
          outp(0x3CF, videoRightMask);	// mask off the right byte
        }
        else
        {
          outp(0x3CF, 0xFF);		// middle bytes don't need masking
        }

        *address = *image;		// write the byte
        image++;
        address++;
      }
      address += 79-iWidth;		// next cursor line
    }
  }
  outp(0x3CF, 0xFF);
}

void ColorGraphicsCursor::CursorWrite(void)
{
  static unsigned char *image, *address, *base, *base0;
  static unsigned char vByte, mask, rShift, lShift;
  register int k, j, i;

  image = (unsigned char *)cImage;	// set image to the start of the

  base0 = (unsigned char *)cMask;	// base0 is the screen mask
  for(k=0; k<cBytes; k++)		// clip any part that's < yStart
    base0 += yStart;

  rShift = (x-hotx)&7;
  lShift = 8-((x-hotx)&7);

  outp(0x3CE, 5);			// select write mode 0
  outp(0x3CF, 0);
  outp(0x3CE, 3);
  outp(0x3CF, 0);

  for(i=0; i<4; i++)			// for each bit plane...
  {
    address = videoAddress;
    outp(0x3C4, 2);			// select the bit plane...
    outp(0x3C5, 1<<i);
    outp(0x3CE, 8);

    for(j=0; j<cBytes; j++)		// clip any part that's < yStart
      image += yStart;
    base = base0;

    for(j = yStart; j < yEnd; j++)	// for each cursor line...
    {
      image += xStart;
      base  += xStart;

      for(k = xStart; k <= xEnd; k++)	// for each byte...
      {
        vByte = *address;

        if(k == 0)
        {
          mask  = *base  >> rShift;	// get the shift mask
          vByte = *image >> rShift;	// shift the image byte
        }
        else if(k == cBytes)
        {
          mask  = *(base-1)  << lShift;
          vByte = *(image-1) << lShift;
        }
        else
        {
          mask  =  (*(base-1) << lShift) |  (*base >> rShift);
          vByte = (*(image-1) << lShift) | (*image >> rShift);
        }

        outp(0x3CF, mask);		// mask off the bits
        *address = vByte;		// write the byte to video
        address++;			// next video byte
        image++;			// next image byte
        base++;				// next mask byte
      }
      address += 79-iWidth;		// next cursor line
      image += cBytes-xEnd-1;		// next image line
      base  += cBytes-xEnd-1;		// next mask line
    }
    for(j=0; j<cBytes; j++)		// next bit plane in image
      image += cHeight-yEnd;
  }
  outp(0x3CF, 0xFF);
}
