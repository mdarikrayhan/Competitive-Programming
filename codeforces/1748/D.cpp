#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll binpow(ll b, ll p, ll w) {
    ll c = 1;
    while (p > 0) {
        if (p & 1) c = 1LL * c * b % w;
        p >>= 1;
        b = 1LL * b * b % w;
    }
    return c;
}

void solve() {
    ll a, b, d;
    cin >> a >> b >> d;
    a |= b;

    if ((d & -d) > (a & -a)) {
        cout << "-1\n";
        return;
    }

    if (a % d == 0) {
        cout << a << '\n';
        return;
    }

    int k = 0;
    while (1 ^ d & 1) {
        d >>= 1;
        k++;
    }

    ll inv = (d + 1) >> 1;
    ll p = (binpow(inv, 30 - k, d) + d - 1) % d;
    ll x = (1LL << k) * (p * (1LL << 30 - k) + (1LL << 30 - k) - 1);
    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}

