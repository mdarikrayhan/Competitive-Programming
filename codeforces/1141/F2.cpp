#include <bits/stdc++.h>

using i64 = long long;

typedef std::pair<int, int> PII;
const int mod = 998244353;
const int N = 2e6 + 1000;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i ++) std::cin >> a[i], pre[i] = pre[i - 1] + a[i];

    std::map<int, std::vector<PII>> mp;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j ++)
            mp[pre[j] - pre[i - 1]].emplace_back(i, j);

    int max = 0, id;
    for (auto &[x, c] : mp) {
        std::sort(c.begin(), c.end());
        int R = -1, cnt = 0;
        for (auto [l, r] : c) {
            if (l > R) {
                cnt ++;
                R = r;
            }
            else
                R = std::min(R, r);
        }
        if (cnt > max) {
            max = cnt;
            id = x;
        }
    }
    std::cout << max << "\n";

    std::vector<PII> ans;
    int R = -1;
    for (auto [l, r] : mp[id]) {
        if (l > R) {
            ans.emplace_back(l, r);
            R = r;
        }
        else if (R > r) {
            R = std::min(R, r);
            ans.pop_back();
            ans.emplace_back(l, r);
        }
    }

    for (auto [l, r] : ans) std::cout << l << " " << r << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int t = 1;
//    std::cin >> t;
    while (t--)
        solve();
    return 0;
}