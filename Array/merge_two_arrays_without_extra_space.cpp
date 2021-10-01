#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i=n-1,j=0;
    while(i>=0 && j<m) 
    {
        if(arr1[i] >= arr2[j])
        {   
            swap(arr1[i],arr2[j]);
        }
        i--;
        j++;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}


void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{ 
    int a[] = {1, 1, 1, 2, 3, 5, 7, 7, 7, 9, 9, 13, 13, 14, 14, 17, 17, 19, 20, 20};
    int b[] = {3, 5, 7, 9, 10, 12, 13, 14, 20, 20};
    int size1 = sizeof(a)/sizeof(a[0]);
    int size2 = sizeof(b)/sizeof(b[0]);
    merge(a, b, size1, size2);
    printArray(a, size1);
    printArray(b, size2);
}