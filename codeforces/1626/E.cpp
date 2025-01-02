#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 3e5 + 5;
vector<ll> g[N];
ll c[N];
ll dp[N];
ll sub[N];
bool ans[N];
void dfs(ll v, ll par = 0)
{
    dp[v] = c[v];
    sub[v] = c[v];
    for (ll to : g[v])
        if (to != par)
        {
            dfs(to, v);
            sub[v] += sub[to];
            if (sub[to] >= 2 or c[to])  dp[v] += !!dp[to];
        }
}
void dfs1(ll v, ll par = 0)
{
    if (par)
    {
        dp[v] += sub[1] - sub[v] >= 2 or c[par] ? !!(dp[par] - ((sub[v] >= 2 or c[v]) and !!dp[v])) : 0;
        ans[v] = !!dp[v];
    }
    else
        ans[v] = !!dp[v];
    for (ll to : g[v])
        if (to != par)
            dfs1(to, v);
}
void solve()
{
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> c[i];
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    dfs1(1);
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // precomp();
    // cin >> t;
    for (ll cs = 1; cs <= t; cs++)
        solve();
    // cerr << "\nTime elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n";
}