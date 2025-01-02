/*
 * author:  ADMathNoob
 * created: 05/06/24 10:11:12
 * problem: https://codeforces.com/contest/1572/problem/E
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

const int N = 205;

int n, k;
long long x[N], y[N];

int best[N][N];
long long space[N][N];

long long TwiceArea(int i, int j, int l) {
  long long ret = 0;
  ret += x[i] * y[j] - x[j] * y[i];
  ret += x[j] * y[l] - x[l] * y[j];
  ret += x[l] * y[i] - x[i] * y[l];
  return ret;
}

bool Works(long long T) {
  for (int len = 1; len < n; len++) {
    for (int L = 0; L < n; L++) {
      int R = (L + len) % n;
      best[L][R] = space[L][R] = 0;
      if (len == 1) {
        continue;
      }
      for (int t = 1; t < len; t++) {
        int M = (L + t) % n;
        int cnt = best[L][M] + best[M][R];
        long long rem = TwiceArea(L, M, R) + space[L][M] + space[M][R];
        if (rem >= T) {
          cnt += 1;
          rem = 0;
        }
        if (cnt > best[L][R]) {
          best[L][R] = cnt;
          space[L][R] = rem;
        } else if (cnt == best[L][R]) {
          space[L][R] = max(space[L][R], rem);
        }
      }
    }
  }
  for (int L = 0; L < n; L++) {
    for (int len = 1; len < n; len++) {
      int R = (L + len) % n;
      int cnt = best[L][R] + best[R][L];
      long long rem = space[L][R] + space[R][L];
      if (rem >= T) {
        cnt += 1;
        rem = 0;
      }
      if (cnt >= k + 1) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  long long low = 1;
  long long high = 1e18 / (k + 1);
  while (low < high) {
    long long mid = (low + high + 1) / 2;
    if (Works(mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << low << '\n';
  return 0;
}
