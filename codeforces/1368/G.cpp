// LUOGU_RID: 160480233
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
#define PII pair<int, int>
#define x first
#define y second
#define For(i, l, r) for(int i = l; i <= r; i ++)
#define Rep(i, l, r) for(int i = l; i >= r; i --)

bool TOU;

void in(int &x)
{
	char c = getchar(); int op = 1;
	while(c > '9' || c < '0') op *= (c == '-' ? -1 : 1), c = getchar();
	for(x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0'; x *= op;
}

const int N = 4e5 + 50;

int n, m;
int id(int i, int j) { if(i > n || j > m || i < 1 || j < 1) return 0;
	return (i - 1) * m + j;}
int dfn[N], sz[N], Fa[N], deg[N];
char s[N], cp[N];
vector<int> G[N];

void add(int u, int v)
{
	G[u].push_back(v); deg[v] ++;
}

namespace seg
{
	#define ls (u << 1)
	#define rs (u << 1 | 1)
	int t[N << 2], tag[N << 2], Len[N << 2];
	void up(int u)
	{
		if(tag[u]) t[u] = Len[u]; else t[u] = t[ls] + t[rs];
	}
	void build(int u, int l, int r)
	{
		Len[u] = r - l + 1;
		if(l == r) return ; int mid = (l + r) >> 1;
		build(ls, l, mid); build(rs, mid + 1, r);
	}
	void modify(int u, int l, int r, int x, int y, int w)
	{
		if(x <= l && r <= y)
		{
			tag[u] += w; up(u); return ;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) modify(ls, l, mid, x, y, w);
		if(y > mid) modify(rs, mid + 1, r, x, y, w);
		up(u);
	}
}

int DPS;

void Dfs(int u, int pa)
{
	sz[u] = 1; dfn[u] = ++ DPS;
	// printf("u = %d\n", u);
	for(int v : G[u])
	{
		Fa[v] = u;
		Dfs(v, u); sz[u] += sz[v];
	}
}

struct Rec {int x, y, w; } ;
vector<Rec> g[N];

void add_rec(int xl, int xr, int yl, int yr)
{
	if(xl > yl) swap(xl, yl), swap(xr, yr);
	g[xl].push_back({yl, yr, 1});
	g[xr + 1].push_back({yl, yr, -1});
}

bool WEI;
int main()
{
	in(n); in(m);
	int num = 0;
	For(i, 1, n)
	{
		scanf("%s", cp + 1);
		For(j, 1, m) s[++ num] = cp[j];
	}
	For(i, 1, n) For(j, 1, m)
	{
		int u = id(i, j);
		if(s[id(i, j + 1)] == 'L' && s[id(i, j + 2)] == 'R') add(u, id(i, j + 2));
		if(s[id(i, j - 1)] == 'R' && s[id(i, j - 2)] == 'L') add(u, id(i, j - 2));
		if(s[id(i + 1, j)] == 'U' && s[id(i + 2, j)] == 'D') add(u, id(i + 2, j));
		if(s[id(i - 1, j)] == 'D' && s[id(i - 2, j)] == 'U') add(u, id(i - 2, j));
	}
	For(i, 1, n * m) if(!deg[i]) Dfs(i, 0);
	For(i, 1, n * m)
	{
		if(s[i] == 'L' && s[i + 1] == 'R')
		{
			add_rec(dfn[i], dfn[i] + sz[i] - 1 , dfn[i + 1], dfn[i + 1] + sz[i + 1] - 1);
		}
		if(s[i] == 'U' && s[i + m] == 'D')
		{
			add_rec(dfn[i], dfn[i] + sz[i] - 1 , dfn[i + m], dfn[i + m] + sz[i + m] - 1);
		}
	}
	seg::build(1, 1, n * m);
	LL ans = 0;
	For(i, 1, n * m)
	{
		sort(g[i].begin(), g[i].end(), [](Rec a, Rec b) {return a.w > b.w;});
		for(Rec E : g[i])
		{
			seg::modify(1, 1, n * m, E.x, E.y, E.w);
		}
		ans += seg::t[1];
	}
	printf("%lld\n", ans);
	return 0;
}