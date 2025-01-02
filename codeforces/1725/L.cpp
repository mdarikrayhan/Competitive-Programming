// LUOGU_RID: 160262917
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
typedef long long ll;

int n, tot;
ll a[MAXN], b[MAXN];
ll sum[MAXN], tr[MAXN];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (; x <= n; x += lowbit(x))
        tr[x] += v;
}

ll query(int x) {
    ll ret = 0;
    for (; x; x -= lowbit(x)) {
        ret += tr[x];
    }
    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
        b[i] = sum[i];
    }
    for (int i = 1; i <= n; i++) {
        if (sum[i] < 0 || sum[i] > sum[n]) {
            puts("-1");
            return 0;
        }
    }
    sort(b + 1, b + n + 1);
    tot = unique(b + 1, b + n + 1) - (b + 1);
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        int p = lower_bound(b + 1, b + tot + 1, sum[i]) - b;
        add(p, 1);
        ans += query(p - 1);
    }
    printf("%lld\n", ans);
}