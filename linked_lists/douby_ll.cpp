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
class dll
  {
	list *h;
  public:
	dll()
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
			while(ploc!=NULL&&target>ploc->data)
			{
				ppre=ploc;
				ploc=ploc->forward;
			}
			if(ploc==NULL)
			  return false;
			else
			  if(target==ploc->data)
			  return true;
	  		  else return false;
		}
	bool emptydll()
	 {
	   if(h->count==0)
              return true;
	   else
	      return false;
	}
	bool fulldll()
	{
	node *temp=new node;
	if(temp!=NULL)
	{
	delete temp;
	return false;
	}
	else return true;	
	}
	int insertdll(int datain)
	 {
	  node *ppre;
	  node *psuc;
	  bool found=search(ppre,psuc,datain);
	  cout<<found;
	  if(!found)
	    {
				node *newnode=new node;
				newnode->data=datain;
				if(emptydll())
				{
					newnode->forward=NULL;
					newnode->backward=NULL;
				}
				else
				{
					newnode->forward=psuc;
					newnode->backward=ppre;
				}
				++(h->count);
				if(ppre==NULL)
					h->head=newnode;
				else 
					ppre->forward=newnode;
				if(psuc==NULL)
					h->rear=newnode;
				else
					psuc->backward=newnode;
				return 1;
	     }
	   else 
	        return 2;
	}
	int deletedll(int dataout)
	 {
	  if(emptydll())
	    return 0;
	  node *ppre,*pdel;
	  bool found=search(ppre,pdel,dataout);
	  if(found)
	   {
	    if(pdel->backward!=NULL)
	     {
	       ppre->forward=pdel->forward;
	      }
	    else
	      h->head=pdel->forward;
	    if(pdel->forward!=NULL)
	     {
	       pdel->forward->backward=pdel->backward;
	      }
	    else
	      h->rear=pdel->backward;
	   delete pdel;
	   --(h->count);
	   return 1;
	   }
	return 2;
	}
	void display()
	{
	  if(emptydll())
		cout<<"there are no elements";
	else
	{
	  node *temp=new node;
	  temp=h->head;
	  while(temp!=NULL)
	   {
	     cout<<temp->data<<"->";
	     temp=temp->forward;
	    }
	}
	}
};
int main()
{
        dll s;
	s.create();
	node *ppre,*ploc;
	int m,n,o,f,p;
	do
	 {
	  cout<<"enter1.insert\n2.delete\n3.display\n4.retrieve\n";
	  cin>>m;
	  switch(m){
	  case 1:
			{
				cout<<"enter value";
				cin>>n;
				p=s.insertdll(n);
				break;
			}
	  case 2:
				{
					cout<<"enter value to be deleted";
					cin>>n;	
					s.deletedll(n);
					break;
				}
	  case 3:
	  {
		  s.display();
		  break;
	  }
	  default: break;
	  }
	     cout<<"do you want to continue(1/0)\n";
	     cin>>o;
	}
	while(o==1);
	return 0;
}
