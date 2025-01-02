#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n;

  vector<vector<int>> adj(n + 1);
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int t = 1;
  vector<int> in(n + 1), out(n + 1);
  function<void(int)> dfs = [&](int u) {
    in[u] = t++;
    for (int &v: adj[u])
      if (!in[v])
        dfs(v);
    out[u] = t - 1;
  };
  dfs(1);

  cin >> k;
  vector<pair<int, int>> paths(k);
  for (auto &[u, v]: paths) {
    cin >> u >> v;
  }

  auto is_inside_subtree = [&](int root, int u) {
    return in[root] <= in[u] and out[u] <= out[root];
  };

  auto generate_mask = [&](int y) -> int {
    int msk = 0;
    for (int i = 0; i < paths.size(); ++i) {
      auto [u, v] = paths[i];
      if (is_inside_subtree(y, u) and is_inside_subtree(y, v))continue;
      if (is_inside_subtree(y, u) or is_inside_subtree(y, v)) {
        msk |= 1 << i;
      }
    }
    return msk;
  };

  set<int> st;
  function<void(int)> dfs1 = [&](int u) {
    for (int v: adj[u]) {
      if (in[u] > in[v])continue;
      int msk = generate_mask(v);
      if (msk) {
        st.emplace(msk);
      }
      dfs1(v);
    }
  };
  dfs1(1);


  vector<int> masks(st.begin(), st.end());
  n = masks.size();
  const int N = (1 << k);
  vector<char> dp(N, n + 1);
  dp[0] = 0;
  for (int msk = 0; msk < N; ++msk) {
    for (int x: masks) {
      dp[x | msk] = min(
          dp[x | msk] + 0,
          dp[msk] + 1
      );
    }
  }

  cout << (int) dp[N - 1] << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}