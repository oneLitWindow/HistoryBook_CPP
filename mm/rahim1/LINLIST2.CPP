#include <string.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <process.h>
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
			first=new Node<type>;
			last=new Node<type>;
			first=NULL;last=NULL;
	      }
	      ~linklist();
	      void insertdata(type);
	      void catchdata();
	      type search(type);
	      type deletenode(type);
	};
//////////////////////////////////////////////////
template <class type>
linklist<type>::~linklist(){
				Node<type> *link1;
				link1=new Node<type>;
				Node<type> *link2;
				link2=new Node<type>;
				link1=first;
				while(link1->link)
				{
					link2=link1;
					if(!(link1->link))
					break;
					if (link1->link)
						link1=link1->link;
					delete(link2);
				 }
				 delete(link1);
	       }

//////////////////////////////////////////////////
template <class type>
type  linklist<type>::search(type r)
{
	Node<type> *link1;
	link1=new Node<type>;
	link1=first;
	char *u;
	while (link1)
	{
		*u=link1->data;
		if(strchr(u,r)==0)
			return(link1->data);
		if(!(link1->link))
			link1=link1->link;
		else
			break;
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
        cout<<"@"<<r;
	if (first==NULL){
		first=link1;
		first->data=r;
		first->link=NULL;
	return;
	}
	if(!last) {
	first->link=link1;
	last=link1;
	}
	last->link=link1;
	if(first)
	{
	  link1->data=r;
	  link1->link=NULL;
	  last=link1;
	}
}
//////////////////////////////////////////////////
template <class type>
void  linklist<type>::catchdata()
{
	Node<type> *link1;
	link1=new Node<type>;
	link1=first;
	while(link1)
	{
	cout<<"#"<<link1->data;
	if(!(link1->link))
		break;
	if (link1->link)
	link1=link1->link;
	 }
}
//////////////////////////////////////////////////
int main()
{
        clrscr();
	linklist<char*> a;
	char *h;
	h=new char;
	for(int i=0;i<4;i++)
	{
                cin>>h;
		a.insertdata(h);
	}
	a.catchdata();
	cout<<"enter experssion:";
	cin>>h;
	if (a.search(*h))
		cout<<"Yes!";
	getch();
	return 0;
}