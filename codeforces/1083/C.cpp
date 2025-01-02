// LUOGU_RID: 159051783
// LUOGU_RID: 159051507
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200005, M = (N << 1), inf = 1e16, mod = 1e9 + 7;
int n, q, tot, a[N], dep[N], anc[21][N], pos[N], dfn[N], siz[N], fa[N];
vector<int> G[N];
int top[N], h[N];
void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    anc[0][u] = fa;
    dfn[u] = ++ tot;
    siz[u] = 1;
    for (int v : G[u]) {
        dfs(v, u), siz[u] += siz[v];
        if (siz[v] > siz[h[u]]) h[u] = v;
    }
}
void dfs2(int u, int t) {
    top[u] = t;
    if (h[u]) dfs2(h[u], t);
    for (int i : G[u]) {
        if (i != h[u]) dfs2(i, i);
    }
}

int LCA(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            swap(u, v);
        }
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) return u;
    else return v;
}
struct SGT { int x, y, an; } t[N << 2];
int in(int x, int y) {
    return dfn[x] <= dfn[y] && dfn[y] < dfn[x] + siz[x];
}
int check(int x, int y, int z) {
    return in(z, x) && in(y, z);
}
pii check(vector<int> v) {
    int x = v[0], y = v[1], L = LCA(x, y);
    for (int i = 2; i < v.size(); i++) {
        int z = v[i];
        if (check(x, L, z) || check(y, L, z)) continue;
        if (x != L && y != L) {
            if (in(x, z)) {
                x = z;
                continue;
            }
            if (in(y, z)) {
                y = z;
                continue;
            }
            return {-1, -1};
        }
        if (y == L) swap(x, y);
        if (!in(x, z)) {
            x = z;
            L = LCA(x, y);
            continue;
        }
        if (in(y, z)) {
            y = z;
            continue;
        }
        if (LCA(z, y) == x) {
            x = z;
            continue;
        }
        return {-1, -1};
    }
    return {x, y};
}
SGT merge(SGT L, SGT R) {
    if (!L.an || !R.an) return {0, 0, 0};
    vector<int> ve;
    if (L.x) ve.push_back(L.x);
    if (R.x) ve.push_back(R.x);
    if (L.y) ve.push_back(L.y);
    if (R.y) ve.push_back(R.y);
    sort(ve.begin(), ve.end());
    ve.erase(unique(ve.begin(), ve.end()), ve.end());
    if (ve.size() == 1) return {ve[0], ve[0], 1};
    if (ve.size() == 2) return {ve[0], ve[1], 1};
    pii res = check(ve);
    if (res.first == -1) return {0, 0, 0};
    else return {res.first, res.second, 1};
}
void build(int p, int l, int r) {
    if (l == r) {
        t[p] = {pos[l], pos[l], 1};
        return ;
    }
    int mid = l + r >> 1;
    build(p * 2, l, mid),
    build(p * 2 + 1, mid + 1, r);
    t[p] = merge(t[p * 2], t[p * 2 + 1]);
}
void change(int p, int x, int l, int r) {
    if (l == r) {
        t[p] = {pos[x], pos[x], 1};
        return ;
    }
    int mid = l + r >> 1;
    if (x <= mid) change(p * 2, x, l, mid);
    else change(p * 2 + 1, x, mid + 1, r);
    t[p] = merge(t[p * 2], t[p * 2 + 1]);
}
int query(int p, int l, int r, SGT lst) {
    if (merge(lst, t[p]).an) return r + 1;
    if (l == r) return l;
    int mid = l + r >> 1;
    SGT now = merge(lst, t[p * 2]);
    if (!now.an) return query(p * 2, l, mid, lst);
    return query(p * 2 + 1, mid + 1, r, now);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    F(i, 1, n) {
        cin >> a[i];
        pos[++ a[i]] = i;
    }
    F(i, 2, n) {
        cin >> fa[i];
        G[fa[i]].push_back(i);
    }
    dfs(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    cin >> q;
    while (q --) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            swap(a[x], a[y]);
            pos[a[x]] = x, pos[a[y]] = y;
            change(1, a[x], 1, n);
            change(1, a[y], 1, n);
        } else {
            cout << query(1, 1, n, {0, 0, 1}) - 1 << '\n';
        }
    }
    return 0;
}
