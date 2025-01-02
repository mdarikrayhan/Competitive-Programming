// LUOGU_RID: 159881409
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 100 + 10;

int n;
double a[N], ans, res, prod;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<double>());
    ans = res = a[1], prod = 1 - a[1];
    for(int i = 2; i <= n; i ++) {
        res = a[i] * (prod - res) + res;
        prod *= 1 - a[i];
        ans = max(ans, res);
    }
    printf("%.12lf\n", ans);

    return 0;
}
