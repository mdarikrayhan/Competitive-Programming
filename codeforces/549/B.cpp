#include<bits/stdc++.h>
using namespace std;

int c[105][105];
int num[105];
int ans[105];

signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &c[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
	}
	int cc = 0, cnt = 0;
	while (1) {
		cc++;
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			if (num[i] == 0 && ans[i] == 0) {
				ans[i] = 1;
				cnt++;
				for (int j = 1; j <= n; j++) {
					if (c[i][j] == 1) {
						num[j]--;
					}
				}
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			break;
		}
		if (cc > n) {
			cout << "-1";
			return 0;
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}
