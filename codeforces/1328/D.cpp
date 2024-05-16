#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    set<int> s(a.begin(), a.end());
    vector<int> b(n);
    if((int) s.size() == 1) {
      b = vector<int> (n, 1);
    } else if(n % 2 == 0) {
      for(int i = 0; i < n; i++) {
        b[i] = (i % 2 == 0 ? 1 : 2);
      }
    } else {
      b[0] = 1;
      for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
          b[i] = b[i - 1]; 
        } else {
          b[i] = 3 - b[i - 1];
        }
      }
      if(b[n - 1] == b[0] && a[0] != a[n - 1]) {
        bool ok = 0;
        for(int i = 0; i + 1 < n; i++) {
          if(a[i] == a[i + 1] && !ok) {
            b[i + 1] = 3 - b[i];
            ok = 1;
          } else if(a[i] == a[i + 1]) {
            b[i + 1] = b[i];
          } else {
            b[i + 1] = 3 - b[i];
          }
        }
      }
      if(b[n - 1] == b[0] && a[n - 1] != a[0]) {
        b[n - 1] = 3;
      }
    }
    cout << *max_element(b.begin(), b.end()) << '\n';
    for(int i = 0; i < n; i++) {
      cout << b[i] << " \n"[i == n - 1];
    }
  }
  return 0;
}
