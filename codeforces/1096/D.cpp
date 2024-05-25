#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

string s;
ll n;
ll dp[300005][7];
string t = "hard";
vector<ll> a;
ll func(ll i , ll j){
    if(j == 4) return 2e18;
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = LLONG_MAX;
    if(s[i] != t[j]){
        ans = func(i + 1 , j);
    }
    else{
        ans = func(i + 1 , j) + a[i];
        ans = min(ans , func(i + 1 , j + 1));
    }
    
    return dp[i][j] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        cin >> n >> s;
        for(ll i = 0 ; i < n ; i++) {
            ll x;
            cin >> x;
            a.push_back(x);
        }

        for(ll i = 0 ; i < n + 3 ; i++){
            for(ll j = 0 ; j < 6 ; j++) dp[i][j] = -1;
        }
        
        cout << func(0 , 0) << "\n";

    return 0;
}
// Author : Raj_Singh