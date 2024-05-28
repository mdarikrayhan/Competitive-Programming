// LUOGU_RID: 159906100
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 505, M = 100005, inf = 1e16, mod = 1e9 + 7;
int n, m, a[N], ind[N], outd[N], mp[N][N];
int cnt = 1, head[M], lv[M], cur[M], vis[M], s, t;
struct edge {
    int v, w, nxt;
} e[M];
void add(int u, int v, int w) {
    e[++cnt] = {v, w, head[u]}; head[u] = cnt;
}
int dfs(int u = s, int flow = inf) {
    if (u == t) return flow;
    int res = flow;
    for (int i = cur[u]; i && res > 0; i = e[i].nxt) {
        cur[u] = i;
        int v = e[i].v, w = e[i].w, c;
        if (w > 0 && lv[v] == lv[u] + 1) {
            c = dfs(v, min(res, w));
            res -= c, e[i].w -= c, e[i ^ 1].w += c;
        }
    }
    return flow - res;
}
int bfs() {
    queue<int> q;
    memset(lv, -1, sizeof lv);
    memcpy(cur, head, sizeof cur);
    q.push(s), lv[s] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if (w > 0 && lv[v] == -1)
                lv[v] = lv[u] + 1, q.push(v);
        }
    }
    return lv[t] != -1;
}
int dinic() {
    int res = 0;
    while (bfs())
        res += dfs();
    return res;
}
struct EDGE {
    int u, v;
} E[M];
int solve(int v) {
    int res = ind[v] + outd[v], tt = 0;
    // F(i, 1, n) {
    //     if (!mp[i][v]) res ++;
    //     if (!mp[v][i]) res ++;
    // }
    cnt = 1;
    memset(head, 0, sizeof head);
    memset(e, 0, sizeof e);
    s = 0, t = 10000;
    F(i, 1, n) {
        add(s, i, 1);
        add(i, s, 0);
        add(i + 500, t, 1);
        add(t, i + 500, 0);
    }
    F(i, 1, m) {
        if (E[i].u == v || E[i].v == v) continue ;
        add(E[i].u, E[i].v + 500, 1);
        add(E[i].v + 500, E[i].u, 0);
    }
    int ans = dinic();
    // return res + n - 1 - ans;
    return n - 1 - ans + m - ans + 2 * n - 1 - res * 2;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    F(i, 1, m) {
        int a, b;
        cin >> a >> b;
        E[i] = {a, b};
        mp[a][b] = 1;
        ind[b] ++;
        outd[a] ++;
        if (a == b) {
            ind[a] --;
        }
    }
    int an = inf;
    F(v, 1, n) {
        an = min(an, solve(v));
    }
    cout << an;
    return 0;
}
