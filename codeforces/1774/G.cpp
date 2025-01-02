// LUOGU_RID: 160565707
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

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

int n, m, fa[N][20];
PII p[N];
int a[N], b[N], nxt[N], Q;

bool WEI;
int main()
{
	in(n); in(Q);
	For(i, 1, n) in(p[i].x), in(p[i].y), p[i].y = -p[i].y;
	sort(p + 1, p + n + 1);
	For(i, 1, n) p[i].y *= (-1);
	m = 1;
	For(i, 2, n)
	{
		while(m && p[m].y >= p[i].y) m --;
		p[++ m] = p[i];
	}
	// printf("m = %d\n", m); For(i, 1, m) printf("(%d, %d)\n", p[i].x, p[i].y);
	n = m;
	For(i, 1, n) a[i] = p[i].x, b[i] = p[i].y;
	For(i, 1, n)
	{
		int j = upper_bound(a + 1, a + n + 1, b[i]) - a;
		nxt[i] = j; fa[i][0] = j;
	}
	b[n + 1] = 1e9 + 40;
	fa[n + 1][0] = n + 1;
	For(i, 1, 19) For(u, 1, n + 1) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	while(Q --)
	{
		int l, r; in(l); in(r);
		int u = lower_bound(a + 1, a + n + 1, l) - a;
		if(a[u] != l) {puts("0"); continue;}
		if(b[u] == r) {puts("998244352"); continue;}
		if(b[u] > r) {puts("0"); continue;}
		// cerr << "G1" << endl;
		int v = u + 1;
		if(a[v] > b[u]) {puts("0"); continue;}
		if(b[v] > r) {puts("0"); continue;}
		// cerr << "G2" << endl;
		Rep(i, 19, 0)
		{
			if(b[fa[u][i]] <= r) u = fa[u][i];
			if(b[fa[v][i]] <= r) v = fa[v][i];
		}
		if(max(b[u], b[v]) != r) {puts("0"); continue;}
		if(u == v) {puts("0"); continue;}
		if(b[u] == r) {puts("998244352"); continue;}
		puts("1");
	}
	return 0;
}