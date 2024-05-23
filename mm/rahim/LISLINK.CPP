#include <string.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
/*struct mychar{
		char transition[2];
		};*/
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
			type search(type);
			void deletenode(type);
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
type  linklist<type>::search(type r)
{
	Node<type> *link1;
	link1=first;
	while (link1)
	{
		if (link1->data==r)
			return (link1->data);
//		if (link1->data.transition[0]==r)
//			return (link1->data.transition[1]);
		link1=link1->link;
	}
	return (NULL);
}
//////////////////////////////////////////////////
template <class type>
void  linklist<type>::deletenode(type r)
{
	Node<type> *link1;
	Node<type> *link2;
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
				Node<type> *link3;
				link3=link1->link;
				link2->link=link3;
			}
			delete(link1);
			break;
		}
		link2=link1;
		link1=link1->link;
	}

//	return r;
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
	link1=new Node<type>;
	link1=first;
	while (link1)
	{
	cout<<"* *"<<link1->data;//.transition;
		link1=link1->link;
	 }
}
//////////////////////////////////////////////////
int main()
{
	clrscr();
	mychar chare;
	linklist<int> a;
	for (int i=1;i<9;i++)
	{
//		gets(chare.transition);
		a.insertdata(i);
	}
	a.catchdata();
	cout<<endl;
	char ch;
	int d;
	cin>>d;
        a.deletenode(d);
	a.catchdata();
	cout<<endl;
	cout<<"^^"<<a.search(10);
	getch();
	return 0;
}