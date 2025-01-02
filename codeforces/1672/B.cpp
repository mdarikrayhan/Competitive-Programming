// Problem: B. I love AAAB
// Contest: Codeforces - Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define all(s) s.begin(), s.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int _N = 1e5 + 5;

int T;

void solve() {
	string s; cin >> s;
	int n = s.length();
	int flag = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			flag++;
		} else {
			flag--;
			if (flag < 0) {
				cout << "NO" << '\n';
				return;
			}
		}
	}
	if (s[n - 1] == 'A') cout << "NO" << '\n';
	else cout << "YES" << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		solve();
	}
}