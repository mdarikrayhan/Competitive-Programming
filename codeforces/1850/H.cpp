#include <bits/stdc++.h>
#include <random>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define rep(i, j, n) for (int i = j; i < n; i++)
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define vi vector<int>
#define vvi vector <vi>
#define no cout << "NO\n";
#define yes cout << "YES\n";
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define debug(x) cout << "[" << #x << "] = [" << x << "] ";
#define nl cout << endl;
template <typename T> 
using heap = priority_queue<T, vector <T>, greater<T>>;
void solve();
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;
int32_t main(){
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << "ms\n";
    return 0;
}
bool dfs(int u, int x, vi &pos, vector <pii> adj[], vi &vis)
{
    vis[u] = 1;
    pos[u] = x;
    bool ans = true;
    for(auto [v, d] : adj[u])
    {
        if(vis[v])
        {
            ans &= (pos[v] == x + d);
        }
        else
        {
            ans &= dfs(v, x + d, pos, adj, vis);
        }
    }
    return ans;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector <pii> adj[n];
    rep(i, 0, m)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        if(a > b) d = -d, swap(a, b);
        adj[a].pb({b, d});
        adj[b].pb({a, -d});
    }
    bool ans = true;
    vector <int> pos(n, -1), vis(n, 0);
    for(int i = 0; i < n; i++)
    {
        if(vis[i]) continue;
        bool safe = dfs(i, 0, pos, adj, vis);
        ans &= safe;
    }
    if(ans) yes else no
}