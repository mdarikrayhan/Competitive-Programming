// LUOGU_RID: 160069490
//A tree without skin will surely die.
//A man without face is invincible.
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,j,k) for (int i=j;i<=k;++i)
int const N=2e5+10;
int n,a[N],ans;
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    map<int,int>dp;dp[a[1]-1]=0;
    rep(i,2,n)
        for (auto j=dp.lower_bound(a[i]);j!=dp.end();dp.erase(j++)){
            int x=j->first,y=j->second;
            dp[x%a[i]]=max(dp[x%a[i]],y+(x-x%a[i])*(i-1));
            dp[a[i]-1]=max(dp[a[i]-1],y+(i-1)*((x-a[i]+1)/a[i]*a[i]));
        }
    for (auto it:dp) ans=max(ans,it.first*n+it.second);
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--) solve();
    return 0;
}