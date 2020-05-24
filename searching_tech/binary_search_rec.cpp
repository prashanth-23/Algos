#include<iostream>
using namespace std;
void bubsort(int a[],int n);
int binary_search_rec(int arr[],int low,int high,int tar);
int main()
 {
	int n,req;
        cout<<"enter the no of elements in array";
        cin>>n;
	int arr[n],low=0,high=n-1;
	cout<<"enter array elements";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	bubsort(arr,n);
	cout<<"the array after sort";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<"enter the number to search";
	cin>>req;
	binary_search_rec(arr,low,high,req);
	return 0;
}
void bubsort(int a[],int n)
{
  int flag=1,i,j,temp;
   for(i=0;i<n;i++)
  {   
	flag=1;
	for(j=0;j<n-i-1;j++)
	if(a[j]>a[j+1])
	  {temp=a[j];
	   a[j]=a[j+1];
	   a[j+1]=temp;	
	    flag=0;
	   }
     if (flag==1)
	break;
   }
}
int binary_search_rec(int arr[],int low,int high,int tar)
  {	 
	  int mid;
       	  if(low>high)
	  return -1;
	  else
	  mid=(low+high)/2;
	  if(arr[mid]>tar)
	  return binary_search_rec(arr,low,mid-1,tar);
	  if(arr[mid]<tar)
	  return binary_search_rec(arr,mid-1,high,tar);
	  if(arr[mid]==tar)
	  cout<<"it has found at index"<<mid<<endl;
	  else
	  cout<<"it has not found in array"<<endl;
		return 0;
 }
	

















