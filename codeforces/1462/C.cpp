#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    if (n > 45){
      cout << "-1\n";
      continue;
    }
    int ans = 0;
    for (int i = 9; i >= 1; i--){
      ans += i;
      if (ans > n){
        cout << n - ans + i;
        for (int j = i + 1; j <= 9; j++){
          cout << j;
        }
        cout << "\n"; break;
      }
      if (ans == n){
        for (int j = i; j <= 9; j++){
          cout << j;
        }
        cout << "\n"; break;
      }
    }
  }
  return 0;
}
 	    	   						 	    		  		 	