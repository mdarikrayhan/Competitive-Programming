#include<bits/stdc++.h>

#define ll long long

void solve() {
	int n; std::cin >> n;
	std::string s; std::cin >> s;
	int cnt = 0;
	// std::set<int> st;
	for (int i = (n - 1) / 2; i >= 0; i--) {
		// std::cout << i << " " << cnt << "\n";
		if (s[i] != s[n / 2]) break;
		if (i == n / 2 && (n & 1)) {
			cnt--;	
		}
		cnt = cnt + 2;
	}
	std::cout << cnt << "\n";
}

int main() {		
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	
	int t = 1;
	std::cin >> t;
	while (t--) {
			solve();
	}
	return 0;
}