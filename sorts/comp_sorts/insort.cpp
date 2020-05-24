#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int comp;
void insertion_sort(int a[], int n);
int main()
{
	int n, *a;
	cout<<"enter value of n";
	cin>>n;	
	a = new int[n];
	ofstream ofs;
	ifstream ifs;
	ofs.open("gp_input.txt");
	for(int i = 0; i < n; i++)
	{
		ofs<<rand() % n<<"\t";
	}
	ofs.close();
	ifs.open("gp_input.txt");
	for(int i = 0; i < n; i++)
	{
		ifs>>a[i];
	}
	clock_t start, end;
	start = clock();
	insertion_sort(a, n);
	end = clock();
	ofs.open("gp_output.txt");
	for(int i = 0; i < n; i++)
		ofs<<a[i]<<"\t";
	ofs<<comp<<"comps";
	ofs.close();
	cout<<comp<<"comparisons"<<"\t";
	cout<<double(end - start) / CLOCKS_PER_SEC<<endl;
}
void insertion_sort(int a[], int n)
{
	int i, j, temp;
	for(j = 1; j < n; j++)
	{
		temp = a[j];
		i = j - 1;
		for(; i >= 0 && a[i] > temp; i--)
		{
			a[i + 1] = a[i];
			comp++;
		}
		a[i + 1] = temp;
	}		
}
