#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
    }
    int scc = 0;
    vector<int> col(n, -1);
    vector<vector<int>> com;
    {
        vector<int> stk, num(n, -1), low(n);
        int cnt = 0;
        function<void(int)> DFS = [&](int u) {
            num[u] = low[u] = cnt++;
            stk.push_back(u);
            for (int v : adj[u]) {
                if (col[v] != -1) {
                    continue;
                }
                if (num[v] == -1) {
                    DFS(v);
                    low[u] = min(low[u], low[v]);
                } else {
                    low[u] = min(low[u], num[v]);
                }
            }
            if (low[u] == num[u]) {
                com.push_back({});
                while (col[u] == -1) {
                    int x = stk.back(); stk.pop_back();
                    col[x] = scc;
                    com.back().push_back(x);
                }
                scc++;
            }
        };
        for (int i = 0; i < n; i++) {
            if (num[i] == -1) {
                DFS(i);
            }
        }
    }
    auto ask = [](int a, int b) {
        cout << "? " << a + 1 << " " << b + 1 << endl;
        int ret; cin >> ret;
        assert(ret != -1);
        return ret;
    };
    vector<int> deg(scc), rep(scc);
    set<int> se;
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            if (col[u] != col[v]) {
                deg[col[v]]++;
            }
        }
    }
    for (int i = 0; i < scc; i++) {
        if (deg[i] == 0) {
            se.insert(i);
        }
    }
    int cur = *se.begin();
    while (se.size() > 1) {
        se.erase(cur);
        int oth = *se.begin(); se.erase(oth);
        for (; rep[cur] < com[cur].size() && rep[oth] < com[oth].size(); ) {
            rep[ask(com[cur][rep[cur]], com[oth][rep[oth]]) ? oth : cur]++;
        }
        if (rep[cur] == com[cur].size()) {
            swap(cur, oth);
        }
        se.insert(cur);
        for (int u : com[oth]) {
            for (int v : adj[u]) {
                if (col[u] != col[v] && --deg[col[v]] == 0) {
                    se.insert(col[v]);
                }
            }
        }
    }
    cout << "! " << com[cur][rep[cur]] + 1 << endl;
}