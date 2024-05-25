#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false) ; cin.tie(0);
  
  int t; cin >> t;
  while(t--){
    int a , b , c , d; cin >> a >> b >> c >> d;
    // (-inf , -1] * (-1 , 0) * (0 , 1) * [1 , inf];
    int sign = (a + b) % 2 ? -1 : 1;
    cout << (sign == -1 && a + d > 0 ? "Ya" : "Tidak") << " ";
    cout << (sign == -1 && b + c > 0 ? "Ya" : "Tidak") << " ";
    cout << (sign == 1 &&  b + c ? "Ya" : "Tidak") << " ";
    cout << (sign == 1 && a + d ? "Ya" : "Tidak") << "\n";
  }
  
  return 0;
}