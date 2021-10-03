#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int lis(const vector<int> &A) {
    int n=A.size();
    int lis[n];
    lis[0]=0;
    for(int i=0;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(A[i]>A[j] && lis[i]<lis[j]+1)
            lis[i]=lis[j]+1;
        }
    }
    return *max_element(lis,lis+n);
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        arr.push_back(x);
    }
    cout<<lis(arr);
    
    return 0;
}