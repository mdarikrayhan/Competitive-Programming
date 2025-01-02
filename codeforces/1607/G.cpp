#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> dishes(n);
    ll balance = 0;
    ll max_a = 0, max_b = 0;
    ll total_eat = static_cast<long long>(n) * m;

    for (int i = 0; i < n; i++) {
        std::cin >> dishes[i].first >> dishes[i].second;
        balance += dishes[i].first - dishes[i].second;
        max_a += std::min(m, dishes[i].first);
        max_b += std::min(m, dishes[i].second);
    }
    ll max_delta = 2 * max_a - total_eat, min_delta = total_eat - 2 * max_b;
    ll min_a = total_eat - max_b;

    ll eat_a;
    if (balance < 0) {
        eat_a = min_a;
        if (balance - min_delta >= 0) {
            eat_a = std::min(max_a, (total_eat + balance + 1) / 2);
        }
    } else {
        eat_a = max_a;
        if (balance - max_delta <= 0) {
            eat_a = std::min(max_a, (total_eat + balance + 1) / 2);
        }
    }
    ll ans = std::abs(balance - 2 * eat_a + total_eat);

    std::cout << ans << '\n';
    ll rest_a = eat_a - min_a;
    for (int i = 0; i < n; i++) {
        ll cur_a = 0;
        if (dishes[i].second < m) {
            cur_a += m - dishes[i].second;
        }
        ll add = std::min(rest_a, std::min(m - cur_a, dishes[i].first - cur_a));
        cur_a += add;
        rest_a -= add;
        std::cout << cur_a << ' ' << m - cur_a << '\n';
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
