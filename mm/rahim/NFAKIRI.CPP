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
#include "L1.h"
#include "L2.h"
#include "STACKt.h"
#include "regular_expression.h"

struct targets{
char tranition;
int  targetstate;
};
///////////////////////////////////////////////////
struct states{
int statenum;
targets *target;
};
///////////////////////////////////////////////////
class nfa{
public:
nfa(){
start=0;end=0;
}
states *state;
private:
int start,end;
};
//////////////////////////////////////////////////

//////////////////////////////////////////////////
void build_nfa(char f[],char alphabet[])
{
	stack <char> c;
	for (int i=0;i<strlen(f);i++)
	{
		if (strchr(alphabet,f[i]))
		{
			nfa *a=new nfa;
			a->build(f[i]);
		}
		if (f[i]=='*')
			;
		if (f[i]=='+')
			c.push(f[i]);
	}
	char h;
	while (c.empty())
	{
		h=c.pop();
		if (h=='+')
		{
			nfa *a=new nfa;
			a->add();
		}
	}
	nfa *a=new nfa;
	a=b.pop();
	a->chap();
}

//////////////////////////////////////////////////
int main()
{
	clrscr();
	regular_expression a1;
	cout<<endl;
	char *alphabet=a1.get_alphabet();
	char f[]="a+b";//a1.get_expression();
	if (a1.valid_expression2(f))
		build_nfa(f,alphabet);
	getch();
	return 0;
}