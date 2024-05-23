#include <string.h>
#include <ctype.h>
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <process.h>
int huge install(void)
{
return 0;
}

char q=0;
char w[]=" ";
int h1,h,z,l,k;
int p=0;
char endopens[80]="‚ƒ~XYš›–—’“´µhide\\]`az{vw¼½LM¦§TU®¯ª«Ÿ£¢‰ˆ…„ÃÄ";
char beforopens[80]="}W™•‘³gc[_yu»K¥BS­© Š†qomk·±./sO";
char characters[80]="qwertyuiop[]asdfghjkl;'zxcvbnm,./\\`";
char farsichars[80]="ƒY›—“µie]a{w½M§AU¯«Ÿ£ˆ„pnljÄ°./rQ";
char beforopens2[80]="‚~Xš–’´hd\\`zv¼L¦BT®ª¢‰…";
char beforopens3[80]="jklmnopqrs°™ABCD±";
char nebo[80]="€|V˜”Œ²fbZ^xtºJ¤AR¬¨œ ‹‡pnlj¶°./\\rN";
int charisin(char a0)
{
for(h=0;h<=(strlen(characters));h++)
   if (characters[h]==a0)
   return 0;
 return 1;
}
int charisinf(char a0)
{
for(h=0;h<=(strlen(farsichars));h++)
   if (farsichars[h]==a0)
   return 0;
 return 1;
}
int charisinb2(char a0)
{
for(h=0;h<=(strlen(beforopens2));h++)
   if (beforopens2[h]==a0)
   return 0;
 return 1;
}
int charisinneb(char a)
{
for(h1=0;h1<=(strlen(nebo));h1++)
   if (nebo[h1]==a)
   return 0;
 return 1;
}

int charisinb(char a1)
{
for(l=0;l<=(strlen(beforopens));l++)
   if (beforopens[l]==a1)
   return 0;
 return 1;
}
int charisinb3(char a4)
{
for(int l1=0;l1<=(strlen(beforopens3));l1++)
   if (beforopens3[l1]==a4)
   return 0;
 return 1;
}

int charisine(char a2)
{
for(k=0;k<=(strlen(endopens));k++)
   if (endopens[k]==a2)
   return 0;
 return 1;
}
char readkey()
{
char b;
b=getch();
if ((b==8)||(b==13)||(b==27)||(charisin(b)==0)) return b;
else if(b==32) return b;
else readkey();
return 0;
}
void main()
{
int driver , gmode=2;
driver=installuserdriver ("svga256", install);
initgraph(&driver, &gmode, "e:\\compiler\\borlan~1.1la\\borlan~1\\bgi");
int userfont = installuserfont("yasr");

setrgbpalette(0,4,0,0);
setbkcolor(0);
cleardevice();
setcolor(15);
char type[80]="";
int i=0,j=1,j1=0;
char a=0;
int y;
while (a!=27){
a=readkey();
cleardevice();

if (a==8){
	  if (charisinf(type[strlen(type)-2])==0)
	  type[strlen(type)-2]=nebo[h];
	  if (charisinb2(type[strlen(type)-2])==0)
	    type[strlen(type)-2]=beforopens[h];
	  type[strlen(type)-1]=0;
 }
if (strlen(type)==0) j=1;
if ((j!=1)&&(strlen(type)>1)&&(charisinb3(type[strlen(type)-1])==0)&&(charisin(a)==0)) j=1;
if ((j==1)&&(a!=27)&&(a!=8)&&(a!=13)&&(a!=32))type[strlen(type)]=nebo[h];
if ((j!=1)&&(a!=27)&&(a!=8)&&(a!=13)&&(a!=32))type[strlen(type)]=beforopens[h];
settextstyle(userfont,0,2);
char pa[10]="";
if ((j!=1)&&(strlen(type)>1)&&(charisinneb(type[strlen(type)-2])==0)&&(charisin(a)==0)) {type[strlen(type)-2]=farsichars[h1];type[strlen(type)-1]=beforopens[h1];}
if ((strlen(type)>1)&&(charisine(type[strlen(type)-2])==0)&&(charisin(a)==0)) type[strlen(type)-1]=beforopens[h];
if ((j1!=1)&&(j!=1)&&(strlen(type)>1)&&(charisinb(type[strlen(type)-2])==0)&&(charisin(a)==0)) type[strlen(type)-2]=beforopens2[l];
if ((j1==1)&&(j!=1)&&(strlen(type)>1)&&(charisinb(type[strlen(type)-2])==0)&&(charisin(a)==0)) type[strlen(type)-2]=farsichars[l];
j++;
if (a==32)  j=1;
if (charisinb3(type[strlen(type)-1])==0)
   {j=1;
    j1=1;
   }
 else j1=0;
 cleardevice();
 settextstyle(userfont,0,2);
 for(z=strlen(type);z>=0;z--)
   {pa[0]=type[z];
      outtext(pa);}
   }
closegraph();
}