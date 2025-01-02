#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void DFS(int v, vector<vector<int>> &adj,
         vector<int> &vis, vector<int> &cc) {
    vis[v] = 1;
    cc.push_back(v);
    for (int u : adj[v]) {
        if (!vis[u]) {
            DFS(u, adj, vis, cc);
        }
    }
}
int sol(int head, vector<vector<int>> &adj,
        vector<int> &cc, vector<int> dg,
        vector<int> &output, int write=0) {
    queue<int> q;
    q.push(head);
    for (int v : cc) {
        if (dg[v] == 0 && v != head) {
            q.push(v);
        }
    }
    int loop = (dg[head] > 0), count = 0;
    while (!q.empty()) {
        int v = q.front();
        ++count;
        q.pop();
        output.push_back(v);
        for (int u : adj[v]) {
            if (u == head) continue;
            --dg[u];
            if (dg[u] == 0) {
                q.push(u);
            }
        }
    }
    if (loop) {
        output.push_back(head);
    }
    int ans = output.size();
    if (count != cc.size()) ans = INF;
    if (!write) output.clear();
    return ans;
}
void solve(int testCase=1) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> undir(n + 1);
    vector<int> dg(n + 1);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        undir[u].push_back(v);
        undir[v].push_back(u);
        ++dg[v];
    }
    vector<int> vis(n + 1);
    vector<array<int, 2>> allOutput;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        vis[i] = 1;
        vector<int> cc;
        DFS(i, undir, vis, cc);
        vector<int> output;
        array<int, 2> ans = {INF, 0};
        for (int head : cc) {
            ans = min(ans, {sol(head, adj, cc, dg, output), head});
        }
        if (ans[0] == INF) {
            cout << "-1\n";
            return;
        }
        sol(ans[1], adj, cc, dg, output, 1);
        for (int j = 0; j < (int)output.size() - 1; ++j) {
            allOutput.push_back({output[j], output[j + 1]});
        }
    }
    cout << allOutput.size() << '\n';
    for (auto [u, v] : allOutput) {
        cout << u << ' ' << v << '\n';
    }
}
int main() {
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    solve();
    /*int t = 5;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }*/
}