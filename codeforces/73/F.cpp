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
const ld eps = 1e-4, inf = 1e9, pi = acos(-1);
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

	point rotate(const ld & a) const{return point(x * cosl(a) - y * sinl(a), x * sinl(a) + y * cosl(a));}
	point perp() const{return point(-y, x);}
	ld ang() const{
		ld a = atan2l(y, x); a += le(a, 0) ? 2*pi : 0; return a;
	}
	ld dot(const point & p) const{return x * p.x + y * p.y;}
	ld cross(const point & p) const{return x * p.y - y * p.x;}
	ld norm() const{return x * x + y * y;}
	ld length() const{return sqrtl(x * x + y * y);}
	point unit() const{return (*this) / length();}
	
};

istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}

point intersectLines(const point & a1, const point & v1, const point & a2, const point & v2){
	ld det = v1.cross(v2);
	return a1 + v1 * ((a2 - a1).cross(v2) / det);
}

ld fastReadDouble(string s){
    int32_t res = 0, res2 = 0, res2_10_pow = 1;
    bool first = true;
    for(int32_t i = 0; i < s.size(); i++) {
        if(first) {
            if(s[i] == '.') {
                first = false;
            } else
                res = res * 10 + s[i] - '0';
        } else {
            res2 = res2 * 10 + s[i] - '0';
            res2_10_pow *= 10;
        }
    }
    return res + (ld) res2 / res2_10_pow;
}

bool pointInLine(const point & a, const point & v, const point & p){
	//line a+tv, point p
	return eq((p - a).cross(v), 0);
}

bool pointInSegment(const point & a, const point & b, const point & p){
	//segment ab, point p
	return pointInLine(a, b - a, p) && leq((a - p).dot(b - p), 0);
}

ld f1(point a, point b, point c, point d, ld v0, ld t, point e){
    ld at = v0 * t;
    point it = intersectLines(a, b - a, c, d - c);
    ld et = (it - a).length();
    if(pointInSegment(a, b, it) == 0){
        //cout<<"Linea de vision en: "<<c<<" con "<<d<<'\n'<<"Con interseccion en: "<<it<<'\n'<<"Iniciando en el punto: "<<e<<'\n';
        return -Inf;
    }
    return et - at;
}

bool f(point ct, point at, point a, point b, ld v0, ld t0, ld t1, ld v2, ld x){
    //Ternaria sobre el tiempo maximizando ((b - a).unit() * v0 * t).length() - (intersectLines() - a).length() 
    //cout<<ct<<"------";
    ld l = t0, r = t1;
    if(r < l) return false;
    //cout<<l<<" "<<r<<'\n';
    for(int i = 0; i < 50; i++){
        ld m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        ld w1 = (m1 - t0) * v2, w2 = (m2 - t0) * v2;
        if(x){
            w1 = (ld) 2 * pi - w1; w2 = (ld) 2 * pi - w2;
        }
        point r1 = ct + (at - ct).rotate(w1), r2 = ct + (at - ct).rotate(w2);
        ld s1 = f1(a, b, ct, r1, v0, m1, at), s2 = f1(a, b, ct, r2, v0, m2, at);
        if(s1 < s2) l = m1;
        else r = m2;
    }
    //cout<<v0<<" & "<<l<<" -> "<<ct<<" "<<ct + (at - ct).rotate((l - t0) * v2)<<" | "<<f1(a, b, ct, ct + (at - ct).rotate((l - t0) * v2), v0, l)<<'\n';
    //if(f1(a, b, ct, ct + (at - ct).rotate((l - t0) * v2), v0, l) > eps) cout<<a + (b - a).unit() * l * v0<<", "<<l<<'\n';
    ld w1 = (l - t0) * v2; if(x) w1 = pi * 2 - w1;
    if(f1(a, b, ct, ct + (at - ct).rotate(w1), v0, l, at) > eps) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int y1, y2, y3, y4; cin>>y1>>y2>>y3>>y4;
    point in(y1, y2), fi(y3, y4);
    int n; cin>>n;
    ld v[n][4] = {};
    for(int i = 0; i < n; i++){
        int a, b; string s, z; cin>>a>>b>>s>>z; 
        v[i][0] = a; v[i][1] = b; v[i][2] = fastReadDouble(s); v[i][3] = fastReadDouble(z);
    }
    int k; cin>>k;
    if(k == n){
        cout<<0; return 0;
    }
    vector<ld> ts;
    for(int i = 0; i < n; i++){
        if(!v[i][3]){ continue;}
        point at(10000, 0), p0(v[i][0], v[i][1]);
        at = p0 + at.rotate(v[i][2]);
        //cout<<at<<'\n';
        point a = at - p0, b = fi - p0, c = in - p0;
        ld tet1 = acosl(a.dot(b) / a.length() / b.length());
        ld tet0 = acosl(a.dot(c) / a.length() / c.length());
        if(tet1 <= tet0 + eps){
            ts.pb((in - fi).length() / (tet1 / v[i][3]));
            continue;
        }
        //Binaria sobre la velocidad
        at = in;
        point it = intersectLines(in, fi - in, p0, (fi - in).perp());
        if(!pointInSegment(in, fi, it)) it = fi;
        //cout<<at<<" "<<it<<'\n';
        ld tet2 = acosl(a.dot(it - p0) / a.length() / (it - p0).length());
        ld x = 0;
        if((in - p0).cross(it - p0) < -eps) x = 1;
        /*if(tet1 <= tet2 + eps){
            ts.pb((in - fi).length() / (tet1 / v[i][3]));
            continue;
        }*/
        ld l = (in - fi).length() / (tet1 / v[i][3]), r = Inf;
        //cout<<l<<" ";
        //cout<<l<<" "<<r<<'\n';
        for(int j = 0; j < 50; j++){
            ld m = (l + r) / 2;
            if(f(p0, at, in, it, m, tet0 / v[i][3], min((tet0 + tet2) / v[i][3], (in - it).length() / m), v[i][3], x)) l = m;
            else r = m;
        }
        //cout<<r<<'\n';
        ts.pb(r);
    }
    sort(all(ts));
    //for(auto e : ts) cout<<e<<" ";
    if(k >= ts.size()){
        cout<<0; return 0;
    }
    cout<<fixed<<setprecision(4)<<ts[(int)ts.size() - k - 1];
}