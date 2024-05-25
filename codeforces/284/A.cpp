#include <iostream>

using namespace std;

int p; 

int phi (int x) {
  int res = x;
  for (int i = 2; i * i <= x; ++i) {
    if (!(x % i)) {
      while (!(x % i)) x /= i;
      res = res / i * (i - 1);
    }
  }
  if (x != 1) res = res / x * (x - 1);
  return res;
} 

int main () {
  cin >> p; 
  cout << phi(p - 1) << '\n';
  return 0; 
} 