// LUOGU_RID: 160013489
#include <bits/stdc++.h>
#define eb emplace_back
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define int long long

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef tuple<int, int, int> tu;
bool Mbe;

const int N = 5e4 + 5;
const int M = 8.5e5 + 5;
const int K = 20;

int n, m, a[N], f[N][K];
int g[M], c[M], su[M], sl[M];
map<int, int> C;

struct S {
    int cx, cy, sx, sy;
    S () { cx = cy = sx = sy = 0; }
    S (int _a, int _b, int _c, int _d) :
        cx(_a), cy(_b), sx(_c), sy(_d) { }
    S operator * (const S &rh) const {
        S res;
        res.cx = cx + rh.cx;
        res.cy = cy + rh.cy;
        res.sx = sx + rh.sx + cx * rh.cx;
        res.sy = sy + rh.sy + cy * rh.cx;
        return res;
    }
} x, y;

S qpow(S p, int q) {
    S res;
    for (; q; q >>= 1, p = p * p)
        if (q & 1) res = res * p;
    return res;
}

S Eu(int p, int q, int r, int l, S x, S y) {
    if (!l) return S();
    if (p >= q) return Eu(p % q, q, r, l, x, qpow(x, p / q) * y);
    int m = (p * l + r) / q;
    if (!m) return qpow(y, l);
    int c = l - (q * m - r - 1) / p;
    return qpow(y, (q - r - 1) / p) * x * Eu(q, p, (q - r - 1) % p, m - 1, y, x) * qpow(y, c);
}

int F(int a, int b, int c) {
    if (c <= 0) return 0;
    x.cy = y.cx = y.sx = 1;
    S res = qpow(x, c / b) * Eu(((a + b - 1) / b) * b - a, b, c % b, c / a, x, y);
    return res.sy - ((a + b - 1) / b) * (c / a) * ((c / a) + 1) / 2;
}

int G(int l, int r) {
    int len = __lg(r - l + 1);
    return __gcd(f[l][len], f[r - (1 << len) + 1][len]);
}

int H(int k, int l, int r) {
    int n = c[l], m = c[r], a = g[l], b = g[r], t = k - (su[r - 1] - su[l]);
    return F(a, b, t) - F(a, b, t - a * n) - F(a, b, t - b * m) + F(a, b, t - a * n - b * m);
}

int calc(int k) {
    // for (int i = 1; i <= m; i++)
    //     cout << g[i] << ' ' << c[i] << '\n';
    int res = 0;
    for (int i = 1; i <= m; i++) {
        int lim = min(k / g[i], c[i]);
        res += lim * c[i] - lim * (lim - 1) / 2;
    }
    // cout << res << '\n';
    for (int i = 1, j = 1; i <= m; i++) {
        while (j < i && su[i] - su[j - 1] > k) j++;
        if (j != i) res += c[i] * (sl[i - 1] - sl[j - 1]);
        int p = j - 1;
        while (p && su[i] - su[p - 1] > k && su[i - 1] - su[p] + g[p] + g[i] <= k) 
            res += H(k, p, i), p--;
    }
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], f[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = __gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n) {
            int l = j, r = n, g = G(i, j), k = j;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (G(i, mid) == g) k = mid, l = mid + 1;
                else r = mid - 1; 
            }
            C[g] += k - j + 1, j = k + 1;
        }
    }
    for (pi p : C) g[++m] = p.fi, c[m] = p.se;
    reverse(g + 1, g + m + 1), reverse(c + 1, c + m + 1);
    for (int i = 1; i <= m; i++) 
        su[i] = su[i - 1] + c[i] * g[i],
        sl[i] = sl[i - 1] + c[i];
    int l = 1, r = 1e14, res = -1, ct = (n * (n + 1) / 2 * (n * (n + 1) / 2 + 1) / 2 + 1) / 2;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (calc(mid) < ct) l = mid + 1;
        else r = mid - 1, res = mid;
    }
    cout << res << '\n';
}

bool Med;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cerr << (&Mbe - &Med) / 1048576.0 << " MB\n";
	#ifdef FILE
		freopen(".in", "r", stdin);
		freopen(".out", "w", stdout);
	#endif
	int T = 1;
	// cin >> T;
	while (T--) solve();
	cerr << (int)(1e3 * clock() / CLOCKS_PER_SEC) << " ms\n";
	return 0;
}