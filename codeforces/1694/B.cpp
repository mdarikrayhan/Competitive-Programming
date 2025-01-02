#include<bits/stdc++.h>

#define ll long long

void solve() {
	int n; std::cin >> n;
	std::string s; std::cin >> s;
	int i = 0;
	std::vector<int> b;
	while (i < n) {
		int i0 = i++;
		while (i < n && s[i] == s[i - 1]) {
			i++;	
		}
		b.push_back(i - i0);
	}
	
	
	ll ans = n;
	int cnt = 0;
	for (int i = 0; i < b.size(); i++) {
		ans = ans + cnt;
		cnt += b[i];
	}
	std::cout << ans << "\n";
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