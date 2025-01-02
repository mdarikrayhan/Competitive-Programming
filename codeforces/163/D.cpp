/**
 * Author: Sergey Kopeliovich ([email protected])
 * Date: 2012.03.22
 */

#include <ctime>
#include <cmath>
#include <cstdio>
#include <cassert>

#include <map>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define mp make_pair

typedef long long ll;
typedef pair <ll, ll> pll;

double start = clock();
void TimeStamp()
{
  fprintf(stderr, "time = %.2f\n", (clock() - start) / CLOCKS_PER_SEC);
  start = clock();
}

const int maxP = 15;

int pn, mdeg[maxP], s[maxP];
int rn, rs[maxP];

map <ll, pair<pll, pll> > mem;

ll N1, N, C, rS, rA, rB, rC, p[maxP];
int A, B, num;

void go( int restx, int x, int i, int f )
{
  if (i == pn || restx < p[i])
  {
    if (!f)
    {
      A = x;
      N1 = N / A;
      long double B = sqrtl(N1);
      if (2 * A * B + N1 < rS)
      {
        forn(i, pn) mdeg[i] -= s[i];
        go((ll)sqrt(N1) + 1, 1, 0, 1);
        forn(i, pn) mdeg[i] += s[i];
      }
    }
    else
    {
      B = x, C = N1 / B;
      ll curS = (ll)A * (B + C) + N1;
      if (curS < rS)
        rS = curS, rA = A, rB = B, rC = C;
    }
    return;
  }
 
  int m = 0, _restx[64], _x[64];
  while (restx >= 1 && m <= mdeg[i])
  {
    _restx[m] = restx, _x[m++] = x;
    restx /= p[i], x *= p[i];
  }

  fornd(j, m)
  {
    if (!f)
      s[i] = j;
    go(_restx[j], _x[j], i + 1, f);
  }
}

int main()
{
#ifdef DEBUG
  double tmp_start = clock();
  fprintf(stderr, "Start\n");
#endif

  int T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &pn);
    assert(pn <= maxP);
    forn(i, pn)
      scanf(I64"%d", &p[i], &mdeg[i]);

    N = 1, num = 1;
    forn(i, pn)
    {
      forn(j, mdeg[i])
        N *= p[i];
      num *= mdeg[i] + 1;
    }
    forn(i, pn)
      forn(j, pn - 1)
        if (p[j] > p[j + 1])
          swap(p[j], p[j + 1]), swap(mdeg[j], mdeg[j + 1]);
    
    if (mem.count(N))
    {
      pair<pll, pll> p = mem[N];
      rS = p.first.first;
      rA = p.first.second;
      rB = p.second.first;
      rC = p.second.second;
    }
    else
    {
      rS = 3 * N + 1;
      go((ll)pow(N, 1.0 / 3) + 1, 1, 0, 0);
      mem[N] = mp(mp(rS, rA), mp(rB, rC));
    }
    printf(I64" "I64" "I64" "I64"\n", 2 * rS, rA, rB, rC);
  }

#ifdef DEBUG
  fprintf(stderr, "Total time = %.2f\n", (clock() - tmp_start) / CLOCKS_PER_SEC);
#endif
  return 0;
}