#include <bits/stdc++.h>

using LL = long long;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n, k ,t;
    std::cin >> m >> n >> k >> t;

    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    struct node {
        int l, r;
        int v;
    };
    std::vector<int> c(k);
    std::vector<node> q(k);
    for (int i = 0; i < k; i++) {
        std::cin >> q[i].l >> q[i].r >> q[i].v;
        c[i] = q[i].v;
    }
    std::sort(c.begin(), c.end());
    std::sort(q.begin(), q.end(), [&](node x, node y) {
        return x.v < y.v;
    });
    
    auto check = [&](int x) {
        auto it = std::upper_bound(c.begin(), c.end(), x);
        if (it == c.end()) {
            return true;
        }
        std::vector<node> tmp;
        for (int i = it - c.begin(); i < k; i++) {
            tmp.emplace_back(q[i]);
        }
        std::sort(tmp.begin(), tmp.end(), [&](node x, node y) {
            if (x.l != y.l) return x.l < y.l;
            return x.r < y.r;
        });

        int cost = n + 1;
        for (int i = 0; i < tmp.size(); i++) {
            int j = i, R = tmp[i].r;
            while (j < tmp.size() && tmp[j].l <= R) {
                R = std::max(R, tmp[j].r);
                j++;
            }
            cost += 2 * (R - (tmp[i].l - 1));
            i = j - 1;
        }
 
        return cost <= t;
    };

    int lo = 0, hi = m - 1;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (check(a[mid])) hi = mid;
        else lo = mid + 1;
    }
    if (check(a[hi]) == 0) {
        std::cout << 0 << '\n';
    } else {
        std::cout << m - hi << '\n';
    }
    return 0;
}