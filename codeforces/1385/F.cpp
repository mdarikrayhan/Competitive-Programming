#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n, k;  cin >> n >> k;
  vector<array<int, 2>> edges(n - 1);
  vector<int> deg(n);
  for (auto &[u, v]: edges) {
    cin >> u >> v;  u--, v--;
    deg[u]++, deg[v]++;
  }
  set<int> leaf[n], nleaf[n];
  for (auto [u, v]: edges) {
    if (deg[v] == 1)  leaf[u].insert(v);
    else  nleaf[u].insert(v);
    if (deg[u] == 1)  leaf[v].insert(u);
    else  nleaf[v].insert(u);
  }

  set<array<int, 2>, greater<>> st;
  for (int u = 0; u < n; ++u) {
    st.insert({leaf[u].size(), u});
  }

  int ans = 0;
  while (!st.empty()) {
    auto [L, u] = *st.begin();  st.erase(st.begin());
    if (L < k)  break;
    int q = L / k;
    ans += q;
    int out = q * k;
    while (out--) {
      int v = *leaf[u].begin();  leaf[u].erase(leaf[u].begin());
      assert(st.find({leaf[v].size(), v}) != st.end());
      st.erase({leaf[v].size(), v});
    }
    if (leaf[u].empty() and nleaf[u].size() == 1) {
      int v = *nleaf[u].begin();  nleaf[v].erase(u);
      st.erase(st.find({leaf[v].size(), v}));
      leaf[v].insert(u);
      st.insert({leaf[v].size(), v});

      if (leaf[v].size() + nleaf[v].size() == 1) {
        nleaf[u].erase(v);
        leaf[u].insert(v);
      }
    }
    st.insert({leaf[u].size(), u});
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}