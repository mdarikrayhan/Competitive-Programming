#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i=(b); i<(e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define PP(x,y) \
	auto operator<<(auto& o, auto a) \
	->decltype(y,o) { o<<"("; x; return o<<")"; }
PP(a.print(), a.print());
PP(o << a.x << ", " << a.y, a.y);
PP(for (auto i : a) o << i << ", ", all(a));
void DD(auto s, auto... k) {
	([&] {
		while (cerr << *s++, 45 % ~*s);
		cerr << ": " << k;
	}(), ...);
}
#ifdef LOC
auto SS = signal(6, [](int) { *(int*)0=0; });
#define deb(x...) \
	DD(":, "#x, __LINE__, x), cerr << endl
#else
#define deb(...)
#endif
#define DBP(x...) void print() { DD(#x, x); }

using sc = double;
constexpr sc eps = 1e-9;

// -1 if a < -eps, 1 if a > eps, 0 otherwise
int sgn(sc a) { return (a>eps) - (a < -eps); }

// 2D point/vector structure; UNIT-TESTED
struct vec {
	using P = vec;
	sc x = 0, y = 0;

	P operator+(P r) const {return{x+r.x,y+r.y};}
	P operator-(P r) const {return{x-r.x,y-r.y};}
	P operator*(sc r) const { return {x*r,y*r}; }
	P operator/(sc r) const { return {x/r,y/r}; }

	sc dot(P r)   const { return x*r.x + y*r.y; }
	sc cross(P r) const { return x*r.y - y*r.x; }
	sc len2()     const { return x*x + y*y; }
	double len()  const { return hypot(x, y); }
	P perp()      const { return {-y,x}; } // CCW

	// Equality (with epsilon)
	bool operator==(vec r) const {
		return !sgn(x-r.x) && !sgn(y-r.y);
	}

	// Lexicographic compare by (y,x) (with eps)
	int cmpYX(P r) const {
		return sgn(y-r.y) ?: sgn(x-r.x);
	}

	// Is above OX or on its non-negative part?
	bool upper() const {
		return (sgn(y) ?: sgn(x)) >= 0;
	}

	// Compare vectors by angles.
	// Depends on: cross, upper
	int cmpAngle(P r) const {
		return r.upper()-upper() ?: -sgn(cross(r));
	}
};

struct line {
	vec v;    // Normal vector
	sc c = 0; // Offset
	DBP(v, c);

	line norm() {
		sc s = v.len();
		return {v/s, c/s};
	}

	bool intersect(line a, vec& out) {
		sc d = v.cross(a.v);
		if (!sgn(d)) return 0;
		out = (v*a.c - a.v*c).perp() / d;
		return 1;
	}
};

// Line through 2 points with normal vector
// pointing to the right of ab vector.
// Depends on vec: -, cross, perp
line through(vec a, vec b) {
	return { (a-b).perp(), a.cross(b) };
}

// Parallel line through point.
// Depends on vec: dot
line parallel(vec a, line b) {
	return { b.v, b.v.dot(a) };
}

// Perpendicular line through point.
// Depends on vec: cross, perp
line perp(vec a, line b) {
	return { b.v.perp(), b.v.cross(a) };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<vec> p(n);
	each(e, p) {
		int x, y;
		cin >> x >> y;
		e = {double(x), double(y)};
	}

	constexpr double INF = 1e30;
	double ans = INF;
	vector<line> lines;

	auto check = [&](int i, int j, int k) {
		if (p[i] == p[j]) return;
		line l1 = through(p[i], p[j]).norm();
		line l2 = parallel(p[k], l1).norm();
		lines.pb({(l1.v+l2.v)/2, (l1.c+l2.c)/2});
	};

	rep(i, 0, n) rep(j, 0, n) {
		int k = (i+1) % n;
		check(i, j, k);
		check(i, k, j);
		check(j, k, i);
	}

	auto consider = [&](vec center) {
		vector<vec> points = p;
		each(q, p) points.pb(center*2-q);

		vec lowest = {INF, INF};
		each(q, points) if (q.cmpYX(lowest) < 0) lowest = q;
		erase(points, lowest);
		each(q, points) q = q-lowest;

		sort(all(points), [&](vec l, vec r) {
			return (l.cmpAngle(r) ?: sgn(l.len2()-r.len2())) < 0;
		});

		points.erase(unique(all(points)), points.end());

		while (sz(points) > 2) {
			vec a = points.back(), b = points[sz(points)-2];
			if (sgn(a.cross(b))) break;
			points.erase(points.end()-2);
		}

		rep(i, 0, sz(points)-2) {
			vec a = points[i], b = points[i+1], c = points[i+2];
			if ((b-a).cross(c-a) < -eps) return;
		}

		double alt = 0;
		rep(i, 0, sz(points)-1) {
			vec a = points[i], b = points[i+1];
			alt += a.cross(b);
		}

		alt /= 2;
		ans = min(ans, alt);
	};

	rep(i, 0, sz(lines)) {
		rep(j, i+1, sz(lines)) {
			vec c;
			if (lines[i].intersect(lines[j], c)) {
				consider(c);
			}
		}
	}

	if (ans < INF) {
		cout << ans << '\n';
	} else {
		cout << "-1\n";
	}
}
