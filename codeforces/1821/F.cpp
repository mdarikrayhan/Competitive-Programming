#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define lb(x,y) lower_bound(all(x),y)-begin(x)

mt19937 rng;

int mod = 998244353;

ll exGCD(ll a, ll b, ll &x, ll &y) {
    if (a == 0) { x = 0; y = 1; return b; }
    ll g = exGCD(b % a, a, x, y);
    ll t = x; x = y - b / a * x; y = t;
    return g;
}

int mInv(int n) {
    ll x, y, g = exGCD(n, mod, x, y);
    if (g != 1) return 0;
    return (x % mod + mod) % mod;
}

vector<int> factArr = {1}, factInvArr = {1};
int fact(int n) {
    while (sz(factArr) <= n)
        factArr.pb((int)((ll)factArr[sz(factArr) - 1] * sz(factArr) % mod));
    return factArr[n];
}

int factInv(int n) {
    fact(n);
    while (sz(factInvArr) <= n)
        factInvArr.pb(mInv(factArr[sz(factInvArr)]));
    return factInvArr[n];
}

int choose(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (int)((ll)fact(n) * factInv(k) % mod * factInv(n - k) % mod);
}

int mPow(int n, int p) {
    int res = 1, pow = n;
    while (p > 0) {
        if ((p & 1) == 1)
            res = (int)((ll)res * pow % mod);
        pow = (int)((ll)pow * pow % mod);
        p >>= 1;
    }
    return res;
}

void solve() {
    int n, m, k; cin >> n >> m >> k; k++;
    if ((ll)m * k > n) {
        cout << 0 << "\n";
        return;
    }
    ll res = 0;
    for (int i = 0; i <= m; i++) {
        int s = n - ((m - i) * k + i * (k * 2 - 1));
        ll n = (ll)choose(m, i) * choose(s + m, s) % mod * mPow(2, m - i) % mod;
        if (i % 2 == 0) {
            res += n;
            if (res >= mod) res -= mod;
        } else {
            res -= n;
            if (res < 0) res += mod;
        }
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    solve();

    return 0;
}