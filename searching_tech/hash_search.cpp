#include<iostream>
using namespace std;
struct node
  {
    int data;
    node *link;
  };
class hashsearch
 {	public:
	node *a[10];
	hashsearch()
	 {
	  for(int i=0;i<10;i++)
	   a[i]=NULL;
	 }
	void inserttohash(int key)
	  {
	   node *newnode=new node;
	   newnode->data=key;
	   int pos=key%10;
	   newnode->link=a[pos];//++(a[pos]->data);
	   a[pos]=newnode;
	  }
	void deletefromhash(int key)
	  {
	   node *temp,*pre;
	   int pos=key%10;
	   temp=a[pos];
	   while(temp!=NULL&&temp->data!=key)
	    {
	      pre=temp;
	      temp=temp->link;
	    }
	  if(temp!=NULL)
	    {
	      pre->link=temp->link;
	      delete temp;
	       cout<<"element deleted";
	     }
	else cout<<"not found"<<endl;
	}
	void search(int key)
	  {
	   node *temp=a[key%10];
	   int count=1;
	   while(temp!=NULL&&temp->data!=key)
	    {
	      count++;
	      temp=temp->link;
	     }
	   if(temp!=NULL)
	     cout<<"elementin"<<key%10<<"found at"<<count<<"position"<<endl;
	   else
	     cout<<"not found"<<endl;
	}
	void display()
	{
	for(int i=9;i>=0;i--)
	  {
	    node *temp=a[i];
	    cout<<i<<"->";
	    while(temp!=NULL)
	      {
		cout<<temp->data<<"->";
		temp=temp->link;
	      }
		cout<<"NULL\n";
	  }
	}
};
int main()
{
	hashsearch c;
	int m,n,u;
	do
	{
	cout<<"1.inserttohash\n2.deletefromhash\n3.display\n4.search\n";
	cin>>m;
	if(m==1)
	{
	cout<<"enter the key\n";
	cin>>u;
	c.inserttohash(u);
	}
	else if(m==2)
	{
	cout<<"enter the key\n";
	cin>>u;
	c.deletefromhash(u);
	}
	else if(m==3)
	c.display();
	else if(m==4)
	{
	cout<<"enter the key\n";
	cin>>u;
	c.search(u);
	}
	cout<<"do u want to continue(1/0)\n";
	cin>>n;
	}
	while(n==1);
}
	
	
	
	
