#include <bits/stdc++.h>

using i64 = long long;

typedef std::pair<int, int> PII;
const int mod = 998244353;
const int N = 1e6 + 1000;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    auto get = [](int x) {
        std::cout << "+ " << x << std::endl;
        int ans;
        std::cin >> ans;
        return ans;
    };

    const int M = 1e6 + 7;

    std::vector<int> pos(N);
    int num, n0, add = 0, start;
    std::cin >> num;
    start = num;
    n0 = num;
    for (int i = 1; i <= 400; i ++) {
        int rand = rng() % M;
        add += rand;
        num = get(rand);
        n0 = std::max(n0, num);
    }

    std::cout << "- " << add << std::endl;
    std::cin >> num;

    add = n0 - 1;
    num = get(n0 - 1);

    pos[num] = n0;

    for (int d = 1; d <= 300; d ++) {
        add ++;
        num = get(1);
        pos[num] = n0 + d;
        if (num == start) {
            std::cout << "! " << n0 + d - 1 << std::endl;
            return ;
        }
    }
    std::cout << "- " << add << std::endl;
    std::cin >> num;

    int ans = 0;
    while (true) {
        std::cout << "- 300" << std::endl;
        ans += 300;
        std::cin >> num;
        if (pos[num]) {
            std::cout << "! " << ans + pos[num] - 1 << std::endl;
            return ;
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;
//    std::cin >> t;
    while (t --)
        solve();
    return 0;
}