#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	ll a, b;
	cin >> a >> b;
	vector<ll> ans;
	if(a > b || ((b - a) & 1)) {
		cout << -1;
		return ;
	} else {
		if(a == b) {
			if(a != 0) {
				ans.emplace_back(a);
			}
		} else {
			ll c = (b - a) / 2, u = 0, v = 0;
			for(int i = 0; i < 63; i++) {
				if((c >> i) & 1) {
					u += (1ll << i);
					v += (1ll << i);
				} else if((a >> i) & 1) {
					u += (1ll << i);
				}
			}
			if(u + v == b && (u ^ v) == a) {
				ans.emplace_back(u);
				ans.emplace_back(v);
			} else {
				ans.emplace_back(a);
				ans.emplace_back((b - a) / 2), ans.emplace_back((b - a) / 2);
			}
		}
		cout << ans.size() << '\n';
		for(auto i : ans) {
			cout << i << ' ';
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}