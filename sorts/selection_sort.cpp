#include<iostream>
using namespace std;
void secsort(int a[],int n);
int main()
  {	
      int n,i,j,temp;
      cout<<"enter no of elementsin array";
      cin>>n;
      int a[n];
      cout<<"enter the nos";
      for(i=0;i<n;i++)
	   cin>>a[i]; 
        secsort(a,n);
	
	for(i=0;i<n;i++)
	cout<<a[i]<<endl;
} 
void secsort(int a[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}
