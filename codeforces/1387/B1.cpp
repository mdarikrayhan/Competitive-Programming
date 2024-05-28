#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #include "bits/tools.h"
    #define debug(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
    #define debug(x...)
#endif

#define ll long long
#define fi first
#define se second
#define endl '\n'
const int N = 1e6 + 6,LOG = 27,MOD = 1e9 + 7;
const ll INF = 1e18;
void solver();

signed main(){
    cin.tie(0)->sync_with_stdio(0); 
    int t = 1; //cin>>t; 
    while(t--) solver();
}
int n,deg[N]; 
vector<int>g[N];
int par[N],euler[N],tin[N],timer = 0;
void dfs(int u,int p = 0){
    tin[u] = ++timer;
    euler[timer] = u;
    for(int v : g[u]) if(v != p){
        par[v] = u;
        dfs(v,u);
    }
}
void solver(){
    cin>>n; 
    for(int i = 1,u,v;i < n;++i){
        cin>>u>>v; 
        g[u].push_back(v); g[v].push_back(u); 
    }
    dfs(1); 
    vector<int>res(n + 1); 
    iota(res.begin(),res.end(),0);
    int cost = 0;  
    for(int i = n;i >= 1;--i){
        int u = euler[i];
        if(u == 1 || res[u] != u) continue;
        swap(res[u],res[par[u]]);
        cost += 2;
    }      
    if(res[1] == 1){swap(res[1],res[g[1][0]]); cost += 2;}
    cout<<cost<<endl;
    for(int i = 1;i <= n;++i) cout<<res[i]<<" ";
}