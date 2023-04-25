#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=2e5+9;
int lc[N],rc[N],a[N],rt,n,m,T,s[N],tp;
vector<int>dp[N];
void dfs(int x){
    if(lc[x])dfs(lc[x]);
    if(rc[x])dfs(rc[x]);
    for(int i=1;i<=m;i++)dp[x][i]=1ll*(lc[x]?dp[lc[x]][i-1]:1)*(rc[x]?dp[rc[x]][i]:1)%mod,(dp[x][i]+=dp[x][i-1])%=mod;
}
main(){
    for(cin>>T;T--;){
        cin>>n>>m;tp=0;
        for(int i=1;i<=n;i++){
            cin>>a[i],lc[i]=rc[i]=0,dp[i].resize(m+1);
            while(tp&&a[i]>a[s[tp]])lc[i]=s[tp--];
            tp?rc[s[tp]]=i:0;s[++tp]=i;
        }
        dfs(s[1]),cout<<dp[s[1]][m]<<'\n';
    }
}