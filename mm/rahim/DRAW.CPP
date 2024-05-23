#include <string.h>  //
#include <ctype.h>   //
#include <iostream.h>//
#include <stdio.h>   //
#include <stdlib.h>  //
#include <dos.h>     //
#include <conio.h>   //
#include <graphics.h>//
#include <math.h>    //
#include <process.h> //
///////////////////////
#include "L1.h"      //
#include "L2.h"      //
#include "STACKt.h"  //
#include "regular_.h"//
#include "nfa.h"     //
#include "dfa.h"     //
#include "reduce.h"  //
///////////////////////
#include "foo_date.h"//
#include "foo_keyb.h"//
#include "foo_mous.h"//
#include "foo_grpe.h"//
#include "supercrt.h"//
//#include "asmkey.h"//
///////////////////////
mycircle(int x,int y,int r,int c,int d){
int i;float f;
for (i=0;i<500;i++)
{f=(float(i)/500)*2*M_PI;
putpixel (x+r*cos(f),y+r*sin(f),c);
delay (d);
}

}
main(){
clrscr();
initsvga();
setviewport(0,0,getmaxx(),getmaxy(),0);
//getch();
int numberofstates=20;
float f[10];
int i[10],x,y;
x=getmaxx()/2;
y=getmaxy()/2;
float r1,r2;
r2=(getmaxy()/numberofstates)/2;
r1=(float(numberofstates)/float(getmaxy()))*450.0;
int tf=0,tf1=0;
int color=15;
if (r2<textheight("W")+1) tf=30;
if (r1<150)r1=150;
char s[3]="";
settextstyle (0,0,1);
settextjustify(1,1);
for (i[0]=0;i[0]<numberofstates;i[0]++)
{f[0]=(float(i[0])/numberofstates)*2*M_PI;
itoa(i[0],s,10);
setcolor (15);
if (i[0]%2)tf1=tf; else tf1=tf/3;
if (i[0]%2) color=15; else color =12;
setcolor(color-8);
if (tf)line (x+((r1+r2)+(float(tf1)/1.2))*1.4*cos(f[0]),y+((r1+r2)+(float(tf1)/1.2))*sin(f[0]),x+(r1+r2)*1.4*cos(f[0]),y+(r1+r2)*sin(f[0]));
setcolor(color);
outtextxy (x+(r1+tf1)*1.4*cos(f[0]),y+(r1+tf1)*sin(f[0]),s);
mycircle (x+r1*1.4*cos(f[0]),y+r1*sin(f[0]),r2,color,0);
delay (1);
}
getch();
niceeffect(0);
getch();
//niceeffect(int c);
//pageborder(int mode);
//paneclose();
//border(int x1,int y1,int x2,int y2,int mode);
//flashcolor(int c,int r,int g,int b);
//showpane(char s[]);
//int setmenu(char menuname[],char item1[],char item2[],char item3[],char item4[],char item5[],char item6[]);

}