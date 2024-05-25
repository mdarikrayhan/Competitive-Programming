#include <bits/stdc++.h>

#define lli long long

using namespace std;

lli MOD = 1e9+7;

void dfs(vector<vector<lli> > &adj, vector<lli> &dp, vector<bool> &visited, lli u, vector<lli>& bfs_dist){
    visited[u] = true;
    dp[u] = bfs_dist[u];
    for(auto v: adj[u]){
        if(!visited[v] and bfs_dist[v] > bfs_dist[u]){
            dfs(adj, dp, visited, v, bfs_dist);
        }
        if (bfs_dist[v] > bfs_dist[u]){
            dp[u] = min(dp[u], dp[v]);
        }
        else{
            dp[u] = min(dp[u], bfs_dist[v]);
        }
    }
}

void solve(){
    lli n,m;
    cin>>n>>m;
    vector<vector<lli> > adj(n+1, vector<lli>());
    for(int i=0; i<m; i++){
        lli a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<lli> bfs_dist (n+1, -1);
    queue<lli> q;
    q.push(1);
    bfs_dist[1] = 0;
    while(!q.empty()){
        lli u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(bfs_dist[v] == -1){
                bfs_dist[v] = bfs_dist[u] + 1;
                q.push(v);
            }
        }
    }   
    vector<lli> dp(n+1, -1);
    vector<bool> visited(n+1, false);   
    dfs(adj, dp, visited, 1, bfs_dist);
    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}