#include <bits/stdc++.h>
using namespace std;

// Holi c:

#define ll long long int
//#define ld long double
#define ii __int128
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()

const int Inf = 1e9;
const ll mod = 998244353;
const ll INF = 1e18;
const int maxn = 3e5 + 5;

using ld = long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

struct point{
	ld x, y;
	point(): x(0), y(0){}
	point(ld x, ld y): x(x), y(y){}

	point operator+(const point & p) const{return point(x + p.x, y + p.y);}
	point operator-(const point & p) const{return point(x - p.x, y - p.y);}
	point operator*(const ld & k) const{return point(x * k, y * k);}
	point operator/(const ld & k) const{return point(x / k, y / k);}

	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	point operator*=(const ld & p){*this = *this * p; return *this;}
	point operator/=(const ld & p){*this = *this / p; return *this;}

	point rotate(const ld & a) const{return point(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a));}
	point perp() const{return point(-y, x);}
	ld ang() const{
		ld a = atan2l(y, x); a += le(a, 0) ? 2*pi : 0; return a;
	}
	ld dot(const point & p) const{return x * p.x + y * p.y;}
	ld cross(const point & p) const{return x * p.y - y * p.x;}
	ld norm() const{return x * x + y * y;}
	ld length() const{return sqrtl(x * x + y * y);}
	point unit() const{return (*this) / length();}

	bool operator==(const point & p) const{return eq(x, p.x) && eq(y, p.y);}
	bool operator!=(const point & p) const{return !(*this == p);}
	bool operator<(const point & p) const{return le(x, p.x) || (eq(x, p.x) && le(y, p.y));}
	bool operator>(const point & p) const{return ge(x, p.x) || (eq(x, p.x) && ge(y, p.y));}
	bool half(const point & p) const{return le(p.cross(*this), 0) || (eq(p.cross(*this), 0) && le(p.dot(*this), 0));}
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}

point intersectlines(const point & a1, const point & v1, const point & a2, const point & v2){
	//lines a1+tv1, a2+tv2
	//assuming that they intersect
	ld det = v1.cross(v2);
	return a1 + v1 * ((a2 - a1).cross(v2) / det);
}

point inversion(point c, ld r, point a){
    return c + (a - c).unit() * (r * r / (a - c).length());
}

pair<point, ld> circumcenter(point a, point b, point c){
    point m0 = (a + b) / 2, m1 = (a + c) / 2;
    point d = intersectlines(m0, ((a - b).perp()).unit(), m1, ((a - c).perp()).unit());
    return {d, (d - a).length()};
}

int main(){
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int R, r, k; cin>>R>>r>>k;
        point c(0, R); ld r0 = r * 2;
        point at = inversion(c, r0, point(R * 2, R));
        ld r1 = r0 - at.x;
        point m(at.x + r1 / 2, R);
        m.y += r1 * k;
        point it = inversion(c, r0, point(m.x - r1 / 2, m.y)), et = inversion(c, r0, point(m.x + r1 / 2, m.y)), ot = inversion(c, r0, point(m.x, m.y + r1 / 2));
        auto res = circumcenter(it, et, ot);
        cout<<setprecision(20)<<res.se<<'\n';
    }
}