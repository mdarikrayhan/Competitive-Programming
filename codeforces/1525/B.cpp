#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll ans = 2;
    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }
    if(is_sorted(v.begin(), v.end())){
        ans = 0;
    }
    else if(v[0] == 1 || v[n-1] == n){
        ans = 1;
    }
    else if(v[0] == n && v[n-1] == 1){
        ans = 3;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}