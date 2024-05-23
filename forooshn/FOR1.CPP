#include "stdlib.h"
#include "conio.h"
#include "process.h"
#include "stdio.h"
#include "iostream.h"
#include "string.h"
#include "fstream.h"
#include "dos.h"
#include "malloc.h"
#include "graphics.h"
// Forooshande's own headers:
#include "foo_date.h"
#include "foo_keyb.h"
#include "foo_mous.h"
class goods{int number;
	    struct dosdate_t expdate,prodate,entdate;
	    char name[20],producer[20],code[10],group[15];
	    unsigned long buyprice,sellprice;
	    };

void niceeffect(int c){
int i,j;
c=abs(c);
if (c) for (i=0;i<=(getmaxx()/32);i++){
setcolor(0);
rectangle (i,i,getmaxx()-i,getmaxy()-i);
delay(5+((getmaxx()/32)-i));
}else for (i=(getmaxx()/32);i<=getmaxy()/2;i++){
	setcolor(15);
	line ((getmaxx()/32)+1,i,getmaxx()-(getmaxx()/32)-1,i);
	line ((getmaxx()/32)+1,getmaxy()-i,getmaxx()-(getmaxx()/32)-1,getmaxy()-i);
	delay(5);
	setcolor(0);
	line ((getmaxx()/32)+1,i,getmaxx()-(getmaxx()/32)-1,i);
	line ((getmaxx()/32)+1,getmaxy()-i,getmaxx()-(getmaxx()/32)-1,getmaxy()-i);
	}
if (c==1) c=12; else
if (c==2) c=10; else
if (c==3) c= 9; else
if (c==4) c=14; else
if (c==5) c=11; else
if (c==6) c=13; else
if (c==7) c=15; else
if (c==8) c= 9; else
if (c==9) c=12;
setfillstyle (1,0);
for (i=0;i<=20;i++) {
setcolor(15);
fillellipse ((getmaxx()/32)-(i/2),(getmaxx()/32)-(i/2),i,i);
fillellipse ((getmaxx()-(getmaxx()/32))+(i/2),(getmaxy()-(getmaxx()/32))+(i/2),i,i);
delay(i+10);
setcolor (0);
fillellipse ((getmaxx()/32)-(i/2),(getmaxx()/32)-(i/2),i,i);
fillellipse ((getmaxx()-(getmaxx()/32))+(i/2),(getmaxy()-(getmaxx()/32))+(i/2),i,i);
}
for (i=20;i>=0;i--) {
setcolor(15);
fillellipse ((getmaxx()/32)-(i/2),(getmaxx()/32)-(i/2),i,i);
fillellipse ((getmaxx()-(getmaxx()/32))+(i/2),(getmaxy()-(getmaxx()/32))+(i/2),i,i);
delay(i+10);
setcolor (0);
fillellipse ((getmaxx()/32)-(i/2),(getmaxx()/32)-(i/2),i,i);
fillellipse ((getmaxx()-(getmaxx()/32))+(i/2),(getmaxy()-(getmaxx()/32))+(i/2),i,i);
}
for (i=getmaxx()/32;i<=getmaxx()-getmaxx()/32;i++){
putpixel (i,getmaxx()/32,15);
putpixel (getmaxx()-i,getmaxy()-getmaxx()/32,15);
delay (2);
putpixel (i,getmaxx()/32,c);
putpixel (getmaxx()-i,getmaxy()-getmaxx()/32,c);
}
for (i=getmaxx()/32;i<=getmaxy()-getmaxx()/32;i++){
putpixel (getmaxx()-getmaxx()/32,i,15);
putpixel (getmaxx()/32,getmaxy()-i,15);
delay (1);
putpixel (getmaxx()-getmaxx()/32,i,c);
putpixel (getmaxx()/32,getmaxy()-i,c);
}
setcolor(c);
for (i=(getmaxx()/32);i>=0;i--){
rectangle (i,i,getmaxx()-i,getmaxy()-i);
delay(5+((getmaxx()/32)-i));
}
}
void pageborder(int mode){
setviewport (0,0,getmaxx(),getmaxy(),0);
niceeffect(mode);
int j;
for (int i=0;i<=(getmaxx()/32);i++){
setcolor(100+i);
j=i*63/(getmaxx()/32);
if (mode<0) j=63-j;
switch (abs(mode)){
case 1: setrgbpalette (100+i,j,0,0);break;
case 2: setrgbpalette (100+i,0,j,0);break;
case 3: setrgbpalette (100+i,0,0,j);break;
case 4: setrgbpalette (100+i,j,j,0);break;
case 5: setrgbpalette (100+i,0,j,j);break;
case 6: setrgbpalette (100+i,j,0,j);break;
case 7: setrgbpalette (100+i,j,j,j);break;
case 8: setrgbpalette (100+i,j,0,63-j);break;
case 9: setrgbpalette (100+i,63,63-j,0);break;
}
rectangle (i,i,getmaxx()-i,getmaxy()-i);
delay(5+(getmaxx()/32)-i);
}
i=(getmaxx()/32);
setcolor (100+((getmaxx()/32)-i));
rectangle (i,i,getmaxx()-i,getmaxy()-i);
setviewport (i+1,i+1,(getmaxx()-i)-1,(getmaxy()-i)-1,1);
}
int huge temp(void){return 0;}
void initsvga(){
int drv=installuserdriver ("svga256",temp),md=2;
initgraph(&drv,&md,"bgi");
setrgbpalette (0,20,00,2);
delay (1000);
pageborder(-9);
getkeys();
}
main(){
mouse mymouse;
mymouse.install();
randomize();
textcolor(15);
textbackground(1);
clrscr();
initsvga();
char s[20];
strcpy (s,date());
setcolor(10);
settextstyle (7,0,1);
outtextxy (0,0,s);
char c;
mymouse.setplace(0,0);
char co[10][10][2]={NULL};
co[ 0][ 0][0]=1;
co[ 0][ 1][0]=1;
co[ 0][ 2][0]=1;
co[ 0][ 3][0]=1;
co[ 0][ 4][0]=1;
co[ 0][ 5][0]=1;
co[ 0][ 6][0]=1;
co[ 1][ 0][0]=1;
co[ 1][ 1][0]=1;
co[ 1][ 2][0]=1;
co[ 1][ 3][0]=1;
co[ 1][ 4][0]=1;
co[ 1][ 5][0]=1;
co[ 1][ 6][0]=1;
co[ 2][ 0][0]=1;
co[ 2][ 1][0]=1;
co[ 2][ 2][0]=1;
co[ 2][ 3][0]=1;
co[ 2][ 4][0]=1;
co[ 3][ 0][0]=1;
co[ 3][ 1][0]=1;
co[ 3][ 2][0]=1;
co[ 3][ 3][0]=1;
co[ 3][ 4][0]=1;
co[ 4][ 0][0]=1;
co[ 4][ 1][0]=1;
co[ 4][ 2][0]=1;
co[ 4][ 3][0]=1;
co[ 4][ 4][0]=1;
co[ 4][ 5][0]=1;
co[ 5][ 0][0]=1;
co[ 5][ 1][0]=1;
co[ 5][ 4][0]=1;
co[ 5][ 5][0]=1;
co[ 5][ 6][0]=1;
co[ 6][ 0][0]=1;
co[ 6][ 1][0]=1;
co[ 6][ 5][0]=1;
co[ 6][ 6][0]=1;
co[ 6][ 7][0]=1;
co[ 7][ 6][0]=1;
co[ 7][ 7][0]=1;
co[ 7][ 8][0]=1;
co[ 8][ 7][0]=1;
co[ 8][ 8][0]=1;
/*
co[  ][  ][0]=1;
#   0 1 2 3 4 5 6 7 8 9
  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
0 ³ 1 1 1 1 1 1 1 0 0 0
1 ³ 1 1 1 1 1 1 1 0 0 0
2 ³ 1 1 1 1 1 0 0 0 0 0
3 ³ 1 1 1 1 1 0 0 0 0 0
4 ³ 1 1 0 1 1 1 0 0 0 0
5 ³ 1 1 0 0 1 1 1 0 0 0
6 ³ 1 1 0 0 0 1 1 1 0 0
7 ³ 0 0 0 0 0 0 1 1 1 0
8 ³ 0 0 0 0 0 0 1 1 0 0
9 ³ 0 0 0 0 0 0 0 0 0 0
*/
int x=0,y=0,xo=1,yo=1;
int ii,jj;
	   for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) if (co[jj][ii][0]) co[jj][ii][1]=getpixel (xo+ii,yo+jj);
do {
if (mymouse.getx()+2>=(getmaxx()-(2*(getmaxx()/32)))) mymouse.setplace (getmaxx()-(2*getmaxx()/32)-2,mymouse.gety());
if (mymouse.gety()+2>=(getmaxy()-(2*(getmaxx()/32)))) mymouse.setplace (mymouse.getx(),mymouse.gety()-(getmaxx()/64)+8);
x=mymouse.getx();
y=mymouse.gety();
if ((x!=xo)||(y!=yo)){
	   for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) if (co[jj][ii][0]) putpixel (xo+ii,yo+jj,co[jj][ii][1]);
	   xo=x;
	   yo=y;
	   for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) if (co[jj][ii][0]) co[jj][ii][1]=getpixel (xo+ii,yo+jj);
	   for (ii=0;ii<10;ii++) for (jj=0;jj<10;jj++) if (co[jj][ii][0]) putpixel (xo+ii,yo+jj,98+((20)-(ii+jj)));
	   }
if (kbhit()) c=getch();
} while (c!=27);
setviewport(0,0,getmaxx(),getmaxy(),1);
niceeffect(0);
}
/*  //Example for Main function to use Mouse....
  int main(){
	int y=4;
	textmode(C80);
	normvideo();
	clrscr();
	window (20, 4,60,15); // Change to (1,1,80,25) for fullscreen blue squar!
	textbackground(1);
	clrscr();
	textcolor(15);
	cprintf ("\n\n\n\n\n      I defined a window for mouse!\n\n\r              (20, 4,60,15)");
	window (1,1,80,25);
	textbackground(0);
	textcolor(2);
	mouse mymouse;
	mymouse.install();
	mymouse.hide();
	clreol();
	textcolor(9);
	clreol();
	cprintf("\n\n\rMouse Reader By Amin Safinejad, Press any key to exit...");
	clreol();
	mymouse.win (20, 4,60,15); // Change to (1,1,80,25) for full mouse range!
	mymouse.show();
	while (!kbhit())  {
		gotoxy (1,2);
		textcolor(11);
		cprintf ("Mouse.GetX= %2d, Mouse.Gety= %2d ",mymouse.getx(),mymouse.gety());
		clreol();
		while ((mymouse.prsleft())||(mymouse.prsright())) {
			if (mymouse.prsleft())  {gotoxy(1,4);textcolor(12);cprintf("Left  button Pressed!\r");sound(100);delay(100);nosound();}
			if (mymouse.prsright()) {gotoxy(1,4);textcolor(12);cprintf("Right button Pressed!\r");sound(150);delay(100);nosound();}
			if (mymouse.prsmid())   {gotoxy(1,4);textcolor(12);cprintf("Mid.  button Pressed!\r");sound(200);delay(100);nosound();}
		}
		gotoxy(1,4);
		clreol();
		delay(20);
	}
	mymouse.hide();
	textcolor(7);
	mymouse.win (1, 1,80,25);
	clrscr();
	cout << "End!";
	delay(500);
	return 0;
*/