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
void store(){
mouse mymouse;
mymouse.install();
char c;
int io=0,i=1;
//border (220,80,380,270,-2);
setrgbpalette (16,0,0,0);
showfulltime();
flashcolor (16,20,0,63);
char s[50]="",s1[50]="1";
showpane ("Store");
settextstyle (7,0,1);
settextjustify(1,2);
setrgbpalette (3,20,0,0);
setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),100,"Add to Inventory");
outtextxy ((getmaxx()/2)-(getmaxx()/32),130,"Remove Itimes");
outtextxy ((getmaxx()/2)-(getmaxx()/32),160,"Send to sell");
outtextxy ((getmaxx()/2)-(getmaxx()/32),190,"Budget");
outtextxy ((getmaxx()/2)-(getmaxx()/32),220,"Exit");
border (190,80,410,270,-2);
flashcolor (3,0,20,20);
int q,ioo=-1;
do {
c=255;
strcpy (s,time());
if (strcmp(s1,s)) {showfulltime();strcpy (s1,s);}
settextstyle (7,0,1);
settextjustify(1,2);
mymouse.updatecursor();
if (mymouse.isin(210,100,390,123)) {i=1;if (mymouse.prsleft()) {i=1;c=13;}}
if (i==1) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),100,"Add to Inventory");
if (mymouse.isin(210,130,390,153)) {i=2;if (mymouse.prsleft()) {i=2;c=13;}}
if (i==2) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),130,"Remove Itimes");
if (mymouse.isin(210,160,390,183)) {i=3;if (mymouse.prsleft()) {i=3;c=13;}}
if (i==3) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),160,"Send to sell");
if (mymouse.isin(210,190,390,213)) {i=4;if (mymouse.prsleft()) {i=4;c=13;}}
if (i==4) setcolor(15); else setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),190,"Budget");
if (mymouse.isin(210,220,390,243)) {i=5;if (mymouse.prsleft()) {i=5;c=27;}}
if (i==5) setcolor(15);io=i;} else setcolor(3);
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
paneclose();
setcolor (14);
showpane("Store");
//settextstyle (3,1,5);
//settextjustify(1,1);
//outtextxy (20,getmaxy()/2-getmaxx()/32,"Store");
settextstyle (7,0,1);
settextjustify(1,2);
setrgbpalette (3,20,0,0);
setcolor(3);
outtextxy ((getmaxx()/2)-(getmaxx()/32),100,"Add to Inventory");
outtextxy ((getmaxx()/2)-(getmaxx()/32),130,"Remove Itimes");
outtextxy ((getmaxx()/2)-(getmaxx()/32),160,"Send to sell");
outtextxy ((getmaxx()/2)-(getmaxx()/32),190,"Budget");
outtextxy ((getmaxx()/2)-(getmaxx()/32),220,"Exit");
border (190,80,410,270,-2);
flashcolor (3,0,20,20);
}} while (c!=27);
//setviewport(0,0,getmaxx(),getmaxy(),1);

};
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
paneclose();
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
