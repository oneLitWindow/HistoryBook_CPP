char mybot[80];

struct  data
	{
		linklist2 list2;
		int state;
	};
/////////////////////////////////////////////////////
int* remove_tekrari(int s[])
{
	for (int i=0;i<20;i++)
	{
		for (int j=i+1;j<20;j++)
			if (s[i]==s[j])
				s[j]=0;
	}
	int k;
	for (i=0;i<20;i++)
		if (s[i]==0)
		{
			k=i;
			for (k=i+1;k<20;k++)
				if (s[k]!=0)
					s[i]=s[k];
		}
	return s;
}
/////////////////////////////////////////////////////
class NFA{
	private:
	      int* findlanda(int*,int);
		int start;
		int end;
		linklist1 <data> list1;
		char *lk;
		int belakharerahdare(int*,char,int,int);
	public:
		int  getend();
		int  getstart();//{ return (start);};
		int* find1(char, int);
		void build(char);
		void multiple();
		void add();
		void star();
		void chap();
	};
//////////////////////////////////////////////////////
stack <NFA> b;
int counter;
//////////////////////////////////////////////////////
int	NFA::getend()
{
	NFA a;
	a=b.pop();
	b.push(a);
	return(a.end);
}
//////////////////////////////////////////////////////
int	NFA::getstart()
{
	NFA a;
	a=b.pop();
	b.push(a);
	return(a.start);
}
//////////////////////////////////////////////////////
int statefound(int ebarat[],int d)
{
	for(int i=0;i<20;i++)
		if (ebarat[i]==d)
			return 1;
	return 0;
}
//////////////////////////////////////////////////////
int* putarr(int temp[],int temp1[])
{
	int k=0;
	for(int i=0;i<20;i++)
		if (temp[i]==0)
		{
			if (temp1[k]==0)break;
			temp[i]=temp1[k];
			k++;
		}
	return (temp);
}
//////////////////////////////////////////////////////
int* putint(int temp[],int temp1)
{
	for(int i=0;i<20;i++)
		if (temp[i]==0)
		{
			temp[i]=temp1;
			break;
		}
	return (temp);
}
//////////////////////////////////////////////////////
int* NFA::findlanda(int mymasir[],int beginstate)
{
	int ebarat[20]={0};
	int masir=0;
	int k=1;
	data r;
	NFA b1;
	b1=b.pop();
	b.push(b1);
	mychar w;
	int myk;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==beginstate)
		{
			for (myk=1;;myk++)
			{
			w=r.list2.get('~',myk);
			if (w.state<0) break;
			masir=w.state;
			if (statefound(mymasir,w.state)) continue;
			putint(mymasir,masir);
			putint(ebarat,w.state);
			putarr(ebarat,findlanda(mymasir,w.state));
			}
			break;
		}
		k++;
	if (k>b1.end) break;
	}
return (ebarat);
}
//////////////////////////////////////////////////////
int NFA::belakharerahdare(int mymasir[],char a, int startstate, int firststate)
{
	if (firststate==startstate) return 0;
	int masir=0;
	int t=0;
	NFA b1;
	mychar w;
	data r;
	int myk;
	b1=b.pop();
	b.push(b1);
	int k=1;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==startstate)
		{
			w=r.list2.get(a,1);
			if ((w.state)>-1){return ++t;}
			for (myk=1;;myk++)
			{
			w=r.list2.get('~',myk);
			if (w.state<0) break;
			if (statefound(mymasir,w.state)) continue;
			masir=w.state;
			mymasir=putint(mymasir,masir);
			t=t+belakharerahdare(mymasir,a,w.state,firststate);if (t>0) return t;
			}
			break;
		}
		k++;
	if (k>b1.end) break;
	}
	return t;
}
//////////////////////////////////////////////////////
int* NFA::find1(char a,int l)
{
	delay(10);
	mychar w;
	data r;
	NFA b1;
	int k=1;
	b1=b.pop();
	b.push(b1);
	int ebar[20]={0};
	int chandominlanda;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==l)
		{
			for (chandominlanda=1;;chandominlanda++)
			{
				w=r.list2.get('~',chandominlanda);
				if (w.state==-1) break;
				int d[20]={0};
				if (!belakharerahdare(d,a,w.state,l)) continue;
				if (statefound(ebar,w.state)) continue;
				putarr(ebar,find1(a,w.state));
			}
			w=r.list2.get(a,1);
			if (w.state==-1) break;
			putint(ebar,w.state);
			int j[20]={0};
			putarr(ebar,findlanda(j,w.state));
			break;
		}
		k++;
	}
	if (ebar[0]!=0)
		remove_tekrari(ebar);
	return (ebar);
}
//////////////////////////////////////////////////////
void NFA::build(char t)
{
	NFA a;
	data r,r1;
	counter+=2;
	r.state=counter-1;
	r.list2.insertdata(t,counter);
	a.list1.insertdata(r);
	r1.state=counter;
	a.list1.insertdata(r1);
	a.end=counter;
	a.start=counter-1;
	b.push(a);
}
//////////////////////////////////////////////////////
void NFA::add()
{
	int s;
	int k=1;
	data r,r1,r2;
	NFA b1,b2;
	b2=b.pop();
	b1=b.pop();
	counter+=2;
	k=1;
	while (1)
	{
		r=b2.list1.search(k);
		b1.list1.insertdata(r);
		if (r.state==b2.end)
			break;
		k++;
	}
	k=1;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==b2.end)
		{
			s=k;
			break;
		}
		k++;
	}
	r.state=b2.end;
	r.list2.insertdata('~',counter);
	b1.list1.replace(r,s);
	k=1;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==b1.end)
		{
			s=k;
			break;
		}
		k++;
	}
	r.list2.insertdata('~',counter);
	b1.list1.replace(r,s);
	r1.state=counter-1;
	r1.list2.insertdata('~',b2.start);
	r1.list2.insertdata('~',b1.start);
	b1.list1.insertdata(r1);
	r2.state=counter;
	b1.list1.insertdata(r2);
	b1.end=counter;
	b1.start=counter-1;
	b.push(b1);
}
//////////////////////////////////////////////////////
void NFA::star()
{
	data r;
	NFA b1;
	b1=b.pop();
	int k,s;
	k=1;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==b1.start)
		{
			s=k;
			break;
		}
		k++;
	}
	r.list2.insertdata('~',b1.end);
	b1.list1.replace(r,s);
	k=1;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==b1.end)
		{
			s=k;
			break;
		}
		k++;
	}
	r.list2.insertdata('~',b1.start);
	b1.list1.replace(r,s);
	b.push(b1);
}
//////////////////////////////////////////////////////
void NFA::chap()
{
	int screencontrol=1;
	data r;
	int bak;
	cprintf ("\r");
	tcolor (10);
	centerg ("The NFA is:",wherey());
	cprintf("\n\r");
	for(int i=1;i<=counter;i++)
	{
		r=list1.search(i);
		if (i%2)bak=2;else bak=1;
		tcolor (15,bak);
		space80();
		cprintf("Transition For State %03d:\n\r",r.state);
		checkscreen(&++screencontrol);
		tcolor (11,bak);
		r.list2.catchdata(&screencontrol);
		delay(50);
	}
textbackground (0);
}
//////////////////////////////////////////////////////
void NFA::multiple()
{
	NFA b1,b2;
	data r,r1;
	b2=b.pop();
	b1=b.pop();
	int k=1;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==b1.end)
			break;
		k++;
	}
	while (1)
	{
		r1=b2.list1.search(k);
		if (r1.state==b2.end)
			break;
		k++;
	}
	k=1;
	while (1)
	{
		r=b2.list1.search(k);
		b1.list1.insertdata(r);
		if (r.state==b2.end)
			break;
		k++;
	}
	k=1;
	int s;
	while (1)
	{
		r=b1.list1.search(k);
		if (r.state==b1.end)
		{
			s=k;
			break;
		}
		k++;

	}

	r.list2.insertdata('~',b2.start);
	b1.list1.replace(r,s);
	b1.end=b2.end;
	b.push(b1);
}
//////////////////////////////////////////////////////
NFA build_nfa1(char *f,char *alphabet,char *tb)
{
	tcolor (10);centerg ("Now Making NFA... Please wait...\n\r",wherey());
	strcpy(mybot,tb);
//	int mylength=strlen(alphabet);
//	char lastchar1=alphabet[mylength-1];
//	char lastchar2=alphabet[mylength-2];
//	char *alphabet2=alphabet;
	stack <char> c;
	int k=0;
	int t=0;
	NFA a;
	strcpy(alphabet,tb);
	for (int i=0;i<strlen(f);i++)
	{
//		if (f[i]=='f')
//			getch();
		if (f[i]=='.')
			c.push(f[i]);
		else if (f[i]=='*')
			a.star();
		else if (f[i]=='(')
		{
		     c.push(f[i]);
		     t++;
		}
		else if (strchr(alphabet,f[i]))
		{
                        strcpy(alphabet,mybot);
			a.build(f[i]);
//			alphabet3=alphabet2;
//			alphabet[mylength-2]=lastchar2;
//			alphabet[mylength-1]=lastchar1;
//			alphabet[mylength]='\0';
			strcpy(alphabet,mybot);
			k++;
		}
		else if (f[i]=='+')
		{
			if (k)
			{
//				NFA *a=new NFA;
				char h;
				while (c.empty())
				{
					h=c.pop();
					if (h=='+')
					{
						a.add();
						continue;
					}
					if (h=='.')
					{
						a.multiple();
						continue;
					}
					c.push(h);
					break;
				}
			}
			c.push(f[i]);
		}
		else if ((t>0) && (f[i]==')'))
		{
			char h;
			while (c.empty())
			{
				h=c.pop();
				if (h=='.')
					a.multiple();
				if (h=='+')
				{
					a.add();
				}
				if (h=='(')
				{
					break;
				}
			}
			if (f[i+1]=='*')
			{
				i++;
				a.star();
			}
		}
	}
	char h;
	while (c.empty())
	{
		h=c.pop();
		if (h=='.')
			a.multiple();
		if (h=='+')
		{
			a.add();
		}
	}
	a=b.pop();
//	clrscr();
//	a.chap();
	b.push(a);
//       cprintf ("\n\r");
       tcolor (2);centerg ("NFA Made...\n\r",wherey());
       return (a);
}
//////////////////////////////////////////////////////

