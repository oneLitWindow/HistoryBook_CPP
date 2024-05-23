#include <string.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
# if!defined(__LISTLINK_H)
#define __LISTLINK_H
//////////////////////////////////////////////////
template <class type>
class Node1{
	friend class ll<type>;
	private:
		Node1 *link;
		type data;
	};
//////////////////////////////////////////////////
template <class type>
class ll{
	private:
		Node1<type> *first;
		Node1<type> *last;
	public:
	      ll(){
			first=NULL;last=NULL;
			};
			~ll();
			void insertdata(type);
			void catchdata();
			type search(type);
			void deletenode(type);
	};
//////////////////////////////////////////////////
template <class type>
ll<type>::~ll(){
	Node1<type> *link1;
	Node1<type> *link2;
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
type  ll<type>::search(type r)
{
	Node1<type> *link1;
	link1=first;
	while (link1)
	{
		if (link1->data==r)
			return (link1->data);
		link1=link1->link;
	}
	return (NULL);
}
//////////////////////////////////////////////////
template <class type>
void  ll<type>::deletenode(type r)
{
	Node1<type> *link1;
	Node1<type> *link2;
	link1=first;
	link2=first;
	while (link1)
	{
		if (link1->data==r)
		{
			if (link1==first)
			{
				link2=link2->link;
				first=link2;
			}
			else
			{
				Node1<type> *link3;
				link3=link1->link;
				link2->link=link3;
			}
			delete(link1);
			break;
		}
		link2=link1;
		link1=link1->link;
	}
}
//////////////////////////////////////////////////
template <class type>
void  ll<type>::insertdata(type r)
{
	Node1<type> *link1;
	link1=new Node1<type>;
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
void  ll<type>::catchdata()
{
	Node1<type> *link1;
	link1=new Node1<type>;
	link1=first;
	while (link1)
	{
	cout<<"* *"<<link1->data;//.transition;
		link1=link1->link;
	 }
}
//////////////////////////////////////////////////
#endif