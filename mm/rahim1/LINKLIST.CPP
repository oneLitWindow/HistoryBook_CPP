#include <string.h>
#include <ctype.h>
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <process.h>
//////////////////////////////////////////////////
template <class type>
class Node{
	public:
		Node *first;
		Node *link;
		type *data;
	public :
		Node(){ link=NULL;first=link;}
		~Node(){ delete(data);}
		void push(type);
		type pop();
	};
//////////////////////////////////////////////////
template <class type>
void Node<type>::push(type f)
{
	cout<<"salam  "<<f<<"   ";
    *data=f;
    cout<<" (* "<<*data<<" *) ";
    if (f==4)
    	link=first;

}
//////////////////////////////////////////////////
template <class type>
type Node<type>::pop()
{
	cout<<"salam3   "<<*(link->data)<<"   ";
	return (*data);
}
//////////////////////////////////////////////////
template <class type>
class linklist{
	protected:
		Node<type> *link1;
	public:
	      linklist(){
	    //  first=*(link1->link);
	      }
	      ~linklist(){};
	      void insertdata(type);
	      type catchdata();
	      type deletenode();
	};
//////////////////////////////////////////////////
template <class type>
void  linklist<type>::insertdata(type r)
{
	cout<<"salam1   "<<endl;
	Node<type> *link1=new Node<type>[1];
	link1->push(r);
	link1->link=link1;
//	if (r==4)
  //		*link1=*first;
}
//////////////////////////////////////////////////
template <class type>
type  linklist<type>::catchdata()
{
      //	*link1=*first;
	cout<<"salam2  "<<*(link1->data)<<endl;
	type r;
	for(int i=0; i<=4;i++)
	{
	r=link1->pop();
	Node<type> *link1=new Node<type>[1];
	link1=link1->link;
	 }
	return (r);
}
//////////////////////////////////////////////////

//////////////////////////////////////////////////
int main()
{
	clrscr();
	linklist<int> a;
	int h;
	for(int i=0;i<=4;i++)
		a.insertdata(i);
      //	 cout<<" ^"<<(a.catchdata())<<"^"<<endl;
      //  cout<<"  @ "    ;
	h=a.catchdata();
	if(h % 2 ==0)
	 cout<<"___"<< h;
	getch();
	return 0;
}