//#pragma comment(linker, "/STACK:100000000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
// If you only do what you can do, you’ll never be more than you are now
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
#define cin(v)         \
  for (auto& el : v) { \
    cin >> el;         \
  }
#define cout(v)        \
  for (auto& el : v) { \
    cout << el << " "; \
  }                    \
  cout << "\n";

using namespace std;
using ll = long long;
using ldb = long double;
using db = double;
const ll LINF = 1e15 + 1;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1072005019;

struct segtree {
  int n;
  vector<ll> sum, max_, val;

  void build(int v, int l, int r, vector<ll>& a) {
    if (l == r) {
      sum[v] = a[l];
      max_[v] = a[l];
      return;
    }
    int mid = l + (r - l) / 2;
    build(2 * v + 1, l, mid, a);
    build(2 * v + 2, mid + 1, r, a);
    sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
    max_[v] = max(max_[2 * v + 1], max_[2 * v + 2]);
  }

  segtree(vector<ll>& a) { n = a.size();
    sum.resize(4 * n);
    max_.resize(4 * n);
    val.resize(4 * n, -1e18);
    build(0, 0, n - 1, a);
  }

  void push(int v, int vl, int vr) {
    if (val[v] == -1e18) {
      return;
    }
    if (vl != vr) {
      val[2 * v + 1] = val[v];
      val[2 * v + 2] = val[v];
    }
    sum[v] = val[v] * (vr - vl + 1);
    max_[v] = val[v];
    val[v] = -1e18;
    return;
  }

  int bin_search(int v, int vl, int vr, int ind, int t) {
    if (vl == vr) {
      return vl;
    } 
    int mid = vl + (vr - vl) / 2;
    push(2 * v + 1, vl, mid);
    push(2 * v + 2, mid + 1, vr);
    if (mid >= ind && max_[2 * v + 1] >= t) {
      return bin_search(2 * v + 1, vl, mid, ind, t);
    } else if (max_[2 * v + 2] >= t) {
      return bin_search(2 * v + 2, mid + 1, vr, ind, t);
    } else {
      return vr + 1;
    }
  }

  ll query_sum(int v, int vl, int vr, int ql, int qr) {
    push(v, vl, vr);
    if (vl > qr || vr < ql) {
      return 0;
    }
    if (ql <= vl && vr <= qr) {
      return sum[v];
    }
    int mid = vl + (vr - vl) / 2;
    return query_sum(2 * v + 1, vl, mid, ql, qr) +
           query_sum(2 * v + 2, mid + 1, vr, ql, qr);
  }

  void update(int v, int vl, int vr, int ql, int qr, ll zn) {
    push(v, vl, vr);
    if (vl > qr || vr < ql) {
      return;
    }
    if (ql <= vl && vr <= qr) {
      val[v] = zn;
      push(v, vl, vr);
      return;
    }
    int mid = vl + (vr - vl) / 2;
    update(2 * v + 1, vl, mid, ql, qr, zn);
    update(2 * v + 2, mid + 1, vr, ql, qr, zn);
    sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
    max_[v] = max(max_[2 * v + 1], max_[2 * v + 2]);
  }
};

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  cin(a);
  vector<ll> k(n - 1);
  cin(k);
  vector<ll> b(n), pref_(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    b[i] = a[i] - sum;
    if (i == n - 1) {
      break;
    }
    sum += k[i];
    pref_[i + 1] = sum;
  }
  vector<ll> pref_2(n + 1);
  for (int i = 1; i <= n; i++) {
    pref_2[i] = pref_2[i - 1] + pref_[i - 1];
  }
  segtree segtree(b);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    char c;
    cin >> c;
    if (c == 's') {
      int l, r;
      cin >> l >> r;
      cout << segtree.query_sum(0, 0, n - 1, l - 1, r - 1) + pref_2[r] -
                  pref_2[l - 1] << endl;
    } else {
      ll ind, add;
      cin >> ind >> add;
      ll zn = segtree.query_sum(0, 0, n - 1, ind - 1, ind - 1);
      if (i == q - 3) {
        int gfk = 0;
      }
      int ind2 = segtree.bin_search(0, 0, n - 1, ind - 1, zn + add);
      segtree.update(0, 0, n - 1, ind - 1, ind2 - 1, zn + add);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}