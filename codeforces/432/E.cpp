#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	int n, m;
	cin >> n >> m;
	vector a(n + 2, vector<int>(m + 2, -1));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] != -1) {
				continue;
			}
			for(int k = 0; k < 26; k++) {
				int len = 0, flag = 0;
				if(a[i - 1][j] == k || a[i][j + 1] == k) {
					flag = 1;
				} else if(a[i][j - 1] == k) {
					for(int o = 1; j - o >= 1; o++) {
						if(a[i][j - o] != k) {
							break;
						}
						len++;
					}
					if(i + len > n) {
						flag = 1;
					}
				}
				if(!flag) {
					for(int o = 0; o <= len; o++) {
						a[i + o][j] = k;
						a[i + len][j - o] = k;
					}
					break;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << (char)(a[i][j] + 'A');
		}
		cout << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}