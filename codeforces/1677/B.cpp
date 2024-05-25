// LUOGU_RID: 159555127
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6 + 10;
const int inf = 1e9;
int n, m;
int lst;
int cnt_col;
int row[MAXN];
int col[MAXN];
char a[MAXN];
void init() {
	lst = -inf;
	cnt_col = 0;
	for (int i = 0; i < m; ++i) {
		row[i] = col[i] = 0;
	}
}
void solve() {
	cin >> n >> m >> a;
	init();
	for (int i = 0; i < n * m; ++i) {
		if (a[i] == '1') {
			lst = i;
			if (!col[i % m]) {
				col[i % m] = 1;
				++cnt_col;
			}
		}
		if (i - lst < m) {
			++row[i % m];
		}
		cout << cnt_col + row[i % m] << " ";
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}