#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int M = 1e9 + 7;

ll add(ll a, ll b) {
    a %= M;
    b %= M;
    a += b;
    if (a >= M) return a - M;
    if (a < 0) return a + M;
    return a;
}

ll f(__int128 x) {
    __int128 ans = x * (x + 1) / 2;
    return (ll) (ans % M);
}

ll gauss(ll l, ll r) {
    return add(f(r), -f(l - 1));
}

ll get(ll x, ll l, ll r) {
    if (x % 2 == 0) {
        return 2 * gauss(l, r) % M;
    } else {
        return (2 * gauss(l - 1, r - 1) + (r - l + 1)) % M;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l, r;
    cin >> l >> r;
    vector<ll> cnt(2, 0);
    int par = 1;
    ll p = 1;
    ll sum = 0;
    ll ans = 0;
    for (int i = 1; i <= 62; ++i) {
        if (l <= sum + 1 && sum + p <= r) {
            ans += get(par, cnt[par] + 1, cnt[par] + p);
        } else if (sum + 1 <= l && sum + p >= r) {
            ans += get(par, cnt[par] + l - sum, cnt[par] + r - sum);
        } else if (sum + 1 <= l && sum + p <= r && sum + p >= l) {
            ans += get(par, cnt[par] + l - sum, cnt[par] + p);
        } else if (sum + 1 >= l && sum + p >= r) {
            ans += get(par, cnt[par] + 1, cnt[par] + r - sum);
        }
        ans %= M;
        sum += p;
        if (sum > r) break;
        cnt[par] += p;
        p *= 2;
        par ^= 1;
    }
    cout << ans << "\n";
    return 0;
}


