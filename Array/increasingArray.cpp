#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //main code
    int t=1;
    while(t--)
    {
        int n;
        cin>>n;
        ll ans=0;
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            a.emplace_back(x);
        }
        for(int i=1;i<n;i++)
        {
            if(a[i]-a[i-1]<0)
            {
                ans+=a[i-1]-a[i];
                a[i]+=a[i-1]-a[i];
            }
        }
        cout<<ans;
    }
    return 0;
}