#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
const ll M=998244353;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> mp(10);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mp[v]|=(1<<u);
        mp[u]|=(1<<v);
    }
    vector<vector<int>> to((1<<10),vector<int>(10,-1));
    for(int i=0;i<(1<<10);i++){
        for(int j=0;j<=9;j++){
            if((i>>j)&1)    continue;
            int nxt=0;
            for(int k=0;k<=9;k++){
                if((i>>k)&1){
                    if((mp[k]>>j)&1)    nxt|=(1<<k);
                }
                else{
                    if(j>k&&((mp[k]>>j)&1)) nxt|=(1<<k);
                }
            }
            to[i][j]=nxt;
        }
    }
    vector<vector<ll>> dp(2,vector<ll>(1<<10,0));
    int t=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        t^=1;
        for(int j=0;j<(1<<10);j++){
            dp[t][j]=0;
        }
        for(int j=0;j<(1<<10);j++){
            if(dp[1^t][j]==0)  continue;
            for(int k=0;k<10;k++){
                if(to[j][k]==-1)    continue;
                dp[t][to[j][k]]=(dp[t][to[j][k]]+dp[1^t][j])%M;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<(1<<10);i++){
        ans=(ans+dp[t][i])%M;
    }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
   // cin >> _;
    while(_--) solve();
    return 0;
}