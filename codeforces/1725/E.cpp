// LUOGU_RID: 160151674
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int mod = 998244353, inv = 499122177;
typedef long long ll;

int n, cnt;
int pr[MAXN], vis[MAXN];
int a[MAXN];
vector<int> val[MAXN];

void init() {
    vis[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        if (!vis[i]) pr[++cnt] = i;
        for (int j = 1; j <= cnt && i * pr[j] <= 200000; j++) {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0) break;
        }
    }
}

vector<int> g[MAXN];
int dep[MAXN], fa[MAXN];
int top[MAXN], sz[MAXN], son[MAXN];
int dfn[MAXN], idx;

void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    sz[u] = 1;
    son[u] = -1;
    for (int v : g[u]) {
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = ++idx;
    if (son[u] == -1) return;
    dfs2(son[u], t);
    for (int v : g[u]) {
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
    }
}

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    return x;
}

struct edge {
    int v, next;
} e[MAXN * 2];

int eid, p[MAXN];

void insert(int u, int v) {
    e[eid] = {v, p[u]};
    p[u] = eid++;
}

void add(int u, int v) {
    insert(u, v);
    insert(v, u);
}

int h[MAXN], tag[MAXN], k;
int st[MAXN], tp;
int ans, tmp;

void build() {
    sort(h + 1, h + k + 1, [](int x, int y) {
        return dfn[x] < dfn[y];
    });
    tp = 0;
    st[++tp] = 1;
    eid = 0;
    p[1] = -1;
    for (int i = 1; i <= k; i++)
        if (h[i] != 1) {
            int l = lca(h[i], st[tp]);
            if (l != st[tp]) {
                while (dfn[l] < dfn[st[tp - 1]]) {
                    add(st[tp], st[tp - 1]);
                    tp--;
                }
                if (l != st[tp - 1]) {
                    p[l] = -1;
                    add(st[tp], l);
                    tp--;
                    st[++tp] = l;
                } else {
                    add(st[tp], l);
                    tp--;
                }
            }
            p[h[i]] = -1;
            st[++tp] = h[i];
        }
    while (tp > 1) {
        add(st[tp], st[tp - 1]);
        tp--;
    }
}

void dfs(int u, int f) {
    sz[u] = tag[u];
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (v == f) continue;
        dfs(v, u);
        sz[u] += sz[v];
        int w = dep[v] - dep[u];
        tmp = (tmp + (ll)w * sz[v] % mod * (k - sz[v]) % mod) % mod;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    init();
    int V = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        val[a[i]].push_back(i);
        V = max(V, a[i]);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 1);
    dfs2(1, 1);
    for (int j = 1; j <= cnt; j++) {
        if (pr[j] > V) break;
        k = 0;
        for (int i = pr[j]; i <= V; i += pr[j]) {
            for (int x : val[i]) h[++k] = x;
        }
        for (int i = 1; i <= k; i++) {
            tag[h[i]] = 1;
        }
        build();
        tmp = 0, dfs(1, -1);
        ans = (ans + (ll)tmp * (k - 2) % mod * inv % mod) % mod;
        for (int i = 1; i <= k; i++) {
            tag[h[i]] = 0;
        }
    }
    printf("%d\n", ans);
}