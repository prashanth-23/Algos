#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int comp;
void MERGE(int A[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j;
	int L[n1 + 1], R[n2 + 1];
	for(i = 1; i <= n1; i++)
		L[i] = A[p + i - 1];
	for(j = 1; j <= n2; j++)
		R[j] = A[q+j];
	L[n1 + 1] = 89890;
	R[n2 + 1] = 98909;
	i = 1; j = 1;
	int k;
	for(k = p; k <= r; k++)
	  {
	  	if(L[i] <= R[j])
	  	  { A[k] = L[i];
	  	    i++;
	  	   }
	  	   else 
	  	    { A[k] = R[j];
	  	     j++;
	  	     }
	  	     comp++;
	  }
	
}
void MERGE_SORT(int A[], int p, int r)
 {
 	if(p < r)
 		{int q = (p + r) / 2;
 		 MERGE_SORT(A, p, q);
 		 MERGE_SORT(A, q+1, r);
 		 MERGE(A, p, q, r);
 		 }
 }	
int main()
{
	
	int n, *a;
	cout<<"enter value of n";
	cin>>n;	
	a=new int[n];
	ofstream ofs;
	ifstream ifs;
	ofs.open("gp_input(mer).txt");
	for(int i = 0; i < n; i++)
	{
		ofs<<rand()%n<<"\t";
	}
	ofs.close();
	ifs.open("gp_input(mer).txt");
	for(int i = 0; i < n; i++)
	{
		ifs>>a[i];
	}
	int r = 0;
	clock_t start,end;
	start = clock();
	MERGE_SORT(a, r, n-1);
	end=clock();
	ofs.open("gp_output(mer).txt");
	for(int i = 0; i < n; i++)
		ofs<<a[i]<<"\t";
	ofs<<comp<<"comps";
	cout<<comp<<"comparisons"<<"\t";
	cout<<double(end - start) / CLOCKS_PER_SEC<<endl;
	ofs.close();
}
