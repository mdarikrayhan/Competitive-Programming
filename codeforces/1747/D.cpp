#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector<i64> sum(n + 1);
    std::vector<int> xsum(n + 1), a(n);
    std::map<int, std::vector<int>> f[2];
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        xsum[i + 1] = xsum[i] ^ a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    for (int i = 0; i <= n; i++) {
        f[i % 2][xsum[i]].push_back(i);
    }
    
    auto query = [&](int l, int r) {
        if (sum[l] == sum[r]) {
            return 0;
        }
        if (xsum[l] != xsum[r]) {
            return -1;
        }
        if ((r - l) % 2) {
            return 1;
        }
        if (!a[l] || !a[r - 1]) {
            return 1;
        }
        auto &b = f[!(l % 2)][xsum[l]];
        auto it = std::lower_bound(b.begin(), b.end(), l);
        if (it != b.end() && *it < r) {
            return 2;
        }
        return -1;
    };
    
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        
        std::cout << query(l, r) << "\n";
    }
    
    return 0;
}
