#include<bits/stdc++.h>

#define ll long long

void solve() {
	int m, n, k; std::cin >> m >> n >> k;
	std::string s, t;
	std::cin >> s >> t;
	
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());
	
	int i = 0, j = 0;
	std::string str;
	int cnt = 0;
	int p = 0;
	while (i < m && j < n) {
		if (cnt >= k) {
			if (p == 0) {
				str += t[j++];
				cnt = 1;
				p = 1;
			} else {
				str += s[i++];
				cnt = 1;
				p = 0;
			}
		} else {
			if (s[i] <= t[j]) {
				str += s[i++];
				if (p == 1) {
					p = 0;
					cnt = 1;
				} else {
					cnt++;
				}
			} else {
				str += t[j++];
				if (p == 0) {
					p = 1;
					cnt = 1;
				} else {
					cnt++;
				}
			}
		}
	}
	std::cout << str << "\n";
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