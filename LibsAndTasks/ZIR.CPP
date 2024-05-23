#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <dos.h>
int t,j,n,i=-1;
char x[100][10];
char k[80];
void fun(char d);
void main()
{

clrscr();
gets(k);
n=strlen(k);
j=0;
fun(k[0]);
cout<<" "<<"{ }";
gotoxy(40,12);
cout<<(++i)+1;
getche();
}
void fun(char d)
{
 int m,z;
delay(100);
cout<<"{"<<d<<"}"<<" ";
x[++i][0]=d;
t=i;
if (j!=0)
  {
  for(m=0;m<(pow(2,j)-1);m++)
  {
	  i++;
	  t=0;
	  do
	  {
	  x[i][t]=x[m][t];
	  t++;
	  } while(x[m][t]!='\0');
	  x[i][t]=d;
	  delay(100);
		cout<<"{";
		for(z=0;x[i][z]!='\0';z++)
		   {cout<<x[i][z];
		   if (x[i][z+1]!='\0') cout<<",";}
	  cout<<"}"<<" ";
	  }
  }
++j;
if (j<n) fun(k[j]);
}
