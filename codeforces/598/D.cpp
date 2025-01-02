// LUOGU_RID: 159220615
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define quickio ios::sync_with_stdio(false);
#define quickin cin.tie(nullptr);
#define quickout cout.tie(nullptr);
#define maxn 1005
using namespace std;
int ans[maxn * maxn], pos[maxn][maxn];
int n, m, k, tx, ty, num; char c[maxn][maxn];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
void dfs(int x, int y) {
	pos[x][y] = num;
	for(int i = 0; i < 4; i++) {
		int ex = x + dx[i], ey = y + dy[i];
		if(!ex || !ey || ex > n || ey > m) continue ;
		if(pos[ex][ey]) continue ;
		if(c[ex][ey] == '*') ans[num]++;
		else dfs(ex, ey);
	}
}
signed main() {
	quickio
	quickin
	quickout
    cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
	while(k--) {
		cin >> tx >> ty, num++;
		if(!pos[tx][ty]) dfs(tx, ty);
		cout << ans[pos[tx][ty]] << endl;
	}
	return 0;
}