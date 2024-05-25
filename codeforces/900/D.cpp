#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int kN = 31623;
const int kM = 1e9 + 7;

int t, n;
bool v[kN];
vector<int> p;
LL ans;

LL Pow(LL b, int e) {
  LL s = 1;
  for (; e; e /= 2, b = b * b % kM) {
    (e & 1) && (s = s * b % kM);
  }
  return s;
}
int Mu(int n) {
  int s = 0;
  for (int i : p) {
    if (i * i > n) {
      break;
    }
    int c = 0;
    for (; n % i == 0; n /= i, ++c) {
    }
    if (c > 1) {
      return 0;
    }
    s += c;
  }
  if (n > 1) {
    ++s;
  }
  return ((s & 1) ? -1 : 1);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  for (int i = 2; i < kN; ++i) {
    if (!v[i]) {
      p.push_back(i);
    }
    for (int j : p) {
      if (i * j >= kN) {
        break;
      }
      v[i * j] = 1;
      if (i % j == 0) {
        break;
      }
    }
  }
  int x, y;
  cin >> x >> y;
  if (y % x) {
    cout << 0;
    return 0;
  }
  y /= x;
  for (int i = 1; i * i <= y; ++i) {
    if (y % i == 0) {
      ans = (ans + Mu(i) * Pow(2, y / i - 1) % kM + kM) % kM;
      if (y / i != i) {
        ans = (ans + Mu(y / i) * Pow(2, i - 1) % kM + kM) % kM;
      }
    }
  }
  cout << ans;
  return 0;
}
 	 		    	  				  	   			  	  	