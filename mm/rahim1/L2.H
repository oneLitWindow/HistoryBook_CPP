# if!defined(__L2_H)
#define __L2_H
//---------------/////////////////////////////////
struct mychar
{
	char transition;
	int  state;
};
//---------------////////////////////////////////
class Node{
	friend class linklist2;
	private:
		Node *link;
		mychar data;
	};
//////////////////////////////////////////////////
class linklist2{
	private:
		Node *first;
		Node *last;
	public:
	      linklist2(){
			first=NULL;last=NULL;
			}
//			~linklist2();
			void insertdata(char, int);
			int catchdata();
			int search(char);
			mychar get(char,int);
			mychar deletenode(mychar);
	};
//////////////////////////////////////////////////
mychar linklist2::get(char a,int count)
{
	int cc=0;
	Node *link1;
	link1=first;
	mychar notfound;
	while (link1)
	{
		if (link1->data.transition==a){cc++;
			if (cc==count)return (link1->data);}
		link1=link1->link;
	}
	notfound.transition='!';
	notfound.state=-1;
	return (notfound);
}
//template <class mychar>
/*linklist2::~linklist2(){
	Node *link1;
	Node *link2;
	link1=first;
	while (link1->link)
	{
		link2=link1->link;
		delete(link1);
		link1=link2;
	}
} */
//////////////////////////////////////////////////
//template <class mychar>
int  linklist2::search(char r)
{
	Node *link1;
	link1=first;
	while (link1)
	{
		if (link1->data.transition==r)
			return (link1->data.state);
		link1=link1->link;
	}
	return (NULL);
}
//////////////////////////////////////////////////
//template <class mychar>
/*mychar  linklist2::deletenode(mychar r)
{
return r;
} */
//////////////////////////////////////////////////
//template <class mychar>
void  linklist2::insertdata(char r, int t)
{
	Node *link1;
	link1=new Node;
	link1->data.transition=r;
	link1->data.state=t;
	link1->link=NULL;
	if (first==NULL)
	{
		first=link1;
		last=first;
//	cout<<"  transition : "<<link1->data.transition<<"  state : "<<link1->data.state<<endl;
		return;
	}
	last->link=link1;

//	cout<<"  transition : "<<link1->data.transition<<"  state : "<<link1->data.state<<endl;
	last=link1;
//        catchdata();
}
//////////////////////////////////////////////////
//template <class mychar>

//* **************************************************************
int  linklist2::catchdata()
{
	Node *link1;
	link1=new Node;
	link1=first;
	if (!link1)    {cout<<"NULL"<<endl; return 0;}
	while (link1)
	{
	cout<<"  transition : "<<link1->data.transition<<"  state : "<<link1->data.state<<endl;
	link1=link1->link;
//		if (link1->link) link1=link1->link; else break;
	 }
//delete (link1);
return 1;
}
//************************************************************ */

#endif