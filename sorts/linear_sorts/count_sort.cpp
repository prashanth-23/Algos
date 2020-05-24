#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
int comp=0;
void count_sort(int a[],int b[],int k,int n);
int main()
{
	clock_t start,end;
	int n,*a;
	cout<<"enter no of values\n";
	cin>>n;
	a=new int[n];
	ofstream ofs;
	ofs.open("inp_prash(csort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<rand()%n<<"\t";
	}
	ofs.close();
	ifstream ifs;
	ifs.open("inp_prash(csort).txt");
	for(int i=0;i<n;i++)
		ifs>>a[i];
	ifs.close();
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(k<a[i])
			k=a[i];
	}
	int b[n];
	start=clock();
	count_sort(a,b,k,n);
	end=clock();
	ofs.open("out_prash(csort).txt");
	for(int i=0;i<n;i++)
	{	
		ofs<<b[i]<<"\t";
	}
	ofs.close();
	cout<<double(end-start)/CLOCKS_PER_SEC<<"seconds"<<endl;
	cout<<comp<<"comparisons";
	

	
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
