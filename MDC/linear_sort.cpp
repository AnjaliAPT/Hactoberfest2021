#include <iostream>
using namespace std;
// linear search is AKA is sequential search

//time complexity
//Best case ->O(1) //when element is at first index
//Worst case ->O(n) // when element is at the end or elemnt is not found
//Average case -> O(n) // sigma of all cases of searching /total number of numbers
int Linear_search_algorithm(int arr[], int size, int x)
{
    int found = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == x)
        {
            cout << "Element found at the index : " << i << endl;
            found = 1;
            break;
        }
    }
    if (found == size)
    {
        cout << "Element not found " << endl;
    }
}

int main()
{
    int array[] = {12, 23, 34, 45, 56, 67};
    int size = sizeof(array) / sizeof(int);
    int x = 56;
    Linear_search_algorithm(array, size, x);
    return 0;
}
