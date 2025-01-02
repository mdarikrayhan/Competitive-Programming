/*
Problem: 455C
Date: 25-05-2024 02:12 PM
*/


#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// merge two trees T1 and T2
// either diameter(T1) or diameter(T2) or radius(T1) + radius(T2) + 1.
// radius(T) = ceil(diameter(T) / 2).

const int N = 3e5 + 5;
int n, m, q, u, v, ty;
int dsu[N], diam[N];
vi adj[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    diam[x] = max({diam[x], diam[y], (diam[x] + 1) / 2 + (diam[y] + 1) / 2 + 1});
    dsu[x] += dsu[y];
    dsu[y] = x;
}

bool vis[N];
int dp[N], depth[N];

void dfs(int x) {
    vis[x] = true;
    vector<int> v;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = depth[x] + 1;
            dfs(y);
            dp[x] = max(dp[x], dp[y]);
            v.push_back(depth[y] - depth[x]);
        }
    }
    int d[2] = {0, 0};
    partial_sort_copy(v.begin(), v.end(), d, d + 2, greater<int>());
    depth[x] = d[0] + depth[x];
    dp[x] = max(dp[x], d[0] + d[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    fill(dsu + 1, dsu + n + 1, -1);
    fill(diam + 1, diam + n + 1, 0);
    rep(i, 0, m) {
        cin >> u >> v;
        join(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            dfs(i);
            diam[trace(i)] = dp[i];
        }
    }
    while(q--) {
        cin >> ty >> u;
        if(ty == 1) {
            cout << diam[trace(u)] << '\n';
        }else {
            cin >> v;
            join(u, v);
        }
    }
}