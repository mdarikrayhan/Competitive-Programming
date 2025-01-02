#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (auto &i : a) {
        std::cin >> i;
    }
    for (auto &i : b) {
        std::cin >> i;
    }

    int sa = std::accumulate(a.begin(), a.end(), 0, std::bit_xor<int>());
    int sb = std::accumulate(b.begin(), b.end(), 0, std::bit_xor<int>());

    if (sa != sb) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::vector ans(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            ans[i][m - 1] = a[i];
        }
        for (int i = 0; i < m; i++) {
            ans[n - 1][i] = b[i];
        }
        ans[n - 1][m - 1] = std::accumulate(ans[n - 1].begin(), ans[n - 1].begin() + m - 1, a[n - 1], std::bit_xor<int>());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << ans[i][j] << " \n"[j == m - 1];
            }
        }
    }

    return 0;
}