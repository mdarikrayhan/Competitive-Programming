// LUOGU_RID: 113288271
#include <bits/stdc++.h>
using namespace std;
namespace QYB {
    using ll = long long;
    using ldb = long double;
    int n, t[5005]; ldb ans, g[5005];
    ll x[5005], y[5005], a[5005], b[5005];
    ll gcd(ll a, ll b) { return b? gcd(b, a % b): a; }
    ldb calcx(int i, ldb t) { return (cos(t) * cos(t) * sin(g[i] - t) - sin(t) * cos(g[i])) / sin(g[i]); }
    ldb calcy(int i, ldb t) { return sin(t) * sin(t) * cos(g[i] - t) / sin(g[i]); }
    ldb gett(int i, ldb y) {
        ldb l = 0, r = g[i];
        while (r - l > 1e-10) {
            ldb mid = (l + r) / 2;
            calcy(i, mid) < y? l = mid: r = mid;
        } return (l + r) / 2;
    } ldb calc(int i, ldb t) {
        return ((sin(2 * g[i] + 2 * t) + sin(2 * g[i] - 4 * t) - sin(2 * g[i] - 6 * t) - sin(2 * g[i])) / 64 + sin(4 * t) / 32 + (sin(2 * g[i] - 2 * t) - t - sin(2 * g[i])) / 16 - t * sin(g[i]) * sin(g[i]) / 8) / sin(g[i]) / sin(g[i]);
    } ldb work(int i) {
        int j = i % n + 1; ldb k = sqrt((ldb)t[i]);
        ldb l = 0, r = g[i];
        while (r - l > 1e-10) {
            ldb mid = (l + r) / 2; ldb t2 = gett(j, calcy(i, mid));
            calcx(i, mid) + calcx(j, t2) > k? l = mid: r = mid;
        } ldb t1 = (l + r) / 2;
        ldb t2 = gett(j, calcy(i, t1));
        return calc(i, t1) + calc(j, t2);
    } int main() {
        scanf("%d", &n); const ldb pi = acos(-1);
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", x + i, y + i);
        } if(n == 4) {
            ll maxx = max({x[1], x[2], x[3], x[4]});
            ll maxy = max({y[1], y[2], y[3], y[4]});
            ll minx = min({x[1], x[2], x[3], x[4]});
            ll miny = min({y[1], y[2], y[3], y[4]});
            if (maxx - minx == 1 || maxy - miny == 1){
                printf("%.11Lf\n", (ldb)(maxx - minx) * (maxy - miny));
                return 0;
            }
        } for (int i = 1; i <= n; i++) {
            int p = (i + n - 2) % n + 1, q = i % n + 1;
            ll x1 = x[p] - x[i], y1 = y[p] - y[i], x2 = x[q] - x[i], y2 = y[q] - y[i];
            a[i] = x2 * y1 - x1 * y2; b[i] = x1 * x2 + y1 * y2;
            a[i] < 0? a[i] = -a[i]: b[i] = -b[i]; g[i] = atan2(a[i], b[i]);
            ll h = gcd(abs(a[i]), abs(b[i])); a[i] /= h; b[i] /= h;
            ans += (g[i] * ((ldb)b[i] / a[i]) * ((ldb)b[i] / a[i]) - ((ldb)b[i] / a[i]) + 3 * g[i]) / 16;
            if (abs(x2) + abs(y2) == 1) t[i] = 1;
            else if (abs(x2) == 1 && abs(y2) == 1) t[i] = 2;
            else t[i] = 0;
        } for (int i = 1; i <= n; i++) {
            if (t[i]) ans += work(i);
        } return !printf("%.11Lf\n", ans);
    }
} int main() {
    return QYB::main();
}