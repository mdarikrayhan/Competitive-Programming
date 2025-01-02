// LUOGU_RID: 160600545
/**
 * @author : cyb1010
 * @date   : 2024-05-29 09:31:48
 * @file   : Sharti.cpp
 */
#include <bits/stdc++.h>
using namespace std;
#define fo(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
#define fi first
#define se second
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9 + 10;
int __, n, m, k, rt, lsx, tot, ans;
struct T {
    int x, d, u;
    bool sgn;
    T() {}
    T(int _x, int _d, int _u, bool _sgn) : x(_x), d(_d), u(_u), sgn(_sgn) {}
};
vector<T> g;
struct node {
    int l, r, cnt, tot;
} t[10000010];
void add(int &p, int l, int r, int le, int ri) {
    if (l > ri || r < le) return;
    if (!p) p = ++tot;
    if (l >= le && r <= ri) {
        if (!t[p].tot++) t[p].cnt = r ^ (l - 1);
        return;
    }
    int mid = l + r >> 1;
    add(t[p].l, l, mid, le, ri), add(t[p].r, mid + 1, r, le, ri);
    if (!t[p].tot) t[p].cnt = t[t[p].l].cnt ^ t[t[p].r].cnt;
}
void del(int p, int l, int r, int le, int ri) {
    if (l > ri || r < le) return;
    if (l >= le && r <= ri) {
        if (!--t[p].tot) t[p].cnt = t[t[p].l].cnt ^ t[t[p].r].cnt;
        return;
    }
    int mid = l + r >> 1;
    del(t[p].l, l, mid, le, ri), del(t[p].r, mid + 1, r, le, ri);
    if (!t[p].tot) t[p].cnt = t[t[p].l].cnt ^ t[t[p].r].cnt;
}
int main() {
    // fo("Sharti");
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k, k = 1 << __lg(k), g.resize(m << 1);
    for (int i = 0, a, b, c, d; i < m; i++) {
        cin >> a >> b >> c >> d, a--;
        g[i << 1] = T(a, b, d, 1), g[i << 1 | 1] = T(c, b, d, 0);
    }
    sort(g.begin(), g.end(), [&](T x, T y) { return x.x < y.x; });
    lsx = g[0].x;
    for (int i = 0; i < (m << 1); i++) {
        if (lsx < g[i].x) {
            int ty = t[rt].cnt, tx = g[i].x ^ lsx;
            ty = ty ^ (ty >> 1), tx = tx ^ (tx >> 1);
            for (int j = 0; j <= 30; j++) {
                int tot = 0;
                if ((ty >> j) & 1) tot ^= __builtin_popcount(tx >> j);
                if ((tx >> j) & 1) tot ^= __builtin_popcount(ty >> j + 1);
                if (tot & 1) ans ^= min(k, 1 << j);
            }
            lsx = g[i].x;
        }
        g[i].sgn ? add(rt, 1, inf, g[i].d, g[i].u)
                 : del(rt, 1, inf, g[i].d, g[i].u);
    }
    cout << (ans ? "Hamed\n" : "Malek\n");
    return 0 ^ __ ^ 0;
}