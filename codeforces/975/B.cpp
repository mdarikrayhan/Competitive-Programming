#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
const ll MOD = 1e9+7;
const ll INF = 1e18;
using namespace std;

void solve(){
    ll a[15], b[15];
    for(ll i=0; i<14; i++) cin >> a[i];
    ll ans = 0;
    for(ll i=0; i<14; i++){
        for(ll j=0; j<14; j++) b[j] = a[j];
        ll tmp = 0;
        ll x = a[i]/14;
        ll y = a[i]%14;
        b[i] = 0;
        for(ll j=0; j<14; j++) b[j] += x;
        for(ll j=1; j<=y; j++) b[(i+j)%14]++;
        for(ll j=0; j<14; j++){
            if(b[j]%2 == 0) tmp += b[j];
        }
        ans = max(ans, tmp);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t=1;// cin >> t;
    while(t--){
        solve();
    }
}