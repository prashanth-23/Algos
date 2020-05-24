#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int comp;
int PARTITION(int data[], int first, int last);
void swap(int &a,int &b)
{
	int t = a;
	a = b;
	b = t;
}
void QUICK_SORT(int data[], int first, int last)
{
	int partition_index;
	if(first < last)
	{
		partition_index = PARTITION(data, first, last);
		QUICK_SORT(data, first, partition_index - 1);
		QUICK_SORT(data, partition_index + 1, last);
	}
	
}
int PARTITION(int data[], int first, int last)
{
	int key = data[last];
	int walker_1 = first-1;
	for(int walker_2 = first; walker_2 <= last - 1; walker_2++)
	{
		if(data[walker_2] < key)
		{
			comp++;
			walker_1++;
			swap(data[walker_1], data[walker_2]);
		}
	}
		walker_1++;
		swap(data[walker_1], data[last]);
	
	return walker_1;
	
}	
int main()
{
	
	int n, *a;
	cout<<"enter value of n";
	cin>>n;	
	a = new int[n];
	ofstream ofs;
	ifstream ifs;
	ofs.open("gp_input(qui).txt");
	for(int i = 0; i < n; i++)
	{
		ofs<<rand() % n<<"\t";
	}
	ofs.close();
	ifs.open("gp_input(qui).txt");
	for(int i = 0; i < n; i++)
	{
		ifs>>a[i];
	}
	int r = 0;
	clock_t start,end;
	start = clock();
	QUICK_SORT(a, 0, n - 1);
	end = clock();
	ofs.open("gp_output(qui).txt");
	for(int i = 0; i < n; i++)
		ofs<<a[i]<<"\t";
	ofs<<comp<<"comps";
	cout<<comp<<"comparisons"<<"\t";
	cout<<double(end - start) / CLOCKS_PER_SEC<<endl;
	ofs.close();
}
