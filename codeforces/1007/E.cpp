// LUOGU_RID: 159835127
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

const int maxn = 205;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, t, K;
ll a[maxn], b[maxn], c[maxn], suma[maxn], sumb[maxn];
ll f[maxn][maxn][2], g[maxn][maxn][2];

int main() {
    scanf("%d %d %d", &n, &t, &K);
    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
        suma[i] = suma[i-1] + a[i];
        sumb[i] = sumb[i-1] + b[i];
    }
    a[++n] = inf, c[n] = inf;
    suma[n] = suma[n-1] + a[n];

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= t; j++)
            for(int k = 0; k <= 1; k++)
                f[i][j][k] = g[i][j][k] = inf;
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= t; j++)
            for(int k = 0; k <= 1; k++) {
                if(k*a[i] + j*b[i] <= c[i] && f[i-1][j][k] != inf) {
                    f[i][j][k] = min(f[i][j][k], f[i-1][j][k]);
                    ll x = (k*suma[i-1] + j*sumb[i-1] + K - 1) / K;
                    if(x*K <= k*suma[i] + j*sumb[i]) g[i][j][k] = min(g[i][j][k], x);
                }
                for(int r = 0; r < j; r++) {
                    if(g[i][r][k] != inf && f[i-1][j-r][0] != inf) {
                        ll m = k*suma[i] + r*sumb[i] - K*g[i][r][k], x = (max(0ll, m + (j-r)*b[i] - c[i]) + K - 1) / K;
                        if(x*K <= m) {
                            f[i][j][k] = min(f[i][j][k], g[i][r][k] + x + f[i-1][j-r][0]);
                            ll tmp = ((j-r) * sumb[i-1] + K - 1) / K;
                            if(tmp*K <= m - x*K + (j-r)*sumb[i]) g[i][j][k] = min(g[i][j][k], g[i][r][k] + x + tmp);
                        }
                    }
                }
            }
    printf("%lld\n", f[n][t][1]);
    return 0;
}