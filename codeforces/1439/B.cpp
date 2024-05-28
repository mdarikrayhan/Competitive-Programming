/**
 *    author: tourist
 *    created:
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<int> d(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
      ++d[u];
      ++d[v];
    }
    long long need = (int64_t(k) * int64_t(k - 1)) / 2;
    if (need > m) {
      cout << -1 << '\n';
      continue;
    }
    set<pair<int, int>> st;
    for (int v = 0; v < n; v++) {
      st.insert(make_pair(d[v], v));
    }
    vector<bool> alive(n, true);
    vector<vector<int>> cand;
    while (!st.empty()) {
      auto [dv, v] = *st.begin();
      if (dv == k) {
        break;   
      }
      if (dv == k - 1) {
        vector<int> now;
        now.push_back(v);
        for (int u : g[v]) {
          if (alive[u]) {
            now.push_back(u);
          }
        }
        cand.push_back(now);
      }
      for (int u : g[v]) {
        if (alive[u]) {
          st.erase(make_pair(d[u], u));
          --d[u];
          st.insert(make_pair(d[u], u));
        }
      }
      alive[v] = false;
      st.erase(st.find(make_pair(dv, v)));
    }
    if (!st.empty()) {
      cout << 1 << " " << int(st.size()) << '\n';
      for (auto v : st) {
        cout << v.second + 1 << " ";
      }
      cout << '\n';
      continue;
    }
    vector<vector<int>> at(n);
    vector<bool> ok(int(cand.size()), true);
    for (int i = 0; i < int(cand.size()); i++) {
      for (int v : cand[i]) {
        at[v].push_back(i);
      }
    }
    vector<bool> now(n);
    for (int v = 0; v < n; v++) {
      for (int u : g[v]) {
        now[u] = true;
      }
      for (int i : at[v]) {
        for (int u : cand[i]) {
          if (u != v && !now[u]) {
            ok[i] = false;
          }
        }
      }
      for (int u : g[v]) {
        now[u] = false;
      }
    }
    for (int i = 0; i < int(cand.size()); i++) {
      if (ok[i]) {
        cout << 2 << '\n';
        for (int v : cand[i]) {
          cout << v + 1 << " ";
        }
        cout << '\n';
        break;
      }
    }
    if (count(ok.begin(), ok.end(), true) == 0) {
      cout << -1 << '\n';
    }
  }
  return 0;
}
									  					 		 	     		  	