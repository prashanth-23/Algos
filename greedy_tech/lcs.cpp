#include<iostream>
#include<ctime>
#include<string>
using namespace std;
void LCS_solution(string str1,string str2,int **c,int ** b);
void PRINT_LCS(int **b,string str1,int i,int j);
int main()
{
	string s1,s2;
	cout<<"enter two strings";
	cin>>s1>>s2;
	int **c,**b;
	int len1=s1.length();
	int len2=s2.length();
	c=new int*[len1+1];
	b=new int*[len1+1];
	for(int i=0;i<=len1;i++)
	{
		c[i]=new int[len2+1];
		b[i]=new int[len2+1];
	}
	int ct=LCS_solution(s1,s2,c,b);
	cout<<"len of lcs=>"<<ct<<"\t";
	PRINT_LCS(b,s1,len1,len2);
	
}
void LCS_solution(string str1,string str2,int **c,int ** b)
{

	int m=str1.length();
	int n=str2.length();
	for(int i=0;i<=m;i++)
		c[i][0]=0;
	for(int i=0;i<=n;i++)
		c[0][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(str1[i-1]==str2[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=0;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=1;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=-1;
			}
		}
	}
	return count;
}
int PRINT_LCS(int **b,string str1,int i,int j)
{
	int count = 0;
	if(i!=0&&j!=0)
	{
		if(b[i][j]==0)
		{
			PRINT_LCS(b,str1,i-1,j-1);
			count++;
			cout<<str1[i-1];
		}
		else if(b[i][j]==1)
		{
			PRINT_LCS(b,str1,i-1,j);
		}
		else PRINT_LCS(b,str1,i,j-1);
	}
	return count;
		
}