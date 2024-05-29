// LUOGU_RID: 156990707
#include<bits/stdc++.h>
#define fi first
#define se second
#define MP std::make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef std::pair<int, int> pii;
typedef std::pair<LL, LL> pll;
typedef long double Real;
#define clr(f, n) memset(f, 0, (n) << 2)
#define cpy(f, g, n) memcpy(f, g, (n) << 2)
LL read()
{
	LL s = 0; int f = 1;
	char c = getchar();
	while (!(c >= '0' && c <= '9'))
		f ^= (c == '-'), c = getchar();
	while (c >= '0' && c <= '9')
		s = s * 10 + (c ^ 48), c = getchar();
	return f ? s : -s;
}
char readc()
{
	char c = getchar();
	while (!(c == '(' || c == ')' || c == '*' || c == 'P' || c == 'S')) c = getchar();
	return c;
}
template<typename T>
T& Fmin(T& x, T y){ return x = x < y ? x : y; }
template<typename T>
T& Fmax(T& x, T y){ return x = x < y ? y : x; }
const int MAXN = 160005,  INF = 0x3f3f3f3f;
int n, K, st[MAXN], tp, type[MAXN], cP, m, id[MAXN];
bool para[MAXN];
std::vector<int> e[MAXN];
int coef[MAXN];
void dfs(int x)
{
	if (type[x] == -1) coef[x] = 1;
	else if (type[x] == 1)
	{
		coef[x] = 0;
		for (int y : e[x])
			dfs(y), coef[x] += coef[y];
	}
	else 
	{
		coef[x] = INF;
		for (int y : e[x])
			dfs(y), Fmin(coef[x], coef[y]);
	}
}
void asgn(int x)
{
	if (type[x] == -1) para[id[x]] = true, ++cP;
	else if (type[x] == 1)
		for (int y : e[x]) asgn(y);
	else for (int y : e[x]) if (coef[y] == coef[x]) { asgn(y); break; }
}
void mian()
{
	K = read(), n = m = 0;
	char c = getchar();
	if (c == '*') return printf("REVOLTING %d\n", K), void();
	st[tp = 1] = ++n;
	while (tp) 
	{
		c = readc();
		switch (c)
		{
			case '(': st[++tp] = ++n, e[st[tp - 1]].push_back(n); break;
			case ')': tp--; break;
			case '*': type[++n] = -1, e[st[tp]].push_back(n), id[n] = ++m; break;
			case 'P': type[st[tp]] = 1; break;
			case 'S': type[st[tp]] = 0; break;
		}
	}
	dfs(1);
	cP = 0, memset(para + 1, false, m);
	asgn(1);
	printf("REVOLTING ");
	for (int i = 1; i <= m; i++)
		printf("%lld%c", para[i] ? (LL)cP * K : 0, " \n"[i == m]);
	for (int i = 1; i <= n; i++) e[i].clear();
}
int main()
{
    for (int T = read(); T--; ) mian();
	return 0;
}