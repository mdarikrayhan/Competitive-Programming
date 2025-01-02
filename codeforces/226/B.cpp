#include <bits/stdc++.h>

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i : a) {
        std::cin >> i;
    }

    std::ranges::sort(a);
    std::vector<ll> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    auto get = [&](int l, int r) {
        return pre[r] - pre[l];
    };

    int q;
    std::cin >> q;
    std::map<int, ll> memo;
    while (q--) {
        int k;
        std::cin >> k;

        if (!memo.contains(k)) {
            ll ans = 0;
            for (ll r = n - 2, l, len = k, cnt = 1; r >= 0; r = l - 1) {
                l = std::max<ll>(0, r - len + 1);
                ans += get(l, r + 1) * cnt;
                len *= k;
                cnt++;
            }
            memo[k] = ans;
        }

        std::cout << memo[k] << ' ';
    }

    return 0;
}