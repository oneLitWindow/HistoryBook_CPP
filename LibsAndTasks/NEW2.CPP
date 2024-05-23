#include<stdio.h>
#include<conio.h>
#include<math.h>
int  main()
{
int m=0,n=0,i=0,j=0,numberofavvals=0;
int avvals[50];
clrscr();
cprintf ("\n\rEnter number: ");
scanf("%d",&n);
for (i=2;i<=n;i++){
m=0;
for (j=2;j<=(sqrt(i));j++) if ((i%j)==0) {m=1;break;}
if (m==0){numberofavvals++;avvals[numberofavvals-1]=i;}
}
while (n>1) {
for (int i1=1;i1<=numberofavvals;i1++){
if ((n%avvals[i1-1])==0) {
cprintf ("%d --- ",avvals[i1-1]);
n=n/avvals[i1-1];

}//cprintf ("%3d ",avvals[i1-1]);}
}
}
return 0;
}