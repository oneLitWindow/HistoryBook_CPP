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
template< class type>
class NFA:public regular_expression{
	private:
	      int start;
	      int end;
		  int counter;
	      linklist1 <linklist2> list1;
	public:
	      NFA(){counter=0;};
	      void build_nfa1(char *,NFA<type> );
	      void build_nfa(char *,int& ,char,int &,int &);
	      void build(char ,int,int&,int&,int&,int&);
	      void multiple(int&,int&,int&,int&);
	      void add(int&,int&,int&,int&);
	      void star(int&,int&,int&,int&,int);
	      void chap();
	};
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::add(int &start1 ,int &end1 ,int &start2 ,int &end2)
{
	linklist2 list2;
	linklist2 list3;
	counter+=2;
	list2.insertdata('~',start1);
	list2.insertdata('~',start2);
	chap();
	list1.insertdata(list2);
	list3=list1.search(end1);
	list3.insertdata('~',counter);
	list1.replace(list3,end1);
	list3=list1.search(end2);
	list3.insertdata('~',counter);
	list1.replace(list3,end2);
	start1=counter-1;
	end1=counter;
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::multiple(int &start1 ,int &end1 ,int &start2 ,int &end2)
{
	linklist2 list2;
	list2=list1.search(end1);
	list2.insertdata('~',start2);
	list1.replace(list2,end1);
	end1=end2;
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::star(int &start1 ,int &end1 ,int &start2 ,int &end2 ,int q)
{
	linklist2 list2;
/*	counter+=2;
	if (q==1)
	{
		start1=counter-1;
		end1=counter;
	}
	else
	{
		start2=counter-1;
		end2=counter;
	}  */

	if (q==1)
	{
		list2=list1.search(start1);
		list2.insertdata('~',end1);
		list1.replace(list2,start1);
		list2=list1.search(end1);
		list2.insertdata('~',start1);
		list1.replace(list2,end1);
	}
	else
	{
		list2=list1.search(start2);
		list2.insertdata('~',end2);
		list1.replace(list2,start2);
		list2=list1.search(end2);
		list2.insertdata('~',start2);
		list1.replace(list2,end2);
	}
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build(char w,int q, int &start1 ,int &end1 ,int &start2 ,int &end2)
{
	linklist2 list2;
	linklist2 list3;
	counter+=2;
	if (q==1)
	{
		start1=counter-1;
		end1=counter;
	}
	else
	{
		start2=counter-1;
		end2=counter;
	}
	list2.insertdata(w,counter);
	list1.insertdata(list2);
	list1.insertdata(list3);
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build_nfa(char *f,int &b, char d,int &r,int &a)
{
	linklist2 list2;
	int start1;
	int end1;
	int start2;
	int end2;
	int k=1;
	for(int i=b;i<strlen(f);i++)
	{
	  cout<<"********"<<endl<<"Now processing :"<<f[i]<<endl<<"*******";
		if (f[i]==')')
			if ((f[i+1]=='*'))
			{
				star(start1,end1,start2,end2,1);
				b=++i;
				r=start1;
				a=end1;
				return;
			}
			else
			{
				r=start1;
				a=end1;
				b=i;
				return;
			}
		if ((f[i]=='+'))
		{
			build_nfa(f,++i,'+', r, a);
			end2=a;
			start2=r;
			add(start1,end1,start2,end2);
			continue;
		}
		if ((f[i]=='*'))
		{
			star(start1,end1,start2,end2,1);
			continue;
		}
		if ((k) && (strchr(alphabet,f[i])))
		{
			k=0;
/*			cout<<f[i]<<"-"<<start1<<"-"<<end1<<"-"<<start2<<"-"<<end2<<endl;
			getch();*/
			build(f[i],1,start1,end1,start2,end2);
			if ((strchr(alphabet,f[i+1])) && (i+1<strlen(f)))
			{
				i++;
				build(f[i],2,start1,end1,start2,end2);
				if ((f[i+1]=='*'))
				{
					++i;
					star(start1,end1,start2,end2,2);
				}
				multiple(start1,end1,start2,end2);
			}
			continue;
		}
		if  (strchr(alphabet,f[i]) && ( (!k) || (f[i-1]=='*') ) )
		{
			build(f[i],2,start1,end1,start2,end2);
			multiple(start1,end1,start2,end2);
		}
		int l=i;
		if (f[i]=='(')
		{
			build_nfa(f,++i,'(' , r, a);
			end2=a;
			start2=r;
			if ((l!=0) && (f[l]!='ş'))
				multiple(start1,end1,start2,end2);
		}
	 }
	 r=start1;
	 a=end1;

	 if (d=='s')
	 {
		cout<<" counter: "<<counter;
		start=start1;
		end=end1;
	 }
				b=i;
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build_nfa1(char *f,NFA<type> b)
{
	int start3;
	int end3;
	if (b.valid_expression2(f))
	{
		 build_nfa(f,0,'s', start3, end3);
	}
}
///////////////////////////////////////////////////////
template< class type>
void NFA<type>::chap()
{
	linklist2 list2;
	for(int i=1;i<=counter;i++)
	{
		list2=list1.search(i);
		cout<<endl<<"Transition For State:"<<i;
//		if (i==5)
		list2.catchdata();
	}
}

//////////////////////////////////////////////////////
int main()
{
	NFA<char> a;
	a.get_alphabet();
	char f[]="(a+b)";//a.get_expression();
	a.build_nfa1(f,a);
	a.chap();
	getch();
	return 0;
}