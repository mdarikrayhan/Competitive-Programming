/**
 * Author: Sergey Kopeliovich ([email protected])
 * Date: 2012.03.25
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef double dbl;

const int maxN = (int)1e5 + 3;

int dn, n, l, v1, v2;
dbl a[maxN * 2];
dbl dist, d[2 * maxN], p[maxN];

dbl cor( dbl x )
{
  return x < 0 ? x + 2 * l : x;
}

int k( dbl L )
{
  return lower_bound(a, a + 2 * n, L + dist) - lower_bound(a, a + n, L);
}

int main()
{
  scanf("%d%d%d%d", &n, &l, &v1, &v2); 
  forn(i, n)
    scanf("%lf", &a[i]);
  sort(a, a + n);
  forn(i, n)
    a[i + n] = a[i] + 2 * l;

  dist = (dbl)v2 * l / (v1 + v2);
  d[dn++] = 0, d[dn++] = 2 * l;
  forn(i, n)
    d[dn++] = a[i], d[dn++] = cor(a[i] - dist);
  sort(d, d + dn);
  forn(i, dn - 1)
    p[k((d[i] + d[i + 1]) / 2)] += d[i + 1] - d[i];
  forn(i, n + 1)
    printf("%.20f\n", (double)p[i] / (2 * l));  
  return 0;
}
