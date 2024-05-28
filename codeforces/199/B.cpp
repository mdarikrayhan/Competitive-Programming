#include <bits/stdc++.h>

using namespace std;

#define int long long

const double EPS = 1e-7;

typedef int T;
typedef complex<T> pt;
#define x real()
#define y imag()

T sq(pt p) { return p.x * p.x + p.y * p.y; }

int sgn(double n) {
    if (n > EPS) return 1;
    if (abs(n) < EPS) return 0;
    return -1;
}

int circleCircle(pt o1, T r1, pt o2, T r2) {
    pt d = o2 - o1;
    T d2 = sq(d);
    if (!d2) return 0;
    double pd = (double)(d2 + r1*r1 - r2 * r2)/2.0;
    double h2 = (double)r1*r1 - (double)pd*pd/(double)d2;
    return 1 + sgn(h2);
}

void solve() {
    pt o[2];
    T r[4];
    T X, Y;
    cin >> X >> Y >> r[0] >> r[1];
    o[0] = pt(X, Y);
    cin >> X >> Y >> r[2] >> r[3];
    o[1] = pt(X, Y);
    int ans{}, d = sq(o[0]-o[1]);
    for (int i = 0; i < 2; ++i) {
        bool f = true;
        for (int j = 0; j < 2; ++j)
            if (circleCircle(o[0], r[i], o[1], r[2+j]) > 1) f = false;
        if (d < r[2]*r[2] && r[i] > r[2] && r[i] < r[3]) f = false;
        if (d >= r[2]*r[2] && d < r[3]*r[3] && r[i] < r[3]) f = false;
        ans += f;
        f = true;
        for (int j = 0; j < 2; ++j)
            if (circleCircle(o[0], r[j], o[1], r[2+i]) > 1) f = false;
        if (d < r[0]*r[0] && r[2+i] > r[0] && r[2+i] < r[1]) f = false;
        if (d >= r[0]*r[0] && d < r[1]*r[1] && r[2+i] < r[1]) f = false;
        ans += f;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int qt = 1;
//    cin >> qt;
    for (int q = 1; q <= qt; q++) {
        solve();
    }
}
 	 	 				 	    	          	 		