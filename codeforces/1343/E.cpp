#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 2e5 + 5;
vector<ll> g[N];
ll dist[3][N], n;
void bfs(ll v, ll t)
{
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
        dist[t][i] = -1;
    q.push(v);
    dist[t][v] = 0;
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        for (ll to : g[v])
            if (dist[t][to] == -1)
                dist[t][to] = dist[t][v] + 1, q.push(to);
    }
}
void solve()
{
    ll m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    ll p[m];
    for (ll i = 0; i < m; i++)
        cin >> p[i];
    sort(p, p + m);
    for (ll i = 1; i <= n; i++)
        g[i].clear();
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(a, 0);
    bfs(b, 1);
    bfs(c, 2);
    ll ans = 1e18;
    for (ll i = 1; i < m; i++)
        p[i] += p[i - 1];
    auto sum = [&](ll l, ll r)
    {
        return l > r ? 0 : p[r] - (l - 1 < 0 ? 0 : p[l - 1]);
    };
    for (ll i = 1; i <= n; i++)
    {
        ll dst = dist[0][i] + dist[1][i] * 2 + dist[2][i], rep = dist[1][i];
        if (dst - 1 - rep < m)
            ans = min(ans, sum(0, rep - 1) + sum(0, dst - 1 - rep));
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t = 1;
    // precomp();
    cin >> t;
    for (ll cs = 1; cs <= t; cs++)
        solve();
    // cerr << "\nTime elapsed: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n";
}