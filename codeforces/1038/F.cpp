# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <vector>
# include <map>
# include <climits>
# include <unordered_map>
using namespace std;
int main() {
	int n; string s;
	cin >> n >> s;
	int m = s.size();
	if (2 * m >= n) {
		long long sbit = 0;
		for (int i = 0; i < m; ++i) {
			sbit <<= 1;
			if (s[i] == '1') ++sbit;
		}
		vector<long long> bitlist;
		for (int i = 0; i < 1 << (n - m); ++i) {
			long long bit = (sbit << (n - m)) + i;
			for (int k = 0; k < n; ++k) {
				bitlist.push_back(bit);
				bit = (bit >> 1) + ((bit & 1) << (n - 1));
			}
		}
		sort(bitlist.begin(), bitlist.end());
		bitlist.erase(unique(bitlist.begin(), bitlist.end()), bitlist.end());
		cout << bitlist.size() << '\n';
	}
	else {
		vector<vector<long long> > mul(n, vector<long long>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				mul[i][j] = 1;
				string t = string(m - 1, 'X') + string(i + 1, '.');
				for (int k = i; k < i + m; ++k) t[k] = s[k - i];
				for (int k = j; k < j + m; ++k) {
					if (t[k] != 'X' && t[k] != '.' && t[k] != s[k - j]) mul[i][j] = 0;
					t[k] = s[k - j];
				}
				for (int k = j; k < t.size(); ++k) {
					if (t[k] == '.') mul[i][j] *= 2;
				}
			}
		}
		long long ret = 0;
		for (int i = 0; i < 1 << (m - 1); ++i) {
			vector<long long> dp(n);
			for (int j = 0; j < n; ++j) {
				bool match = true;
				for (int k = 0; k < m; ++k) {
					int pl = (j + k) % n;
					if (pl < m - 1 && (s[k] - '0') != (((i >> pl) & 1) ? 1 : 0)) {
						match = false;
						break;
					}
				}
				if (match) {
					for (int k = j - 1; k >= 0; --k) {
						dp[j] += -dp[k] * mul[j][k];
					}
					dp[j] += 1LL << max(j - (m - 1), 0);
				}
			}
			long long delta = 0;
			for (int j = 0; j < n; ++j) delta += dp[j] << max((n - j - 1) - (m - 1), 0);
			ret += delta;
		}
		cout << ret << '\n';
	}
	return 0;
}