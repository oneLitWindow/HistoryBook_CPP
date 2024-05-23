//           8453308             //
// program of CPPArray, (2-2 #1) //
// Programmed BY Amin Safinejad, //
// 100% TESTED, Fully working.   //
// amin1986@gmail.com            //
//  			         //
#include <stdio.h>
#include <iostream.h>
#include <conio.h>
const int maxterms=50,defaultsize=maxterms;

template <class mytype>
class carray{   public:
		~carray();
		carray(int size=defaultsize, mytype initvalue=0);
		carray(const carray& cp2)
			{
			terms=cp2.getsize();
			for (int i=0;i<terms;i++) array[i]=cp2[i];
			return;
			}
		int getsize();
		carray & operator =(const carray& cp2)
			{
			terms=cp2.getsize();
			for (int i=0;i<terms;i++) array[i]=cp2[i];
			return *this;
			}
		mytype & operator [](int i)
			{
			if (i<0){cout<<"Invalid Index number, must be greater than 0!"<<endl;}
			else if (i>(maxterms-1)){cout<<"Index number exceeds MAXTERMS, must be less than "<<maxterms<<"!"<<endl;}
			else return *(array+i);
			}

	       private:
		mytype array[maxterms];
		int isfull();
		int isempty();
		int terms;
};
//////////////////////////////////////////////////////////////////////////////
template <class mytype>
carray<mytype>::carray(int size=defaultsize, mytype initvalue=0)
{
	terms=size;
	for (int i=0;i<size;i++) array[i]=initvalue;
	return;
}
//////////////////////////////////////////////////////////////////////////////
template <class mytype>
int carray<mytype>::getsize(){return terms;}
//////////////////////////////////////////////////////////////////////////////
template <class mytype>
carray<mytype>::~carray(){
delete [] array;
return;
}
//////////////////////////////////////////////////////////////////////////////
template <class mytype>
ostream& operator<<(ostream& os,carray<mytype>& c)
{
for (int i=0;i<c.getsize();i++){
os<<"("<<i<<","<<c[i]<<") ";}
return os;
}
//////////////////////////////////////////////////////////////////////////////
template <class mytype>
int operator==(carray<mytype>& c1,carray<mytype>& c2)
{
if (c1.getsize()!=c2.getsize()) return 0;
else for (int i=0;i<c1.getsize();i++)if (c1[i]!=c2[i]) return 0;
return 1;
}
//////////////////////////////////////////////////////////////////////////////
int main()
{
clrscr();
carray<int> a(10),b(20),c(10),*n;
a[1]=10;
a[5]=50;
b=a;
cout<< "A:\n" << a<<endl<<"B:\n"<<b<<endl;
cout<<"A and B are ";
if (b==a) cout<<"Equal!\n"; else cout<<"Inequal!\n";
cout<<"A and C are ";
if (c==a) cout<<"Equal!\n"; else cout<<"Inequal!\n";
getch();
return 0;
}
//////////////////////////////////////////////////////////////////////////////
