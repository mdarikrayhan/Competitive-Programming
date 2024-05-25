#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 1e5 + 5;
vector<ll> g[N];
ll col[N];
bool inactive[N];
ll dist[N];
    ll n, m, k;
ll par[N];
void dfs(ll v)
{
    for (ll to : g[v])
        if (col[to] == -1)
            col[to] = col[v] ^ 1, dfs(to);
        else if (col[to] == col[v] and !inactive[to] and !inactive[v])
            inactive[v] = true;
}
void shortestcycle(ll s)
{
    for (ll i = 1; i <= n; i++) dist[i] = -1;
    dist[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty())
    {
        ll v = q.front();
        q.pop();
        for (ll to : g[v])
            if (dist[to] == -1)
                q.push(to), dist[to] = dist[v] + 1, par[to] = v;
            else if (to != par[v] and dist[to] + dist[v] + 1 <= k)
            {
                ll cur = to;
                vector<ll> ans, ans1;
                while (cur != s)
                    ans.push_back(cur), cur = par[cur];
                cur = v;
                while (cur != s)
                    ans1.push_back(cur), cur = par[cur];
                ans.push_back(s);
                ans1.push_back(s);
                ll last = -1;
                while (!ans.empty() and ans.back() == ans1.back())
                    last = ans.back(), ans.pop_back(), ans1.pop_back();
                ans.push_back(last);
                reverse(ans1.begin(), ans1.end());
                for (ll i : ans1)
                    ans.push_back(i);
                cout << ans.size() << endl;
                for (ll i : ans)
                    cout << i << " ";
                cout << endl;
                exit(0);
            }
    }
}
void solve()
{
    cin >> n >> m >> k;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (ll i = 1; i <= n; i++)
        col[i] = -1;
    for (ll i = 1; i <= n; i++)
        if (col[i] == -1)
            col[i] = 0, dfs(i);
    ll cnt[2];
    memset(cnt, 0, sizeof(cnt));
    for (ll i = 1; i <= n; i++)
        if (!inactive[i])
            cnt[col[i]]++;
    for (ll c = 0; c < 2; c++)
        if (cnt[c] >= (k + 1) / 2)
        {
            cout << "1\n";
            ll cur = 0;
            for (ll i = 1; i <= n and cur < (k + 1) / 2; i++)
                if (col[i] == c and !inactive[i])
                    cout << i << " ", cur++;
            cout << endl;
            return;
        }
    cout << "2\n";
    for (ll i = 1; i <= n; i++)
        if (inactive[i])
            shortestcycle(i);
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