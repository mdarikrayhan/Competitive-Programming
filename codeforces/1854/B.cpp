#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e5, MAXN = 1e5 + 10, inf = 1e9, mod = 1e9 + 7;
using pt = std::pair<int, int>;

std::bitset<MAXN * 2> f;
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    f[1] = 1;
    i64 ans = 0, sum = 0, num;
    for (int i = 1;i <= n;++i) {
        std::cin >> num;
        sum += num;
        f |= f << num;
        if (f[i]) {
            ans = std::max(ans, sum - i + 1);
            f[i] = 0;
        }
    }
    for (int i = n + 1;i <= 2 * n;++i) {
        if (f[i]) {
            ans = std::max(ans, sum - i + 1);
            break;
        }
    }
    std::cout << ans;
    return 0;
}