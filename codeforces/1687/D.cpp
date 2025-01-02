// LUOGU_RID: 156908895
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

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

const int N = 2e6 + 50;

int n, m, ans, a[N];
vector<int> G[N];
int pre[N], nxt[N], l[N], r[N];

int sq(int x)
{
	return __builtin_sqrtl(x);
}

int find(int x)
{
	int y = sq(x);
	if(y * y <= x && x <= y * (y + 1)) return y;
	return y + 1;
}

void del(int x)
{
	l[nxt[x]] = l[x];
	pre[nxt[x]] = pre[x];
	nxt[pre[x]] = nxt[x];
}

bool WEI;
signed main()
{
	in(n);
	nxt[0] = 1;
	For(i, 1, n) in(a[i]), l[i] = r[i] = a[i];
	For(i, 1, n) pre[i] = i - 1, nxt[i] = i + 1;
	For(i, 1, n - 1) G[a[i + 1] - a[i]].push_back(i);
	int V = 2e6;
	For(i, 0, V)
	{
		for(int j : G[i]) del(j);
		int L = max(0ll, i * i - l[1]);
		int R = i * (i + 1) - l[1];
		for(int j = nxt[0], x; j <= n; j = nxt[j])
		{
			x = find(l[j] + L);
			L = max(L, x * x - l[j]);
			R = min(R, x * (x + 1) - r[j]);
		}
		if(L <= R) {printf("%lld\n", L); return 0;}
	}
	cerr << (&WEI - &TOU) * 1.0 / 1024 / 1024 << endl;
	return 0;
}