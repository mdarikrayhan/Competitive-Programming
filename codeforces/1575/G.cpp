#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
// typedef __int128 lll;
// typedef __float128 lld;
using namespace std;

ll mod = 1e9 + 7;
vector<ll> f(1e5 + 1, 0), g(1e5 + 1, 0);

ll gcd_sum_fast(vector<ll>& a, ll inc) {
    ll ans = 0;
    for(int i = inc; i <= a.size(); i += inc){
        f[a[i - 1]] ++;
    }
    for(int i = g.size() - 1; i > 0; i--){
        g[i] = 0;
        for(int j = i; j < f.size(); j += i) {
            g[i] += f[j];
        }
        g[i] *= g[i];
        for(int j = i * 2; j < f.size(); j += i){
            g[i] -= g[j];
        }
        ans += g[i] * i;
    }
    for(int i = inc; i <= a.size(); i += inc){
        f[a[i - 1]] --;
    }
    return ans;
}

ll gcd_sum_slow(vector<ll> &a, ll i) {
    int n = a.size();
    ll res = 0;
    for(ll j = i; j <= n; j += i) {
        for(ll k = i; k <= n; k += i) {
            res += gcd(a[j - 1], a[k - 1]);
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> d(1e5 + 1, 0);
    ll ans = 0;
    for(int i = d.size() - 1; i > 0; i--){
        if(i > n) {
            continue;
        }
        if(i > sqrt(n)) {
            d[i] = gcd_sum_slow(a, i);
        }
        else {
            d[i] = gcd_sum_fast(a, i);
        }
        for(int j = i * 2; j < d.size(); j += i){
            d[i] -= d[j];
        }
        ans += d[i] * i;
    }
    ans %= mod;
    cout << ans << "\n";
    
    return 0;
}