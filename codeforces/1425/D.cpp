#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct Snake {
    ll x, y, b;
};

vector<ll> factorial;

ll power(ll x, ll y, ll p) {
    ll res = 1;

    x = x % p;

    if (x == 0) return 0;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll prime = 1000000007;

vector<ll> coefficients;

ll binomial_coefficient_(ll n, ll k) {
    return (factorial[n] * power(factorial[k] * factorial[n - k], prime - 2, prime)) % prime;
}

ll binomial_coefficient(ll n, ll k) {
    return coefficients[n];
}

vector<vector<ll>> grid(1000);

ll squareCount(ll x1, ll y1, ll x2, ll y2) {
    if (x1 > x2 || y1 > y2) return 0;
    x2 = min(999LL, x2);
    y2 = min(999LL, y2);
    ll ret = grid[x2][y2];
    ll u = 0, l = 0, ul = 0;
    if (x1 > 0) u = grid[x1 - 1][y2];
    if (y1 > 0) l = grid[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) ul = grid[x1 - 1][y1 - 1];
    return ret - u - l + ul;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, r;
    cin >> n >> m >> r;

    factorial.resize(n + 1);
    factorial[0] = 1;
    for (ll i = 1; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % prime;
    }
    for (ll i = 0; i < 1000; ++i) {
        grid[i].resize(1000);
    }
    coefficients.resize(5005);
    for (ll i = m; i < 5005; ++i) {
        coefficients[i] = binomial_coefficient_(i, m);
    }
    vector<Snake> snakes(n);
    for (ll i = 0; i < n; ++i) {
        cin >> snakes[i].x >> snakes[i].y >> snakes[i].b;
        snakes[i].x--;
        snakes[i].y--;
        grid[snakes[i].x][snakes[i].y] = 1;
    }
    for (ll i = 1; i < 1000; ++i) {
        grid[0][i] += grid[0][i - 1];
    }
    for (ll i = 1; i < 1000; ++i) {
        grid[i][0] += grid[i - 1][0];
        for (ll j = 1; j < 1000; ++j) {
            grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }

    ll ans = 0;
    vector<ll> nearS(n), nearCount(n);
    for (ll i = 0; i < n; ++i) {
        ll near = 0;
        for (ll j = 0; j < n; ++j) {
            if (max(abs(snakes[i].x - snakes[j].x), abs(snakes[i].y - snakes[j].y)) <= r) {
                near++;
            }
        }
        nearS[i] = near;
        ll far = n - near;
        ll bs = (snakes[i].b * snakes[i].b) % prime;
        if (far < m) {
            ans += (binomial_coefficient(n, m) * bs) % prime;
            nearCount[i] = binomial_coefficient(n, m);
        } else {
            ans += (((prime + binomial_coefficient(n, m) - binomial_coefficient(far, m)) % prime)
                    * bs) % prime;
            nearCount[i] = (prime + binomial_coefficient(n, m) - binomial_coefficient(far, m)) % prime;
        }
        ans %= prime;
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i == j) continue;
            ll x1 = snakes[i].x, x2 = snakes[j].x, y1 = snakes[i].y, y2 = snakes[j].y;
            ll ab = (snakes[i].b * snakes[j].b) % prime;
            ll both = squareCount(max(x1, x2) - r, max(y1, y2) - r, min(x1, x2) + r, min(y1, y2) + r);
            ll far = n - nearS[i] - nearS[j] + both;
            ll together = 0;
            if (far < m) {
                together += binomial_coefficient(n, m);
            } else {
                together += ((prime + binomial_coefficient(n, m) - binomial_coefficient(far, m)) % prime);
                together %= prime;
            }
            ans += (((prime + nearCount[i] + nearCount[j] - together) % prime)
                    * ab) % prime;
            ans %= prime;
        }
    }
    cout << ans % prime << endl;

    return 0;
}