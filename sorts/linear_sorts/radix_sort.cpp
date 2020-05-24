#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
int comp=0;
void count_sort_inradix(int a[],int b[],int p,int n);
void radix_sort(int a[],int d,int n);
int d_ext(int m,int n)
{
	int j;
	j=(m/pow(10,n));
	j=j%10;
	return j;
}
int main()
{
	clock_t start,end;
	int n,*a,d=0;
	cout<<"enter no of values\n";
	cin>>n;
	int f=n;
	for(;f!=0;f=f/10,d++)
	a=new int[n];
	ofstream ofs;
	ofs.open("inp_prash(rsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<rand()%n<<"\t";
	}
	ofs.close();
	ifstream ifs;
	ifs.open("inp_prash(rsort).txt");
	for(int i=0;i<n;i++)
		ifs>>a[i];
	ifs.close();
	start=clock();
	radix_sort(a,d,n);
	end=clock();
	ofs.open("out_prash(rsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<a[i]<<"\t";
	}
	ofs.close();
	cout<<double(end-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	cout<<comp<<"comparisons\n";
}

void count_sort_inradix(int a[],int b[],int p,int n)
{
	int k=10;
	int c[k];
	for(int i=0;i<k;i++,comp++)
		c[i]=0;
	for(int j=0;j<n;j++,comp++)
		c[d_ext(a[j],p)]++;
	for(int i=1;i<k;i++,comp++)
		c[i]=c[i]+c[i-1];

	for(int j=n-1;j>=0;j--,comp++)
	{
		b[c[d_ext(a[j],p)]-1]=a[j];
		c[d_ext(a[j],p)]--;
	}
	
}

void radix_sort(int a[],int d,int n)
{
	int b[n];
	for(int i=0;i<d;i++)
	{
		count_sort_inradix(a,b,i,n);
		for(int l=0;l<n;l++)
			a[l]=b[l];
	}
}
