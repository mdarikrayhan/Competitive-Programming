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
		int n, r; cin>>n>>r;

		r = min(r, n);
		int res = r*(r+1)/2;
		if (r >= n) res -= (r-1);
		cout<<res<<'\n';
	}

	return 0;
}
