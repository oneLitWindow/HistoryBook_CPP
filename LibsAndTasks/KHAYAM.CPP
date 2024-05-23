#include<stdio.h>
#include<conio.h>
int factoriel(int);
int main()
{
int satr,j;
long int x;
clrscr();
scanf("%d",&satr);
switch (satr){
	case '1':{
	cprintf("The first line is :");
	cprintf("\n\r1");
	break; }
	case '2':{
	cprintf("The second line is :");
	cprintf("\n\r1    1");
	break;}
	case '3':{
	cprintf("The third line is :");
	cprintf("\n\r1   2   1");
	break;  }
	default: {
	cprintf("The %dth line is : ",satr);
	for(j=0;j<=satr;j++){
	x=(int)((factoriel(satr)/(factoriel(j)*factoriel(satr-j))));
	cprintf("%3d",x);}
}}
getch();
return (0);
}
int factoriel(int n)
{
	long double a=1;
	int i;
	if(n==0)
		return (1);
	else
	for(i=1;i<=n;i++)
		a=a*i;
	printf("%ld",long int(a));
	getch();
	return (a);
}