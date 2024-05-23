#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "iostream.h"
#include "process.h"
#include "dos.h"
#include "stdlib.h"
#include "io.h"
#include "malloc.h"
#define SIZE 100
#define n 10

//-----------------------------***
struct DATE {
int year;
int month;
int day;
};
//-----------------------------***
struct CHEQUE{
int numbers;               //shomareh check
long int value;            //gheimate har check
DATE ch_date;              //tarigh daryaft check
char defile[15];           //name shobeh (bank)
int code_defile;
};
//-----------------------------***
struct formal{
char name_f[20];
int code_f;
int num_f;
};
//-----------------------------***
struct GOODS1{
char name1[20];
int pre1;
int code1;                  //darsad sod
int num_che1;            //tedad checkha agar kharid ba check bashad
char type1;              //type check (tazmin ya pardakhty)
int numforma1;           //shomareh factor kharid kala
int number1;             //teidad in  kala
int codesailor1;         //code foroshandeh kala(sherkat)
char typebuy1[10];       //type kharid
long int pricebuy1;      //gheimat kharid har kala
long int pricesale1;     //gheimat forosh har kala
int numrest1;            //teidad baghy mandeh az in type kala
int numreturn1;          //teidad barghasht dadeh shodeh
CHEQUE cheque1[10];      //moshkhasate check agar kharid ba check bod
long int advance1;       //sode mahaneh
long int tot_price1;     //gheimat cole kharid az sherkat
DATE date1;
}goods;
//------------------------------***
class GOODS{
char name[20];
int pre;                  //darsad sod
int num_che;            //tedad checkha agar kharid ba check bashad
char type;              //type check (tazmin ya pardakhty)
int numforma;           //shomareh factor kharid kala
int number;             //teidad in  kala
int codesailor;         //code foroshandeh kala(sherkat)
char typebuy[10];       //type kharid
long int pricebuy;      //gheimat kharid har kala
long int pricesale;     //gheimat forosh har kala
int numrest;            //teidad baghy mandeh az in type kala
int numreturn;          //teidad barghasht dadeh shodeh
CHEQUE cheque[10];      //moshkhasate check agar kharid ba check bod
long int advance;       //sode mahaneh
long int tot_price;     //gheimat cole kharid az sherkat
DATE date;
public:
FILE  *wavefile;
GOODS(){numrest=number=0;numreturn=0;advance=0;pricesale=pricebuy=0;num_che=0;
codesailor=0;};
int code;            //code kala
void entergoods(GOODS wave,GOODS1 goods);
//void editche_goods(GOODS goods[k]);
void searchwave(GOODS  goods);
void get_c(GOODS goods,char *name,int &code,int num,int &find,int &sum);
void get_all(GOODS wave,GOODS1 *goodsfound,char num,int find,formal search,int *found);
friend class MEMBER;
}wave2[10];
//------------------------------***
struct MEMBER1{
char name2[20];
int numbook2;
int numbuy2;              //tedad calaye kharidary shodeh
int f_instal2;            //pish pardakht
char identify2[6];        //shomareh shenasnameh
int pre2;                 //sod
int numinstal2;           //tadad aghsat barye in ozv
int numrest2;             //tedad baghimandeh aghsat
int goodscode2[5];        //code cala max=5 cala
char name_g2[20][5];            //name cala max=5 cala
DATE date2;
long int allprice;
}mem;
//------------------------------------***
class MEMBER:public GOODS{
char name[20];
int numbuy;              //tedad calaye kharidary shodeh
int f_instal;            //pish pardakht
char identify[6];        //shomareh shenasnameh
long int deptall;        //cole bedehy
long int paidall;        //cole mablaghy ke bayad  pardaght shavad
int goodscode[5];        //code cala max=5 cala
char name_g[20][5];            //name cala max=5 cala
int pre;                 //sod
int numinstal;           //tadad aghsat barye in ozv
double  priceinstal; //mablagh har ghest ta hade axar 10 ghest
int numrest;             //tedad baghimandeh aghsat
int greatdelay;          //aghar takhir bishtar az yek mah bashad dar inga sabt mishavad
int delay  ;             // takhir
DATE date;
FILE *memfile;
public:
MEMBER(){delay=0;greatdelay=0;numrest=0;priceinstal=0;f_instal=0;num_che=0;};
int numbook;
friend  class GOODS;
void entermember(MEMBER member,MEMBER1 mem);
}mem2[10];
///-------------------
//GOODS1 *goodsfound;

//_________________________________***_______________________________________________
void cute_out(char *string,int start_col)
{
int j;
int x1=start_col,y1=wherey();
for (int i=strlen(string);i>0;i--){
gotoxy (x1,y1);
for (int j=i;j<=strlen(string);j++){
cprintf ("%c",string[j-1]);
}
delay(50);
}
cout<<endl;
}

//_________________________________***_______________________________________________
void cute_in(char *mstring,int start_col)
{
int j=0,i=0;
int x1=start_col,y1=wherey();
for (i=0;i<strlen(mstring);i++){
gotoxy (x1,y1);
for (j=i;j<strlen(mstring);j++){
cprintf ("%c",mstring[j]);
}
delay(50);
cprintf (" \n\r");
}
gotoxy (1,y1);
for (int o=1;o<=79;o++)cprintf (" ");
cprintf("\n\r");
}

//_________________________________***_______________________________________________
void GOODS::get_c(GOODS goods,char *name,int &code,int num,int &find,int &sum)
{
int i;
find=0;
wavefile=fopen("wave.txt","a+b");
if(!wavefile){cout<<"file wave not open\n";getch();return;}
fseek(wavefile,0,SEEK_SET);
while(!feof(wavefile)){
fread(&goods,sizeof(GOODS),1,wavefile);
if(ferror(wavefile)){perror("\t----not read file wave----"); getch();/*clearerr(wavefile);*/ }
if(num==goods.code){
code=goods.code;
name=&goods.name[0];
find=1;
sum+=goods.pricesale;          break;}
}/*end while*/  fclose(wavefile);  name;}
//_________________________________***_______________________________________
void GOODS::get_all(GOODS wave,GOODS1 *goodsfound,char num,int find, formal search,int *found)
{
//goodsfound=(GOODS1 *)malloc(30);
int i,j,k=0,flag=0,k2=0;
char na;
find=0;
wavefile=fopen("wave.txt","rb");
//int filesize=filelength(fileno(wavefile));
if(!wavefile){cout<<"file wave not open\n";getch();return;}
fseek(wavefile,0,SEEK_SET);
while(!feof(wavefile)){
fread(&wave,sizeof(GOODS),1,wavefile);
if(ferror(wavefile)){perror("\t----not read file wave----"); getch(); clearerr(wavefile);}
//puts(search.name_f);
flag=0;

switch(num){
case '1':if(!strcmp(wave.name,search.name_f)) flag=1;break;
case '2':if(wave.code==search.code_f) flag=2;break;
case '3':if(wave.numforma==search.num_f) flag=1;break;
default:cout<<"Invalid selection!\n\r";return;
}//end switch
if((flag==1)||((num=='2') &&(wave.code==search.code_f))){ //$$$$$$
//cprintf ("salam111");
k++;
goodsfound[k].code1=wave.code;
//cout<<goodsfound[k].code1<<"***";
strcpy(goodsfound[k].name1,wave.name);
goodsfound[k].num_che1=wave.num_che; goodsfound[k].type1=wave.type;
goodsfound[k].numforma1=wave.numforma; goodsfound[k].number1=wave.number;
goodsfound[k].codesailor1=wave.codesailor;
for(i=0;i<strlen(wave.typebuy);i++) goodsfound[k].typebuy1[i]=wave.typebuy[i];
goodsfound[k].pricebuy1=wave.pricebuy; goodsfound[k].pricesale1=wave.pricesale;
goodsfound[k].numrest1=wave.numrest; goodsfound[k].numreturn1=wave.numreturn;
goodsfound[k].advance1=wave.advance; goodsfound[k].tot_price1=wave.tot_price;
goodsfound[k].date1.year=wave.date.year; goodsfound[k].date1.month=wave.date.month;
goodsfound[k].date1.day=wave.date.day;
if(wave.num_che){
for(i=0;i<wave.num_che;i++){
goodsfound[k].cheque1[i].numbers=wave.cheque[i].numbers;
goodsfound[k].cheque1[i].value=wave.cheque[i].value;
goodsfound[k].cheque1[i].code_defile=wave.cheque[i].code_defile;
for(j=0;j<strlen(wave.cheque[i].defile);j++)
goodsfound[k].cheque1[i].defile[j]=wave.cheque[i].defile[j];
goodsfound[k].cheque1[i].ch_date.year=wave.cheque[i].ch_date.year;
goodsfound[k].cheque1[i].ch_date.month=wave.cheque[i].ch_date.month;
goodsfound[k].cheque1[i].ch_date.day=wave.cheque[i].ch_date.day; }/*for*/
}/*if*/
find=1;
//puts(goodsfound[k].name1);
//cout <<"------"<<goodsfound[k].code1<<"\n";
if(flag==2)break;}/*$$$$$$*/}//while
fclose(wavefile);
*found=k;
cout<<"Entrie(s) found: "<<k<<"\n\r";
//return goodsfound;
}
//_______________________________
void MEMBER::entermember(MEMBER member,MEMBER1 mem)
{
register int i,j;
char c,ch,name[20];
int num,find;
memfile=fopen("mem.txt","a+b");
if(!memfile){perror("file mem not open");getch();return; }
for(i=0;i<strlen(mem.name2);i++) member.name[i]=mem.name2[i];
member.numbook=mem.numbook2; member.numbuy=mem.numbuy2;
member.f_instal=mem.f_instal2;
for(i=0;i<strlen(member.identify);i++)member.identify[i]=mem.identify2[i];
member.pre=mem.pre2; member.numinstal=mem.numinstal2;
member.date.year=mem.date2.year; member.date.month=mem.date2.month;
member.date.day=mem.date2.day;
for(i=0;i<member.numbuy;i++)       {
member.goodscode[i]=mem.goodscode2[i];
for(j=0;j<strlen(mem.name_g2[i]);j++)
member.name_g[i][j]=mem.name_g2[i][j];   }//end for
member.paidall=mem.allprice; member.deptall=member.paidall-member.f_instal;
member.priceinstal=(member.deptall*member.pre+member.deptall)/member.numinstal;
fseek(memfile,0,SEEK_END);
fwrite(&member,sizeof(MEMBER),1,memfile);
if(ferror(memfile))perror("informations not write in file");
fclose(memfile);
}
//___________________________________***_________________________________________
void GOODS::entergoods(GOODS wave,GOODS1 goods)
{
register int i,j;
int s;
wavefile=fopen("wave.txt","a+b");
if(!wavefile){
cout<<"file donot open"; getch();  exit(1);}
wave.code=goods.code1; s=strlen(goods.name1);
for(i=0;i<s;i++)wave.name[i]=goods.name1[i];
wave.pre=goods.pre1 ;wave.type=goods.type1;
wave.numforma=goods.numforma1;
wave.number=goods.number1;wave.codesailor=goods.codesailor1;
wave.pricebuy=goods.pricebuy1; wave.numreturn=goods.numreturn1;
wave.pricesale=goods.pricesale1; wave.tot_price=goods.tot_price1;
wave.date.year=goods.date1.year; wave.date.month=goods.date1.month;
wave.date.day=goods.date1.day;
if(!goods.num_che1){
wave.num_che=goods.num_che1;
for(i=0;i<wave.num_che;i++) wave.cheque[i].numbers=goods.cheque1[i].numbers;
for(i=0;i<wave.num_che;i++) wave.cheque[i].value=goods.cheque1[i].value;
for(i=0;i<wave.num_che;i++) {wave.cheque[i].ch_date.year=goods.cheque1[i].ch_date.year;
wave.cheque[i].ch_date.month=goods.cheque1[i].ch_date.month;
wave.cheque[i].ch_date.day=goods.cheque1[i].ch_date.day;  }
for(i=0;i<wave.num_che;i++)
for(j=0;j<strlen(goods.cheque1[i].defile);j++)
wave.cheque[i].defile[j]=goods.cheque1[i].defile[j];
for(i=0;i<wave.num_che;i++) wave.cheque[i].code_defile=goods.cheque1[i].code_defile;
}/*end if*/ fseek(wavefile,0,SEEK_END);
fwrite(&wave,sizeof(GOODS),1,wavefile);
if(ferror(wavefile)){cout<<"error in opening file"; getch();exit(1);    }
fclose(wavefile);
}
//__________________________________***_______________________________________
void get_date(int *,int *,int *,int *);
void whereis(int l,int &x,int &y,int &mb);
void get_time(int *hour,int *min,int *sec,int *p_sec);
int numtotal;
void enter_g();
void enter_m();
void search_g();
 //______________________/*  start main  */ __________________________________
main()		     //--------------------//
{
int x1,y2;
normvideo();
textmode(3);
textbackground(0);
textcolor(15);
clrscr();
char key_menu;
int choice,key,i=0,j=0,size_M,size_G;
int cen,year,mon,day,hour,menu,sec,p_sec,min,q,w,e;
GOODS wave1[n],wa,wa1;
MEMBER mem,mem2[n],mem1;
//textattr(15|0*16);
do{
get_date(&cen,&year,&mon,&day);
cout<<"date=(centery,year,moon,day)        "<<cen<<":"<<year<<":"<<mon<<":"<<day<<endl;
get_time(&hour,&min,&sec,&p_sec);
cout<<"time=(hour,minutes,second,%second)  "<<hour<<":"<<min<<":"<<sec<<":"<<p_sec<<endl;
textcolor(12);
y2=wherey();
gotoxy (1,y2);
cute_out("== MAIN MENU ==",10);
textcolor(11);
cute_out("1) Enter members"       ,10);
cute_out("2) Enter goods"         ,10);
cute_out("3) Enter cheque waves"  ,10);
cute_out("4) search waves"        ,10);
cute_out("5) Edit cheques store"  ,10);
cute_out("6) Quit(Esc)"           ,10);
textcolor(15);
cute_out("Push: ",1);
gotoxy (7,wherey()-1);
while (kbhit()) getch();
key_menu=getche();
gotoxy (1,y2);
textcolor(12);
cute_in("== MAIN MENU ==",10); textcolor(11);
cute_in("1) Enter members"       ,10);
cute_in("2) Enter goods"         ,10);
cute_in("3) Enter cheque waves"  ,10);
cute_in("4) search waves"        ,10);
cute_in("5) Edit cheques store"  ,10);
cute_in("6) Quit(Esc)"           ,10);
textcolor(15);
cute_in("Push: ",1);
delay(500);
cout<<endl;
whereis(1,q,w,1);
switch  (key_menu ){
case '1':
enter_m();   break;
case '2':
enter_g(); break;
case '3':
//wa.enter_ch(wave1,size_G); break;
case'4':
search_g(); break;
case '5':
//wa.editche_goods(wave1);break;
case '6':
case 27:exit(0);
}
//key=cin.get();
cprintf ("Hit any key to REturn to main menu....");getch();
clrscr();
}while(key!='5');
getch();
return 0;
}                   /* end of main program and start functions */
//******************************************************************
void enter_g()
{
register int i;
char ch,choice,c;
GOODS  wave;
GOODS1 goods;
do{
cout<<"Enter goods code      : ";cin>>goods.code1;
cout<<"Enter goods name      :  ";gets(goods.name1);   cout<<"\n";
cout<<"Enter precident profit:  "; cin>>goods.pre1; cout<<"\n";
cout<<"Enter cheques type    : \n";cin>>goods.type1;
cout<<"Enter number forma    : \n";cin>>goods.numforma1;
cout<<"Enter number of goods : \n";cin>>goods.number1;
cout<<"Enter sailor code     : \n";cin>>goods.codesailor1;
cout<<"Enter buying price    : \n";cin>>goods.pricebuy1;
cout<<"Enter number goods that return : \n";cin>>goods.numreturn1;
goods.pricesale1=goods.pricebuy1*goods.pre1+goods.pricebuy1;
goods.tot_price1=goods.number1*goods.pricebuy1;
cout<<"enter date goods buy: (y/m/d) \n";
cin>>goods.date1.year>>goods.date1.month>>goods.date1.day;
goods.num_che1=0;
cout<<"----------If buying is by cheque press <t> else another one------------\n";
cin>>ch;
if(ch=='t'||ch=='T'){
cout<<"enter number cheques    :  \n";cin>>goods.num_che1;
cout<<"enter numbers chequs    : \n";
for(i=0;i<goods.num_che1;i++)  cin>>goods.cheque1[i].numbers;
cout<<"enter value of cheque   : \n";
for(i=0;i<goods.num_che1;i++)  cin>>goods.cheque1[i].value;
cout<<"enter cheque date       : \n";
for(i=0;i<goods.num_che1;i++){cin>>goods.cheque1[i].ch_date.year;
cin>>goods.cheque1[i].ch_date.month>>goods.cheque1[i].ch_date.day;   }
cout<<"enter defiles name      : \n";
for(i=0;i<goods.num_che1;i++) cin>>goods.cheque1[i].defile;
cout<<"enter defile code       : \n"; cin>>goods.cheque1[i].code_defile;
}/*end if*/
cout<<"-----------Do you want save informations(y/n)  ?... \n ";
cin>>choice;
if (choice=='y'||choice=='Y')
wave.entergoods(wave,goods);
cout<<"Press K to enter another or any other keys for main menu... \n"; cin>>c;
}while(c=='k'||c=='K');
}
//*********************************************************
void enter_m()
{
register int i,j,ii=0;
char ch,*name;
GOODS wave;
MEMBER member;
MEMBER1 mem;
int find,code;
long int sum;
do{
cout<<"enter member name            : ";gets(mem.name2); cout<<"\n";
cout<<"enter number instalment book : ";cin>>mem.numbook2; cout<<"\n";
cout<<"enter number goods buying    : ";cin>>mem.numbuy2; cout<<"\n";
cout<<"enter first instalment       : ";cin>>mem.f_instal2;cout<<"\n";
cout<<"enter number identify        : ";cin>>mem.identify2 ;cout<<"\n";
cout<<"enter precident profit       : ";cin>>mem.pre2; cout<<"\n";
cout<<"enter number instalment      : "; cin>>mem.numinstal2; cout<<"\n";
cout<<"enter date that buy waves    : ";cin>>mem.date2.year>>mem.date2.month>>mem.date2.day;
cout<<"enter goods code             : \n";
for(i=0;i<mem.numbuy2;){cin>>mem.goodscode2[i];  find=0;
//get_c(GOODS goods,char *name[],int &code,int num,int &find,int &sum);
wave.get_c(wave,name,code,mem.goodscode2[i],find,sum); if(find) {i++; mem.allprice+=sum;
do{
mem.name_g2[i][ii]=*(name+ii);ii++;
}while(!(*(name+ii))); }
else cout<<"Wrong code, Try again\n";}
while (kbhit())getch();
cout<<"Do you want save informations (y/n)? \n";
cin>>ch;
if (ch=='y'||ch=='Y')
member.entermember(member,mem) ;
cout<<"Do you want to continue entering members (y/n)? "<<endl;
cin>>ch;
}while(ch=='y'||ch=='Y');
}
//******************************************************************
void search_g()
{
formal search;
register int i,k=0;
char ch;
GOODS wave;
//FILE *wavefile;
//wavefile=fopen("wave.txt","rb");
//int filesize=filelength(fileno(wavefile));
//fclose(wavefile);
//goodsfound=(GOODS1*) malloc(filesize);

int find;
int maxfound=0;
cout<<"\t 1) Search according to name goods \n";
cout<<"\t 2) Search according to code goods \n";
cout<<"\t 3) Search according to number forma\n";
cout<<"\n\t________________choice one number__________________\n";
ch=getche();
cout<<"\n";
GOODS1 *goodsfound;
switch (ch){
case '1':
cout<<"Enter name :\n";
cin>>search.name_f; /*goodsfound=*/wave.get_all(wave,goodsfound,'1',find,search,&maxfound);break;
case '2':
cout<<"Enter Goods code :\n";
cin>>search.code_f; /*goodsfound=*/wave.get_all(wave,goodsfound,'2',find,search,&maxfound); break;
case '3':
cout<<"Enter number forma :\n";
cin>>search.num_f; /*goodsfound=*/wave.get_all(wave,goodsfound,'3',find,search,&maxfound); break;
}/*end switch*/
while (kbhit())getch();
if((find)&&(maxfound)){
//goodsfound=(GOODS1 *) malloc (maxfound+1);
clrscr();
cout<<" ÉÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍÍÍÍÍËÍÍÍÍÍÍÍÍÍÍÍÍÍÍ» \n";
cout<<" º  code  º   name  º numforma º number rest º  price sale º  code sailor º \n";
cout<<" ÇÄÄÄÄÄÄÄÄ×ÄÄÄÄÄÄÄÄÄ×ÄÄÄÄÄÄÄÄÄÄ×ÄÄÄÄÄÄÄÄÄÄÄÄÄ×ÄÄÄÄÄÄÄÄÄÄÄÄÄ×ÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¶ \n";
//do{
for (int k=1;k<=maxfound;k++){
gotoxy (2,wherey());
cout<<"º "<<goodsfound[k].code1;
gotoxy (11,wherey());
cout<<"º ";
puts(goodsfound[k].name1);
gotoxy (21,wherey()-1);
cout<<"º "<<goodsfound[k].numforma1;
gotoxy (32,wherey());
cout<<"º "<<goodsfound[k].numrest1;
gotoxy (46,wherey());
cout<<"º "<<goodsfound[k].pricesale1;
gotoxy (60,wherey());
cout<<"º "<<goodsfound[k].codesailor1;
gotoxy (75,wherey());
cout<<"º\n\r";
}
cout<<" ÈÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍÍÍÊÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼ \n\r\n\r";
//free (goodsfound);
//k++;
//}while(goods->code1!=NULL);
}}
//******************************************************************
void get_date(int *cen,int *year,int *mon,int *day)
{
union REGS in,out;
in.h.ah=4;
int86(0x1a,&in,&out);
*cen=out.h.al;
*year=out.h.cl;
*mon=out.h.dh;
*day=out.h.dl;
}
//*************************************************************
void get_time(int *hour,int *min,int *sec,int *p_sec)
{
union REGS in,out;
in.h.ah=0x2c;
intdos(&in,&out);
*hour=out.h.ch;
*min=out.h.cl;
*sec=out.h.dh;
*p_sec=out.h.dl;
}
//**************************************************************
int test_key()    //which key choice
{                        // 0:shift right      5:numlook    on
union REGS in,out;        //1:shift            6:capslock on
in.h.ah=0xb;               //2:ctrl            7:insert on
intdos(&in,&out);          //3:alt
return(out.h.al);          //4:scrollock on
}
//**************************************************************
void whereis(int l,int &x,int &y,int &mb)
{
union REGS r;
if(l){r.x.ax=0x1;   int86(0x33,&r,&r);}   //neshan dadan mouse (l=1)
else{ r.x.ax=0x0;   int86(0x33,&r,&r);}   //no neshan dadan mouse   (l=0)
while(mb!=1){
r.x.ax=0x3;           //mogheiyat mouse
int86(0x33,&r,&r);
mb=r.x.bx;
x=r.x.cx;
y=r.x.dx;   }
}

