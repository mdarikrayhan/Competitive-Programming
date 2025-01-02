#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define multitest 0
void file();
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	vector<int> row(n, 0), col(m, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == '*') {
				row[i]++;
				col[j]++;
			}
		}
	}

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '*') {
				ans += (row[i] - 1) * (col[j] - 1);
			}
		}
	}

	cout << ans << endl;
}
int main() {
	file();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#if multitest
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++) {
		solve();
	}
#else
	solve();
#endif
}

void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}