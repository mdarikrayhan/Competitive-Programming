#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::tuple<int, int, int>> a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        if (x < y) {
            a.emplace_back(x, y, i);
        } else if (x > y) {
            b.emplace_back(y, x, i);
        }
    }    

    if (a.size() > b.size()) {
        std::ranges::sort(a, std::greater<>());
        std::cout << a.size() << '\n';
        for (auto [x, y, i] : a) {
            std::cout << i + 1 << ' ';
        }
    } else {
        std::ranges::sort(b);
        std::cout << b.size() << '\n';
        for (auto [x, y, i] : b) {
            std::cout << i + 1 << ' ';
        }
    }

    return 0;
}