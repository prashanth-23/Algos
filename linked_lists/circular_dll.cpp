#include<iostream>
using namespace std;
struct node
  {
	int data;
	node *forward;
	node *backward;
  };
struct list
  {
	int count;
	node *rear;
	node *head;
  };
class cdll
  {
	list *h;
  public:
	cdll()
	{
	   h=NULL;
	}
	void create()
	{
	h=new list;
	h->count=0;
	h->rear=NULL;
	h->head=NULL;
	}
bool search(node *&ppre,node *&ploc,int target)
		{
			ppre=NULL;
			ploc=h->head;
			if(h->count==0)
			return false;
			if(ploc->data==target)
			return true;
			if(target<ploc->data)
			return false;
			ppre=ploc;
			ploc=ploc->forward;
			while(ploc!=h->head&&target>ploc->data)
			{
				ppre=ploc;
				ploc=ploc->forward;
			}
			if(ploc==h->head)
			  return false;
			else
			  if(target==ploc->data)
			  return true;
	  		  else return false;
		}
bool emptycdll()
	{	
	if(h->count==0)
	return true;	
	else return false;
	}
bool fullcdll()
	{
	node *temp=new node;
	if(temp!=NULL)
	  {
	   delete temp;
	   return false;
	  }
	else 
	   return true;	
	}
int insertcdll(int key)
	{
	
	node *ppre;
	node *suc;
	bool found=search(ppre,suc,key);
	if(!found)
	  {cout<<"jio";
		node *newnode=new node;
		newnode->data=key;
		(h->count)++;
		if(ppre==NULL)
		{
		  if(h->count==1)
			{
			h->head=newnode;
			h->rear=newnode;
			}
		  else
			{
			h->head->backward=newnode;
			h->rear->forward=newnode;
			}
		newnode->backward=h->rear;
		newnode->forward=h->head;
		h->head=newnode;
		}
		else
		{
		newnode->forward=suc;
		newnode->backward=ppre;
		ppre->forward=newnode;
		if(suc==h->head)
			h->rear=newnode;
		suc->backward=newnode;
		}
	  return 1;
	  }
	  else return 0;
	}
	 bool deletecdll(int key)
	 {
		 node *ppre=NULL;
		 node *pdel=NULL;
		 bool found=search(ppre,pdel,key);
		 if(found)
		 {
			 if(h->count==1)
			 {
				 h->head=NULL;
				 h->rear=NULL;
			 }
			 else
			 {
				 if(ppre!=NULL)
				 {
					 ppre->forward=pdel->forward;
					 pdel->forward->backward=ppre;
					 if(pdel==h->rear)
						 h->rear=ppre;
				 }
				 else
				 {
					 h->head=pdel->forward;
					 pdel->forward->backward=pdel->backward;
					 h->rear->forward=pdel->forward;
				 }
			 }
			 delete pdel;
			 --(h->count);
			 return true;
		 }
		 else
		 return false;
	 }
	 void display()
	 {
		 node *pwalker=h->head;
		 if(pwalker!=NULL)
		 {
			 cout<<pwalker->data<<"->";
			 pwalker=pwalker->forward;
		 }
		  while(pwalker!=h->head)
		{
			 cout<<pwalker->data<<"->";
			 pwalker=pwalker->forward;
		 }
	 }
	 
				 
};
int main()
{
        cdll s;
	s.create();
	node *ppre,*ploc;
	int m,n,o,f,p;
	do
	 {
	  cout<<"enter1.insert\n2.delete\n3.display\n4.retrieve\n";
	  cin>>m;
	  if(m==1)
	   {
	    cout<<"enter value";
	    cin>>n;
	   p=s.insertcdll(n);cout<<p;
	   }
	  else if(m==2)
	   {
	    cout<<"enter value to be deleted";
	    cin>>n;	
	    s.deletecdll(n);cout<<"okay2";
	   }
	  else if(m==3)
		s.display();
	  else break;

	     cout<<"do you want to continue(1/0)\n";
	     cin>>o;
	}
	while(o==1);
	return 0;
}


