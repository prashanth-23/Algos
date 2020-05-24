#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;
int brute_comp=0;
int maxsub_comp=0;
struct ret
{
	int l;
	int h;
	int s;
};
ret brute_method(int a[],int low,int high);
ret find_max_subarray(int a[],int low,int high);
ret find_max_csubarray(int a[],int low,int mid,int high);
int main()
{
	clock_t start,end;
	int n,*a;
	cout<<"enter value of n";
	cin>>n;	
	a=new int[n];
	ofstream ofs;
	ifstream ifs;
	ofs.open("gp_input(maxsubarr).txt");
	for(int i=0;i<n;i++)
	{
		ofs<<n/2-(rand()%n)<<"\t";
	}
	ofs.close();
	ifs.open("gp_input(maxsubarr).txt");
	for(int i=0;i<n;i++)
	{
		ifs>>a[i];
	}
	ifs.close();
	int low=0,high=n-1;
	ret req1,req2;
	start=clock();
	req1=find_max_subarray(a,low,high);
	end=clock();
	double maxsub_time=double(end-start)/CLOCKS_PER_SEC;
	req2=brute_method(a,low,high);
	start=clock();
	double brute_time=double(start-end)/CLOCKS_PER_SEC;
	cout<<"max_sub->"<<req1.l<<"to"<<req1.h<<"\t the sum is"<<req1.s<<endl;
	cout<<"brute_method"<<req2.l<<"to"<<req2.h<<"\t the sum is"<<req2.s<<endl;
	cout<<"comparisons(maxsub,brute)"<<"("<<maxsub_comp<<","<<brute_comp<<")"<<endl;
	cout<<"time(maxsub,brute)"<<"("<<maxsub_time<<","<<brute_time<<")"<<endl;
}
ret find_max_subarray(int a[],int low,int high)
{	
	ret left,right,cross,re;
	if(low==high)
		{
			maxsub_comp++;
			re.l=low;
			re.h=high;
			re.s=a[low];
			return re;
		}
	else
	{	int mid=(low+high)/2;
		left=find_max_subarray(a,low,mid);
		right=find_max_subarray(a,mid+1,high);
		cross=find_max_csubarray(a,low,mid,high);
		
			if(left.s>=right.s&&left.s>=cross.s)
			{
				maxsub_comp=maxsub_comp+2;
				return left;
			}
			else
				if(right.s>=left.s&&right.s>=cross.s)
					{
						maxsub_comp=maxsub_comp+2;
						return right;
					}
				else
					return cross;
				
	}
}
ret find_max_csubarray(int a[],int low,int mid,int high)
{
	ret ex;
	int l_ind,r_ind;
	int sum=0;
	int l_sum=-789990890;
	for(int i=mid;i>=low;i--,maxsub_comp++)
	{
		sum=sum+a[i];
		if(sum>l_sum)
		{
		maxsub_comp++;
		l_ind=i;
		l_sum=sum;
		}
	}
	int r_sum=-957656555;
	sum=0;
	for(int j=mid+1;j<=high;j++,maxsub_comp++)
	{
		sum=sum+a[j];
		if(sum>r_sum)
		{
		maxsub_comp++;
		r_ind=j;
		r_sum=sum;
		}
	}
	ex.l=l_ind;ex.h=r_ind;
	ex.s=(l_sum+r_sum);
	
	return ex;
}
ret brute_method(int a[],int low,int high)
{
	ret re;
	int left,right,sum,max_sum=-82872313;
	for(int i=low;i<=high;i++,brute_comp++)
	{
		sum=0;
		for(int j=i;j<=high;j++,brute_comp++)
		{
			sum=sum+a[j];
			if(sum>max_sum)
			{
				brute_comp++;
				left=i;
				right=j;
				max_sum=sum;
			}
		}
	}
		re.l=left;
		re.h=right;
		re.s=max_sum;
		return re;
}
	
	
	
	
