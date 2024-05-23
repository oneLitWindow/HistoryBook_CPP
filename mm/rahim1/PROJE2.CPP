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
///////////////////////////////////////////////////
/*int stlen(char *s)
{
	for (int i=0;;i++)
	if (s[i]==0) return i;
} */
///////////////////////////////////////////////////
char *biparantesof(char *s)
{
	char *temp;
	temp=new char(strlen(s));
	int j=0;
	for (int i=0;i<=strlen(s);i++)
	{if ((s[i]!='(') && (s[i]!=')')) {temp[j++]=s[i];}}
	return temp;
}
///////////////////////////////////////////////////
class regular_expression
	{
	    private:
	    char    *expression;
	    char    *alphabet;

	    public:
		 void getalphabet();
		 int valid_expression2(char*);
		 char *get_expression();
	};
///////////////////////////////////////////////////
void regular_expression::getalphabet()
{
	cout<<"Please Enter Alphabet."<<endl;
	gets(alphabet);
	strcat(alphabet,"~");
	cout<<strlen(alphabet);
	cout<<"----"<<biparantesof(alphabet)<<endl;
	getch();
}
///////////////////////////////////////////////////
int regular_expression::valid_expression2(char *d)
{
	int h=1;
	int k=0;
	char *f=d;
	if (f[0]=='+')
	{
		h=0;
		cout<<"The unmatch or error ecour in the first."<<endl;
		return h;
	}

	if (f[strlen(f)-1]=='+')
	{
		h=0;
		cout<<"The unmatch or error ecour in end."<<endl;
		return h;
	}
	for (int i=0;i<strlen(f);i++)
	{
		if ((k<0) ) {
			h=0;
			cout<<"The unmatch or error ecour in "<<i<<endl;
			return h;
			}
		if (f[i]==')')
		{
		     k--;
		}
		if (f[i]=='(')
		{
		     (k)++;
		}
		if ((f[i]=='(') && ((f[i+1]=='*') ||(f[i+1]=='+')))
		{
			h=0;
			cout<<"The unmatch or error ecour in "<<i+1<<endl;
 		return h;
		}
		if ((f[i]=='+') && ((f[i+1]==')') ||(f[i+1]=='+') ||(f[i+1]=='*')))
		{
			h=0;
			cout<<"The unmatch or error ecour in "<<i+1<<endl;
			return h;
		}
		if (!(strchr(alphabet,f[i])) && (f[i]!=alphabet[0]) && (f[i]!='(') && (f[i]!=')') && (f[i]!='~'))
		{
			if ((f[i]=='*')||(f[i]=='+'))
				continue;
			cout<<"The unmatch or error ecour in "<<i<<endl;
			h=0;
			return h;
		}
	}
	if (k>0)
		h=0;
    return h;
}
///////////////////////////////////////////////////
char *regular_expression::get_expression()
{
	cout<<"Enter Your Expression:"<<endl;
	char *g;
	gets(g);
	return g;
}
///////////////////////////////////////////////////
int main()
{
	regular_expression a;
	a.getalphabet();
	if (a.valid_expression2(a.get_expression()))
		cout<<"The Expression Is Regular.";
	else
		cout<<"The Expression Is Irregular.";
	getch();
	return 0;
}