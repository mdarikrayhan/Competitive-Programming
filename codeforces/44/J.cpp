// LUOGU_RID: 158294006
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

const int N = 1000 + 5;
char mp[N][N];
bool vis[4];
int n, m;

void work(int sx, int tx, int sy, int ty) {
	vis[0] = vis[1] = vis[2] = vis[3] = 0;
	for (int i = sx; i <= tx; i++) 
		if(mp[i][sy - 1] <= 'D' && mp[i][sy - 1] >= 'A') vis[mp[i][sy - 1] - 'A'] = 1;
	for (int i = sy; i <= ty; i++) 
		if(mp[sx - 1][i] <= 'D' && mp[sx - 1][i] >= 'A') vis[mp[sx - 1][i] - 'A'] = 1;
	for (int i = sx; i <= tx; i++) 
		if(mp[i][ty + 1] <= 'D' && mp[i][ty + 1] >= 'A') vis[mp[i][ty + 1] - 'A'] = 1;
	for (int i = sy; i <= ty; i++) 
		if(mp[tx + 1][i] <= 'D' && mp[tx + 1][i] >= 'A') vis[mp[tx + 1][i] - 'A'] = 1;
	char res;
	for (int i = 0; i < 4; i++)
		if(!vis[i]) {
			res = i + 'A';
			break;
		}
	for (int i = sx; i <= tx; i++)
		for (int j = sy; j <= ty; j++) mp[i][j] = res;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	memset(mp, 'e', sizeof(mp));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> mp[i][j];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if(mp[i][j] == 'b') {
				puts("NO");
				return 0;
			}
			if(mp[i][j] != 'w') continue;
			if(m - j >= 2 && mp[i][j] == 'w' && mp[i][j + 1] == 'b' && mp[i][j + 2] == 'w') {
				work(i, i, j, j + 2);
				continue;
			}
			if(n - i >= 2 && mp[i][j] == 'w' && mp[i + 1][j] == 'b' && mp[i + 2][j] == 'w'){
				work(i, i + 2, j, j);
				continue;
			}
			puts("NO");
			return 0;
		}
	puts("YES");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) 
			if(mp[i][j] == '.') cout << mp[i][j];
			else cout << char(mp[i][j] - 'A' + 'a');
		puts("");
	}
	return 0;
}