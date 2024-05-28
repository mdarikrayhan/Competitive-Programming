#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    auto solve = [&]() {
        int n, m;
        cin >> n >> m;

        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        vector<pair<int, int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        auto in = [&](int x, int y) {
            return 0 <= x && x < n && 0 <= y && y < m;
        };

        vector<vector<int>> adj(n * m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == 'X') {
                    vector<int> neighbour;
                    for (auto [dx, dy] : dirs) {
                        int nx = i + dx, ny = j + dy;
                        if (in(nx, ny) && s[nx][ny] == '.') {
                            neighbour.push_back(nx * m + ny);
                        }
                    }
                    if (neighbour.size() % 2 != 0) {
                        cout << "NO\n";
                        return;
                    }
                    for (int k = 0; k < neighbour.size(); k++) {
                        adj[neighbour[k]].push_back(neighbour[k ^ 1]);
                    }
                }
            }
        }

        vector ans(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ans[i][j] != 0 || s[i][j] == 'X') {
                    continue;
                }
                queue<int> q;
                q.emplace(i * m + j);
                ans[i][j] = 1;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    int x = u / m, y = u % m;
                    for (auto v : adj[u]) {
                        int nx = v / m, ny = v % m;
                        if (s[nx][ny] == '.' && ans[nx][ny] == 0) {
                            ans[nx][ny] = 5 - ans[x][y];
                            q.emplace(v);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == 'X') {
                    for (auto [dx, dy] : dirs) {
                        int nx = i + dx, ny = j + dy;
                        if (in(nx, ny) && s[nx][ny] == '.') {
                            ans[i][j] += ans[nx][ny];
                        }
                    }
                }
            }
        }
        
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " \n"[j + 1 == m];
            }
        }
    };
    
    solve();
    
    return 0;
}
