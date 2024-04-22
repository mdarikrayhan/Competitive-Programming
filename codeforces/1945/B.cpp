#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "debug.h"  // https://github.com/Heltion/debug.h/blob/main/debug.h
#else
#define debug(...) (void)20240319
#endif
using i64 = int64_t;
using u64 = uint64_t;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti += 1) {
    i64 a, b, m;
    cin >> a >> b >> m;
    cout << m / a + m / b + 2 << "\n";
  }
}