#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> ve(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    vector<int> siz(n+1);
    vector<vector<int>> dp(n+1,vector<int>(20,1));
    vector<vector<int>> mp(n+1,vector<int>(20,1));
    ll ans=0;
    vector<int> dep(n+1);
    const int maxn=20;
    auto dfs=[&](auto self,int u,int v)->void {
        siz[u]=1;
        dep[u]=1;
        for(auto i:ve[u]){
            if(i==v)    continue;
            self(self,i,u);
            siz[u]+=siz[i]; 
            dep[u]=max(dep[u],dep[i]+1);
        }
        dp[u][0]=n;
        mp[u][0]=n;
        for(int i=1;i<20;i++){
            int num=0;
            map<int,int> beg;
            for(auto j:ve[u]){
                if(j==v)    continue;
                beg[dp[j][i-1]]++;num++;
                mp[u][i]=max(mp[u][i],mp[j][i]);
            }
            for(auto [x,y]:beg){
                if(num>=x){
                    dp[u][i]=max(dp[u][i],x);
                }
                else{
                    dp[u][i]=max(dp[u][i],num);
                }
                num-=y;
                if(num<=x)   break;
            }
            mp[u][i]=max(mp[u][i],dp[u][i]);
        }
        for(int i=0;i<20;i++)    ans+=mp[u][i]-1;
        ans+=dep[u];
    };
            
    dfs(dfs,1,1);
    //cout<<dp[2][2]<<'\n';
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}