// LUOGU_RID: 159332070
#include <bits/stdc++.h>
using namespace std;
int edge[300005][5];
int sz[300005];
int v[300005];
void dfs(int x) {
	int cnt = 0;
	for (int i = 1; i <= sz[x]; i++) {
		if (v[edge[x][i]] == v[x]) {
			cnt++;
		}
	}
	if (cnt >= 2) {
		v[x] ^= 1;
		for (int i = 1; i <= sz[x]; i++) {
			if (v[edge[x][i]] == v[x]) {
				dfs(edge[x][i]);
			}
		}
	}
	return;
}
signed main() {
	int n, m; 
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a][++sz[a]] = b;
		edge[b][++sz[b]] = a;
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", v[i]);
	}
	return 0;
}