#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;
int n, m;
std::vector<std::vector<int>> p;

bool check(int x) {
    std::vector<bool> abl(m);
    bool pair = false;
    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < m; ++j) {
            if (p[i][j] >= x) {
                abl[j] = true;
                c++;
            }
        }
        if (c > 1) {
            pair = true;
        }
    }
    if (!pair && m > 1) {
        return false;
    }
    bool ans = true;
    for (bool b : abl) {
        ans = ans && b;
    }
    return ans;
}

void solve() {
    std::cin >> n >> m;
    p.assign(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> p[i][j];
        }
    }
    int l = 1, r = 2;
    while (check(r)) {
        r *= 2;
    }
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout << l << '\n';
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
