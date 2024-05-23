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
	      int start;
	      int end;
	      int counter;
	      linklist2 list2;
	      linklist1 <linklist2> list1;
	public:
	      NFA(){counter=0;};
	      void build_nfa1(char *,NFA<type> );
	      void build_nfa(char *,int& ,char);
	      void build(char ,int,int&,int&,int&,int&);
	      void multiple(int&,int&,int&,int&);
	      void add(int&,int&,int&,int&);
	      void star(int&,int&,int&,int&);
	};
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::add(int &start1 ,int &end1 ,int &start2 ,int &end2)
{
	linklist2 list3;
	counter+=2;
	list2.insertdata('~',start1);
	list2.insertdata('~',start2);
	list1.insertdata(list2);
	list3=list1.search(end1);
	list3.insertdata('~',counter);
	list3=list1.search(end2);
	list3.insertdata('~',counter);
	start=counter-1;
	end=counter;
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::multiple(int &start1 ,int &end1 ,int &start2 ,int &end2)
{
	list2=list1.search(end1);
	list2.insertdata('~',start2);
	end1=end2;
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::star(int &start1 ,int &end1 ,int &start2 ,int &end2)
{
	list2=list1.search(start1);
	list2.insertdata('~',end1);
	list2=list1.search(end1);
	list2.insertdata('~',start1);
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build(char w,int q, int &start1 ,int &end1 ,int &start2 ,int &end2)
{
	linklist2   list3;
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
	list2.insertdata(w,counter-1);
	list1.insertdata(list2);
	list1.insertdata(list3);
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build_nfa(char *f,int &b, char d)
{
	int start1;
	int end1;
	int start2;
	int end2;
	int k=1;
	for(int i=b;i<=strlen(f);i++)
	{
		if (f[i]==')')
			return;
		if ((f[i]=='+')) //&& (!(d=='+') || !(d=='*')))
		{
			build_nfa(f,i+1,'+');
//			d='+';
			add(start1,end1,start2,end2);
		}
//		else
//		{
//			return;
//		}
		if ((f[i]=='*'))//&& (!(d=='+') || !(d=='*')))
		{
			star(start1,end1,start2,end2);
//			build_nfa(f,i,'*');
		}
//		else
//		{
//			return;
//		}
		if ((k) && (strchr(alphabet,f[i])))
		{
			k=0;
			build(f[i],1,start1,end1,start2,end2);
			if (strchr(alphabet,f[i+1]))
			{
				i++;
				build(f[i],2,start1,end1,start2,end2);
				multiple(start1,end1,start2,end2);
			}
			continue;
		}
		if  (strchr(alphabet,f[i]) && ( (!k) || (f[i-1]=='*') ) )
		{
			build(f[i],2,start1,end1,start2,end2);
			multiple(start1,end1,start2,end2);
		}
		if (f[i]=='(')
			build_nfa(f,i,'(');
	 }
}
//////////////////////////////////////////////////////
template< class type>
void NFA<type>::build_nfa1(char *f,NFA<type> b)
{

	if (b.valid_expression2(f))
	{
		 build_nfa(f,0,'s');
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