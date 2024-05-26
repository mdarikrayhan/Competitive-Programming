#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    std::vector<int> p;
    std::vector<int> A(26), B(26);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '?') {
            ++A[s[i] - 'a'];
        } else {
            p.emplace_back(i);
        }
    }
    for (int i = 0; i < t.size(); ++i) {
        ++B[t[i] - 'a'];
    }

    auto check = [&](i64 mid) -> bool {
        i64 need = 0;
        for (int i = 0; i < 26; ++i) {
            need += std::max(mid * B[i] - A[i], 0LL);
        }
        return need <= p.size();
    };

    i64 l = 0, r = int(s.size());
    while (l < r) {
        i64 mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    for (int i = 0; i < 26; ++i) {
        int v = std::max(l * B[i] - A[i], 0LL);
        while (v--) {
            s[p.back()] = char('a' + i);
            p.pop_back();
        }
    }

    while (p.size()) {
        s[p.back()] = 'a';
        p.pop_back();
    }

    std::cout << s << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}