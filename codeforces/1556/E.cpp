// LUOGU_RID: 159516463
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;

int n, q;
int a[MAXN], b[MAXN];
ll sum[MAXN], f[MAXN][20], g[MAXN][20];

ll qmin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(f[l][k], f[r - (1 << k) + 1][k]);
}

ll qmax(int l, int r) {
    int k = __lg(r - l + 1);
    return max(g[l][k], g[r - (1 << k) + 1][k]);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        sum[i] = sum[i - 1] + a[i] - b[i];
        f[i][0] = g[i][0] = sum[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
            g[i][j] = max(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (sum[r] - sum[l - 1]) {
            puts("-1");
            continue;
        }
        if (qmax(l, r) - sum[l - 1] > 0) {
            puts("-1");
            continue;
        }
        printf("%lld\n", -(qmin(l, r) - sum[l - 1]));
    }
}