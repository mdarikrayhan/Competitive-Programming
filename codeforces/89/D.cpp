#include <cstdio>
#include <cmath>
const double eps = 1e-12;
int N, M, i, j;
double Ans, tmp, Ax, Ay, Az, Vx, Vy, Vz, R, r, px, py, pz, Ox, Oy, Oz;
double Get() {
double a = Vx * Vx + Vy * Vy + Vz * Vz;
double b = 2 * Vx * px + 2 * Vy * py + 2 * Vz * pz;
double c = px * px + py * py + pz * pz - r * r;
double d = b * b - 4 * a * c;
if (d < -eps || b - sqrt(d) < -eps)
return 1e63;
return (b - sqrt(d)) / 2 / a;
}
int main()
{
scanf("%lf%lf%lf%lf%lf%lf%lf", &Ax, &Ay, &Az, &Vx, &Vy, &Vz, &R);
scanf("%d", &N);
Ans = 1e63;
for (i = 1; i <= N; ++i) {
scanf("%lf%lf%lf%lf%d", &Ox, &Oy, &Oz, &r, &M);
px = Ox - Ax, py = Oy - Ay, pz = Oz - Az, r += R;
tmp = Get();
if (tmp < Ans)
Ans = tmp;
r = R;
for (j = 1; j <= M; ++j) {
scanf("%lf%lf%lf", &px, &py, &pz);
px += Ox - Ax, py += Oy - Ay, pz += Oz - Az;
tmp = Get();
if (tmp < Ans)
Ans = tmp;
}
}
if (Ans > 1e62)
printf("-1\n");
else
printf("%.9lf\n", Ans);
return 0;
}
