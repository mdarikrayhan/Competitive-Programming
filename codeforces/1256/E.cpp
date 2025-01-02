#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX = 2e5 + 5;

int n;
array<int, 2> a[MAX];
int col[MAX];
ll dp[MAX];

ll f(int i) {
	if (i == n + 2) return 0;
	if (i >= n) return 1e18;
	auto &ans = dp[i];
	if (~ans) return ans;
	ans = f(i + 1);
	ans = min(a[i][0] - a[i + 1][0] + f(i + 3), ans);
	return ans;
}

void g(int i, int cur) {
	if (i >= n) return;
	if (f(i + 1) <= a[i][0] - a[i + 1][0] + f(i + 3)) {
		col[a[i][1]] = col[a[i - 1][1]];
		g(i + 1, cur);
	}
	else {
		col[a[i][1]] = col[a[i - 1][1]];
		col[a[i + 1][1]] = ++cur;
		col[a[i + 2][1]] = cur;
		g(i + 3, cur);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < MAX; i++) a[i][1] = i;
	for (int i = 0; i < n; i++)
		cin >> a[i][0];
	sort(a, a + n);

	memset(dp, -1, sizeof dp);
	col[a[0][1]] = 1;
	col[a[1][1]] = 1;
	g(2, 1);
	cout << -a[0][0] + f(2) << ' ' << col[a[n - 1][1]] << '\n';
	for (int i = 0; i < n; i++) {
		cout << col[i] << ' ';
	}
	cout << '\n';
	return 0;
}
