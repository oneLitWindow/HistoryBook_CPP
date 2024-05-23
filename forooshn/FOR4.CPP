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
void store(){int choice=0;

	     while (choice!=5){
	     choice=setmenu("Store","Add to inventory","Remove Items","Send for sell","Budget","Exit","");};
	     }
void main(){
randomize();
textcolor(15);
textbackground(1);
clrscr();
initsvga();
int choice=0;
while (choice!=5){
choice=setmenu ("Main menu","Manage","Accounting","Store","Cashing","Exit","");
switch (choice){
case 1:manage();break;
case 2:account();break;
case 3:store();break;
case 4:cash();break;
}               }
setviewport(0,0,getmaxx(),getmaxy(),1);
niceeffect(0);
}
//##############################################################
class objects {
   char name[20],group[20],procedure[20];
   int number;
   float buyprice,selprice;
   long int code;
   struct date expdate,prodate,entdate;
public:
void enter();
struct date getdates(char str[]);
int valid(int x,char s[]);
void save(struct objects);
}
//*** MAIN *******************************************************************
void main()
{
   enter();
   printf("\n%d %d %d",list.entdate.da_year,list.entdate.da_mon,list.entdate.da_day);
   save(list);
   getch();
}
//*** Enter Function *********************************************************
void goods::enter() {
  char temp[30];
  clrscr();
  do {
	printf("\nEnter name of product: ");
	gets(list.name);
  }while ((!strlen(list.name)) || (!valid(1,list.name)));
  do {
	printf("\nEnter group of product: ");
	gets(list.group);
  }while ((!strlen(list.group)) || (!valid(1,list.group)));
  do {
	printf("\nEnter procedure: ");
	gets(list.procedure);
  }while ((!strlen(list.procedure)) || (!valid(1,list.procedure)));
  do {
	printf("\nEnter number of product: ");
	gets(temp);
  }while ((!strlen(temp)) || (!valid(0,temp)));
  list.number=atoi(temp);
  do {
	printf("\nEnter buyprice: ");
	gets(temp);
  }while ((!strlen(temp)) || (!valid(2,temp)));
  list.buyprice=atof(temp);
  strcpy(temp,'\0');
  do {
	printf("\nEnter percent of ...: %%");
	gets(temp);
  }while ((!strlen(temp)) || (atoi(temp)>100) || (!valid(0,temp)));
  list.selprice=list.buyprice*(1+atof(temp)/100);
  printf("\nselprice is : %f\n",list.selprice);
  list.prodate=getdates("por");
  list.expdate=getdates("exp");
  getdate(&list.entdate);
}
//*** Gatdates Function ******************************************************
struct date getdates(char str[3]) {
  struct date d;
  char temp[3]={'\0'};
  printf("\nEnter %sdate: 2000 : 00 : 00",str);
  do{
	gotoxy(18,wherey());
	printf("00");
	gotoxy(18,wherey());
	temp[0]=getche();
	temp[1]=getche();
  }while((temp[0]=='\r') || (temp[1]=='\r') || (!valid(0,temp)));
  d.da_year=2000+atoi(temp);
  do{
	gotoxy(23,wherey());
	printf("00");
	gotoxy(23,wherey());
	temp[0]=getche();
	temp[1]=getche();
  }while(((temp[0]=='\r') || (temp[1]=='\r')) || (atoi(temp)<1) || (atoi(temp)>12) || (!valid(0,temp)));
  d.da_mon=atoi(temp);
  do{
	gotoxy(28,wherey());
	printf("00");
	gotoxy(28,wherey());
	temp[0]=getche();
	temp[1]=getche();
  }while(((temp[0]=='\r') || (temp[1]=='\r')) || (atoi(temp)<1) || (atoi(temp)>31) || (!valid(0,temp)));
  d.da_day=atoi(temp);
  return (d);
}
//*** Valid Function *********************************************************
int valid(int x,char s[]) {
   int i=0;
   if (x==0)
	while (s[i]) {
		if (!isdigit(s[i])) return 0;
		i++;
	}
   if (x==1)
	while (s[i]) {
		if ((!isalpha(s[i])) && (!isspace(s[i]))) return 0;
		i++;
	}
   if (x==2)
	while (s[i]) {
		if ((!isdigit(s[i])) && (s[i]!='.')) return 0;
		i++;
	}

   return 1;
}
//*** Save Function **********************************************************
void save(struct objects s) {
   FILE *fp,*temp;
   struct objects tmp;
   int flag=0;
   if((fp=fopen("fpdata.dat","a+b"))==NULL) {
	printf("\n\n\n Can not open main file. Press any key ...");
	getch();
	return;
   }
   if((temp=fopen("temp.dat","a+b"))==NULL) {
	printf("\n\n\n Can not open temp file. Press any key ...");
	getch();
	return;
   }
   printf("\n\n\n ***<< SAVING FILE >>*** ");
   while ((!feof(fp))) {
	if (!flag)
		if ((1 == fread(&tmp,sizeof(struct objects),1,fp)) && (strcmp(tmp.name,list.name)<=0))
			fwrite(&tmp,sizeof(struct objects),1,temp);
		else {
			fwrite(&list,sizeof(struct objects),1,temp);
			flag=1;
		}
	else {
		fread(&tmp,sizeof(struct objects),1,fp);
		fwrite(&tmp,sizeof(struct objects),1,temp);
	}
   }
   fcloseall();
   if (remove("fpdata.dat") !=0) {
	printf("\nCan not remove.peresskey...");
	getch();
   }
   if (rename("temp.dat","fpdata.dat") !=0) {
	printf("\nCan not rename.peresskey...");
	getch();
	exit(1);
   }
	printf("\n\n\n file seccessfuly saved. Press any key ...");
	getch();
}
