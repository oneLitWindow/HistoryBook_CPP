/*                                                                   /
/ Program by Amin Safinejad        (8453308)      Amin1986@gmail.com /
/            Mohammad OstadHashemi (8453301). Ostadhashemi@gmail.com /
/            Rahim Tofigh          (84531??).   rm.tofeegh@gmail.com /
/            				      (Software engineering) /
/ ------------------------------------------------------------------ /
/ 1385.4 - Descrete mathematics project (GRAF), Mr. Rezvani.   	     /
/ ------------------------------------------------------------------ /
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
//////////////////// Our own headers:
#include "grf_tim.h"
#include "grf_mse.h"
#include "grf_grp.h"
//////////////////////////////////////////////////////////////////////////////
int is_directional=0,is_weighted=0,v_num=0,u_num=0,max_degree=0;
FILE *file;
unsigned char *matrix;
//////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////
void get_user_info(){
file=fopen ("graf.dat","w+");
textcolor(14);
cprintf ("Database file created, GRAF.DAT...\n\r");
textcolor(10);
cprintf ("=======================================\r");
char c;
int maxedge=0;
is_directional=0;
is_weighted=0;
v_num=0;
u_num=0;
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
}while ((v_num<=0)||(v_num>30));
maxedge=(v_num)*(v_num-1);
if (!is_directional) maxedge/=2;
fprintf (file,"%d\n",v_num);
do{
strcpy (s,"");
textcolor(11);cprintf ("Enter number of Edges:         ");textcolor (14);gets(s);u_num=atoi(s);cprintf ("\r");
}while ((u_num>maxedge) || (u_num<0));
fprintf (file,"%d\n",u_num);
int k,l,w=1;
int ko,lo;
for (int j=1;j<=u_num;j++){
textcolor(10);
cprintf ("תתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתתת\r");
do{textcolor (15);cprintf ("Enter edge #%2d beginning   vertex: ",j);textcolor(14);scanf ("%d",&k);cprintf ("\r");}while ((k<1)||(k>v_num));
do{textcolor (15);cprintf ("Enter edge #%2d destination vertex: ",j);textcolor(14);scanf ("%d",&l);cprintf ("\r");}while ((l<1)||(l>v_num)||(k==l));
if (is_weighted)do{textcolor (15);cprintf ("Enter edge #%2d weight:             ",j);textcolor(14);scanf ("%d",&w);cprintf ("\r");}while ((w<1)||(w>999));
fprintf (file,"%d,%d,%d\n",k,l,w);
}
fclose(file);
}
//////////////////////////////////////////////////////////////////////////////
void build_matrix(){
file=fopen("graf.dat","r");
fseek(file,0,0);
char c1,c2;
fscanf (file,"%c\n%c\n%d\n%d\n",&c1,&c2,&v_num,&u_num);
if (c1=='D') is_directional=1; else is_directional=0;
if (c2=='W') is_weighted=1; else is_weighted=0;
//cprintf ("%c - %c - %d - %d",c1,c2,v_num,u_num);
free(matrix);
/*M A L L O C*/matrix=(unsigned char*)malloc(pow((v_num+1)*sizeof(unsigned char),2));
// Matrix v+1 dar v+1 ast va meghdar dehi az khaneye 1 shoroo mishavad na khaneye 0!
// (be sefromin khane kar nadarim)
int k,l,w,ko,lo;
char c11,c22;
for (ko=1;ko<=v_num;ko++)for (lo=1;lo<=v_num;lo++)matrix[((ko-1)*v_num)+lo]=0;
while (!feof(file)){fscanf(file,"%d%c%d%c%d\n",&k,&c11,&l,&c22,&w);matrix[((k-1)*v_num)+l]=w;
		    if (!is_directional) matrix[((l-1)*v_num)+k]=w;}
clrscr();
max_degree=(v_num-1);
if (is_directional) max_degree*=2;
fclose(file);
}
//////////////////////////////////////////////////////////////////////////////
int vertex_outgoing(int v){
//faghat TEDADE yal haye kharej shode az ras ra barmigardanad, na vazne anha!
int j=0;
for (int i=1;i<=v_num;i++){if (matrix[((i-1)*v_num)+v]) j++;}
return j;}
//////////////////////////////////////////////////////////////////////////////
int vertex_incoming(int v){
//faghat TETADE yal haye vared shode be ras ra barmigardanad, na vazne anha!
int j=0;
for (int i=1;i<=v_num;i++){if (matrix[((v-1)*v_num)+i]) j++;}
return j;}
//////////////////////////////////////////////////////////////////////////////
int vertex_degree(int v){if (is_directional)return (vertex_outgoing(v)+vertex_incoming(v));
return ((vertex_outgoing(v)+vertex_incoming(v))/2);}
//////////////////////////////////////////////////////////////////////////////
int is_full(){
int flag=1;
for (int i=1;i<=v_num;i++)if (vertex_degree(i)<max_degree) {flag=0;break;}
return flag;}
//////////////////////////////////////////////////////////////////////////////
int v_x(int v,int a){
double angel=0;
angel=v*(6.283/v_num);
return ((2*((getmaxx()/5)+a)*cos(angel))+((getmaxx()-(getmaxx()/16))/2.0));
}
//////////////////////////////////////////////////////////////////////////////
int v_y(int v,int a){
double angel=0;
angel=v*(6.283/v_num);
//return (2*(float(v_num)*sin(angel))+(getmaxy()/2.0)-(getmaxx()/32));
return ((2*((getmaxy()/5)+a)*sin(angel))+((getmaxy()-(getmaxx()/16))/2.0));
}
//////////////////////////////////////////////////////////////////////////////
void draw_graf(){
initsvga();
settextstyle (2,0,4);
settextjustify(1,1);
char s[2]="";
int p;
for (int v=1;v<=v_num;v++){
itoa(v,s,10);
if (float(v)/float(v_num)<=0.5) p=((float(v))/(float(v_num)))*(float(getmaxx())/32.0)*2;
else p=(1-((float(v))/(float(v_num))))*(float(getmaxx())/32.0)*2;
setcolor(100+p);
circle (v_x(v,0),v_y(v,0),(100-(v_num))/40);
outtextxy (v_x(v,5),v_y(v,5),s);
delay(10);
}
int i,j,aa=0;
setcolor(9);
if (is_directional) aa=-1;
settextstyle (2,0,2);
for (i=1;i<=v_num;i++)
for (j=1;j<i;j++)
{if (matrix[((i-1)*v_num)+j]) {line (v_x(i,0)+aa,v_y(i,0)+aa,v_x(j,0)+aa,v_y(j,0)+aa);
//itoa(matrix[((i-1)*v_num)+j],s,10);outtextxy(v_x(i,10),v_y(i,10),s);
delay(10);}}
if (is_directional){
setcolor(12);
for (i=1;i<=v_num;i++)
for (j=i+1;j<=v_num;j++)
{if (matrix[((i-1)*v_num)+j]) {line (v_x(i,0)+1,v_y(i,0)+1,v_x(j,0)+1,v_y(j,0)+1);
//itoa(matrix[((i-1)*v_num)+j],s,10);outtextxy(v_x(i,10),v_y(i,10),s);
delay(10); }}
}
while (kbhit()){
while (kbhit())getch();
delay(500);}
getch();
closegraph();
}
//////////////////////////////////////////////////////////////////////////////
void show_matrix(){
initsvga();
//settextjustify (1,2);
//setviewport (0,0,getmaxx(),getmaxy(),1);
//setcolor (14);
//settextstyle (1,0,2);
//outtextxy ((getmaxx()/2)-(getmaxx()/32),(getmaxy())-getmaxx()/32-5,"Use arrow keys to scroll table...");
//setviewport (getmaxx()/32+1,getmaxx()/32+1,getmaxx()-(getmaxx()/32)-1,getmaxy()-getmaxx()/32-1,1);
settextjustify (0,2);
setcolor(15);
settextstyle (2,0,2);
char stemp[3]="",s[(4*30)+10];
int y=0,ko,lo;
for (ko=1;ko<=v_num;ko++){
itoa(ko,stemp,10);
while (strlen(stemp)<2) strcat (stemp," ");
strcpy (s,stemp);
strcat (s," >  ");
for (lo=1;lo<=v_num;lo++) {
itoa (matrix[((ko-1)*v_num)+lo],stemp,10);
while (strlen(stemp)<3) strcat (stemp," ");
strcat(s,stemp);
strcat(s," ");
}
strcat(s,"<");
outtextxy (10,y,s);
y+=14;
}
while (kbhit()){
while (kbhit())getch();
delay(500);}
getch();
closegraph();
}
/*
for (ko=1;ko<=v_num;ko++){
for (lo=1;lo<=v_num;lo++) cprintf ("%2d ",matrix[((ko-1)*v_num)+lo]);
cprintf ("\n\r");
}
*/
//////////////////////////////////////////////////////////////////////////////

void main(){
textmode(3);
textbackground (0);
textcolor(15);
clrscr();
draw_cadr(1,2,80,24,15,1);
draw_cadr(10,5,70,21,11,3);
draw_cadr(20,8,60,18,10,2);
get_user_info();
draw_cadr(10,5,70,21,11,3);
build_matrix();
if (is_full()) cprintf ("The graf is Complete!"); else cprintf ("The graf is Incomplete!\n\r");
getch();
clrscr();
draw_graf();
show_matrix();
}