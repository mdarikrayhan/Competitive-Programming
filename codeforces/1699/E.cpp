#include <bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
using ll=long long;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    vector<bool> flag(m+1);
    int mn=5000000;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];flag[a[i]]=1;
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    vector<int> dp(mx+1,-1);
    dp[mx]=mx;
    vector<int> bag(mx+1);
    bag[mx]=1;
    int mq=mx;
    int ans=mx-mn;
    //cout<<ans<<'\n';
    for(int i=mx-1;i>=1;i--){
        dp[i]=i;
        if(flag[i]) bag[i]++;
        for(int j=max(2,i);1ll*i*j<=mx;j++){
            if(dp[i*j]>dp[j]){
                if(flag[i*j]){
                    bag[dp[i*j]]--;
                    bag[dp[j]]++;
                }
                dp[i*j]=dp[j];
            }
            while(bag[mq]==0)   mq--;
        }    
        if(i<=mn)   ans=min(ans,mq-i);    
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
