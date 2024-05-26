#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
using li = long long;
using ld = long double;

void solve(bool read) {
  int n, k;
  string s;
  cin >> n >> k >> s;

  int pos = 0;
  for (int t = 0; t < k; ++t) {
    bool found = false;
    for (; pos < n;) {
      if (pos + 1 < n && s[pos] == '4' && s[pos + 1] == '7') {
        if (pos % 2 == 0 && pos + 2 < n && s[pos + 2] == '7') {
          int rest = max(0, (k - t - 10));
          k -= rest / 2 * 2;
        }

        found = true;
        if (pos % 2 == 0) {
          s[pos + 1] = '4';
        } else {
          s[pos] = '7';
          pos = max(0, pos - 2);
        }
        break;
      }

      ++pos;
    }
    if (!found) break;
  }

  cout << s << "\n";
}

int main() {
  solve(true);
  //while (true) solve(false);

  return 0;
}
