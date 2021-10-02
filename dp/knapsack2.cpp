//question : https://atcoder.jp/contests/dp/tasks/dp_e
#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mk make_pair
#define MAX (lld)1e18+7
#define lim (lld)1e9+7
#define MAX2 (lld)2e5+9
#define ff first
#define ss second
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const lld mod=lim;

lld power(lld x, lld y, lld p)  
{   lld res = 1;     x = x % p; if (x == 0) return 0;  
  
    while (y > 0)  
    { if (y & 1) res = (res*x) % p;  y = y>>1; x = (x*x) % p;   }  
    return res;  } 


lld extend_gcd(lld a, lld b, lld& x, lld& y) {
    if (b == 0) { x = 1;y = 0;return a;}
    lld x1, y1;
    lld d = extend_gcd(b, a % b, x1, y1);
    x = y1; y = x1 - y1 * (a / b);return d;	}

lld modinv(lld a, lld p)
{return power(a,p-2,p);}

lld rowNum[]={-1,0,0,1};
lld colNum[]={0,-1,1,0};

int main()
{
	fastio
	lld n,w;
	cin>>n>>w;

	std::vector<lld> weight(n),val(n);
	lld sum=0;
	for(lld i=0;i<n;i++)
	{
		cin>>weight[i]>>val[i];
		sum+=val[i];
	}

	std::vector<vector<lld>> dp(n+1,vector<lld>(sum+1,MAX));

	for(lld i=0;i<=n;i++)
		dp[i][0] = 0;

	for(lld i=1;i<=n;i++)
	{
		for(lld j=0;j<=sum;j++)
		{
			dp[i][j] = dp[i-1][j];

			if(j-val[i-1]>=0)
				dp[i][j] = min(dp[i][j],dp[i-1][j-val[i-1]]+weight[i-1]);
		}
	}

	lld ans = 0;
	for(lld i=0;i<=n;i++)
	{
		for(lld j=0;j<=sum;j++)
		{
			if(dp[i][j]<=w)
				ans = max(ans,j);
		}
	}

	cout<<ans<<endl;
}