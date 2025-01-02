#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::pair<int, int>> res(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        res[i] = {a[i], i};
    }

    auto make = [&](int pos) {
        std::swap(a[pos + 1], a[pos + 2]);
        std::swap(a[pos], a[pos + 1]);
    };
    sort(res.begin(), res.end());
    for (int i = 0; i < n; ++i) {
        a[res[i].second] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cnt += a[j] < a[i];
        }
    }
    if (cnt & 1) {
        for (int i = 0; i < n - 1; ++i) {
            if (res[i].first == res[i + 1].first) {
                std::swap(a[res[i].second], a[res[i + 1].second]);
                break;
            }
        }
    }
    std::vector<int> ans;
    for (int i = 0; i < n - 2; ++i) {
        int pos = std::min_element(a.begin() + i, a.end()) - a.begin();
        while (pos > i + 1) {
            make(pos - 2);
            ans.push_back(pos - 2);
            pos -= 2;
        }
        if (pos != i) {
            make(i);
            make(i);
            ans.push_back(i);
            ans.push_back(i);
            pos = i;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (is_sorted(a.begin(), a.end())) {
            break;
        }
        make(n - 3);
        ans.push_back(n - 3);
    }
    if (!is_sorted(a.begin(), a.end())) {
        std::cout << -1 << '\n';
    } else {
        std::cout << ans.size() << '\n';
        for (auto it : ans) {
            std::cout << it + 1 << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    if (true) {
        std::cin >> T;
    }
    while (T--) {
        solve();
    }

    return 0;
}
