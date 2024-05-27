// LUOGU_RID: 159802905
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5 + 5;

int T, n, m;
int fa[MAXN], ans[MAXN];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) fa[y] = x;
}

struct edge {
    int v, next, w;
} e[MAXN];

int eid, p[MAXN];

void insert(int u, int v, int w) {
    e[eid] = {v, p[u], w};
    p[u] = eid++;
}

void init() {
    eid = 0;
    for (int i = 0; i <= 2 * n; i++) {
        p[i] = -1, ans[i] = 0;
        fa[i] = i;
    }
}

void dfs(int u, int fa) {
    for (int i = p[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);
        if (find(u) == find(v) || find(u + n) == find(v + n)) {
            ans[i] = ans[i ^ 1] = 0;
            merge(u, v);
            merge(u + n, v + n);
        } else {
            ans[i] = ans[i ^ 1] = 1;
            merge(u, v + n);
            merge(v, u + n);
        }
    }
}

void solve() {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1, u, v, t; i < n; i++) {
        scanf("%d%d%d", &u, &v, &t);
        insert(u, v, t);
        insert(v, u, t);
        if (t != -1) {
            if (__builtin_popcount(t) & 1) {
                merge(u, v + n);
                merge(v, u + n);
            } else {
                merge(u, v);
                merge(u + n, v + n);
            }
        }
    }
    for (int i = 1, u, v, c; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        if (c) {
            merge(u, v + n);
            merge(v, u + n);
        } else {
            merge(u, v);
            merge(u + n, v + n);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (find(i) == find(i + n)) {
            puts("NO");
            return; 
        }
    }
    puts("YES");
    dfs(1, 0);
    for (int i = 0; i < eid; i += 2) {
        int v = e[i].v;
        int u = e[i ^ 1].v;
        int t = e[i].w;
        if (t != -1) printf("%d %d %d\n", u, v, t);
        else printf("%d %d %d\n", u, v, ans[i]);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) solve();
}