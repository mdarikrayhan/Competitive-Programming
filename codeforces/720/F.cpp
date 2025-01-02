// LUOGU_RID: 158197020
#include <stdio.h>
#include <algorithm>
using namespace std;
const int _(100002); int n, m, a[_], b[_], l[_], o[_], q[_], u[_]; long long t, w, c[_], d[_], r[_], s[_];
struct BIT {
    long long e[_];
    void add(int p, const long long v) { for (; p <= m; p += p & -p) e[p] += v; }
    long long query(int p) { long long v(0); for (; p; p ^= p & -p) v += e[p]; return v; }
    void clear() { for (int i(1); i <= m; ++i) e[i] = 0; }
} f, g;
long long check()
{
    int p(0); long long h(w = 0); f.add(o[n + 1], 1); g.add(o[n + 1], 0);
    for (int i(1); i <= n; ++i)
    {
        int j(upper_bound(d + 1, d + m + 1, c[i] - t) - d - 1);
        if (j && b[j] < i) h += f.query(j), w += f.query(j) * (c[i] - t) - g.query(j), ++l[b[j] + 1], --l[i + 1];
        f.add(o[i], 1); g.add(o[i], c[i]);
    }
    for (int i(1); i <= n; ++i) if (!(l[i] += l[i - 1])) q[++p] = i;
    for (int i(1); i <= n; ++i) l[i] = 0; f.clear(); g.clear();
    if (p) {
        s[0] = 1e18; u[0] = 0; for (int i(1); i <= q[1]; ++i) s[0] = min(s[0], c[i - 1]); s[0] = -s[0];
        for (int i(1); i <= p; ++i) {
            s[i] = s[0] + r[q[i]] - t; u[i] = u[0] + 1;
            for (int j(q[i]); j < q[i + 1]; ++j) if (s[i] - c[j] >= s[0]) s[0] = s[i] - c[j], u[0] = u[i];
        } w += s[p], h += u[p];
    } return h;
}
int main()
{
    long long k; scanf("%d%lld", &n, &k);
    for (int i(1); i <= n; ++i) scanf("%d", &a[i]), c[i] = d[i] = c[i - 1] + a[i];
    r[n] = c[n]; for (int i(n - 1); i; --i) r[i] = max(r[i + 1], c[i]);
    sort(d + 1, d + n + 2); m = unique(d + 1, d + n + 2) - d - 1;
    for (int i(1); i <= m; ++i) b[i] = n + 1;
    for (int i(n + 1); ~i; --i) b[o[i] = lower_bound(d + 1, d + m + 1, c[i]) - d] = i;
    for (int i(2); i <= m; ++i) b[i] = min(b[i], b[i - 1]);
    long long L(-5e9), R(5e9), p;
    while (L <= R) { t = L + R >> 1; if (check() >= k) p = t, L = t + 1; else R = t - 1; }
    t = p; check(); return !printf("%lld\n", w + t * k);
}