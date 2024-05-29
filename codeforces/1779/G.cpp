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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
      cin >> s[i];
    }
    vector<vector<int>> v(2);
    for (int i = 0; i < 3; i++) {
      int cnt = 0;
      for (int j = n - 1; j >= 0; j--) {
        if (s[i][j] == s[i].back()) {
          cnt += 1;
        } else {
          break;
        }
      }
      v[(int) (s[i].back() - '0')].push_back(cnt);
    }
    int ans = 0;
    for (int x : v[0]) {
      for (int y : v[1]) {
        ans += min(x, y);
      }
    }
    cout << min(ans, n) << '\n';
  }
  return 0;
}