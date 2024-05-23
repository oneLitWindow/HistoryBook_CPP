/* Assembly Code generated in C++     **
** for changing cursor position, Size **
** and screen color (+clear).         **
** By AMIN SAFINEJAD #8453308,        **
** Sat. 12-23-2006 = 1385/10/02       */

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
clrscr(char X, char Y )               //
{                                     //
X=X+(Y*16);                           //
asm{                                  //
mov ah,06                             //
mov al,00                             //
MOV BH, X                             //
mov cl,00                             //
mov ch,00                             //
mov dl,79                             //
mov dh,24                             //
int 10h                               //
}                                     //
}                                     //
////////////////////////////////////////
cursorsize(char X, char Y)            //
{                                     //
asm{                                  //
mov ah,01                             //
mov ch, X                             //
mov cl, Y                             //
int 10h                               //
}                                     //
}                                     //
////////////////////////////////////////
main()                                //
{                                     //
	resetcursorposition;          //
	clrscr(15,1);                 //
	cursorsize(0,8);              //
}                                     //
////////////////////////////////////////
