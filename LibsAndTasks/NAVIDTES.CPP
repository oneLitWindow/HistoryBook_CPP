#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
int o,x,y;     // sahih
float k,z,p; // ashari
textbackground(0);
clrscr();
x=19;
y=x+1;
o=y*2;
textcolor(15);
textbackground(1);
z=1.1;

cprintf ("\n\rye adad vared kon: ");
scanf("%d",&x);

cprintf ("\n\rye adade dige vared kon (ashari): ");
scanf("%f",&p);

cprintf ("\n\rSalam %d, %f sosis",x,p);
cprintf ("\n\ramin is %f",p);

x++;
x=x+1;

x--;
x=x-1;

//int navid;
  long navid;
int amin[10];

x=pow(2,y)+1;

for (navid=10;navid>0;navid=navid-1)
{
amin[navid-1]=navid*10;
cprintf ("\n\rsalam! %d",navid);
cprintf ("*** %d",amin[navid-1]);
}


if (x>10) {//clrscr();
	   cprintf("woosh");
			    }

if ( (x>10) && (y<20) )  {cprintf ("koskesh");}

if ( (x<=10) && (y>2) && (z==0) )  {cprintf("jakesh");}

if (x != 10) {cprintf ("x is not 10!");}
}
