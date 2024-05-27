// LUOGU_RID: 160082425
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5 + 10;
int n;
int ans;
int a[MAXN];
int s[MAXN];

int cei (int x, int y) {
	if (x % y) {
		return x / y + 1;
	}
	return x / y;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] - min(i, n - i + 1) < 0) {
			continue;
		}
		++s[a[i] - min(i, n - i + 1)];
		ans = max(ans, s[a[i] - min(i, n - i + 1)]);
	}
	cout << n - ans << endl;
	return 0;
} 