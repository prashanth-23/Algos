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
    node *head;
   };
class sll
{
	list *headnode;
   public:
	sll()
	{
	headnode=NULL;
	}
	void createsll()
	{ 
	  headnode=new list;
	  headnode->count=0;
	  headnode->head=NULL;	
	}
	bool emptysll()
	{
	  if(headnode->count==0)
	   return true;
	  else return false;
	}
	bool fullsll()
	{
	  node *temp=new node;
	  if(temp!=NULL)
	  {
	   delete temp;
	   return false;
	  }
	  else return true;
	}
	bool searchlist(node *&ppre,node *&ploc,int tar)
	{
	 bool found;
	 ppre=NULL;
	 ploc=headnode->head;
	 while(ploc!=NULL&&tar>ploc->data)
	 {
	  ppre=ploc;
	  ploc=ploc->link;
	 }
	 if(ploc==NULL)
	   found=false;
	 else
	   if(ploc->data!=tar)
	     found=false;
	   else 
	     found=true;
	 return found;
	}
	int insertsll(int datain)
	{
	 node *pnex=NULL;
	 node *ppre=NULL;
	
	 bool found=searchlist(ppre,pnex,datain);
	 if(!found)
	  {
  	    ++(headnode->count);
	    node *newnode=new node;
	    newnode->data=datain;
		if(ppre==NULL)
		{
		  newnode->link=headnode->head;
		  headnode->head=newnode;	
		}
		else
		{
		 newnode->link=ppre->link;
		 ppre->link=newnode;
		}
	    return 1;
	   }
	  else
		return 2;
	}  
	bool deletesll(int dataout)
	{
	  node *ppre=NULL;
	  node *deletenode=NULL;
	  bool found=searchlist(ppre,deletenode,dataout);
	  if(!found)
	   return false;
	  else
	  {
	    if(ppre==NULL)
	      headnode->head=deletenode->link;
	     else
	      ppre->link=deletenode->link;
		delete deletenode;
		--(headnode->count);
	  }
 	  return true;
	}
   bool retrieve(int pos,int &dataout)
	{
	 bool found;
	  node *temp=headnode->head;
	  int cnt=1;
	   while(temp!=NULL&&cnt!=pos)
	   {
	    temp=temp->link;
	     cnt++;
	    }
		if(temp==NULL)
		found=false;
		else
		{
		 dataout=temp->data;
		 found=true;
		}
		if(found)
		cout<<"the element is"<<dataout;
		else
		cout<<"not a valid one";
	return found;
	}
	void display()
	{
	  node *temp=headnode->head;
	  while(temp!=NULL)
	  {
	   cout<<temp->data<<"->"<<endl;
	   temp=temp->link;
	  }
	}
};
int main()
{
	sll s;
	s.createsll();
	int m,n,o,f;
	do
	 {
	  cout<<"enter1.insert\n2.delete\n3.display\n4.retrieve\n";
	  cin>>m;
	  if(m==1)
	   {
	    cout<<"enter value";
	    cin>>n;
	    s.insertsll(n);
	   }
	  else if(m==2)
	   {
	    cout<<"enter value to be deleted";
	    cin>>n;	
	    s.deletesll(n);
	   }
	  else if(m==3)
	   {
	    s.display();
	    }
	   else 
	    {
	     cout<<"enter the position";
	     cin>>n;
	     s.retrieve(n,f);
	   }
	     cout<<"do you want to continue(1/0)\n";
	     cin>>o;
	}
	while(o==1);
	return 0;
}











































	  
