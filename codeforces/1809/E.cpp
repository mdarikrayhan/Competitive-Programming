#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[1005][1005];
int n, c, d;
int a[10005];
signed main() {
    int T = 1;
    while (T--) {
        cin >> n >> c >> d;
        int mx = 0, mn = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum -= a[i];
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        for (int s = 0; s <= c + d; s++) {
            // s = 5;
            int R = min(c, s), L = max(0ll, s - d);
            // if (s == 5) printf("%lld %lld\n", L - mn, R - mx);
            for (int x = L - mn; x <= R - mx; x++) {
                ans[x][s - x] = x + sum;
            }
            int l = L, r = R;
            for (int i = 1; i <= n; i++) {
                l = l - a[i];
                r = r - a[i];
                l = max(l, L), l = min(l, R);
                r = max(r, L), r = min(r, R);
            }
            for (int x = L; x <= min(R, L - mn - 1); x++) {
                ans[x][s - x] = l;
            }
            for (int x = max(L, R - mx + 1); x <= R; x++) {
                ans[x][s - x] = r;
            }
        }
        // puts("!");
        for (int i = 0; i <= c; i++) {
            for (int j = 0; j <= d; j++) {
                printf("%lld ", ans[i][j]);
            }
            puts("");
        }
    }
}