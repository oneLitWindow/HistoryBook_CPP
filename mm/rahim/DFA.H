int counter2=0;
/*struct indis{
	int a;
	int b;
};
/***********************************************/
char talbot[100];
/***********************************************/
struct data_dfa
{
	int  state1;
	int  states[80];
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
		linklist1<data_dfa>  dfalist1;
	public:
		dfa 	build_dfa();
		int* 	findstate(char, int,int& );
		void  print();
		data_dfa	searchstate(int);
};
/***********************************************/
stack <dfa> st,st1;
/***********************************************/
data_dfa	dfa::searchstate(int k)
{
	dfa b1;
	b1=st.pop();
	st.push(b1);
	return(b1.dfalist1.search(k));
}
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
	int l[80]={0};
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
	int temp[80]={0};
	return(temp);
}
/***********************************************/
dfa dfa::build_dfa()
{
	tcolor (9);centerg ("Now Making DFA... Please wait...\n\r",wherey());
	int k=0;
	dfa a1;
	counter1++;
	int help[80]={0};
	data_dfa r,r2;
	a1.start1=r.state1=counter1;
	r.states[0]=a1.getstart();
	r.states[1]=0;
	a1.dfalist1.insertdata(r);
	r2.state1=++counter1;
	r2.states[0]=0;

	for( int i=0;i<strlen(talbot)-1;i++)
		r2.dfalist2.insertdata(talbot[i],counter1);
	a1.dfalist1.insertdata(r2);
	int kk,jj;
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
			remove_tekrari(help);
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
	tcolor (1);centerg ("DFA made...\n\r",wherey());

	return a1;
}
/***********************************************/
void	dfa::print()
{
	int screencontrol=1;
	data_dfa r;
	cprintf ("\r");
	tcolor (10);
	centerg ("The DFA is:",wherey());
	cprintf("\n\r");
	int bak;

	for(int i=1;i<=counter1;i++)
	{
		r=dfalist1.search(i);
		if (i%2)bak=2;else bak=1;
		tcolor (15,bak);
		space80();
//		cout<<"Transition For State "<<r.state1<<" , state name :";
		cprintf("Transition For State %03d named {",r.state1);
		textcolor(14);

		for (int o=0;o<20;o++)
		{
			if (r.states[o]==0)
				break;
			cprintf("%d",r.states[o]);
			if (r.states[o+1]!=0) cprintf (",");
		}
		textcolor(15);
		cprintf ("}:\n\r");
		checkscreen(&++screencontrol);
		tcolor (11,bak);
		r.dfalist2.catchdata(&screencontrol);
		delay(50);
//		getch();
	}
}
/***********************************************/
