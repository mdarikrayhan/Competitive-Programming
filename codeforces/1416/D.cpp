// LUOGU_RID: 160485265
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 500010;

struct Edge
{
    int a, b, c;
    bool operator< (const Edge& t) const {
        return c < t.c;
    }
} edge[N];
int n, m, q, cnt;
int l[N], r[N], w[N], p[N], sz[N], nw[N];
int fa[N][20], dep[N], dfn[N], pw[N], ts;
int tr[N << 2];
PII que[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int pa)
{
    dep[u] = dep[pa] + 1, fa[u][0] = pa, sz[u] = 1;
    dfn[u] = ++ ts, pw[ts] = w[u];
    for (int k = 1; k <= 19; k ++ )
        fa[u][k] = fa[fa[u][k - 1]][k - 1];
    if (!l[u]) return ;
    dfs(l[u], u), dfs(r[u], u);
    sz[u] += sz[l[u]] + sz[r[u]];
}

void build_kruskal()
{
    sort(edge + 1, edge + m + 1);
    cnt = n;
    for (int i = m; i; i -- )
    {
        int a = edge[i].a, b = edge[i].b, c = edge[i].c;
        a = find(a), b = find(b);
        if (a == b) continue;
        nw[ ++ cnt] = c;
        l[cnt] = a, r[cnt] = b;
        p[a] = p[b] = p[cnt] = cnt;
    }
    for (int i = 1; i <= n; i ++ )
        if (!dep[i]) dfs(find(i), 0);
}

void build(int u = 1, int l = 1, int r = cnt)
{
    if (l == r) tr[u] = pw[l];
    else
    {
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u] = max(tr[u << 1], tr[u << 1 | 1]);
    }
}

int query(int l, int r, int u = 1, int pl = 1, int pr = cnt)
{
    if (l <= pl && pr <= r) return tr[u];
    int mid = pl + pr >> 1, res = 0;
    if (l <= mid) res = query(l, r, u << 1, pl, mid);
    if (r > mid) res = max(res, query(l, r, u << 1 | 1, mid + 1, pr));
    return res;
}

void update(int l, int r, int x, int u = 1, int pl = 1, int pr = cnt)
{
    if (l <= pl && pr <= r)
    {
        if (pl == pr)
        {
            if (tr[u] == x) tr[u] = 0;
        }
        else
        {
            int mid = pl + pr >> 1;
            if (tr[u << 1] == x) update(l, r, x, u << 1, pl, mid);
            if (tr[u << 1 | 1] == x) update(l, r, x, u << 1 | 1, mid + 1, pr);
            tr[u] = max(tr[u << 1], tr[u << 1 | 1]);
        }
    }
    else
    {
        int mid = pl + pr >> 1;
        if (l <= mid) update(l, r, x, u << 1, pl, mid);
        if (r > mid) update(l, r, x, u << 1 | 1, mid + 1, pr);
        tr[u] = max(tr[u << 1], tr[u << 1 | 1]);
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i ++ )
        scanf("%d", &w[i]), p[i] = i;
    for (int i = 1, a, b; i <= m; i ++ )
    {
        scanf("%d%d", &a, &b);
        edge[i] = {a, b, (int)1e9};
    }
    
    for (int i = 1; i <= q; i ++ )
    {
        scanf("%d%d", &que[i].x, &que[i].y);
        if (que[i].x == 2) edge[que[i].y].c = i;
    }
    
    build_kruskal();
    build();
    
    for (int i = 1; i <= q; i ++ )
        if (que[i].x == 1)
        {
            int t = que[i].y;
            for (int k = 19; k >= 0; k -- )
                if (nw[fa[t][k]] >= i)
                    t = fa[t][k];
            int x = query(dfn[t], dfn[t] + sz[t] - 1);
            update(dfn[t], dfn[t] + sz[t] - 1, x);
            printf("%d\n", x);
        }
    
    return 0;
}
