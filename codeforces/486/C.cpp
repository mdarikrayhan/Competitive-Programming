#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dis(char a, char b) {
	int d = abs(a - b);
	return min(d, 26 - d);
}
void solve() {
	int n, p;
	string s;
	cin >> n >> p >> s;
	vector<int> a(n + 1), pre(n + 1, 0);
	for(int i = 0; i < n; i++) {
		a[i + 1] = dis(s[i], s[n - 1 - i]);
		a[n - i] = a[i + 1];
	}
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}
	if(p > (n + 1) / 2) {
		p = n + 1 - p;
	}
	int l = 1, r = (n + 1) / 2, ans;
	ans = pre[r];
	while(pre[l] == 0 && l < p) {
		l++;
	}
	while(pre[(n + 1) / 2] - pre[r - 1] == 0 && r > p) {
		r--;
	}
	ans += 2 * min(p - l, r - p) + max(p - l, r - p);
	cout << ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}