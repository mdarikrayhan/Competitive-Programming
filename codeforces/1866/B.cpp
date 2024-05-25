//------ADIL SAYYED--------
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define vin(v,n) for(ll i=0;i<n;i++) cin>>v[i]
#define rep(i, n) for (ll i = 0; i < n; i++)
#define forf(i, a, b) for (ll i = a; i < b; i++)
#define forb(i, s, e) for (ll i = s; i >= e; i--)
#define vt vector<ll>
#define vp vector<pair<long long, long long>>
#define srt(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define pn cout<<"NO"<<'\n'
#define py cout<<"YES"<<'\n'


// ll nCr(ll n, ll r) {
//     if (r > n) return 0;
//     if (r == 0 || n == r) return 1;
//     double res = 0;
//     for (int i = 0; i < r; i++) {
//         res += log(n-i) - log(i+1);
//     }
//     return (ll)round(exp(res));
// }
const ll mod=998244353;
void solve(){
    ll n; cin>>n;
    map<ll,ll> m1;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
    }
    for(ll i=0;i<n;i++){
        m1[a[i]] = b[i];
    }
    ll m; cin>>m;
    map<ll,ll> m2;
    vector<ll> c(m),d(m);
    for(ll i=0;i<m;i++){
        cin>>c[i];
    }
    for(ll i=0;i<m;i++){
        cin>>d[i];
    }
    for(ll i=0;i<m;i++){
        m2[c[i]] = d[i];
    }
    // for(ll it:m2){
    //     m1[it.first]-=it.second;
    // }
    // for(ll it:m1){
    //     if(it.second<0){
    //         cout<<0<<'\n'
    //         return;
    //     }
    // }
    // ll ans=1;
    // for(ll it:m1){
    //     if(it.second>0) ans++;
    // }
    // cout<<int(pow(2,ans))%mod<<'\n';
    for(const auto &it:m2){
        m1[it.first]-=it.second;
    }
    for(const auto &it:m1){
        if(it.second<0){
            cout<<0<<'\n';
            return;
        }
    }
    ll ans=1;
    for(const auto &it:m1){
        if(it.second>0){
            ans*=2;
            ans%=mod;
        }
    }
    // cout <<((1LL<<ans)%mod)<<'\n';
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ll t; cin>>t;
    // while(t--)
    solve();
    return 0;
}