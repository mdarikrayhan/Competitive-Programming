#include <bits/stdc++.h>

#define int long long
#define ld long double
#define F first
#define S second
using namespace std;
vector<set<pair<int, int>>> g;
vector<int> eul;
vector<bool> used;

inline void dfs(int v) {
    while (!g[v].empty()) {
        auto i = *g[v].begin();
        g[v].erase(i);
        g[i.F].erase({v, i.S});
        dfs(i.F);
    }
    eul.push_back(v);
    used[v] = 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    vector<vector<int>> a(m);
    unordered_map<int, int> mp;
    vector<vector<bool>> ans(m);
    for (int i = 0; i < m; ++i) {
        int n;
        cin >> n;
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
        ans[i].resize(n);
    }
    bool ch = 1;
    unordered_map<int, int> idx;
    int id = 0;
    for (auto[k, v]:mp) {
        idx[k] = id++;
        if (v & 1) {
            ch = 0;
        }
    }
    if (!ch) {
        cout << "NO";
        return 0;
    }
    vector<map<int, vector<int>>> idxs(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            idxs[i][idx[a[i][j]]].push_back(j);
        }
    }
    g.resize(m + mp.size());
    used.resize(m + mp.size());
    for (int i = 0; i < m; ++i) {
        id = 0;
        for (int j : a[i]) {
            g[i].insert({idx[j] + m, id});
            g[idx[j] + m].insert({i, id});
            id++;
        }
    }
    for (int i = 0; i < g.size(); ++i) {
        if (!used[i]) {
            eul.clear();
            dfs(i);
            for (int j = 1; j < eul.size(); ++j) {
                if (eul[j - 1] >= m && eul[j] < m) {
                    ans[eul[j]][idxs[eul[j]][eul[j - 1] - m].back()] = 1;
                    idxs[eul[j]][eul[j - 1] - m].pop_back();
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            if (ans[i][j]) {
                cout << "R";
            } else {
                cout << "L";
            }
        }
        cout << '\n';
    }
    return 0;
}
