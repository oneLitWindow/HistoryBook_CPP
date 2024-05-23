
// Program by Navid Alizade vahid (8425312)

#include <stdio.h>
#include <iostream.h>
#include <conio.h>
void main(){
const int maxn=100;
int student[maxn][2],overs=0,down,n=0,min[2]={0,0},min2[2]={0,0};
float middle=0,percent=0;
textcolor (10);
clrscr();
for (int temp=0;temp<maxn;temp++) student[temp][0]=-1;
for (int i=0;i<maxn;i++){
textcolor(15);
cprintf ("\n\rEnter the MARK of student #%2d (-1 to quit): ",i);
textcolor(10);
scanf ("%d",&student[i][0]);
if (student[i][0]==-1) break;
textcolor(9);
cprintf ("                              Student code: ",i);
textcolor(11);
scanf ("%d",&student[i][1]);

if (i==0) {min[0]=student[0][0];min[1]=student[0][1];}
if (i==1) {min2[0]=student[1][0];min2[1]=student[1][1];}
if  (student[i][0]<min[0])                             {min[0] =student[i][0];min[1] =student[i][1];}
if ((student[i][0]<min2[0]) && (student[i][1]!=min[1])){min2[0]=student[i][0];min2[1]=student[i][1];}

middle+=student[i][0];
n++;
}
textcolor(9);
cprintf ("\n\rSumm is:  %6.0f",middle);
middle/=n;
textcolor(14);
cprintf ("\n\rAverage is: %6.2f\n\r",middle);
textcolor (11);
for (i=0;i<maxn;i++){
if (student[i][0]>middle){overs++;cprintf ("\n\rStudent code %d with mark %d is over average!",student[i][1],student[i][0]);}
}
textcolor (9);
percent=(float (overs)/float(n))*100;
cprintf ("\n\rPercentage of students higher than average: %2.0f%",percent);
textcolor (12);
cprintf ("\n\rStudents code %d (mark %d) and %d (mark %d) have the lowest marks!",min[1],min[0],min2[1],min2[0]);
while (kbhit()){getch();}
getch();
}