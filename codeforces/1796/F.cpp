#include <bits/stdc++.h>
 
using namespace std;

#define sz(a) int((a).size())

using li = long long;

const int MAXLEN = 5;

vector<int> divs(int x) {
  vector<int> res;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      res.push_back(i);
      if (i * i != x)
        res.push_back(x / i);
    }
  }
  return res;
}

int main() {
  int A, B, N;
  cin >> A >> B >> N;

  vector<int> pw(10);
  pw[0] = 1;
  for (int i = 1; i < 10; ++i) pw[i] = pw[i - 1] * 10;
  
  int PW = pw[MAXLEN];
  set<array<int, 3>> used;
  
  vector<int> len(PW);
  for (int i = 0; i < PW; ++i)
    len[i] = sz(to_string(i));
  
  for (int lenn = 1; lenn <= 9; ++lenn) {
    int x = pw[lenn] - 1;
    for (int k2 : divs(x)) {
      int r = x / k2;
      for (int d = 1; d < PW; ++d) {
        for (int lenb = len[d]; lenb <= MAXLEN; ++lenb) {
          int bg = pw[lenb] - d * li(r) % pw[lenb];
          int dd = d / __gcd(d, bg);
          int lb = (pw[lenb - 1] + bg - 1) / bg;
          int rb = (pw[lenb] - 1) / bg;
          for (int g = (lb + dd - 1) / dd * dd; g <= rb; g += dd) {
            int b = bg * g;
            assert(b % d == 0);
            if (b >= B || __gcd(b / d, r) != 1) continue;
            int ag = (d * li(r) + bg) / pw[lenb];
            li n = b / d * li(k2) * ag;
            if (n < N && ag * g < A && __gcd(ag, bg) == 1 && sz(to_string(n)) == lenn) 
              used.insert({ag * g, b, n});
          }
        }
      }
    }
  }
  
  int res = 0;
  for (auto it : used) {
    li a = it[0], b = it[1], n = it[2];
    int lenn = sz(to_string(n));
    int lenb = sz(to_string(b));
    res += a * b * pw[lenn] + n * b == a * n * pw[lenb] + a * b;
  }
  
  cout << res << endl;
}
