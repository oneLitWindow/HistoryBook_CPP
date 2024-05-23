void niceeffect(int c){
setviewport (0,0,getmaxx(),getmaxy(),0);
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
//i=(getmaxx()/32);
//setcolor (100+((getmaxx()/32)-i));
//rectangle (i,i,getmaxx()-i,getmaxy()-i);
//setviewport (i+1,i+2,(getmaxx()-i)-1,(getmaxy()-i)-2,1);

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
setviewport (i+1,i+2,(getmaxx()-i)-1,(getmaxy()-i)-2,1);
}
int huge temp(void){return 0;}
void initsvga(){
int drv=installuserdriver ("svga256",temp),md=2;
initgraph(&drv,&md,"bgi");
setrgbpalette (0,0,0,10);
delay (1000);
pageborder(-3);
getkeys();
}

void border(int x1,int y1,int x2,int y2,int mode){
int j;
for (int i=0;i<=(getmaxx()/32);i++){
setcolor(101+i+getmaxx()/32);
j=i*63/(getmaxx()/32);
if (mode<0) j=63-j;
switch (abs(mode)){
case 1: setrgbpalette (101+i+(getmaxx()/32),j,0,0);break;
case 2: setrgbpalette (101+i+(getmaxx()/32),0,j,0);break;
case 3: setrgbpalette (101+i+(getmaxx()/32),0,0,j);break;
case 4: setrgbpalette (101+i+(getmaxx()/32),j,j,0);break;
case 5: setrgbpalette (101+i+(getmaxx()/32),0,j,j);break;
case 6: setrgbpalette (101+i+(getmaxx()/32),j,0,j);break;
case 7: setrgbpalette (101+i+(getmaxx()/32),j,j,j);break;
case 8: setrgbpalette (101+i+(getmaxx()/32),j,0,63-j);break;
case 9: setrgbpalette (101+i+(getmaxx()/32),63,63-j,0);break;
}
rectangle (i+x1,i+y1,x2-i,y2-i);
delay(5+(getmaxx()/32)-i);
}
i=(getmaxx()/32);
setcolor (101+((getmaxx()/32)));
rectangle (i+x1,i+y1,x2-i,y2-i);
}
void flashcolor(int c,int r,int g,int b){
int i,j,r1=0,g1=0,b1=10;
if (b<10) b=10;
while (r1<63 || g1<63 || b1<63) {
if (r1<63) r1++;
if (g1<63) g1++;
if (b1<63) b1++;
setrgbpalette (c,r1,g1,b1);
delay(2);}
r1=63;g1=63;b1=63;
while (r1>r || g1>g || b1>b) {
if (r1>r) r1--;
if (g1>g) g1--;
if (b1>b) b1--;
setrgbpalette (c,r1,g1,b1);
delay(5);}}
void unflashcolor(int c,int r,int g,int b){
if (b<10) b=10;
int i,j,r1=r,g1=g,b1=b;
while (r1<63 || g1<63 || b1<63) {
if (r1<63) r1++;
if (g1<63) g1++;
if (b1<63) b1++;
setrgbpalette (c,r1,g1,b1);
delay(2);}
r1=63;g1=63;b1=63;
while (r1>0 || g1>0 || b1>10) {
if (r1>0) r1--;
if (g1>0) g1--;
if (b1>10) b1--;
setrgbpalette (c,r1,g1,b1);
delay(5);}}

void paneclose(){int q;
for (q=getmaxx()/8;q<=getmaxx()-getmaxx()/32;q++)
{setcolor(15);
line (96,getmaxy()/2-getmaxx()/32,q,0);
line (96,getmaxy()/2-getmaxx()/32,q,getmaxy()-getmaxx()/32);
delay(1);
setcolor(0);
line (96,getmaxy()/2-getmaxx()/32,q,0);
line (96,getmaxy()/2-getmaxx()/32,q,getmaxy()-getmaxx()/32);
}
for (q=-getmaxx()/32;q<=(getmaxy()-getmaxx()/32)/2;q++)
{setcolor(15);
line (96,getmaxy()/2-getmaxx()/32,getmaxx(),q);
line (96,getmaxy()/2-getmaxx()/32,getmaxx(),((getmaxy()-getmaxx()/32))-q);
delay(1);
setcolor(0);
line (96,getmaxy()/2-getmaxx()/32,getmaxx(),q);
line (96,getmaxy()/2-getmaxx()/32,getmaxx(),((getmaxy()-getmaxx()/32))-q);
}                }
void showpane(char s[]){
for (int h=0;h<=int((1.5)*63);h++)
{setcolor(150+h);setrgbpalette (150+h,63,63-int(h/1.5),0);
ellipse (0,(getmaxy()/2)-getmaxx()/32,0,360,h,(getmaxy()-(getmaxx()/32))/2);delay(3);}
setcolor (14);
settextstyle (3,1,5);
settextjustify(1,1);
outtextxy (20,getmaxy()/2-getmaxx()/32,s);
};
int setmenu(char menuname[],char item1[],char item2[],char item3[],char item4[],char item5[],char item6[]){
mouse mymouse;
mymouse.install();
mymouse.setplace((getmaxx()/2)-getmaxx()/32,getmaxy()/10);
mymouse.updatecursor();
char c=255;
int io=0,i=1;
setrgbpalette (16,0,0,0);
showfulltime();
flashcolor (16,20,0,63);
char s[50]="",s1[50]="1";
showpane (menuname);
settextstyle (7,0,1);
settextjustify(1,2);
setrgbpalette (3,20,0,0);
setcolor(3);
int maxw=0;
int maxitem=0;
if (textwidth(item1)>maxw) maxw=textwidth(item1);
if (textwidth(item2)>maxw) maxw=textwidth(item2);
if (textwidth(item3)>maxw) maxw=textwidth(item3);
if (textwidth(item4)>maxw) maxw=textwidth(item4);
if (textwidth(item5)>maxw) maxw=textwidth(item5);
if (textwidth(item6)>maxw) maxw=textwidth(item6);

if (item1[0]!='\0') {outtextxy ((getmaxx()/2)-(getmaxx()/32),100,item1);maxitem=1;}
if (item2[0]!='\0') {outtextxy ((getmaxx()/2)-(getmaxx()/32),130,item2);maxitem=2;}
if (item3[0]!='\0') {outtextxy ((getmaxx()/2)-(getmaxx()/32),160,item3);maxitem=3;}
if (item4[0]!='\0') {outtextxy ((getmaxx()/2)-(getmaxx()/32),190,item4);maxitem=4;}
if (item5[0]!='\0') {outtextxy ((getmaxx()/2)-(getmaxx()/32),220,item5);maxitem=5;}
if (item6[0]!='\0') {outtextxy ((getmaxx()/2)-(getmaxx()/32),250,item6);maxitem=6;}
border (getmaxx()/2-getmaxx()/16-(maxw/2),80,getmaxx()/2+(maxw/2),120+(maxitem*30),-2);
flashcolor (3,0,20,20);
int q;
int iold=0;
do {
c=255;
strcpy (s,time());
if (strcmp(s1,s)) {showfulltime();strcpy (s1,s);}
settextstyle (7,0,1);
settextjustify(1,2);
mymouse.updatecursor();
if (i!=iold){
if (mymouse.isin(250,100,360,123)&&(maxitem>=1)) {i=1;if (mymouse.prsleft()) {i=1;c=13;}}
if (i==1) setcolor(15); else setcolor(3);
if (item1[0]!='\0')outtextxy ((getmaxx()/2)-(getmaxx()/32),100,item1);else if (i>0) i=0;
if (mymouse.isin(250,130,360,153)&&(maxitem>=2)) {i=2;if (mymouse.prsleft()) {i=2;c=13;}}
if (i==2) setcolor(15); else setcolor(3);
if (item2[0]!='\0')outtextxy ((getmaxx()/2)-(getmaxx()/32),130,item2); else if (i>1) i=1;
if (mymouse.isin(250,160,360,183)&&(maxitem>=3)) {i=3;if (mymouse.prsleft()) {i=3;c=13;}}
if (i==3) setcolor(15); else setcolor(3);
if (item3[0]!='\0')outtextxy ((getmaxx()/2)-(getmaxx()/32),160,item3); else if (i>2) i=1;
if (mymouse.isin(250,190,360,213)&&(maxitem>=4)) {i=4;if (mymouse.prsleft()) {i=4;c=13;}}
if (i==4) setcolor(15); else setcolor(3);
if (item4[0]!='\0')outtextxy ((getmaxx()/2)-(getmaxx()/32),190,item4); else if (i>3) i=1;
if (mymouse.isin(250,220,360,243)&&(maxitem>=5)) {i=5;if (mymouse.prsleft()) {i=5;c=13;}}
if (i==5) setcolor(15); else setcolor(3);
if (item5[0]!='\0')outtextxy ((getmaxx()/2)-(getmaxx()/32),220,item5); else if (i>4) i=1;
if (mymouse.isin(250,250,360,273)&&(maxitem>=6)) {i=6;if (mymouse.prsleft()) {i=6;c=13;}}
if (i==6) setcolor(15); else setcolor(3);
if (item6[0]!='\0')outtextxy ((getmaxx()/2)-(getmaxx()/32),250,item6); else if (i>5) i=1;
}
mymouse.updatecursor();
if (kbhit()) c=getch();
if ((c==0)&&(kbhit())) {
c=getch();
if (c==72) i--;
if (c==80) i++;
if (i<1) i=maxitem;
if (i>maxitem) i=1;
}
//if ((c==13) && (i==5)) break;
if ((c==13) && (i<=maxitem)){
paneclose();
break;
}
} while (c!=400);
return i;
};



/*int huge temp(void){return 0;}
void initsvga(){
int drv=installuserdriver ("svga256",temp),md=2;
initgraph(&drv,&md,"bgi");
setrgbpalette (0,20,0,2);
delay (1000);
pageborder(-9);
getkeys();
} */
