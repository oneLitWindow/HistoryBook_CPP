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
#include "L1.h"
#include "L2.h"
#include "STACKt.h"
#include "regular_.h"
#include "nfa.h"
/////////////////////////////////////////////////
char talbot[100];
struct data_dfa
{
	int  state1;
	int  states[20];
	linklist2  dfalist2;
};
int counter1=0;
/////////////////////////////////////////////////
int* putarr2(int temp[],int temp1[])
{
	int k=0,t,flag;
	if (temp[0]==0)
		for(int i=0;i<20;i++)
		{
			if (temp1[i]==0)
				break;
			temp[i]=temp1[i];
		}
	else
	{
		for(int i=0;i<20;i++)
			if (temp[i]==0)
			{
				t=i;
				break;
			}
		for (k=0;k<20;k++)
		{
			if (temp1[k]==0)
				break;
			flag=1;
			for (i=0;i<t;i++)
				if (temp1[k]==temp[i])
				{
					flag=0;
					break;
				}
			if (flag)
				temp[t++]=temp1[k];
		}
	}
	return (temp);
}
//////////////////////////////////////////////////////
class dfa:public NFA
{
	private:
		int start;
		int end;
		linklist1<data_dfa>  dfalist1;
	public:
		void 	build_dfa();
		int* 	findstate(char, int,int& );
		void    print();
};
/////////////////////////////////////////////////
stack <dfa> st,st1;
//////////////////////////////////////////////////
int 	equal(int ty[],int yt[])
{
	for (int i=0;i<20;i++)
		if (yt[i]!=ty[i])
			return(0);
	return(1);
}
//////////////////////////////////////////////////
int* dfa::findstate(char t,int r,int &kk)
{
	kk=0;
	dfa b1;
	int k=1,s=0;
	data_dfa d;
	b1=st.pop();
	st.push(b1);
	int l[20]={0};
	putarr(l,find1(t,r));
	while (1)
	{
		d=b1.dfalist1.search(k);
		if (equal(d.states,l))
		{
			s=k;
			kk=k;
			break;
		}
		k++;
		if (k>counter1)
			break;
	}
	if ((kk!=0) || (s==0))
		if (l[0]!=0)
			return(l);
	int temp[20]={0};
	return(temp);
}
/////////////////////////////////////////////////
void dfa::build_dfa()
{
	int k=0;
	dfa a1;
	counter1++;
	int help[20]={0};
	data_dfa r,r2;
	a1.start=r.state1=counter1;
	r.states[0]=1;
	r.states[1]=0;
	a1.dfalist1.insertdata(r);
	r2.state1=++counter1;
	r2.states[0]=0;
	for( int i=0;i<strlen(talbot)-1;i++)
		r2.dfalist2.insertdata(talbot[i],counter1);
	a1.dfalist1.insertdata(r2);
	a1.print();
	st.push(a1);
	int w,m=0;
	while (1)
	{
		a1=st.pop();
		st.push(a1);
		m++;
		if (m>counter1)
			break;
		if (m==2)
			m++;
		for (int i=0;i<(strlen(talbot))-1;i++)
		{
			r=a1.dfalist1.search(m);
			while(1)
			{
				int kk=0;
				w=r.states[k];
				k++;
				if (w<=0)
				{
					k=0;
					break;
				}
				putarr2(help,findstate(talbot[i],w,kk));
			}
			if (help[0]==0)
				r.dfalist2.insertdata(talbot[i],2);
			else
			{
				int x=1,flag=1;
				while (1)
				{
					data_dfa p;
					p=a1.dfalist1.search(x);
					if (equal(p.states,help))
					{
						flag=0;
						break;
					}
					x++;
					if (counter1<x)
						break;
				}
				if (flag)
				{
					data_dfa r1;
					counter1++;
					x=counter1;
					for (int y=0;y<20;y++)
						r1.states[y]=help[y];
					r1.state1=counter1;
					a1.dfalist1.insertdata(r1);
					r.dfalist2.insertdata(talbot[i],x);
				}
				else
					r.dfalist2.insertdata(talbot[i],x);
			}
			a1.dfalist1.replace(r,m);
			for (int y=0;y<20;y++)
			{
				if (help[y]==0)
					break;
				help[y]=0;
			}
		}
		st1.push(a1);
		st.pop();
		st.push(st1.pop());
	}
	a1.print();
}
/////////////////////////////////////////////////
void	dfa::print()
{
	data_dfa r;
	for(int i=1;i<=counter1;i++)
	{
		r=dfalist1.search(i);
		cout<<"Transition For State "<<r.state1<<" , state name :";
		for (int o=0;o<20;o++)
		{
			if (r.states[o]==0)
				break;
			cout<<r.states[o]<<",";
		}
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
	char f[]="((a)+(b+c+d+e+f+g+h+i)+(j+k+l+m)+(p+n)+o)*+(a+h+g+f+d+n)";//a1.get_expression();
	cout<<"Expression is: "<<f<<endl;
	if (a1.valid_expression2(f))
		build_nfa1(f,alphabet1,talbot);
	getch();
//	a2.build_dfa();
	getch();
	return 0;
}
