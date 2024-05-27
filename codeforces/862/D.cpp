#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include "./algo/debug.h"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  auto ask = [&](string s) {
    cout << "? " << s << endl;
  };
  auto answer = [&](int x, int y) {
    cout << "! " << x << ' ' << y << endl;
  };
  string s = string(n, '0');
  ask(s);
  int hd;
  cin >> hd;
  s[0] = '1';
  ask(s);
  int hd2;
  cin >> hd2;
  int i = -1, j = -1;
  if (hd < hd2) i = 0;
  else j = 0;
  s[0] = '0';
  auto solve = [&]() {
    int lb = 1, rb = n - 1;
    while (lb <= rb) {
      int mb = (lb + rb) >> 1;
      auto t = s;
      for (int i = lb; i <= mb; i++) {
        t[i] = '1';
      }
      ask(t);
      int lhd;
      cin >> lhd;
      if (i > -1) {
        if (lhd - hd == mb - lb + 1) {
          lb = mb + 1;
        } else if (hd - lhd == mb - lb + 1) {
          j = lb;
          return;
        } else {
          rb = mb;
        }
      } else {
        if (lhd - hd == mb - lb + 1) {
          i = lb;
          return;
        } else if (hd - lhd == mb - lb + 1) {
          lb = mb + 1;
        } else {
          rb = mb;
        }
      }
    }
  };
  solve();
  answer(i + 1, j + 1);
  return 0;
}