// LUOGU_RID: 159719804
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#include <bits/stdc++.h>

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200005, M = 10005, inf = 1e9, A = 1e5;
int n, b, sum, a[N], f[2][N], pre[5005][M];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> b;
    F(i, 1, n) cin >> a[i];
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 0, o = 0; i < n; i ++, o ^= 1) {
        int maxn = min((sum + a[i + 1]) / 10, M);
        F(j, 0, maxn) f[o ^ 1][j] = inf;
        for (int j = 0; j <= sum / 10; j ++) {
            if (f[o][j] < inf) {
                int hav = b - (sum - f[o][j]) + j;
                for (int k = 0; k <= min(hav, a[i + 1] / 2); k ++) {
                    int id = j + (a[i + 1] - k) / 10;
                    if (f[o][j] + (a[i + 1] - k) < f[o ^ 1][id]) {
                        f[o ^ 1][id] = f[o][j] + (a[i + 1] - k);
                        pre[i + 1][id] = k;
                    }
                }
            }
        }
        sum += a[i + 1];
    }
    int ans = inf, pos = 0;
    F(i, 0, sum / 10)
        if (ans > f[n & 1][i])
            ans = f[n & 1][i], pos = i;
    vector<int> an(n + 2);
    dF(i, n, 1) {
        an[i] = pre[i][pos];
        pos -= (a[i] - an[i]) / 10;
    }
    cout << ans << '\n';
    F(i, 1, n) cout << an[i] << ' ';
    return 0;
}
