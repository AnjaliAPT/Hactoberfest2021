#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
#define mem(dp,x) memset(dp,x,sizeof(dp))
 
const ll mod = 1e9 + 7;
 
void main2() {
  ll n,i;
  cin>>n;
  vector<string> a(n);
  fo(i,n)cin>>a[i];
  int dp[n][n];
  mem(dp,0);
  fo(i,n)
	{
		for(int j = 0;j<n;j++)
		{
			if(a[i][j] == '.')
				dp[i][j] = 1;
		}
	}
  if(a[0][0] == '*' || a[n-1][n-1] == '*')cout<<0<<endl;
  else
  {
  	for(int i = 1;i<n;i++)
  	{
  		if(a[i][0] == '*')
  			dp[i][0] = 0;
  		else
  			dp[i][0] = dp[i-1][0];
  	}
  	for(int i = 1;i<n;i++)
  	{
  		if(a[0][i] == '*')
  			dp[0][i] = 0;
  		else
  			dp[0][i] = dp[0][i-1];
  	}
  	for(int i = 1;i<n;i++)
  	{
  		for(int j = 1;j<n;j++)
  		{
  			if(a[i][j] == '.')
  			{
  				dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
  			}
  			else
  				dp[i][j] = 0;
  		}
  	}

  	cout<<dp[n-1][n-1]<<endl;
  }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
    int t = 1;
    // cin >> t;
    while(t--) {
      main2();
    }
 
    return 0;
}
