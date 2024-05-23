/*int counter2=0;
struct indis{
	int a;
	int b;
};
/***********************************************/
/*struct red{
	int  a;
	int  b;
};*/
/***********************************************/
class     reduce:public dfa
{
	private:
		linklist1<data_dfa>  redlist1;
	public:
		void	show(linklist1<red>);
		void	indistingushable();
		linklist2<red>  distingushable();
};
/***********************************************/
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
		r=a1.dfalist1.search(k);
		if (searcharr(r.states,l))
			arr[f++]=r.state1;
	}
	k=0;
	cout<<"**********"<<endl;
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
	show(link3);
}
/***********************************************/
/***********************************************/
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
/***********************************************/
