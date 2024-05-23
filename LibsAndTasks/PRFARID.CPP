#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <io.h>
struct date{
int year;
int month;
int day;
};
struct goods{
char  goodsname[15];
char  color[7];
char  model[10];
struct date buyingdate;
struct date sellingdate;
//char  buyingdate[10];
//char  sellingdate[10];
int   price;
int  number;
} good;

int report_ss();
int report_goods();
int dataedit(char b);

void main()
{
char a=0;
clrscr();
while (a!='5'){
cprintf ("\n\r Enter your choice :");
a=getche();
cprintf ("\n\r");
if(a=='1' || a=='2')  {a=dataedit(a);}
if(a=='3')  {a=report_ss();}
if(a=='4')  {a=report_goods();}
if(a=='5')  exit(0);
}}

//****************************************************
int dataedit(char b) {

char position;
fpos_t lastpos;
char name[15],stemp[255];
FILE *fp;
while (kbhit()) getch();
while(b=='1'){
fp=fopen("D:\\m_g.dat","a+b");
	fseek(fp,0l,SEEK_END);
	printf("please enter the name of the good\n");
	gets(good.goodsname);
	printf("please enter the color of the good\n");
	gets(good.color);
	printf("please enter the model of the good\n");
	gets(good.model);
	printf("please enter the buying date of the good\n");
	scanf("%d",&good.buyingdate.year);
	scanf("%d",&good.buyingdate.month);
	scanf("%d",&good.buyingdate.day);
	printf("please enter the selling date of the good\n");
	scanf("%d",&good.sellingdate.year);
	scanf("%d",&good.sellingdate.month);
	scanf("%d",&good.sellingdate.day);
	printf("please enter the price of the good\n");
	scanf("%d",&good.price);
	printf("please enter the number of the good in the store\n");
	scanf("%d",&good.number);
	fwrite(&good, sizeof(struct goods),1,fp);
//	cprintf("please give another order\n\r");
	gets(stemp);
fclose(fp);
return(5);
//	b=getch();
}
while(b=='2'){
fp=fopen("D:\\m_g.dat","r+");
	cprintf("please enter the name of the good that you want to change it's data\n\r");
	gets(name);
	fseek(fp,0l,SEEK_SET);
  while(!feof(fp)){
//	lastpos=ftell(fp);
// int fgetpos(FILE *stream, fpos_t *pos);
	fgetpos(fp,&lastpos);
	fread(&good,sizeof(struct goods),1,fp);
     if(!strcmp(name,good.goodsname)){
	  cprintf("please enter the new data of this good\n\r");
	  cprintf("please enter the name of the good:");
	  gets(good.goodsname);
	  printf("please enter the color of the good:");
	  gets(good.color);
	  printf("please enter the model of the good:");
	  gets(good.model);
	  printf("please enter the buying date of the good:");
	  scanf("%d%d%d",&good.buyingdate.year,&good.buyingdate.month,&good.buyingdate.day);
	  printf("please enter the selling date of the good:");
	  scanf("%d%d%d",&good.sellingdate.year,&good.sellingdate.month,&good.sellingdate.day);
	  printf("please enter the price of the good:");
	  scanf("%d",&good.price);
	  printf("please enter the number of the good in the store:");
	  scanf("%d",&good.number);
	  //int fsetpos(FILE *stream, const fpos_t *pos);
	  fsetpos(fp, &lastpos);
	  //fseek(fp,lastpos,SEEK_SET);
	  fwrite(&good,sizeof(struct goods),1,fp);
	  printf("The information of this good is edited\n");
	  break;
}}
printf("There is no more good with this name\n");
gets(stemp);
//b=getch();
fclose(fp);
return(5);
}

}

//*************************************************************
int report_ss(){
int i=0;
char c='3',lastpos;
FILE *fp;
fp=fopen("D:\\m_g.dat","r");
fseek(fp,0l,SEEK_SET);
//fread(&good,sizeof(struct goods),1,fp);
    if(c=='3')
    while(!feof(fp))
    {
	i++;
	fread(&good,sizeof(struct goods),1,fp);
	if feof(fp) break;
	printf("*** good number %d\n",i);
	cprintf ("name:%s\n\r",good.goodsname);
	printf("color:");
	puts(good.color);
	printf("model:");
	puts(good.model);
	printf("buying date:");
	printf("%d%d%d",good.buyingdate.year,good.buyingdate.month,good.buyingdate.day);	//puts(good.buyingdate);
	printf("selling date:");
	printf("%d%d%d",good.sellingdate.year,good.sellingdate.month,good.sellingdate.day);
	printf("price:%d\n",good.price);
	printf("number:%d\n",good.number);
	cprintf ("Hit any key to continue...");
	getch();
    }
fclose(fp);
return (5);
}
//*********************************************************************

int report_goods(){
int i=0;
FILE *fp;
fp=fopen("D:\\m_g.dat","a+b");
char d='4',modell[15],name[15];
//if (kbhit()) getch();
//char a=getch();
if(d=='4'){
	cprintf("please enter the name of the good that you want to see it's information\n\r");
	gets(name);
	cprintf("please enter the model of the good that you want to see it's information\n\r");
	gets(modell);
	fseek(fp,0l,SEEK_SET);
  clrscr();
  while(!feof(fp)){
	fread(&good,sizeof(struct goods),1,fp);
     if feof(fp) break;
     if ( (!strcmp(name,good.goodsname)) && (!strcmp(modell,good.model))){
	i=1;
	printf("\nthe name of the good is: ");
	puts(good.goodsname);
	printf("the color of the good is: ");
	puts(good.color);
	printf("the model of the good is: ");
	puts(good.model);
	printf("the buyingdate of the good is: ");
	printf(" %d/%d/%d",good.buyingdate.year,good.buyingdate.month,good.buyingdate.day);
	printf("\nthe selling date of the good is: ");
	printf(" %d/%d/%d",good.sellingdate.year,good.sellingdate.month,good.sellingdate.day);
	printf("\nthe price of the good is: ");
	printf("%d",good.price);
	printf("\nthe number of the good is: ");
	printf("%d\n\r",good.number);
if (wherey()==25) {cprintf ("\n\rPress any key to continue...\n\r");getch();}
}
}
if(i==0) printf("there is not any good with this information\n");
fclose(fp);
getch();
return(5);
}}








