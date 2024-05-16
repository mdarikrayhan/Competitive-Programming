/* 16.05.2024 19:31:43 */

#include <bits/stdc++.h>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s;
  std::cin >> s;
  int n = (int) s.size();
  std::vector<char> sk;
  for (int i = 0; i < n; ++i) {
    if (!sk.empty() && sk.back() == s[i]) {
      sk.pop_back();
      continue;
    }
    sk.emplace_back(s[i]);
  }
  std::cout << (sk.empty() ? "Yes" : "No") << '\n';

  return 0;
}
