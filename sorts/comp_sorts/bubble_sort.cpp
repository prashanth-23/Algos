#include<iostream>
using namespace std;
void bubsort(int a[],int n);
int main()
  {	
      int n,i,j,temp;
      cout<<"enter no of elementsin array";
      cin>>n;
      int a[n];
      cout<<"enter the nos";
      for(i=0;i<n;i++)
	   cin>>a[i]; 
        bubsort(a,n);
	
	for(i=0;i<n;i++)
	cout<<a[i]<<endl;
} 
void bubsort(int a[],int n)
{
  int flag=1,i,j,temp;
   for(i=0;i<n-1;i++)
  {   
	flag=1;
	for(j=0;j<n-i-1;j++)
	if(a[j]>a[j+1])
	  {temp=a[j];
	   a[j]=a[j+1];
	   a[j+1]=temp;	
	    flag=0;
	   }
     if (flag==1)//😢😢🤢🤢🤢🤢🤢🎐🎐
	break;
   }
}
