////////////////////////////////////////
resetcursorposition()                 //
{                                     //
asm{                                  //
mov ah,02                             //
mov bh,00                             //
mov dl,00                             //
mov dh,00                             //
int 10h}                              //
}                                     //
////////////////////////////////////////
cursorsize(char X=7, char Y=8)        //
{                                     //
asm{                                  //
mov ah,01                             //
mov ch, X                             //
mov cl, Y                             //
int 10h                               //
}                                     //
}                                     //
///////////////////////////////////////////////////////////////////
void clr(int x1=1,int y1=1,int x2=80,int y2=25){                                                      //
int j;                                                           //
//textbackground(1);                                             //
for (int i=x1;i<=x2;i++) {                                        //
	for (j=y1;j<=y2;j++) {gotoxy(i,j);                        //
	cprintf (" ");}delay (10);                               //
	}//clrscr();                                               //
//recadr();                                                      //

}                                                                //
///////////////////////////////////////////////////////////////////
void initializescreen(int background=0){                         //
  textmode(C80);                                                 //
  normvideo();                                                   //
  cursorsize();                                                  //
  resetcursorposition();                                         //
  textbackground(background);                                    //
  clr();                                                         //
}                                                                //
///////////////////////////////////////////////////////////////////
void tcolor(int foreground=7,int background=0,int clearscreen=0){//
  textcolor(foreground);                                         //
  textbackground(background);                                    //
  if (clearscreen)  clr();                                       //
}                                                                //
///////////////////////////////////////////////////////////////////
void getkeys(){                                                  //
while (kbhit())getch();                                          //
}                                                                //
///////////////////////////////////////////////////////////////////
void gprintf(char s[80]) {                                       //
int x=wherex(),y=wherey();                                       //
int j;                                                           //
for (int i=1;i<=strlen(s);i++) {                                 //
gotoxy (x,y);                                                    //
for (j=strlen(s)-i;j<=strlen(s);j++) {cprintf("%c",s[j]);}     //
gotoxy (x,y);                                                    //
delay(20);                                                       //
}                                                                //
}                                                                //
///////////////////////////////////////////////////////////////////
void centerg(char s[80],int y){                                  //
gotoxy ((81-strlen(s))/2,y);                                     //
gprintf(s);                                                      //
}                                                                //
///////////////////////////////////////////////////////////////////
void center(char s[80],int y){                                   //
gotoxy ((81-strlen(s))/2,y);                                     //
cprintf("%s",s);                                                 //
}                                                                //
///////////////////////////////////////////////////////////////////
void recadr(int x1=4,int y1=2,int x2=78,int y2=24,int d=10){     //
//textcolor(15);                                                   //
//textbackground(1);                                               //
gotoxy (x1-1,y1);                                                  //
cprintf(" É");                                                    //
delay (d);                                                       //
for (int i=x1+1;i<=x2-1;i++){                                    //
gotoxy (i,y1);cprintf("Í");delay(d);}                            //

gotoxy(x2,y1);                                                   //
cprintf ("» ");                                                   //
delay(d);                                                        //

for (i=y1+1;i<=y2-1;i++){                                        //
gotoxy (x2,i); cprintf("º ");delay(d);}                                     //

gotoxy (x2,y2);                                                  //
cprintf ("¼ ");                                                   //
delay(d);
for (i=x2-1;i>=x1+1;i--){                                    //
gotoxy (i,y2);cprintf("Í");delay(d);}                            //

gotoxy(x1-1,y2);                                                   //
cprintf(" È");                                                    //
delay(d);

for (i=y2-1;i>=y1+1;i--){                                        //
gotoxy (x1-1,i); cprintf(" º");delay(d);}                                     //
clr(x1+1,y1+1,x2-1,y2-1);

}                                                                //
///////////////////////////////////////////////////////////////////

