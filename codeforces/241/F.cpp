// LUOGU_RID: 158261855
#include <bits/stdc++.h>
using namespace std;
pair <int, int> xy[30];
char s[1005];
char a[105][105];
int c[105][105];
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (a[i][j] >= 'a' && a[i][j] <= 'z') {
				xy[a[i][j] - 'a'] = {i, j};
				c[i][j] = 1;
			}
			else {
				c[i][j] = a[i][j] - '0';
			}
		}
	}
	int sx, sy;
	cin >> sx >> sy;
	scanf("%s", s + 1);
	cin >> xy[26].first >> xy[26].second;
	int len = strlen(s + 1) + 1;
	
	for (int i = 1; i < len; i++) {
		s[i] -= 'a';
	}s[len] = 26;
	int nowx = sx, nowy = sy;
	
	for (int i = 1; i <= len; i++) {
		while (nowx != xy[s[i]].first || nowy != xy[s[i]].second) {
			k -= c[nowx][nowy];
			if (k < 0) {
				break;
			}
			if (nowx > xy[s[i]].first)nowx--;
			if (nowx < xy[s[i]].first)nowx++;
			if (nowy > xy[s[i]].second)nowy--;
			if (nowy < xy[s[i]].second)nowy++;
		//	cout << nowx << ":" << nowy << endl;
		}
		if (k <= 0)break;
	}
	cout << nowx << " " << nowy;
	return 0;
}