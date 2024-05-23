#include <string.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
struct mychar{
		char transition[2];
		};
//////////////////////////////////////////////////
template <class type>
class Node{
	friend class linklist<type>;
	private:
		Node *link;
		type data;
	};
//////////////////////////////////////////////////
template <class type>
class linklist{
	private:
		Node<type> *first;
		Node<type> *last;
	public:
	      linklist(){
			first=NULL;last=NULL;
			}
			~linklist();
			void insertdata(type);
			void catchdata();
			char search(char);
			type deletenode(type);
	};
//////////////////////////////////////////////////
template <class type>
linklist<type>::~linklist(){
	Node<type> *link1;
	Node<type> *link2;
	link1=first;
	while (link1->link)
	{
		link2=link1->link;
		delete(link1);
		link1=link2;
	}
}
//////////////////////////////////////////////////
template <class type>
char  linklist<type>::search(char r)
{
	Node<type> *link1;
	link1=first;
	while (link1)
	{
		if (link1->data.transition[0]==r)
			return (link1->data.transition[1]);
		link1=link1->link;
	}
	return (NULL);
}
//////////////////////////////////////////////////
template <class type>
type  linklist<type>::deletenode(type r)
{
return r;
}
//////////////////////////////////////////////////
template <class type>
void  linklist<type>::insertdata(type r)
{
	Node<type> *link1;
	link1=new Node<type>;
	if (first==NULL)
	{
		first=link1;
		first->data=r;
		first->link=NULL;
		last=first;
		return;
	}
	last->link=link1;
	link1->data=r;
	link1->link=NULL;
	last=link1;
}
//////////////////////////////////////////////////
template <class type>
void  linklist<type>::catchdata()
{
	Node<type> *link1;
//	link1=new Node<type>;
	link1=first;
	while (link1)
	{
	cout<<"* *"<<link1->data.transition;
		link1=link1->link;
	 }
}
//////////////////////////////////////////////////
int main()
{
	clrscr();
	mychar chare;
	linklist<mychar> a;
	for (int i=0;i<4;i++)
	{
		gets(chare.transition);
		a.insertdata(chare);
	}
	a.catchdata();
	cout<<endl;
	char ch;
	cout<<"^^"<<a.search(getche());
	getch();
	return 0;
}