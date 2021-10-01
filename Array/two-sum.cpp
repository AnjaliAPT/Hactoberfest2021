#TWO SUM PROBLEM SOLUTION

#include <bits/stdc++.h>
using namespace std;
 
bool hasArrayTwoCandidates(int A[], int n,int target)
{
    int l, r;
    sort(A, A + arr_size);

    l = 0;
    r = arr_size - 1;
    while (l < r) {
        if (A[l] + A[r] == sum)
            return 1;
        else if (A[l] + A[r] < sum)
            l++;
        else r--;
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
  
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
   
    int target = 16;
    if (hasArrayTwoCandidates(a, n, target))
        cout << "Array has two elements with given sum";
    else
        cout << "Array doesn't have two elements with given sum";
    return 0;
}
