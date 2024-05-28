#include <bits/stdc++.h>
using ll = long long;
const int mod = 998244353;

template <class T>
bool ckmin(T &a, T b) {
    return a > b ? a = b, true : false;
}

struct option {
    int t, p, id;

    option(int _t, int _p, int _id) : t(_t), p(_p), id(_id) {}
};

const int INF = INT_MAX >> 1;

std::vector<int> get(std::vector<option> &v) {
    int n = v.size();
    std::vector<std::vector<int>> dp(101, std::vector<int>(n + 1, INF));
    dp[0][0] = 0;
    for (int k = 1; k <= n; k++) {
        auto [t, p, id] = v[k - 1];
        dp[0][k] = 0;
        for (int i = 100; i > 0; i--) {
            int prev = std::max(0, i - p);
            dp[i][k] = dp[i][k - 1];
            ckmin(dp[i][k], dp[prev][k - 1] + t);
        }
    }
    std::vector<int> ans;
    int t = dp[100][n];

    if (t == INF) {
        return {-1};
    }
    for (int i = 100, k = n; k >= 1; k--) {
        if (dp[i][k] == dp[i][k - 1]) {
            continue;
        }
        ans.emplace_back(v[k - 1].id);
        i = std::max(0, i - v[k - 1].p);
    }

    std::reverse(ans.begin(), ans.end());
    ans.emplace_back(t);
    return ans;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = n - 1; i > 0; i--) {
        a[i] -= a[i - 1];
    }
    std::vector<std::vector<option>> v(n);
    for (int i = 0; i < m; i++) {
        int e, t, p;
        std::cin >> e >> t >> p;
        e--;
        v[e].emplace_back(t, p, i + 1);
    }
    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        auto cur = get(v[i]);
        if (cur.size() == 1 && cur[0] == -1) {
            std::cout << "-1\n";
            return;
        }
        int t = cur.back();
        if (t > a[i]) {
            std::cout << "-1\n";
            return;
        }
        cur.pop_back();
        if (i + 1 < n) {
            a[i + 1] += a[i] - t;
        }
        ans.insert(ans.end(), cur.begin(), cur.end());
    }
    std::cout << ans.size() << '\n';
    for (auto &e : ans) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
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
