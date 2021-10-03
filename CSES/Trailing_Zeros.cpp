#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    int k=5;
    int ans=0;
    while(k<=n)
    {
        ans+=n/k;
        k*=5;
    }
    cout<<ans;
 
    return 0;
}