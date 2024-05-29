//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int bubbleGum = 0;
#ifdef RODYA
#define FAST_IO 0;
#include "Templates/Debug template.cpp"
#else
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define dbg(...) ++bubbleGum
#define dbgArr(x) ++bubbleGum
#endif


#define vec vector
#define eb emplace_back
#define pb push_back
#define sz(v) (int)(v.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mp(a, b) make_pair(a, b)
#define endl "\n"
#define lb(a, b) lower_bound(all(a), b)
#define ub(a, b) upper_bound(all(a), b)



using pii = pair<int, int>;

const int N = 1505;


inline ll sq(int x) { return 1LL * x * x; }

int n, m;
map<vec<int>, vec<pii>> starts, fins;
vec<int> circles[N];


vec<int> getLine(int x, int y, int x2, int y2) {
    int a = y2 - y, b = x - x2;
    int g = __gcd(abs(a), abs(b));
    a /= g, b /= g;
    if (a < 0 || (a == 0 && b < 0))
        a *= -1, b *= -1;
    int c = -a * x - b * y;
    return {a, b, c};
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        x *= 2, y *= 2, x2 *= 2, y2 *= 2;
        vec<int> line = getLine(x, y, x2, y2);

        pii sta = mp(x, y), fin = mp(x2, y2);
        if (sta > fin) swap(sta, fin);
        starts[line].eb(sta);
        fins[line].eb(fin);
        dbg(line);
    }
    for (auto& [_, it] : starts)
        sort(all(it));
    for (auto& [_, it] : fins)
        sort(all(it));

    for (int i = 1; i <= m; ++i) {
        int x, y, r; cin >> x >> y >> r;
        circles[i] = {x * 2, y * 2, r * 2};
    }
}



void solve() {
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            auto e = circles[i], f = circles[j];
            int x1 = e[0], y1 = e[1], r1 = e[2];
            int x2 = f[0], y2 = f[1], r2 = f[2];
            if (r1 != r2) continue;
            if (sq(x2 - x1) + sq(y2 - y1) <= sq(r1 + r2)) continue;

            int x = (x1 + x2) / 2, y = (y1 + y2) / 2;
            vec<int> line = getLine(x1, y1, x2, y2);
            int xx = x + line[0], yy = y + line[1];
            line = getLine(x, y, xx, yy);
            if (starts.find(line) == starts.end()) continue;

            int total = sz(starts[line]);
            int one = starts[line].end() - ub(starts[line], mp(x, y));
            int two = lb(fins[line], mp(x, y)) - fins[line].begin();
            ans += total - one - two;
        }
    }

    cout << ans << endl;
}



signed main() {
#ifdef RODYA
    setLocalThings();
#endif
    FAST_IO


    input();
    solve();


}

/*



 */

