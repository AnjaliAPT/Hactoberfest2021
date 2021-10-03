#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int minDistance(string A, string B) {
    int n=A.length();
    int m=B.length();
    int dp[n+1][m+1];
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=i;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=1+min(min(dp[i][j-1],dp[i-1][j-1]),dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<minDistance(a,b);
    
    return 0;
}