#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

#define Point pair<double, pair<double, double> >
#define x first
#define y second.first
#define z second.second


const double PI = acos(-1);
const double EPS = 1e-8;
double R, H;


double dist(Point a, Point b)
{
Point c = { a.x - b.x , {a.y - b.y, a.z - b.z} };

return sqrt(c.x * c.x + c.y * c.y + c.z * c.z);
}

double ang(Point a)
{
return atan2(a.y, a.x);
}

double ldist(Point a, Point b)
{
Point p = { 0., {0., H} };

double d1 = dist(a, p);
double d2 = dist(b, p);

double dang = fabs(ang(a) - ang(b));
dang = min(dang, 2. * PI - dang);


return sqrt(d1 * d1 + d2 * d2 - 2. * d1 * d2 * cos(R * dang / sqrt(R * R + H * H)));
}

double solve(Point a, Point b, int f);

double F(Point a, Point b, Point c, int f)
{
if (!f) {
return dist(a, b) + ldist(b, c);
}
else {
return ldist(a, b) + solve(b, c, 0);
}
}

double solve(Point a, Point b, int f)
{


double ans = 1e9;
if (f) ans = ldist(a, b);

double s = 2. * PI / 3.;

for (int i = 0; i < 3; i++) {
double l = i * s;
double r = i * s + s + 0.1;

while(r - l > EPS) {
double c1 = (l * 2. + r) / 3.;
double c2 = (l + r * 2.) / 3.;

Point p1 = { R * cos(c1), {R * sin(c1), 0.} };
Point p2 = { R * cos(c2), {R * sin(c2), 0.} };


double val1 = F(a, p1, b, f);
double val2 = F(a, p2, b, f);


if (val1 < val2) {
r = c2;
}
else {
l = c1;
}
}

double c = (l + r) / 2.;

Point p = { R * cos(c), {R * sin(c), 0.} };
double val = F(a, p, b, f);

ans = min(ans, val);
}

return ans;
}





int main()
{
Point a, b;

cin >> R >> H;

cin >> a.x >> a.y >> a.z;
cin >> b.x >> b.y >> b.z;

if (a.z > b.z) swap(a, b);

cout << fixed << setprecision(15);

if (b.z == 0) {
cout << dist(a, b);
}
else {
cout << solve(a, b, a.z != 0.);
}

return 0;
}