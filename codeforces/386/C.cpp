#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    int n = s.length();
    std::vector<std::vector<int>> next(n, std::vector<int>(26, n));
    for (int i = 0; i < 26; ++i) {
        for (int j = n - 2; j >= 0; --j) {
            if (s[j + 1] == i + 'a') {
                next[j][i] = j + 1;
            } else {
                next[j][i] = next[j + 1][i];
            }
        }
    }

    int mask = 0;
    for (int i = 0; i < n; ++i) {
        mask |= (1 << (s[i] - 'a'));
    }
    int ds = __builtin_popcount(mask);
    std::vector<i64> ans(ds + 1);
    for (int l = 0; l < n; ++l) {
        int st = (1 << (s[l] - 'a'));
        int cnt = 1;
        int r = l;
        while (r < n) {
            int min = n;
            for (int i = 0; i < 26; ++i) {
                if (st >> i & 1 ^ 1) {
                   min = std::min(min, next[r][i]);
                }
            }
            ans[cnt] += min - r;
            ++cnt;
            r = min;
            st |= (1 << (s[r] - 'a'));
        }
    }

    std::cout << ds << '\n';
    for (int i = 1; i <= ds; ++i) {
        std::cout << ans[i] << '\n';
    }
}