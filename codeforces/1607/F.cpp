#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> dir(n);
    for (int i = 0; i < n; i++) {
        std::cin >> dir[i];
    }

    std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
    int opt = 0, optr = 0, optc = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (res[r][c] > 0) {
                continue;
            }

            int nr = r, nc = c;
            int depth = 0;
            std::vector<std::pair<int, int>> path;
            auto ok = [&n, &m](int row, int col) {
                return row > -1 && row < n && col > -1 && col < m;
            };

            do {
                res[nr][nc] = --depth;
                path.emplace_back(nr, nc);
                if (dir[nr][nc] == 'L') {
                    nc--;
                } else if (dir[nr][nc] == 'R') {
                    nc++;
                } else if (dir[nr][nc] == 'U') {
                    nr--;
                } else {
                    nr++;
                }
            } while (ok(nr, nc) && res[nr][nc] == 0);

            int start = 1;
            if (ok(nr, nc)) {
                if (res[nr][nc] < 0) {
                    int cycle = res[nr][nc] - depth + 1;
                    for (int i = 0; i < cycle; i++) {
                        auto p = path.back();
                        path.pop_back();
                        res[p.first][p.second] = cycle;
                    }
                }
                start = res[nr][nc] + 1;
            }
            while (!path.empty()) {
                auto p = path.back();
                path.pop_back();
                res[p.first][p.second] = start++;
            }

            if (res[r][c] > opt) {
                opt = res[r][c];
                optr = r;
                optc = c;
            }
        }
    }

    std::cout << optr + 1 << ' ' << optc + 1 << ' ' << opt << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
