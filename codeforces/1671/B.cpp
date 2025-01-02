#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define int ll
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

signed main() {
	cin.tie(0)->sync_with_stdio(false);
	cin.exceptions(cin.failbit);

	int tt; cin>>tt;
	while (tt--) {
		int n; cin>>n;
		vector<int> x(n);
		for (int i = 0; i < n; i++) cin>>x[i];

		x[0] += 1;
		for (int i = 1; i < n; i++) {
			int dif = x[i] - x[i-1];
			if (dif == 1) {
				continue;
			} else if (dif > 1) {
				x[i] -= 1;
			} else {
				x[i] += 1;
			}
		}

		bool valid = true;
		for (int i = 1; i < n; i++) {
			if (x[i] != x[i-1]+1) valid = false;
		}
		cout<<(valid? "YES\n": "NO\n");
	}

	return 0;
}

     					    						 	 			  		