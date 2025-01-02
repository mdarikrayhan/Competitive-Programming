// LUOGU_RID: 157361744
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

#define int long long
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

const int N = 2e5 + 50, P = 998244353;

int n, m, ad[N << 2], t[N << 2], mu[N << 2], Len[N << 2];

#define ls (u << 1)
#define rs (u << 1 | 1)

void up(int u) {t[u] = (t[ls] + t[rs]) % P;}

void Add(int u, int x, int y) // *x + y
{
	t[u] = (t[u] * x + y * Len[u]) % P;
	ad[u] = (ad[u] * x + y) % P; mu[u] = mu[u] * x % P;
}

void down(int u)
{
	Add(ls, mu[u], ad[u]); Add(rs, mu[u], ad[u]); mu[u] = 1; ad[u] = 0;
}

void build(int u, int l, int r)
{
	ad[u] = 0; mu[u] = 1; Len[u] = r - l + 1;
	if(l == r) return ;
	int mid = (l + r) >> 1; build(ls, l, mid); build(rs, mid + 1, r);
}

void modify(int u, int l, int r, int x, int y, int z, int w)
{
	if(x <= l && r <= y) {Add(u, z, w); return ;}
	int mid = (l + r) >> 1; down(u);
	if(x <= mid) modify(ls, l, mid, x, y, z, w);
	if(y > mid) modify(rs, mid + 1, r, x, y, z, w);
	up(u);
}

int query(int u, int l, int r, int x, int y)
{
	if(x <= l && r <= y) return t[u];
	int mid = (l + r) >> 1, s = 0; down(u);
	if(x <= mid) s = (s + query(ls, l, mid, x, y)) % P;
	if(y > mid) s = (s + query(rs, mid + 1, r, x, y)) % P;
	return s;
}

struct node{int l, r, v; } ;
bool operator < (node a, node b) {return a.l < b.l;}

set<node> s[N];
#define Auto set<node>::iterator

Auto split(int c, int x)
{
	Auto it = s[c].lower_bound({x, 0, 0});
	if(it != s[c].end() && it->l == x) return it;
	it --; int l = it->l, r = it->r, v = it->v;
	s[c].erase(it); s[c].insert((node){l, x - 1, v});
	return s[c].insert((node){x, r, v}).first;
}

void assign(int c, int l, int r)
{
	Auto itr = split(c, r + 1);
	Auto itl = split(c, l);
	for(Auto it = itl; it != itr; it ++)
	{
		if(!(it -> v)) modify(1, 1, n, it -> l, it -> r, 1, 1);
		else modify(1, 1, n, it -> l, it -> r, 2, 0);
	}
	s[c].erase(itl, itr);
	s[c].insert({l, r, 1});
}

bool WEI;
signed main()
{
	in(n); in(m);
	build(1, 1, n);
	For(i, 1, n) s[i].insert({1, n + 1, 0});
	while(m --)
	{
		int op, l, r, x; in(op); in(l); in(r);
		if(op == 1)
		{
			in(x); assign(x, l, r);
		}
		else printf("%lld\n", query(1, 1, n, l, r));
	}
	cerr << (&WEI - &TOU) * 1.0 / 1024 / 1024 << endl;
	return 0;
}