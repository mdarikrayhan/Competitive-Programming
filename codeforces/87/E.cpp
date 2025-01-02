#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

using pt = complex<int>;
#define x real()
#define y imag()
template<class T> istream& operator>>(istream& in, complex<T>& o) {
    T X, Y; in >> X >> Y; o.real(X); o.imag(Y); return in;
}
template<class T> bool operator<=(const complex<T>& a, const complex<T>& b) {
    if (a.x == b.x) return a.y <= b.y;
    return a.x < b.x;
}
V<pt> pg[3];

V<pt> preprocess(V<pt> a) {
    pt mn = {inf, inf};
    int pos = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i].y < a[pos].y || a[i].y == a[pos].y && a[i].x < a[pos].x) {
            pos = i;
        } 
    }
    rotate(a.begin(), a.begin()+pos, end(a));
    a.pb(a[0]); a.pb(a[1]);
    return a;
}

V<pt> add(V<pt> a, V<pt> b) {
    a = preprocess(a);
    b = preprocess(b);

    V<pt> res;
    int i = 0, j = 0;
    while (i < a.size()-2 || j < b.size()-2) {
        res.pb(a[i]+b[j]);
        int cross = (conj(a[i+1]-a[i])*(b[j+1]-b[j])).y;
        int I = i, J = j;
        if (cross >= 0 && i < a.size()-2) {
            i++;
        }
        if (cross <= 0 && j < b.size()-2) {
            j++;
        }
        if (i == I && j == J) assert(false);
    }
    return res;
}

bool point_in_pg(const V<pt>& a, pt p) {
    int lo = 1, hi = a.size()-1;
    if ((conj(a[lo]-a[0])*(p-a[0])).y < 0) return false;
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;
        (conj(a[mid]-a[0])*(p-a[0])).y >= 0 ? lo = mid : hi = mid;
    }
    if ((conj(a[hi]-a[0])*(p-a[0])).y > 0) return false;
    return (conj(a[lo+1]-a[lo])*(p-a[lo])).y >= 0;    
}

void solve() {
    for (int i = 0; i < 3; i++) {
        int n; cin >> n;
        pg[i].resize(n);
        for (int j = 0; j < n; j++) cin >> pg[i][j];
    }

    auto sum = add(pg[0], pg[1]);
    sum = add(sum, pg[2]);

    int q; cin >> q;
    while (q--) {
        int X, Y; cin >> X >> Y; X *= 3; Y *= 3;
        cout << (point_in_pg(sum, {X, Y}) ? "YES" : "NO") << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
