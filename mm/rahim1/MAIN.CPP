#include <string.h>
#include <ctype.h>
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <process.h>
//#include "asmkey.h"
//#include "reduce.h"
#include "L1.h"
#include "L2.h"
#include "STACKt.h"
#include "regular_.h"
#include "nfa.h"
#include "dfa.h"
/////////////////////////////////////////////////
int main()
{
	clrscr();
	dfa a2;
	clrscr();
	regular_expression a1;
	char *alphabet1=a1.get_alphabet();
	strcpy(talbot,alphabet1);
	char f[]="d.((a.c)+(d.b).(b+f))*";//"((a)+(b+c+d+e+f+g+h+i)+(j+k+l+m)+(p+n)+o)*+(a+h+g+f+d+n)";//a1.get_expression();
	cout<<"Expression is: "<<f<<endl;
	if (a1.valid_expression2(f))
		build_nfa1(f,alphabet1,talbot);
	getch();
	a2.build_dfa();
	a2.indistingushable();
	getch();
	return 0;
}
