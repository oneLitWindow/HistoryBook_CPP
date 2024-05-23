#include <string.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
# if!defined(__LISTLINK_H)
#define __LISTLINK_H

		struct mychar{
		char transition[2];
		};
//////////////////////////////////////////////////
//template <class mychar>
class Node{
	friend class linklist2;
	private:
		Node *link;
		mychar data;
	};
//////////////////////////////////////////////////
//template <class mychar>
class linklist2{
	private:
		Node *first;
		Node *last;
	public:
	      linklist2(){
			first=NULL;last=NULL;
			}
			~linklist2();
			void insertdata(mychar);
			void catchdata();
			char search(char);
			mychar deletenode(mychar);
	};
//////////////////////////////////////////////////
//template <class mychar>
linklist2::~linklist2(){
	Node *link1;
	Node *link2;
	link1=first;
	while (link1->link)
	{
		link2=link1->link;
		delete(link1);
		link1=link2;
	}
}
//////////////////////////////////////////////////
//template <class mychar>
char  linklist2::search(char r)
{
	Node *link1;
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
//template <class mychar>
mychar  linklist2::deletenode(mychar r)
{
return r;
}
//////////////////////////////////////////////////
//template <class mychar>
void  linklist2::insertdata(mychar r)
{
	Node *link1;
	link1=new Node;
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
//template <class mychar>
void  linklist2::catchdata()
{
	Node *link1;
//	link1=new Node;
	link1=first;
	while (link1)
	{
	cout<<"* *"<<link1->data.transition;
		link1=link1->link;
	 }
}
//////////////////////////////////////////////////
#endif