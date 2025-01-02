#include <bits/stdc++.h>

typedef long long ll;

typedef std::complex <ll> P;

template <typename T> auto cross(T a, T b) {
	return std::imag(std::conj(a) * b);
}

template <typename T> double dot(T a, T b) {
	return std::real(std::conj(a) * b);
}

template <typename T> T sgn(T x) {
	return (x > (T) 0) - (x < (T) 0);
}

template <typename T = P> struct L {
	T u, v;
	template <typename U = ll> L(U _u = 0, U _v = 0) : u(_u), v(_v) { }
	bool on(T p) const {
		return !cross(u - p, v - p) && dot(u - p, v - p) <= 0;
	}
	bool intersects(L <T> l) const {
		T a = u, b = v, c = l.u, d = l.v;
		ll oa = cross(d - c, a - c);
		ll ob = cross(d - c, b - c);
		ll oc = cross(b - a, c - a);
		ll od = cross(b - a, d - a);
		if (sgn(oa) * sgn(ob) < 0LL && sgn(oc) * sgn(od) < 0LL) return true;
		return L <T> (c, d).on(a) || L <T> (c, d).on(b) || L <T> (a, b).on(c) || L <T> (a, b).on(d);
	}
	int side_of(T p) const {
		return sgn(cross(v - u, p - u));
	}
	T proj(T p) const {
		T V = v - u;
		return p - T(-V.imag(), V.real()) * cross(V, p - u) / std::norm(V);
	}
};

L <P> doub(L <P> l) {
	ll re = l.u.real() + 2 * (l.v.real() - l.u.real());
	ll im = l.u.imag() + 2 * (l.v.imag() - l.u.imag());
	l.v = { re, im };
	return l;
}

void read(P& p) {
	ll x, y; std::cin >> x >> y;
	p = P(x, y);
}

typedef std::complex <double> Pd;

Pd topd(P p) {
	return Pd(p.real(), p.imag());
}

Pd intersection(L <P> l1, L <P> l2) {
	double x1 = l1.u.real(), y1 = l1.u.imag();
	double x2 = l1.v.real(), y2 = l1.v.imag();
	double x3 = l2.u.real(), y3 = l2.u.imag();
	double x4 = l2.v.real(), y4 = l2.v.imag();
	double numx = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4);
	double denx = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	double numy = (x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4);
	double deny = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	return Pd(numx / denx, numy / deny);
}

#define YES { std::cout << "YES\n"; return 0; }
#define NO { std::cout << "NO\n"; return 0; }

int main() {
	P q1; read(q1);
	P q2; read(q2);
	L <P> w; read(w.u); read(w.v);
	L <P> m; read(m.u); read(m.v);
	P ext = doub(L(q1, m.proj(q1))).v;
	L s1(q1, q2), s2(ext, q2);
	if (!s1.intersects(w) && !s1.intersects(m)) YES;
	if (!s1.intersects(w) && s1.on(m.u) && s1.on(m.v)) YES;
	Pd in = intersection(L(ext, q2), m);
	L <Pd> ray1(topd(q1), in);
	L <Pd> ray2(in, topd(q2));
	L <Pd> wd(topd(w.u), topd(w.v));
	if (!s2.intersects(w) && s2.intersects(m) && !ray1.intersects(wd) && !ray2.intersects(wd)) YES;
	NO;
}
