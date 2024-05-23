#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
int check16hbyte(char B){
int flag=48;
char T=0;
asm{
mov AX, 00
mov ah,12h
int 16h
//mov T, ah;
test al,B
jz noflag
mov flag,49
}
noflag:
return flag;
}
char rshift(){check16hbyte(1);  }
char lshift(){check16hbyte(2);  }
char ctrl  (){check16hbyte(4);  }
char alt   (){check16hbyte(8);  }
char scroll(){check16hbyte(16); }
char num   (){check16hbyte(32); }
char caps  (){check16hbyte(64); }
char insert(){check16hbyte(128);}

main(){
cout<<endl<<endl<<endl<<"Enter a key to begin! ";
getch();
cout<< "-> Wait...";
delay (2000);
cout<< "-> Began!"<<endl;

while (kbhit())getch();
cout<<"rshift is now: ³"<<rshift()<<"³"<<endl;
cout<<"lshift is now: ³"<<lshift()<<"³"<<endl;
cout<<"ctrl   is now: ³"<<ctrl  ()<<"³"<<endl;
cout<<"alt    is now: ³"<<alt   ()<<"³"<<endl;
cout<<"scroll is now: ³"<<scroll()<<"³"<<endl;
cout<<"num    is now: ³"<<num   ()<<"³"<<endl;
cout<<"caps   is now: ³"<<caps  ()<<"³"<<endl;
cout<<"insert is now: ³"<<insert()<<"³"<<endl;
cout<<endl<<"Ended! -> Enter a key to Exit!"<<endl;
getch();
}