#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n, m; cin >> n >> m;

    v<v<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v<int> color(n), ans;
    auto dfs = [&](int u, int c, auto&& dfs) -> void {
        color[u] = c;
        for (int& i : adj[u])
            if (not color[i])
                dfs(i, (c == 1 ? 2 : 1), dfs);
    };
    dfs(0, 1, dfs);
    dbg(color);

    int ones = count(color.begin(), color.end(), 1ll);
    for (int i = 0; i < n; i++)
        if (color[i] == 1 and ones < n - ones)
            ans.push_back(i + 1);
        else if (color[i] == 2 and ones >= n - ones)
            ans.push_back(i + 1);
    
    cout << ans.size() << nl;
    for (int& a : ans)
        cout << a << " ";
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}