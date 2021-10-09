
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Data structure to store a heap node
struct Node
{
    // `val` stores the element,
    // `i` stores the list number of the element,
    // `index` stores the column number of the list from which element was taken
    int val, i, index;
};

// Comparison object to be used to order the min-heap
struct comp
{
    bool operator()(const Node &lhs, const Node &rhs) const
    {
        return lhs.val > rhs.val;
    }
};

// Function to merge `M` sorted lists of variable length and
// print them in ascending order
void printSorted(vector<vector<int>> const &lists)
{
    int M = lists.size();

    // create an empty min-heap
    priority_queue<Node, vector<Node>, comp> pq;

    // push the first element of each list into the min-heap
    // along with the list number and their index in the list
    for (int i = 0; i < M; i++)
    {
        if (lists[i].size() >= 1)
        {
            pq.push({lists[i][0], i, 0});
        }
    }

    // run till min-heap is empty
    while (!pq.empty())
    {
        // extract the minimum node from the min-heap
        Node min = pq.top();
        pq.pop();

        // print the minimum element
        cout << min.val << " ";

        // take the next element from the "same" list and
        // insert it into the min-heap
        if (min.index + 1 < lists[min.i].size())
        {
            min.index += 1;
            min.val = lists[min.i][min.index];
            pq.push(min);
        }
    }
}

int main()
{
    // `M` lists of variable size
    vector<vector<int>> lists =
        {
            {10, 20, 30, 40},
            {15, 25, 35},
            {27, 29, 37, 48, 93},
            {32, 33}};

    printSorted(lists);

    return 0;
}