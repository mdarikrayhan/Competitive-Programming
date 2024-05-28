// LUOGU_RID: 160484438
#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

struct MF {
  int n;
  i64 maxflw;
  vector<vector<int>> ag; vector<int> at, acur; vector<i64> acap;
  vector<int> dep;
  void build(int _n) {
    n = _n;
    maxflw = 0;
    ag.resize(n + 1); at.clear(); acur.resize(n + 1); acap.clear();
    for (int i = 1; i <= n; i += 1) ag[i].clear();
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
    for (int i = 1; i <= n; i += 1) dep[i] = (int)1E9;
    dep[ss] = 0;
    deque<int> que;
    que.emplace_back(ss);
    while (que.size()) {
      int u = que.front();
      que.pop_front();
      for (int e : ag[u]) {
        if (acap[e] && dep[u] + 1 < dep[at[e]]) {
          dep[at[e]] = dep[u] + 1;
          que.push_back(at[e]);
        }
      }
    }
    return dep[tt] < (int)1E9;
  }
  i64 dfs(int u, int tt, i64 inflw) {
    if (u == tt) return inflw;
    i64 outflw = 0;
    for (int &i = acur[u]; i < ag[u].size(); i++) {
      int e = ag[u][i];
      if (acap[e] && dep[u] + 1 == dep[at[e]]) {
        i64 curflw = dfs(at[e], tt, min(inflw, acap[e]));
        if (!curflw) dep[at[e]] = -2;
        inflw -= curflw; outflw += curflw;
        acap[e] -= curflw; acap[e ^ 1] += curflw;
      }
      if (!inflw) break;
    }
    if (!outflw) dep[u] = (int)1E9;
    return outflw;
  }
  void run(int ss, int tt) {
    while (bfs(ss, tt)) {
      for (int i = 1; i <= n; i += 1) acur[i] = 0;
      maxflw += dfs(ss, tt, (i64)1E18);
    }
  }
};

struct BMF {
  int n;
  i64 maxflw;
  struct Eg {
    int u, v; i64 dn, up;
  };
  vector<Eg> eg;
  MF bal, opt;
  vector<i64> netin;
  void build(int n_) {
    n = n_;
    maxflw = 0;
    eg.clear();
    bal.build(n + 2);
    opt.build(n);
    netin.assign(n + 1, 0);
  }
  int link(int u, int v, i64 dn, i64 up) {
    eg.emplace_back((Eg){u, v, dn, up});
    netin[u] -= dn;
    netin[v] += dn;
    return bal.link(u, v, up - dn);
  }
  i64 getflw(int e) {
    return eg[e >> 1].dn + opt.acap[e ^ 1];
  }
  int run(int ss, int tt) {
    int cnt = bal.at.size();
    bal.link(tt, ss, (i64)1E18);
    for (int i = 1; i <= n; i += 1) {
      if (netin[i] > 0) {
        bal.link(n + 1, i, netin[i]);
      } else if (netin[i] < 0) {
        bal.link(i, n + 2, -netin[i]);
      }
    }
    bal.run(n + 1, n + 2);
    for (int e : bal.ag[n + 1]) {
      if (bal.acap[e]) {
        return 0;
      }
    }
    for (int e = 0; e < cnt; e += 2) {
      int o = opt.link(bal.at[e ^ 1], bal.at[e], bal.acap[e]);
      opt.acap[o ^ 1] = bal.acap[e ^ 1];
    }
    opt.run(ss, tt);
    for (int e : opt.ag[ss]) {
      maxflw += getflw(e);
    }
    return 1;
  }
};

int n, m;
i64 r, b;
BMF bmf;

struct Dat {
  int x, y;
} dat[100005];
int eid[100005];

void lsh(vector<int> &a) {
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
int disc(const vector<int> &a, int x) {
  return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  cin >> r >> b;
  int rev = 0;
  if (r > b) {
    rev = 1;
    swap(r, b);
  }
  
  vector<int> xs, ys;
  for (int i = 1; i <= n; i += 1) {
    cin >> dat[i].x >> dat[i].y;
    xs.emplace_back(dat[i].x);
    ys.emplace_back(dat[i].y);
  }
  lsh(xs);
  lsh(ys);
  
  int ss = xs.size() + ys.size() + 1, tt = ss + 1;
  bmf.build(tt);
  vector<int> xlim(xs.size(), n), ylim(ys.size(), n);
  vector<int> xcnt(xs.size(), 0), ycnt(ys.size(), 0);
  for (int i = 1; i <= n; i += 1) {
    int xid = disc(xs, dat[i].x);
    int yid = disc(ys, dat[i].y);
    xcnt[xid - 1] += 1;
    ycnt[yid - 1] += 1;
    eid[i] = bmf.link(xid, xs.size() + yid, 0, 1);
  }
  for (int j = 1; j <= m; j += 1) {
    int t, l, d;
    cin >> t >> l >> d;
    if (t == 1) {
      int id = disc(xs, l);
      if (id <= xs.size() && xs[id - 1] == l) {
        xlim[id - 1] = min(xlim[id - 1], d);
      }
    } else {
      int id = disc(ys, l);
      if (id <= ys.size() && ys[id - 1] == l) {
        ylim[id - 1] = min(ylim[id - 1], d);
      }
    }
  }
  for (int i = 1; i <= xs.size(); i += 1) {
    int dn = (xcnt[i - 1] - xlim[i - 1] + 1) / 2;
    int up = (xcnt[i - 1] + xlim[i - 1]) / 2;
    if (dn > up) {
      cout << "-1\n";
      return 0;
    }
    bmf.link(ss, i, max(dn, 0), min(up, n));
  }
  for (int i = 1; i <= ys.size(); i += 1) {
    int dn = (ycnt[i - 1] - ylim[i - 1] + 1) / 2;
    int up = (ycnt[i - 1] + ylim[i - 1]) / 2;
    if (dn > up) {
      cout << "-1\n";
      return 0;
    }
    bmf.link(xs.size() + i, tt, max(dn, 0), min(up, n));
  }
  if (!bmf.run(ss, tt)) {
    cout << "-1\n";
    return 0;
  }
  
  i64 cst = (i64)(n - bmf.maxflw) * b + (i64)bmf.maxflw * r;
  cout << cst << "\n";
  for (int i = 1; i <= n; i += 1) {
    int stat = bmf.getflw(eid[i]);
    assert(stat <= 1);
    cout << "br"[stat ^ rev];
  }
  cout << "\n";
  return 0;
}
