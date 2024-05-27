// Constructive

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve () {
  int n;  cin >> n;
  vector<int> a(n - 1), cnt(n);
  for (auto &ai: a) {
    cin >> ai;  ai--;
    ++cnt[ai];
  }
  vector<int> mx(n);
  set<array<int, 2>> st;
  for (int u = 0; u < n; ++u) {
    mx[u] = u;
    if (!cnt[u]) {
      st.insert({mx[u], u});
    }
  }

  vector<array<int, 2>> edges(n - 1);
  for (int e = n - 2; e >= 0; --e) {
    auto [mxu, u] = *st.begin();  st.erase(st.begin());
    int p = a[e];
    edges[e] = {p, u};
    mx[p] = max(mx[p], mxu);
    cnt[p]--;
    if (!cnt[p]) {
      st.insert({mx[p], p});
    }
  }

  cout << a[0] + 1 << "\n";
  for (auto [u, v]: edges) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
}