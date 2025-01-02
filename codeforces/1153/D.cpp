#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=1e9;
const int maxn=3e5+5;
vector<int> adj[maxn];
int arr[maxn];
int dp[maxn];
int leaf=0;
void dfs(int u){
    if(adj[u].size()==0){
        dp[u]=1;
        leaf++;
        return;
    }
    if(arr[u]==1)   dp[u]=inf;
    for(auto v:adj[u]){
        dfs(v);
        if(arr[u]==1)   dp[u]=min(dp[u],dp[v]);
        else    dp[u]+=dp[v];
    }
}
void solve(){
    int n;  cin>>n;
    for(int i=0;i<n;i++)    cin>>arr[i];
    for(int i=1;i<n;i++){
        int x;  cin>>x; x--;
        adj[x].push_back(i);
    }
    dfs(0);
    int res=leaf-dp[0]+1;
    cout<<res<<"\n";
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