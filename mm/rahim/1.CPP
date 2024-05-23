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
//	      ~NFA(){return;};
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
	NFA *myb;
	b2=b.pop();
	b1=b.pop();
	counter+=2;


	r1.state=counter-1;
	r1.list2.insertdata('~',b2->start);
	r1.list2.insertdata('~',b1->start);
	b2->list1.insertdata(r1);
//	b1->list1.replace(r1,counter-1);
//	b1->end=counter;
cout<<"b1 is: 03298703245094385"<<endl;
b2->chap();
getch();
	k=1;
	while (1)
	{
		r=b2->list1.search(k);
		b1->list1.insertdata(r);
		if (r.state==b2->end)
			break;
		k++;

	}
cout<<endl<<"*******\\b1/****"<<endl;
b1->chap();
cout<<endl<<"*******++++****"<<endl;
getch();
b2->chap();
cout<<endl<<"*******/b2\\****"<<endl;
getch();

	k=1;
	while (1)
	{
		r=b1->list1.search(k);
		if (r.state==b2->end)
			break;
		k++;
	}
cout << "after first while"<<endl;getch();
	r.list2.insertdata('~',counter);

	b1->list1.replace(r,b2->end);

cout << "after replace"<<endl;getch();
//	int temp=b2->start;
//	cout<<"Salam"<<endl;
//	delete(b2);

	k=1;
	while (1)
	{
		r=b1->list1.search(k);
		if (r.state==b1->end)
			break;
		k++;
	}
cout << "after second while"<<endl;getch();

	r.list2.insertdata('~',counter);
	b1->list1.replace(r,b1->end);
cout<<"bad az replace avali********\\b1/**"<<endl;
b1->chap();
cout<<"********/b1\\**"<<endl;
//if (counter==4)counter=6;
getch();

cout<<"counter="<<counter<<endl;
//if (counter==6)counter=4;
cout<<"b1.end="<<b1->end<<endl;
cout<<"********\\b1/**"<<endl;
b1->chap();
cout<<"********/b1\\**"<<endl;
//if (counter==4)counter=6;
getch();

cout << "after replace"<<endl;getch();

//	b1->list1.insertdata(r1);
	r1.state=counter-1;
	r1.list2.insertdata('~',b2->start);

	r1.list2.insertdata('~',b1->start);

cout<<"--- pish kir!"<<endl;
	r1.list2.catchdata();
cout<<"--- get ready to be kir!"<<endl;
getch();
cout<<"******** \\b1/ **"<<endl;
b1->chap();
cout<<"******** /b1\\ **"<<endl;
getch();

data l;
l.state=counter-1;
l.list2.insertdata('~',b1->start);
l.list2.insertdata('~',b2->start);
myb->list1.insertdata(l);
cout<<"******** \\myb/ **"<<endl;
myb->chap();
cout<<"******** /myb\\ **"<<endl;
getch();


/*
myb->start=counter-1;
myb->list1.list2.insertdata('~',b1->start);
myb->list1.list2.insertdata('~',b2->start);
*/
	k=1;
	while (1)
	{
		r=myb->list1.search(k);
		b1->list1.insertdata(r);
		if (r.state==myb->end)
			break;
		k++;

	}
cout<<"SSSSS******** \\b1/ **"<<endl;
b1->chap();
cout<<"******** /b1\\ **"<<endl;
getch();


getch();
/*
//	b1->list1.insertdata(r1);
	b1->list1.replace(r1,counter-1);
	b1->end=counter;

cout<<"******** \\b1/ **"<<endl;
b1->chap();
cout<<"******** /b1\\ **"<<endl;
getch();

	r2.state=counter;
	b1->list1.insertdata(r2);
cout << "after others"<<endl;getch();
cout<<"******** \\b1/ **"<<endl;
b1->chap();
cout<<"******** /b1\\ **"<<endl;
getch(); */
	b.push(b1);
cout << "after push to stack"<<endl;getch();

//	delete(b1);
}
//////////////////////////////////////////////////////
void NFA::chap()
{
	data r;
	data oldr;
	for(int i=1;i<=counter;i++)
	{
		r=list1.search(i);
		//if ((i>1)&&(r.state==oldr.state)) break;
		oldr=r;
		cout<<endl<<"Transition For State "<<r.state<<": ";
		r.list2.catchdata();
		getch();
		//if (!r.list2.catchdata()) break;
	}
}
//////////////////////////////////////////////////////
void build_nfa1(char f[],char alphabet[])
{
	stack <char> c;
	for (int i=0;i<strlen(f);i++)
	{
		if (strchr(alphabet,f[i]))
		{
			NFA *a=new NFA;
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
	char f[]="a+b";//a1.get_expression();
	if (a1.valid_expression2(f))
		build_nfa1(f,alphabet);
	getch();
	return 0;
}