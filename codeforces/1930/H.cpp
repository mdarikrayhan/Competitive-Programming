// LUOGU_RID: 160223391
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> G[N];
int dfn1[N], rev1[N], dfn2[N], rev2[N], tot1, tot2;
int Fa[N], dep[N], siz[N], son[N], top[N], res;

void dfs(int x, int fa = 0) {
    siz[x] = 1, son[x] = 0, dfn1[x] = ++tot1, rev1[tot1] = x;
    for (auto v : G[x]) if (v != fa) dep[v] = dep[x] + 1, dfs(v, Fa[v] = x), siz[x] += siz[v], (siz[v] > siz[son[x]]) && (son[x] = v);
    dfn2[x] = ++tot2, rev2[tot2] = x;
}

void dfs2(int x) {
    for (auto v : G[x]) if (v != Fa[x]) top[v] = (v == son[x] ? top[x] : v), dfs2(v);
}

int LCA(int x, int y) {
    while (top[x] != top[y]) {
        int &t = (dep[top[x]] > dep[top[y]] ? x : y);
        t = Fa[top[t]];
    }
    return (dep[x] < dep[y] ? x : y);
}

int lst(int x, int y) {
    while (top[x] != top[y]) if (Fa[top[x]] == y) return top[x]; else x = Fa[top[x]];
    return son[y];
}

void query1(int x, int y) {
    if (x > y) return;
    printf("? 1 %d %d\n", x, y);
    fflush(stdout); scanf("%d", &x);
    res = min(res, x);
}

void query2(int x, int y) {
    if (x > y) return;
    printf("? 2 %d %d\n", x, y);
    fflush(stdout); scanf("%d", &x);
    res = min(res, x);
}

signed main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, q; scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 1, x, y; i < n; ++i) {
            scanf("%d%d", &x, &y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        tot1 = tot2 = 0;
        dfs(dep[1] = 1);
        dfs2(top[1] = 1);
        for (int i = 1; i <= n; ++i) printf("%d%c", rev1[i], " \n"[i == n]);
        for (int i = 1; i <= n; ++i) printf("%d%c", rev2[i], " \n"[i == n]);
        fflush(stdout);
        while (q--) {
            int x, y; scanf("%d%d", &x, &y);
            if (dfn1[x] > dfn1[y]) swap(x, y);
            res = n;
            int l = LCA(x, y), w = lst(y, l);
            if (l != x) {
                query2(1, dfn2[x] - 1);
                query2(dfn2[w] - siz[w] + 1, dfn2[y] - siz[y]);
                query2(dfn2[l] + 1, n);
                query1(dfn1[y] + 1, dfn1[l] + siz[l] - 1);
                query1(dfn1[x] + siz[x], dfn1[w] - 1);
            } else {
                query2(1, dfn2[y] - 1);
                query1(dfn1[y] + siz[y], n);
                query2(dfn2[x] + 1, n);
            }
            printf("! %d\n", res); fflush(stdout);
            scanf("%d", &res); assert(~res);
        }
    }
    return 0;
}