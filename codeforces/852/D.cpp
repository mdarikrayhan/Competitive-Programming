#include <bits/stdc++.h>
using namespace std;

void TC() {
    int n, m, _n, k;
    cin >> n >> m >> _n >> k;

    int start = n * 2, end = start | 1;
    auto inv = [&](int i) {
        return i + n;
    };
    vector<vector<int>> g(end + 1, vector<int>(end + 1));

    for(int i = 0, x; i < _n; i++) {
        cin >> x; x--;
        g[start][x]++;
    }
    for(int i = 0; i < n; i++) {
        g[inv(i)][end] = 1;
    }
//    vector<vector<pair<int, int>>> e(n);
    vector<vector<int>> e(n, vector<int>(n, 1e9));
    while(m--) {
        int u, v, w;
        cin >> u >> v >> w; u--, v--;
//        e[u].emplace_back(v, w);
//        e[v].emplace_back(u, w);
        e[u][v] = e[v][u] = min(e[v][u], w);
    }
    for(int i = 0; i < n; i++) e[i][i] = 0;
    for(int i = 0; i < n; i++) {
        for(int l = 0; l < n; l++) {
            for(int r = 0; r < n; r++) {
                if(e[l][r] > e[l][i] + e[i][r])
                    e[l][r] = e[l][i] + e[i][r];
            }
        }
    }
    auto good = [&](int mid) -> bool {
        auto rg = g;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                rg[i][inv(j)] = e[i][j] > mid? 0: INT_MAX;
            }
        }
        vector<int> par(end + 1);
        auto bfs = [&]() -> bool {
            std::fill(par.begin(), par.end(), -1);
            queue<int> q;
            q.emplace(start);
            par[start] = start;
            while(!q.empty()) {
                auto u = q.front(); q.pop();
                for(int v = 0; v <= end; v++) {
                    if(par[v] == -1 && rg[u][v] > 0) {
                        par[v] = u;
                        if(v == end) return true;
                        q.emplace(v);
                    }
                }
            }
            return false;
        };
        int mxFlow = 0;
        while(bfs()) {
            mxFlow++;
            int v = end;
            while(v != start) {
                int u = par[v];
                rg[u][v]--;
                rg[v][u]++;
                v = u;
            }
        }
        return mxFlow >= k;
    };
    int l = -1, r = 1731311;
    while(r > l + 1) {
        int mid = (l + r) >> 1;
        if(good(mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    if(!good(r))
        cout << "-1\n";
    else
        cout << r << '\n';
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
