#include <cstdio>
#include <algorithm>
#include <queue>
#define N 200005
#define LGN 20
#define ceil(x,y) (((x)+(y)-1)/y)
#define mod(x,y) (((x)%(y)+(y))%(y))
#define cmp(rule) [](int x,int y){return rule;}
using namespace std;

int n, q, k, m, v[N], s[N], u[N], col[N];
int tot, head[N], nxt[N * 2], ver[N * 2];

struct virus
{
	int x, c, round, rest;
	virus (int p, int u, int v, int w) {x = p, c = u, round = v, rest = w;}
	friend bool operator < (virus a, virus b)
	{
		return a.round != b.round ? a.round > b.round : a.c > b.c;
	}
};

priority_queue <virus> Q;

void read (int &x)
{
	char c = getchar ();
	for (x = 0; c < '0' || c > '9'; c = getchar ());
	for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar ());
	return ;
}

void insert (int x, int y)
{
	ver[++ tot] = y, nxt[tot] = head[x], head[x] = tot;
	return ;
}

namespace virtual_tree
{
	int num, dfn[N], dep[N], lgd[N], anc[N][LGN];
	int tv, hv[N], nv[N * 2], vv[N * 2], ev[N * 2];
	int cnt, a[N * 2];
	
	void insertv (int x, int y, int z)
	{
		vv[++ tv] = y, ev[tv] = z;
		nv[tv] = hv[x], hv[x] = tv;
		return ;
	}
	
	void dfs (int x, int fa)
	{
		dfn[x] = ++ num, anc[x][0] = fa;
		for (int &i = lgd[x] = 0; anc[x][i + 1] = anc[anc[x][i]][i]; i ++);
		for (int i = head[x], y; i; i = nxt[i])
		{
			if ((y = ver[i]) == fa) continue;
			dep[y] = dep[x] + 1, dfs (y, x);
		}
		return ;
	}
	
	int lca (int x, int y)
	{
		if (dep[x] < dep[y]) swap (x, y);
		for (int i = lgd[x]; ~i; i --)
		{
			if (dep[x] - (1 << i) >= dep[y]) x = anc[x][i];
		}
		if (x == y) return x;
		for (int i = lgd[x]; ~i; i --)
		{
			if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
		}
		return anc[x][0];
	}
	
	void build ()
	{
		for (int i = 1; i <= k; i ++) a[++ cnt] = v[i];
		for (int i = 1; i <= m; i ++) a[++ cnt] = u[i];
		sort (a + 1, a + cnt + 1, cmp (dfn[x] < dfn[y]));
		cnt = unique (a + 1, a + cnt + 1) - a - 1;
		for (int i = 1, t = cnt; i < t; i ++)
		{
			a[++ cnt] = lca (a[i], a[i + 1]);
		}
		sort (a + 1, a + cnt + 1, cmp (dfn[x] < dfn[y]));
		cnt = unique (a + 1, a + cnt + 1) - a - 1;
		for (int i = 2; i <= cnt; i ++)
		{
			int Lca = lca (a[i - 1], a[i]), dis = dep[a[i]] - dep[Lca];
			insertv (Lca, a[i], dis), insertv (a[i], Lca, dis);
		}
		return ;
	}
	
	void clear ()
	{
		for (int i = 1; i <= cnt; i ++) hv[a[i]] = col[a[i]] = 0;
		tv = cnt = 0;
		return ;
	}
}
using namespace virtual_tree;

void heap_dijkstra ()
{
	for (int i = 1; i <= k; i ++)
	{
		Q.push (virus (v[i], i, 0, 0));
	}
	while (!Q.empty ())
	{
		virus x = Q.top (); Q.pop ();
		if (col[x.x]) continue;
		col[x.x] = x.c;
		for (int i = hv[x.x]; i; i = nv[i])
		{
			int y = vv[i], z = ev[i], now = x.rest - z;
			if (col[y]) continue;
			int nround = ceil (-now, s[x.c]), nrest = mod (now, s[x.c]);
			Q.push (virus (y, x.c, x.round + nround, nrest));
		}
	}
	return ;
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1, x, y; i < n; i ++)
	{
		read (x), read (y);
		insert (x, y), insert (y, x);
	}
	dfs (1, 0), scanf ("%d", &q);
	for (int i = 1; i <= q; i ++)
	{
		read (k), read (m);
		for (int i = 1; i <= k; i ++)
		{
			read (v[i]), read (s[i]);
		}
		for (int i = 1; i <= m; i ++)
		{
			read (u[i]);
		}
		build (), heap_dijkstra ();
		for (int i = 1; i <= m; i ++)
		{
			printf ("%d ", col[u[i]]);
		}
		puts (""), clear ();
	}
	return 0;
}
  		    	  		   	 			   	  		 	