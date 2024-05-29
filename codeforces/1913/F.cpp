/**
 *    author:  tourist
 *    created: 18.12.2023 09:53:41       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
template <typename T>
vector<int> suffix_array(int n, const T &s, int char_bound) {
  vector<int> a(n);
  if (n == 0) {
    return a;
  }
  if (char_bound != -1) {
    vector<int> aux(char_bound, 0);
    for (int i = 0; i < n; i++) {
      aux[s[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < char_bound; i++) {
      int add = aux[i];
      aux[i] = sum;
      sum += add;
    }
    for (int i = 0; i < n; i++) {
      a[aux[s[i]]++] = i;
    }
  } else {
    iota(a.begin(), a.end(), 0);
    sort(a.begin(), a.end(), [&s](int i, int j) { return s[i] < s[j]; });
  }
  vector<int> sorted_by_second(n);
  vector<int> ptr_group(n);
  vector<int> new_group(n);
  vector<int> group(n);
  group[a[0]] = 0;
  for (int i = 1; i < n; i++) {
    group[a[i]] = group[a[i - 1]] + (!(s[a[i]] == s[a[i - 1]]));
  }
  int cnt = group[a[n - 1]] + 1;
  int step = 1;
  while (cnt < n) {
    int at = 0;
    for (int i = n - step; i < n; i++) {
      sorted_by_second[at++] = i;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] - step >= 0) {
        sorted_by_second[at++] = a[i] - step;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      ptr_group[group[a[i]]] = i;
    }
    for (int i = 0; i < n; i++) {
      int x = sorted_by_second[i];
      a[ptr_group[group[x]]++] = x;
    }
    new_group[a[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (group[a[i]] != group[a[i - 1]]) {
        new_group[a[i]] = new_group[a[i - 1]] + 1;
      } else {
        int pre = (a[i - 1] + step >= n ? -1 : group[a[i - 1] + step]);
        int cur = (a[i] + step >= n ? -1 : group[a[i] + step]);
        new_group[a[i]] = new_group[a[i - 1]] + (pre != cur);
      }
    }
    swap(group, new_group);
    cnt = group[a[n - 1]] + 1;
    step <<= 1;
  }
  return a;
}
 
template <typename T>
vector<int> suffix_array(const T &s, int char_bound) {
  return suffix_array((int) s.size(), s, char_bound);
}
 
template <typename T>
vector<int> build_lcp(int n, const T &s, const vector<int> &sa) {
  assert((int) sa.size() == n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[sa[i]] = i;
  }
  vector<int> lcp(max(n - 1, 0));
  int k = 0;
  for (int i = 0; i < n; i++) {
    k = max(k - 1, 0);
    if (pos[i] == n - 1) {
      k = 0;
    } else {
      int j = sa[pos[i] + 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
        k++;
      }
      lcp[pos[i]] = k;
    }
  }
  return lcp;
}
 
template <typename T>
vector<int> build_lcp(const T &s, const vector<int> &sa) {
  return build_lcp((int) s.size(), s, sa);
}
 
template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;
 
  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
 
  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string u = s + "#" + string(s.rbegin(), s.rend());
  auto sa = suffix_array(u, 256);
  auto lcp = build_lcp(u, sa);
  SparseTable<int> st(lcp, [&](int i, int j) { return min(i, j); });
  vector<int> pos(sa.size());
  for (int i = 0; i < (int) sa.size(); i++) {
    pos[sa[i]] = i;
  }
  auto LCP = [&](int i, int j) {
    i = n + 1 + (n - 1 - i);
    i = pos[i];
    j = pos[j];
    if (i > j) {
      swap(i, j);
    }
    return st.get(i, j - 1);
  };
  const int ALPHA = 26;
  vector<vector<long long>> delta(n, vector<long long>(ALPHA));
  vector<long long> broke_k(n + 1);
  vector<long long> broke_b(n + 1);
  auto Add = [&](int l, int r, int k, int b) {
    broke_k[l] += k;
    broke_k[r + 1] -= k;
    broke_b[l] += b;
    broke_b[r + 1] -= b;
  };
  long long init = 0;
  for (int t = 0; t <= 2 * (n - 1); t++) {
    int i = t >> 1;
    int j = (t + 1) >> 1;
    int v = LCP(i, j);
    init += v;
    if (i - v >= 0 && j + v < n) {
      assert(s[i - v] != s[j + v]);
      int add = 1;
      if (i - v - 1 >= 0 && j + v + 1 < n) {
        add += LCP(i - v - 1, j + v + 1);
      }
      delta[i - v][(int) (s[j + v] - 'a')] += add;
      delta[j + v][(int) (s[i - v] - 'a')] += add;
    }
    if (i == j) {
      i -= 1;
      j += 1;
      v -= 1;
    }
    if (v > 0) {
      Add(i - v + 1, i, 1, -(i - v));
      Add(j, j + v - 1, -1, j + v);
    }
  }
  vector<long long> broke(n);
  for (int i = 0; i < n; i++) {
    broke[i] = broke_k[i] * i + broke_b[i];
    broke_k[i + 1] += broke_k[i];
    broke_b[i + 1] += broke_b[i];
  }
  auto Better = [&](pair<int, int> a, pair<int, int> b) {
    assert(a.first <= b.first);
    if (a.first == b.first) {
      return a.second < b.second;
    }
    return a.second < (int) (s[a.first] - 'a');
  };
  long long ans = init;
  pair<int, int> p = {n, -1};
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      if (j == (int) (s[i] - 'a')) {
        continue;
      }
      long long cur = init + delta[i][j] - broke[i];
      pair<int, int> q = {i, j};
      if (cur > ans || (cur == ans && Better(q, p))) {
        ans = cur;
        p = q;
      }
    }
  }
  cout << ans << '\n';
  if (p.first < n) {
    s[p.first] = (char) ('a' + p.second);
  }
  cout << s << '\n';
  return 0;
}