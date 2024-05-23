#include <ctype.h>
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
   struct objects{
   char name[20],group[20],producer[20],location;
   int number;
   int buyprice,sellprice;
   unsigned long int code;
   char expdate[8],prodate[8],entdate[8];
};
//###Proto-Type#########################################################
void add_good();
void del_good();
void list_good();
void list2();
void show_data(objects kala);
void show_data2();
//void sel_good();
objects getfields(objects,int model);
void save(objects kala);
void del(objects kala);

//##############################################################
//class objects {
//public:
/*void enter();
struct date getdates(char str[]);
int valid(int x,char s[]);
};*/
objects kala;
//*** Objects Function *********************************************************
/*void objects::enter() {
  char temp[30];
//  clrscr();
  do {
	printf("\nEnter name of product: ");
	gets(name);
  }while ((!strlen(name)) || (!valid(1,name)));
  do {
	printf("\nEnter group of product: ");
	gets(group);
  }while ((!strlen(group)) || (!valid(1,group)));
  do {
	printf("\nEnter producer: ");
	gets(producer);
  }while ((!strlen(producer)) || (!valid(1,producer)));
  do {
	printf("\nEnter number of product: ");
	gets(temp);
  }while ((!strlen(temp)) || (!valid(0,temp)));
  number=atoi(temp);
  do {
	printf("\nEnter buyprice: ");
	gets(temp);
  }while ((!strlen(temp)) || (!valid(2,temp)));
  buyprice=atof(temp);
  strcpy(temp,'\0');
  do {
	printf("\nEnter percent of ...: %%");
	gets(temp);
  }while ((!strlen(temp)) || (atoi(temp)>100) || (!valid(0,temp)));
  selprice=buyprice*(1+atof(temp)/100);
  printf("\nselprice is : %f\n",selprice);
  prodate=getdates("por");
  expdate=getdates("exp");
  getdate(&entdate);
}
//*** Gatdates Function ******************************************************
struct date objects::getdates(char str[3]) {
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
int objects::valid(int x,char s[]) {
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
} */

//################################################################
int charisin(char a0)
{
char str[40]=" -1234567890qwertyuiopasdfghjklzxcvbnm";
for(int h=0;h<=(strlen(str));h++)
   if (str[h]==a0)
   return 0;
 return 1;
}
int charisin2(char a0)
{
char str[40]="1234567890";
for(int h=0;h<=(strlen(str));h++)
   if (str[h]==a0)
   return 0;
 return 1;
}

/*char getstring(int x,int y)
{
char str[40]=" -1234567890qwertyuiopasdfghjklzxcvbnm";
char stri[20]="";
char a='0';
int i=0;
settextjustify(0,2);
do{
a=getch();
for(int h=0;h<(strlen(str));h++)
   if (str[h]==a) {i=1;break;}
       else i=0;

settextstyle (2,0,4);
setcolor(0);
outtextxy(x+1,y+1,stri);
if ((a==8)&(strlen(stri)>0)) stri[strlen(stri)-1]=0;
if (i==1) stri[strlen(stri)]=a;
setcolor(15);
outtextxy(x+1,y+1,stri);
}while (a!=13);
} */
//################################################################
void manage(){};
void account(){};
void cash(){list2(); };
void store(){
int choice=0;
while (choice!=6){
choice=setmenu ("Store","Add to inventory","Remove Items","Send for sell","Budget","List","Exit");
switch (choice){
case 1:add_good();break;
case 2:del_good();break;
case 3:/*sel_good();*/break;
case 4:break;
case 5:list_good();break;
}
if (choice!=6)paneclose();
	      }
	     }
//###MAIN##################################################
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
};
//*** ADD*****************************************************************
void add_good()
{
showpane ("Data I/O");
objects oldobject;
strcpy(oldobject.name,"");
strcpy(oldobject.group,"");
strcpy(oldobject.producer,"");
oldobject.code=0;
oldobject.buyprice=0;
oldobject.sellprice=0;
oldobject.location=0;
strcpy(oldobject.expdate,"");
strcpy(oldobject.prodate,"");
strcpy(oldobject.entdate,"");
objects newobject=getfields(oldobject,0);
if (newobject.name[0]!='#') save (newobject);
}
objects getfields(objects mygood,int model)
{char key;int i=1;
settextstyle (10,0,1);
setusercharsize(1,3,1,2);
 settextjustify(1,1);
setcolor (255);
outtextxy ((getmaxx()/2)-getmaxx()/32+20,20,"Enter Datas, Use Tab/Shift+Tab to scroll");
setusercharsize(1,1,1,1);
 flashcolor (255,20,0,63);
 settextjustify(0,2);
 settextstyle (2,0,4);
char name[20]="",group[20]="",producer[20]="",code[20]="",buyprice[20]=""
     ,sellprice[20]="",expdate[20]="",prodate[20]="",entdate[20]="";
/* strcpy (name,mygood.name);
 strcpy (group,mygood.group);
 strcpy (producer,mygood.producer);
 ultoa(mygood.code,code,10);
 ltoa(mygood.buyprice,buyprice,10);
 ltoa(mygood.sellprice,sellprice,10);
 strcpy (expdate,mygood.expdate);
 strcpy (prodate,mygood.prodate);
 strcpy (entdate,mygood.entdate);*/
 do{
   setcolor(15);
   if (i==1) {setcolor(13);outtextxy(109,105,"Name:");rectangle(160,100,310,120);}
	else {setcolor(15);outtextxy(109,105,"Name:");rectangle(160,100,310,120);}
   if (i==2) {setcolor(13);if (model)setcolor(8);outtextxy(109,145,"Group:");rectangle(160,140,310,160);}
	else {setcolor(15);if (model)setcolor(8);outtextxy(109,145,"Group:");rectangle(160,140,310,160);}
   if (i==3) {setcolor(13);if (model)setcolor(8);outtextxy(109,185,"Producer:");rectangle(160,180,310,200);}
	else {setcolor(15);if (model)setcolor(8);outtextxy(109,185,"Producer:");rectangle(160,180,310,200);}
   if (i==4) {setcolor(13);if (model)setcolor(8);outtextxy(109,225,"Code:");rectangle(160,220,310,240);}
	else {setcolor(15);if (model)setcolor(8);outtextxy(109,225,"Code:");rectangle(160,220,310,240);}
   if (i==5) {setcolor(13);if (model)setcolor(8);outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);}
	else {setcolor(15);if (model)setcolor(8);outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);}
   if (i==6) {setcolor(13);if (model)setcolor(8);outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);}
	else {setcolor(15);if (model)setcolor(8);outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);}
   if (i==7) {setcolor(13);if (model)setcolor(8);outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);}
	else {setcolor(15);if (model)setcolor(8);outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);}
   if (i==8) {setcolor(13);if (model)setcolor(8);outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);}
	else {setcolor(15);if (model)setcolor(8);outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);}
   if (i==9) {setcolor(13);if (model)setcolor(8);outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);}
	else {setcolor(15);if (model)setcolor(8);outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);}
   key=getch();
   if (key==9) i++;
   if (key==15) i--;
   if (i>9) i=1;
   if (i<1) i=9;
   if (model) i=1;
		    char pa[1];
		    if ((!(charisin(key))||(key==8))&&(i==1))
		       {
		       setcolor(0);
		       outtextxy(161,104,name);
		       if (key==8) name[strlen(name)-1]=0;
			   else if (strlen(name)<19)name[strlen(name)]=key;
			setcolor(15);
			outtextxy(161,104,name);
		       }
		    if ((!(charisin(key))||(key==8))&&(i==2))
		       {
		       setcolor(0);
		       outtextxy(161,144,group);
		       if (key==8) group[strlen(group)-1]=0;
			   else if (strlen(group)<19)group[strlen(group)]=key;
			setcolor(15);
			outtextxy(161,144,group);
		       }
		    if ((!(charisin(key))||(key==8))&&(i==3))
		       {
		       setcolor(0);
		       outtextxy(161,184,producer);
		       if (key==8) producer[strlen(producer)-1]=0;
			   else if (strlen(producer)<19)producer[strlen(producer)]=key;
			setcolor(15);
			outtextxy(161,184,producer);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==4))
		       {
		       setcolor(0);
		       outtextxy(161,224,code);
		       if (key==8) code[strlen(code)-1]=0;
			   else if (strlen(code)<19)code[strlen(code)]=key;
			setcolor(15);
			outtextxy(161,224,code);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==5))
		       {
		       setcolor(0);
		       outtextxy(411,104,buyprice);
		       if (key==8) buyprice[strlen(buyprice)-1]=0;
			   else if (strlen(buyprice)<19)buyprice[strlen(buyprice)]=key;
			setcolor(15);
			outtextxy(411,104,buyprice);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==6))
		       {
		       setcolor(0);
		       outtextxy(411,144,sellprice);
		       if (key==8) sellprice[strlen(sellprice)-1]=0;
			   else if (strlen(sellprice)<19)sellprice[strlen(sellprice)]=key;
			setcolor(15);
			outtextxy(411,144,sellprice);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==7))
		       {
		       setcolor(0);
		       outtextxy(411,184,expdate);
		       if (key==8) expdate[strlen(expdate)-1]=0;
			   else if (strlen(expdate)<8)expdate[strlen(expdate)]=key;
			setcolor(15);
			outtextxy(411,184,expdate);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==8))
		       {
		       setcolor(0);
		       outtextxy(411,224,prodate);
		       if (key==8) prodate[strlen(prodate)-1]=0;
			   else if (strlen(prodate)<8)prodate[strlen(prodate)]=key;
			setcolor(15);
			outtextxy(411,224,prodate);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==9))
		       {
		       setcolor(0);
		       outtextxy(411,264,entdate);
		       if (key==8) entdate[strlen(entdate)-1]=0;
			   else if (strlen(entdate)<8)entdate[strlen(entdate)]=key;
			setcolor(15);
			outtextxy(411,264,entdate);
		       }
    }while((key!=13)&&(key!=27));
 if (key==27) strcpy (name,"#");
 strcpy (mygood.name,name);
 strcpy (mygood.group,group);
 strcpy (mygood.producer,producer);
 mygood.code=atol(code);
 mygood.buyprice=atol(buyprice);
 mygood.sellprice=atol(sellprice);
 strcpy (mygood.expdate,expdate);
 strcpy (mygood.prodate,prodate);
 strcpy (mygood.entdate,entdate);
return mygood;
}
//*** del() ******************
void del_good()
{
showpane ("Data I/O");
objects oldobject;
strcpy(oldobject.name,"");
strcpy(oldobject.group,"");
strcpy(oldobject.producer,"");
oldobject.code=0;
oldobject.buyprice=0;
oldobject.sellprice=0;
oldobject.location=0;
strcpy(oldobject.expdate,"");
strcpy(oldobject.prodate,"");
strcpy(oldobject.entdate,"");
objects newobject=getfields(oldobject,1);
if (newobject.name[0]!='#') del (newobject);
//   getch();
}
/*objects getfields(objects mygood)
{char key;int i=1;
settextstyle (10,0,1);
setusercharsize(1,3,1,2);
 settextjustify(1,1);
setcolor (255);
outtextxy ((getmaxx()/2)-getmaxx()/32+20,20,"Enter Datas, Use Tab/Shift+Tab to scroll");
setusercharsize(1,1,1,1);
 flashcolor (255,20,0,63);
 settextjustify(0,2);
 settextstyle (2,0,4);
char name[20]="",group[20]="",producer[20]="",code[20]="",buyprice[20]=""
     ,sellprice[20]="",expdate[20]="",prodate[20]="",entdate[20]="";
 strcpy (name,mygood.name);
 strcpy (group,mygood.group);
 strcpy (producer,mygood.producer);
 ultoa(mygood.code,code,10);
 ltoa(mygood.buyprice,buyprice,10);
 ltoa(mygood.sellprice,sellprice,10);
 strcpy (expdate,mygood.expdate);
 strcpy (prodate,mygood.prodate);
 strcpy (entdate,mygood.entdate);
 do{
   setcolor(15);
   if (i==1) {setcolor(13);outtextxy(109,105,"Name:");rectangle(160,100,310,120);}
	else {setcolor(15);outtextxy(109,105,"Name:");rectangle(160,100,310,120);}
   if (i==2) {setcolor(13);outtextxy(109,145,"Group:");rectangle(160,140,310,160);}
	else {setcolor(15);outtextxy(109,145,"Group:");rectangle(160,140,310,160);}
   if (i==3) {setcolor(13);outtextxy(109,185,"Producer:");rectangle(160,180,310,200);}
	else {setcolor(15);outtextxy(109,185,"Producer:");rectangle(160,180,310,200);}
   if (i==4) {setcolor(13);outtextxy(109,225,"Code:");rectangle(160,220,310,240);}
	else {setcolor(15);outtextxy(109,225,"Code:");rectangle(160,220,310,240);}
   if (i==5) {setcolor(13);outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);}
	else {setcolor(15);outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);}
   if (i==6) {setcolor(13);outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);}
	else {setcolor(15);outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);}
   if (i==7) {setcolor(13);outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);}
	else {setcolor(15);outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);}
   if (i==8) {setcolor(13);outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);}
	else {setcolor(15);outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);}
   if (i==9) {setcolor(13);outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);}
	else {setcolor(15);outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);}
   key=getch();
   if (key==9) i++;
   if (key==15) i--;
   if (i>9) i=1;
   if (i<1) i=9;
		    char pa[1];
		    if ((!(charisin(key))||(key==8))&&(i==1))
		       {
		       setcolor(0);
		       outtextxy(161,104,name);
		       if (key==8) name[strlen(name)-1]=0;
			   else if (strlen(name)<19)name[strlen(name)]=key;
			setcolor(15);
			outtextxy(161,104,name);
		       }
		    if ((!(charisin(key))||(key==8))&&(i==2))
		       {
		       setcolor(0);
		       outtextxy(161,144,group);
		       if (key==8) group[strlen(group)-1]=0;
			   else if (strlen(group)<19)group[strlen(group)]=key;
			setcolor(15);
			outtextxy(161,144,group);
		       }
		    if ((!(charisin(key))||(key==8))&&(i==3))
		       {
		       setcolor(0);
		       outtextxy(161,184,producer);
		       if (key==8) producer[strlen(producer)-1]=0;
			   else if (strlen(producer)<19)producer[strlen(producer)]=key;
			setcolor(15);
			outtextxy(161,184,producer);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==4))
		       {
		       setcolor(0);
		       outtextxy(161,224,code);
		       if (key==8) code[strlen(code)-1]=0;
			   else if (strlen(code)<19)code[strlen(code)]=key;
			setcolor(15);
			outtextxy(161,224,code);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==5))
		       {
		       setcolor(0);
		       outtextxy(411,104,buyprice);
		       if (key==8) buyprice[strlen(buyprice)-1]=0;
			   else if (strlen(buyprice)<19)buyprice[strlen(buyprice)]=key;
			setcolor(15);
			outtextxy(411,104,buyprice);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==6))
		       {
		       setcolor(0);
		       outtextxy(411,144,sellprice);
		       if (key==8) sellprice[strlen(sellprice)-1]=0;
			   else if (strlen(sellprice)<19)sellprice[strlen(sellprice)]=key;
			setcolor(15);
			outtextxy(411,144,sellprice);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==7))
		       {
		       setcolor(0);
		       outtextxy(411,184,expdate);
		       if (key==8) expdate[strlen(expdate)-1]=0;
			   else if (strlen(expdate)<8)expdate[strlen(expdate)]=key;
			setcolor(15);
			outtextxy(411,184,expdate);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==8))
		       {
		       setcolor(0);
		       outtextxy(411,224,prodate);
		       if (key==8) prodate[strlen(prodate)-1]=0;
			   else if (strlen(prodate)<8)prodate[strlen(prodate)]=key;
			setcolor(15);
			outtextxy(411,224,prodate);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==9))
		       {
		       setcolor(0);
		       outtextxy(411,264,entdate);
		       if (key==8) entdate[strlen(entdate)-1]=0;
			   else if (strlen(entdate)<8)entdate[strlen(entdate)]=key;
			setcolor(15);
			outtextxy(411,264,entdate);
		       }
    }while((key!=13)&&(key!=27));
 if (key==27) strcpy (name,"#");
 strcpy (mygood.name,name);
 strcpy (mygood.group,group);
 strcpy (mygood.producer,producer);
 mygood.code=atol(code);
 mygood.buyprice=atol(buyprice);
 mygood.sellprice=atol(sellprice);
 strcpy (mygood.expdate,expdate);
 strcpy (mygood.prodate,prodate);
 strcpy (mygood.entdate,entdate);
return mygood;
} */

//*** Save Function **********************************************************
void save(objects kala) {
//   closegraph();
   FILE *fp,*temp;
   struct objects tmp;
   int flag=0;
   fp=fopen("fpdata.dat","a+b");
/*   if((fp=fopen("fpdata.dat","a+b"))==NULL) {
	printf("\n\n\n Can not open main file. Press any key ...");
	getch();
	return;
   }*/
   temp=fopen("temp.dat","a+b");
/*   if((temp=fopen("temp.dat","a+b"))==NULL) {
	printf("\n\n\n Can not open temp file. Press any key ...");
	getch();
	return;
   }*/
   //printf("\n\n\n ***<< SAVING FILE >>*** ");
   int wrote=0;
   while ((!feof(fp))) {
	if (!flag)
		if ((1 == fread(&tmp,sizeof(struct objects),1,fp)) && (strcmp(tmp.name,kala.name)<=0))
			fwrite(&tmp,sizeof(struct objects),1,temp);
		else {
			fwrite(&kala,sizeof(struct objects),1,temp);
			flag=1;
		}
	else {
		fread(&tmp,sizeof(struct objects),1,fp);
		fwrite(&tmp,sizeof(struct objects),1,temp);
	}
	     /*	if ((1==fread(&temp,sizeof(struct objects),1,fp))&&(strcmp(kala.name,tmp.name)>0)){fwrite(&tmp,sizeof(struct objects),1,temp);}else
		if((!wrote)&&(strcmp(kala.name,tmp.name)<0)) {fwrite(&kala,sizeof(struct objects),1,temp);fwrite(&tmp,sizeof(struct objects),1,temp);wrote=1;}else
		if((!wrote)&&(strcmp(kala.name,tmp.name))==0){fwrite(&kala,sizeof(struct objects),1,temp);fwrite(&tmp,sizeof(struct objects),1,temp);wrote=1;}*/
//	else {
//		fread(&tmp,sizeof(struct objects),1,fp);
//		fwrite(&tmp,sizeof(struct objects),1,temp);
//	}
   }
   fcloseall();
   remove("fpdata.dat");
   rename ("temp.dat", "fpdata.dat");
/*   if (remove("fpdata.dat") !=0) {
	printf("\nCan not remove.peresskey...");
	getch();
   }
   if (rename("temp.dat","fpdata.dat") !=0) {
	printf("\nCan not rename.peresskey...");
	getch();
	exit(1);
   }
	printf("\n\n\n file seccessfuly saved. Press any key ...");
	getch();*/
}
//*** List Goods *************************************************************
void list_good(){
char key=1;int i=1;
objects mygood;
setusercharsize(1,1,1,1);
 flashcolor (255,20,0,63);
 settextjustify(0,2);
 settextstyle (2,0,4);
 setcolor(15);
char name[20]="",group[20]="",producer[20]="",code[20]="",buyprice[20]=""
     ,sellprice[20]="",expdate[20]="",prodate[20]="",entdate[20]="";

   FILE *pf;
struct objects kala;
   int flag=0;
   pf=fopen("fpdata.dat","a+b");
   //pf=fopen("fpdata.dat","r");
//   fseek(pf,0l,SEEK_SET);
 do{
   if (i==1) {setcolor(13);outtextxy(109,105,"Name:");rectangle(160,100,310,120);}
	else {setcolor(15);outtextxy(109,105,"Name:");rectangle(160,100,310,120);}
   if (i==2) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(109,145,"Group:");rectangle(160,140,310,160);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(109,145,"Group:");rectangle(160,140,310,160);}
   if (i==3) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(109,185,"Producer:");rectangle(160,180,310,200);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(109,185,"Producer:");rectangle(160,180,310,200);}
   if (i==4) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(109,225,"Code:");rectangle(160,220,310,240);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(109,225,"Code:");rectangle(160,220,310,240);}
   if (i==5) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);}
   if (i==6) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);}
   if (i==7) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);}
   if (i==8) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);}
   if (i==9) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);}
   key=getch();
   if (key==9) i++;
   if (key==15) i--;
   if (i>9) i=1;
   if (i<1) i=9;
   //if (model) i=1;
		    char pa[1];
		    if ((!(charisin(key))||(key==8))&&(i==1))
		       {
		       setcolor(0);
		       outtextxy(161,105,name);
		       if (key==8) name[strlen(name)-1]=0;
			   else if (strlen(name)<19)name[strlen(name)]=key;
			setcolor(15);
			outtextxy(161,105,name);
		       }
		    if ((!(charisin(key))||(key==8))&&(i==2))
		       {
		       setcolor(0);
		       outtextxy(161,145,group);
		       if (key==8) group[strlen(group)-1]=0;
			   else if (strlen(group)<19)group[strlen(group)]=key;
			setcolor(15);
			outtextxy(161,145,group);
		       }
		    if ((!(charisin(key))||(key==8))&&(i==3))
		       {
		       setcolor(0);
		       outtextxy(161,185,producer);
		       if (key==8) producer[strlen(producer)-1]=0;
			   else if (strlen(producer)<19)producer[strlen(producer)]=key;
			setcolor(15);
			outtextxy(161,185,producer);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==4))
		       {
		       setcolor(0);
		       outtextxy(161,225,code);
		       if (key==8) code[strlen(code)-1]=0;
			   else if (strlen(code)<19)code[strlen(code)]=key;
			setcolor(15);
			outtextxy(161,225,code);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==5))
		       {
		       setcolor(0);
		       outtextxy(411,105,buyprice);
		       if (key==8) buyprice[strlen(buyprice)-1]=0;
			   else if (strlen(buyprice)<19)buyprice[strlen(buyprice)]=key;
			setcolor(15);
			outtextxy(411,105,buyprice);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==6))
		       {
		       setcolor(0);
		       outtextxy(411,145,sellprice);
		       if (key==8) sellprice[strlen(sellprice)-1]=0;
			   else if (strlen(sellprice)<19)sellprice[strlen(sellprice)]=key;
			setcolor(15);
			outtextxy(411,145,sellprice);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==7))
		       {
		       setcolor(0);
		       outtextxy(411,185,expdate);
		       if (key==8) expdate[strlen(expdate)-1]=0;
			   else if (strlen(expdate)<8)expdate[strlen(expdate)]=key;
			setcolor(15);
			outtextxy(411,185,expdate);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==8))
		       {
		       setcolor(0);
		       outtextxy(411,225,prodate);
		       if (key==8) prodate[strlen(prodate)-1]=0;
			   else if (strlen(prodate)<8)prodate[strlen(prodate)]=key;
			setcolor(15);
			outtextxy(411,225,prodate);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==9))
		       {
		       setcolor(0);
		       outtextxy(411,265,entdate);
		       if (key==8) entdate[strlen(entdate)-1]=0;
			   else if (strlen(entdate)<8)entdate[strlen(entdate)]=key;
			setcolor(15);
			outtextxy(411,265,entdate);
		       }
    }while((key!=13)&&(key!=27));
//if ((1 == fread(&tmp,sizeof(struct objects),1,pf)) && (strcmp(tmp.name,kala.name)!=0)&&(kala.location=tmp.location))
 strcpy (mygood.name,name);
 strcpy (mygood.group,group);
 strcpy (mygood.producer,producer);
 mygood.code=atol(code);
 mygood.buyprice=atol(buyprice);
 mygood.sellprice=atol(sellprice);
 strcpy (mygood.expdate,expdate);
 strcpy (mygood.prodate,prodate);
 strcpy (mygood.entdate,entdate);
     fseek(pf,0l,SEEK_SET);
//     closegraph();
//     cout<<name;
	 fread(&kala,sizeof(struct objects),1,pf);
     while (!feof(pf))
	 {

	 //if (feof(pf)) break;
	 //show_data(kala);
	 flag=1;
	 if (stricmp(kala.name,mygood.name)&&(strlen(name)!=0)) flag=0;
	 if (stricmp(kala.group,mygood.group)&&(strlen(group)!=0))flag=0;
	 if (stricmp(kala.producer,mygood.producer)&&(strlen(producer)!=0))flag=0;
	 if ((kala.code==mygood.code)&&(strlen(code)!=0))flag=0;
	 if ((kala.buyprice==mygood.buyprice)&&(strlen(buyprice)!=0))flag=0;
	 if ((kala.sellprice==mygood.sellprice)&&(strlen(sellprice)!=0))flag=0;
	 if (stricmp(kala.expdate,mygood.expdate)&&(strlen(expdate)!=0))flag=0;
	 if (stricmp(kala.entdate,mygood.entdate)&&(strlen(entdate)!=0))flag=0;
	 if (flag==1) show_data(kala); //outtextxy(500,500,"aksjhdkajsdasd");}
	 fread(&kala,sizeof(struct objects),1,pf);
	 //getch();
	 }
   fcloseall();
//   show_data();
}
//*** Delete Function **********************************************************
void del(objects kala1) {
//   closegraph();
   FILE *fp,*temp;
   struct objects tmp;
   int flag=0;
   fp=fopen("fpdata.dat","a+b");
/*   if((fp=fopen("fpdata.dat","a+b"))==NULL) {
	printf("\n\n\n Can not open main file. Press any key ...");
	getch();
	return;
   }*/
   temp=fopen("temp.dat","a+b");
/*   if((temp=fopen("temp.dat","a+b"))==NULL) {
	printf("\n\n\n Can not open temp file. Press any key ...");
	getch();
	return;
   }*/
   //printf("\n\n\n ***<< SAVING FILE >>*** ");
   while ((!feof(fp))) {
//	if (!flag)
		if ((1 == fread(&tmp,sizeof(struct objects),1,fp)) && (strcmp(tmp.name,kala1.name)!=0)&&(kala1.location=tmp.location))
			fwrite(&tmp,sizeof(struct objects),1,temp);
   if (strcmp(tmp.name,kala1.name)==0) flag=1;
   }
setcolor (16);
settextjustify (1,0);
settextstyle (7,0,3);
if (!flag) outtextxy(getmaxx()/2-getmaxx()/32,getmaxy()-(3*getmaxx()/32),"Requested name was not found!");
flashcolor (16,63,20,20);
//		else {
//			fwrite(&kala,sizeof(struct objects),1,temp);
//			flag=1;
//		}
//	else {
//		fread(&tmp,sizeof(struct objects),1,fp);
//		fwrite(&tmp,sizeof(struct objects),1,temp);
//	}
   fcloseall();
   remove("fpdata.dat");
   rename ("temp.dat", "fpdata.dat");
/*   if (remove("fpdata.dat") !=0) {
	printf("\nCan not remove.peresskey...");
	getch();
   }
   if (rename("temp.dat","fpdata.dat") !=0) {
	printf("\nCan not rename.peresskey...");
	getch();
	exit(1);
   }
	printf("\n\n\n file seccessfuly saved. Press any key ...");
	getch();*/
}
/*
void sel_good()
{
showpane ("Data I/O");
objects oldobject;
strcpy(oldobject.name,"");
strcpy(oldobject.group,"");
strcpy(oldobject.producer,"");
oldobject.code=0;
oldobject.buyprice=0;
oldobject.sellprice=0;
oldobject.location=0;
strcpy(oldobject.expdate,"");
strcpy(oldobject.prodate,"");
strcpy(oldobject.entdate,"");
objects newobject=getfields(oldobject,0);
if (newobject.name[0]!='#') changetosell (newobject);
//   getch();
}*/
/*
void changetosell(objects kala) {
   FILE *fp,*temp;
   struct objects tmp;
   int flag=0;
   fp=fopen("fpdata.dat","a+b");
   temp=fopen("temp.dat","a+b");
   while ((!feof(fp))) {
		if ((1 == fread(&tmp,sizeof(struct objects),1,fp)) && (strcmp(tmp.name,kala.name)!=0)&&(kala.location=tmp.location))
			fwrite(&tmp,sizeof(struct objects),1,temp);
   if (strcmp(tmp.name,kala.name)==0) flag=1;
   }
setcolor (16);
settextjustify (1,0);
settextstyle (7,0,3);
if (!flag) outtextxy(getmaxx()/2-getmaxx()/32,getmaxy()-(3*getmaxx()/32),"Requested name was not found!");
flashcolor (16,63,20,20);
   fcloseall();
   remove("fpdata.dat");
   rename ("temp.dat", "fpdata.dat");
} */
//*** Show Data *******************************************************
void show_data(objects ka){
setusercharsize(1,1,1,1);
 flashcolor (255,20,0,63);
 settextjustify(0,2);
 settextstyle (2,0,4);
char code[20],buyprice[20],sellprice[20];
(ltoa(ka.code,code,10));
(ltoa(ka.buyprice,buyprice,10));
(ltoa(ka.sellprice,sellprice,10));

//while (!kbhit()) getch();
   setcolor(15);
   outtextxy(109,105,"Name:");rectangle(160,100,310,120);outtextxy(161,105,ka.name);
/*if (model)setcolor(8);*/outtextxy(109,145,"Group:");rectangle(160,140,310,160);outtextxy(161,145,ka.group);
/*if (model)setcolor(8);*/outtextxy(109,185,"Producer:");rectangle(160,180,310,200);outtextxy(161,185,ka.producer);
/*if (model)setcolor(8);*/outtextxy(109,225,"Code:");rectangle(160,220,310,240);outtextxy(161,225,code);
/*if (model)setcolor(8);*/outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);outtextxy(411,105,buyprice);
/*if (model)setcolor(8);*/outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);outtextxy(411,145,sellprice);
/*if (model)setcolor(8);*/outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);outtextxy(411,185,ka.expdate);
/*if (model)setcolor(8);*/outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);outtextxy(411,225,ka.prodate);
/*if (model)setcolor(8);*/outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);outtextxy(411,265,ka.entdate);
//getch();
//getch();
  setcolor(15); outtextxy(109,105,"Name:");rectangle(160,100,310,120);setcolor(0);outtextxy(161,105,ka.name);
/*if (model)setcolor(8);*/setcolor(15);outtextxy(109,145,"Group:");rectangle(160,140,310,160);setcolor(0);outtextxy(161,145,ka.group);
/*if (model)setcolor(8);*/setcolor(15);outtextxy(109,185,"Producer:");rectangle(160,180,310,200);setcolor(0);outtextxy(161,185,ka.producer);
/*if (model)setcolor(8);*/setcolor(15);outtextxy(109,225,"Code:");rectangle(160,220,310,240);setcolor(0);outtextxy(161,225,code);
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);setcolor(0);outtextxy(411,105,buyprice);
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);setcolor(0);outtextxy(411,145,sellprice);
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);setcolor(0);outtextxy(411,185,ka.expdate);
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);setcolor(0);outtextxy(411,225,ka.prodate);
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);setcolor(0);outtextxy(411,265,ka.entdate);
getch();
}
//**** list2 ******************************************
void list2()
{
char key=1;int i=1;
objects mygood;
setusercharsize(1,1,1,1);
 flashcolor (255,20,0,63);
 settextjustify(0,2);
 settextstyle (2,0,4);
 setcolor(15);
char name[20]="",group[20]="",producer[20]="",code[20]="",buyprice[20]=""
     ,sellprice[20]="",expdate[20]="",prodate[20]="",entdate[20]="";

   FILE *pf;
struct objects kala;
   int flag=0;
   pf=fopen("fpdata.dat","a+b");
 do{
   if (i==1) {setcolor(13);outtextxy(109,105,"Name:");rectangle(160,100,310,120);}
	else {setcolor(15);outtextxy(109,105,"Name:");rectangle(160,100,310,120);}
   if (i==2) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(109,145,"Group:");rectangle(160,140,310,160);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(109,145,"Group:");rectangle(160,140,310,160);}
   if (i==3) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(109,185,"Producer:");rectangle(160,180,310,200);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(109,185,"Producer:");rectangle(160,180,310,200);}
   if (i==4) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(109,225,"Code:");rectangle(160,220,310,240);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(109,225,"Code:");rectangle(160,220,310,240);}
   if (i==5) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);}
   if (i==6) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);}
   if (i==7) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);}
   if (i==8) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);}
   if (i==9) {setcolor(13);/*if (model)setcolor(8);*/outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);}
	else {setcolor(15);/*if (model)setcolor(8);*/outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);}
   key=getch();
   if (key==9) i++;
   if (key==15) i--;
   if (i>9) i=1;
   if (i<1) i=9;
   //if (model) i=1;
		    char pa[1];
		    if ((!(charisin(key))||(key==8))&&(i==1))
		       {
		       setcolor(0);
		       outtextxy(161,104,name);
		       if (key==8) name[strlen(name)-1]=0;
			   else if (strlen(name)<19)name[strlen(name)]=key;
			setcolor(15);
			outtextxy(161,104,name);
		       }
		    if ((!(charisin(key))||(key==8))&&(i==2))
		       {
		       setcolor(0);
		       outtextxy(161,144,group);
		       if (key==8) group[strlen(group)-1]=0;
			   else if (strlen(group)<19)group[strlen(group)]=key;
			setcolor(15);
			outtextxy(161,144,group);
		       }
		    if ((!(charisin(key))||(key==8))&&(i==3))
		       {
		       setcolor(0);
		       outtextxy(161,184,producer);
		       if (key==8) producer[strlen(producer)-1]=0;
			   else if (strlen(producer)<19)producer[strlen(producer)]=key;
			setcolor(15);
			outtextxy(161,184,producer);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==4))
		       {
		       setcolor(0);
		       outtextxy(161,224,code);
		       if (key==8) code[strlen(code)-1]=0;
			   else if (strlen(code)<19)code[strlen(code)]=key;
			setcolor(15);
			outtextxy(161,224,code);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==5))
		       {
		       setcolor(0);
		       outtextxy(411,104,buyprice);
		       if (key==8) buyprice[strlen(buyprice)-1]=0;
			   else if (strlen(buyprice)<19)buyprice[strlen(buyprice)]=key;
			setcolor(15);
			outtextxy(411,104,buyprice);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==6))
		       {
		       setcolor(0);
		       outtextxy(411,144,sellprice);
		       if (key==8) sellprice[strlen(sellprice)-1]=0;
			   else if (strlen(sellprice)<19)sellprice[strlen(sellprice)]=key;
			setcolor(15);
			outtextxy(411,144,sellprice);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==7))
		       {
		       setcolor(0);
		       outtextxy(411,184,expdate);
		       if (key==8) expdate[strlen(expdate)-1]=0;
			   else if (strlen(expdate)<8)expdate[strlen(expdate)]=key;
			setcolor(15);
			outtextxy(411,184,expdate);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==8))
		       {
		       setcolor(0);
		       outtextxy(411,224,prodate);
		       if (key==8) prodate[strlen(prodate)-1]=0;
			   else if (strlen(prodate)<8)prodate[strlen(prodate)]=key;
			setcolor(15);
			outtextxy(411,224,prodate);
		       }
		    if ((!(charisin2(key))||(key==8))&&(i==9))
		       {
		       setcolor(0);
		       outtextxy(411,264,entdate);
		       if (key==8) entdate[strlen(entdate)-1]=0;
			   else if (strlen(entdate)<8)entdate[strlen(entdate)]=key;
			setcolor(15);
			outtextxy(411,264,entdate);
		       }
    }while((key!=13)&&(key!=27));
//if ((1 == fread(&tmp,sizeof(struct objects),1,pf)) && (strcmp(tmp.name,kala.name)!=0)&&(kala.location=tmp.location))
 strcpy (mygood.name,name);
 strcpy (mygood.group,group);
 strcpy (mygood.producer,producer);
 mygood.code=atol(code);
 mygood.buyprice=atol(buyprice);
 mygood.sellprice=atol(sellprice);
 strcpy (mygood.expdate,expdate);
 strcpy (mygood.prodate,prodate);
 strcpy (mygood.entdate,entdate);

   fread(&kala,sizeof(struct objects),1,pf);
     while (!feof(pf))
	 {
	 flag=1;
	 if (stricmp(kala.name,mygood.name)&&(strlen(name)!=0)) flag=0;
	 if (stricmp(kala.group,mygood.group)&&(strlen(group)!=0))flag=0;
	 if (stricmp(kala.producer,mygood.producer)&&(strlen(producer)!=0))flag=0;
	 if ((kala.code==mygood.code)&&(strlen(code)!=0))flag=0;
	 if ((kala.buyprice==mygood.buyprice)&&(strlen(buyprice)!=0))flag=0;
	 if ((kala.sellprice==mygood.sellprice)&&(strlen(sellprice)!=0))flag=0;
	 if (stricmp(kala.expdate,mygood.expdate)&&(strlen(expdate)!=0))flag=0;
	 if (stricmp(kala.entdate,mygood.entdate)&&(strlen(entdate)!=0))flag=0;
	 if (kala.location) flag=0;
	 //if (flag==1) show data(); //outtextxy(500,500,"aksjhdkajsdasd");
	 //getch();
	 fread(&kala,sizeof(struct objects),1,pf);
	 }
   fcloseall();
   show_data2();
}
//*** Show Data2 *******************************************************
void show_data2(){
char a=0;
setusercharsize(1,1,1,1);
 flashcolor (255,20,0,63);
 settextjustify(0,2);
 settextstyle (2,0,4);
//while (!kbhit()) getch();
   setcolor(15);
   outtextxy(109,105,"Name:");rectangle(160,100,310,120);outtextxy(161,105,"ka.name:");
/*if (model)setcolor(8);*/outtextxy(109,145,"Group:");rectangle(160,140,310,160);outtextxy(161,145,"ka.group:");
/*if (model)setcolor(8);*/outtextxy(109,185,"Producer:");rectangle(160,180,310,200);outtextxy(161,185,"ka.roducer:");
/*if (model)setcolor(8);*/outtextxy(109,225,"Code:");rectangle(160,220,310,240);outtextxy(161,225,"ka.code:");
/*if (model)setcolor(8);*/outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);outtextxy(411,105,"ka.uyprice:");
/*if (model)setcolor(8);*/outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);outtextxy(411,145,"ka.ellprice:");
/*if (model)setcolor(8);*/outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);outtextxy(411,185,"ka.expdate:");
/*if (model)setcolor(8);*/outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);outtextxy(411,225,"ka.prodate:");
/*if (model)setcolor(8);*/outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);outtextxy(411,265,"ka.entdate:");
a=getch();
//getch();
			  setcolor(15); outtextxy(109,105,"Name:");rectangle(160,100,310,120);setcolor(0);outtextxy(161,105,"ka.name:");
/*if (model)setcolor(8);*/setcolor(15);outtextxy(109,145,"Group:");rectangle(160,140,310,160);setcolor(0);outtextxy(161,145,"ka.group:");
/*if (model)setcolor(8);*/setcolor(15);outtextxy(109,185,"Producer:");rectangle(160,180,310,200);setcolor(0);outtextxy(161,185,"ka.producer:");
/*if (model)setcolor(8);*/setcolor(15);outtextxy(109,225,"Code:");rectangle(160,220,310,240);setcolor(0);outtextxy(161,225,"ka.code:");
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,105,"Buyprice:");rectangle(410,100,560,120);setcolor(0);outtextxy(411,105,"ka.buyprice:");
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,145,"Sellprice:");rectangle(410,140,560,160);setcolor(0);outtextxy(411,145,"ka.sellprice:");
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,185,"Expdate:");rectangle(410,180,560,200);setcolor(0);outtextxy(411,185,"ka.expdate:");
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,225,"Prodate:");rectangle(410,220,560,240);setcolor(0);outtextxy(411,225,"ka.prodate:");
/*if (model)setcolor(8);*/setcolor(15);outtextxy(350,265,"Entdate:");rectangle(410,260,560,280);setcolor(0);outtextxy(411,265,"ka.entdate:");

if (a==13) outtextxy(200,20,"Enter Number Of");//gotoxy();scanf("%d",&x);
getch();
}
