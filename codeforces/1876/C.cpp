#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n), color(n, -1); // 1 for black, 0 for white
    vector g(n, vector<int>()); // n 個點, n 個邊, 最多一個環, 可能多個自環

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g[--a[i]].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            int s = i; // start, can be root or cycle
            while (color[s] == -1) {
                color[s] = 0;
                s = a[s];
            }

            bool valid = 0;
            for (int c = 0; c <= 1; c++) { // leaf 的顏色
                bool ok = true;
                auto dfs = [&](auto self, int u, bool isRoot = false) -> void {
                    if (u == s && !isRoot) { // 有環
                        color[u] = c;
                        return;
                    }
                    int cnow = 0; // 如果子節點有白那就是黑, 全黑就是白
                    for (auto v : g[u]) {
                        self(self, v);
                        cnow |= !color[v];
                    }
                    if (isRoot && color[u] != cnow) {
                        ok = false;
                    }
                    color[u] = cnow;
                };
                dfs(dfs, s, true);
                if (ok) {
                    valid = true;
                    break;
                }
            }
            if (!valid) {
                cout << "-1\n";
                return;
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!color[i]) { // white
            ans.push_back(a[i] + 1);
        }
    }
    cout << ans.size() << "\n";
    for (auto x : ans) {
        cout << x << " ";
    } cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}