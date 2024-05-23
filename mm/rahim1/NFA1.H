char mybot[80];

struct  data
	{
		linklist2 list2;
		int state;
	};
/////////////////////////////////////////////////////
void fixcommas(char *s){
char s1[80]="";
s1[0]=s[0];
//strcpy(s1,s);
int k=0;
for (int i=1;i<strlen(s);i++)
if (!((s[i]==',')&&(s[i-1]==','))) s1[++k]=s[i];

if (s1[strlen(s1)-1]==',') s1[strlen(s1)-1]=0;
//cout<<"S1"<<s1<<endl;getch();
strcpy (s,s1);
}
/////////////////////////////////////////////////////
int n_omin(char *s1,int w){
char s[80];
strcpy (s,s1);
fixcommas(s);
char joda[80]="";
int i=0;
int o=0;
int foundcomma=0;
for (int y=0;y<strlen(s);y++)if (s[y]==',') {foundcomma=y+1;break;}
if ((!foundcomma) && (w>1)) return -1;
if (w==1)return atoi(s);
for (i=foundcomma;i<=strlen(s);i++)joda[o++]=s[i];
return n_omin(joda,w-1);
}
/////////////////////////////////////////////////////
void remove_tekrari(char *s){
char s1[80]="";
char stemp[4]="";
int i[80]={0};
i[0]=-1;
int j;
int t;
int y=1;
int q=0;
int flag=0;
for (j=1;;j++)
{
	q=n_omin(s,j);
	flag=0;
	if (q==-1) break;
	for (t=0;t<j;t++)
		if (q==i[t])flag=1;
	if (!flag)i[y++]=q;
}
for (t=1;t<y;t++) {itoa(i[t],stemp,10);strcat(s1,stemp);strcat(s1,",");}
s1[strlen(s1)-1]='\0';
strcpy (s,s1);
}
/////////////////////////////////////////////////////
class NFA{
	private:
	      char* findlanda(char *,int);
	      int start;
	      int end;
	      linklist1 <data> list1;
	      char *lk;
	      int belakharerahdare(char*,char,int,int);
	public:
	      char *find(char, int);
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
char* NFA::findlanda(char *mymasir,int beginstate)
{
char masir[80]="";
char tmasir[80]="";
char ebarat[80]="";
for (int tempo=0;tempo<80;tempo++)ebarat[tempo]=0;
strcpy(ebarat,",");
	int k=1;
	data r;
	NFA b1;
	b1=b.pop();
	b.push(b1);
	mychar w;
	char temp[4];
	for (tempo=0;tempo<4;tempo++)temp[tempo]=0;
	strcpy(temp,"");
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
			itoa (w.state,tmasir,10);
			strcat (masir,",");
			strcat(masir,tmasir);
			if (strstr(mymasir,masir)) continue;
			strcat (mymasir,",");
			strcat (mymasir,masir);
			itoa(w.state,temp,10);
			strcat(ebarat,temp);strcpy(temp,"");
			strcat(ebarat,",");
			strcat(ebarat,findlanda(mymasir,w.state));
			}
			break;
		}
		k++;
	if (k>b1.end) break;
	}
if (ebarat[strlen(ebarat)-1]!=',') strcat(ebarat,",");
return (ebarat);
}
//////////////////////////////////////////////////////
int NFA::belakharerahdare(char *mymasir,char a, int startstate, int firststate){
	if (firststate==startstate) return 0;
	char masir[80]="";
	char tmasir[80]="";
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
			itoa(w.state,tmasir,10);
			strcat(masir,",");
			strcat (masir,tmasir);
			if (strstr(mymasir,masir)) continue;
			strcat(mymasir,",");
			strcat(mymasir,masir);
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
char* NFA::find(char a, int l)
{
 	char ebar[80]="";
	for (int tempo=0;tempo<80;tempo++)ebar[tempo]=0;
	strcpy(ebar,"");
	mychar w;
	data r;
	NFA b1;
	int k=1;
	b1=b.pop();
	b.push(b1);
	char anothertemp[10];
	char t[80]="";
	int chandominlanda;
	while (1)
	{
		r=b1.list1.search(k);
//		cout<<""<<r.state<<"";
		if (r.state==l)
		{
			for (chandominlanda=1;;chandominlanda++)
			{
				w=r.list2.get('~',chandominlanda);
				if (w.state==-1) break;
				if (!belakharerahdare(",\0",a,w.state,l)) continue;
				itoa(w.state,anothertemp,10);
				if (strstr(ebar,anothertemp)) continue;
				char iop[80]="";
				strcpy(iop,find (a,w.state));
				strcat(iop,",");
				strcat(ebar,iop);
				getch();
			}
			w=r.list2.get(a,1);
			if (w.state==-1) break;
			char myc[5]="";
			itoa(w.state,myc,10);
			strcat(t,myc);
			strcat(t,",");
			strcat (t,findlanda(",\0",w.state));
			strcat(ebar,t);
			break;
		}
		k++;
	}
//cout<<endl<<"the T is: "<<t<<endl;getch();
if (strlen(ebar)>0)
	remove_tekrari(ebar);
return (ebar);
}
//////////////////////////////////////////////////////
void NFA::build(char t)
{
	NFA a;//=new NFA;
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
void build_nfa1(char *f,char *alphabet,char *tb)
{
	strcpy(mybot,tb);
//	int mylength=strlen(alphabet);
//	char lastchar1=alphabet[mylength-1];
//	char lastchar2=alphabet[mylength-2];
//	char *alphabet2=alphabet;
	stack <char> c;
	int k=0;
	int t=0;
	NFA a;
	for (int i=0;i<strlen(f);i++)
	{
		if (f[i]=='f')
			getch();
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
//	a.chap();
	b.push(a);
}
//////////////////////////////////////////////////////
