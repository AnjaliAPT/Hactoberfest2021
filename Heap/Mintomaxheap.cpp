
#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
    // return left child of `A[i]`
    int LEFT(int i)
    {
        return (2 * i + 1);
    }

    // return right child of `A[i]`
    int RIGHT(int i)
    {
        return (2 * i + 2);
    }

    // Recursive function to implement the heapify-down algorithm.
    // The node at index `i` and its two direct children
    // violates the heap property
    void heapify(vector<int> &A, int i, int size)
    {
        // get left and right child of node at index `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int smallest = i;

        // compare `A[i]` with its left and right child
        // and find the smallest value
        if (left < size && A[left] < A[i])
        {
            smallest = left;
        }

        if (right < size && A[right] < A[smallest])
        {
            smallest = right;
        }

        // swap with a child having lesser value and
        // call heapify-down on the child
        if (smallest != i)
        {
            swap(A[i], A[smallest]);
            heapify(A, smallest, size);
        }
    }

public:
    // Constructor (Build-Heap – convert max-heap into min-heap)
    MinHeap(vector<int> &A)
    {
        int n = A.size();

        // call heapify starting from the last internal node all the
        // way up to the root node
        int i = (n - 2) / 2;
        while (i >= 0)
        {
            heapify(A, i--, n);
        }
    }

    // Function to remove an element with the highest priority (present at the root)
    int pop(vector<int> &A, int size)
    {
        // if the heap has no elements
        if (size <= 0)
        {
            return -1;
        }

        int top = A[0];

        // replace the heap's root with the last element
        // of the array
        A[0] = A[size - 1];

        // call heapify-down on the root node
        heapify(A, 0, size - 1);

        return top;
    }
};

// Convert max-heap into min-heap in linear time
int main()
{
    /*
               9
             /   \
            /     \
           4       7
          / \     / \
         /   \   /   \
        1    -2 6     5
 
    */

    // an array representing the max-heap
    vector<int> A = {9, 4, 7, 1, -2, 6, 5};

    // build a min-heap by initializing it by the given array
    MinHeap pq(A);

    // print the min-heap
    /*
               -2
             /    \
            /      \
           1        5
          / \      / \
         /   \    /   \
        9     4  6     7
    */

    for (int i : A)
    {
        cout << i << " ";
    }

    // repeatedly pop from the heap till it becomes empty
    /*
    int n = A.size();
    while (n > 0)
    {
        cout << pq.pop(A, n) << " ";
        n--;
    }*/

    return 0;
}