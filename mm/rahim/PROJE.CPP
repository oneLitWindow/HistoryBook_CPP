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
const int Maxmeans = 10;
int stlen(char *s){
for (int i=0;;i++)
if (s[i]==0) return i;
return 0;
}
char *biparantesof(char *s){
char *temp;
temp=new char(stlen(s));
int j=0;
for (int i=0;i<=stlen(s);i++)
{if ((s[i]!='(') && (s[i]!=')')) {temp[j++]=s[i];}}
return temp;
}

class regular_expression
	{
	    private:
	    char    *expression;
	    char    *alphabet;

	    public:
		 void getalphabet();
		 int valid_expression(char*);

	};
void regular_expression::getalphabet(){
gets(alphabet);
cout<<stlen(alphabet);
cout<<"----"<<biparantesof(alphabet);
getch();
}
int regular_expression::valid_expression(char *d)
{
	int h=1;
	char *f=biparantesof(d);
	if (f[stlen(f)]=='+')
	{
		h=0;
		return h;
	}
	for (int i=0;i<stlen(f);i++)
	{
		if (!(strchr(alphabet,f[i])) && (f[i]!=alphabet[0]))
		{
			if ((f[i]=='*')||(f[i]=='+'))
				continue;
			cout<<"The unmatch or error ecour in "<<i;
			h=0;
			return h;
		}
	}
	return h;
}
main(){
char *g;
gets(g);
regular_expression a;
a.getalphabet();
if (a.valid_expression(g))
	cout<<"Rahim is a good boy";
else
	cout<<"Milad is a bad boy";

getch();
}