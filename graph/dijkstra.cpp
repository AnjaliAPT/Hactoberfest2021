#include <bits/stdc++.h>
using namespace std;
#define sz(a)               int((a).size())
#define ll                  long long
#define pb                  push_back
#define ld                  long double
#define mp                  make_pair
#define vi                  vector<ll>
#define vii                  vector<pi>
#define endl                "\n"
#define ff                  first
#define ss                  second
#define all(c)              (c).begin(),(c).end()
#define allr(c)             (c).rbegin(),(c).rend()
#define rep(i,n)            for(ll i=0;i<n;i++)
#define cpresent(c,x)       (find(all(c),x) != (c).end())
#define input(a,n)          for(long long i=0;i<n;i++)cin>>a[i]
#define output(a,n)         for(long long i=0;i<n;i++)cout<<a[i]<<" "
#define reset(a,n)          memset(a,n,sizeof(a))   // n can only be 0 or -1
#define vl                  LLONG_MIN
#define vm                  LLONG_MAX
#define ep                  1e-10
#define seed                13331
#define pi                  pair<ll,ll>
#define inf                 10e9
#define N                   1000000
#define minp                vector<ll>, greater<ll>
#define M                   1000000007
#define MM                  1000000009
#define pie                 3.1415926535897932384626433832795
#define eu                  2.718281828459045
#define                     she_taught_me_to_code cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);cin.tie(NULL);    clock_t startTime=clock();
#define time     cout<<(double(clock()-startTime )/(double)CLOCKS_PER_SEC)*1000<<" ms"<<endl;
#define debug(k) cout<<"\t-> "<<#k<<" = "<<k<<endl;



bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
ll gcd(ll a,ll b)
{
    return b?gcd(b, a % b):a;
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
vi visited(N,0),dis(N,0);
vector<pair<ll,ll> > adj[N];        // value, node
void dijkstra()                     // time complexity is O( v+e*log(v) )
{
    for(ll i=2;i<=N;i++)
        dis[i]=N;
    priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
    pq.push(mp(0,1));
    while(!pq.empty())
    {
        pair<ll,ll> p=pq.top();
        ll x=p.ss;
        pq.pop();
        if(p.ff>dis[x])
            continue;
        for(ll i=0;i<adj[x].size();i++)
        {
            if(dis[adj[x][i].ss]>dis[x]+adj[x][i].ff)
            {
                dis[adj[x][i].ss]=dis[x]+adj[x][i].ff;
                pq.push(mp(dis[adj[x][i].ss],adj[x][i].ss));
            }
        }
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].pb(mp(c,b));
        adj[b].pb(mp(c,a));
    }
    dijkstra();
    for(ll i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
}
