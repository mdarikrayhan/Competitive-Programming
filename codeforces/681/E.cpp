#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

using uint = unsigned int;
using ull = unsigned long long;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif


template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

using P = Point<double>;

const double PI = acos(0) * 2;

const double EPS = 1e-9;

void solve(){
    int x0, y0, v, T;
    cin >> x0 >> y0 >> v >> T;
    double R = (ll) v * T;
    
    int n;
    cin >> n;
    vi x(n), y(n), r(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
        x[i] -= x0;
        y[i] -= y0;
    }

    cout << fixed << setprecision(20);

    for(int i = 0; i < n; i++) {
        if((ll) x[i] * x[i] + (ll) y[i] * y[i] <= (ll) r[i] * r[i]) {
            cout << 1.0 << endl;
            return;
        }
    }

    auto norm = [&](double x) {
        while(x >= 2 * PI) {
            x -= 2 * PI;
        }
        while(x < 0) {
            x += 2 * PI;
        }
        return x;
    };

    vector<pair<double, int>> event;
    int off = 0;
    for(int i = 0; i < n; i++) {
        double arg = atan2(y[i], x[i]);
        double d = sqrt((double) x[i] * x[i] + (double) y[i] * y[i]);
        if(d >= R + r[i] - EPS) {
            continue;
        }
        double theta;
        if(d * d >= (double) r[i] * r[i] + R * R) {
            debug("far");
            theta = acos((R * R + d * d - (double) r[i] * r[i]) / (2.0 * R * d));
        } else {
            debug("near");
            theta = asin(r[i] / d);
        }
        debug(i, arg, theta);
        double lo = norm(arg - theta);
        double hi = norm(arg + theta);
        if(lo > hi) {
            off++;
        }
        event.push_back({lo, 1});
        event.push_back({hi, -1});
    }
    event.push_back({2 * PI, 0});
    sort(event.begin(), event.end());
    debug(event, off);
    double last = 0;
    double on = 0;
    for(pair<double, int> p : event) {
        double arg;
        int chg;
        tie(arg, chg) = p;
        if(off == 0) {
            on += (arg - last);
        }
        off += chg;
        last = arg;
    }
    cout << 1.0 - on / (2.0 * PI) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
