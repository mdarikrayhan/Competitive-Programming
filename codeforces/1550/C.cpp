/*adid_r10*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//#define int long long

const int N = 1e5 + 9, MOD = 1e9 + 7;

void LesGo () {
	int n; cin >> n;
	vector <int> v (n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		bool done = 0;
		for (int j = i + 2; j <= min(n, i + 10); j++) {
			bool ok = 1;
			for (int g = i; g < j - 1; g++) {
				for (int k = g + 1; k < j; k++) {
					if ((v[k] > v[j] && v[k] > v[g]) or (v[k] < v[j] && v[k] < v[g])){
						;
					} else {
						ok = 0;
						break;
					}
				}
				if (!ok) break;
			}
			if (!ok) {
				ans += j - i;
				done = 1;
				// cout << i << ' ' << j <<  '\n';
				break;
			}
		}
		if (!done) {
			ans += n - i + 1;
		} else {
			// cout << i << '\n';
		}
	}
	cout << ans << '\n';
}

int32_t main () {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t = 1; 
	cin >> t;
	int cc = 1;
	while(t--){
		//cout << "Case " << cc++ << ": ";
		LesGo();
	}
	return 0;
} 