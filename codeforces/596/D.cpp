#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
double p;
int a[2005];
int v[2][2005][2005][2];
int tl[2005], tr[2005];
double dp[2][2005][2005][2];
int f(int v1, int l, int r, int v2) {
	return min(a[r] - a[l] - m * (v1 + v2), 0ll);
}
double dfs(int v1, int l, int r, int v2) {
    if (l > r) {
		return f(v1, r, l, v2);
    }
	if (v[v1][l][r][v2]) {
		return dp[v1][l][r][v2];
	}
    v[v1][l][r][v2] = 1; 
	double sum = 0;
    int x = min(tr[l], r);
    sum += p * (dfs(0, l + 1, r, v2) + f(v1, l - 1, l, 1) + m);
    sum += (1 - p) * (dfs(1, x + 1, r, v2) + a[x] - a[l] + m);
    int y = max(l, tl[r]);
    sum += (1 - p) * (dfs(v1, l, r - 1, 0) + f(1, r, r + 1, v2) + m);
    sum += p * (dfs(v1, l, y - 1, 1) + a[r] - a[y] + m);
    return dp[v1][l][r][v2] = sum / 2;
    
}
signed main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
    }
	sort(a + 1, a + n + 1);
	a[0] = -1e9;
	a[n + 1] = 1e9;
    for (int i = 1; i <= n; i++) {
		tl[i] = (i > 1 && a[i] - a[i - 1] < m) ? tl[i - 1] : i;
	}
    for (int i = n; i >= 1; i--) {
		tr[i] = (i < n && a[i + 1] - a[i] < m) ? tr[i + 1] : i;
    }
	printf("%.10lf", dfs(0, 1, n, 0));
	return 0;
}
