#include <bits/stdc++.h>

using namespace std;
using ll  =  long long;

#ifdef wk
#include "algo/debug.h"
#else
#define deb(x...) 42
#endif
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define szof(x) (int)x.size()
#define int ll

template<class T> bool MIN(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool MAX(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int mod = 1e9 + 7;
const int N = 6e6 + 5;
const int inf = 2147483647;
const int INF = 9223372036854775807;
// Follow the white rabbit.	
struct dark {
	
};



void ka () {
	int n; cin >> n;
	int l = 1, r = n;
	while (l < r) {
		cout << l++ << ' ';
		if (l > r) break;
		cout << r-- << ' ';
	}
	if (n % 2) cout << n / 2 + 1;
}


const bool overflow = 0;

main() {
  //freopen(".in", "r", stdin); freopen(".out", "w", stdout);
  cout.setf(ios::fixed);cout.precision(12);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int tc = 1; 
  if (overflow) cin >> tc;
  for (int cs = 1; cs <= tc; cs ++) {
		#ifdef wk
		cout << ":D\n";
		#endif
		ka();
		if (cs != tc) cout << '\n';
  }
}

bool bt (int MASK, int BIT) {return (MASK & (1 << BIT));} 
