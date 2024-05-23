	#include <string.h>
	#include <fstream.h>
	#include <iostream.h>
	#include <conio.h>
	#include <iostream.h>
	#include <fstream.h>
	#include <dos.h>
	#include <stdlib.h>
	#include <mouse.h>
	#include <process.h>
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/
	#include "mse.h"
	#include "supercrt.h"
//////////////////////////////////////////////////////////////////////////////
int exist=0,superfast=1;
//////////////////////////////////////////////////////////////////////////////
struct file_rec{
unsigned long int number;
char code;
};

int fileexist(char *s){
int i=0;
filebuf myfile;
myfile.open (s, ios::nocreate | ios::in |ios::binary);
if (myfile.is_open()) i=1; else i=0;
//myfile.seekg(0,ios::beg);
//if (myfile.eof()) i=0;
myfile.close();
myfile.open (s, ios::out);
myfile.close();

ifstream myfile2;
file_rec frec,*rec;
//int i;
myfile2.open (s, ios::nocreate | ios::in|ios::binary);
myfile2.seekg(0,ios::beg);
myfile2.read ((char*)rec,sizeof(file_rec));
//myfile2.read (&i,sizeof(file_rec));

//cout<<rec->number<<"<<"<<myfile2.tellg()<<" --- "<<myfile2.eof();getch();
if (myfile2.eof()) i=0;
myfile2.close();
return i;
}
//////////////////////////////////////////////////////////////////////////////
void create_file(){
tcolor (12+128,4);center ("  Please Wait.....      ",4);
sound(200);
delay(100);
nosound();
file_rec frec,*rec;

int i=0;
ofstream myfile;
myfile.open ("amin.dat",ios::out|ios::binary);
//if (myfile.is_open()) exist=1; else exist=0;
tcolor (12,4);
for (unsigned long int j=1;j<=100000;j++){
if (kbhit()){if (getch()==27){
//delete_file();
myfile.close();
myfile.open ("amin.dat",ios::out|ios::binary);
myfile.close();
cursorsize();
//mymouse.hide();
tcolor(7,0);
clr();
textmode (C80);
exit(0);
}}

if ((!(j%100))||(!superfast)){gotoxy (45,4);cprintf ("%%%0.2f",(float)j/1000.0);}
//delay(1);
rec->number=j;
if (j<=50000){rec->code=0;} else {rec->code=0;}
myfile.write ((char*)rec,sizeof(file_rec));
}
myfile.close();
if (fileexist("amin.dat")) (exist=1); else (exist=0);
if (!exist) {tcolor (12,4);center ("  File does not exist!  ",4);} else
	    {tcolor (10,4);center ("      File exists!      ",4);}
sound(500);
delay(050);
sound(100);
delay(050);
sound(600);
delay(050);
sound(300);
delay(050);
sound(200);
delay(050);
nosound();

};
//////////////////////////////////////////////////////////////////////////////
void delete_file(){
tcolor (12+128,4);center ("  Please Wait.........  ",4);
tcolor (12,4);
ofstream myfile;
myfile.open ("amin.dat",ios::out|ios::binary);
myfile.close();
if (fileexist("amin.dat")) (exist=1); else (exist=0);
if (!exist) {tcolor (12,4);center ("  File does not exist!  ",4);} else
	    {tcolor (10,4);center ("      File exists!      ",4);}
sound(500);
delay(100);
nosound();
};
//////////////////////////////////////////////////////////////////////////////
void measure_sparse(){
struct  time t;
double spt;
long double timer,timero;

tcolor(15,4);
center ("Sparse    Reading time: ####.##",6);
tcolor (14+128,4);center ("  Please Wait.........  ",4);
tcolor(9,1);
recadr(7,8,73,10,10);
ifstream myfile;
file_rec frec,*rec;
myfile.open ("amin.dat", ios::nocreate | ios::in|ios::binary);
myfile.seekg(0,ios::beg);
unsigned long int p1=0;
unsigned long int p2=50001;
unsigned long int j=0;
int k=0,ko=0;
gettime(&t);
timero=(t.ti_hour*3600)+ (t.ti_min*60)+ (t.ti_sec)+ ((float)t.ti_hund/100.0);
int tirtapar;
int tapartoor=-1;
while (!myfile.eof()){
if (kbhit()){if (getch()==27){
cursorsize();
//mymouse.hide();
tcolor(7,0);
clr();
textmode (C80);
exit(0);
}}
tapartoor=-tapartoor;
/*for (tirtapar=1;tirtapar<=10;tirtapar++){
myfile.seekg((p1)*sizeof(file_rec),ios::beg);
myfile.seekg((p2)*sizeof(file_rec),ios::beg);}*/
myfile.seekg(0,ios::beg);
if (tapartoor==1){
myfile.seekg((p2)*sizeof(file_rec),ios::beg);
myfile.seekg((p1++)*sizeof(file_rec),ios::beg);
myfile.read ((char*)rec,sizeof(file_rec));
if ((!(p1%100))||(!superfast)){gotoxy (8,9);if ((rec->number)<50001)cout<<rec->number<<" ";}}
/*for (tirtapar=1;tirtapar<=10;tirtapar++){
myfile.seekg((p2)*sizeof(file_rec),ios::beg);
myfile.seekg((p1)*sizeof(file_rec),ios::beg);}*/
if (tapartoor==-1){
myfile.seekg((p1)*sizeof(file_rec),ios::beg);
myfile.seekg((p2++)*sizeof(file_rec),ios::beg);
myfile.read ((char*)rec,sizeof(file_rec));
if ((!(p2%100))||(!superfast)){gotoxy (41,9);if ((rec->number)>50000)cout<<rec->number<<" ";}}
//gotoxy (40,9);
//cprintf ("*");
k=8+(((float)p1/100000.0)*(71.0-7.0));
if ((!superfast)||(k!=ko)){
tcolor(11,3);
ko=k;
gotoxy (k,9);
cprintf (" ");
k=10+(((float)p2/100000.0)*(70.0-8.0));
gotoxy (k,9);
cprintf (" ");
}
j++;
if (!(j%100)||(j<3)||(!superfast)){
tcolor (12,4);
gotoxy (45,4);cprintf ("%%%0.2f",(float)j/1000.0);
tcolor(15,4);
gettime(&t);
timer=(t.ti_hour*3600)+ (t.ti_min*60)+ (t.ti_sec)+ ((float)t.ti_hund/100.0);
if (timer-timero<0){timer=timer+(24*3600);}
spt=timer-timero;
gotoxy(49,6);
cprintf ("%07.2f",spt);}
}
myfile.close();
tcolor(15,4);
gettime(&t);
timer=(t.ti_hour*3600)+ (t.ti_min*60)+ (t.ti_sec)+ ((float)t.ti_hund/100.0);
if (timer-timero<0){timer=timer+(24*3600);}
spt=timer-timero;
gotoxy(49,6);
cprintf ("%07.2f",spt);

delay(1000);
tcolor (15,2);
clr(6,8,74,10);
tcolor(0,4);
center ("Sparse    Reading time: ####.##",6);
gotoxy(49,6);
cprintf ("%07.2f",spt);
if (fileexist("amin.dat")) (exist=1); else (exist=0);
if (!exist) {tcolor (12,4);center ("  File does not exist!  ",4);} else
	    {tcolor (10,4);center ("      File exists!      ",4);}
sound(500);
delay(100);
nosound();

};
//////////////////////////////////////////////////////////////////////////////
void measure_conti(){
struct  time t;
double ctt;
long double timer,timero;

tcolor(15,4);
center ("Continues Reading time: ####.##",5);
tcolor (14+128,4);center ("  Please Wait.........  ",4);
tcolor(9,1);
recadr(7,8,73,10,10);
ifstream myfile;
file_rec frec,*rec;
myfile.open ("amin.dat", ios::nocreate | ios::in|ios::binary);
myfile.seekg(0,ios::beg);
unsigned long int j=0;
int k=0,ko=0;
gettime(&t);
timero=(t.ti_hour*3600)+ (t.ti_min*60)+ (t.ti_sec)+ ((float)t.ti_hund/100.0);
while (!myfile.eof()){
if (kbhit()){if (getch()==27){
cursorsize();
//mymouse.hide();
tcolor(7,0);
clr();
textmode (C80);
exit(0);
}}
myfile.seekg((j++)*sizeof(file_rec),ios::beg);
myfile.read ((char*)rec,sizeof(file_rec));
if ((!(j%100))||(!superfast)){gotoxy (8,9);cout<<rec->number<<" ";}
k=8+(((float)j/100000.0)*(71.0-7.0));
if ((!superfast)||(k!=ko)){
tcolor(11,3);
ko=k;
gotoxy (k,9);
cprintf (" ");
}
if (!(j%100)||(!superfast)){
tcolor (12,4);
gotoxy (45,4);cprintf ("%%%0.2f",(float)j/1000.0);
tcolor(15,4);
gettime(&t);
timer=(t.ti_hour*3600)+ (t.ti_min*60)+ (t.ti_sec)+ ((float)t.ti_hund/100.0);
if (timer-timero<0){timer=timer+(24*3600);}
ctt=timer-timero;
gotoxy(49,5);
cprintf ("%07.2f",ctt);}
}
myfile.close();
tcolor(15,4);
gettime(&t);
timer=(t.ti_hour*3600)+ (t.ti_min*60)+ (t.ti_sec)+ ((float)t.ti_hund/100.0);
if (timer-timero<0){timer=timer+(24*3600);}
ctt=timer-timero;
gotoxy(49,5);
cprintf ("%07.2f",ctt);

delay(1000);
tcolor (15,2);
clr(6,8,74,10);
tcolor(0,4);
center ("Continues Reading time: ####.##",5);
gotoxy(49,5);
cprintf ("%07.2f",ctt);
if (fileexist("amin.dat")) (exist=1); else (exist=0);
if (!exist) {tcolor (12,4);center ("  File does not exist!  ",4);} else
	    {tcolor (10,4);center ("      File exists!      ",4);}
sound(500);
delay(100);
nosound();



};
//////////////////////////////////////////////////////////////////////////////
int main(){
//clrscr();
nosound();
exist=fileexist("amin.dat");
initializescreen(1);
cursorsize(-1,-1);
tcolor(14,2);
recadr(4,2,76,24,5);
getkeys();
mouse mymouse;
mymouse.install();
mymouse.hide();
tcolor (10,2);
cursorsize(-1,-1);
centerg("ESC=Exit --- File structures, Exam number one",20);
centerg("Program of Sparse and continues file reading, ",21);
centerg("By: Amin Safinejad, Vahid Panahi, Rahim Tofigh",22);
tcolor (7,2);
centerg("Use arrows, Enter, ESC or mouse to Create, Delete or Read 'amin.dat'",23);
tcolor(14,4);
cursorsize(-1,-1);
recadr(22,3,57,7,10);
if (!exist) {tcolor (12,4);centerg ("File does not exist!",4);} else
	    {tcolor (10,4);centerg ("    File exists!    ",4);}
tcolor (0,4);
centerg ("Continues Reading time: ----.--",5);
centerg ("Sparse    Reading time: ----.--",6);
tcolor(15,0);
cursorsize(-1,-1);
recadr(27,11,53,17,10);               if (exist) tcolor(7);else tcolor (9,1);
centerg ("¯ (RE)Creat File      ",12);if (exist) tcolor (9); else tcolor (8);
centerg ("¯ Delete File         ",13);
centerg ("¯ Start sparse Read   ",14);
centerg ("¯ Start continues Read",15);tcolor(9);
centerg ("¯ Exit to O.S.        ",16);
mymouse.win(28,12,52,16);
int menu_item=1;
if (exist) menu_item=3;
char k=255;
int b[6]={0};
//mymouse.show();
int tp;
int msy=mymouse.gety();
getkeys();
cursorsize(-1,-1);
while (1)  {
if (msy!=mymouse.gety()){
msy=mymouse.gety();
menu_item=msy-11;
//gotoxy (1,1);cout<<msy<<" ";
}
if (kbhit()) k=getch(); else k=255;
if (k==27){menu_item=5;}
for (tp=1;tp<=5;tp++) if (tp==menu_item) b[tp]=1; else b[tp]=0;
if (k==0) {
	   k=getch();
	   if (k==72) menu_item--;
	   if (k==80) menu_item++;
	   }
if ((k==13)||(mymouse.prsleft())){
	   cursorsize(-1,-1);
if (menu_item==5) break;
switch (menu_item){
case 1:           create_file();   if (exist)menu_item=3;break;
case 2:if (exist){delete_file();   menu_item=1;}break;
case 3:if (exist){measure_sparse();menu_item=4;}break;
case 4:if (exist){measure_conti(); menu_item=5;}break;
}
getkeys();
}
if (menu_item<1) menu_item=5;
if (menu_item>5) menu_item=1;

				      if (exist) tcolor (7,b[1]); else tcolor (9,b[1]);
center ("¯ (RE)Creat File       ",12);if (exist) tcolor (9,b[2]); else tcolor (8,b[2]);
center ("¯ Delete File          ",13);if (exist) tcolor (9,b[3]); else tcolor (8,b[3]);
center ("¯ Start sparse Read    ",14);if (exist) tcolor (9,b[4]); else tcolor (8,b[4]);
center ("¯ Start continues Read ",15);tcolor(9,b[5]);
center ("¯ Exit to O.S.         ",16);
if (k==27)break;
}
cursorsize();
mymouse.hide();
tcolor(7,0);
clr();
textmode (C80);
return 0;
}