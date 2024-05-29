// LUOGU_RID: 158264088
#include <bits/stdc++.h>
using namespace std;

string c[10005];
int ans[10005];
int zy[10005];
short id[(1 << 26) + 5];

signed main() {
	ios::sync_with_stdio();
	cin.tie();
	string s;
	int m;
	cin >> s >> m;
	for (int i = 1; i <= m; i++) {
		cin >> c[i];
		for (int j = 0; j < c[i].size(); j++) {
			zy[i] |= (1 << (c[i][j] - 'a'));
		}
		id[zy[i]] = i;
	}
	int len = s.size();
	s = " " + s;
	for (int i = 1; i <= len; i++) {
		int sum = 0;
		for (int j = i; j <= len; j++) {
			if (i != j && s[j] == s[i]) {
				break;
			}
			sum |= (1 << (s[j] - 'a'));
			if (j == len || !(sum & (1 << (s[j + 1] - 'a')))) {
				ans[id[sum]]++;
			}
		}
	}
	
	for (int i = 1; i <= m; i++)
		cout << ans[id[zy[i]]] << "\n";
	return 0;
}