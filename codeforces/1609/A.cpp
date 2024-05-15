#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n;
    cin >> n;
    ll max = 0, res = 0, cnt = 0;
    for(ll i = 0; i < n; i++){
        ll x;
        cin >> x;
        while(x%2 == 0){
            x /= 2;
            cnt++;
        }
        if(x > max){
            res += max;
            max = x;
        }
        else{
            res += x;
        }
    }
    for(ll i = 0; i < cnt; i++){
        max *= 2;
    }
    res += max;
    cout << res << endl;
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