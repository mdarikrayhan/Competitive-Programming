#include<bits/stdc++.h>

using namespace std;

void runcase(){
    int n,k,c;
    cin >> n >> k >> c;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<int> dp(n+1);
    long long ans=0;
    function<void(int,int,int)> dfs=[&](int u,int p,int l){
        int x=0,y=0;
        for(auto v:adj[u]){
            if(v==p)continue;
            dfs(v,u,l+1);
            dp[u]=max(dp[u],dp[v]+1);
            y=max(y,dp[v]+1);
            if(x<y)swap(x,y);
        }
        ans=max({ans,1ll*(x+y)*k-1ll*(y+l)*c,1ll*x*k-1ll*l*c});
    };
    dfs(1,0,0);
    cout << ans << '\n';
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t(1);
    cin >> t;
    while(t--)runcase();
}