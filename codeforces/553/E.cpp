// LUOGU_RID: 160557762
#include<cstdio>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;

char buf[1000000], *p1 = buf, *p2 = buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++)
inline int read() {
	int x = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return x;
}

namespace Poly {
	const int MAXN = 100005;
	const double Pi = acos(-1);
	int n, rev[MAXN];
	struct I {
		double x, y;
		inline I() {}
		inline I(double x, double y) : x(x), y(y) {}
		inline I& operator = (int o) { return x = o, y = 0, *this; }
		inline I& operator = (double o) { return x = o, y = 0, *this; }
		inline I operator + (const I &o) const { return I(x + o.x, y + o.y); }
		inline I operator - (const I &o) const { return I(x - o.x, y - o.y); }
		inline I operator * (const I &o) const {
			return I(x * o.x - y * o.y, x * o.y + y * o.x);
		}
		inline I operator / (const int &o) const { return I(x / o, y / o); }
		inline I operator / (const double &o) const { return I(x / o, y / o); }
	}f[MAXN], g[MAXN];
	inline void Init(int length) {
		int len = 1, l = -1;
		while (len < length) len <<= 1, ++ l;
		n = len;
		for (int i = 0; i < len; ++ i) f[i] = g[i] = 0;
		for (int i = 1; i < len; ++ i) 
			rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << l);
	}
	inline void FFT(I a[], int sgn) {
		for (int i = 1; i < n; ++ i)
			if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int flr = 2; flr <= n; flr <<= 1) {
			I Wn = (I){cos(2 * Pi / flr), sgn * sin(2 * Pi / flr)};
			for (int l = 0, mid = flr >> 1; l < n; l += flr) {
				I w, x, y; w = 1;
				for (int i = l; i < l + mid; ++ i, w = w * Wn)
					x = a[i], y = w * a[i + mid], 
					a[i] = x + y, a[i + mid] = x - y;
			}
		}
		if (!~sgn)
			for (int i = 0; i < n; ++ i)
				a[i] = a[i] / n;
	}
	inline void Times(int length, double a[], double b[], double c[]) {
		Init(length);
		for (int i = length; i < n; ++ i) a[i] = b[i] = 0;
		for (int i = 0; i < length; ++ i) f[i] = a[i];
		for (int i = 0; i < length; ++ i) g[i] = b[i];
		FFT(f, 1); FFT(g, 1);
		for (int i = 0; i < n; ++ i) f[i] = f[i] * g[i];
		FFT(f, -1);
		for (int i = 0; i < length; ++ i) c[i] = f[i].x;
	}
}

const int MAXN = 55, MAXM = 105;
const int MAXT = 20005;
const double INF = 1e10;

int n, m, t, X;
int fr[MAXM], to[MAXM];
double a[MAXT << 2], b[MAXT << 2]; 
double d[MAXN][MAXN], c[MAXM];
double p[MAXM][MAXT << 1];
double f[MAXN][MAXT << 1], g[MAXM][MAXT];

inline void cdq(int l, int r) {
	if (l == t) return;
	if (l == r) {
		for (int i = 1; i < n; ++ i) f[i][l] = INF;
		for (int i = 1; i <= m; ++ i)
			if (fr[i] ^ n) f[fr[i]][l] = min(f[fr[i]][l], g[i][l] + c[i]);
		return;
	}
	int mid = (l + r) >> 1; cdq(mid + 1, r);
	int l1 = r - l, l2 = r - mid;
	for (int i = 1; i <= m; ++ i) 
		if (fr[i] ^ n) {
			for (int j = 0; j < l1 + l2; ++ j) a[j] = b[j] = 0;
			for (int j = 0; j < l1; ++ j) a[j] = p[i][j + 1];
			for (int j = 0; j < l2; ++ j) b[j] = f[to[i]][r - j];
			Poly::Times(l1 + l2, a, b, a);
			for (int j = l; j <= mid; ++ j) g[i][j] += a[r - j - 1];
		}
	cdq(l, mid);
}

int main()
{
	n = read(), m = read(), t = read(), X = read();
	for (int i = 1; i <= n; ++ i)
		for (int j = 1; j <= n; ++ j)
			if (i ^ j) d[i][j] = INF;
	for (int i = 1, x; i <= m; ++ i) {
		fr[i] = read(), to[i] = read(), x = read();
		c[i] = d[fr[i]][to[i]] = x;
		for (int j = 1; j <= t; ++ j)
			x = read(), p[i][j] = x / 1e5;
	}
	for (int k = 1; k <= n; ++ k)
		for (int i = 1; i <= n; ++ i)
			for (int j = 1; j <= n; ++ j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 0; i < (t << 1); ++ i) f[n][i] = (i <= t) ? 0 : X;
	for (int i = 1; i < n; ++ i)
		for (int j = t; j < (t << 1); ++ j)
			f[i][j] = d[i][n] + X;
	cdq(0, (t << 1) - 1);
	printf ("%.10lf", f[1][0]);
	return 0;
}