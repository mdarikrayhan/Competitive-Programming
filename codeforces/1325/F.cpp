// LUOGU_RID: 159780881
#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

int getsqrt(int n) {
  int res = 0;
  for(int j = 15; j >= 0; j -= 1) {
    res ^= (1 << j);
    if(res * res > n) {
      res ^= (1 << j);
    }
  }
  return res;
}

int n, m;
int t;
vector<int> adj[100005];
int fa[100005];
int dep[100005];
vector<int> lvl[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  t = getsqrt(n - 1) + 1;
  for(int i = 1; i <= m; i += 1) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  auto dfs = [&](const auto &self, int u, int p) -> void {
    lvl[dep[u] % (t - 1)].emplace_back(u);
    for(int v : adj[u]) {
      if(v == u) continue;
      if(!dep[v]) {
        fa[v] = u;
        dep[v] = dep[u] + 1;
        self(self, v, u);
      }
    }
  };
  dep[1] = 1;
  dfs(dfs, 1, -1);
  for(int i = 1; i <= n; i += 1) {
    for(int v : adj[i]) {
      if(v != fa[i]) {
        if(dep[i] - dep[v] + 1 >= t) {
          cout << 2 << "\n";
          cout << (dep[i] - dep[v] + 1) << "\n";
          for(int x = i; true; x = fa[x]) {
            cout << x << " \n"[x == v];
            if(x == v) break;
          }
          return 0;
        }
      }
    }
  }
  for(int i = 0; i < t; i += 1) {
    if(lvl[i].size() >= t) {
      cout << 1 << "\n";
      for(int j = 1; j <= t; j += 1) {
        cout << lvl[i][j - 1] << " \n"[j == t];
      }
      return 0;
    }
  }
  assert(false);
  return 0;
}
