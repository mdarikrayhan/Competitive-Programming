// Hydro submission #6654481dbf5c09e48a97ab8c@1716799517733
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using u128 = unsigned __int128;
template <typename T>
void chkmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  if (y < x) x = y;
}
struct rectangle {
  int x1, y1, x2, y2;
};
struct operation {
  int x, typ, id;
};
bool operator<(const operation &u, const operation &v) { return u.x < v.x; }
constexpr int MAXN = 1e5 + 10;
int n, mp[MAXN * 2], sz, cnt;
rectangle a[MAXN];
operation op[MAXN * 2];
bool del[MAXN], have[MAXN];
namespace sgt {
int ls(int p) { return p << 1; }
int rs(int p) { return p << 1 | 1; }
int mini[MAXN * 8], can[MAXN * 8];
priority_queue<int> pq[MAXN * 8];
void push_up(int p, int l, int r) {
  while (!pq[p].empty() && del[pq[p].top()]) pq[p].pop();
  if (l == r) {
    if (pq[p].empty()) {
      mini[p] = can[p] = 0;
    } else {
      mini[p] = pq[p].top();
      can[p] = (have[pq[p].top()] ? 0 : pq[p].top());
    }
  } else {
    mini[p] = min(mini[ls(p)], mini[rs(p)]);
    can[p] = max(can[ls(p)], can[rs(p)]);
    if (!pq[p].empty()) {
      chkmax(mini[p], pq[p].top());
      if (pq[p].top() > can[p]) can[p] = 0;
      if (pq[p].top() >= mini[p] && !have[pq[p].top()]) chkmax(can[p], pq[p].top());
    }
  }
}
void insert(int p, int l, int r, int ql, int qr, int id) {
  if (ql <= l && r <= qr) {
    pq[p].emplace(id);
    push_up(p, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) insert(ls(p), l, mid, ql, qr, id);
  if (qr > mid) insert(rs(p), mid + 1, r, ql, qr, id);
  push_up(p, l, r);
}
void update(int p, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) {
    push_up(p, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid) update(ls(p), l, mid, ql, qr);
  if (qr > mid) update(rs(p), mid + 1, r, ql, qr);
  push_up(p, l, r);
}
}  // namespace sgt
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    mp[++sz] = a[i].y1;
    mp[++sz] = a[i].y2;
  }
  sort(mp + 1, mp + sz + 1);
  sz = unique(mp + 1, mp + sz + 1) - mp - 1;
  for (int i = 1; i <= n; ++i) {
    a[i].y1 = lower_bound(mp + 1, mp + sz + 1, a[i].y1) - mp;
    a[i].y2 = lower_bound(mp + 1, mp + sz + 1, a[i].y2) - mp;
    op[++cnt] = {a[i].x1, 1, i};
    op[++cnt] = {a[i].x2, 0, i};
  }
  sort(op + 1, op + cnt + 1);
  for (int i = 1; i <= cnt; ++i) {
    if (op[i].typ) {
      sgt::insert(1, 1, sz, a[op[i].id].y1, a[op[i].id].y2 - 1, op[i].id);
    } else {
      del[op[i].id] = true;
      sgt::update(1, 1, sz, a[op[i].id].y1, a[op[i].id].y2 - 1);
    }
    if (i == cnt || op[i].x != op[i + 1].x) {
      while (sgt::can[1]) {
        have[sgt::can[1]] = true;
        sgt::update(1, 1, sz, a[sgt::can[1]].y1, a[sgt::can[1]].y2 - 1);
      }
    }
  }
  cout << accumulate(have + 1, have + n + 1, 0) + 1 << "\n";
  return 0;
}
/*
g++ B.cpp -o B -O2 -std=c++14 -Wall -Wextra -Wshadow -g -fsanitize=address,undefined
*/