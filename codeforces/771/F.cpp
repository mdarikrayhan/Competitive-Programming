#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()

const int Inf = 1e9;
const ll INF = 1e12;
const int maxn = 1e5;

using ld = long double;
const ld eps = 1e-9, inf = 1e6, pi = acos(-1);
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return fabs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return fabs(a-b) > eps;}  //a != b

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

int sgn(ld x){
	if(ge(x, 0)) return 1;
	if(le(x, 0)) return -1;
	return 0;
}

void polarSort(vector<point> & P, const point & o, const point & v){
	//sort points in P around o, taking the direction of v as first angle
	sort(P.begin(), P.end(), [&](const point & a, const point & b){
		return point((a - o).half(v), 0) < point((b - o).half(v), (a - o).cross(b - o));
	});
}

struct plane{
	point a, v;
	plane(): a(), v(){}
	plane(const point& a, const point& v): a(a), v(v){}
 
	point intersect(const plane& p) const{
		ld t = (p.a - a).cross(p.v) / v.cross(p.v);
		return a + v*t;
	}
 
	bool outside(const point& p) const{ // test if point p is strictly outside
		return le(v.cross(p - a), 0);
	}
 
	bool inside(const point& p) const{ // test if point p is inside or in the boundary
		return geq(v.cross(p - a), 0);
	}
 
	bool operator<(const plane& p) const{ // sort by angle
		auto lhs = make_tuple(v.half({1, 0}), ld(0), v.cross(p.a - a));
		auto rhs = make_tuple(p.v.half({1, 0}), v.cross(p.v), ld(0));
		return lhs < rhs;
	}
 
	bool operator==(const plane& p) const{ // paralell and same directions, not really equal
		return eq(v.cross(p.v), 0) && ge(v.dot(p.v), 0);
	}
};
 
vector<point> halfPlaneIntersection(vector<plane> planes){
	planes.push_back({{0, -inf}, {1, 0}});
	planes.push_back({{inf, 0}, {0, 1}});
	planes.push_back({{0, inf}, {-1, 0}});
	planes.push_back({{-inf, 0}, {0, -1}});
	sort(planes.begin(), planes.end());
	planes.erase(unique(planes.begin(), planes.end()), planes.end());
	deque<plane> ch;
	deque<point> poly;
	for(const plane& p : planes){
		while(ch.size() >= 2 && p.outside(poly.back())) ch.pop_back(), poly.pop_back();
		while(ch.size() >= 2 && p.outside(poly.front())) ch.pop_front(), poly.pop_front();
		if(p.v.half({1, 0}) && poly.empty()) return {};
		ch.push_back(p);
		if(ch.size() >= 2) poly.push_back(ch[ch.size()-2].intersect(ch[ch.size()-1]));
	}
	while(ch.size() >= 3 && ch.front().outside(poly.back())) ch.pop_back(), poly.pop_back();
	while(ch.size() >= 3 && ch.back().outside(poly.front())) ch.pop_front(), poly.pop_front();
	poly.push_back(ch.back().intersect(ch.front()));
	return vector<point>(poly.begin(), poly.end());
}

ld area(vector<point> & P){
	int n = P.size();
	ld ans = 0;
	for(int i = 0; i < n; i++){
		ans += P[i].cross(P[(i + 1) % n]);
	}
	return abs(ans / 2);
}

ld solve(){
    int n; cin>>n; n--;
    vector<point> v(n);
    int a11, b11; cin>>a11>>b11; point p0(a11, b11);
    for(int i = 0; i < n; i++){
        int a, b; cin>>a>>b; v[i] = point(a, b);
    }
    polarSort(v, p0, point(10, 0));
    vector<plane> vp;
    for(int i = 0; i < n; i++){
        int l = i + 1; if(l == n) l = 0;
        if(eq((v[l] - v[i]).cross(p0 - v[i]), 0)) return 0;
        int x = 1; if((v[l] - v[i]).cross(p0 - v[i]) < 0) x = -1;
        vp.pb(plane((v[i] + v[l]) / 2, (v[l] - v[i]) * x));
    }
    int l = 1;
    for(int i = 0; i < n; i++){
        if(l == i) l++; if(l == n) l = 0;
        while(i != l && (v[i] - p0).cross(v[l] - p0) > -eps){
            if(eq((v[i] - p0).cross(v[l] - p0), 0)) return 0;
            l++; if(l == n) l = 0;
        }
        if(i != l) if(eq((v[i] - p0).cross(v[l] - p0), 0)) return 0;
        if(l != i) l--; if(l < 0) l = n - 1;
        if(i != l) if(eq((v[i] - p0).cross(v[l] - p0), 0)) return 0;
        ld x = 1; if((v[l] - v[i]).cross(p0 - v[i]) < 0) x = -1;
        if(i != l) vp.pb(plane((v[l] + v[i]) / 2, (v[l] - v[i]) * x));
    }
    auto u = halfPlaneIntersection(vp);
    if((int) u.size() <= 2) return 0;
    return area(u);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--){
        cout<<setprecision(25)<<solve()<<'\n';
        //cout<<"-----------------"<<'\n';
    }
}