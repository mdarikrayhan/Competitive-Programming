#define _CRT_SECURE_NO_DEPRECATE

#include <bits/stdc++.h>

using namespace std;
#define Ma7moud_7amdy ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Open_Sesame Open()
#define watch(x) cout << #x << " = " << x << endl;
#define endl "\n"
typedef long long ll;

void Open() {
#ifndef ONLINE_JUDGE
    freopen("standard.in", "r", stdin);
    freopen("standard.out", "w", stdout);
#endif
}

const int mod = ll(1e8), N = 1e6 + 5 + 2, oo = 0x3f3f3f3f;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    if (vis[node])return;
    vis[node] = 1;
    for (int nxt: adj[node]) {
        dfs(nxt, adj, vis);
    }
    return;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> ans;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            for (int j = m - 1; j >= 0; --j) {
                if (ans.empty() || ans.back().size() >= 2 && ans.size() < k)ans.push_back({});
                ans.back().push_back({i, j});
            }
        } else {
            for (int j = 0; j < m; ++j) {
                if (ans.empty() || (ans.back().size() >= 2 && ans.size() < k))ans.push_back({});
                ans.back().push_back({i, j});
            }
        }
    }

    for (auto &it: ans) {
        cout << it.size() << " ";
        for (auto i: it)cout << i.first + 1 << " " << i.second + 1 << " ";
        cout << endl;
    }
}

int main() {
    Ma7moud_7amdy;
    Open_Sesame;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}