#include<iostream>
using namespace std;
struct node
 {
   int data;
   node *link;
  };
struct list
  {
   int count;
   node *front;
   node *rear;
  };
class qsll
{
     list *h;
  public:
	qsll()
	{
	h=NULL;
	}
	void createqsll()
	{
	  h=new list;
	  h->count=0;
	  h->rear=NULL;
	  h->front=NULL;
	}
	bool emptyqsll()
	{
	if(h->rear==NULL)
	return true;
	else return false;
	}
	bool qsllfull()
	{
	  node *temp=new node;
	  if(temp!=NULL)
	   {
		delete temp;
	  	return true;
	   }
	   else return false;
	}
	bool enqueue(int datain)
	{ 
	  node *newnode=new node;
	  newnode->data=datain;
	  newnode->link=NULL;
	  if(emptyqsll())
	  {
	    h->rear=newnode;
	    h->front=newnode;
	  }
	  else
	   {
	     h->rear->link=newnode;	
	     h->rear=newnode;	
	    }
	   return true;
 	}
	bool dequeue(int &dataout)
	{
	  if(emptyqsll())
	  return false;
	  else
		dataout=h->front->data;
	        if(h->count==1)
		{	
		 h->front=NULL;
	  	 h->rear=NULL;
		}
		else
		{
		h->front=h->front->link;
		}
		--(h->count);
	}
	void display()
	{
	 node *temp=h->front;
	 while(temp!=NULL)
	 {
	  cout<<temp->data<<"->";
	  temp=temp->link;
	  }
	cout<<endl;//<<"hi"<<endl;
	}
};
int main()
{
  qsll f;
  f.createqsll();
  int u=7,v=5,t=3,m,o;
  m=f.enqueue(u);cout<<m<<endl;
  o=f.enqueue(v);cout<<o<<endl;
  f.enqueue(t);f.dequeue(o);f.enqueue(o);
  f.display();
  return 0;
}
				
	  	  
 
