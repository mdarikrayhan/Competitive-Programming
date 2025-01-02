#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k, t, tag, a[N], b[N];
vector<int> g[N];

void dfs(int x, int p) {
	if (a[x]) {
		tag = x;
		return;
	}
	for (int i = 0; i < g[x].size(); i++)
		if (g[x][i] != p) dfs(g[x][i], x);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; i++) g[i].clear();
		scanf("%d", &n);
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d", &t);
			a[t] = 1;
		}
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			scanf("%d", &t);
			b[t] = 1;
		}
		printf("B %d\n", t);
		fflush(stdout);
		scanf("%d", &tag);
		dfs(tag, 0);
		printf("A %d\n", tag);
		fflush(stdout);
		scanf("%d", &t);
		if (b[t])
			printf("C %d\n", tag);
		else
			puts("C -1");
		fflush(stdout);
	}
	return 0;
}