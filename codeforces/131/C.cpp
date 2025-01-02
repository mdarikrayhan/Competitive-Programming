#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fact[105];
void factorize() {
    fact[0] = 1;
    for (int i = 1; i <= 60; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

ll binp(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k & 1) res = (res * n);
        n = (n * n);
        k >>= 1;
    }
    return res;
}

ll Cnk(ll n, ll k) {
    if (k > n) return 0;
    ll res = 1;
    for (ll i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main() {
    ll n, m, t, sum = 0;
    cin >> n >> m >> t;
    factorize();
    for (int b = 4; b <= t - 1; b++) {
        int g = t - b;
        sum += Cnk(n, b) * Cnk(m, g);
    }
    cout << sum;
    return 0;
}
