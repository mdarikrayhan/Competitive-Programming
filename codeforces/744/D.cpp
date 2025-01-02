#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld eps = 1e-9;

bool geq (ld a, ld b) { return a - b >= -eps; }
bool leq (ld a, ld b) { return b - a >= -eps; }
bool ge (ld a, ld b) { return a - b > eps; }
bool le (ld a, ld b) { return b - a > eps; }
bool eq (ld a, ld b) { return abs(a - b) <= eps; }
bool neq (ld a, ld b) { return abs(a - b) > eps; }

struct point {
	ld x, y;
	point () : x(0), y(0) {}
	point (ld x, ld y) : x(x), y(y) {}

	point operator + (const point &p) const { return point(x + p.x, y + p.y); }
	point operator - (const point &p) const { return point(x - p.x, y - p.y); }
	point operator * (const ld &k) const { return point(x * k, y * k); }
	point operator / (const ld &k) const { return point(x / k, y / k); }

	point operator += (const point &p) { *this = *this + p; return *this; }
	point operator -= (const point &p) { *this = *this - p; return *this; }
	point operator *= (const ld &p) { *this = *this * p; return *this; }
	point operator /= (const ld &p) { *this = *this / p; return *this; }

	point perp () const { return point(-y, x); }
	ld dot (const point &p) const {return x * p.x + y * p.y; }
	ld cross (const point &p) const {return x * p.y - y * p.x; }
	ld norm () const { return x * x + y * y; }
	ld length () const { return hypot(x, y); }
	point unit () const { return (*this) / length(); }

	bool operator == (const point &p) const { return eq(x, p.x) && eq(y, p.y); }
	bool operator != (const point &p) const { return !(*this == p); }
	bool operator < (const point &p) const { return le(x, p.x) || (eq(x, p.x) && le(y, p.y)); }
	bool operator > (const point &p) const { return ge(x, p.x) || (eq(x, p.x) && ge(y, p.y)); }
	bool half (const point& p) const { return le(p.cross(*this), 0) || (eq(p.cross(*this), 0) && le(p.dot(*this), 0)); }
};

void convexHull (vector<point> &P, int f) {
	sort(all(P));
	vector<point> L, U;
	
	for (auto &p : P) {
		while (L.size() >= 2 && (f ? le : leq)((L.end()[-2] - p).cross(L.end()[-1] - p), 0))
			L.pop_back();
		L.push_back(p);
	}
	
	reverse(all(P));
	for (auto &p : P) {
		while (U.size() >= 2 && (f ? le : leq)((U.end()[-2] - p).cross(U.end()[-1] - p), 0))
			U.pop_back();
		U.push_back(p);
	}
	
	L.pop_back();
	U.pop_back();
	L.insert(L.end(), all(U));
	
	P = L;
}

ld distancePointLine (const point &a, const point &v, const point &p) {
	return abs(v.cross(p - a)) / v.length();
}

int n, m;
vector<point> a, b;

bool valid (const point &p, point &v, vector<point> &a, vector<point> &b, int ska) {
	if (eq(v.cross(p), 0))
		return 0;
	
	if (le(v.cross(p), 0)) {
		v.x = -v.x;
		v.y = -v.y;
	}
	
	int f = ska, g = 1;
	
	for (int i = 0; !f && i < (int)a.size(); i++)
		f |= geq(v.cross(a[i] - p), 0);
	
	for (int i = 0; g && i < (int)b.size(); i++)
		g &= leq(v.cross(b[i] - p), 0);
	
	return f && g;
}

ld go (const point &o) {
	vector<point> na, nb;
	
	forn (i, n) {
		na.pb(a[i] - o);
		na.back() *= 1e4 / na.back().norm();
	}
	
	forn (i, m) {
		if (b[i] == o)
			continue;
		nb.pb(b[i] - o);
		nb.back() *= 1e4 / nb.back().norm();
	}
	convexHull(nb, 0);
	
	shuffle(all(na), rng);
	
	ld res = 0;
	
	forn (i, nb.size()) {
		const auto &p = nb[i];
		auto v = (i + 1 == (int)nb.size() ? nb[0] : nb[i + 1]) - p;
		
		if (valid(p, v, na, nb, 0))
			res = max(res, (ld)1e4 / distancePointLine(p, v, {0, 0}));
	}
	
	forn (i, na.size()) {
		const auto &p = na[i];
		
		forn (j, nb.size()) {
			auto v = nb[j] - p;
		
			if (valid(p, v, na, nb, 1))
				res = max(res, (ld)1e4 / distancePointLine(p, v, {0, 0}));
		}
	}
	
	
	return res / 2;
}

void main_() {
	cin >> n >> m;
	
	forn (i, n) {
		int x, y;
		cin >> x >> y;
		a.pb({(ld)x, (ld)y});
	}

	forn (i, m) {
		int x, y;
		cin >> x >> y;
		b.pb({(ld)x, (ld)y});
	}
	
	auto P = a;
	P.insert(P.end(), all(b));
	
	convexHull(P, 1);
	
	for (point &p : P)
	forn (i, n)
		if (p == a[i]) {
			cout << -1 << endl;
			return;
		}
	
	ld res = 0;
	forn (i, m)
		res = max(res, go(b[i]));
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}
