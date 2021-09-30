#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define m 1000000007
// by sudhanshu
vector<ll> c(1000001,-1);
ll solve(ll n)
{
    if(n<1)
    {
    	return 0;
	}
	else if(n==1)
	{
		return 1;
	}
	else if(n==2)
	{
		return 2;
	}
    else if(n==3)
    {
        return 4;
    }
    else if(n==4)
    {
        return 8;
    }
    else if(n==5)
    {
        return 16;
    }
    else if(n==6)
    {
        return 32;
    }
	else
	{
		if(c[n]!=-1)
		{
			return (c[n]%m);
		}
		return c[n]=((solve(n-1)%m)+(solve(n-2)%m)+(solve(n-3)%m)+(solve(n-4)%m)+(solve(n-5)%m)+(solve(n-6)%m))%m;
	}
}
int main()
{
    ll t=1;
    cin>>t;
    cout<<solve(t);
    return 0;
}
