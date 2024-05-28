// LUOGU_RID: 160142304
#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

mt19937 MT(time(nullptr));

int n;

vector<int> ag[250005], at;
vector<i64> alen;
void alink(int u, int v, i64 d) {
  ag[u].emplace_back(at.size());
  at.emplace_back(v);
  alen.emplace_back(d);
}

namespace trp {
  int n, ch[1000005][2], del[1000005], delcnt;
  struct Node {
    int pri, siz; i64 val, sum;
  } s[1000005];
  void init() {
    n = 0;
    ch[0][0] = ch[0][1] = 0;
    s[0].pri = (int)MT(); s[0].siz = 0; s[0].val = 0; s[0].sum = 0;
  }
  int newnode(const i64 &val = 0) {
    int u = delcnt ? del[delcnt--] : ++n;
    ch[u][0] = ch[u][1] = 0;
    s[u].pri = (int)MT(); s[u].siz = 1; s[u].val = val; s[u].sum = val;
    return u;
  }
  void pushdn(int u) {
  }
  void pushup(int u) {
    if(!u) return;
    s[u].siz = 1 + s[ch[u][0]].siz + s[ch[u][1]].siz;
    s[u].sum = s[u].val + s[ch[u][0]].sum + s[ch[u][1]].sum;
  }
  void spl(int u, int i, int &x, int &y) {
    if(!u) return x = y = 0, void();
    int curi = 1 + s[ch[u][0]].siz;
    if(curi <= i) x = u, pushdn(u), spl(ch[u][1], i - curi, ch[u][1], y), pushup(u);
    else y = u, pushdn(u), spl(ch[u][0], i, x, ch[u][0]), pushup(u);
  }
  void splval(int u, i64 k, int &x, int &y) {
    if(!u) return x = y = 0, void();
    if(s[u].val <= k) x = u, pushdn(u), splval(ch[u][1], k, ch[u][1], y), pushup(u);
    else y = u, pushdn(u), splval(ch[u][0], k, x, ch[u][0]), pushup(u);
  }
  int mrg(int u, int v) {
    if(!u || !v) return u + v;
    if(s[u].pri < s[v].pri) return pushdn(u), ch[u][1] = mrg(ch[u][1], v), pushup(u), u;
    else return pushdn(v), ch[v][0] = mrg(u, ch[v][0]), pushup(v), v;
  }
  void ins(int &u, int i, i64 k) {
    int x, y;
    spl(u, i - 1, x, y);
    u = mrg(mrg(x, newnode(k)), y);
  }
  void insval(int &u, i64 k) {
    int x, y;
    splval(u, k, x, y);
    u = mrg(mrg(x, newnode(k)), y);
  }
  void delval(int &u, i64 k) {
    int x, y;
    splval(u, k - 1, x, y);
    splval(y, k, u, y);
    if(u) del[++delcnt] = u;
    u = mrg(ch[u][0], ch[u][1]);
    u = mrg(mrg(x, u), y);
  }
  i64 getbst(int &u, int k) {
    int x, y;
    splval(u, 0, x, u);
    spl(u, s[u].siz - k, u, y);
    i64 res = s[y].sum;
    u = mrg(mrg(x, u), y);
    return res;
  }
  void output(int &u) {
    if(ch[u][0]) output(ch[u][0]);
    if(u) cout << s[u].sum << " ";
    if(ch[u][1]) output(ch[u][1]);
  }
};

int mxd[250005];
i64 up[250005];
i64 sum[250005];
i64 f[250005][2];
int tr[250005];

void process(int u, int p) {
  mxd[u] = ag[u].size();
  for(int e : ag[u]) {
    if(at[e] != p) {
      up[at[e]] = alen[e];
      process(at[e], u);
      mxd[u] = max(mxd[u], mxd[at[e]]);
    }
  }
}

int lim;
void dfs(int u, int p) {
  for(int e : ag[u]) {
    if(at[e] != p) {
      if(mxd[at[e]] >= lim) {
        trp::delval(tr[u], f[at[e]][1] - f[at[e]][0]);
        sum[u] -= f[at[e]][0];
        dfs(at[e], u);
        sum[u] += f[at[e]][0];
        trp::insval(tr[u], f[at[e]][1] - f[at[e]][0]);
      } else {
        break;
      }
    }
  }
  f[u][0] = sum[u] + trp::getbst(tr[u], lim);
  f[u][1] = sum[u] + up[u] + trp::getbst(tr[u], lim - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  trp::init();
  cin >> n;
  i64 allsum = 0;
  for(int i = 1; i <= n - 1; i += 1) {
    int u, v;
    i64 c;
    cin >> u >> v >> c;
    allsum += c;
    alink(u, v, c);
    alink(v, u, c);
  }
  int rt = (int)(MT() % n) + 1;
  process(rt, 0);
  for(int i = 1; i <= n; i += 1) {
    sort(ag[i].begin(), ag[i].end(), [&](const int &A, const int &B)->bool {
      return mxd[at[A]] > mxd[at[B]];
    });
  }
  for(int k = 0; k <= n - 1; k += 1) {
    lim = k;
    dfs(rt, 0);
    cout << (allsum - max(f[rt][0], f[rt][1])) << " \n"[k == n - 1];
  }
  return 0;
}