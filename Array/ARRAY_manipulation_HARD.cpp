#include <bits/stdc++.h>
using namespace std;
const int N =1e7+10;
long long int pf[N];
long long int ar[N];
int main()
{
  int n,m;
  cin>>n>>m;
  while(m--)
  {
  	int a,b,k;
  	cin>>a>>b>>k;
  	ar[a]+=k;
  	ar[b+1]-=k;
  }
  for(int i=1;i<=n;i++)
  {
  	pf[i]=pf[i-1]+ar[i];
  }
  long long mx=-1;
  for(int i=1;i<=n;i++)
  {
  	mx=max(mx,pf[i]);
  }
  cout<<mx;
}