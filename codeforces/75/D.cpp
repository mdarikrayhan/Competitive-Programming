//ulimit -s unlimited
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define pql priority_queue<long long>
#define pqp priority_queue<pair<ll,ll> >
#define pqs priority_queue<ll,vl,greater<ll> >
#define md ((ll) 1e9+7)


void solve(){

    ll i,j,k,n,m;
    cin>>n>>m;
    ll mps[n];
    memset(mps,0,sizeof(mps));
    ll mai[n];
    memset(mai,0,sizeof(mai));
    vector<vl> a(n),dp(n),ps(n);
    for(i=0;i<n;i++){
        cin>>k;
        a[i].resize(k);
        dp[i].resize(k);
        ps[i].resize(k);
        for(j=0;j<k;j++){
            cin>>a[i][j];
        }
        dp[i][0] = a[i][0];
        ps[i][0] = a[i][0];
        mps[i] = a[i][0];
        mai[i] = a[i][0];
        for(j=1;j<k;j++){
            ps[i][j] = a[i][j]+ps[i][j-1];
            dp[i][j] = max(a[i][j],dp[i][j-1]+a[i][j]);
            mps[i] = max(mps[i],ps[i][j]);
            mai[i] = max(mai[i],dp[i][j]);
        }
    }

    ll curr = 0;
    ll ans = -md;
    for(i=0;i<m;i++){
        cin>>j;
        j--;
        ans = max({mai[j],curr+mps[j],ans});
        curr = max({0LL,curr+ps[j].back(),dp[j].back()});
        //cout<<ans<<","<<curr<<" ";
    }
    cout<<ans<<"\n";

    // for(i=0;i<n;i++){
    //     for(auto c:dp[i]){
    //         cout<<c<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
    // for(i=0;i<n;i++){
    //     for(auto c:ps[i]){
    //         cout<<c<<" ";
    //     }
    //     cout<<"\n";
    // }



}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while(t--)
        solve();
    return 0;
}