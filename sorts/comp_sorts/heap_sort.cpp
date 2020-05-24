#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int comps=0;
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
void heap_sort(int a[],int n);
void build_max_heap(int a[] ,int n);
void heapify(int a[],int n,int i);
int main()
{
	int n,*a;
	cout<<"enter value of n";
	cin>>n;	
	a=new int[n];
	ofstream ofs;
	ifstream ifs;
	ofs.open("gp_input(heap).txt");
	for(int i=0;i<n;i++)
	{
		ofs<<rand()%n<<"\t";
	}
	ofs.close();
	ifs.open("gp_input(heap).txt");
	for(int i=0;i<n;i++)
	{
		ifs>>a[i];
	}
	clock_t start,end;
	start=clock();
	heap_sort(a,n);
	end=clock();
	ofs.open("gp_output(heap).txt");
	for(int i=0;i<n;i++)
		ofs<<a[i]<<"\t";
	ofs<<comps<<"compsrisons";
	ofs.close();
	cout<<comps<<"comparisons"<<"\t";
	cout<<double(start-end)/CLOCKS_PER_SEC<<endl;
}
void heap_sort(int a[],int n)
{
	build_max_heap(a,n);
	
	for(int i=n-1;i>=1;i--)
	{
		swap(a[0],a[i]);
		n--;
		heapify(a,n,0);
	}	
}
void build_max_heap(int a[] ,int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
}
void heapify(int a[],int n,int i)
{
	int left=2*i+1;
	int right=2*i+2;
	int largest;
	
	if(left<n&&a[left]>a[i])
	{
	largest=left;
	comps++;
	}
	else
		largest=i;
	if(right<n&&a[right]>a[largest])
	{
		comps++;
	largest=right;}
	
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		heapify(a,n,largest);
	}
		
		
}
/*
void heap_sort(int a[],int n)
{
	buildmax_heap(a,n);
	for(int i=n-1;i>0;i--)
	{
		swap(a[0],a[i]);
		n--;
		heapify(a,n,0);
	}
}
void buildmax_heap(int a[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(a,n,i);
}
void heapify(int a[],int n,int k)
{
	int left=2*k+1;
	int right=2*k+2;
	int largest=k;
	if(left<n&&a[left]<a[largest])
		largest=left;
	if(right<n&&a[right]<a[largest])
		largest=right;
	if(largest!=k)
	{
		swap(a[k],a[largest]);
		heapify(a,n,largest);
	}
}*/
