#include <stdio.h>
#include <complex>
#include <utility>
#include <algorithm>

using namespace std;

typedef complex<double> point;
#define X real()
#define Y imag()
typedef pair<point, point> line;
typedef point vec;
const double ESP = 1e-6;

int dcmp(double d)
{ return (d > ESP) - (d < -ESP); }

double cross(vec a, vec b)
{ return a.X * b.Y - b.X * a.Y; }

double cross(point a, point b, point c)
{ return cross(b - a, c - a); }

double dot(vec a, vec b)
{ return a.X * b.X + a.Y * b.Y; }

double dot(point a, point b, point c)
{ return dot(b - a, c - a); }

vec dir(line ln)
{ return ln.second - ln.first; }

int n;
const int MAXN = 500;
point p[MAXN][5];
double tot1, tot2;
pair<double, int> c[MAXN * 4];

double area2(point *p)
{
	double s = 0;
	for (int i = 0; i < 4; ++i) {
		s += cross(p[i], p[i + 1]);
	}
	return s;
}

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		scanf("%d%d%d%d%d%d%d%d",
		      &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
		p[i][0] = p[i][4] = point(x1, y1);
		p[i][1] = point(x2, y2);
		p[i][2] = point(x3, y3);
		p[i][3] = point(x4, y4);
		double s = area2(p[i]);
		if (s < 0) swap(p[i][1], p[i][3]), s = -s;
		tot1 += s;
	}
}

double pos(point p, line ln)
{ return dot(p - ln.first, dir(ln)) / norm(dir(ln)); }

void solve()
{
	for (int i = 0; i < n; ++i) for (int ii = 0; ii < 4; ++ii) {
		point A = p[i][ii], B = p[i][ii + 1];
		line AB = line(A, B);
		int m = 0;
		for (int j = 0; j < n; ++j) if (i != j) for (int jj = 0; jj < 4; ++jj) {
			point C = p[j][jj], D = p[j][jj + 1];
			line CD = line(C, D);
			int f1 = dcmp(cross(A, B, C));
			int f2 = dcmp(cross(A, B, D));
			if (!f1 && !f2) {
				if (i < j && dcmp(dot(dir(AB), dir(CD))) > 0) {
					c[m++] = make_pair(pos(C, AB), 1);
					c[m++] = make_pair(pos(D, AB), -1);
				}
			} else {
				double s1 = cross(C, D, A);
				double s2 = cross(C, D, B);
				double t = s1 / (s1 - s2);
				if (f1 >= 0 && f2 < 0) c[m++] = make_pair(t, 1);
				if (f1 < 0 && f2 >= 0) c[m++] = make_pair(t, -1);
			}
		}
		c[m++] = make_pair(0.0, 0);
		c[m++] = make_pair(1.0, 0);
		sort(c, c + m);
		double s = 0, z = min(max(c[0].first, 0.0), 1.0);
		for (int j = 1, k = c[0].second; j < m; ++j) {
			double w = min(max(c[j].first, 0.0), 1.0);
			if (!k) s += w - z;
			k += c[j].second;
			z = w;
		}
		tot2 += s * cross(A, B);
	}
}

int main()
{
	init();
	solve();
	printf("%.10lf\n", tot1 / tot2);
}