#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<int, int> ii;
typedef long long ll;
typedef ll ftype;

struct P {
    ftype x, y;
    P operator+(const P &p) const { return {x + p.x, y + p.y}; }
    P operator-(const P &p) const { return {x - p.x, y - p.y}; }
    P operator*(ftype c) const { return {x * c, y * c}; }
    ftype operator*(P q) const { return x * q.y - y * q.x; }
    P operator/(ftype c) const { return {x / c, y / c}; }
    ftype angle() const {
        return atan2(y, x);
    }
    P RotateCCW90() const { return {-y, x}; }
    P RotateCW90() const { return {y, -x}; }
    ftype size2() const {
        return x * x + y * y;
    }
    ftype size() const {
        return sqrt(size2());
    }
};
ftype dot(P p, P q) { return p.x * q.x + p.y * q.y; }
ftype dist2(P p, P q) { return (p - q).size2(); }
ftype dist(P p, P q) { return (p - q).size(); }
ostream &operator<<(ostream &os, const P &p) {
    return os << "(" << p.x << "," << p.y << ")";
}

int sgn(ll x) {
    return (x < 0 ? -1 : (x > 0 ? 1 : 0));
}

bool between(P a, P b, P c) {
    return sgn(dot(a-c, b-c)) < 0;   
}

void solve(const vector<P> &poly, const P& p) {
    int n = poly.size();
    ll ans = ll(n) * (n-1) * (n-2) / 6;

    auto get = [&](int i, int off) {
        auto &&c = poly[i];
        auto &&q = poly[(i + off) % n];
        
        return sgn((p-c) * (q-c));
    };
    auto check = [&](int i, int j, int k) {
        auto pi = poly[i];
        auto pj = poly[j];
        auto pk = poly[k];

        return  abs((p - pi) * (pj - pi)) +
                abs((p - pi) * (pk - pi)) +
                abs((p - pk) * (pj - pk)) == abs((pj - pi) * (pk - pi));
    };

    for(int i=0 ; i<n ; i++) {
        int l = 1, r=n-1;
        int gl = get(i, l);
        int gr = get(i, r);
        if(gl == gr)
            continue;
        
        while(r-l > 1) {
            int mid = (l + r) / 2;
            int cur = get(i, mid);
            if(cur == gr)
                r = mid;
            else
                l = mid;
        }

        if(!check(i, (i+l) % n, (i+r) % n)) {
            cout << "0\n";
            return;
        }
        
        // cerr << i << ", " << l << ", " << r << " ** \n";
        if(i + l >= n) {
            ll cnt = (n-i-1);
            if(cnt>1)
                ans -= cnt * (cnt-1) / 2;
            continue;
        }
        ans -= ll(l) * (l-1) / 2;

        ll cnt = (n-r-i);
        // cerr << "now " << cnt << "\n";
        if(cnt > 1)
            ans -= cnt * (cnt - 1) / 2;
        ans -= cnt * i;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin >> n;
    vector<P> poly(n);
    for(int i=0 ; i<n ; i++) {
        cin >> poly[i].x >> poly[i].y;
    }

    int t;cin >> t;
    while(t --) {
        int x, y;cin >> x >> y;
        solve(poly, P{x, y});
    }
}