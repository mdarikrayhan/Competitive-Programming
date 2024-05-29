#ifdef DEBUG
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <complex>
#include <numeric>
#include <assert.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ui = unsigned int;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, long long>;
using pli = pair<long long, int>;
using pll = pair<long long, long long>;
template <typename T>
using uset = unordered_set<T>;
template <typename T1, typename T2>
using umap = unordered_map<T1, T2>;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const int mod = 998244353;

int add(int a, int b) {
    if (a + b >= mod)
        return a + b - mod;
    return a + b;
}

int sub(int a, int b) {
    if (a < b)
        return a + mod - b;
    return a - b;
}

int mul(int a, int b) {
    return (int)((1ll * a * b) % mod);
}

int binpow(int a, int pw) {
    int b = 1;
    while (pw) {
        if (pw & 1)
            b = mul(b, a);
        a = mul(a, a);
        pw >>= 1;
    }
    return b;
}

int inv(int a) {
    return binpow(a, mod - 2);
}

const int N = (1 << 18) + 1;
int w[N], lg[N], rev[N];

void prepareFFT(int n) {
    int root = binpow(3, (mod - 1) / n);
    w[0] = 1;
    for (int i = 1; i < n; i++)
        w[i] = mul(w[i - 1], root);
    for (int i = 1; i < n; i++)
        rev[i] = rev[i ^ (1 << lg[i])] ^ (1 << (lg[n] - 1 - lg[i]));
}

vector<int> fft(vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int len = 1; len < n; len <<= 1)
        for (int i = 0; i < n; i += 2 * len)
            for (int j = 0; j < len; j++) {
                int x = mul(w[j << (lg[n] - 1 - lg[len])], a[i + j + len]);
                a[i + j + len] = sub(a[i + j], x);
                a[i + j] = add(a[i + j], x);
            }
    return a;
}

vector<int> ifft(vector<int> a) {
    int n = a.size();
    int in = inv(n);
    a = fft(a);
    reverse(a.begin() + 1, a.end());
    for (int i = 0; i < n; i++)
        a[i] = mul(a[i], in);
    return a;
}

vector<int> poly_multiply(vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    if (n & (n - 1))
        n = 2 << lg[n];
    if (m & (m - 1))
        m = 2 << lg[m];
    int sz = max(n, m) << 1;
    a.resize(sz);
    b.resize(sz);
    a = fft(a);
    b = fft(b);
    for (int i = 0; i < sz; i++)
        a[i] = mul(a[i], b[i]);
    return ifft(a);
}

vector<int> strangeFFT(vector<int> a, vector<int> b) {
    int n = a.size();
    if (n & (n - 1)) {
        n = 2 << lg[n];
        a.resize(n);
        b.resize(n);
    }
    queue<pii> q;
    q.push({ 0, n });
    int last = -1;
    vector<int> ans(2 * n);
    while (!q.empty()) {
        int l, r;
        l = q.front().first;
        r = q.front().second;
        q.pop();
        if (last != r - l) {
            last = r - l;
            prepareFFT(r - l);
        }
        if (r - l == 1)
            continue;
        int m = (l + r) / 2;
        vector<int> al, br;
        for (int i = l; i < m; i++)
            al.push_back(a[i]);
        for (int i = m; i < r; i++)
            br.push_back(b[i]);
        vector<int> res = poly_multiply(al, br);
        for (int i = 0; i < r - l && i + l + m < (int) ans.size(); i++)
            ans[i + l + m] = add(ans[i + l + m], res[i]);
        q.push({ l, m });
        q.push({ m, r });
    }
    return ans;
}

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> pos(n);
    int leftest = n, rightest = -1;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        x--;
        leftest = min(leftest, x);
        rightest = max(rightest, x);
        pos[x] = 1;
    }
    vector<int> pw(2 * n);
    pw[0] = 1;
    for (int i = 1; i < 2 * n; i++)
        pw[i] = add(pw[i - 1], pw[i - 1]);
    vector<int> le(n), ri(n);
    for (int i = 0, cnt = 0; i < n; cnt += pos[i++])
        le[i] = pw[cnt];
    for (int i = n - 1, cnt = 0; i > -1; cnt += pos[i--])
        ri[i] = pw[cnt];
    for (int i = 0; i < n; i++)
        if (!pos[i])
            le[i] = 0, ri[i] = 0;
    vector<int> k = strangeFFT(le, ri);
    vector<int> p(n), pp(n);
    p[0] = a[0];
    pp[0] = 0;
    for (int i = 1; i < n; i++) {
        p[i] = add(p[i - 1], a[i]);
        pp[i] = add(pp[i - 1], mul(a[i], i));
    }
    int ans = 0;
    for (int s = 1; s < 2 * n; s++)
        ans = add(ans, mul(k[s], sub(add(pp[s / 2], pp[s / 2]), mul(s, p[s / 2]))));
    for (int i0 = 0; i0 < n; i0++)
        if (pos[i0] && i0 < rightest) {
            int x = ri[i0];
            x = sub(x, 1);
            int y = le[i0];
            int dif = sub(mul(i0, p[i0]), pp[i0]);
            ans = add(ans, mul(dif, mul(x, y)));
        }
    for (int j0 = 0; j0 < n; j0++)
        if (pos[j0] && j0 > leftest) {
            int x = ri[j0];
            int y = le[j0];
            y = sub(y, 1);
            int dif = sub(mul(j0, p[j0]), pp[j0]);
            ans = add(ans, mul(dif, mul(x, y)));
        }
    for (int i0 = 0; i0 < n; i0++)
        if (pos[i0]) {
            int x = le[i0];
            int pps = sub(pp[n - 1], pp[i0]);
            int ps = mul(i0, sub(p[n - 1], p[i0]));
            int dif = sub(pps, ps);
            ans = add(ans, mul(x, dif));
        }
    for (int j0 = 0; j0 < n; j0++)
        if (pos[j0]) {
            int y = ri[j0];
            int ps = mul(j0, p[j0]);
            int pps = pp[j0];
            int dif = sub(ps, pps);
            ans = add(ans, mul(y, dif));
        }
    //cout << ans << '\n';
    ans = mul(ans, inv(sub(pw[m], 1)));
    cout << ans << '\n';
}

signed main() {
    for (int i = 2; i < N; i++)
        lg[i] = lg[i >> 1] + 1;
#ifdef DEBUG
    freopen("01.dat", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt = 1;
#ifdef DEBUG
    cin >> tt;
#endif
    while (tt--) {
#ifdef DEBUG
        cout << "Testcase#\n";
#endif
        solve();
    }
    return 0;
}
