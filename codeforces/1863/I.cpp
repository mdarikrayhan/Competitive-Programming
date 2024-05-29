#include<iostream>
#include<set>
#include<vector>
#include <algorithm>
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
using namespace std;
const int N = 3e3 + 100;
int nn, tot;
vector<int>G[N], g[N * N];
int fa[N * N], siz[N * N];
int num[N][N], FA[N][N];
void dfs(int x, int c)
{
	num[c][x] = ++tot;
	for (auto y : G[x])if (!num[c][y])dfs(y, c); else FA[c][x] = y;
}
int calc(int x)
{
	int res = 0; for (auto y : g[x])res += calc(y);
	return max(res, siz[x]);
}
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
int merge(int x, int y) { if ((x = get(x)) != (y = get(y)))return fa[x] = y, siz[y] += siz[x], 1; return 0; }
signed main()
{
	scanf("%d", &nn);
	for (int i = 1; i <= nn * nn; i++)fa[i] = i, siz[i] = 1;
	for (int i = 1, x, y; i < nn; i++)scanf("%d%d", &x, &y), G[x].push_back(y), G[y].push_back(x);
	for (int i = 1; i <= nn; i++)dfs(i, i), FA[i][i] = i;
	for (int i = 1; i <= nn; i++)for (int j = i + 1; j <= nn; j++)merge(num[i][j], num[j][i]);
	for (int i = 1; i <= nn; i++)for (int j = i + 1; j <= nn; j++)
		if (FA[i][j] != i)merge(num[i][FA[i][j]], num[j][FA[j][i]]);
	int p = get(num[1][G[1][0]]);
	vector<pii>vt;
	for (int i = 1; i <= nn; i++)for (int j = i + 1; j <= nn; j++)
		if (FA[i][j] != i)vt.push_back(mk(get(num[i][FA[i][j]]), get(num[i][j])));
	sort(vt.begin(), vt.end()); vt.erase(unique(vt.begin(), vt.end()), vt.end());
	for (auto t : vt)g[t.fi].push_back(t.se);
	printf("%d\n", calc(p) / 2);
	return 0;
}
 	 		  	       		  	 	     	 		