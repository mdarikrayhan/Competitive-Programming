// LUOGU_RID: 159960520
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<pair<int, int>, int>cnt;
int n, x[2005], y[2005];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < i; ++j) 
			cnt[make_pair(x[i] + x[j], y[i] + y[j])]++;
	ll ans = 0;
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		int t = it->second;
		ans += t * (t - 1) / 2;
	}
	cout << ans;
}