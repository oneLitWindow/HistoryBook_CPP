#include<stdio.h>
#include<STDLIB.h>
#include<conio.h>
#include<string.h>
int f();
void main()
{
  int i;
  double d;
  int a[5],b[4];
  clrscr();
  cprintf("enter five number:");
  for (i=0;i<5;i++)
	a[i]=f();
	d=a[0];
  cprintf("enter four operator");
  for(i=0;i<4;i++){
	  b[i]=getche();
	  switch (b[i]){
		case '+': d=d+a[i+1];
			  break;
		case '*': d=d*a[i+1];
			  break;
		case '-': d=d-a[i+1];
			  break;
		case '/': d=d/a[i+1];
			  break;
		default : break;
	  }
  }
  cprintf("%5.2f",d);
  getch();
 }
//========================//
  int f()
  {
   char r[]="0123456789",w[2],s[5]="";
   char c;
   int v;
   int n=1;
   while (n) {
	if (kbhit()) {
		c=getch();
		if (c==13 || c==32) {n=0;break;}
		if (strchr(r,c)){
			itoa(c,w,10);
			strcat(s,w);
			cprintf("%c",c);
		}
	}
   }
   v=atol(s);
    cprintf ("\n\r");
    return(v);
 }


