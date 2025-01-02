#include <bits/stdc++.h>
using namespace std;
#define endl  "\n"
#define int long long
void dfs(int root,int par,vector<int> adj[],vector<int>& dp,int& ans){
    for(auto it:adj[root]){
        if(it != par){
            dfs(it,root,adj,dp,ans);
            dp[root]=max(dp[root],dp[it]+1);
        }
    }
    ans+=dp[root];
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mod=1e9+7;
        vector<int>adj[n+1],dp(n+1,1);
        for(int i=0;i<n-1;i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        dfs(1,-1,adj,dp,ans);
        for(int i=0;i<n-1;i++){
            ans=(ans%mod*2%mod)%mod;
        }
        cout << ans%mod << endl;


    }

}
