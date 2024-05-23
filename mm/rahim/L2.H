//# if!defined(__L2_H)
//#define __L2_H

void checkscreen(int *screencontrol=0){


		if (*screencontrol>=23) {
		//tcolor (14,4);
		space80();
		gprintf ("Press any key to show continue...");
		getch();
		//tcolor (15,0);
		space80();//cprintf ("\n\r");
		*screencontrol=1;
//		clrscr();
		}
}

/***************************************************************/
struct mychar
{
	char transition;
	int  state;
};
/***************************************************************/
class Node{
	friend class linklist2;
	private:
		Node *link;
		mychar data;
	};
/***************************************************************/
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
			int catchdata(int*);
			int search(char);
			mychar get(char,int);
			mychar deletenode(mychar);
	};
/***************************************************************/
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
/***************************************************************/
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
//template <class mychar>
/***************************************************************/
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
/***************************************************************/
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
		return;
	}
	last->link=link1;
	last=link1;
}
/***************************************************************/
int  linklist2::catchdata(int *screencontrol=0)
{
	Node *link1;
	link1=new Node;
	link1=first;
	if (!link1)    {gotoxy (1,wherey());space80();gotoxy (27,wherey());cprintf("NULL\n\r");checkscreen(&++*screencontrol); return 0;}


	while (link1)
	{
//	cout<<"  transition : "<<link1->data.transition<<"  state : "<<link1->data.state<<endl;

	gotoxy (1,wherey());
	space80();
	gotoxy (27,wherey());
	cprintf ("Transition: %c to State: %03d\n\r",link1->data.transition,link1->data.state);
	checkscreen(&++*screencontrol);
	link1=link1->link;
	 }
return 1;
}
//************************************************************ */

//#endif