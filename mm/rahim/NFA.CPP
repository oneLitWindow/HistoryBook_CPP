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
#include "regular_expression.h"
/////////////////////////////////////////////////////
class NFA:public regular_expression{
	private:
	      int *transition[];
	      char *state;
	      stack s;
	public:
	      void build_nfa(char *,NFA );
	};
//////////////////////////////////////////////////////
void NFA::build_nfa(char *f,NFA b)
{
	if (b.valid_expression2(f))
	{
	    //int c=0;
	    for (int i=0;i<strlen(f);i++)
	    {
	      if (((f[i]=='(') && (f[i]==')')))
		continue;
	      if (f[i]=='+')
	      {
		s.push(f[i]);
	      }
	      if (f[i]=='*')
	      {
		s.pop();
	      }

	    }
	}
}
/*//////////////////////////////////////////////////////
void NFA::build_nfa(char *f,NFA b)
{
	if (b.valid_expression2(f))
	{
	    int c=0;
	    for (int i=0;i<strlen(f);i++)
	    {
		if (!(strchr(alphabet,f[i])) && (f[i]!=alphabet[0]))
		{
		   c++;
		}
		if (f[i]=='(')
		{
		   if (!(strchr(alphabet,f[i])) && (f[i]!=alphabet[0]))
		   {

		   }
		}
		state= new char[c];


	    }
	}
} */
//////////////////////////////////////////////////////
int main()
{
	NFA a;
	a.get_alphabet();
	char*f=a.get_expression();
	a.build_nfa(f,a);
	return 0;
}