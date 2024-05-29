#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, u, v;
	cin >> n >> m;
	int edge[n][n]{};
	int lens[n]{};
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		edge[u - 1][v - 1] = 1;
		edge[v - 1][u - 1] = 1;
		lens[u - 1] += 1;
		lens[v - 1] += 1;
	}
	long long ans = 0;
	long long minus = 0;
	for (int i = 0; i < n; i++) {
		int cnt2[n]{};
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (edge[i][k] == 1 && edge[j][k] == 1)
					cnt2[j] += 1;
		cnt2[i] = 0;
		for (int u = 0; u < n; u++)
			for (int v = 0; v < u; v++)
				if (edge[u][v] == 1) {
					ans += cnt2[u] * cnt2[v];
					if (edge[i][u] == 1 && edge[i][v] == 1) {
						ans -= lens[u] + lens[v] - 3;
						minus += lens[u] + lens[v] + lens[i] - 6;
					}
				}
	}
	cout << (ans - minus / 3) / 5;
}