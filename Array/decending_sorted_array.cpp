#include<iostream>
using namespace std;
int dorder_binary_search(int a[], int n, int key)
{
	int s = 0;
	int e = n-1;
	while (s <= e)
	{
		int mid = s+ (e-s)/2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] > key)
		{
			s = mid + 1;
		}
		else
		{
			e = mid - 1;
		}

	}
	return -1;
}

int main()
{
	int n,key;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<dorder_binary_search(arr,n,key)<<endl; 

}