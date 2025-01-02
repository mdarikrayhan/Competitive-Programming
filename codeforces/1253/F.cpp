#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;

const int N = 200010, M = 3 * N;

int n, m, k, q, cnt;
int h[N], e[M], w[M], ne[M], idx;
int l[N], r[N], p[N];
int fa[N][20], dep[N];
LL dist[N], nw[N];
bool st[N];
struct Edge
{
    int a, b;
    LL c;
    bool operator< (const Edge& t) const {
        return c < t.c;
    }
} edge[M];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for (int i = 1; i <= k; i ++ )
        heap.push({0ll, i}), dist[i] = 0;
    
    while (heap.size())
    {
        int t = heap.top().second;
        heap.pop();
        
        if (st[t]) continue;
        st[t] = true;
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (dist[ver] > dist[t] + w[i])
            {
                dist[ver] = dist[t] + w[i];
                heap.push({dist[ver], ver});
            }
        }
    }
}

void dfs(int u, int pa)
{
    dep[u] = dep[pa] + 1, fa[u][0] = pa;
    for (int k = 1; k <= 19; k ++ )
        fa[u][k] = fa[fa[u][k - 1]][k - 1];
    if (l[u]) dfs(l[u], u), dfs(r[u], u);
}

void build()
{
    for (int u = 1, k = 0; u <= n; u ++ )
        for (int i = h[u]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (ver < u)
                edge[ ++ k] = {u, ver, dist[u] + dist[ver] + w[i]};
        }
    
    sort(edge + 1, edge + m + 1);
    cnt = n;
    for (int i = 1; i <= m; i ++ )
    {
        int a = edge[i].a, b = edge[i].b;
        a = find(a), b = find(b);
        if (a == b) continue;
        nw[ ++ cnt] = edge[i].c;
        l[cnt] = a, r[cnt] = b;
        p[a] = p[b] = cnt;
    }
    dfs(cnt, 0);
}

LL lca(int a, int b)
{
    if (dep[a] < dep[b]) swap(a, b);
    for (int k = 19; k >= 0; k -- )
        if (dep[fa[a][k]] >= dep[b])
            a = fa[a][k];
    if (a == b) return nw[a];
    for (int k = 19; k >= 0; k -- )
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return nw[fa[a][0]];
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= 2 * n; i ++ ) p[i] = i;
    for (int i = 1; i <= m; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    
    dijkstra();
    build();
    
    while (q -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%lld\n", lca(a, b));
    }
    
    return 0;
}
