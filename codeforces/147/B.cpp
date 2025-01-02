#include <bits/stdc++.h>

using namespace std;

const int N = 310;

int n, m, d[10][N][N], f[N][N], tmp[N][N];

int main() {
	scanf("%d%d", &n, &m);
	memset(d, -0x3f, sizeof d);
	memset(f, -0x3f, sizeof f);
	for (int i = 1; i <= n; i++) {
		d[0][i][i] = f[i][i] = 0;
	}
	while (m--) {
		int a, b, c1, c2;
		scanf("%d%d%d%d", &a, &b, &c1, &c2);
		d[0][a][b] = max(d[0][a][b], c1);
		d[0][b][a] = max(d[0][b][a], c2);
	}
	
	for (int t = 1; t < 10; t++) {
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					d[t][i][j] = max(d[t][i][j], d[t-1][i][k]+d[t-1][k][j]);
				}
			}
		}
	}
	
	int res = 0;
	for (int t = 9; t >= 0; t--) {
		memset(tmp, -0x3f, sizeof tmp);
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					tmp[i][j] = max(tmp[i][j], f[i][k]+d[t][k][j]);
				}
			}
		}
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (tmp[i][i] > 0) {
				flag = true; break;
			}
		}
		if (flag) continue;
		else {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					f[i][j] = tmp[i][j];
				}
			}
			res += (1<<t);
		}
	}
	if (res >= n) res = -1;
	printf("%d\n", res+1);
	
	return 0;
}