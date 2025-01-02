#include <bits/stdc++.h>
using namespace std;

using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

int n, m, q;
int a[300005], b[300005];

i64 f(i64 x) {
  return x * (x + 1) / 2;
}
i64 g(i64 x) {
  return (x - 1) * x * (2 * x - 1) / 6 - x * x * (x - 1) / 2;
}

namespace xds2 {
  int n, ch[1200005][2];
  struct Node {
    int cnt;
    int sum; i64 fsum, gsum;
  } s[1200005];
  void pushup(int u) {
    s[u].cnt = s[ch[u][0]].cnt + s[ch[u][1]].cnt;
    s[u].sum = s[ch[u][0]].sum + s[ch[u][1]].sum;
    s[u].fsum = s[ch[u][0]].fsum + s[ch[u][1]].fsum;
    s[u].gsum = s[ch[u][0]].gsum + s[ch[u][1]].gsum;
  }
  int build(int l, int r) {
    int u = ++n;
    if (l == r) {
      return u;
    }
    int mid = (l + r) >> 1;
    ch[u][0] = build(l, mid);
    ch[u][1] = build(mid + 1, r);
    return u;
  }
  void add(int u, int l, int r, int len, int flg) {
    if (l == r) {
      s[u].cnt += flg;
      s[u].sum += flg * len;
      s[u].fsum += flg * f(len);
      s[u].gsum += flg * g(len);
      return;
    }
    int mid = (l + r) >> 1;
    if (len <= mid) add(ch[u][0], l, mid, len, flg);
    else add(ch[u][1], mid + 1, r, len, flg);
    pushup(u);
  }
  i64 cal(int u, int l, int r, int len) {
    if (l == r) {
      i64 res = s[u].fsum * len + s[u].gsum;
      return res;
    }
    int mid = (l + r) >> 1;
    if (len <= mid) {
      i64 res = s[ch[u][1]].sum * f(len) + s[ch[u][1]].cnt * g(len);
      return res + cal(ch[u][0], l, mid, len);
    } else {
      i64 res = s[ch[u][0]].fsum * len + s[ch[u][0]].gsum;
      return res + cal(ch[u][1], mid + 1, r, len);
    }
  }
}

struct St {
  int totlen;
  int tra, trb;
  i64 ans;
  void adda(int len) {
    xds2::add(tra, 1, totlen, len, 1);
    ans += xds2::cal(trb, 1, totlen, len);
  }
  void dela(int len) {
    xds2::add(tra, 1, totlen, len, -1);
    ans -= xds2::cal(trb, 1, totlen, len);
  }
  void addb(int len) {
    xds2::add(trb, 1, totlen, len, 1);
    ans += xds2::cal(tra, 1, totlen, len);
  }
  void delb(int len) {
    xds2::add(trb, 1, totlen, len, -1);
    ans -= xds2::cal(tra, 1, totlen, len);
  }
} thing;

namespace xds {
  int n, ch[1200005][2];
  struct {
    i64 val; i64 addtag;
  } s[1200005];
  void pushdn(int u) {
    if (s[u].addtag) {
      s[ch[u][0]].val += s[u].addtag;
      s[ch[u][0]].addtag += s[u].addtag;
      s[ch[u][1]].val += s[u].addtag;
      s[ch[u][1]].addtag += s[u].addtag;
      s[u].addtag = 0;
    }
  }
  int build(int l, int r, int *val) {
    int u = ++n;
    s[u].addtag = 0;
    if (l == r) {
      s[u].val = val[l];
      return u;
    }
    int mid = (l + r) >> 1;
    ch[u][0] = build(l, mid, val);
    ch[u][1] = build(mid + 1, r, val);
    return u;
  }
  i64 getval(int u, int l, int r, int p) {
    if (l == r) {
      return s[u].val;
    }
    int mid = (l + r) >> 1;
    pushdn(u);
    if (p <= mid) return getval(ch[u][0], l, mid, p);
    return getval(ch[u][1], mid + 1, r, p);
  }
  void add(int u, int l, int r, int ll, int rr, i64 x) {
    if (ll <= l && r <= rr) {
      s[u].val += x;
      s[u].addtag += x;
      return;
    }
    int mid = (l + r) >> 1;
    pushdn(u);
    if (ll <= mid) add(ch[u][0], l, mid, ll, rr, x);
    if (rr > mid) add(ch[u][1], mid + 1, r, ll, rr, x);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i += 1) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i += 1) {
    cin >> b[i];
  }
  
  thing.totlen = max(n, m);
  thing.tra = xds2::build(1, thing.totlen);
  thing.trb = xds2::build(1, thing.totlen);
  set<pair<int, int>> sta, stb;
  int combo = 0;
  for (int i = 1; i <= n; i += 1) {
    combo += 1;
    if (i == n || a[i] == a[i + 1]) {
      thing.adda(combo);
      sta.emplace(i - combo + 1, i);
      combo = 0;
    }
  }
  combo = 0;
  for (int i = 1; i <= m; i += 1) {
    combo += 1;
    if (i == m || b[i] == b[i + 1]) {
      thing.addb(combo);
      stb.emplace(i - combo + 1, i);
      combo = 0;
    }
  }
  cout << thing.ans << "\n";
  
  int tra = xds::build(1, n, a);
  int trb = xds::build(1, m, b);
  for (int t = 1; t <= q; t += 1) {
    int op, l, r; i64 x;
    cin >> op >> l >> r >> x;
    if (x) {
      if (op == 1) {
        int lto = -1, rto = -1;
        if (l > 1) {
          i64 lval = xds::getval(tra, 1, n, l);
          i64 llval = xds::getval(tra, 1, n, l - 1);
          if (lval == llval) {
            lto = 0;
          } else if (lval + x == llval) {
            lto = 1;
          }
        }
        if (r < n) {
          i64 rval = xds::getval(tra, 1, n, r);
          i64 rrval = xds::getval(tra, 1, n, r + 1);
          if (rval == rrval) {
            rto = 0;
          } else if (rval + x == rrval) {
            rto = 1;
          }
        }
        xds::add(tra, 1, n, l, r, x);
        if (lto == 0) {
          auto it = sta.lower_bound({l, 0});
          int u = prev(it)->first;
          int v = it->second;
          thing.dela((l - 1) - u + 1);
          thing.dela(v - l + 1);
          thing.adda(v - u + 1);
          sta.erase({u, l - 1});
          sta.erase({l, v});
          sta.emplace(u, v);
        }
        if (lto == 1) {
          auto it = --sta.upper_bound({l, 0x3f3f3f3f});
          int u = it->first;
          int v = it->second;
          thing.dela(v - u + 1);
          thing.adda((l - 1) - u + 1);
          thing.adda(v - l + 1);
          sta.erase({u, v});
          sta.emplace(u, l - 1);
          sta.emplace(l, v);
        }
        if (rto == 0) {
          auto it = --sta.upper_bound({r, 0x3f3f3f3f});
          int u = it->first;
          int v = next(it)->second;
          thing.dela(r - u + 1);
          thing.dela(v - (r + 1) + 1);
          thing.adda(v - u + 1);
          sta.erase({u, r});
          sta.erase({r + 1, v});
          sta.emplace(u, v);
        }
        if (rto == 1) {
          auto it = --sta.upper_bound({r, 0x3f3f3f3f});
          int u = it->first;
          int v = it->second;
          thing.dela(v - u + 1);
          thing.adda(r - u + 1);
          thing.adda(v - (r + 1) + 1);
          sta.erase({u, v});
          sta.emplace(u, r);
          sta.emplace(r + 1, v);
        }
      } else {
        int lto = -1, rto = -1;
        if (l > 1) {
          i64 lvbl = xds::getval(trb, 1, m, l);
          i64 llvbl = xds::getval(trb, 1, m, l - 1);
          if (lvbl == llvbl) {
            lto = 0;
          } else if (lvbl + x == llvbl) {
            lto = 1;
          }
        }
        if (r < m) {
          i64 rvbl = xds::getval(trb, 1, m, r);
          i64 rrvbl = xds::getval(trb, 1, m, r + 1);
          if (rvbl == rrvbl) {
            rto = 0;
          } else if (rvbl + x == rrvbl) {
            rto = 1;
          }
        }
        xds::add(trb, 1, m, l, r, x);
        if (lto == 0) {
          auto it = stb.lower_bound({l, 0});
          int u = prev(it)->first;
          int v = it->second;
          thing.delb((l - 1) - u + 1);
          thing.delb(v - l + 1);
          thing.addb(v - u + 1);
          stb.erase({u, l - 1});
          stb.erase({l, v});
          stb.emplace(u, v);
        }
        if (lto == 1) {
          auto it = --stb.upper_bound({l, 0x3f3f3f3f});
          int u = it->first;
          int v = it->second;
          thing.delb(v - u + 1);
          thing.addb((l - 1) - u + 1);
          thing.addb(v - l + 1);
          stb.erase({u, v});
          stb.emplace(u, l - 1);
          stb.emplace(l, v);
        }
        if (rto == 0) {
          auto it = --stb.upper_bound({r, 0x3f3f3f3f});
          int u = it->first;
          int v = next(it)->second;
          thing.delb(r - u + 1);
          thing.delb(v - (r + 1) + 1);
          thing.addb(v - u + 1);
          stb.erase({u, r});
          stb.erase({r + 1, v});
          stb.emplace(u, v);
        }
        if (rto == 1) {
          auto it = --stb.upper_bound({r, 0x3f3f3f3f});
          int u = it->first;
          int v = it->second;
          thing.delb(v - u + 1);
          thing.addb(r - u + 1);
          thing.addb(v - (r + 1) + 1);
          stb.erase({u, v});
          stb.emplace(u, r);
          stb.emplace(r + 1, v);
        }
      }
    }
    cout << thing.ans << "\n";
  }
  return 0;
}
