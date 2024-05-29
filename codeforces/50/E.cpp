#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long ans = 0;
    vector<bool> vis(m + 1);
    for (long long b = 1; b <= n; ++b) {
        int cnt = 0;
        for (long long x = b - 1; x >= 0 && b * b - x * x <= m; --x) {
            vis[b - x] = vis[b + x] = true;
            ++cnt;
        }

        ans += 2 * (min<long long>(b * b, m) - cnt);
    }

    cout << (ans + ranges::count(vis, true)) << '\n';
}
