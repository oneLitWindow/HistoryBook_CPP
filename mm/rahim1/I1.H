#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <process.h>

int cadr(void){
   int i;
   for (i=1;i<=20;i++){
   setcolor (220+i);
   rectangle (20-i,20-i,getmaxx()-(20-i),getmaxy()-(20-i));
   setrgbpalette (220+i,0,(i/20)*63,10);
    }
   getch();
   setrgbpalette (0,0,0,10);
   rectangle (22,22,getmaxx()-(22),getmaxy()-22);
   setviewport (23,23,getmaxx()-23,getmaxy()-23,1);
   getch();
      for (i=1;i<=200;i++){
   setrgbpalette(20+i,(i/200)*63,0,63-((i/200)*63));

 }
  return 0;
 }