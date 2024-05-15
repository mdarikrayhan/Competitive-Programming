#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::string line, temp, str;
  for (int i = 0; i < n; i++) {
    std::cin >> line;
    temp += line;
  }
  str = temp;
  std::reverse(str.begin(), str.end());
  if (str != temp) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
  }
  return 0;
}
