#include <iostream.h>
#include <conio.h>
/////////////////////////////////////////////
template <class  mytype >
class stack{
	protected:
		int top;
		mytype bag[20];
	public:
		stack() {top=0;}
		void push(mytype);
		mytype pop();
	};
//////////////////////////////////////////////////////
template <class mytype>
void stack<mytype>::push(mytype r)
{
		{
			bag[top++]=r;
		}
}
//////////////////////////////////////////////////////
template <class mytype>
mytype stack<mytype>::pop()
		{
			mytype g=bag[--top];
			return g;
		}
//////////////////////////////////////////////////////

int main()
{
	clrscr();
	char j;
	stack<char> a;
	for (int i=0;i<10;i++)
	{
		cin>>j;
		a.push(j);
	}
	cout<<endl;
	for (i=0;i<10;i++)
		cout<<"__"<<a.pop();
	getch();
	return 0;
}