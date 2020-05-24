#include<iostream>
#include<ctime>
#include<fstream>
#include<cstdlib>
using namespace std;
int MATRIXCHAIN_ORDER(int p[],int n,int **s);
int MATRIXCHAIN_DAC(int p[],int i,int j);
void PRINT_PAREN(int **s,int i,int j);
int main()
{
	clock_t start,end;
	int n,*p;
	cout<<"enter no of matrices";
	cin>>n;
	p=new int[n+1];
	cout<<"enter sizes";
	for(int i=0;i<n+1;i++)
	{
		cin>>p[i];
	}
	/*cout<<"values generated are\t";
	for(int i=0;i<n+1;i++)
		cout<<p[i]<<" ";*/
	int **s;
	s=new int*[n+1];
	for(int i=0;i<n+1;i++)
	s[i]=new int[n+1];
	int count_dp,count_dac;
	start=clock();
	count_dp=MATRIXCHAIN_ORDER(p,n,s);
	end=clock();
	cout<<"time for DP -"<<double(end-start)/CLOCKS_PER_SEC<<endl;
	cout<<"no of scalar multiplications in dp-"<<count_dp<<endl;
	
	start=clock();
	count_dac=MATRIXCHAIN_DAC(p,1,n);
	end=clock();
	cout<<"time for DAC -"<<double(end-start)/CLOCKS_PER_SEC<<endl;
	cout<<"no of scalar multiplications in dac-"<<count_dp<<endl;
	
	cout<<"the parenthesized format is";
	PRINT_PAREN(s,1,n);
}
int MATRIXCHAIN_DAC(int p[],int i,int j)
{
	if(i==j)
		return 0;
	int min=9999999;
	for(int k=i;k<j;k++)
	{
		int q=p[i-1]*p[k]*p[j]+MATRIXCHAIN_DAC(p,i,k)+MATRIXCHAIN_DAC(p,k+1,j);
		if(q<min)
			min=q;
	}
	return min;
}
int MATRIXCHAIN_ORDER(int p[],int n,int **s)
{
	int x;
	int m[n+1][n+1];
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{m[i][j]=0;
		s[i][j]=0;
		}
	}
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			m[i][j]=99999999;
			for(int k=i;k<j;k++)
			{
				x=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(x<m[i][j])
				{
					
					m[i][j]=x;
					s[i][j]=k;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{cout<<m[i][j]<<"->";
		 cout<<s[i][j]<<"-";
		}
		cout<<endl;
	}
return m[1][n];
}

void PRINT_PAREN(int **s,int i,int j)
{
	if(i==j)
		cout<<"A"<<i;
	else
	{
		cout<<"(";
		PRINT_PAREN(s,i,s[i][j]);
		PRINT_PAREN(s,s[i][j]+1,j);
		cout<<")";
	}
}
