#include "stdlib.h"
#include "conio.h"
#include "process.h"
#include "stdio.h"
#include "iostream.h"
#include "string.h"
#include "fstream.h"
#include "dos.h"
#include "malloc.h"
#include "graphics.h"
// Forooshande's own headers:
#include "foo_date.h"
#include "foo_keyb.h"
#include "foo_mous.h"
#include "foo_grpe.h"
class goods{int number;
	    struct dosdate_t expdate,prodate,entdate;
	    char name[20],producer[20],code[10],group[15];
	    unsigned long buyprice,sellprice;
	    char location; // 1=store, 2=sell
	    };
void manage(){};
void account(){};
void cash(){};
void setmenu(char menuname[],char item1[],char item2[],char item3[],char item4[],char item5[],char item6[]){
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
border (220-(maxw/4),80,380+(maxw/4),120+(maxitem*30),-2);
flashcolor (3,0,20,20);
int q;
do {
c=255;
strcpy (s,time());
if (strcmp(s1,s)) {showfulltime();strcpy (s1,s);}
settextstyle (7,0,1);
settextjustify(1,2);
mymouse.updatecursor();
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
if (mymouse.isin(250,250,360,273)&&(maxitem>=6)) {i=6;if (mymouse.prsleft()) {i=6;c=13;}} else if (i>5) i=1;
if (i==6) setcolor(15); else setcolor(3);
if (item6[0]!='\0')outtextxy ((getmaxx()/2)-(getmaxx()/32),250,item6); else if (i>5) i=1;

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
} while (c!=27);
};
void store(){setmenu("Store","Add to inventory","Remove Items","Send for sell","Exit","","");};
void main(){
randomize();
textcolor(15);
textbackground(1);
clrscr();
initsvga();
mouse mymouse;
mymouse.install();
mymouse.setplace((getmaxx()/2)-getmaxx()/32,getmaxy()/10);
mymouse.updatecursor();
char c;
int io=0,i=1;
//border (220,80,380,270,-2);
setrgbpalette (16,0,0,0);
showfulltime();
flashcolor (16,20,0,63);
char s[50]="",s1[50]="1";
showpane ("Main menu");
settextstyle (7,0,1);
settextjustify(1,2);
setrgbpalette (3,20,0,0);
setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),100,"Manage");
outtextxy ((getmaxx()/2)-(getmaxx()/32),130,"Accounting");
outtextxy ((getmaxx()/2)-(getmaxx()/32),160,"Store");
outtextxy ((getmaxx()/2)-(getmaxx()/32),190,"Cashing");
outtextxy ((getmaxx()/2)-(getmaxx()/32),220,"Exit");
border (220,80,380,270,-2);
flashcolor (3,0,20,20);
int q;
do {
c=255;
strcpy (s,time());
if (strcmp(s1,s)) {showfulltime();strcpy (s1,s);}
settextstyle (7,0,1);
settextjustify(1,2);
mymouse.updatecursor();
if (mymouse.isin(250,100,360,123)) {i=1;if (mymouse.prsleft()) {i=1;c=13;}}
if (i==1) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),100,"Manage");
if (mymouse.isin(250,130,360,153)) {i=2;if (mymouse.prsleft()) {i=2;c=13;}}
if (i==2) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),130,"Accounting");
if (mymouse.isin(250,160,360,183)) {i=3;if (mymouse.prsleft()) {i=3;c=13;}}
if (i==3) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),160,"Store");
if (mymouse.isin(250,190,360,213)) {i=4;if (mymouse.prsleft()) {i=4;c=13;}}
if (i==4) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),190,"Cashing");
if (mymouse.isin(250,220,360,243)) {i=5;if (mymouse.prsleft()) {i=5;c=27;}}
if (i==5) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),220,"Exit");
//if (mymouse.prsleft()) {i=1;c=13;}
mymouse.updatecursor();
if (kbhit()) c=getch();
if ((c==0)&&(kbhit())) {
c=getch();
if (c==72) i--;
if (c==80) i++;
if (i<1) i=5;
if (i>5) i=1;
}
if ((c==13) && (i==5)) break;
if (c==13) {
//showpane("");
paneclose();
switch (i){
case 1:manage();break;
case 2:account();break;
case 3:store();break;
case 4:cash();break;
}
//paneclose();
showpane("Main menu");
setcolor (14);
//settextstyle (3,1,5);
//settextjustify(1,1);
//outtextxy (20,getmaxy()/2-getmaxx()/32,"Main menu");
settextstyle (7,0,1);
settextjustify(1,2);
setrgbpalette (3,20,0,0);
setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),100,"Manage");
outtextxy ((getmaxx()/2)-(getmaxx()/32),130,"Accounting");
outtextxy ((getmaxx()/2)-(getmaxx()/32),160,"Store");
outtextxy ((getmaxx()/2)-(getmaxx()/32),190,"Cashing");
outtextxy ((getmaxx()/2)-(getmaxx()/32),220,"Exit");
border (220,80,380,270,-2);
flashcolor (3,0,20,20);

}
} while (c!=27);
setviewport(0,0,getmaxx(),getmaxy(),1);
niceeffect(0);
}
