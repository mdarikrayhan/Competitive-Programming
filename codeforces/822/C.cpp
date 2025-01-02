#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, sum;
    std::cin >> n >> sum;
    std::vector<std::tuple<int, int, int>> a(n);
    for (auto &[l, r, cost] : a) {
        std::cin >> l >> r >> cost;
    }

    std::ranges::sort(a);

    std::multiset<std::tuple<int, int, int>> b;
    std::map<int, int> min;
    int ans = -1;
    for (int i = 0; i < n; i++) {
        auto [l, r, cost] = a[i];
        int len = r - l + 1;
        while (!b.empty() && std::get<0>(*b.begin()) < l) {
            int len = std::get<0>(*b.begin()) - std::get<1>(*b.begin()) + 1;
            if (!min.contains(len)) {
                min[len] = std::get<2>(*b.begin());
            } else {
                min[len] = std::min(min[len], std::get<2>(*b.begin()));
            }
            b.erase(b.begin());
        }
        if (min.contains(sum - len)) {
            if (ans == -1 || min[sum - len] + cost < ans) {
                ans = min[sum - len] + cost;
            }
        }
        b.insert({r, l, cost});
    }

    std::cout << ans << '\n';

    return 0;
}