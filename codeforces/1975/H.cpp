/**
 *    author:  tourist
 *    created: 25.05.2024 12:30:26
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int foo;
    cin >> foo;
    string s;
    cin >> s;
    auto Dfs = [&](auto&& self, vector<int> a) -> vector<int> {
      int n = int(a.size());
      if (n == 0) {
        return vector<int>();
      }
      sort(a.begin(), a.end());
      int sz = 1;
      for (int i = n - 2; i >= 0; i--) {
        if (a[i] == a[n - 1]) {
          sz += 1;
        } else {
          break;
        }
      }
      if (sz == 1) {
        return vector<int>(1, a[n - 1]);
      }
      vector<vector<int>> b;
      int rest = n - sz;
      int times = max(1, sz / (rest + 1));
      b.assign(sz, vector<int>(1, a[n - 1]));
      int start = times;
      int ptr = times;
      for (int i = 0; i < rest; i++) {
        if (b[ptr].size() == 1) {
          b[ptr].assign(times, a[n - 1]);
          b.resize(b.size() - (times - 1));
        }
        b[ptr].push_back(a[i]);
        if (i > 0 && a[i] != a[i - 1]) {
          start = ptr;
        }
        ptr += 1;
        if (ptr == sz) {
          ptr = start;
        }
      }
      vector<int> c(b.size());
      vector<int> any;
      for (int i = 0; i < int(b.size()); i++) {
        if (i == 0 || b[i] != b[i - 1]) {
          any.push_back(i);
        }
        c[i] = int(any.size()) - 1;
      }
      c.erase(c.begin(), c.begin() + times);
      auto got = self(self, c);
      for (int i = 0; i < times; i++) {
        got.push_back(0);
      }
      vector<int> res;
      for (int x : got) {
        for (int y : b[any[x]]) {
          res.push_back(y);
        }
      }
      return res;
    };
    vector<int> a(foo);
    for (int i = 0; i < foo; i++) {
      a[i] = int(s[i] - 'a');
    }
    auto res = Dfs(Dfs, a);
    for (int x : res) {
      cout << char(x + 'a');
    }
    cout << '\n';
  }
  return 0;
}
