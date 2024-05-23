int counter2=0;
struct indis{
	int a;
	int b;
};
/***********************************************/
struct red{
	int  a;
	int  b;
};
char talbot[100];
/***********************************************/
struct data_dfa
{
	int  state1;
	int  states[20];
	linklist2  dfalist2;
};
int counter1=0;
/***********************************************/
int	searcharr(int temp[],int t)
{
	for(int i=0;i<20;i++)
	{
		if (temp[i]==0)
			break;
		if (temp[i]==t)
			return(1);
	}
	return (0);
}
/***********************************************/
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
/***********************************************/
class dfa:public NFA
{
	private:
		int start1;
//		linklist1<data_dfa>  redlist1;
		linklist1<data_dfa>  dfalist1;
	public:
		void	show(linklist1<red>);
		void	indistingushable();
		linklist1<red>  distingushable();
		void 	build_dfa();
		int* 	findstate(char, int,int& );
		void  print();
};
/***********************************************/
stack <dfa> st,st1;
/***********************************************/
int 	equal(int ty[],int yt[])
{
	for (int i=0;i<20;i++)
		if (yt[i]!=ty[i])
			return(0);
	return(1);
}
/***********************************************/
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
/***********************************************/
void dfa::build_dfa()
{
	int k=0;
	dfa a1;
	counter1++;
	int help[20]={0};
	data_dfa r,r2;
	a1.start1=r.state1=counter1;
	r.states[0]=1;
	r.states[1]=0;
	a1.dfalist1.insertdata(r);
	r2.state1=++counter1;
	r2.states[0]=0;
	for( int i=0;i<strlen(talbot)-1;i++)
		r2.dfalist2.insertdata(talbot[i],counter1);
	a1.dfalist1.insertdata(r2);
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
//	a1.print();
}
/***********************************************/
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
/***********************************************/
linklist1<red>	dfa::distingushable()
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
		r=a1.dfalist1.search(k);
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
/***********************************************/
void	dfa::indistingushable()
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
						flag=0;
					jj++;
				}
				if (flag)
				{
					r=a1.dfalist1.search(k);
					r1=a1.dfalist1.search(a);
					int q1,q2;
					for (int i=0;i<stlen(talbot);i++)
					{
						q1=r.dfalist2.search(talbot[i]);
						q2=r1.dfalist2.search(talbot[i]);
						int kk=1;
						if (q1==q2)
							continue;
						while (counter2>kk)
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
	show(link3);
	indis q[20];
	for (int i=1;i<=counter1;i++)
	{
		q[i].a=i;
		q[i].b=i;
	}
	k=1;
	int f=counter1;
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
				rec=link3.search(kk);
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
}
/***********************************************/
void	dfa::show(linklist1<red> temp)
{
	red r;
	for(int i=1;i<=counter2;i++)
	{
		r=temp.search(i);
		cout<<"a="<<r.a<<", b="<<r.b;
		cout<<"        ";
	}
}
/***********************************************/
