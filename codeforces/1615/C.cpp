#include "bits/stdc++.h"

using namespace std;

#define N         '\n'
#define int        long long
#define all(v)    v.begin(),v.end()

int getAns(string &a, string &b) {
	int n = (int)a.size();
	if (count(all(a), '1') != count(all(b), '1'))
		return 9e18;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += a[i] != b[i];
	return cnt;
}

void testcases(int tc) {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int ans = getAns(a, b);
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1' && b[i] == '1')
			pos = i;
	}
	if (~pos) {
		for (int i = 0; i < n; i++)
			if (i != pos) {
				if (a[i] == '1')a[i] = '0';
				else a[i] = '1';
			}
		ans = min(ans, getAns(a, b) + 1);
		for (int i = 0; i < n; i++)
			if (i != pos) {
				if (a[i] == '1')a[i] = '0';
				else a[i] = '1';
			}
	}
	if (ans == 9e18)ans = -1;
	cout << ans << N;
}

int32_t main()
{	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int tt = 1;
	cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		// cout<<"Case #"<<tc<<": ";
		testcases(tc);
	}

	return 0;
}