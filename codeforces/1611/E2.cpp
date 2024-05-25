/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dfs1(int node,vector<int> &vis,vector<int> adj[],vector<int> &dp,set<int> &s)
{
    vis[node]=1;
    
    for(auto i:adj[node])
    {
        if(vis[i]==0)
        {
            dfs1(i,vis,adj,dp,s);
            dp[node]=min(dp[node],dp[i]+1);
        }
    }
    
    if(s.find(node)!=s.end())
    {
        dp[node]=0;
    }
}

void dfs2(int node,vector<int> &vis,vector<int> adj[],vector<int> &dp,int dis,int &ans)
{
    vis[node]=1;
    
    int c=0;
    
    if(dp[node]>dis)
    {
        for(auto i:adj[node])
        {
          if(vis[i]!=1)
          {
              c=1;
              dfs2(i,vis,adj,dp,dis+1,ans);
          }
        }
    }
    
    if(dp[node]<=dis)
    {
        if(ans!=-1)
        {
            ans=ans+1;
        }
        return;
    }
    
    if(c==0)
    {
        if(dp[node]>dis)
        {
            ans=-1;
        }
    }
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    while(test--)
    {
        int n,k;
        cin>>n>>k;
        set<int> s;
        for(int t=0;t<k;t++)
        {
            int x;
            cin>>x;
            s.insert(x);
        }
        vector<int> adj[n+1];
        int q=n-1;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }   
        
        vector<int> dp(n+1,1e14);
        vector<int> vis(n+1,0);
        dfs1(1,vis,adj,dp,s);
        int ans=0;
        for(int t=0;t<=n;t++)
        {
            vis[t]=0;
        }
        dfs2(1,vis,adj,dp,0,ans);
        
        cout<<ans<<endl;
    }
    return 0;
}