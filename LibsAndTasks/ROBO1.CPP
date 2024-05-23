#include <graphics.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
void draw_a_table(int x1,int y1,int x2,int y2,int cols,int rows,int backcolor, int forcolor){
setfillstyle(1,backcolor);
setcolor(forcolor);
bar (x1,y1,x2,y2);
rectangle (x1,y1,x2,y2);
float xlength=float(x2-x1)/cols;
float ylength=float(y2-y1)/rows;
for (int xs=1;xs<cols;xs++) line (x1+(xlength*xs),y1,x1+(xlength*xs),y2);
for (int ys=1;ys<rows;ys++) line (x1,y1+(ylength*ys),x2,y1+(ylength*ys));}
main(){
int i=DETECT;
int j=2;
initgraph (&i,&j,"");
setcolor (9);
int map[31][31]={0};
int x1=3;
int y1=12;
int x2=29;
int y2=20;
map[x1][y1]=10;
map[x2][y2]=11;

map[10][11]=1;
map[11][11]=1;
map[12][11]=1;
map[12][12]=1;
map[12][13]=1;
map[11][13]=1;
map[10][13]=1;

map[14][17]=1;
map[10][25]=1;
map[1][29]=1;
map[12][5]=1;
map[23][18]=1;
map[15][28]=1;
map[12][3]=1;
map[14][7]=1;
map[15][29]=1;
map[15][28]=1;
map[15][27]=1;
map[14][27]=1;
map[13][27]=1;
map[13][26]=1;



for (i=1;i<=30;i++){
for (j=1;j<=30;j++){
map[1 ][j ]=1;
map[i ][1 ]=1;
map[30][j ]=1;
map[i ][30]=1;
if (map[i][j]==1)setfillstyle (1,15); else
if (map[i][j]==10)setfillstyle (1,10); else
if (map[i][j]==11)setfillstyle (1,11); else
setfillstyle (1,1);
bar (i*10,j*10,(i*10)+10,(j*10)+10);
rectangle (i*10,j*10,(i*10)+10,(j*10)+10);
}
}
int dx,dy;
getch();
int aloy,alox;
while ((x1!=x2)||(y1!=y2)){
checkx:
dx=x2-x1;
dy=y2-y1;
if (x2>=x1)x1++;else x1--;
checkcheckx:
i=x1;
j=y1;
setfillstyle (1,4);
setcolor (12);
bar (i*10+1,j*10+1,(i*10)+9,(j*10)+9);
delay(10);
if (map[i][j]==1)setfillstyle (1,7); else setfillstyle (1,3);
bar (i*10+1,j*10+1,(i*10)+9,(j*10)+9);
if ((abs(x1-x2)==0)&&(abs(y1-y2)<=1))break;
if (y2>=y1) aloy=1;else aloy=-1;
if (x2>=x1){
	    if (map[x1][y1]==1){x1--;if (map[x1][y1+aloy]!=1)goto checky; else {map[x1][y1]=1;goto checkchecky;}}else {if (dx>(x2-x1)) {dx=x2-x1;goto checkx;} else {map[x1][y1]=1;x1--;goto checkcheckx;}}
	   } else {
	    if (map[x1][y1]==1){x1++;if (map[x1][y1+aloy]!=1)goto checky; else {map[x1][y1]=1;goto checkchecky;}}else {if (dx>(x1-x2)) {dx=x1-x2;goto checkx;} else {map[x1][y1]=1;x1++;goto checkcheckx;}}
	   }
checky:
dx=x2-x1;
dy=y2-y1;
if (y2>=y1)y1++; else y1--;
checkchecky:
setfillstyle (1,4);
setcolor (12);
i=x1;
j=y1;
setfillstyle (1,4);
setcolor (12);
bar (i*10+1,j*10+1,(i*10)+9,(j*10)+9);
delay(10);
if (map[i][j]==1)setfillstyle (1,7); else setfillstyle (1,3);
bar (i*10+1,j*10+1,(i*10)+9,(j*10)+9);
if ((abs(x1-x2)==0)&&(abs(y1-y2)<=1))break;
if (x2>=x1) alox=1;else alox=-1;
if (y2>=y1) {
		if (map[x1][y1]==1){y1--;if (map[x1+alox][y1]!=1)goto checkx; else {map[x1][y1]=1;goto checkcheckx;}}else {if (dy>(y2-y1)) {dy=y2-y1;goto checky;} else {break;map[x1][y1]=1;y1--;goto checkcheckx;}}
	    } else {
		if (map[x1][y1]==1){y1++;if (map[x1+alox][y1]!=1)goto checkx; else {map[x1][y1]=1;goto checkcheckx;}}else {if (dy>(y1-y2)) {dy=y1-y2;goto checky;} else {break;map[x1][y1]=1;y1++;goto checkcheckx;}}
	    }
}
//setviewport(100,100,539,379,1);
//draw_a_table (0,0,439,279,30,30,1,9);
getch();
}