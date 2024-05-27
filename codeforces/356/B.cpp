// LUOGU_RID: 159683828
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, cnt[1000005][27];
string s, t;
signed main() {
	cin >> n >> m >> s >> t;
	int lcm = s.size() * t.size() / __gcd(s.size(), t.size());
	int x = __gcd(s.size(), t.size());
	for (int i = 0; i < t.size(); i++) {
		cnt[i % x][t[i] - 'a']++;
	}
	int ans = lcm;
	for (int i = 0; i < s.size(); i++) {
		ans -= cnt[i % x][s[i] - 'a'];
	}
	cout << ans * (n * s.size() / lcm);
	return 0;
}