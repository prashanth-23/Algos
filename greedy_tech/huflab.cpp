#include<iostream>
#include<cmath>
using namespace std;
int c=0;
struct node
{
	int freq;
	char data;
	node *left;
	node *right;
};
struct minheap
{
	int size;
	int capacity;
	node **nodes;
};
node *create_node(char d,int f)
{
	node *newnode=new node;
	newnode->data=d;
	newnode->freq=f;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}
minheap* create_minheap(int cap)
{
	minheap* newminheap=new minheap;
	newminheap->size=0;
	newminheap->nodes=new node*[cap];
	return newminheap;
}
void swapnodes(node** a,node** b)
{
	node* t=*a;
	*a=*b;
	*b=t;
	
}
void minheapify(minheap* mh,int p)
{
	int left=2*p+1;
	int right=2*p+2;
	int smallest=p;
	if(left<mh->size&&mh->nodes[left]->freq<mh->nodes[p]->freq)
		smallest=left;
	if(right<mh->size&&mh->nodes[right]->freq<mh->nodes[smallest]->freq)
		smallest=right;
	if(smallest!=p)
	{
		swapnodes(&mh->nodes[p],&mh->nodes[smallest]);
		minheapify(mh,smallest);
	}
}
node* extract_min(minheap* mh)
{
	node* newnode=mh->nodes[0];
	mh->nodes[0]=mh->nodes[mh->size-1];
	mh->size=mh->size-1;
	minheapify(mh,0);	
	return newnode;
}
void insert_minheap(minheap* mh,node* newnode)
{
	mh->size++;
	int i=mh->size-1;
	while(i&&mh->nodes[(i-1)/2]->freq>newnode->freq)
	{
			mh->nodes[i]=mh->nodes[(i-1)/2];
			i=(i-1)/2;
	}
	mh->nodes[i]=newnode;
}
void buildminheap(minheap* mh)
{
	int n=mh->size-1;
		for(int i=(n-1)/2;i>=0;i--)
			minheapify(mh,i);
}
minheap* createandbuildhuffmanntree(char alpha[],int fre[],int size)
{
	minheap* mh=create_minheap(size);
	
	for (int i = 0; i < size; ++i) 
	mh->nodes[i] = create_node(alpha[i], fre[i]);
	
	mh->size=size;
		
	buildminheap(mh);
	
	return mh;
}
node* buildhuffmanntree(char alpha[],int fre[],int size)
{
	node *min1,*min2,*top;
	minheap* mh=createandbuildhuffmanntree(alpha,fre,size);
	while(mh->size!=1)
	{
		min1=extract_min(mh);
		min2=extract_min(mh);
		
		top=create_node('@',min1->freq+min2->freq);
		top->left=min1;
		top->right=min2;
		insert_minheap(mh,top);
	}
	return extract_min(mh);
}
void printCodes( node* root, int arr[], int top) 
{  
	if (root->left) { 
		arr[top] = 0; 
		printCodes(root->left, arr, top + 1); 
	} 
	if (root->right) { 
		arr[top] = 1; 
		printCodes(root->right, arr, top + 1); 
	} 
	if (!root->left&&!root->right) { 

		cout<< root->data <<": ";
		 c=c+(root->freq*top);
		for(int i=0;i<top;i++)
				cout<<arr[i];
			cout<<endl;
	} 
}  
int main()
{
	int n;
	cout<<"enter no of chars";
	cin>>n;
	char alphabet[n];
	int frequency[n];
	cout<<"enter char and it's frequency"<<n<<"times\n";
	for(int i=0;i<n;i++)
	cin>>alphabet[i]>>frequency[i];
	 
	node *x=buildhuffmanntree(alphabet,frequency,n);
	int ar[100],top=0;
	printCodes(x,ar,top);
	
	int sumoffreq=0;
	for(int i=0;i<n;i++)
	sumoffreq+=frequency[i];
	
	
	double count=sumoffreq*((int)(log(n)/log(2))+1);
	cout<<count<<" required for fixed length\n";
	cout<<c<<"required for variable length\n";
	
	
	
	
	return 0;
}
