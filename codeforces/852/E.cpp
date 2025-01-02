#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);

using namespace std;

const int mod = 1e9 + 7;

int mexp(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n % 2 != 0) res = (res * a) % mod, n--;
        a = (a * a) % mod, n /= 2;
    }

    return res;
}

signed main() {
    fastio()

    int n;
    cin >> n;

    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }

    vector<int> dp(n, 1);
    function<void(int, int)> dfs = [&](int node, int par) {
        for (auto &x : adj[node]) {
            if (x != par) {
                dfs(x, node);
                dp[node] = (dp[node] * dp[x]) % mod;
            }
        }

        if (node == 0 || size(adj[node]) != 1) dp[node] = (dp[node] * 2) % mod;
    };

    dfs(0, -1);

    auto apply = [&](int node, int x) {
        dp[node] = (dp[node] * mexp(dp[x], mod - 2)) % mod;
        if (size(adj[node]) == 1) dp[node] = (dp[node] * mexp(2, mod - 2)) % mod;
        dp[x] = (dp[x] * dp[node]) % mod;
        if (size(adj[x]) == 1) dp[x] = (dp[x] * 2) % mod;
    };

    int ans = 0;
    function<void(int, int)> dfs2 = [&](int node, int par) {
        ans = (ans + dp[node]) % mod;

        for (auto &x : adj[node]) {
            if (x != par) {
                apply(node, x);
                dfs2(x, node);
                apply(x, node);
            }
        }
    };

    dfs2(0, -1);

    cout << ans << endl;

    return 0;
}