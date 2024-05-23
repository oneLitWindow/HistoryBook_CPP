
template <class  mytype >
class stack{
	protected:
		int top;
		mytype bag[1000];
	public:
		int empty();
		stack() {top=0;}
		void push(mytype);
		mytype pop();
	};
//////////////////////////////////////////////////////
template <class mytype>
void stack<mytype>::push(mytype r)
{
	bag[++top]=r;
}
//////////////////////////////////////////////////////
template <class mytype>
int stack<mytype>::empty()
{
	if (top==0)
		return 0;
	return 1;
}
//////////////////////////////////////////////////////
template <class mytype>
mytype stack<mytype>::pop()
{
	mytype g=bag[top--];
	return g;
}
//////////////////////////////////////////////////////
