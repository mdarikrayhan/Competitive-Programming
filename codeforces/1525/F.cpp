// LUOGU_RID: 159712372
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

int n, m, k;

int tot;
int id[55][2];
int isdel[105];
struct Eg {
  int u, v;
} eg[100005];
i64 x[55], y[55];
i64 f[55][55];
int g[55][55];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  
  for(int i = 1; i <= n; i += 1) {
    id[i][0] = ++tot;
    id[i][1] = ++tot;
  }
  for(int i = 1; i <= m; i += 1) {
    cin >> eg[i].u >> eg[i].v;
  }
  for(int i = 1; i <= k; i += 1) {
    cin >> x[i] >> y[i];
  }
  
  auto work = [&]()->void {
    zdl.build(2 * n + 2);
    int ss = 2 * n + 1;
    int tt = ss + 1;
    for(int i = 1; i <= n; i += 1) {
      if(!isdel[id[i][0]]) zdl.link(ss, id[i][0], 1);
      if(!isdel[id[i][1]]) zdl.link(id[i][1], tt, 1);
    }
    for(int i = 1; i <= m; i += 1) {
      int u = eg[i].u, v = eg[i].v;
      if(!isdel[id[u][0]] && !isdel[id[v][1]]) {
        zdl.link(id[u][0], id[v][1], 1);
      }
    }
    zdl.run(ss, tt);
  };
  
  vector<int> way;
  work();
  int mx = zdl.maxflw;
  for(int i = 1; i <= mx; i += 1) {
    for(int j = 1; j <= n; j += 1) {
      if(!isdel[id[j][0]] && zdl.dep[id[j][0]] == (int)1E9) {
        isdel[id[j][0]] = 1;
        way.emplace_back(j);
        break;
      }
      if(!isdel[id[j][1]] && zdl.dep[id[j][1]] != (int)1E9) {
        isdel[id[j][1]] = 1;
        way.emplace_back(-j);
        break;
      }
    }
    work();
  }
  
  memset(f, ~0x3f, sizeof(f));
  f[0][0] = 0;
  g[0][0] = 0;
  for(int i = 1; i <= k; i += 1) {
    for(int j = 0; j <= mx; j += 1) {
      for(int t = 0; t <= j; t += 1) {
        if(i < n - (mx - j)) {
          i64 val = f[i - 1][t] + max(0LL, x[i] - (j - t) * y[i]);
          if(f[i][j] < val) {
            f[i][j] = val;
            g[i][j] = t;
          }
        }
      }
    }
  }
  
  int bst = 0;
  for(int j = 0; j <= mx; j += 1) {
    if(f[k][j] > f[k][bst]){
      bst = j;
    }
  }
  vector<int> ans;
  for(int i = k; i >= 1; i -= 1) {
    ans.emplace_back(0);
    for(int j = bst; j > g[i][bst]; j -= 1) {
      ans.emplace_back(way[j - 1]);
    }
    bst = g[i][bst];
  }
  reverse(ans.begin(), ans.end());
  
  cout << ans.size() << "\n";
  for(int i = 1; i <= ans.size(); i += 1) {
    cout << ans[i - 1] << " \n"[i == ans.size()];
  }
  return 0;
}
