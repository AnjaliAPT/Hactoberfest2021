
#define N 1000000
vector<ll> adj[N];
vector<bool> visited(N,0);
void _DFS(ll u)
{
    visited[u] = true;
    for (ll i=0; i<adj[u].size(); i++)
    {
        if (visited[adj[u][i]] == false)
        {
            _DFS(adj[u][i]);
        }
    }
}
void DFS(ll n)
{
    for (ll u=1; u<=n; u++)
    {
        if (visited[u] == false)
        {
            DFSUtil(u);
        }
    }
}
void aE(ll u, ll v)
{
    adj[u].push_back(v);
}
