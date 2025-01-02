#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int

int fl{};

void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&prv,vector<int>&cyclenodes){
    vis[node]=1;
    for(auto v:adj[node]){
        if(v==prv[node])continue;
        if(vis[v]){
            if(!fl){
                fl=1;
                cyclenodes[node]=1;cyclenodes[v]=1;
                prv[v]=node;
                int u=prv[node];
                while(u!=v){
                    cyclenodes[u]=1;
                    u = prv[u];
                }
            }
            return;
        }
        else{
            prv[v]=node;
            dfs(v,adj,vis,prv,cyclenodes);
        }
    }
}

void dfstree(int node,vector<vector<int>>&adj,vector<int>&cntv,vector<int>&cyclenodes,vector<int>&prv){
    for(auto v:adj[node]){
        if(v==prv[node])continue;
        if(!cyclenodes[v]){
            prv[v]=node;
            dfstree(v,adj,cntv,cyclenodes,prv);
            cntv[node]+=cntv[v];
        }
    }
    cntv[node]++;
}

void solve(){
    int n;cin>>n;
    fl=0;
    vector<vector<int>>adj(n);
    for(int i=0;i<n;++i){
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    vector<int>vis(n,0),prv(n,-1),cntv(n,0),cyclenodes(n,0);
    dfs(0,adj,vis,prv,cyclenodes);
    int ans{};
    for(int i=0;i<n;++i){
        if(cyclenodes[i]){
            dfstree(i,adj,cntv,cyclenodes,prv);
            int cv = cntv[i];
            ans+=(cv*(cv-1))/2 + cv*(n-cv);
        }
    }
    cout << ans << endl;
}       

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
    solve();
    return 0;
}
