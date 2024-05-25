#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1e9+7;
void solve()
{
    ll int n;
    cin>>n;
    vector<ll int>v(n);
    for(ll int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll int>dp(n+1);
    map<ll int,ll int>a,b;
    for(ll int i=1;i<=n;i++){
        if(a[v[i-1]]==0){
            dp[i]=dp[i-1]+1;
            a[v[i-1]]=1;
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    ll int ans=0;
    for(ll int i=n-1;i>=0;i--){
        if(b[v[i]]==0){
            ans+=dp[i];
            b[v[i]]=1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}