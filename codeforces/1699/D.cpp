#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)   cin>>a[i];
    vector<vector<bool>> flag(n+1,vector<bool>(n+1,0));
    vector<int> sum(n+1);
    int mx=0;
    for(int i=1;i<=n;i++){
        mx=0;
        for(int j=i;j<=n;j++){
            sum[a[j]]++;
            mx=max(mx,sum[a[j]]);
            if((j-i)&1){
                if(j-i+1>=2*mx) flag[i][j]=1;
            }
        }
        for(int j=i;j<=n;j++)   sum[a[j]]--;
    }
    vector<int> dp(n+1,-1);
    dp[0]=0;dp[1]=1;
    for(int i=2;i<=n;i++){
        if(flag[1][i-1])    dp[i]=1;
        if(a[i-1]==a[i]&&dp[i-1]!=-1)    dp[i]=max(dp[i],dp[i-1]+1);
        for(int j=i-3;j>=1;j-=2){
            if(a[j]==a[i]&&flag[j+1][i-1]&&dp[j]!=-1)   dp[i]=max(dp[i],dp[j]+1);
        }    
    }
    int ans=0;
    if(dp[n]!=-1)   ans=dp[n];
    for(int i=n-2;i>=1;i-=2){
        if(dp[i]!=-1&&flag[i+1][n]){
            //cout<<dp[i]<<'\n';
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
