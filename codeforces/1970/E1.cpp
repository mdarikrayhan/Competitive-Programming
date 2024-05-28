/* -*- coding: utf-8 -*-
 *
 * 1970E1.cc: E1. Trails (Easy)
 */

#include<cstdio>
#include<algorithm>

using namespace std;

/* constant */

const int MAX_N = 1000;
const int MAX_M = 100;
const int MOD = 1000000007;

/* typedef */

template<const int MOD>
struct MI {
  int v;
  MI(): v() {}
  MI(int _v): v(_v % MOD) { if (v < 0) v += MOD; }
  MI(long long _v): v(_v % MOD) { if (v < 0) v += MOD; }

  explicit operator int() const { return v; }
  
  MI operator+(const MI m) const { return MI(v + m.v); }
  MI operator-(const MI m) const { return MI(v + MOD - m.v); }
  MI operator*(const MI m) const { return MI((long long)v * m.v); }

  MI &operator+=(const MI m) { return (*this = *this + m); }
  MI &operator-=(const MI m) { return (*this = *this - m); }
  MI &operator*=(const MI m) { return (*this = *this * m); }

  bool operator==(const MI m) const { return v == m.v; }
  bool operator!=(const MI m) const { return v != m.v; }

  MI pow(int n) const {  // a^n % MOD
    MI pm = 1, a = *this;
    while (n > 0) {
      if (n & 1) pm *= a;
      a *= a;
      n >>= 1;
    }
    return pm;
  }

  MI inv() const { return pow(MOD - 2); }
  MI operator/(const MI m) const { return *this * m.inv(); }
  MI &operator/=(const MI m) { return (*this = *this / m); }
};

typedef MI<MOD> mi;

/* global variables */

int ss[MAX_M], ls[MAX_M];
mi dp[MAX_N + 1][MAX_M];

/* subroutines */

/* main */

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++) scanf("%d", ss + i);
  for (int i = 0; i < m; i++) scanf("%d", ls + i);

  dp[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (dp[i][j] != 0) {
	for (int k = 0; k < m; k++) {
	  int d = (ss[j] + ls[j]) * (ss[k] + ls[k]) - ls[j] * ls[k];
	  dp[i + 1][k] += dp[i][j] * d;
	}
      }

  mi sum = 0;
  for (int j = 0; j < m; j++) sum += dp[n][j];

  printf("%d\n", (int)sum);
  
  return 0;
}
