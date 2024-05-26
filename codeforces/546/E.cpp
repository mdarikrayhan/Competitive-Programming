#include <bits/stdc++.h>
using namespace std;

int max_flow(vector<vector<int>> &g, int start, int end) {
    if(start == end) return INT_MAX;
    int n = int(g.size());
    vector<int> par(n);
    int mxFlow = 0;
    auto bfs = [&]() {
        std::fill(par.begin(), par.end(), -1);
        queue<int> q;
        q.emplace(start);
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(int v = 0; v < n; v++) {
                if(par[v] == -1 && g[u][v] > 0) {
                    par[v] = u;
                    if(v == end) return true;
                    q.emplace(v);
                }
            }
        }
        return false;
    };
    while(bfs()) {
        int res = INT_MAX, v = end;
        while(v != start) {
            int u = par[v];
            res = min(res, g[u][v]);
            v =  u;
        }
        mxFlow += res;
        v = end;
        while(v != start) {
            int u = par[v];
            g[u][v] -= res;
            g[v][u] += res;
            v =  u;
        }
    }
    return mxFlow;
}


void TC() {
    int n, m;
    cin >> n >> m;
    int start = n * 2, end = start + 1;
    vector<vector<int>> g(end + 1, vector<int>(end + 1));
    auto inv = [&](int i) {
        return i + n;
    };
    for(int i = 0, a; i < n; i++) {
        cin >> a;
        g[start][i] = a;
    }
    for(int i = 0, b; i < n; i++) {
        cin >> b;
        g[inv(i)][end] = b;
        g[i][inv(i)] = INT_MAX;
    }
    while(m--) {
        int u, v;
        cin >> u >> v; u--, v--;
        g[u][inv(v)] = g[v][inv(u)] = INT_MAX;
    }
    max_flow(g, start, end);
    for(int i = 0; i < n; i++) {
        if(g[start][i] != 0 || g[inv(i)][end] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << g[inv(j)][i] << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    for (int test = 1; test <= tc; ++test) {
        TC();
    }
//    cerr << clock() / 1000.0 << " Secs";
    return 0;
}
