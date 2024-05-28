#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    auto query = [&](int i, int j) {
        std::cout << "? " << i << " " << j << std::endl;
        int ans;
        std::cin >> ans;
        return ans;  
    };
    
    std::vector<int> q1(n), q2(n);
    for (int i = 0; i < n; i++) {
        q1[i] = query(0, i);
        q2[i] = query(i, 0);
    }

    int cnt = 0;
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        std::vector<int> b(n);
        for (int j = 0; j < n; j++) {
            b[j] = q1[j] ^ i;
        }
        auto check = [&]() -> std::pair<bool, std::vector<int>> {
            if (std::any_of(b.begin(), b.end(), [&](int x) { return x >= n; })) {
                return {false, {}};
            }
            std::vector<int> a(n);
            for (int i = 0; i < n; i++) {
                a[b[i]] = i;
            }
            for (int i = 0; i < n; i++) {
                if ((a[i] ^ b[0]) != q2[i]) {
                    return {false, {}};
                }
            }
            return {true, a};
        };
        if (auto [ok, res] = check(); ok) {
            ans = res;
            cnt++;
        }
    }

    std::cout << "!" << std::endl;
    std::cout << cnt << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}