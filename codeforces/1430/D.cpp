#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {

	ll n; cin >> n;
	string s; cin >> s;

	vector<ll>v;
	char c = s[0];
	ll ct = 1;
	for (ll i = 1; i < n; i++) {
		if (s[i] == c) {
			ct++;
		}
		else {
			v.push_back(ct);
			c = s[i];
			ct = 1;
		}
	}
	v.push_back(ct);


	ll ans = 0, k = 0;
	for (ll i = 0; i < v.size(); i++) {
		k = max(k, i);
		while (k < v.size() && v[k] == 1)k++;
		if (k == v.size()) {
			ans += (k - i + 1) / 2;
			break;
		}
		v[k]--;
		ans++;

	}

	cout << ans << endl;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll t = 1;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}