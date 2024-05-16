#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e6 + 1, mod = 1 << 30;
int d[N];

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  for (int i = 1; i < N; ++i) {/// O (n*log(n))
    for (int j = i; j < N; j += i) {
      d[j] += 1;
    }
  }
  int a, b, c;
  cin >> a >> b >> c;
  ll res = 0;
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      for (int k = 1; k <= c; ++k) {
        res += d[i * j * k];
//        res %= mod;
      }
    }
  }
  cout << res;
}

  			   		 			 		 			    		 			