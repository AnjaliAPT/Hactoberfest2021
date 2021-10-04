#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int repeating(string A) {
    int n=A.length();
    string B=A;
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
    dp[i][0]=0;
    for(int i=0;i<=n;i++)
    dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(A[i-1]==B[j-1] && i!=j)
                dp[i][j]=1+dp[i-1][j-1];
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    if(dp[n][n]>1)
    return 1;
    return 0;
}
int main()
{
    string a;
    cin>>a;
    cout<<repeating(a);
    
    return 0;
}