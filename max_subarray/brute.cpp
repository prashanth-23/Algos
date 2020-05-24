#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter no of elements\n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int left,right,sum,max_sum=-82872313;
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=i;j<n;j++)
		{
			sum=sum+a[j];
			if(sum>max_sum)
			{
				left=i;
				right=j;
				max_sum=sum;
			}
		}
	}			
}
