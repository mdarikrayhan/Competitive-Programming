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

const int N = 20;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    v<bitset<N>> adj(N);
    for (int i = 0; i < n; i++) {
        if (s[i] > t[i]) {
            cout << -1 << nl;
            return;
        }
        if (s[i] - 'a' != t[i] - 'a')
            adj[s[i] - 'a'][t[i] - 'a'] = 1;
    }

    int ans = 0;
    for (int u = N - 1; u >= 0; u--) {
        bitset<N> vis;
        vis[u] = 1;
        for (int i = u + 1; i < N; i++)
            if (adj[u][i] and not vis[i]) {
                ans++;
                for (int j = u + 1; j < N; j++)
                    if (adj[j][i]) {
                        vis |= adj[j];
                        break;
                    }
            }
        adj[u] |= vis;
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while (T--) solve();
}