#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
int d_ext(int m,int n)
{
	int j;
	j=(m/pow(10,n));
	j=j%10;
	return j;
}
void count_sort_inradix(int a[],int b[],int p,int n);
void radix_sort(int a[],int d,int n);
void insertion_sort(float a[],int n);
void count_sort(int a[],int b[],int k,int n);
void bucket_sort(float a[],int n)
{
	float f[n][n];
	int key,k;
	int count[n];
	for(int i=0;i<n;i++)
	count[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		f[i][j]=0;
	}
	for(int i=0;i<n;i++)
	{
		key=a[i];
		f[key][count[key]++]=a[i];
	}
	for(int i=0;i<n;i++)
	insertion_sort(f[i],count[i]);
	for(int i=0,m=0;i<n;i++)
	{
		k=count[i];
		for(int j=0;j<k;j++)
		a[m++]=f[i][j];
		
		
	}
}
void count_sort(int a[],int b[],int k,int n)
{
	
	int c[k+1];
	for(int i=0;i<=k;i++,comp++)
		c[i]=0;
	for(int j=0;j<n;j++,comp++)
		c[a[j]]++;
	for(int i=1;i<=k;i++,comp++)
		c[i]=c[i]+c[i-1];

	for(int j=n-1;j>=0;j--,comp++)
	{
		b[c[a[j]]-1]=a[j];
		c[a[j]]--;
	}
	
}
void insertion_sort(float a[],int n)
{
	int i,j,temp;
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
int main()
{
	int bucket_time,radix_time,count_time;
	clock_t start,end;
	int n;
	float *bucket;
	int *counts,*radix;
	cout<<"enter no of values\n";
	cin>>n;
	a=new float[n];
	ofstream ofs;
	ifstream ifs;
	//countsort;
	ofs.open("inp_prash(csort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<rand()%n<<"\t";
	}
	ofs.close();
	ifs.open("inp_prash(csort).txt");
	for(int i=0;i<n;i++)
		ifs>>counts[i];
	ifs.close();
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(k<counts[i])
			k=a[i];
	}
	//radixsort;
	ofs.open("inp_prash(rsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<rand()%n<<"\t";
	}
	ofs.close();
	ifs.open("inp_prash(rsort).txt");
	for(int i=0;i<n;i++)
		ifs>>a[i];
	ifs.close();
	//bucketsort;
	ofs.open("inp_prash(bsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<float(rand()/(float)RAND_MAX*n)<<"\t";
	}
	ofs.close();
	ifs.open("inp_prash(bsort).txt");
	for(int i=0;i<n;i++)
		ifs>>bucket[i];
	ifs.close();
	//end of taking inputs;
	start=clock();
	bucket_sort(bucket,n);
	end=clock();
	bucket_time=double(end-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	count_sort(counts,)
	start=clock();
	
	ofs.open("out_prash(bsort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<bucket[i]<<"\t";
	}
	ofs.close();
}
