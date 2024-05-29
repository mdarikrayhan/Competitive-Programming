/*
 * author:  ADMathNoob
 * created: 05/05/24 21:30:48
 * problem: https://codeforces.com/contest/1572/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...) 42
#endif

namespace vector_compression {

template <typename T>
void MakeUnique(vector<T>& v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

template <typename T>
int GetIndex(const vector<T>& v, const T& x) {
  const auto it = lower_bound(v.begin(), v.end(), x);
  if (it == v.end() || *it != x) return -1;
  return static_cast<int>(it - v.begin());
}

void Compress(vector<int>& a, const vector<int>& v) {
  const int n = static_cast<int>(a.size());
  for (int i = 0; i < n; i++) {
    a[i] = GetIndex(v, a[i]);
  }
}

void Compress(vector<int>& a) {
  vector<int> v = a;
  MakeUnique(v);
  Compress(a, v);
}

template <typename T>
vector<int> Compressed(const vector<T>& a, const vector<T>& v) {
  const int n = static_cast<int>(a.size());
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    res[i] = GetIndex(v, a[i]);
  }
  return res;
}

template <typename T>
vector<int> Compressed(const vector<T>& a) {
  vector<T> v = a;
  MakeUnique(v);
  return Compressed(a, v);
}

}  // namespace vector_compression

using namespace vector_compression;

template <typename T, typename C>
class MCMF {
 public:
  static constexpr T EPS = (T) 1e-9; // so that flow decomp works
  static constexpr C INF_C = numeric_limits<C>::max() / 2;

  struct Edge {
    int from;
    int to;
    T c;
    T f;
    C cost;
  };

  int n;
  vector<vector<int>> g;
  vector<Edge> edges;

  explicit MCMF(int n_) : n(n_), g(n) {}

  int add(int from, int to, T forward_cap, T backward_cap, C cost) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = edges.size();
    g[from].push_back(id);
    edges.push_back({from, to, forward_cap, 0, cost});
    g[to].push_back(id + 1);
    edges.push_back({to, from, backward_cap, 0, -cost});
    return id;
  }

  // works with negative costs because we use Bellman-Ford
  vector<pair<T, C>> solve(int st, int fin, int limit) {
    T flow = 0;
    C cost = 0;
    vector<pair<T, C>> bests(1, make_pair(flow, cost));
    while (true) {
      vector<C> dist(n, INF_C);
      vector<bool> in_queue(n, false);
      vector<int> que(1, st);
      vector<int> pe(n);
      dist[st] = 0;
      in_queue[st] = true;
      bool found = false;
      for (int b = 0; b < (int) que.size(); b++) {
        int v = que[b];
        if (v == fin) {
          found = true;
        }
        in_queue[v] = false;
        for (int id : g[v]) {
          const Edge& e = edges[id];
          int to = e.to;
          if (e.c - e.f > EPS && dist[v] + e.cost < dist[to]) {
            dist[to] = dist[v] + e.cost;
            pe[to] = id;
            if (!in_queue[to]) {
              que.push_back(to);
              in_queue[to] = true;
            }
          }
        }
      }
      if (!found) {
        break;
      }
      T push = numeric_limits<T>::max();
      int v = fin;
      while (v != st) {
        const Edge& e = edges[pe[v]];
        push = min(push, e.c - e.f);
        v = e.from;
      }
      v = fin;
      while (v != st) {
        Edge& e = edges[pe[v]];
        e.f += push;
        Edge& back = edges[pe[v] ^ 1];
        back.f -= push;
        v = e.from;
      }
      flow += push;
      cost += push * dist[fin];
      bests.emplace_back(flow, cost);
      if (flow == limit) {
        break;
      }
    }
    return bests;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  k = min(k, (1 << n) / 2);
  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    cin >> a[i];
  }
  vector<int> even, odd;
  vector<tuple<int, int, int>> all;
  all.reserve(n * (1 << (n - 1)));
  for (int i = 0; i < (1 << n); i++) {
    int cc = __builtin_popcount(i);
    if (cc % 2 == 0) {
      even.push_back(i);
      for (int j = 0; j < n; j++) {
        int to = i ^ (1 << j);
        all.emplace_back(a[i] + a[to], i, to);
      }
    } else {
      odd.push_back(i);
    }
  }
  int need = (2 * n - 1) * (k - 1) + 1;
  need = min(need, (int) all.size());
  nth_element(all.begin(), all.end() - need, all.end());
  assert(clock() * 1.0 / CLOCKS_PER_SEC < 1);
  vector<tuple<int, int, int>> good(all.end() - need, all.end());
  vector<int> used;
  for (auto [c, x, y] : good) {
    used.push_back(x);
    used.push_back(y);
  }
  MakeUnique(used);
  for (auto& [c, x, y] : good) {
    x = GetIndex(used, x);
    y = GetIndex(used, y);
  }
  const int U = used.size();
  MCMF<int, int> fg(U + 2);
  int st = U;
  int fin = st + 1;
  for (int x : even) {
    x = GetIndex(used, x);
    if (x != -1) {
      fg.add(st, x, 1, 0, 0);
    }
  }
  for (int y : odd) {
    y = GetIndex(used, y);
    if (y != -1) {
      fg.add(y, fin, 1, 0, 0);
    }
  }
  for (auto [c, x, y] : good) {
    fg.add(x, y, 1, 0, -c);
  }
  auto res = fg.solve(st, fin, k);
  assert(res[k].first == k);
  cout << -res[k].second << '\n';
  return 0;
}
