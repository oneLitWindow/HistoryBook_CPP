#include <iostream.h>
#include <stdio.h>
#include <conio.h>
void main()
{
textbackground(0);
clrscr();
textcolor(10);
int a=0;
if (kbhit()) getch();
if (kbhit()) getch();
cprintf ("First day in year (sat=0 sun=1 mon=2 tue=3 wed=4 thu=5 fri=6) ? ");
textcolor(15);
cscanf("%d",&a);
if (kbhit()) getch();
int b;
for (int month=1;month<=12;month++){
textcolor(2);
cprintf("\n\r\n\r");
if (month%3==0) gotoxy (50,wherey()-8); else
if ((month%2==0)&&((month-1)%3!=0)) gotoxy (25,/*wherey()-8)*/wherey()-8);
if ((month==5)||(month==11)) gotoxy (25,/*wherey()-8)*/wherey()-8);
cprintf ("Month...%2d\n\r",month);
textcolor(10);
a=a%7;
if ((month%2==0)&&((month-1)%3!=0)) gotoxy (25,/*wherey()-8)*/wherey());
if (month%3==0) gotoxy (50,wherey());
if ((month==5)||(month==11)) gotoxy (25,/*wherey()-8)*/wherey());
for (b=1;b<=a;b++) {cprintf ("   ");}
for (b=1;b<=31;b++){
if ((month>6)&&(b>=31)) break;
if ((month==12) && (b>=30)) break;
if ((!(a%7))&&(b!=1)) {cprintf("\n\r");if ((month==5)||(month==11)) gotoxy (25,/*wherey())*/wherey());if ((month%2==0)&&((month-1)%3!=0)) gotoxy (25,/*wherey()-8)*/wherey());if (month%3==0) gotoxy (50,wherey());}
cprintf ("%2d ",b);
a=a+1;}
cprintf("\n\r");
if (month%3==0)getch();}}