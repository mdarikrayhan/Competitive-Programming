/**
    author : archisman.juno1
    created : 21/05/2024
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else 
#define debug(...) 42
#endif
#define ll long long

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    vector<int> b(n);
    int L = 0, R = n;
    int pl = 0, pr = n - 1;
    bool fail = false;
    for (int it = 0; it < n; it++) {
      if (a[order[pl]] == L && a[order[pr]] != R) {
        b[order[pl]] = -(n - it);
        R -= 1;
        pl += 1;
        continue;
      }
      if (a[order[pl]] != L && a[order[pr]] == R) {
        b[order[pr]] = n - it;
        L += 1;
        pr -= 1;
        continue;
      }
      fail = true;
      break;
    }
    if (fail) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}