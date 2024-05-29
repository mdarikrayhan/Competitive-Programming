#line 1 "main.cpp"
#include <bits/stdc++.h>

int N;
int A[10][10];

using namespace std;

template <typename F>
void run(F f) {
  (N <= 0 || f(0));
  (N <= 1 || f(1));
  (N <= 2 || f(2));
  (N <= 3 || f(3));
  (N <= 4 || f(4));
  (N <= 5 || f(5));
  (N <= 6 || f(6));
  (N <= 7 || f(7));
  (N <= 8 || f(8));
  (N <= 9 || f(9));
}

void solve() {
  cin >> N;
  run([&](int i) -> bool {
    run([&](int j) -> bool {
      cin >> A[i][j];
      return 0;
    });
    return 0;
  });

  run([&](int k) -> bool {
    run([&](int i) -> bool {
      run([&](int j) -> bool {
        int x = A[i][k] + A[k][j];
        ((A[i][j] < x) || (A[i][j] = x));
        return 0;
      });
      return 0;
    });
    return 0;
  });

  int ANS = 0;
  run([&](int i) -> bool {
    run([&](int j) -> bool {
      int x = A[i][j];
      ((ANS > x) || (ANS = x));
      return 0;
    });
    return 0;
  });

  cout << ANS << "\n";
}

signed main() {
  solve();
  return 0;
}
