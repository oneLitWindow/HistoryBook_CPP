///////////////////////////////////////////////////
int stlen(char *s)
{
	for (int i=0;;i++)
	if ((s[i]==0)||(s[i]=='\0'))
	return i;

}
///////////////////////////////////////////////////
const char* available_alphabets="ZXCVBNMASDFGHJKLPOIUYTREWQabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&`-_=|\\/<>?,:;\"'\0";
///////////////////////////////////////////////////
char *biparantesof(char *s)
{
	char *temp;
	temp=new char(strlen(s));
	int j=0;
	for (int i=0;i<=strlen(s);i++)
	{if ((s[i]!='(') && (s[i]!=')')) {temp[j++]=s[i];}}
	return temp;
}
///////////////////////////////////////////////////
class regular_expression
	{
	    public:
	    char    *expression;
	    char    *alphabet;
	    public:
		 char* get_alphabet();
		 int valid_expression2(char*);
		 char *get_expression();
		 regular_expression(){alphabet=new char[80];
		 strcpy(alphabet,"\0");}
	};
///////////////////////////////////////////////////
char* manage(char *s)
{
	int i,j,found=0,k=0;
	char *f;
	f=new char(80);
	for (i=0;i<80;i++)
		f[i]='\0';
	for (i=0;i<stlen(s);i++) {
		found=0;
		for (j=0;j<stlen(f);j++) {
			if (s[i]==f[j])
				{found=1;break;}
		}
	if (!(found)&&(strchr(available_alphabets,s[i]))) f[k++]=s[i];
	}
f[k]='\0';
return f;
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
char* regular_expression::get_alphabet()
{

//	cout<<"Please Enter Alphabet."<<endl;
//	gets(alphabet);
//	strcpy(alphabet,"abcdefghijklmnopq\0");
	strcpy (alphabet,"\0");
	char temp[2]="";
	for (int i=0;i<=strlen(expression);i++){
	temp[0]=expression[i];
	temp[1]='\0';
	if (strchr(available_alphabets,expression[i])) strcat (alphabet,temp);
	}
	alphabet=manage(alphabet);
	strcat(alphabet,"~");
	//cout<<"Length of alphabet: "<<strlen(alphabet)<<endl;
	//cout<<"Your alphabet will be: '"<<alphabet<<"'"<<endl;
	gprintf ("Your alphabet will be: ³");
	gprintf(alphabet);
	cprintf("³\n\r");
	return(alphabet);
}
///////////////////////////////////////////////////
int regular_expression::valid_expression2(char *d)
{
	int h=1;
	int k=0;
	char *f=d;
	if ((f[0]=='+')||(f[0]=='.'))
	{
		h=0;
		cout<<"The unmatch or error ecour in the first. Irregular!"<<endl;
		return h;
	}

	if ((f[strlen(f)-1]=='+')||(f[strlen(f)-1]=='.'))
	{
		h=0;
		cout<<"The unmatch or error ecour in end.  Irregular!"<<endl;
		return h;
	}
	for (int i=0;i<strlen(f);i++)
	{
		if ((k<0) ) {
			h=0;
			cout<<"The unmatch or error ecour in "<<i<<". Irregular!"<<endl;
			return h;
			}
		if (f[i]==')')
		{
		     k--;
		}
		if (f[i]=='(')
		{
		     (k)++;
		}
		if ((f[i]=='(') && ((f[i+1]=='*') ||(f[i+1]=='+')||(f[i+1]=='.')))
		{
			h=0;
			cout<<"The unmatch or error ecour in "<<i+1<<". Irregular!"<<endl;
			return h;
		}
		if (((f[i]=='.')||(f[i]=='+')) && ((f[i+1]==')') ||(f[i+1]=='+') ||(f[i+1]=='*')||(f[i+1]=='.')))
		{
			h=0;
			cout<<"The unmatch or error ecour in "<<i+1<<". Irregular!"<<endl;
			return h;
		}
		if (strstr(f,".+")||strstr(f,"+.")) {
			h=0;
			cout<<"The unmatch or error ecour in "<<i+1<<". Irregular!"<<endl;
			return h;
		}
		if (!(strchr(alphabet,f[i])) && (f[i]!=alphabet[0]) && (f[i]!='(') && (f[i]!=')') && (f[i]!='~'))
		{
			if ((f[i]=='.')||(f[i]=='*')||(f[i]=='+'))
				continue;
			cout<<"The unmatch or error ecour in "<<i<<". Irregular!"<<endl;
			h=0;
			return h;
		}
	}
	if (k>0)
		h=0;
    return h;
}
///////////////////////////////////////////////////
char *regular_expression::get_expression()
{
	gprintf("Enter Your Expression:");
	cprintf ("\n\r");
	char *g;
	g=new char(250);
	gets(g);
	strcpy(expression,g);
	return g;
}
///////////////////////////////////////////////////
