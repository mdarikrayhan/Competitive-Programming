#include "bits/stdc++.h"

using namespace std;

#define N         '\n'
#define int        long long
#define all(v)    v.begin(),v.end()

void testcases(int tc) {
	int n, x, y;
	cin >> n >> x >> y;
	string s; cin >> s;
	vector<int>use;
	int cnt = 0;
	for (auto &it : s) {
		if (it == '1') {
			if (cnt)use.push_back(cnt);
			cnt = 0;
		} else
			cnt++;
	}
	int ans = 9e18;
	if (cnt)use.push_back(cnt);
	for (int i = 1; i <= use.size(); i++) {
		int temp = (int)use.size() / i;
		int reem = (int)use.size() % i;
		int cur_sum = 0;
		cur_sum += (temp * (i - 1) * x);
		if (reem)cur_sum += (reem - 1) * x;
		cur_sum += (temp + (reem != 0)) * y;
		ans = min(ans, cur_sum);
	}
	if (ans == 9e18)ans = 0;
	cout << ans;
}

int32_t main()
{	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		// cout<<"Case #"<<tc<<": ";
		testcases(tc);
	}

	return 0;
}