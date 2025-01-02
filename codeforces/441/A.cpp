#include <bits/stdc++.h>
int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> sellers;
  for (int i = 1; i <= n; i++) {
    int antq;
    std::cin >> antq;
    bool hasIt = false;
    for (int j = 0; j < antq; j++) {
      int price;
      std::cin >> price;
      if (price < k) {
        hasIt = true;
      }
    }
    if (hasIt) {
      sellers.push_back(i);
    }
  }

  std::cout << sellers.size() << "\n";
  for (int seller : sellers) {
    std::cout << seller << "\n";
  }

  return 0;
}
