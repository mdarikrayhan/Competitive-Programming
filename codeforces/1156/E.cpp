#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    auto solve = [&]() {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        i64 ans = 0;

        auto dc = [&](auto dc, int l, int r) -> void {
            if (l == r) {
                return;
            }
            
            int m = (l + r) / 2;
            dc(dc, l, m);
            dc(dc, m + 1, r);

            {
                set<int> s;
                for (int i = m, j = m + 1, mx = 0; i >= l; i--) {
                    mx = max(mx, p[i]);
                    while (j <= r && p[j] <= mx) {
                        s.insert(p[j++]);
                    }
                    ans += s.count(mx - p[i]);
                }
            }
            {
                set<int> s;
                for (int i = m, j = m + 1, mx = 0; j <= r; j++) {
                    mx = max(mx, p[j]);
                    while (i >= l && p[i] <= mx) {
                        s.insert(p[i--]);
                    }
                    ans += s.count(mx - p[j]);
                }
            }
        };
        dc(dc, 0, n - 1);

        cout << ans << '\n';
    };
    
    solve();
    
    return 0;
}
/////