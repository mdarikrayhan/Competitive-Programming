#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--;    v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> odd(n),parity(n);
    for(auto &x:odd)    cin>>x;
    vector<int> vis(n);
    int found=0;
    vector<int> path;
    auto dfs=[&](auto dfs,int u,int p,int root)->void{
        vis[u]=1;
        if(odd[u])  found=1;
        path.push_back(u);
        parity[u]^=1;
        for(auto x:adj[u]){
            if(!vis[x]){
                dfs(dfs,x,u,0);
                if(parity[x]^odd[x]){
                    path.push_back(u);
                    path.push_back(x);
                    parity[u]^=1;
                    parity[x]^=1;
                }
                path.push_back(u);
                parity[u]^=1;
            }
        }
        if(u==root){
            if(parity[u]^odd[u]){
                path.pop_back();
                parity[u]^=1;
            }
        }
    };
    {}
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            found=0;
            dfs(dfs,i,0,i);
            if(found){
                cnt++;
                if(cnt>1){
                    cout<<-1<<"\n";
                    return;
                }
            }
            else if(!cnt){
                path.clear();
            }
        }
    }
    cout<<path.size()<<"\n";
    for(auto x:path)    cout<<x+1<<" ";
    cout<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}