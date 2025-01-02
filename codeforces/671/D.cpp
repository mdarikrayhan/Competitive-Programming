// LUOGU_RID: 160142548
#include <bits/stdc++.h>
using namespace std;

using i64 = long long int;

int n, m;
vector<int> adj[300005];
int dep[300005];
vector<pair<int, int>> con[300005];
// i64 f[3005][3005];
// i64 tmp[3005];
int son[300005];
int siz[300005];

void process(int u, int p_u) {
  siz[u] = 1;
  for(int v : adj[u]) {
    if(v != p_u) {
      dep[v] = dep[u] + 1;
      process(v, u);
      if(!son[u] || siz[v] > siz[son[u]]) {
        son[u] = v;
      }
    }
  }
}

int check(int u, int p_u) {
  int mn = n;
  for(auto t : con[u]) {
    mn = min(mn, dep[t.first]);
  }
  for(int v : adj[u]) {
    if(v != p_u) {
      mn = min(mn, check(v, u));
    }
  }
  if(p_u && mn >= dep[u]) {
    cout << "-1\n";
    exit(0);
  }
  return mn;
}

struct DTXDS {
  int n, ch[6000005][2], del[6000005], delcnt;
  struct Node {
    i64 mn, addtag;
  } s[6000005];
  
  void init() {
    n = 0;
    s[0].mn = (i64)1E16; s[0].addtag = 0;
  }
  int newnode() {
    int u = delcnt ? del[delcnt--] : ++n;
    assert(n <= 6000000);
    ch[u][0] = ch[u][1] = 0;
    s[u].mn = (i64)1E16; s[u].addtag = 0;
    return u;
  }
  void set_addtag(int u, i64 addtag) {
    if(s[u].mn == (i64)1E16) {
      return;
    }
    if(addtag == (i64)1E16) {
      s[u].mn = (i64)1E16;
      s[u].addtag = (i64)1E16;
    } else {
      s[u].mn += addtag;
      s[u].addtag += addtag;
    }
  }
  void push_dn(int u) {
    if(s[u].addtag) {
      if(!ch[u][0]) ch[u][0] = newnode();
      if(!ch[u][1]) ch[u][1] = newnode();
      set_addtag(ch[u][0], s[u].addtag);
      set_addtag(ch[u][1], s[u].addtag);
      s[u].addtag = 0;
    }
  }
  void push_up(int u) {
    s[u].mn = min(s[ch[u][0]].mn, s[ch[u][1]].mn);
  }
  
  void ins(int u, int l, int r, int i, i64 k) {
    if(l == r) {
      s[u].mn = min(s[u].mn, k);
      return;
    }
    int mid = (l + r) >> 1;
    push_dn(u);
    if(i <= mid) {
      if(!ch[u][0]) ch[u][0] = newnode();
      ins(ch[u][0], l, mid, i, k);
    } else {
      if(!ch[u][1]) ch[u][1] = newnode();
      ins(ch[u][1], mid + 1, r, i, k);
    }
    push_up(u);
  }
  i64 getmn(int u, int l, int r, int ll, int rr) {
    if(!u || rr < l || r < ll) return s[0].mn;
    if(ll <= l && r <= rr) return s[u].mn;
    int mid = (l + r) >> 1;
    push_dn(u);
    if(rr <= mid) return getmn(ch[u][0], l, mid, ll, rr);
    if(ll > mid) return getmn(ch[u][1], mid + 1, r, ll, rr);
    return min(getmn(ch[u][0], l, mid, ll, rr), getmn(ch[u][1], mid + 1, r, ll, rr));
  }
  int mrg(int u, int v, int l, int r, const i64 &cu, const i64 &cv) {
    if(!u && !v) return 0;
    i64 tmpu = s[u].mn, tmpv = s[v].mn;
    if(!u) {
      if(cv < (i64)1E16) {
        set_addtag(v, cv);
      }
      return v;
    }
    if(!v) {
      if(cu < (i64)1E16) {
        set_addtag(u, cu);
      }
      return u;
    }
    if(l == r) {
      s[u].mn = min((i64)1E16, min(tmpu + cu, tmpv + cv));
      del[++delcnt] = v;
      return u;
    }
    int mid = (l + r) >> 1;
    push_dn(u);
    push_dn(v);
    ch[u][0] = mrg(ch[u][0], ch[v][0], l, mid, cu, cv);
    ch[u][1] = mrg(ch[u][1], ch[v][1], mid + 1, r, cu, cv);
    del[++delcnt] = v;
    push_up(u);
    return u;
  }
  void output(int u, int l, int r) {
    if(l == r) {
      cout << "(" << l << " " << s[u].mn << ") ";
      return;
    }
    int mid = (l + r) >> 1;
    push_dn(u);
    if(ch[u][0]) output(ch[u][0], l, mid);
    if(ch[u][1]) output(ch[u][1], mid + 1, r);
    push_up(u);
  }
} dtxds;

int tr[300005];

void dfs(int u, int p_u) {
  if(son[u]) {
    dfs(son[u], u);
  }
  
  tr[u] = dtxds.newnode();
  // for(int i = 0; i < n; i += 1) {
  //   f[u][i] = (i64)1E16;
  // }
  for(auto t : con[u]) {
    // f[u][dep[t.first]] = min(f[u][dep[t.first]], (i64)t.second);
    dtxds.ins(tr[u], 0, n - 1, dep[t.first], t.second);
  }
  // f[u][dep[u]] = 0;
  dtxds.ins(tr[u], 0, n - 1, dep[u], 0);
  
  // cout << "st " << u << " : ";
  // dtxds.output(tr[u], 0, n - 1);
  // cout << "\n";
  
  if(son[u]) {
    int v = son[u];
    i64 cu = dtxds.getmn(tr[v], 0, n - 1, 0, dep[u]);
    i64 cv = dtxds.getmn(tr[u], 0, n - 1, 0, dep[u]);
    tr[u] = dtxds.mrg(tr[u], tr[v], 0, n - 1, cu, cv);
  }
  
  for(int v : adj[u]) {
    if(v != p_u && v != son[u]) {
      dfs(v, u);
      // i64 cu = (i64)1E16, cv = (i64)1E16;
      // for(int i = 0; i <= dep[u]; i += 1) {
      //   cu = min(cu, f[v][i]);
      //   cv = min(cv, f[u][i]);
      // }
      // for(int i = 0; i < n; i += 1) {
      //   f[u][i] = min((i64)1E16, min(f[u][i] + cu, cv + f[v][i]));
      // }
      i64 cu = dtxds.getmn(tr[v], 0, n - 1, 0, dep[u]);
      i64 cv = dtxds.getmn(tr[u], 0, n - 1, 0, dep[u]);
      tr[u] = dtxds.mrg(tr[u], tr[v], 0, n - 1, cu, cv);
      
      // cout << "mrg " << u << " " << v << " : ";
      // dtxds.output(tr[u], 0, n - 1);
      // cout << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for(int i = 1; i < n; i += 1) {
    int u, v; cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  
  dep[1] = 0;
  process(1, 0);
  
  for(int i = 1; i <= m; i += 1) {
    int u, v, c; cin >> u >> v >> c;
    if(dep[u] < dep[v]) {
      swap(u, v);
    }
    con[u].emplace_back(make_pair(v, c));
  }
  
  check(1, 0);
  
  dtxds.init();
  dfs(1, 0);
  i64 ans = dtxds.getmn(tr[1], 0, n - 1, 0, 0);
  if(ans >= (i64)1E16) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
  }
  // cout << dtxds.n << " " << dtxds.delcnt << "\n";
  return 0;
}