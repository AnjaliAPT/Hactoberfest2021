#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

    int n;
    cin>>n;
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        ans = (ans*2)%1000000007;
    }
    cout<<ans;
    
 
    return 0;
}