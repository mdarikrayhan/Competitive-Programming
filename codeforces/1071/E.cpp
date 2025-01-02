#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ld = long double;
const ld EPS = 1e-9;
int n,t[N];
ld w,h,e1,e2,p[N][2];
bool check(ld mid) {
    ld l = e1,r = e1,dx = (e1 + e2) / 2,dy = h / 2;
    for (int i = 1;i <= n;i++) {
        ld a = (h - p[i][1]) / p[i][1] * (dy / (h - dy)),
        b = (dx + dy / (h - dy) * dx) + (-dy / (h - dy)) *
            (p[i][0] + (h / p[i][1] - 1) * p[i][0]);
        ld a1 = mid * (t[i] - t[i - 1]),a2 = (dy / (h - dy)) * a1;
        ld l1 = l - a1,r1 = r + a1,l2 = (l - a2 - b) / a,r2 = (r + a2 - b) / a,
            l3,r3,l4,r4;
        if (a < 1) {
            l3 = (a1 + a2 - b) / (a - 1);r3 = (-a1 - a2 - b) / (a - 1);
        }
        else if (a > 1) {
            l3 = (-a1 - a2 - b) / (a - 1);r3 = (a1 + a2 - b) / (a - 1);
        } else{
            if (abs(b) > a1 + a2) return 0;
            l3 = 0;r3 = w;
        }
        l4 = p[i][0] - (w - p[i][0]) * p[i][1] / (h - p[i][1]);
        r4 = p[i][0] + p[i][0] * p[i][1] / (h - p[i][1]);
        l = max({l1,l2,l3,l4,0.0l});r = min({r1,r2,r3,r4,w});
        if (l > r) {if (l - r < EPS) swap(l,r);else return 0;}
        dx = p[i][0];dy = p[i][1];
    }
    return 1;
}
int main ()
{
    ios::sync_with_stdio(false);
    cin >> n >> w >> h >> e1 >> e2;
    for (int i = 1;i <= n;i++) cin >> t[i] >> p[i][0] >> p[i][1];
    if (!check(w + 1)) {cout << -1 << endl;return 0;}
    ld l = 0,r = w;
    while (r - l > EPS)
    {
        ld mid = (l + r) / 2;if (check(mid)) r = mid;else l = mid;
    }
    printf("%.8lf\n",double(l));
    return 0;
}