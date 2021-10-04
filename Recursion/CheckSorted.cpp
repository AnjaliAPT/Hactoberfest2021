#include <iostream>
using namespace std;

bool is_sorted(int arr[], int n)
{
    // base case
    if (n == 0 or n == 1)
    {
        return true;
    }

    // check if sorted or not
    if (arr[0] > arr[1])
    {
        return false;
    }

    // recursive case
    return is_sorted(arr + 1, n - 1);
    // increment the pointer and decrement the size;
}

// the func will compare a[0] and a[1]
// if it's true the it will check
// a[1] and a[2] and same process goes on;

// if a[n] not greater then it will return false;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (is_sorted(arr, n))
    {
        cout << "SORTED\n";
    }
    else
    {
        cout << "NOT SORTED\n";
    }

    return 0;
}