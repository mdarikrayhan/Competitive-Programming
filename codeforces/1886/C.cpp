// LUOGU_RID: 159219043
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int p, n;
	string s;
	cin >> s >> p;
	n = s.length();
	s = " " + s + " ";
	vector<char>stk;
	bool done = (p <= n);
	for (int i = 1; i <= s.length() + 1; i++) {
		while ((!done) && (!stk.empty()) && (stk.back() > s[i])) {
			stk.pop_back();
			p -= (n--);
			done = (p <= n);
		}
		stk.push_back(s[i]);
	}
	cout << stk[p - 1];
	return;
}

signed main() {
	int ____ = 1;
	cin >> ____;
	while (____--)solve();
	return 0;
}