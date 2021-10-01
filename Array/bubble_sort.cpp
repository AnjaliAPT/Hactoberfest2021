#include<iostream>
using namespace std;
int main()
{	int n, key;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) // input taking
	{
		cin >> arr[i];
	}

	int count = 1;
	while (count < n)
	{
		for (int i = 0; i < n - count; i++)
		{	if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			} 
		} count++;

	}

	for (int i = 0; i < n; i++) // output
		{
			cout << arr[i] << " ";
		}
}