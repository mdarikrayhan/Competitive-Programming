/*
 * author:  ADMathNoob
 * created: 04/30/24 15:06:27
 * problem: https://codeforces.com/contest/1557/problem/E
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

const int N = 8;

int queries;

pair<int, int> MoveTo(int r, int c) {
  assert(++queries <= 130);
  cout << r + 1 << ' ' << c + 1 << endl;
  string ret;
  cin >> ret;
  if (ret == "Done") return {-2, -2};
  int dx = 0, dy = 0;
  if (ret.find("Up") != string::npos) dx = -1;
  if (ret.find("Down") != string::npos) dx = 1;
  if (ret.find("Left") != string::npos) dy = -1;
  if (ret.find("Right") != string::npos) dy = 1;
  return {dx, dy};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  auto SolveTestCase = [&]() -> void {
    int r = 0, c = 0;
    queries = 0;
    int dr, dc;
    tie(dr, dc) = MoveTo(r, c);
    if (dr == -2) {
      return;
    }
    c += 1;
    bool reset = false;
    while (true) {
      tie(dr, dc) = MoveTo(r, c);
      if (dr == -2) {
        return;
      }
      if (dr == 1) {
        r += 1;
        reset = true;
        continue;
      }
      if (reset || dr == -1) {
        c = (c == 1 ? 0 : 1);
        reset = false;
        continue;
      }
      if (c == 6) {
        r += 1;
        reset = true;
        continue;
      }
      c = min(c + 2, 6);
    }
  };
  
  {
    int tt;
    cin >> tt;
    for (int qq = 1; qq <= tt; qq++) {
      SolveTestCase();
    }
  }

  return 0;
}
