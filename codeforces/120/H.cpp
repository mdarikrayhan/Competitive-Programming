#include <bits/stdc++.h>
using namespace std;

int max_flow(vector<vector<bool>> &g, int start, int end) {
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
                if(par[v] == -1 && g[u][v]) {
                    par[v] = u;
                    if(v == end) return true;
                    q.emplace(v);
                }
            }
        }
        return false;
    };
    while(bfs()) {
        int v = end;
        mxFlow++;
        while(v != start) {
            int u = par[v];
            g[u][v] = false;
            g[v][u] = true;
            v =  u;
        }
    }
    return mxFlow;
}


void TC() {
    int n;
    cin >> n;
    map<string, int> mp;
    vector<string> hs;
    auto get = [&](const string &t) {
        if(!mp.count(t)) {
            mp[t] = int(hs.size());
            hs.emplace_back(t);
        }
        return mp[t];
    };
    vector<string> arr(n);
    vector<vector<int>> e(n);
    function<void(int, int, const string&)> rec = [&](int i, int j, const string &t) {
        if(!t.empty()) {
            if(e[i].size() <= n)
                e[i].push_back(get(t));
        }
        if(t.size() < 4 && j < arr[i].size()) {
            rec(i, j + 1, t + arr[i][j]);
            rec(i, j + 1, t);
        }
    };
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        rec(i, 0, "");
    }
    int m = n + int(hs.size()) + 2, start = m - 2, end = start + 1;
    vector<vector<bool>> g(m, vector<bool>(m));
    for(int i = 0; i < n; i++) {
        for(int j : e[i]) {
            g[i][j + n] = true;
        }
    }
    for(int i = 0; i < start; i++) {
        if(i < n)
            g[start][i] = true;
        else
            g[i][end] = true;
    }
    int res = max_flow(g, start, end);
    if(res != n) {
        cout << "-1\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j : e[i]) {
            if(g[j + n][i]) {
                cout << hs[j] << '\n';
                break;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("output.txt", "w", stdout); freopen("input.txt", "r", stdin);
    int tc = 1;
//    cin >> tc;
    for (int test = 1; test <= tc; ++test) {
        TC();
    }
//    cerr << clock() / 1000.0 << " Secs";
    return 0;
}
