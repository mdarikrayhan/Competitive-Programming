/**
 *    author:  tourist
 *    created: 25.12.2020 14:34:39       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
 public:
  vector<T> fenw;
  int n;

  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

struct node {
  int a = (int) -1e9;

  inline void operator += (node &other) {
    a = max(a, other.a);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> dp(n);
    fenwick<node> fenw(n);
    set<pair<int, int>> s;
    fenw.modify(0, {0});
    s.emplace(0, 0);
    for (int i = 0; i < n; i++) {
      dp[i] = fenw.get(a[i]).a + 1;
      fenw.modify(a[i], {dp[i]});
      while (!s.empty() && a[i] >= s.begin()->first) {
        fenw.modify(s.begin()->first, {s.begin()->second + 1});
        s.erase(s.begin());
      }
      s.emplace(a[i], dp[i]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
  }
  return 0;
}
