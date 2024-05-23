#include <string.h>  //
#include <ctype.h>   //
#include <iostream.h>//
#include <stdio.h>   //
#include <stdlib.h>  //
#include <dos.h>     //
#include <conio.h>   //
#include <graphics.h>//
#include <math.h>    //
#include <process.h> //
///////////////////////
#include "foo_date.h"//
#include "foo_keyb.h"//
#include "foo_mous.h"//
#include "foo_grpe.h"//
#include "supercrt.h"//
#include "draw.h"    //
//#include "asmkey.h"//
///////////////////////
#include "L1.h"      //
#include "L2.h"      //
#include "STACKt.h"  //
#include "regular_.h"//
#include "nfa.h"     //
#include "dfa.h"     //
#include "reduce.h"  //
///////////////////////

/***********************************************/
/*
struct red{
	int  a;
	int  b;
};
/***********************************************/
/*struct data1_dfa
{
	int  state1;
	int  states[20];
	linklist2  dfalist2;
};*/
/***********************************************/
/*
red* putarr3(red temp[],red temp1[],int &f)
{
	for (int i=0;i<=f;i++)
	{
		temp[i].a=temp1[i].a;
		temp[i].b=temp1[i].b;
	}
	return (temp);
}
/***********************************************/
/*
class reduce:public dfa
{
	private:
			linklist1<data_dfa>  redlist1;
	public:
			void  show1(reduce);
			void	show(linklist1<red>);
			void	indistingushable();
			linklist1<red>  distingushable();
			red*	hamarzi(linklist1<red>, int&);
			void	build_reduce(red [],int&);
};
/***********************************************/
//int counter3=0;
/***********************************************/
/*
red*	reduce::hamarzi(linklist1<red>  lk, int &f)
{
	int k,kk,flag;
	red q[20],rec;
	for (int i=1;i<=counter1;i++)
	{
		q[i-1].a=i;
		q[i-1].b=i;
	}
	k=1;
	f=counter1-1;
	while (k<=counter1)
	{
		for (i=1;i<=counter1;i++)
		{
			flag=1;
			int kk=1;
			if (k==i)
				continue;
			while (kk<=counter2)
			{
				rec=lk.search(kk);
				if ((rec.a==k) && (rec.b==i)|| (rec.b==k) && (rec.a==i))
				{
					flag=0;
					break;
				}
				kk++;
			}
			if (flag)
			{
				for (int ii=1;ii<=f;ii++)
				{
					if ((q[ii].a==k) && (q[ii].b==i)|| (q[ii].b==k) && (q[ii].a==i))
					{
						flag=0;
						break;
					}
				}
				if (flag)
				{
					q[++f].a=k;
					q[f].b=i;
				}
			}
		}
		k++;
	}
	return(q);
}
/ * ********************************************** /
linklist1<red>	reduce::distingushable()
{
	red rec;
	linklist1<red> c;
	int k=0,f=0;
	dfa a1;
	a1=st.pop();
	st.push(a1);
	data_dfa  r;
	int  arr[20]={0};
	int l=a1.getend();
	while (k<counter1)
	{
		k++;
		r=a1.searchstate(k);
		if (searcharr(r.states,l))
			arr[f++]=r.state1;
	}
	k=0;
	while (k!=f)
	{
		for (int i=1;i<=counter1;i++)
			if ((arr[k]!=i) && (!searcharr(arr,i)))
			{
				rec.a=i;
				rec.b=arr[k];
				c.insertdata(rec);
				counter2++;
			}
		k++;
	}
	return (c);
}
/*********************************************** /
void	reduce::indistingushable()
{
	red rec;
	dfa a1;
	a1=st.pop();
	st.push(a1);
	data_dfa  r,r1;
	linklist1<red>   link3;
	link3=distingushable();
	int R2=1,k,a,jj,flag;
	while (R2!=0)
	{
		R2=0;
		k=1;
		while (k<=counter1)
		{
			a=1;
			while (a<=counter1)
			{
				jj=1;
				flag=1;
				if (a==k)
				{
					a++;
					if (a>counter1)
						break;
				}
				while ((flag) && (counter2>=jj))
				{
					rec=link3.search(jj);
					if (((rec.a==a) && (rec.b==k)) || ((rec.a==k) && (rec.b==a)))
					{
						flag=0;
				break;
					}
					jj++;
				}
				if (flag)
				{
					r=a1.searchstate(k);
					r1=a1.searchstate(a);
					int q1,q2;
					for (int i=0;i<stlen(talbot)-1;i++)
					{
						q1=r.dfalist2.search(talbot[i]);
						q2=r1.dfalist2.search(talbot[i]);
						int kk=1;
						if (q1==q2)
							continue;
						while (counter2>=kk)
						{
							rec=link3.search(kk);
							if (((rec.a==q1) && (rec.b==q2)) || ((rec.a==q2) && (rec.b==q1)))
							{
								rec.a=a;
								rec.b=k;
								link3.insertdata(rec);
								R2=1;
								counter2++;
								i=stlen(talbot);
								break;
							}
							kk++;
						}
					}
				}
				a++;
			}
			k++;
		}
	}
	red p[20];
	show(link3);
	int f=0;
	putarr3(p,hamarzi(link3,f),f);
	cout<<endl<<"******************************"<<endl;
	for (int i=0;i<=f;i++)
	{
		cout<<"a="<<p[i].a<<", b="<<p[i].b<<"        ";
	}
	build_reduce(p,f);
}
/*********************************************** /
void	reduce::build_reduce(red temp[],int &f)
{
	reduce  n;
	data_dfa r,r1,r2;
	int k,a,flag,kk=1,j=f,jj=1,o=0;
	while(1)
	{
		k=1;
		flag=1;
		while (k<=counter3)
		{
			r1=n.redlist1.search(k);
			if (searcharr(r1.states,kk))
			{
				kk++;
				flag=0;
				break;
			}
			k++;
		}
		if (flag)
		{
			r.states[o++]=kk;
			r.state1=jj;
			jj++;
			j--;
			counter3++;
			for (int i=0;i<=f;i++)
			{
				if ((temp[i].a==kk) && (temp[i].b!=kk))
				{
					r.states[o++]=temp[i].b;
					j--;
					temp[i].a=0;
					temp[i].b=0;
				}
				else if ((temp[i].b==kk) && (temp[i].a!=kk))
				{
					r.states[o++]=temp[i].a;
					j--;
					temp[i].a=0;
					temp[i].b=0;
				}
			}
			kk++;
			r.states[o]=0;
			n.redlist1.insertdata(r);
			o=0;
		}
		if (kk>counter1)
			break;
	}
	dfa a1;
	a1=st.pop();
	st.push(a1);
	jj=1;
	while (1)
	{
		k=1;
		while (1)
		{
			r1=n.redlist1.search(k);
			if (r1.state1==jj)
			{
				mychar w=r1.dfalist2.get(talbot[0],1);
				if (w.state==-1)
				{
					r=a1.searchstate(r1.states[0]);
					for (int i=0;i<stlen(talbot)-1;i++)
					{
						kk=r.dfalist2.search(talbot[i]);
						f=1;
						while (1)
						{
							r2=n.redlist1.search(f);
							if (searcharr(r2.states,kk))
							{
								r1.dfalist2.insertdata(talbot[i],f);
								break;
							}
							f++;
							if (f>counter3)
								break;
						}
					}
					n.redlist1.replace(r1,k);
				}
			}
			k++;
			if (k>counter3)
				break;
		}
		jj++;
		if (jj>counter3)
			break;
	}

	k=1;
	cout<<endl<<"**********RAHIM**************"<<endl;
	show1(n);
}
/*********************************************** /
void	reduce::show(linklist1<red> temp)
{
	red r;
	for(int i=1;i<=counter2;i++)
	{
		r=temp.search(i);
		cout<<"a="<<r.a<<", b="<<r.b;
		cout<<"        ";
	}
}
/*********************************************** /
void	reduce::show1(reduce temp)
{
	data_dfa r;
	for(int i=1;i<=counter3;i++)
	{
		r=temp.redlist1.search(i);
		cout<<"Transition For State "<<r.state1<<" , state name : ";
		for (int o=0;o<20;o++)
		{
			if (r.states[o]==0)
				break;
			cout<<r.states[o]<<",";
		}
		cout<<endl;
		r.dfalist2.catchdata();
		getch();
	}
}
/***********************************************/
int main()
{
	textmode(3);
	clrscr();
//	dfa a2;
	reduce a3;
	clrscr();
	regular_expression a1;
	char *alphabet1;
	alphabet1=new char[80];
	strcpy(alphabet1,"\0");
//	a1.get_alphabet();
	strcpy(talbot,a1.get_alphabet());
	char f[]=/*/"d.((a.c)+(d.b).(b+f))*";//*/ "((a)+(b+c+d+e+f+g+h+i)+(j+k+l+m)+(p+n)+o)*+(a+h+g+f+d+n+q+w+e)";//a1.get_expression();
	cout<<"Expression is: "<<f<<endl;
	if (a1.valid_expression2(f))
		build_nfa1(f,alphabet1,talbot); else {getch();exit(1);}
	getch();
	a3.build_dfa();
	a3.makereduce();
	getch();

	return 0;
}