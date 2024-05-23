# if!defined(__L1_H)
#define __L1_H
//////////////////////////////////////////////////
template <class type>
class Node1{
	friend class linklist1<type>;
	private:
		Node1 *link;
		type data;
	};
//////////////////////////////////////////////////
template <class type>
class linklist1{
	private:
		Node1<type> *first;
		Node1<type> *last;
	public:
	      linklist1(){
			first=NULL;last=NULL;
			};
//			~linklist1();
			void insertdata(type);
			void merge(linklist1,linklist1);
			void replace(type ,int);
			type search(int);
			void deletenode(int);
	};
//////////////////////////////////////////////////
/*template <class type>
linklist1<type>::~linklist1(){
	Node1<type> *link1;
	Node1<type> *link2;
	link1=first;
	while (link1->link)
	{
		link2=link1->link;
		delete(link1);
		link1=link2;
	}
}    */
//////////////////////////////////////////////////
//////////////////////////////////////////////////
template <class type>
type  linklist1<type>::search(int r)
{
	Node1<type> *link1;
	link1=first;
	int k=1;
	while (link1)//!=last)
	{
		if (k==r)
			{//cout<<"i found k!";
			return (link1->data);}
		link1=link1->link;
		k++;
	}
	return (first->data);
}
//////////////////////////////////////////////////
template <class type>
void  linklist1<type>::deletenode(int r)
{
	Node1<type> *link1;
	Node1<type> *link2;
	link1=first;
	int k=1;
	link2=first;
	while (link1)
	{
		if (k==r)
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
		k++;
		link1=link1->link;
	}
}
//////////////////////////////////////////////////
template <class type>
void  linklist1<type>::insertdata(type r)
{
	Node1<type> *link1;
	link1=new Node1<type>;
//	cout<<"D";
	if (first==NULL)
	{
		first=link1;
		first->data=r;
		first->link=NULL;
		last=first;
//		cout<<"I built the first link!"<<first<<"="<<last<<endl;
		return;
	}
	last->link=link1;
	link1->data=r;
	link1->link=NULL;
	last=link1;
}
//////////////////////////////////////////////////
/*template <class type>
void  linklist1<type>::replace2(type r, int t)
{
	Node1<type> *link1;
	link1=first;
	int k=1;
	while (link1)
	{
		if (k==t)
			delete(l;
		link1=link1->link;
	}


} */

//////////////////////////////////////////////////
template <class type>
void  linklist1<type>::replace(type r, int t)
{
	Node1<type> *link1;
	link1=first;
	int k=1;
//	cout<<"%%$";
	while (link1)
	{
		if (k==t)
			{link1->data=r;break;}
		link1=link1->link;
	k++;
	}
}
#endif