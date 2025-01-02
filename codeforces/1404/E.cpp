// LUOGU_RID: 159797920
#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

struct ZDL {
  int n;
  i64 maxflw;
  vector<vector<int>> ag; vector<int> at, acur; vector<i64> acap;
  vector<int> dep;
  void build(int _n) {
    n = _n;
    maxflw = 0;
    ag.resize(n + 1); at.clear(); acur.resize(n + 1); acap.clear();
    for(int i = 1; i <= n; i += 1) ag[i].clear();
    dep.resize(n + 1);
  }
  int link(int u, int v, i64 c) {
    ag[u].emplace_back(at.size()); at.emplace_back(v);
    acap.emplace_back(c);
    ag[v].emplace_back(at.size()); at.emplace_back(u);
    acap.emplace_back(0);
    return at.size() - 2;
  }
  int bfs(int ss, int tt) {
    for(int i = 1; i <= n; i += 1) dep[i] = (int)1E9;
    dep[ss] = 0;
    deque<int> que;
    que.emplace_back(ss);
    while(que.size()) {
      int u = que.front();
      que.pop_front();
      for(int e : ag[u]) {
        if(acap[e] && dep[u] + 1 < dep[at[e]]) {
          dep[at[e]] = dep[u] + 1;
          que.push_back(at[e]);
        }
      }
    }
    return dep[tt] < (int)1E9;
  }
  i64 dfs(int u, int tt, i64 inflw) {
    if(u == tt) return inflw;
    i64 outflw = 0;
    for(int i = acur[u]; i < ag[u].size(); i = acur[u]) {
      acur[u] += 1;
      int e = ag[u][i];
      if(acap[e] && dep[u] + 1 == dep[at[e]]) {
        i64 curflw = dfs(at[e], tt, min(inflw, acap[e]));
        if(!curflw) dep[at[e]] = -2;
        inflw -= curflw; outflw += curflw;
        acap[e] -= curflw; acap[e ^ 1] += curflw;
      }
      if(!inflw) break;
    }
    if(!outflw) dep[u] = (int)1E9;
    return outflw;
  }
  void run(int ss, int tt) {
    while(bfs(ss, tt)) {
      for(int i = 1; i <= n; i += 1) acur[i] = 0;
      maxflw += dfs(ss, tt, (i64)1E18);
    }
  }
} zdl;

int n, m;
string bd[205];
int rid[205][205];
int cid[205][205];
int id[205][205];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for(int i = 1; i <= n; i += 1) {
    cin >> bd[i];
  }
  int tot = 0;
  int ans = 0;
  for(int i = 1; i <= n; i += 1) {
    for(int j = 1; j <= m; j += 1) {
      if(bd[i][j - 1] == '#') {
        ans += 1;
        if(i > 1 && bd[i - 1][j - 1] == '#') {
          rid[i][j] = ++tot;
        }
        if(j > 1 && bd[i][j - 2] == '#') {
          cid[i][j] = ++tot;
        }
      }
    }
  }
  zdl.build(tot + 2);
  int ss = tot + 1, tt = tot + 2;
  for(int i = 1; i <= n; i += 1) {
    for(int j = 1; j <= m; j += 1) {
      if(bd[i][j - 1] == '#') {
        if(rid[i][j]) {
          zdl.link(ss, rid[i][j], 1);
          if(cid[i][j]) zdl.link(rid[i][j], cid[i][j], 1);
          if(cid[i][j + 1]) zdl.link(rid[i][j], cid[i][j + 1], 1);
          if(cid[i - 1][j]) zdl.link(rid[i][j], cid[i - 1][j], 1);
          if(cid[i - 1][j + 1]) zdl.link(rid[i][j], cid[i - 1][j + 1], 1);
        }
        if(cid[i][j]) {
          zdl.link(cid[i][j], tt, 1);
        }
      }
    }
  }
  zdl.run(ss, tt);
  ans -= tot - zdl.maxflw;
  cout << ans << "\n";
  return 0;
}
