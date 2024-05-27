#include <bits/stdc++.h>
 
using namespace std;

#define int long long
#define inf 0x3F3F3F3F3F3F3F3F

const int MXN = 3e5 + 5;

int n, m, X;
vector<array<int, 2>> adj[MXN];
int e[MXN], sum[MXN];
set<array<int, 2>> s;

int get(int x)
{
    if (e[x] < 0) return x;
    return e[x] = get(e[x]);
}
int unite(int x, int y)
{
    x = get(x), y = get(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    s.erase({sum[y], y}), s.erase({sum[x], x});
    sum[x] += sum[y] - X;
    assert(sum[x] >= 0);
    e[x] += e[y];
    e[y] = x;
    sum[y] = 0;
    if (adj[x].size() < adj[y].size()) swap(adj[x], adj[y]);
    for (array<int, 2> &z : adj[y]) adj[x].push_back(z);
    adj[y].clear();
    s.insert({sum[x], x});
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int S = 0;
    cin >> n >> m >> X;
    for (int i = 1; i <= n; i++) 
    {
        cin >> sum[i], e[i] = -1;
        s.insert({sum[i], i});
        S += sum[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    if (S < (n - 1) * X) 
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    while (s.size() > 1)
    {
        array<int, 2> e = *s.rbegin();
        assert(!adj[e[1]].empty());
        int x = adj[e[1]].back()[0], id = adj[e[1]].back()[1];
        adj[e[1]].pop_back();
        if (unite(e[1], x)) cout << id << '\n';
    }
}