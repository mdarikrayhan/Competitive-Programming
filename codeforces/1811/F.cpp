#include <bits/stdc++.h>

using namespace std;

int sz(int v, vector<vector<int>> &g, vector<bool> &used){
    used[v] = true;
    int s = 1;
    for(int u: g[v]){
        if(!used[u]) s += sz(u, g, used);
    }
    return s;
}

void remove(vector<int> &from, int x){
    for(int &e: from){
        if(e == x){
            swap(e, from.back());
            from.pop_back();
            return;
        }
    }
}

void solve(int tc) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> sl(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        sl[--u].emplace_back(--v);
        sl[v].emplace_back(u);
    }
    int k = sqrt(n);
    if(n != k * k || m != n + k){
        cout << "NO";
        return;
    }
    for(int i = 0; i < n; ++i){
        if(sl[i].size() != 2 && sl[i].size() != 4){
            cout << "NO";
            return;
        }
    }
    vector<bool> used(n);
    if(sz(0, sl, used) != n){
        cout << "NO";
        return;
    }
    for(int i = 0; i < n; ++i){
        if(sl[i].size() == 2) continue;
        for(int j = 0; j < sl[i].size();){
            int u = sl[i][j];
            if(sl[u].size() > 2){
                remove(sl[i], u);
                remove(sl[u], i);
            }
            else{
                j++;
            }
        }
    }
    used = vector<bool>(n);
    for(int i = 0; i < n; ++i){
        if(!used[i] && sz(i, sl, used) != k){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

bool multi = true;

signed main() {
    cout.tie(nullptr);
    int t = 1;
    if (multi)cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "\n";
    }
    return 0;
}
