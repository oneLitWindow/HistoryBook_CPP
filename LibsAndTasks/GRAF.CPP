/*                                                                   /
/ Program by Amin Safinejad        (8453308)    Amin1986@gmail.com   /
/            Mohammad OstadHashemi (8453301). Ostadhashemi@gmail.com /
/            (Software engineering)                        	     /
/ ------------------------------------------------------------------ /
/ 1385.4 - Descrete mathematics, Mr. Rezvani.              	     /
/ ------------------------------------------------------------------ /
/ HI!, Zoor nazan finglish neveshtam...				     /
/ ‏ Mohammad! tooye goroohe man faghat khodamam!         	     /
/   (ye nafari hastam!), Che konim?!                     	     /
/ ‏ Rasti, "Yal" be english chi mishe?!!!                	     /
/ 							  	     /
/ ‏‏‏ Esme function ha va modele barname, tooye in noskhe hanooz     /
/     TAGHYIR NAKARDE, age lazem bood khodet taghyireshoon bede. bye /
/								    */
#include "stdio.h"
#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#include "graphics.h"
#include "dos.h"
#include "ctype.h"
#include "string.h"
#include "malloc.h"
#include "math.h"
int is_directional=0,is_weighted=0,v_num=0,u_num=0;
FILE *file;
unsigned char *matrix;
void draw_cadr(int x1,int y1,int x2,int y2,int c,int b){
window (x1,y1,x2,y2);
textcolor(c);
textbackground(b);
clrscr();
window (1,1,80,25);
gotoxy (1,1);
for (int i=x1+1;i<=x2-1;i++){
gotoxy (i,y1);cprintf("ֽ");
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
gotoxy (x1,y1);
window (x1+1,y1+1,x2-1,y2-1);
}

void get_user_info(){
file=fopen ("graf.dat","w+");
textcolor(14);
cprintf ("Database file created, GRAF.DAT...\n\r");
textcolor(10);
cprintf ("=======================================\r");
char c;
int maxyal=0;
do{
textcolor(15);cprintf ("Is the graf directional (Y/N)? ");textcolor (10);c=toupper(getche());cprintf ("\n\r");
}while ((c!='Y')&&(c!='N'));
if (c=='Y'){is_directional=1;fprintf(file,"%c\n",'D');} else fprintf (file,"%c\n",'U');
do{
textcolor(11);cprintf ("Is the graf Weighted    (Y/N)? ");textcolor (14);c=toupper(getche());cprintf ("\n\r");
}while ((c!='Y')&&(c!='N'));
if (c=='Y') {is_weighted=1;fprintf(file,"%c\n",'W');} else fprintf (file,"%c\n",'U');
char s[3];
do{
strcpy (s,"");
textcolor(15);cprintf ("Enter number of vertexes:      ");textcolor (10);gets(s);v_num=atoi(s);cprintf ("\r");
}while (v_num<=0);
/*M A L L O C*/matrix=(unsigned char*)malloc(pow((v_num+1)*sizeof(unsigned char),2));
// Matrix v+1 dar v+1 ast va meghdar dehi az khaneye 1 shoroo mishavad na khaneye 0!
// (be sefromin khane kar nadarim)

for (int i=1;i<=pow(v_num,2);i++)matrix[i]=0;

maxyal=(v_num)*(v_num-1);
if (!is_directional) maxyal/=2;
fprintf (file,"%d\n",v_num);
do{
strcpy (s,"");
textcolor(11);cprintf ("Enter number of Yal:           ");textcolor (14);gets(s);u_num=atoi(s);cprintf ("\r");
}while ((u_num>maxyal) || (u_num<0));
fprintf (file,"%d\n",u_num);
int k,l;
for (int j=1;j<=u_num;j++){
textcolor(10);
cprintf ("תתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתת\r");
do{textcolor (15);cprintf ("Enter Yal #%d beginning   vertex: ",j);textcolor(14);scanf ("%d",&k);cprintf ("\r");}while ((k<1)||(k>v_num));
do{textcolor (15);cprintf ("Enter Yal #%d destination vertex: ",j);textcolor(14);scanf ("%d",&l);cprintf ("\r");}while ((l<1)||(l>v_num));
fprintf (file,"%d,%d\n",k,l);
matrix[((k-1)*v_num)+l]=1;
}
fclose(file);
}
void main(){
textmode(3);
textbackground (0);
textcolor(15);
clrscr();
draw_cadr(1,1,80,24,15,1);
draw_cadr(10,5,70,21,11,3);
draw_cadr(20,8,60,18,10,2);
get_user_info();
//draw_graf();
}