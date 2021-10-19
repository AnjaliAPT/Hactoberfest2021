#include <bits/stdc++.h>
using namespace std;

// This function returns true if arr[0..size-1] has a pair
// with sum equals to the target sum.
void pairInSortedRotated(int arr[], int n, int target)
{
    // Find the pivot(largest) element
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            break;
    int low = (i + 1) % n; // l is now the index of smallest element
    int high = i;          // r is now index of largest element
    // Keep moving either low or high till they meet
    while (low != high)
    {
        // return true if we find a pair satisfying the condition
        if (arr[low] + arr[high] == target)
        {
            cout << "A pair exists with the given target sum: " << arr[low] << " and " << arr[high] << "\n";
            return;
        }
        // If current pair sum is less, increment the low pointer
        if (arr[low] + arr[high] < target)
            low = (low + 1) % n;
        // Move to the lower sum side
        else
            high = (n + high - 1) % n;
    }
    cout << "There does not exist any pair with the given target sum\n";
    return;
}

int main()
{
    int size, target;
    cout << "Enter the size of the array:\n";
    cin >> size;
    int arr[size];
    cout << "Enter the array elements:\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the target sum:\n";
    cin >> target;

    pairInSortedRotated(arr, size, target);
    return 0;
}
