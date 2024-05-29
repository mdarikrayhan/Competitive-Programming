// Hydro submission #663f6bdc71c54d2b348d8c6d@1715433812435
#include <bits/stdc++.h>
#define P pair
#define fi first 
#define se second
#define eb emplace_back 
#define bg begin
#define vec vector
#define mst memset
#define ull unsigned long long
#define ll long long
using namespace std; const int N = 2e5 + 5; const ull B = 1145141;
int n, m, q, a[N], ord = 26, len, cnt[N], lg[N], sz[N], hd[N];
ull H[N], pw[N]; string s; vec<P<int, int>> g[N]; vec<ull> Hu[N], Hd[N];
struct range { int l, r, id; bool tp; }; vec<range> tmpx, tmpy, tmp; // 0 U 1 D
struct Query { int u, v, id, val; }; vec<Query> evt[N]; ll ans[N];
struct BinaryIndexedTree {
    #define lb(x) ((x) & (-(x)))
    ll sum[N]; void init() { mst(sum, 0, sizeof sum); }
    void modify(int x, int v) { for (; x <= len; x += lb(x)) sum[x] += v; }
    ll query(int x) { 
        ll ret = 0; for (; x; x -= lb(x)) ret += sum[x]; return ret;
    }
} bit;
struct SuffixArray {
    int rk[N], sa[N], ht[N], val[20][N]; P<P<int, int>, int> p[N], tmp[N];
    void init() {
        mst(rk, 0, sizeof rk); mst(val, 0, sizeof val); 
        mst(ht, 0, sizeof ht); mst(p, 0, sizeof p);
    }
    void Sort() {
        for (int i = 1; i <= len; ++i) ++cnt[a[i]];
        for (int i = 1; i <= ord; ++i) cnt[i] += cnt[i - 1];
        for (int i = 1; i <= len; ++i) rk[i] = cnt[a[i] - 1] + 1;
        for (int l = 1, id; l <= len; l <<= 1) {
            for (int i = 1; i <= len; ++i)
                p[i] = {{rk[i], i + l > len ? 0 : rk[i + l]}, i};
            mst(cnt, 0, sizeof cnt);
            for (int i = 1; i <= len; ++i) ++cnt[p[i].fi.se];
            for (int i = 1; i <= len; ++i) cnt[i] += cnt[i - 1];
            for (int i = len; i >= 1; --i) tmp[cnt[p[i].fi.se]--] = p[i];
            for (int i = 1; i <= len; ++i) p[i] = tmp[i];
            mst(cnt, 0, sizeof cnt);
            for (int i = 1; i <= len; ++i) ++cnt[p[i].fi.fi];
            for (int i = 1; i <= len; ++i) cnt[i] += cnt[i - 1];
            for (int i = len; i >= 1; --i) tmp[cnt[p[i].fi.fi]--] = p[i];
            for (int i = 1; i <= len; ++i) p[i] = tmp[i]; id = 0;
            for (int i = 1; i <= len; ++i) { 
                if (i == 1 || p[i].fi != p[i - 1].fi) ++id; rk[p[i].se] = id; 
            }
            if (id == len) break;
        }   
        for (int i = 1; i <= len; ++i) sa[rk[i]] = i;
    }
    void height() {
        for (int i = 1, k = 0; i <= len; ++i) {
            lg[i] = __lg(i); if (rk[i] == 1) { k = 0; continue; }
            if (k) --k; int j = sa[rk[i] - 1];
            for (; i + k <= len && j + k <= len && a[i + k] == a[j + k]; ++k); 
            val[0][rk[i]] = ht[i] = k;
        }
        for (int i = 1; (1 << i) <= len; ++i) 
            for (int j = 1; j + (1 << i) - 1 <= len; ++j)
                val[i][j] = min(val[i - 1][j], val[i - 1][j + (1 << (i - 1))]);
    }
    int LCP(int l, int r) {
        if (l == r) return len - sa[l] + 1;
        int k = lg[r - l]; return min(val[k][l + 1], val[k][r - (1 << k) + 1]);
    }
} SA;
ull HashA(int l, int r) { return H[r] - H[l - 1] * pw[r - l + 1]; }
ull HashU(int id, int l, int r) 
    { return Hu[id][l] - Hu[id][r + 1] * pw[r - l + 1]; }
ull HashD(int id, int l, int r)
    { return Hd[id][r] - Hd[id][l - 1] * pw[r - l + 1]; }
int dfn[N], idx, fa[N], siz[N], top[N], dep[N], hson[N], ed[N], val[N];
void dfs1(int u) {
    siz[u] = 1;
    for (auto v : g[u]) {
        if (v.fi == fa[u]) continue; val[v.fi] = v.se; 
        dep[v.fi] = dep[fa[v.fi] = u] + 1; dfs1(v.fi); siz[u] += siz[v.fi];
    }
}
void dfs2(int u) {
    for (auto v : g[u]) {
        if (v.fi == fa[u]) continue; 
        if (siz[v.fi] > siz[hson[u]]) hson[u] = v.fi;
    }
    for (auto v : g[u]) {
        if (v.fi == fa[u]) continue;
        if (v.fi == hson[u]) top[v.fi] = top[u]; else top[v.fi] = v.fi; 
        dfs2(v.fi); 
    }
}
void dfs3(int u) {
    dfn[u] = ++idx; if (hson[u]) dfs3(hson[u]); else ed[top[u]] = u;
    for (auto v : g[u])
        { if (v.fi == fa[u] || v.fi == hson[u]) continue; dfs3(v.fi); }
}
void CalD(int x) {
    int u = x; ull b = 0; Hd[x].eb(0);
    while (u) Hd[x].eb(b = b * B + val[u]), u = hson[u]; Hd[x].eb(0);
}
void CalU(int x) {
    int u = x; ull b = 0; Hu[top[x]].eb(0);
    while (top[u] == top[x]) Hu[top[x]].eb(b = b * B + val[u]), u = fa[u];
    Hu[top[x]].eb(0); reverse(Hu[top[x]].bg(), Hu[top[x]].end());
}
int get(int x) { return dfn[x] - dfn[top[x]] + 1; }
int length(range x) { return x.r - x.l + 1; }
int lca(int x, int y) {
    tmp.clear(), tmpx.clear(), tmpy.clear();
    while (top[x] != top[y]) {
        if (dep[top[x]] > dep[top[y]]) 
            tmpx.eb(range{1, get(x), top[x], 0}), x = fa[top[x]];
        else tmpy.eb(range{1, get(y), top[y], 1}), y = fa[top[y]];
    }
    reverse(tmpy.bg(), tmpy.end()); for (auto i : tmpx) tmp.eb(i);
    if (x != y)
        if (dep[x] < dep[y]) tmp.eb(range{get(x) + 1, get(y), top[x], 1});
        else tmp.eb(range{get(y) + 1, get(x), top[x], 0});
    for (auto i : tmpy) tmp.eb(i); return dep[x] < dep[y] ? x : y;
}
P<int, bool> check(int u, int v, int pos, int &dis) { // u -> v <= pos
    int anc = lca(u, v), p = pos - 1; 
    dis = dep[u] + dep[v] - (dep[anc] << 1); int pl = min(dis, len - p);
    for (auto i : tmp) {
        int pip = min(pos + pl - p - 1, length(i));
        if (i.tp)
            if (HashD(i.id, i.l, i.l + pip - 1) != HashA(p + 1, p + pip)) {
                int l = 1, r = pip, f = 0;
                while (l <= r) {
                    int md = (l + r) >> 1;
                    if (HashD(i.id, i.l, i.l + md - 1) == HashA(p + 1, p + md))
                        f = md, l = md + 1;
                    else r = md - 1;
                }
                return {p + f - pos + 1, 
                        HashD(i.id, i.l + f, i.l + f) < a[p + f + 1]};
            } else p += pip;
        else
            if (HashU(i.id, i.l, i.l + pip - 1) != HashA(p + 1, p + pip)) {
                int l = 1, r = pip, f = 0;
                while (l <= r) {
                    int md = (l + r) >> 1;
                    if (HashU(i.id, i.r - md + 1, i.r) == HashA(p + 1, p + md))
                        f = md, l = md + 1;
                    else r = md - 1;
                }
                return {p + f - pos + 1, 
                        HashU(i.id, i.r - f, i.r - f) < a[p + f + 1]};
            } else p += pip;
        if (p - pos + 1 == dis) return {dis, 1}; if (p - pos + 1 == pl) break;
    }
    return {pl, 0};
}
signed main() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0); cin >> n >> m >> q;
    for (int i = 1, u, v; i < n; ++i) {
        char c; cin >> u >> v >> c; 
        g[u].eb(v, c - 'a' + 1); g[v].eb(u, c - 'a' + 1);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> s; sz[i] = s.size(); hd[i] = len + 1;
        for (int j = 0; j < sz[i]; ++j) a[++len] = s[j] - 'a' + 1; 
        a[++len] = ++ord;
    }
    for (int i = pw[0] = 1; i <= len; ++i) 
        H[i] = H[i - 1] * B + a[i], pw[i] = pw[i - 1] * B;
    SA.init(); SA.Sort(); SA.height(); bit.init();
    for (int i = 1, l, r, u, v; i <= q; ++i) {
        cin >> u >> v >> l >> r; evt[hd[l] - 1].eb(Query{u, v, i, -1}); 
        evt[hd[r] + sz[r]].eb(Query{u, v, i, 1});
    }
    dfs1(1), dfs2(top[1] = 1), dfs3(1);
    for (int i = 1; i <= n; ++i)
        { if (i == top[i]) CalD(i); if (i == ed[top[i]]) CalU(i); }
    for (int i = 1; i <= len; ++i) {
        bit.modify(SA.rk[i], 1);
        for (auto j : evt[i]) {
            int l = 1, r = len, f = 0, d, o;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (check(j.u, j.v, SA.sa[mid], d).se) f = mid, r = mid - 1; 
                else l = mid + 1;
            }
            if (!f) continue; int k = check(j.u, j.v, SA.sa[f], d).fi;
            if (k < d) continue; l = f, r = len;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (SA.LCP(f, mid) >= d) o = mid, l = mid + 1; else r = mid - 1;
            }
            ans[j.id] += (bit.query(o) - bit.query(f - 1)) * j.val;
        }
    }
    for (int i = 1; i <= q; ++i) cout << ans[i] << '\n'; return 0;
}