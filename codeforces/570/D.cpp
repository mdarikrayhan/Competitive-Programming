/**
 *  author:  Jotinha (ツ)
 *  created: 05-27-2024 20:47:07
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
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for(int i = 1; i < n; i++) {
    int u;
    cin >> u;
    --u;
    g[u].push_back(i);
  }
  string s;
  cin >> s;
  vector<vector<pair<int, int>>> qr(n);
  for(int i = 0; i < q; i++) {
    int v, h;
    cin >> v >> h;
    --v, --h;
    qr[v].push_back({h, i});
  }
  vector<int> dep(n), id(n), sz(n);
  vector<map<int, map<short int, int>>> v(n);
  vector<bool> ans(q);
  function<void(int, int)> dfs = [&](int u, int p) {
    int big = -1;
    for(int nxt : g[u]) {
      if(nxt != p) {
        dep[nxt] = dep[u] + 1;
        dfs(nxt, u);
        if(big == -1 or sz[id[big]] < (int) sz[id[nxt]]) {
          big = nxt;
        }
      }
    }
    if(big == -1) {
      big = u;
      id[u] = u;
    } else {
      for(int nxt : g[u]) {
        if(nxt == p or nxt == big) {
          continue;
        }
        for(const auto& x : v[id[nxt]]) {
          for(const auto& y : x.second) {
            if(!v[id[big]][x.first][y.first]) {
              sz[id[big]] += 1;
            }
            v[id[big]][x.first][y.first] += y.second;
          }
        }
      }
    }
    id[u] = id[big];
    if(!v[id[u]][dep[u]][s[u]]) {
      sz[id[u]] += 1;
    }
    v[id[u]][dep[u]][s[u]] += 1;
    for(auto [i, j] : qr[u]) {
      int odd = 0;
      for(auto x : v[id[u]][i]) {
        odd += x.second % 2;
        if(odd > 1) {
          break;
        }
      }
      ans[j] = (bool) (odd < 2);
    }
  };
  dfs(0, -1);
  for(int i = 0; i < q; i++) {
    cout << (ans[i] ? "Yes" : "No") << '\n';
  }
  return 0;
}