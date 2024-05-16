#include <bits/stdc++.h>

const int max_size = 505;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::map < int, int > mp;
  for (int i = 1; i <= max_size; i++) {
    int triangular_number = i * (i + 1) / 2;
    mp[triangular_number]++;
  }
  int n;
  std::cin >> n;
  if (mp[n] != 0) {
    std::cout << "YES" << '\n';
  } else {
    std::cout << "NO" << '\n';
  }
  return 0;
}