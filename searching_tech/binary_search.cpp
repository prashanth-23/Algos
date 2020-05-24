#include<iostream>
using namespace std;
void bubsort(int a[],int n);
void binary_search(int arr[],int size,int tar);
int main()
 {
	int n,req;
        cout<<"enter the no of elements in array";
        cin>>n;
	int arr[n];
	cout<<"enter array elements";
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	//bubsort(arr,n);
	cout<<"the array after sort";
	for(int i=0;i<n;i++)
	  cout<<arr[i]<<" ";
	cout<<"enter the number to search";
	cin>>req;
	binary_search(arr,n,req);
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
void binary_search(int arr[], int size, int tar)
  {
	int low = 0, high = size - 1, mid, position;
	 while(low <= high)    
	  {
	   mid=(low + high) / 2;
	   if(tar > arr[mid])
	     high = mid - 1;
	   else
	     if(tar < arr[mid])
	       low = mid + 1;
	     else  
	        low = high + 1;
	  } 
	  if(arr[mid] == tar)
	    cout<<"it has found at index"<<mid<<endl;
	  else if(arr[mid] < tar)
	    cout<<"it has not found in array but its pos is"<<mid<<endl;
		else
		cout<<"it has not found in array but its pos is"<<mid + 1<<endl;
 }
	

















