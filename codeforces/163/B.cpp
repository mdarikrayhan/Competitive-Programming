/**
 * Author: Sergey Kopeliovich ([email protected])
 * Date: 2012.03.24
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxN = (int)1e5;

int N, K, H, m[maxN], v[maxN], p[maxN], o[maxN];

inline bool mless( int i, int j )
{
  #define F(x) make_pair(m[x], v[x])
  return F(i) < F(j);
}

int solve( double t )
{
  int x = 1;
  forn(i, N)
    if (v[p[i]] * t >= (double)x * H)
      o[x++ - 1] = p[i];
  return x > K;
}

int main()
{
  scanf("%d%d%d", &N, &K, &H);
  forn(i, N)
    scanf("%d", &m[i]);
  forn(i, N)
    scanf("%d", &v[i]);
  forn(i, N)
    p[i] = i;
  sort(p, p + N, mless);

  double mi = 0, ma = (double)H * K, t;
  forn(tt, 100)
    if (solve(t = (mi + ma) / 2))
      ma = t;
    else
      mi = t;
  assert(solve(ma));

  //printf("%.9f\n", mi);
  forn(i, K)
    printf("%d ", o[i] + 1);
  return 0;
}