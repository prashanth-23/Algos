#include<iostream>
using namespace std;
struct graphVertex;
struct graphArc
  {
	graphVertex *destination;
	graphArc *nextArc;
  };
struct graphVertex
  {
	char data;
	graphVertex *nextVertex;
	bool processed;
	bool instack;
	graphArc *firstArc;
  };
struct HEAD
  {
	graphVertex *first;
	int count;
  };
struct node
  {
	graphVertex *dataptr;
	node *link;
  };
struct stackhead
  {
	int scount;
	node *top;
  };
class stack
  {
	stackhead *sh;
	public:
	stack()
	{
		sh=new stackhead;
		sh->scount=0;
		sh->top=NULL;
	}
	void push(graphVertex *gv)
	{
		++(sh->scount);
		node *newnode=new node;
		newnode->dataptr=gv;
		newnode->link=sh->top;
		sh->top=newnode;
	}
	graphVertex* pop()
	{
		--(sh->scount);
		graphVertex *tmp=new graphVertex;
		tmp=sh->top->dataptr;
		sh->top=sh->top->link;
		return tmp;
	}
	bool emptystack()
	{
		if(sh->scount==0)
			return true;
		else
			return false;
	}
};
		
class Graph
  {
	public:
	HEAD *h;
	void createGraph()
	{
	h=new HEAD;
	h->first=NULL;
	h->count=0;
	}
	bool emptygraph()
	{
		if(h->count==0)
			return true;
		else
			return false;
	}
	void insertVertex(char datain)
	{	
	graphVertex *newvertex=new graphVertex;
	newvertex->data=datain;
	newvertex->processed=false;
	newvertex->instack=false;
	newvertex->nextVertex=NULL;
	newvertex->firstArc=NULL;
	++(h->count);
	if(h->first==NULL)
		h->first=newvertex;
	else
	 {
	   graphVertex *t=h->first;
	   while(t->nextVertex!=NULL)
	   t=t->nextVertex;
	   t->nextVertex=newvertex;
	 }
	}
	int insertArc(char fromkey,char tokey)
	{
		graphArc *newarc=new graphArc;
		graphVertex *fromvertex=new graphVertex;
		graphVertex *tovertex=new graphVertex;
		fromvertex=search(fromkey);
		if(fromvertex==NULL)
			return -2;
		tovertex=search(tokey);
		if(tovertex==NULL)
			return -3;
		newarc->destination=tovertex;
		newarc->nextArc=NULL;
		if(fromvertex->firstArc==NULL)
		{
		  fromvertex->firstArc=newarc;
		  return 1;
		}
		else
		{
		  graphArc *t=fromvertex->firstArc;
		  while(t->nextArc!=NULL)
	 	  	t=t->nextArc;
	 	  t->nextArc=newarc;
		  return 2;
		}
	}
	void display()
	{
	graphArc *y=new graphArc;
	graphVertex *f=h->first;
	while(f!=NULL)
	{
		cout<<f->data<<" ->";
		y=f->firstArc;
		while(y!=NULL)
		{
			cout<<y->destination->data<<"->";
			y=y->nextArc;
		}
		cout<<endl;
		f=f->nextVertex;
	}
	}
	graphVertex* search(char ch)
	{
		graphVertex *t=h->first;
		while(t!=NULL)
		  {	
			if(t->data==ch)
				break;
			t=t->nextVertex;
		  }
			return t;
	}
	int DFS()
	{
		if(emptygraph())
			return -1;
		graphVertex *temp = h->first;
		while(temp!=NULL)
			{
				temp->processed = false;	
				temp->instack = false;
				temp = temp->nextVertex;
			}
		stack st;
		temp = h->first;
		while(temp!=NULL)
		{
			if(!temp->processed)
			{
				if(!temp->instack)
				{
					st.push(temp);
					temp->instack = true;
				}
				while(!st.emptystack())	
				{
					graphVertex *temp2 = st.pop();
					temp2->processed = true;
					cout<<"\n"<<temp2->data<<" "<<temp2->processed;
					graphArc *temp3 = temp2->firstArc;
					while(temp3 != NULL)
					{
						bool b1=temp3->destination->processed;
						bool b2=temp3->destination->instack;
						if(!(b1||b2))
						{st.push(temp3->destination);
						temp3->destination->instack=true;
						}
						temp3=temp3->nextArc;
					}
				}
			}
		temp=temp->nextVertex;
		}
		return 0;
	}
		
};	
int main()
{
	Graph p;
	int n,m,l;
	p.createGraph();
	cout<<"enter no of vertices:\n";
	cin>>m;
	char key='A';
	for (int i=0;i<m;i++,key++)
	{
	p.insertVertex(key);
	}
	cout<<"enter no of edges:\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	char x,y;
	cout<<"enter"<<i+1<<"edge's from and to keys\n";
	cin>>x>>y;
	l=p.insertArc(x,y);
	cout<<i+1<<"'s result"<<l<<"   "<<endl;
	}
	p.display();
	p.DFS();
	cout<<endl;
}
	