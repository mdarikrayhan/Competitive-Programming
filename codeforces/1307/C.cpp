#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

string s;
long long n, cnt[MAXN][26];

void input() {
	cin >> s;
	n = s.size();
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 26; j++)
			cnt[i][j] = cnt[i - 1][j] + ((s[i - 1] - 'a') == j);
}

long long findAns() {
	long long res = 0;
	for (int i = 0; i < 26; i++) {
		res = max(res, cnt[n][i]);
		for (int j = 0; j < 26; j++) {
			long long t = 0;
			for (int k = 0; k < n; k++) {
				if ((s[k] - 'a') == i)
					t += (cnt[n][j] - cnt[k + 1][j]);
			}
			res = max(res, t);
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	input();
	cout << findAns() << endl;
	return 0;	
}