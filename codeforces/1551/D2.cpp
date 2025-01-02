#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

char field[128][128];

void solve() {
    int n, m, kh;
    std::cin >> n >> m >> kh;
    int kv = n * m / 2 - kh;
    if (n & 1) {
        kh -= m / 2;
        if (kh < 0) {
            std::cout << "NO\n";
            return;
        }

        for (int i = 0; i < m / 2; i++) {
            field[n - 1][i * 2] = field[n - 1][i * 2 + 1] =
                ((i & 1) ? 'x' : 'y');
        }
    } else if (m & 1) {
        kv -= n / 2;
        if (kv < 0) {
            std::cout << "NO\n";
            return;
        }

        for (int i = 0; i < n / 2; i++) {
            field[i * 2][m - 1] = field[i * 2 + 1][m - 1] =
                ((i & 1) ? 'x' : 'y');
        }
    }
    if ((kh & 1) || (kv & 1)) {
        std::cout << "NO\n";
        return;
    }
    for (int i = 0; i < n / 2; i++)
        for (int j = 0; j < m / 2; j++) {
            if (kh) {
                kh -= 2;
                field[2 * i][2 * j] = field[2 * i][2 * j + 1] =
                    (((i + j) & 1) ? 'a' : 'b');
                field[2 * i + 1][2 * j] = field[2 * i + 1][2 * j + 1] =
                    (((i + j) & 1) ? 'c' : 'd');
            } else {
                field[2 * i][2 * j] = field[2 * i + 1][2 * j] =
                    (((i + j) & 1) ? 'a' : 'b');
                field[2 * i][2 * j + 1] = field[2 * i + 1][2 * j + 1] =
                    (((i + j) & 1) ? 'c' : 'd');
            }
        }

    std::cout << "YES\n";
    for (int i = 0; i < n; i++) {
        field[i][m] = 0;
        std::cout << field[i] << '\n';
    }
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
