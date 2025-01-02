#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define cnt first
#define h second
const int N = 1e6 + 5;
const int inf = 1e9 + 5;

bool maximize(auto &a, auto b) {
    if(a >= b) return true;
     a = b;
     return false;
}

bool minimize(auto &a, auto b) {
    if(a <= b) return true;
     a = b;
     return false;
}

int n, k, dep[N], f[N];
pii dp[N];
vector<int> g[N];

void dfs(int u) {
    dp[u].h = inf;
    if(g[u].empty()) {
        dp[u] = make_pair(1, dep[u]);
        return;
    }
    for(int v : g[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
        if(dp[v].h - dep[u] <= k) {
            dp[u].cnt += dp[v].cnt;
            minimize(dp[u].h, dp[v].h);
        }
    }
}

void calc(int u) {
    if(g[u].empty()) {
        f[u] = 1;
        return;
    }
    for(int v : g[u]) {
        calc(v);
        int res = dp[u].cnt;
        if(dp[v].h - dep[u] <= k) res -= dp[v].cnt;
        maximize(f[u], res + f[v]);
    }
}

void solve() {
    cin >> n >> k;
    for(int i = 2, p; i <= n; ++i) {
        cin >> p;
        g[p].push_back(i);
    }
    dfs(1);
    calc(1);
    cout << f[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
    // cin >> test;
    while(test--) solve();
    return 0;
}
// https://codeforces.com/contest/1065/problem/F