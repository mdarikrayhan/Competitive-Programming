#include <bits/stdc++.h>
using namespace std;
#define GO       \
    cin.tie(0);  \
    cout.tie(0); \
    ios::sync_with_stdio(0)
typedef long long ll;
const ll N = 400000;

ll n, m;
vector<vector<char>> grid;
vector<ll> in[N], out[N], adj[N], top_sort;
ll label[N], in_degree[N];
bool mark[N];

void dfs_out(ll u)
{
    mark[u] = 1;
    for (auto v : out[u])
    {
        if (!mark[v])
        {
            dfs_out(v);
        }
    }
    top_sort.push_back(u);
}

void dfs_in(ll u, ll comp)
{
    mark[u] = 1;
    label[u] = comp;
    for (auto v : in[u])
    {
        if (!mark[v])
        {
            dfs_in(v, comp);
        }
    }
}

void dfs(ll u)
{
    mark[u] = 1;
    for (auto v : out[u])
    {
        if (!mark[v])
        {
            if (label[u] != label[v])
            {
                adj[label[u]].push_back(label[v]);
                in_degree[label[v]]++;
            }
            else
            {
                dfs(v);
            }
        }
    }
}

int main()
{
    GO;
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    for (ll i = 0; i < n * m; i++)
    {
        label[i] = i;
    }
    ll dots = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            dots += (grid[i][j] == '.');
        }
    }
    ll a[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (ll j = 0; j < m; j++)
    {
        for (ll i = 0; i < n; i++)
        {
            if (grid[i][j] == '#')
            {
                ll u = i * m + j;
                if (i - 1 >= 0 && grid[i - 1][j] == '#')
                {
                    ll v = (i - 1) * m + j;
                    out[u].push_back(v);
                    in[v].push_back(u);
                }
                for (ll k = i + 1; k < n; k++)
                {
                    if (grid[k][j] == '#')
                    {
                        ll v = k * m + j;
                        out[u].push_back(v);
                        in[v].push_back(u);
                        break;
                    }
                }
                bool l = 1, r = 1;
                for (ll k = i; k < n && (r || l) && (grid[k][j] != '#' || k == i); k++)
                {
                    if (l && j - 1 >= 0 && grid[k][j - 1] == '#')
                    {
                        l = 0;
                        ll v = k * m + (j - 1);
                        out[u].push_back(v);
                        in[v].push_back(u);
                    }
                    if (r && j + 1 < m && grid[k][j + 1] == '#')
                    {
                        r = 0;
                        ll v = k * m + (j + 1);
                        out[u].push_back(v);
                        in[v].push_back(u);
                    }
                }
            }
        }
    }
    for (ll u = 0; u < n * m; u++)
    {
        if (!mark[u])
        {
            dfs_out(u);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    fill(mark, mark + n * m, 0);
    ll comp = 0;
    for (ll i = 0; i < n * m; i++)
    {
        ll u = top_sort[i];
        if (!mark[u])
        {
            dfs_in(u, comp++);
        }
    }
    fill(mark, mark + n * m, 0);
    for (ll i = 0; i < n * m; i++)
    {
        ll u = top_sort[i];
        if (!mark[u])
        {
            dfs(u);
        }
    }
    ll ans = -dots;
    for (ll i = 0; i < comp; i++)
    {
        ans += (in_degree[i] == 0);
    }
    cout << ans;
    return 0;
}