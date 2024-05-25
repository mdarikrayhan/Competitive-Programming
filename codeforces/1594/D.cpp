#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'
const int mod = 1000000007;
// clang-format off
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// clang-format on

bool dfs(int u, int n, int col, int &cnt0, int &cnt1, vector<vector<int>> &g, vector<bool> &vis, vector<int> &color)
{
    vis[u] = 1;
    color[u] = col;
    if (u <= n)
    {
        cnt0 += (col == 0);
        cnt1 += (col == 1);
    }
    for (auto &v : g[u])
    {
        if (!vis[v])
        {
            bool f = dfs(v, n, !col, cnt0, cnt1, g, vis, color);
            if (!f)
                return 0;
        }
        else
        {
            if (color[u] == color[v])
                return 0;
        }
    }
    return 1;
}
void solve()
{
    ll t, m, n, a, b;
    string h;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> h;
        if (h == "crewmate")
        {
            g.push_back({});
            g[a].push_back(g.size() - 1);
            g.back().push_back(b);
            g[b].push_back(g.size() - 1);
            g.back().push_back(a);
        }
        else
        {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    dbg(g);
    vector<bool> vis(g.size() + 1);
    vector<int> color(g.size() + 1, -1);
    int ans = 0, cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bool f = dfs(i, n, 0, cnt0, cnt1, g, vis, color);
            if (!f)
            {
                cout << "-1\n";
                return;
            }
            dbg(color);
            // int cnt0 = count(color.begin() + 1, color.begin() + n + 1, 0);
            // int cnt1 = count(color.begin() + 1, color.begin() + n + 1, 1);
            ans += max(cnt0, cnt1);

            cnt0 = 0, cnt1 = 0;
            // color = vector<int>(g.size() + 1, -1);
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}