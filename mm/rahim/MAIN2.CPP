#include <string.h>  //
#include <ctype.h>   //
#include <iostream.h>//
#include <stdio.h>   //
#include <stdlib.h>  //
#include <dos.h>     //
#include <conio.h>   //
#include <graphics.h>//
#include <math.h>    //
#include <process.h> //
///////////////////////
#include "foo_date.h"//
#include "foo_keyb.h"//
#include "foo_mous.h"//
#include "foo_grpe.h"//
#include "supercrt.h"//
//#include "draw.h"  //
//#include "asmkey.h"//
///////////////////////
#include "L1.h"      //
#include "L2.h"      //
#include "STACKt.h"  //
#include "regular_.h"//
#include "nfa.h"     //
#include "dfa.h"     //
#include "reduce.h"  //
////////////////////////////////////////////////////////////////////////
int main()
{
	initializescreen();
	reduce a3;
	dfa a2;
	NFA a1;
	clrscr();
	regular_expression r;
	char f[250]="";//char f[]="d.((a.c)+(d.b).(b+f))*";//*/ "((a)+(b+c+d+e+f+g+h+i)+(j+k+l+m)+(p+n)+o)*+(a+h+g+f+d+n+q+w+e)";
	strcpy (f,r.get_expression());
	gotoxy (1,wherey()-1);
	gprintf ("Expression is:");
	gprintf (f);
	cprintf ("\n\r");
	char *alphabet1;
	alphabet1=new char[80];
	strcpy(alphabet1,"\0");
	strcpy(talbot,r.get_alphabet());
	if (r.valid_expression2(f))
		a1=build_nfa1(f,alphabet1,talbot); else {getch();exit(1);}
	a1.chap();
//	cprintf ("\n\r");
	tcolor (12,0);
	space80();
	gprintf ("End of NFA... Press any key to continue...");
	getch();
	tcolor (15,0);
	clr();
	a2=a3.build_dfa();
	a2.print();
	tcolor (12,0);
	space80();
	gprintf ("End of DFA... Press any key to continue...");
	getch();
	tcolor (15,0);
	clr();
	a3.makereduce();
	getkeys();
	getch();
//	draw();
	closescreen();
	return 0;
}