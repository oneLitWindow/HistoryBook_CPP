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
#include "asmkey.h"
#include "L1.h"
#include "L2.h"
#include "STACKt.h"
#include "regular_.h"
#include "nfa.h"
/////////////////////////////////////////////////
char talbot[80];
struct data_dfa
{
	int  state1;
	int states[100];
	linklist2  dfalist2;
};
int counter1=0;
/////////////////////////////////////////////////
class dfa:public NFA
{
	private:
		int start;
		int end;
		linklist1<data_dfa>  dfalist1;
	public:
		void 	build_dfa();
		char* 	findstate(char, int );
		void    print();
};
/////////////////////////////////////////////////
stack <dfa> st,st1;
//////////////////////////////////////////////////
char* dfa::findstate(char t,int r)
{
	dfa b1;
	int k=1,s=0;
	data_dfa d;
	b1=st.pop();
	st.push(b1);
	char *l;
	if (t=='f')
		getch();
	l=find(t,r);
	if (strlen(l)==0)
	{
		char *temp="\0";
		strcpy(temp,"");
		itoa(2,temp,10);
		strcat(temp,"!");
		return(temp);
	}
	while (1)
	{
		d=b1.dfalist1.search(k);
		if (strcmp(d.states,l)==0)
		{
			s=k;
			break;
		}
		k++;
		if (k>counter1) break;
	}
	if (s==0)
	{
		if (strlen(l)>0)
			return(l);
	}
	else
	    {
		char *temp="\0";
		strcpy(temp,"");
		itoa(s,temp,10);
		strcat(temp,"!");
		return(temp);
	    }
}
/////////////////////////////////////////////////
void dfa::build_dfa()
{
	int k=0;
	dfa a1;
	counter1++;
	char *help="\0";
	data_dfa r,r2;
	a1.start=r.state1=counter1;
	r.states[0]=1;
	a1.dfalist1.insertdata(r);
	r2.state1=++counter1;
	r2.states[]=0;
	for( int i=0;i<strlen(talbot)-1;i++)
		r2.dfalist2.insertdata(talbot[i],counter1);
	a1.dfalist1.insertdata(r2);
	st.push(a1);
	int w,z=2;
	dfa q=a1;
	cout<<endl<<"&*************************"<<endl;
	while (1)
	{
		a1=st.pop();
		st.push(a1);
		k++;
		if (k==2)
			k++;
		w=n_omin(r.states,k);
		if (z==3)
			getch();
		if (w>0)
		{
			for (int i=0;i<(strlen(talbot))-1;i++)
			{
				help=findstate(talbot[i],w);
				if (help[strlen(help)-1]=='!')
				{
					help[strlen(help)-1]='\0';
					r.dfalist2.insertdata(talbot[i],atoi(help));
				}
				else //if (talbot[i]!='d')
				    {
					data_dfa r1;
					r.dfalist2.insertdata(talbot[i],++counter1);
					strcpy(r1.states,help);
					r1.state1=counter1;
					a1.dfalist1.insertdata(r1);
				    }
//				a1.dfalist1.replace(r,k);
			}
		}
		if (w==-1)
		{
			r=a1.dfalist1.search(++z);
			k=0;
		}
		st1.push(a1);
		st.pop();
		st.push(st1.pop());
		a1.print();
	}
}
/////////////////////////////////////////////////
void	dfa::print()
{
	data_dfa r;
	for(int i=1;i<=counter1;i++)
	{
		r=dfalist1.search(i);
//		cout<<"Salam dayoos!!!";
		cout<<"Transition For State "<<r.state1<<" , state name :"<<r.states;
		r.dfalist2.catchdata();
		getch();
	}

}
/////////////////////////////////////////////////
int main()
{
	clrscr();
	dfa a2;
	clrscr();
	regular_expression a1;
	char *alphabet1=a1.get_alphabet();
	strcpy(talbot,alphabet1);
	char *f="d.((a.c)+(d.b).(b+f))*";//a1.get_expression();
	cout<<"Expression is: "<<f<<endl;
	if (a1.valid_expression2(f))
		build_nfa1(f,alphabet1,talbot);
	a2.build_dfa();
	getch();
	return 0;
}
