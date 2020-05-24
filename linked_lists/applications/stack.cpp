#include<iostream>
using namespace std;
struct node
  {
    int data;
    node *link;
   };
struct head
  {
    int count;
    node *top;
  };
class ssll
{
  head *n;
   public:
	ssll()
	{
	  n=NULL;
	}
	void createssll()
	{
	  n=new head;
	  n->count=0;
	  n->top=NULL;
	}
	bool fullssll()
	{
	  node *temp=new node;
	  if(temp!=NULL)
	   {
		delete temp;
	  	return true;
	   }
	   else return false;
	}
	bool emptyssll()
	{
	  if(n->count==0)
	     return true;
	  else return false;
	}
	void push(int datain)
	{
	 
		node *newnode=new node;
		newnode->data=datain;
		newnode->link=n->top;
		n->top=newnode;
		++(n->count);
	   }
	bool pop()
	{
		if(!emptyssll())
		{
		  dataout=n->top->data;
		  node *temp=n->top;
		  n->top=n->top->link;
		  delete temp;
		  --(n->count);
		  cout<<"the popped element is"<<dataout;
		  return true;
		}
		else
		return false;
	}
	void display()
	{
	 node *temp=n->top;
	 while(temp!=NULL)
	 {
	  cout<<temp->data<<"->";
	  temp=temp->link;
	 }
	  cout<<endl;
	}
	void destroyssll()
	{
	  node *temp=n->top;
	  while(temp!=NULL)
	  {
  	    n->top=n->top->link;
	    delete temp;
	    temp=n->top;
	  }
	delete n;
	}
};		
int main()
{
	ssll s;
	s.createssll();
	int k=3,j=8,h=6;int d,c;
	s.push(k);
	s.push(j);
	s.push(h);
	s.display();
	s.pop(d);
	s.display();
	s.destroyssll();
	s.display();
 	return 0;
}
