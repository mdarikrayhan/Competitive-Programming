#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define el "\n"
#define vll vector<ll>
#define pb push_back
#define all(a) a.begin(), a.end()
#define ull unsigned long long

ll binpow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binpow(a, b/2);
    if(b%2) return res*res*a;
    else return res*res;
}

void solve(){
    ll n; cin >> n;
    ll l; cin >> l;
    vll a(n), b(n);
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> b[i];
    vll dif_a, dif_b;
    for(ll i = 0; i+1 < n; ++i) dif_a.pb(a[i+1]-a[i]);
    dif_a.pb((l - a[n-1] + a[0]));
    for(ll i = 0; i+1 < n; ++i) dif_b.pb(b[i+1]-b[i]);
    dif_b.pb(l - b[n-1] + b[0]);
    vll aux = dif_a;
    do{
        ll elem = dif_a[0];
        dif_a.erase(dif_a.begin());
        dif_a.pb(elem);
        if(dif_a == dif_b){
            cout << "YES" << el;
            return;
        }  
    }while(dif_a != aux);

    cout << "NO" << el;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}