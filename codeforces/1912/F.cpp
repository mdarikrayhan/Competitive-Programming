#include "bits/stdc++.h"
#ifndef ALGO
#define DUMP(...)
#endif
using i64 = long long;
template<typename T, typename U>
inline bool enlarge(T& a, U b) {
  return a < b ? (a = b, true) : false;
}
template<typename T, typename U>
inline bool minify(T& a, U b) {
  return a > b ? (a = b, true) : false;
}

using Float = long double;

struct Solver {

  void solve(int ca, std::istream& reader) {
    int N;
    reader >> N;
    std::vector<std::vector<int>> adj(N, std::vector<int>(N, N));
    std::vector<int> deg(N);
    for (int i = 0; i < N - 1; ++i) {
      int x, y;
      reader >> x >> y; --x; --y;
      deg[x]++;
      deg[y]++;
      adj[x][y] = adj[y][x] = 1;
    }
    for (int i = 0; i < N; ++i) {
      adj[i][i] = 0;
    }
    for (int k = 0; k < N; ++k) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          minify(adj[i][j], adj[i][k] + adj[k][j]);
        }
      }
    }
    std::vector<int> leaves;
    for (int i = 0; i < N; ++i) {
      if (deg[i] == 1) {
        leaves.emplace_back(i);
      }
    }
    int M = leaves.size();
    std::vector<Float> y(M, 1);
    for (int iteration = 0; iteration < 2000; ++iteration) {
      std::vector<Float> yy(M);
      for (int i = 0; i < M; ++i) {
        Float p = 0, q = -1;
        for (int j = 0; j < M; ++j) if (i != j) {
          p += y[j];
          q += adj[leaves[i]][leaves[j]] * y[j] + 1;
        }
        yy[i] = p / q;
      }
      y.swap(yy);
    }
    DUMP(y);

    int S;
    reader >> S; --S;
    {
      Float p = 0, q = -1;
      for (int j = 0; j < M; ++j) if (leaves[j] != S) {
        p += y[j];
        q += adj[S][leaves[j]] * y[j] + 1;
      }
      Float result = q / p;
      printf("%.13f\n", (double)result);
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  // reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

