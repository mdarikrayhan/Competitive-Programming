#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

void solve() {
  int n, counter;
  std::cin >> n;
  std::map<int, std::pair<int, int>> dict;
  counter = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (dict.find(x) == dict.end()) {
      dict[x] = {0, i};
    } else {
      int first, second;
      first = dict[x].first;
      second = dict[x].second;
      if (first == 0) {
        dict[x] = {i - second, i};
      }
      if (first != 0) {
        if (i - second == first) {
          dict[x] = {first, i};
        } else {
          dict[x] = {-1, i};
        }
      }
    }
  }
  for (auto& item: dict) {
    if (item.second.first != -1) {
      ++counter;
    }
  }
  std::cout << counter << "\n";
  for (auto& item: dict) {
    if (item.second.first != -1) {
      std::cout << item.first << " " << item.second.first << "\n";
    }
  }
}

int main() {
  solve();
  return 0;
}