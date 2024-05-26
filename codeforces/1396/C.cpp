// LUOGU_RID: 160354157
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

typedef long long ll;
const ll INF = numeric_limits<ll>::max();

int n;
ll r1, r2, r3, d;
ll a[MAXN], f[MAXN][2];

void chkmn(ll &x, ll y) {
    if (x > y) x = y;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        f[i][0] = f[i][1] = INF;
    }
    f[1][0] = r1 * a[1] + r3;
    f[1][1] = min(r2, r1 * (a[1] + 1));
    for (int i = 2; i <= n; i++) {
        chkmn(f[i][0], f[i - 1][0] + d + r1 * a[i] + r3);
        chkmn(f[i][0], f[i - 1][1] + d + min(r2, r1 * (a[i] + 1)) + d + r1 + d + r1);
        chkmn(f[i][0], f[i - 1][1] + d + r1 * a[i] + r3 + d + r1 + d);
        chkmn(f[i][1], f[i - 1][0] + d + min(r2, r1 * (a[i] + 1)));
        chkmn(f[i][1], f[i - 1][1] + d + min(r2, r1 * (a[i] + 1)) + d + r1 + d);
        if (i == n) chkmn(f[i][0], f[i - 1][1] + d + r1 * a[i] + r3 + d + r1);
    }
    printf("%lld\n", f[n][0]);
}