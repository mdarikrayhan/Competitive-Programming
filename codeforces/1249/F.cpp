// LUOGU_RID: 160212303
#include <bits/stdc++.h>

using namespace std;
const int N = 201;
int n, k, a[N], f[N][N], tmp[N];
vector<int> graph[N];

void dfs(int u, int fa) {
    f[u][0] = a[u];
    for(int v: graph[u]) {
        if(v == fa) continue;
        dfs(v, u);
        for(int j = 0; j <= n; j++) {
			tmp[j] = f[u][j];
        }
		for(int d1 = 0; d1 <= n; d1++) {
			for(int d2 = max(0, k - d1); d2 <= n; d2++) {
				tmp[min(d1, d2 + 1)] = max(tmp[min(d1, d2 + 1)], f[u][d1] + f[v][d2]);
			}
		}
		for(int j = 0; j <= n; j++) {
			f[u][j] = tmp[j];
		}
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        graph[i].clear();
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = max(ans, f[1][i]);
    }
    printf("%d\n", ans);
    return 0;
}