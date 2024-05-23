/*                                                                   /
/ Program by Amin Safinejad        (8453308)    Amin1986@gmail.com   /
/            Mohammad OstadHashemi (8453301). Ostadhashemi@gmail.com /
/            (Software engineering)                        	     /
/ ------------------------------------------------------------------ /
/ 1385.4 - Descrete mathematics, Mr. Rezvani.              	     /
/ ------------------------------------------------------------------ /
/ þ Mohammad! tooye goroohe man faghat khodamam!         	     /
/   (ye nafari hastam!), Che konim?!                     	     /
/ þ Rasti, "Yal" be english chi mishe?!!!                	     /
/ 							  	    */
#include "stdio.h"
#include "iostream.h"
#include "conio.h"
#include "stdlib.h"
#include "graphics.h"
#include "dos.h"
#include "ctype.h"
#include "string.h"
int is_directional=0,is_weighted=0,v_num=0,u_num=0;
FILE *file;
void draw_cadr(int x1,int y1,int x2,int y2,int c,int b){
window (1,1,80,25);
textcolor(c);
textbackground(b);
clrscr();
for (int i=x1+1;i<=x2-1;i++){
gotoxy (i,y1);cprintf("Í");
gotoxy (i,y2);cprintf("Í");}
for (i=y1+1;i<=y2-1;i++){
gotoxy (x1,i); cprintf("º");
gotoxy (x2,i);cprintf("º");}
gotoxy (x1,y1);
cprintf("É");
gotoxy(x2,y1);
cprintf ("»");
gotoxy(x1,y2);
cprintf("È");
gotoxy (x2,y2);
cprintf ("¼");
gotoxy (x1,y1);
window (x1+1,y1+1,x2-1,y2-1);
}

void get_user_info(){
file=fopen ("graf.dat","w+");
char c;
int maxvertex=0;
do{
textcolor( 3);cprintf ("Is the graf directional (Y/N)? ");textcolor (10);c=toupper(getche());cprintf ("\n\r");
}while ((c!='Y')&&(c!='N'));
if (c=='Y'){is_directional=1;fprintf(file,"%c\n",'D');} else fprintf (file,"%c\n",'U');

do{
textcolor(11);cprintf ("Is the graf Weighted    (Y/N)? ");textcolor ( 2);c=toupper(getche());cprintf ("\n\r");
}while ((c!='Y')&&(c!='N'));
if (c=='Y') {is_weighted=1;fprintf(file,"%c\n",'W');} else fprintf (file,"%c\n",'U');
char s[3];
strcpy (s,"");
textcolor( 3);cprintf ("Enter number of vertexes:      ");textcolor (10);gets(s);v_num=atoi(s);gotoxy(1,wherey());
fprintf (file,"%d\n",v_num);
strcpy (s,"");
textcolor(11);cprintf ("Enter number of Yal:           ");textcolor ( 2);gets(s);u_num=atoi(s);gotoxy(1,wherey());
fprintf (file,"%d\n",u_num);
fclose(file);
}
void main(){
textbackground (1);
textcolor(15);
clrscr();
draw_cadr(1,1,80,24,15,1);
get_user_info();
draw_graf();
}