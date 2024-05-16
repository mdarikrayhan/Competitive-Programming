#include<iostream>
#include<iterator>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<list>
#include<bits/stdc++.h>
#include<utility>
#include<iomanip>
#define int long long int
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}


void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	// cout << gcd(36, 24) << ' ' << gcd(24, 36) << endl;

	if (gcd(a[0], a[1]) <= 2) {cout << "YES" << endl; return;}

	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (gcd(a[i], a[j]) <= 2) {flag = 1; break;}
		}
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return;
}

int32_t main() {

	// for fast i/o to be wriiten every time
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	cin.ignore();
	while (t--) solve();
	return 0;
}