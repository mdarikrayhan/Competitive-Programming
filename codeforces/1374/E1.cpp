/* 14.05.2024 11:14:38 */

#include <bits/stdc++.h>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  std::cin >> n >> k;
  std::multiset<int> qu[3];
  for (int i = 0; i < n; ++i) {
    int t, a, b;
    std::cin >> t >> a >> b;
    if (a == 1 && b == 1) {
      qu[0].emplace(t);
    } else if (a == 0 && b == 1) {
      qu[1].emplace(t);
    } else if (a == 1 && b == 0) {
      qu[2].emplace(t);
    }
  }
  int sm = 0;
  int read = 0;
  while (read < k) {
    if (qu[1].empty() || qu[2].empty()) {
      if (qu[0].empty()) {
        break;
      }
      sm += *qu[0].begin();
      qu[0].erase(qu[0].begin());
      ++read;
    } else {
      int cur = *qu[1].begin() + *qu[2].begin();
      if (qu[0].empty() || cur <= *qu[0].begin()) {
        sm += cur;
        qu[1].erase(qu[1].begin());
        qu[2].erase(qu[2].begin());
        ++read;
      } else {
        sm += *qu[0].begin();
        qu[0].erase(qu[0].begin());
        ++read;
      }
    }
  }
  if (read < k) {
    std::cout << -1 << '\n';
  } else {
    std::cout << sm << '\n';
  }

  return 0;
}
