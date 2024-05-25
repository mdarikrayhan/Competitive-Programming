#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// UNSOLVED

// const ll mod = 1000000007;
// const ll mod = 998244353;
int n, x, y;
vector<vector<int>> edges;
vector<ll> v;
vector<pair<ll, ll>> dp;
ll ans = 0;

void dfs(int node, int parent) {
    for (int v : edges[node]) {
        if (v == parent) {
            continue;
        }
        dfs(v, node);
        dp[node].first = max(dp[node].first, dp[v].first);
        dp[node].second = max(dp[node].second, dp[v].second);
    }
    ll diff = dp[node].first - dp[node].second;
    v[node] += diff;
    if (v[node] < 0) {
        dp[node].first += -v[node];
    } else {
        dp[node].second += v[node];
    }
}

void solve() {
    cin >> n;
    edges.resize(n);
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--, y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // dp[i].first denotes increments required for node i + subtree rooted at node i
    // dp[i].second similarly denotes decrements
    dp.assign(n, {0, 0});
    // do dfs and assign dp values
    dfs(0, -1);
    ans = dp[0].first + dp[0].second;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
