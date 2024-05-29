/*
BuzzyBeez
22:00 UTC+7
16/04/2024 
*/
#include <bits/stdc++.h>
using namespace std;

int fact[13];
bool mark[13];

bool lucky(int x) {
	while (x) {
		if (x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}

vector<int> lucky_numbers;

signed main() {
	int n, k; cin >> n >> k; --k;
	int m = min(n, 13);
	if (n <= 13) {
		long long f = 1;
		for (int i = 1; i <= n; ++i) f *= i;
		if (f <= k) {cout << -1; return 0;}
	}
	for (int i = 1; i < 10; ++i) {
		int num;
		for (int msk = 0; msk < (1 << i); ++msk) {
			num = 0;
			for (int bit = 0; bit < i; ++bit)
				if (msk & (1 << bit)) num = num * 10 + 4;
				else num = num * 10 + 7;
			lucky_numbers.push_back(num);
		}
	}
	sort(lucky_numbers.begin(), lucky_numbers.end());
	fact[0] = 1;
	for (int i = 1; i <= 12; ++i) fact[i] = fact[i - 1] * i;
	vector<int> v(m); int cur, cnt;
	for (int i = 0; i < m; ++i) v[i] = n + i + 1 - m;
	vector<int> p(m); vector<int> a;
	for (int i = 0; i < m; ++i) {
		cur = k / fact[m - i - 1]; cnt = 0;
		for (int j = 0; j < m; ++j) {
			if (cnt == cur && !mark[j]) {p[i] = j; break;}
			if (!mark[j]) ++cnt;
		}		
		mark[p[i]] = 1;
		k %= fact[m - i - 1];
	}
	for (int i : p) a.push_back(v[i]);
	int ans = 0;
	for (int i = n - m + 1; i <= n; ++i) if (lucky(i) && lucky(a[i - (n - m + 1)])) ++ans;
	ans += lower_bound(lucky_numbers.begin(), lucky_numbers.end(), n - m + 1) - lucky_numbers.begin();
	cout << ans;
	
}