#include<iostream>
using namespace std;
struct node	
	{
	  int key;
	  node *left;
	  node *right;
	};
class BST
	{  public:
	int count;
	BST()
	{
	  count=0;
	}
	node *insert(node *&r,int key)
	
		node *newnode=new node;
		newnode->key=key;
		if(r==NULL)
		{
		  r=newnode;count++;
		  return r;
		}
		else
		  if(key<r->key)
			{
			return insert(r->left,key);
			}
		else
		  if(key>r->key)
			{
			return insert(r->right,key);
			}
		else return r;
	}
	bool empty(node *&r)
	{
	if(r==NULL)
		return true;
	else return false;
	}
	bool deletebst(node*&r,int key)	
	{
		if(r==NULL)
		return false;
		if(key>r->key)
			return deletebst(r->right,key);
		else if(key<r->key)
			return deletebst(r->left,key);
		else
			{
				if(r->left==NULL)
				{r=r->right;
				return true;
				}
				else 
				if(r->right==NULL)
				{r=r->left;
				return true;
				}
				else
					{
					node *node2=new node;
					node2=findlargest(r->left);
					r->key=node2->key;
					return deletebst(r->left,node2->key);
					}
				
			}
	}
					
	bool search(node *&r,int key)
	{
		if(r==NULL)
		   return false;
		if(key>r->key)
			return search(r->right,key);
		else if(key<r->key)
			return search(r->left,key);
		else return true;
	}
	void preorder(node *&r)
	{
		if(r!=NULL)
			{cout<<r->key<<" ";
		        preorder(r->left);
		        preorder(r->right);
			}
		 
	}
	void postorder(node *&r)
	{
		if(r!=NULL)
			{
			postorder(r->left);
		        postorder(r->right);
			cout<<r->key<<" ";   
			}
	}
	void inorder(node *&r)
	{
		if(r!=NULL)
			{inorder(r->left);
		        cout<<r->key<<" ";
			inorder(r->right);
			
			}
		  
	}
	node * findsmallest(node *&r)
	{
		if(r==NULL)
		return r;
		if(r->left==NULL)
		   return r;
		else
			return findsmallest(r->left);
	}
	node * findlargest(node *&r)
	{
		if(r==NULL)
		return r;
		if(r->right==NULL)
		   return r;
		else
			return findlargest(r->right);
	}
};
int main()
	{
	node *x=new node;
	x=NULL;
	node *node1=new node;
	BST a;
	int y,z;
	do
	{
	cout<<"press1.insert2.delete3,4,5->pre,in,postdisplay6.largest7.smallest8.search";
	cin>>z;
	if(z==1)
	{
		cout<<"enter the key";
		cin>>y;
		a.insert(x,y);
	}
	else if(z==2)
	{
		cout<<"enter the delete key";
		cin>>y;
		a.deletebst(x,y);
	}
	else if(z==3)
		a.preorder(x);
	else if(z==4)
		a.inorder(x);	
	else if(z==5)
		a.postorder(x);
	else if(z==6)
		{
		node1=a.findlargest(x);
		cout<<"the largest is"<<node1->key<<endl;
		}
	else if(z==7)
		{node1=a.findsmallest(x);
		cout<<"the largest is"<<node1->key<<endl;
		}
	else {
		cout<<"enter the key to search";
		cin>>y;
		if(a.search(x,y))
		  cout<<"the key is present ";
		else
		   cout<<"the key is not present";
		}
	cout<<"do you want to continue(1/0)";
	cin>>y;
	}
	while(y!=0);
	

}
		
	
		
	  
		
