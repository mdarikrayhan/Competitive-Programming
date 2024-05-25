// LUOGU_RID: 158400874
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 200010;
int n, a[N];
LL h;

int main() {
    scanf("%lld%d", &h, &n);
    LL tot = 0, mn = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        tot += a[i];
        if(tot < mn) mn = tot;
    }
    mn = -mn;
    LL l = 1, r = 1e12, rd = 1;
    while(l <= r) {
        LL mid = l + r >> 1;
        if(-(__int128)tot*(mid - 1) + mn >= h) {
            rd = mid;
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    h -= -tot*(rd - 1);
    LL ans = n*(rd - 1);
    for(int i = 1; i <= n; i++) {
        h += a[i];
        ans++;
        if(h <= 0) break;
    }
    if(h > 0) {
        puts("-1");
        return 0;
    }
    printf("%lld\n", ans);
    return 0;
}