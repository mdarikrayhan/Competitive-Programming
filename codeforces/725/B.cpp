#include<bits/stdc++.h>
using namespace std;

long long toLL (string s) {
	int len = s.length();
	long long res = 0LL;
	for (int i = 0; i < len; i++) {
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s, k = "fedabc";
	cin >> s;
	char ss = s.back();
	s.pop_back();
	long long n = toLL(s);
	long long ans;
	ans = (n - 1) / 4 * 16;
	if (!(n & 1)) ans += 7;
	for (int i = 0; i < 6; i++) {
		if (ss == k[i]) {
			ans += i + 1;
			cout << ans;
			return 0;
		}
	}
	return 0;
}