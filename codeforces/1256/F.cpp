/*
BuzzyBeez
20:47 UTC+7
25/05/2024 
*/
#include <bits/stdc++.h>
using namespace std;

int fs[26], ft[26];
int pt[26];
string s, t;

void reset() {fill(fs, fs + 26, 0); fill(ft, ft + 26, 0); fill(pt, pt + 26, 0);}

void solve() {
	reset();
	int n, delta = 0, l; cin >> n >> s >> t; 
	for (char c : s) ++fs[c - 'a'];
	for (char c : t) ++ft[c - 'a'];
	for (int c = 0; c < 26; ++c) if (fs[c] != ft[c]) {cout << "NO\n"; return;}
	for (int c = 0; c < 26; ++c) if (fs[c] > 1) {cout << "YES\n"; return;}
	for (int i = 0; i < n; ++i) pt[t[i] - 'a'] = i;
	for (int i = 0; i < n; ++i) {
		delta += pt[s[i] - 'a'] - i; 
		for (int j = pt[s[i] - 'a']; j > i; --j) swap(t[j], t[j - 1]);
		for (int i = 0; i < n; ++i) pt[t[i] - 'a'] = i;
	}
	cout << (delta & 1 ? "NO\n" : "YES\n");
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while (tc--) solve();
}