#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll MOD = 1000000007;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res *= a;
        a *= a;
        res %= MOD;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll ans = binpow(3, 3 * n) - binpow(7, n);
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans;
}