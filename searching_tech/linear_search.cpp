#include<iostream>
using namespace std;
void search(int a[],int size,int req);
int main()
 {
	int n,req;
        cout<<"enter the no of elements in array";
        cin>>n;
	int arr[n];
	cout<<"enter array elements";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<"enter the number to search";
	cin>>req;
	search(arr,n,req);
	return 0;
}
void search(int a[],int size,int req)
 {
	int i=0;
	for(;i<size;i++)
	{
	 if(a[i]==req)
	 break;
	}
	if(i<size)
	cout<<"it has found at index"<<i;
	else
	cout<<"it has not found in array";
 }
	
	
	
	
	
	
	
	
	
	
	
