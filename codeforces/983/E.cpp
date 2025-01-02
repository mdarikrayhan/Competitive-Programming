#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define inf 0x3F3F3F3F3F3F3F3F

const int MXN = 2e5 + 5;
const int LOG = 18;

int n, m;
vector<int> adj[MXN], qq[MXN];
int p[LOG][MXN], np[LOG][MXN];
multiset<int> A[MXN], B[MXN];
int dep[MXN];
int in[MXN], out[MXN], tim = -1, rein[MXN];
int up[MXN];
int ANS[MXN];
int NO[MXN];

int anc(int u, int v)
{
    return in[u] <= in[v] && out[v] <= out[u];
}
int LCA(int u, int v)
{
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (anc(p[i][u], v)) continue;
        u = p[i][u];
    }
    return p[0][u];
}
void _dfs(int a)
{
    in[a] = ++tim;
    rein[tim] = a;
    for (int v : adj[a])
    {
        dep[v] = dep[a] + 1;
        _dfs(v);
    }
    out[a] = tim;
}

void dfs1(int a)
{
    for (int v : adj[a])
    {
        dfs1(v);
        if (up[v]) up[a] = (up[a] ? (dep[up[v]] < dep[up[a]] ? up[v] : up[a]) : up[v]);
    }
}

vector<array<int, 3>> q;

void getans(int u, int v, int id)
{
    if (anc(v, u)) swap(u, v);
    int f = anc(u, v);
    int ans = 0;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (!np[i][u] || anc(np[i][u], v)) continue;
        u = np[i][u];
        ans += (1LL << i);
    }
    if (!f && !np[0][u]) 
    {
        ANS[id] = -1;
        q.push_back({-1, -1, -1});
        return;
    }
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (!np[i][v] || anc(np[i][v], u)) continue;
        v = np[i][v];
        ans += (1LL << i);
    }
    if (!np[0][v]) 
    {
        ANS[id] = -1;
        q.push_back({-1, -1, -1});
        return;
    }
    if (f)
    {
        ANS[id] = ans + 1;
        q.push_back({-1, -1, -1});
        return;
    }
    q.push_back({u, v, id});
    ANS[id] = ans + (!f);
}

void dfs(int a)
{
    for (int v : adj[a])
    {
        dfs(v);
        if (A[v].size() > A[a].size()) swap(A[v], A[a]);
        for (int x : A[v]) A[a].insert(x);
        A[v].clear();
    }
    for (int i : qq[a])
    {
        auto it = A[a].lower_bound(in[q[i][1]]);
        if ((it == A[a].end() || *it > out[q[i][1]])) ANS[i]++;
    }
}

signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[0][1] = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[0][i];
        adj[p[0][i]].push_back(i);
    }
    for (int i = 1; i < LOG; i++) for (int j = 1; j <= n; j++) p[i][j] = p[i - 1][p[i - 1][j]];
    vector<array<int, 2>> pa;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        pa.push_back({a, b});
    }
    _dfs(1);
    for (array<int, 2> &x : pa)
    {
        int a = x[0], b = x[1];
        A[x[0]].insert(in[x[1]]);
        A[x[1]].insert(in[x[0]]);
        int lca = LCA(a, b);
        up[a] = (up[a] ? (dep[lca] < dep[up[a]] ? lca : up[a]) : lca);
        up[b] = (up[b] ? (dep[lca] < dep[up[b]] ? lca : up[b]) : lca);
    }
    dfs1(1);
    for (int i = 1; i <= n; i++) 
    {
        if (dep[up[i]] >= dep[i]) up[i] = 0;
        np[0][i] = up[i];
    }
    for (int i = 1; i < LOG; i++) for (int j = 1; j <= n; j++) np[i][j] = np[i - 1][np[i - 1][j]];
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int u, v;
        cin >> u >> v;
        getans(u, v, i);
    }
    for (array<int, 3> &x : q)
    {
        if (x[0] != -1)
        qq[x[0]].push_back(x[2]);
    }
    dfs(1);
    for (int i = 0; i < Q; i++) cout << ANS[i]  << '\n';
}
