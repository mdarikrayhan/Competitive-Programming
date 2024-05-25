#include <iostream>
#include <vector>

using namespace std;

int result = INT_MAX;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited)
{
    if(visited[node])return;
    visited[node] = true;
    vector<bool> found(visited.size());
    for(int e: adj[node])
    {
        found[e] = true;
        dfs(e, adj, visited);
        for(int d:adj[e])
        {
            if(found[d])
            {
                int sum = adj[node].size() + adj[e].size() + adj[d].size();
                result = min(result, sum-6);
            }
        }
    }
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n+1);
    for(int i=1; i<=n; i++)
    {
        if(visited[i])continue;
        dfs(i, adj, visited);
    }
    if(result == INT_MAX)
    {
        cout<<-1;
    }
    else
    {
        cout<<result;
    }
    return 0;
}