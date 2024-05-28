#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 1e6 + 1;

ll n, k;
ll a[N];

ll g(ll x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x % 2 == 0) return 1;
    return 0;
}

ll h(ll x) {
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) return 0;
    if (x == 3) return 1;
    if (x % 2 == 1) return 0;

    map<ll, ll> mex;
    mex[h(x - 1)] ++;
    if (x % 2 == 0) mex[h(x / 2)] ++;
    ll res = 0;
    while (mex[res] != 0) res ++;
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    if (k % 2 == 0) {
        ll nim = 0;
        for (int i = 1; i <= n; i ++)
            nim ^= g(a[i]);
        cout << ((nim == 0) ? "Nicky" : "Kevin");
    } else {
        ll nim = 0;
        for (int i = 1; i <= n; i ++)
            nim ^= h(a[i]);
        cout << ((nim == 0) ? "Nicky" : "Kevin");
    }
}