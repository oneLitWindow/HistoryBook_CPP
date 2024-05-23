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
//#include "L.h"
#include "L1.h"
#include "L2.h"
#include "STACKt.h"
#include "regular_expression.h"
/////////////////////////////////////////////////////
template< class type>
class NFA:public regular_expression{
	private:
//	      int *transition[];
//	      char *state;
	      int start1;
	      int end1;
	      int start2;
	      int end2;
	      int counter;
	      linklist2 list;
	      linklist1 <linklist2> h;
	public:
	      void build_nfa1(char *,NFA<type> );
	      void build_nfa(char *,int);
	      void build(char);
	};
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build(char w)
{
//	insert
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build_nfa(char *f,int b)
{
	for(int i=b;i<=strlen(f);i++)
	{
		if (f[i]==')')
			return;
		if (f[i]=='(')
			build_nfa(f,i);
	 }
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build_nfa1(char *f,NFA<type> b)
{

	if (b.valid_expression2(f))
	{
	    for (int i=0;i<strlen(f);i++)
	    {
	      if (f[i]=='(')
		 build_nfa(f,i);
	      if (f[i]=='+')
	      {
	      }
	      if (f[i]=='*')
	      {
	      }

	    }
	}
}
///////////////////////////////////////////////////////

//////////////////////////////////////////////////////
int main()
{
	NFA<char> a;
	a.get_alphabet();
	char*f=a.get_expression();
	a.build_nfa1(f,a);
	return 0;
}