#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// Ofast, O0, O1, O2, O3, unroll-loops, fast-math, trapv

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define Mp          make_pair
#define sep         ' '
#define endl        '\n'
#define F	        first
#define S	        second
#define pb          push_back
#define SZ(x)       (int)x.size()
#define all(x)      (x).begin(),(x).end()
#define kill(res)	cout << res << '\n', exit(0);
#define set_dec(x)	cout << fixed << setprecision(x);
#define fast_io     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io     freopen("input.txt", "r", stdin) ; freopen("output.txt", "w", stdout);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll N = 3e5 + 50;
const ll Mod = 1e9 + 7;

int n, m, k, cnt[N], c[N], w[N], high[N], h[N], col[N], cc;
ll dp[N], up[N], val[N];

bool mark[N], cut[N];
vector<pii> edge, adj[N], g[N];

void dfs(int v, int p = 0, int e = -1){
    high[v] = h[v];
    mark[v] = true;
    for(auto [u, id]: adj[v]){
        if(mark[u]){
            if(u != p) high[v] = min(high[v], h[u]);
            continue;
        }
        h[u] = h[v] + 1; dfs(u, v, id);
        high[v] = min(high[v], high[u]);
        cnt[v] += cnt[u];
    }
    if(high[v] >= h[v] && cnt[v] && cnt[v] < k) cut[e] = true;
}

void fillcomp(int v){
    col[v] = cc;
    val[cc] += c[v];

    mark[v] = true;
    for(auto [u, id]: adj[v]){
        if(!mark[u] && !cut[id]) fillcomp(u);
    }
}

void filldown(int v, int p = 0){
    dp[v] = val[v];
    for(auto [u, id]: g[v]){
        if(u == p) continue;
        filldown(u, v);
        dp[v] += max(0ll, dp[u] - w[id]);
    }
}

void fillup(int v, int p = 0, int e = -1){
    ll sum = 0;
    for(auto [u, id]: g[v]){
        if(u == p) continue;
        sum += max(0ll, dp[u] - w[id]);
    }
    for(auto [u, id]: g[v]){
        if(u == p) continue;
        up[u] = val[v] + sum - max(0ll, dp[u] - w[id]) + up[v];
        up[u] = max(0ll, up[u] - w[id]);
        fillup(u, v, id);
    }
}

int main(){
    fast_io;
    
    cin >> n >> m >> k;

    for(int i = 1; i <= k; i++){
        int v; cin >> v; cnt[v]++;
    }

    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < m; i++) cin >> w[i];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        edge.pb({u, v});
    }

    dfs(1);

    fill(mark, mark + N, false);

    for(int i = 1; i <= n; i++){
        if(!mark[i]){
            cc++; fillcomp(i);
        }
    }

    for(int i = 0; i < m; i++){
        if(!cut[i]) continue;
        int u = col[edge[i].F];
        int v = col[edge[i].S];
        g[u].pb({v, i});
        g[v].pb({u, i});
    }

    filldown(1);
    fillup(1);

    for(int i = 1; i <= n; i++) cout << up[col[i]] + dp[col[i]] << sep;

}
