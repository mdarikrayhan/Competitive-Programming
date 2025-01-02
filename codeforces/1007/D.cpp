// LUOGU_RID: 157417364
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 6e6 + 5;
int n, m, sz[N], de[N], fa[N], son[N], dfn, id[N], top[N];
vector <int> tr[N];
void dfs1(int u, int f)
{
    fa[u] = f; sz[u] = 1; de[u] = de[f] + 1;
    for (int v : tr[u])
    {
        if (v == f) continue;
        dfs1(v, u); sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int tp)
{
    top[u] = tp; id[u] = ++dfn;
    if (!son[u]) return;
    dfs2(son[u], tp);
    for (int v : tr[u])
    {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
vector <int> pnt[N << 2], g[M];
int L, R, k, cnt;
#define mid (l + r >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
inline void add(int u, int v)
{
    g[u].push_back(v);
    g[v^1].push_back(u^1);
}
void insert(int p, int l, int r)
{
    if (L <= l && r <= R) return pnt[p].push_back(k);
    if (L <= mid) insert(ls, l, mid);
    if (R > mid) insert(rs, mid + 1, r);
}
void modify(int u, int v)
{
    while (top[u] != top[v])
    {
        if (de[top[u]] < de[top[v]]) swap(u, v);
        L = id[top[u]]; R = id[u]; insert(1, 2, n);
        u = fa[top[u]];
    }
    if (u != v)
    {
        if (de[u] > de[v]) swap(u, v);
        L = id[u] + 1; R = id[v]; insert(1, 2, n);
    }
}
void build(int p, int l, int r, int o)
{
    int s = pnt[p].size(), r1 = ++cnt, r2 = (cnt += s);
    if (s) add((r2 - 1) << 1, r2 << 1);
    else if (o) add(o << 1, r2 << 1);
    for (int i = 0; i < s; i++)
    {
        int nd = pnt[p][i]; add(nd, (r1 + i) << 1);
        if (i) add((r1 + i - 1) << 1, (r1 + i) << 1), add((r1 + i - 1) << 1, nd ^ 1);
        else if (o) add(o << 1, r1 << 1), add(o << 1, nd ^ 1);
    }
    if (l == r) return;
    build(ls, l, mid, r2); build(rs, mid + 1, r, r2);
}
int tot, num[M], low[M], of[M], _dfn;
stack <int> sta;
void dfs(int u)
{
    low[u] = num[u] = ++_dfn;
	sta.push(u);
	for (int v : g[u])
	{
		if (!num[v]) dfs(v), low[u] = min(low[u], low[v]); 
		else if (!of[v]) low[u] = min(low[u], num[v]);
	}
	if (num[u] == low[u])
	{
		tot++;
		int v;
		do v = sta.top(), sta.pop(), of[v] = tot;
		while (v != u);
	}
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
		int u, v; cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	dfs1(1, 1); dfs2(1, 1);
    cin >> m;
	for (int i = 1; i <= m; i++)
    {
        int u1, v1, u2, v2;
		cin >> u1 >> v1 >> u2 >> v2;
        k = (i << 1); modify(u1, v1);
		k ^= 1; modify(u2, v2);
	}
	cnt = m; build(1, 2, n, 0);
	for (int i = 1; i <= (cnt << 1); i++) if (!num[i]) dfs(i);
	for (int i = 1; i <= m; i++) if (of[i<<1] == of[i<<1|1]) return cout << "NO\n", 0;
	cout << "YES\n";
	for (int i = 1; i <= m; i++) cout << (of[i << 1] < of[i << 1 | 1] ? 1 : 2) << "\n";
    return 0;
}