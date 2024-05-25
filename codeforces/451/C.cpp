#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
 
int solveFaster(LL n, LL k, LL d1, LL d2) {
      if (n % 3 != 0) {
            return 0;
      }
 
      for (int sign1 = -1; sign1 <= 1; sign1++) {
            for (int sign2 = -1; sign2 <= 1; sign2++) {
                  if (sign1 == 0 || sign2 == 0) {
                        continue;
                  }
                  LL D1 = d1 * sign1;
                  LL D2 = d2 * sign2;
 
                  LL x2 = (k - D1 + D2) / 3;
                  if ((k - D1 + D2) % 3 != 0) {
                        continue;
                  }
                  if (x2 >= 0 && x2 <= k) {
                        LL x1 = D1 + x2;
                        LL x3 = x2 - D2;
                        if (x1 >= 0 && x1 <= k && x3 >= 0 && x3 <= k) {
                              if (x1 <= n / 3 && x2 <= n / 3 && x3 <= n / 3) {
                                    //assert(abs(x1 - x2) == d1);
                                    //assert(abs(x2 - x3) == d2);
                                    return true;
                              }
                        }
                  }
            }
      }
 
      return false;
}
 
int main() {
	int T;
	cin >> T;
	
	while (T--) {
		LL n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;
	
		int ans = solveFaster(n, k, d1, d2);
		if (ans == 1)
			cout << "yes" << endl;
		else 
			cout << "no" << endl;
	}
	
      return 0;
}