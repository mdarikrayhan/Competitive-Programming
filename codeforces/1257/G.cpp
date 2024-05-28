#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
#define lb(x,y) lower_bound(all(x),y)-begin(x)

mt19937 rng;

int mod = 998244353, bits;

ll exGCD(ll a, ll b, ll &x, ll &y) {
    if (a == 0) { x = 0; y = 1; return b; }
    ll g = exGCD(b % a, a, x, y);
    ll t = x; x = y - b / a * x; y = t;
    return g;
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

int mInv(int n) {
    ll x, y, g = exGCD(n, mod, x, y);
    if (g != 1) return 0;
    return (x % mod + mod) % mod;
}

struct mont {
    inline static ll M, K, rInv, P, mask;
    static void setMod(int m) {
        while (1 << P < m) P++; mask = (1 << P) - 1;
        M = m; exGCD(1 << P, M, rInv, K);
        K = (1 << P) - K; if (rInv < 0) rInv += M; }
    ll v;
    explicit operator int() { return (int)(v * rInv % M); }
    mont():v(0) {}
    mont(ll n) { v = (n << P) % M; }
    mont& operator+=(mont o) { if ((v += o.v) >= M) v -= M; return *this; }
    mont& operator-=(mont o) { if ((v -= o.v) < 0) v += M; return *this; }
    mont& operator*=(mont o) { v = reduce(v * o.v); return *this; }
    friend mont operator+(mont a, mont b) { return a += b; }
    friend mont operator-(mont a, mont b) { return a -= b; }
    friend mont operator*(mont a, mont b) { return a *= b; }
    static ll reduce(ll n) {
        ll m = (n & mask) * K & mask;
        ll res = n + m * M >> P;
        if (res >= M) res -= M;
        return res;
    }
};

void fft(vector<mont> &v, bool inv) {
    int root = mPow(3, (mod - 1) >> bits);
    vector<mont> tmp(1 << bits);
    int half = 1 << bits - 1;
    for (int k = 1 << bits - 1; k > 0; k >>= 1) {
        mont w = 1, d = mPow(root, k);
        for (int l = 0; l < 1 << bits; l += k << 1, w *= d) {
            for (int m = 0; m < k; m++) {
                mont a = v[l + m], b = v[l + m + k] *= w;
                tmp[(l >> 1) + m] = a + b; tmp[(l >> 1) + m + half] = a - b;
            }
        }
        swap(v, tmp);
    }
    if (inv) {
        mont nI = mInv(1 << bits);
        reverse(1+all(v));
        for (int i = 0; i < 1 << bits; i++) v[i] *= nI;
    }
}

vector<int> mult(vector<int> &a, vector<int> &b) {
    mont::setMod(mod);
    vector<mont> v1(1 << bits), v2(1 << bits);
    for (int i = 0; i < sz(a); i++) v1[i] = a[i];
    for (int i = 0; i < sz(b); i++) v2[i] = b[i];
    fft(v1, false); fft(v2, false);
    vector<mont> v3(1 << bits);
    for (int i = 0; i < 1 << bits; i++) v3[i] = v1[i] * v2[i];
    fft(v3, true);
    vector<int> c(sz(a) + sz(b) - 1);
    for (int i = 0; i < sz(c); i++) c[i] = (int)v3[i];
    return c;
}

class cmp {
public:
    bool operator()(vector<int> &a, vector<int> &b) {
        return sz(a) > sz(b);
    }
};

void solve() {
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    map<int, int> freq;
    for (int i : a) freq[i]++;
    vector<int> b;
    for (auto &p : freq) {
        b.pb(p.second);
    }
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for (int i : b) {
        vector<int> v;
        for (int j = 0; j <= i; j++) v.pb(1);
        pq.push(v);
    }
    while (sz(pq) >= 2) {
        vector<int> v1 = pq.top(); pq.pop();
        vector<int> v2 = pq.top(); pq.pop();
        int m = 1, b = 0; while (m < sz(v1) + sz(v2)) m <<= 1, b++;
        bits = b;
        vector<int> v3 = mult(v1, v2);
        pq.push(v3);
    }
    vector<int> res = pq.top();
    cout << res[sz(res) / 2] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());

    solve();

    return 0;
}