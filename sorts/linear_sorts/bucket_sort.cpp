#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
int comp;
void insertion_sort(float a[],int n);
void bucket_sort(float a[],int n)
{
	float f[10][n];
	int key,k;
	int count[10];
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<n;j++)
		f[i][j]=0;
		count[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		key=10*a[i];
		cout<<key<<":";
		f[key][count[key]++]=a[i];
	}
	for(int i=0;i<10;i++)
	insertion_sort(f[i],count[i]);
	for(int i=0,m=0;i<10;i++)
	{
		for(int j=0;j<count[i];j++)
		a[m++]=f[i][j];
	}
	for(int j=0;j<n;j++)
		cout<<a[j];
}
void insertion_sort(float a[],int n)
{
	int i,j;
	float temp;
	for(j=1;j<n;j++)
	{
		temp=a[j];
		i=j-1;
		for(;i>=0&&a[i]>temp;i--)
		{
			a[i+1]=a[i];
			comp++;
		}
		a[i+1]=temp;
	}		
}
int main()
{
	clock_t start,end;
	int n;
	float *a;
	cout<<"enter no of values\n";
	cin>>n;
	a=new float[n];
	ofstream ofs;
	ofs.open("inp_prash(bsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<float(rand())/(float)RAND_MAX<<"\t";
	}
	ofs.close();
	ifstream ifs;
	ifs.open("inp_prash(bsort).txt");
	for(int i=0;i<n;i++)
		ifs>>a[i];
	ifs.close();
	start=clock();
	bucket_sort(a,n);
	end=clock();
	ofs.open("out_prash(bsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<a[i]<<"\t";
	}
	ofs.close();
	cout<<double(end-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	cout<<comp<<"comparisons\n";
}
