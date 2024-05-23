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
#include "regular_.h"
/////////////////////////////////////////////////////
struct  data
	{
		linklist2 list2;
		int state;
	};
/////////////////////////////////////////////////////
class NFA
	{
	private:
	      int start;
	      int end;
	      int counter1;
	      linklist1 <data> list1;
	public:
	      NFA(){counter1=0;};
	      ~NFA(){return;};
	      void build_nfa();
	      void build(char);
	      void multiple();
	      void add();
	      void star();
	      void chap();
	};
//////////////////////////////////////////////////////
stack <NFA*> b;
int counter;
//////////////////////////////////////////////////////
void NFA::build(char t)
{
	NFA *a=new NFA;
	data r,r1;
	linklist2 list2;
	counter+=2;
	r.state=counter-1;
	r.list2.insertdata(t,counter);
	a->list1.insertdata(r);
	r1.state=counter;
	a->list1.insertdata(r1);
	counter1=counter;
	a->end=counter;
	a->start=counter-1;
	b.push(a);
}
//////////////////////////////////////////////////////
void NFA::add()
{
	int k=1;
	data r,r1,r2;
	NFA *b1,*b2;
	b2=b.pop();
	b1=b.pop();
	counter+=2;
	k=1;
	while (1)
	{
		r=b2->list1.search(k);
		b1->list1.insertdata(r);
		if (r.state==b2->end)
			break;
		k++;
	}
	k=1;
	while (1)
	{
		r=b1->list1.search(k);
		if (r.state==b2->end)
			break;
		k++;
	}
	r.state=b2->end;
	r.list2.insertdata('~',counter);
	r.list2.catchdata();
	b1->list1.replace(r,b2->end);
	k=1;
	while (1)
	{
		r=b1->list1.search(k);
		if (r.state==b1->end)
			break;
		k++;
	}
	r.list2.insertdata('~',counter);
	b1->list1.replace(r,b1->end);
	r1.state=counter-1;
	r1.list2.insertdata('~',b2->start);
	r1.list2.insertdata('~',b1->start);
	b1->list1.insertdata(r1);
	r2.state=counter;
	b1->list1.insertdata(r2);
	b1->end=counter;
	b1->start=counter-1;
	b.push(b1);
}
//////////////////////////////////////////////////////
void NFA::star()
{
	data r;
	NFA *b1;
	b1=b.pop();
	int k;
	k=1;
	while (1)
	{
		r=b1->list1.search(k);
		if (r.state==b1->start)
			break;
		k++;
	}
	r.list2.insertdata('~',b1->end);
	b1->list1.replace(r,b1->start);
	k=1;
	int s;
	while (1)
	{
		r=b1->list1.search(k);
		if (r.state==b1->end)
		{
			s=k;
			break;
		}
		k++;
	}
	r.list2.insertdata('~',b1->start);
	b1->list1.replace(r,s);
	b.push(b1);
}
//////////////////////////////////////////////////////
void NFA::chap()
{
	data r;
	for(int i=1;i<=counter;i++)
	{
		r=list1.search(i);
		cout<<"Transition For State "<<r.state<<": ";
		r.list2.catchdata();
	}
}
//////////////////////////////////////////////////////
void NFA::multiple()
{
	NFA *b1,*b2;
	data r,r1;
	b2=b.pop();
	b1=b.pop();
	int k=1;
	while (1)
	{
		r=b1->list1.search(k);
		if (r.state==b1->end)
			break;
		k++;
	}
	while (1)
	{
		r1=b2->list1.search(k);
		if (r1.state==b2->end)
			break;
		k++;
	}


	k=1;
	while (1)
	{
		r=b2->list1.search(k);
		b1->list1.insertdata(r);
		if (r.state==b2->end)
			break;
		k++;
	}

	k=1;
	int s;
	while (1)
	{
		r=b1->list1.search(k);
		if (r.state==b1->end)
		{
			s=k;
			break;
		}
		k++;

	}

	r.list2.insertdata('~',b2->start);
	b1->list1.replace(r,s);
	b1->end=b2->end;
	b.push(b1);
}
//////////////////////////////////////////////////////
void build_nfa1(char f[],char alphabet[])
{
	stack <char> c;
	int k=0;
	int m=1;
	int t=0;
	for (int i=0;i<strlen(f);i++)
	{
		if (f[i]=='*')
		{
			NFA *a=new NFA;
			a->star();
		}
		if (f[i]=='(')
		     t++;
		if (strchr(alphabet,f[i]))
		{
			NFA *a=new NFA;
			a->build(f[i]);
			k++;
			if (m==0)
			{
				if (f[i+1]=='*')
				{
					i++;
					a->star();
				}
				a->multiple();
				k--;
			}
			m=0;
		}
		if (f[i]=='+')
		{
			m=1;
			c.push(f[i]);
			if (k>1)
			{
				char h;
				h=c.pop();
				if (h=='+')
				{
					NFA *a=new NFA;
					a->add();
				}
				k=1;
			}
		}
		if ((t>0) && (f[i]==')'))
		{
			char h;
			while (c.empty())
			{
				h=c.pop();
				if (h=='+')
				{
					NFA *a=new NFA;
					a->add();
				}
			}
		}
	}
	char h;
	while (c.empty())
	{
		h=c.pop();
		if (h=='+')
		{
			NFA *a=new NFA;
			a->add();
		}
	}
	NFA *a=new NFA;
	a=b.pop();
	a->chap();
}
//////////////////////////////////////////////////////
int main()
{
	clrscr();
	regular_expression a1;
	cout<<endl;
	char *alphabet=a1.get_alphabet();
	char f[]="(a*b)*";//a1.get_expression();
	cout<<"Expression is: "<<f<<endl;getch();
	if (a1.valid_expression2(f))
		build_nfa1(f,alphabet);
	getch();
	return 0;
}