#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

/*
	Hint:
	1.left存储左端点,right存储右端点.
	2.存在最小右端点rn,假如存在左端点lm>rn，说明一定存在不相交线段.
*/

#define int long long
#define endl '\n'

void solve() {
	int n;cin >> n;
	multiset<int>left, right;

	for (int i = 1;i <= n;i++) {
		char op;
		int l, r;
		cin >> op >> l >> r;

		if (op == '+') {
			left.insert(l);right.insert(r);
		}
		else {
			auto ll = left.find(l);
			auto rr = right.find(r);
			left.erase(ll);right.erase(rr);
		}

		if (left.size() <= 1) {
			cout << "NO\n";
		}
		else {
			int r = *right.begin();
			auto it = left.upper_bound(r);
			if (it == left.end()) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t = 1;
	while (t--) solve();
	return 0;
}