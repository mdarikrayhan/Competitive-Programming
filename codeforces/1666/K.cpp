// Hydro submission #6655e55cbf5c09e48a997213@1716905308985
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 2010, M = 101000;
int s, t;
int head[N], to[M], nxt[M], tot = 2;
int dep[N], cur[N];
i64 val[M];

inline void Add(int u, int v, i64 w) {
    to[tot] = v, nxt[tot] = head[u], val[tot] = w, head[u] = tot++;
}

inline bool bfs() {
    queue<int> q;
    memset(dep, -1, sizeof(dep)), dep[s] = 0, q.push(s);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = head[p]; i; i = nxt[i])
            if (val[i] && dep[to[i]] == -1) dep[to[i]] = dep[p] + 1, q.push(to[i]);
    }
    return dep[t] != -1;
}
i64 dfs(int n, i64 fl) {
    if (n == t) return fl;
    i64 lf = fl;
    for (int &i = cur[n]; i; i = nxt[i])
        if (dep[to[i]] == dep[n] + 1 && val[i]) {
            i64 g = dfs(to[i], min(lf, (i64) val[i]));
            val[i] -= g, val[i ^ 1] += g, lf -= g;
            if (!lf) return fl;
        }
    return fl - lf;
}
inline i64 dinic() {
    i64 res = 0;
    while (bfs()) memcpy(cur, head, sizeof(head)), res += dfs(s, LONG_LONG_MAX);
    return res;
}

constexpr i64 inf = LONG_LONG_MAX / 2;

inline void addE(int u, int v, int l) {
    int u1 = u << 1, u2 = u << 1 | 1;
    int v1 = v << 1, v2 = v << 1 | 1;
    Add(u1, v2, l), Add(v2, u1, l);
    Add(u2, v1, l), Add(v1, u2, l);
}
inline void add(int u, int v, i64 w) {
    Add(u, v, w), Add(v, u, 0);
}
bool vis[M];
void dfs2(int n) {
    if (vis[n]) return;
    vis[n] = 1;
    for (int i = head[n]; i; i = nxt[i])
        if (val[i]) dfs2(to[i]);
}

int n, m, a, b;

int main() {
    assert(scanf("%d%d%d%d", &n, &m, &a, &b));
    for (int i = 0, u, v, w; i < m; i++) {
        assert(scanf("%d%d%d", &u, &v, &w));
        addE(u, v, w);
    }
    s = 0, t = 1;
    add(s, a << 1, inf), add(a << 1 | 1, t, inf);
    add(s, b << 1 | 1, inf), add(b << 1, t, inf);
    i64 res = dinic();
    printf("%lld\n", res);
    dfs2(s);
    for (int i = 1; i <= n; i++) {
        int x = vis[i << 1], y = vis[i << 1 | 1];
        if (x && !y) putchar('A');
        else if (!x && y) putchar('B');
        else putchar('C');
    }
    printf("\n");
    return 0;
}