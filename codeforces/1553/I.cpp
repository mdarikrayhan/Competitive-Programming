// LUOGU_RID: 159851784
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
const int maxn = 1e6 + 10;
const int mod = 998244353, G = 3;
const int inv2 = (mod + 1) >> 1;

namespace IO {
void openfile() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
}
void Min(int& x, int y) {
    x = (x < y) ? x : y;
}
void Max(int& x, int y) {
    x = (x > y) ? x : y;
}
int add(int x, int y) {
    return (x + y) >= mod ? (x + y - mod) : (x + y);
}
int sub(int x, int y) {
    return (x < y) ? (x + mod - y) : (x - y);
}
void Add(int& x, int y) {
    x = (x + y) >= mod ? (x + y - mod) : (x + y);
}
void Sub(int& x, int y) {
    x = (x < y) ? (x - y + mod) : (x - y);
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
void Mul(int& x, int y) {
    x = 1ll * x * y % mod;
}
int qpow(int x, int y = mod - 2) {
    int ans = 1;
    while (y) {
        if (y & 1)
            ans = 1ll * x * ans % mod;
        x = 1ll * x * x % mod, y >>= 1;
    }
    return ans;
}
inline int read() {
    int x = 0, f = 0;
    char c = getchar();
    while (!isdigit(c))
        f |= c == '-', c = getchar();
    while (isdigit(c))
        x = x * 10 + c - '0', c = getchar();
    if (f)
        x = -x;
    return x;
}
}  // namespace IO
using namespace IO;

const int invG = qpow(G);
int tr[maxn << 1], tf;
ull invn;
void tpre(int n) {
    if (n == tf)
        return;
    invn = qpow(n), tf = n;
    for (int i = 0; i < n; i++)
        tr[i] = ((tr[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0));
}
void NTT(int* g, int op, int n) {
    tpre(n);
    static ull f[maxn << 1], w[maxn << 1];
    w[0] = 1;
    for (int i = 0; i < n; i++)
        f[i] = g[tr[i]];
    for (int len = 1; len < n; len <<= 1) {
        ull tG = qpow(op ? G : invG, (mod - 1) / (len << 1));
        for (int i = 1; i < len; i++)
            w[i] = mul(w[i - 1], tG);
        for (int k = 0; k < n; k += (len << 1))
            for (int p = 0; p < len; p++) {
                int tt = w[p] * f[k | p | len] % mod;
                f[k | p | len] = f[k | p] + mod - tt;
                f[k | p] += tt;
            }
        if (len == (1 << 10))
            for (int i = 0; i < n; i++)
                f[i] %= mod;
    }
    if (!op)
        for (int i = 0; i < n; i++)
            g[i] = f[i] % mod * invn % mod;
    else
        for (int i = 0; i < n; i++)
            g[i] = f[i] % mod;
}
void px(int* f, int* g, int n) {
    for (int i = 0; i < n; i++)
        f[i] = 1ll * f[i] * g[i] % mod;
}

#define Poly vector<int>
Poly operator+(const Poly& A, const Poly& B) {
    Poly C = A;
    C.resize(max(A.size(), B.size()));
    for (int i = 0; i < B.size(); i++)
        Add(C[i], B[i]);
    return C;
}
Poly operator-(const Poly& A, const Poly& B) {
    Poly C = A;
    C.resize(max(A.size(), B.size()));
    for (int i = 0; i < B.size(); i++)
        Sub(C[i], B[i]);
    return C;
}
Poly operator*(const int x, const Poly& A) {
    Poly C;
    C.resize(A.size());
    for (int i = 0; i < A.size(); i++)
        C[i] = mul(x, A[i]);
    return C;
}
int lim;
Poly operator*(const Poly& A, const Poly& B) {
    static int a[maxn << 1], b[maxn << 1];
    cpy(a, &A[0], A.size()), cpy(b, &B[0], B.size());
    Poly C;
    C.resize(min(lim, (int)(A.size() + B.size() - 1)));
    int n = 1;
    for (; n < (A.size() + B.size() - 1); n <<= 1)
        ;
    NTT(a, 1, n), NTT(b, 1, n);
    px(a, b, n), NTT(a, 0, n);
    cpy(&C[0], a, C.size());
    clr(a, n), clr(b, n);
    return C;
}
void pinv(const Poly& A, Poly& B, int n) {
    if (n == 1)
        B.push_back(qpow(A[0]));
    else if (n & 1) {
        pinv(A, B, --n);
        int ans = 0;
        for (int i = 0; i < n; i++)
            Add(ans, mul(A[n - i], B[i]));
        Mul(ans, qpow(mod - A[0]));
        B.push_back(ans);
        // F[n] = -1/G[0]*(sum_{i=1}^{n-1}F[i]G[n-i]),G(A),F(B)
    }
    else {
        pinv(A, B, n / 2);
        Poly sa;
        sa.resize(n);
        cpy(&sa[0], &A[0], n);
        B = 2 * B - B * B * sa;
        B.resize(n);
        // R(x) = 2R*(x) - R*(x)^2F(x)(mod x^n)
    }
}
Poly pinv(const Poly& A) {
    Poly C;
    pinv(A, C, A.size());
    return C;
}

int inv[maxn], fac[maxn], ifac[maxn];
void Init() {
    fac[0] = fac[1] = ifac[0] = ifac[1] = inv[1] = 1;
    for (int i = 2; i <= lim; i++) {
        inv[i] = mul(mod - mod / i, inv[mod % i]);
        fac[i] = mul(fac[i - 1], i);
        ifac[i] = mul(ifac[i - 1], inv[i]);
    }
}
Poly dao(const Poly& A) {
    Poly C;
    C.resize(A.size() - 1);
    for (int i = 0; i < C.size(); i++)
        C[i] = mul(i + 1, A[i + 1]);
    return C;
}
Poly ints(const Poly& A) {
    Poly C;
    C.resize(A.size());
    for (int i = A.size() - 1; i; i--)
        C[i] = mul(inv[i], A[i - 1]);
    C[0] = 0;
    return C;
}
Poly ln(const Poly& A) {
    return ints(dao(A) * pinv(A));
}
void pexp(const Poly& A, Poly& B, int n) {
    if (n == 1)
        B.push_back(1);
    else if (n & 1) {
        pexp(A, B, n - 1), n -= 2;
        int ans = 0;
        for (int i = 0; i <= n; i++)
            Add(ans, 1ll * (i + 1) * A[i + 1] % mod * B[n - i] % mod);
        B.push_back(1ll * ans * inv[n + 1] % mod);
    }
    else {
        pexp(A, B, n / 2);
        Poly lnB = B;
        lnB.resize(n), lnB = ln(lnB);
        for (int i = 0; i < lnB.size(); i++)
            lnB[i] = sub(A[i], lnB[i]);
        lnB[0]++;
        B = lnB * B;
        B.resize(n);
    }
}
Poly pexp(const Poly& A) {
    Poly C;
    pexp(A, C, A.size());
    return C;
}
Poly qpow(const Poly& A, int k) {
    Poly B = ln(A);
    k %= (mod - 1);
    for (int i = 0; i < A.size(); i++)
        Mul(B[i], k);
    B = pexp(B);
    return B;
}
int b[maxn], m, a[maxn];
struct dat {
    vector<int> v[2][2];
    void resize(int x) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                v[i][j].resize(x + 1);
    }
    vector<int>* operator[](int x) {
        return v[x];
    }
};
dat solve(int l, int r) {
    if (r - l + 1 <= 3) {
        dat res;
        res.resize(r - l + 1);
        if (r - l + 1 == 2) {
            res[b[l]][b[r]][2] = (b[l] + 1) * (b[r] + 1);
            res[1][1][1] = 2;
        }
        else {
            res[b[l]][b[r]][3] = (b[l] + 1) * (b[l + 1] + 1) * (b[r] + 1);
            res[b[l]][1][2] = (b[l] + 1) << 1;
            Add(res[1][b[r]][2], (b[r] + 1) << 1);
            res[1][1][1] = 2;
        }
        return res;
    }
    int mid = (l + r) >> 1, len = r - l + 1;
    dat L = solve(l, mid), R = solve(mid + 1, r), res;
    res.resize(len);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++) {
                    Poly now = L[i][x] * R[y][j];
                    for (int t = 1; t <= r - l + 1; t++)
                        Add(res[i][j][t], now[t]);
                    for (int t = 1; t <= r - l; t++) {
                        if (x + y == 2)
                            Add(res[i][j][t], mul(now[t + 1], inv2));
                        else if (x + y == 1)
                            Add(res[i][j][t], now[t + 1]);
                        else
                            Add(res[i][j][t], add(now[t + 1], now[t + 1]));
                    }
                }
    return res;
}
signed main() {
    openfile();
    int n;
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n, lim = maxn - 10, Init();
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, num = 0; i <= n; i++) {
        num++;
        if (a[i] != a[i + 1]) {
            if (num % a[i]) {
                cout << 0 << endl;
                return 0;
            }
            for (int j = 1; j <= (num / a[i]); j++)
                b[++m] = a[i] > 1;
            num = 0;
        }
    }
    if (m == 1) {
        cout << b[1] + 1 << endl;
        return 0;
    }
    dat res = solve(1, m);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int sum = 0;
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                Add(sum, res[j][k][i]);
        if ((m - i) & 1)
            Sub(ans, mul(fac[i], sum));
        else
            Add(ans, mul(fac[i], sum));
    }
    cout << ans;
    return 0;
}
