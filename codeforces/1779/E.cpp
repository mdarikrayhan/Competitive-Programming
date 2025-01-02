/**
    author : archisman.juno1
    created : 24/05/2024
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
  int n;
  cin >> n;
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    string s(n, '1');
    s[i] = '0';
    cout << "? " << i + 1 << " " << s << endl;
    cin >> deg[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return deg[i] > deg[j];
  });
  string res(n, '0');
  for (int i = 1; i <= n; i++) {
    res[order[i - 1]] = '1';
    int sum = 0;
    for (int j = 0; j < i; j++) {
      sum += deg[order[j]];
    }
    sum -= i * (i - 1) / 2;
    if (sum == i * (n - i)) {
      cout << "! " << res << endl;
      return 0;
    }
  }
  assert(false);
  return 0;
}
