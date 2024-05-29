#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
typedef pair<int, int> pii;
const int inf=INT_MAX;
const int maxn=1e6+10;

typedef long double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-11;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
    return abs(a - b) <= eps;
}

struct pt { // ponto
    ld x, y;
    pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
    bool operator < (const pt p) const {
        if (!eq(x, p.x)) return x < p.x;
        if (!eq(y, p.y)) return y < p.y;
        return 0;
    }
    bool operator == (const pt p) const {
        return eq(x, p.x) and eq(y, p.y);
    }
    pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
    pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
    ld operator * (const pt p) const { return x*p.x + y*p.y; }
    ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
    friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
    }
};
ld dist(pt p, pt q) { // distancia
    return hypotl(p.y - q.y, p.x - q.x);
}
pt rotate90(pt p) { // rotaciona 90 graus
    return pt(-p.y, p.x);
}
vector<pt> circ_inter(pt a, pt b, ld r, ld R) { // intersecao da circunf (a, r) e (b, R)
    vector<pt> ret;
    ld d = dist(a, b);
    if (d > r+R or d+fminl(r, R) < fmaxl(r, R)) return ret;
    ld x = (d*d-R*R+r*r)/(2*d);
    ld y = sqrtl(fabsl(r*r-x*x));
    pt v = (b-a)/d;
    ret.push_back(a+v*x + rotate90(v)*y);
    if (y > 0) ret.push_back(a+v*x - rotate90(v)*y);
    return ret;
}

int t1, t2;
pt c, h, s;

int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout); 
    #endif
    ios::sync_with_stdio(0);cin.tie(0);
    cout<< setprecision(10)<< fixed;

    cin>> t1>> t2>> c.x>> c.y>> h.x>> h.y>> s.x>> s.y;
    swap(t1, t2);
    ld ch = dist(c, h), cs = dist(c, s), hs = dist(h, s);
    auto check = [&](ld d)
    {
        ld rc = d, rh = ch + t1 - d, rs = cs + hs + t2 - hs - d;
        if(rc < -eps) return false;
        if(rh < -eps) return false;
        if(rs < -eps) return false;
        vector<pt> vec = circ_inter(c, h, rc, rh);
        vector<pt> aux = circ_inter(c, s, rc, rs);
        for(pt p: aux) vec.pb(p);
        aux = circ_inter(h, s, rh, rs);
        for(pt p: aux) vec.pb(p);
        vec.pb(c); vec.pb(h); vec.pb(s);
        bool found = false;
        for(pt p: vec)
            if(dist(c, p) <= rc + eps && dist(h, p) <= rh + eps && dist(s, p) <= rs + eps) found = true;
        return found;
    };
    const ld epsbs = 1e-15;
    ld lo = 0, hi = 100000;
    while(fabsl(hi-lo) > epsbs)
    {
        ld mid = (lo + hi) / 2;
        if(check(mid))
            lo = mid;
        else
            hi = mid;
    }
    if(cs+hs<=ch+t1)
    {
        // eles conseguem ir juntos pro shop e pra casa
        lo = fmaxl(lo, fminl(ch+t1, cs+hs+t2));
    }
    cout<< lo<< "\n";

    return 0;
}