#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
void cadr(int x1,int y1,int x2, int y2);
struct people{
char first_name[15],fam_name[15],tell_num[12],address[30];
};
void add_field(){
FILE *fp;
struct people person;
fp=fopen ("saved.nav","a+b");
textcolor (15);cprintf ("\n\rEnter first   name    : ");textcolor(10);gets(person.first_name);
textcolor (15);cprintf ("\n\rEnter familly name    : ");textcolor(10);gets(person.fam_name);
textcolor (15);cprintf ("\n\rEnter telephone number: ");textcolor(10);gets(person.tell_num);
textcolor (15);cprintf ("\n\rEnter address         : ");textcolor(10);gets(person.address);
textcolor(0);
fwrite(&person, sizeof(person), 1, fp); /* write struct s to file */
cprintf ("\n\rData added to file, hit any key...");
getch();
clrscr();
fclose(fp);
}
void find_sone(int zz){
// zz=1 ====> find all
// zz=0 ====> find name
FILE *fp;
struct people person,onetofind;
fp=fopen("saved.nav","a+b");
fseek(fp,0l,SEEK_SET);
if (!zz){textcolor (15);cprintf ("\n\rEnter first name    : ");textcolor(10);gets(onetofind.first_name);}
window (1,1,80,25);
textcolor(15);
textbackground(1);clrscr();
int y=0;
int flag=0;
gotoxy (1,1);
textcolor (14);
cprintf ("\n\r³%15s³%15s³%12s³%30s³","First nameתתתתת", "Familly nameתתת","Tel.numberתת","Addressתתתתתתתתתתתתתתתתתתתתתתת");
textcolor(10);
while (!feof(fp)){
fread(&person, sizeof(person), 1, fp); /* write struct s to file */
if (zz) strcpy (onetofind.first_name,person.first_name);
if (feof(fp)) break;
if (strcmp(onetofind.first_name,person.first_name)==0){
flag++;
textcolor(10);
cprintf ("\n\r³%15s³%15s³%12s³%30s³",person.first_name,person.fam_name,person.tell_num,person.address);
if ((flag%22)==0) {textcolor(9);cprintf ("\n\rPress any key to show more...");getch();gotoxy (1,1);
textcolor (14);
cprintf ("\n\r³%15s³%15s³%12s³%30s³","First nameתתתתת", "Familly nameתתת","Tel.numberתת","Addressתתתתתתתתתתתתתתתתתתתתתתת");gotoxy (1,24);textcolor(9);
cprintf ("\n\r³%15s³%15s³%12s³%30s³","---------------", "---------------","------------","------------------------------");
}
}
}
textcolor (9);
if (flag) cprintf ("\n\r%d items found, Hit any key to go to main menu...",flag); else {textcolor(12);cprintf ("\n\rData not found... press any key...");}
getch();
fclose(fp);
clrscr();
cadr(20,5,60,18);
window (21,6,59,17);
textbackground(3);
clrscr();
}

void delete_one(){
FILE *fp,*temp;
struct people person,onetofind;
fp=fopen("saved.nav","a+b");
temp=fopen("temp.arm","w");
fseek(fp,0l,SEEK_SET);
textcolor (15);cprintf ("\n\rEnter first   name    : ");textcolor(10);gets(onetofind.first_name);
textcolor (15);cprintf ("\n\rEnter familly name    : ");textcolor(10);gets(onetofind.fam_name);
textcolor (15);cprintf ("\n\rEnter telephone number: ");textcolor(10);gets(onetofind.tell_num);
//textcolor (15);cprintf ("\n\rEnter address         : ");textcolor(10);gets(onetofind.address);
window (1,1,80,25);
textcolor(15);
textbackground(1);clrscr();
int flag=0,nowflag=0;
while (!feof(fp)){
nowflag=0;
fread(&person, sizeof(person), 1, fp); /* write struct s to file */
if (feof(fp)) break;
if ((strcmp(onetofind.first_name,person.first_name)==0)&&(strcmp(onetofind.fam_name,person.fam_name)==0)&&
   (strcmp(onetofind.tell_num,person.tell_num)==0)){nowflag=1;flag++;}
if (!nowflag) {fwrite(&person, sizeof(person), 1, temp);}
}
textcolor(9);
if (flag) cprintf ("\n\r%d items deleted, Hit any key to go to main menu...",flag); else {textcolor(12);cprintf ("\n\rData not found... press any key...");}
getch();
fclose(fp);
fclose(temp);
remove ("saved.nav");
rename ("temp.arm","saved.nav");
clrscr();
cadr(20,5,60,18);
window (21,6,59,17);
textbackground(3);
clrscr();
}


void main(){
textmode(3);
textbackground(1);
textcolor (15);
clrscr();
cadr(20,5,60,18);
window (21,6,59,17);
int choice=0;
textbackground (3);
clrscr();
while (choice!=5){
textbackground (3);
textcolor (11);
cprintf ("1.Add to file\n\r");
cprintf ("2.Find someone\n\r");
cprintf ("3.Show all\n\r");
cprintf ("4.Delete from file\n\r");
cprintf ("5.Exit program\n\r");
textcolor (10);cprintf ("Enter your choice: ");
char c=0;
while ((c<'1')||(c>'5')){
c=getch();
}
textcolor(14);
choice=c-48;
cprintf ("%i\n\r\n\r",choice);
switch (choice){
case 1:add_field(); break;
case 2:find_sone(0); break;
case 3:find_sone(1);  break;
case 4:delete_one();break;
}}
window (1,1,80,25);
textbackground (0);
clrscr();
cprintf ("Bye bye!!!");
delay(1000);
}
void cadr(int x1,int y1,int x2, int y2){
textcolor(15);
textbackground(1);
for (int i=x1+1;i<=x2-1;i++){
gotoxy (i,y1);cprintf("ֽ");// alt+number (180/186/...) = ÷¹¸ֳ
gotoxy (i,y2);cprintf("ֽ");}
for (i=y1+1;i<=y2-1;i++){
gotoxy (x1,i); cprintf("÷");
gotoxy (x2,i);cprintf("÷");}
gotoxy (x1,y1);
cprintf("ֹ");
gotoxy(x2,y1);
cprintf ("»");
gotoxy(x1,y2);
cprintf("ָ");
gotoxy (x2,y2);
cprintf ("¼");
}
