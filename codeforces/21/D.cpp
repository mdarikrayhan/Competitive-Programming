#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f
using namespace std;
int n, m, base, cur=0, dp[1<<17], ans;
vector<pair<pair<int, int>, int>> ed;
vector<int> adj[20];
bool vis[20];
void dfs(int u)
{
    vis[u]=1;
    for(int v:adj[u])
        if(!vis[v])
            dfs(v);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    while(m--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        ed.push_back({{u, v}, w});
        cur+=w;
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i] && adj[i].size()>0)
            return cout<<-1, 0;
        if(adj[i].size()%2!=0)
            base+=(1<<(i-1));
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[base]=cur;
    for(auto it:ed)
    {
        for(int mask = 0; mask < (1<<n); mask++)
        {
            if(dp[mask]==inf)
                continue;
            int u=it.fi.fi-1, v=it.fi.se-1;
            dp[mask^(1<<u)^(1<<v)]=min(dp[mask^(1<<u)^(1<<v)], dp[mask]+it.se);
        }
    }
    ans=dp[0];
    cout<<ans;
}

 			   			  	 			 	 						   	