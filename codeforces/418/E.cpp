// LUOGU_RID: 159729547
#include <bits/stdc++.h>
using namespace std;
int n;
#define N 100010
int a[N];
int q;
const int kc = 317;
int op[N][4];
struct decr {
  int a[N * 2];
  int cnt;
  void add(int v) {a[++cnt] = v;}
  void ini() {sort(a + 1, a + cnt + 1); cnt = unique(a + 1, a + cnt + 1) - a - 1;}
  int operator() (int x) const {return lower_bound(a + 1, a + cnt + 1, x) - a;}
  int operator[] (int x) const {return a[x];}
}lis;
int buck[N], cs[N * 2];
int res[N];
void add(int v) {
  ++cs[v];
  ++buck[cs[v]];
}
void del(int v) {
  --buck[cs[v]];
  --cs[v];
}
int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    lis.add(a[i]);
  }
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> op[i][0] >> op[i][2] >> op[i][1];
    if (op[i][0] == 1) {
      op[i][3] = a[op[i][1]];
      a[op[i][1]] = op[i][2];
      lis.add(op[i][2]);
    } else {
      if (op[i][2] > 1) {
        op[i][2] = (op[i][2] & 1) + 2;
      }
    }
  }
  lis.ini();
  for (int i = 1; i <= q; ++i) {
    if (op[i][0] == 1) {
      op[i][2] = lis(op[i][2]);
      op[i][3] = lis(op[i][3]);
    }
  }
  for (int i = 1; i <= n; ++i) a[i] = lis(a[i]);
  vector<int> p(q);
  iota(p.begin(), p.end(), 1);
  sort(p.begin(), p.end(), [&](int x, int y) {
    auto a = make_pair(x / kc, op[x][1]);
    auto b = make_pair(y / kc, op[y][1]);
    if (a.first != b.first) return a < b;
    if (a.first & 1) return a < b;
    return a > b;
  });
  int ps = 0, tim = q;
  for (auto i : p) {
    if (op[i][0] == 1) continue;
    while (tim > i) {
      if (op[tim][0] == 2) {--tim; continue;}
      int x = op[tim][1], fr = op[tim][3], to = op[tim][2];
      if (x <= ps) del(to), add(fr);
      a[x] = fr;
      --tim;
    }
    while (tim < i) {
      ++tim;
      if (op[tim][0] == 2) {continue;}
      int x = op[tim][1], fr = op[tim][3], to = op[tim][2];
      if (x <= ps) del(fr), add(to);
      a[x] = to;
    }
    while (ps < op[i][1]) {
      ++ps;
      add(a[ps]);
    }
    while (ps > op[i][1]) {
      del(a[ps]);
      --ps;
    }
    if (op[i][2] == 1) {
      res[i] = lis[a[op[i][1]]];
    } else if (op[i][2] == 2) {
      res[i] = cs[a[op[i][1]]];
    } else {
      res[i] = buck[cs[a[op[i][1]]]];
    }
  }
  for (int i = 1; i <= q; ++i) {
    if (op[i][0] == 2) cout << res[i] << '\n';
  }
  return 0;
}