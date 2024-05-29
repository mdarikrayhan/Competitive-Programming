#include<iostream>
#include<cstring>
#include<vector>
#include<random>
#include<chrono>
#include<algorithm>
using namespace std;
using LL = long long;
const int maxn = 2e6 + 5, mod = 998244353, G = 3, Gi = 332748118;

int qpow(int a, int b, int mod){
    int res = 1;
    while (b){
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

inline int mul(int a, int b){
    return 1LL * a * b % mod;
}

inline void add(int &a, int b){
    a += b;
    if (a >= mod) a -= mod;
}

inline void sub(int &a, int b){
    a -= b;
    if (a < 0) a += mod;
}

int inv[(1 << 21) + 5], fact[(1 << 21) + 5], invfact[(1 << 21) + 5];
void init(int n){
    inv[1] = 1;
    for(int i = 2; i <= n; i++)
        inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod; 
    fact[0] = invfact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = mul(fact[i - 1], i);
    invfact[n] = qpow(fact[n], mod - 2, mod);
    for(int i = n - 1; i >= 1; i--)
        invfact[i] = mul(invfact[i + 1], i + 1);  
}

int C(int a, int b){
    if (a < 0 || b < 0 || a < b) return 0;
    return mul(mul(fact[a], invfact[b]), invfact[a - b]);
}

namespace NTT{
    vector<int> Omega(int L){
        int wn = qpow(G, mod / L, mod);
        vector<int> w(L); 
        w[L >> 1] = 1;
        for(int i = L / 2 + 1; i < L; i++) w[i] = mul(w[i - 1], wn);
        for(int i = L / 2 - 1; i >= 1; i--) w[i] = w[i << 1];
        return w;
    }
    auto W = Omega(1 << 21);

    void DIF(int *a, int n) {
        for(int k = n >> 1; k; k >>= 1)
            for(int i = 0, y; i < n; i += k << 1)
                for(int j = 0; j < k; j++){
                    y = a[i + j + k], a[i + j + k] = mul(a[i + j] - y + mod, W[k + j]), 
                    add(a[i + j], y);
                }
    }

    void IDIT(int *a, int n) {
        for (int k = 1; k < n; k <<= 1)
            for (int i = 0, x, y; i < n; i += k << 1)
                for(int j = 0; j < k; j++){
                    x = a[i + j], y = mul(a[i + j + k], W[k + j]),
                    a[i + j + k] = x - y < 0 ? x - y + mod : x - y;
                    add(a[i + j], y);
                }
        int inv = mod - (mod - 1) / n;
        for(int i = 0; i < n; i++) a[i] = mul(a[i], inv);
        reverse(a + 1, a + n);
    }
}

using Poly = std::vector<int>;

void DFT(Poly &a){
    NTT::DIF(a.data(), a.size());
}

void IDFT(Poly &a){
    NTT::IDIT(a.data(), a.size());
}

int normed(int n) { 
    return n == 1 ? 1 : (1 << (32 - __builtin_clz(n - 1))); 
}

void norm(Poly &a) { 
    if (!a.empty()) a.resize(normed((int)a.size()), 0); 
}

void dot(Poly &a, Poly &b) {
    for(int i = 0; i < a.size(); i++)
        a[i] = mul(a[i], b[i]);
}

Poly operator*(Poly a, Poly b) {
    int n = a.size() + b.size() - 1, L = normed(n);
    if (a.size() <= 8 || b.size() <= 8) {
        Poly c(n);
        for(int i = 0; i < a.size(); i++)
            for(int j = 0; j < b.size(); j++)
                c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % mod;
        return c;
    }
    a.resize(L), b.resize(L);
    DFT(a), DFT(b), dot(a, b), IDFT(a);
    return a.resize(n), a;
}

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(mod / 2, mod - 1);

    int hsh[27];
    int mp[27];
    for(int i = 1; i <= 26; i++){
        hsh[i] = dist(rnd);
        cin >> mp[i];
    }
    string t, s;
    cin >> t >> s;
    reverse(t.begin(), t.end());
    Poly a(t.size()), b(t.size()), c(s.size());
    int sum = 0;
    for(int i = 0; i < t.size(); i++){
        int x = t[i] - 'a' + 1;
        int y = mp[x];
        a[i] = hsh[x], b[i] = hsh[y];
        add(sum, mul(a[i], b[i]));
    }
    vector<int> pre(s.size());
    for(int i = 0; i < s.size(); i++){
        int x = s[i] - 'a' + 1;
        c[i] = hsh[x];
        pre[i] = mul(c[i], c[i]);
        if (i - 1 >= 0) add(pre[i], pre[i - 1]);
    }
    Poly d(t.size());
    for(int i = 0; i < t.size(); i++){
        d[i] = a[i] + b[i];
        if (d[i] >= mod) d[i] -= mod;
    }
    d = d * c;

    auto get = [&](int l, int r){
        int k = pre[r] - (l == 0 ? 0 : pre[l - 1]);
        if (k < 0) k += mod;
        return k;
    };

    for(int i = 0; i + t.size() - 1 < s.size(); i++){
        int cur = 0;
        sub(cur, d[i + t.size() - 1]);
        add(cur, sum);
        add(cur, get(i, i + t.size() - 1));
        cout << (cur == 0);
    }
    cout << '\n';

}