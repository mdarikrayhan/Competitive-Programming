// LUOGU_RID: 158461692
// LUOGU_RID: 158447805
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define PII pair<int,int>
#define x first
#define y second
#define For(i, l, r) for(int i = l; i <= r; i ++)
#define Rep(i, l, r) for(int i = l; i >= r; i --)

bool START;

void in(int &x)
{
	char c = getchar(); int op = 1;
	while(c > '9' || c < '0') op *= (c == '-' ? -1 : 1), c = getchar();
	for(x = 0; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + c - '0'; x *= op;
}

const int N = 1e5 + 50, oo = 1e9;

int n, m;
struct node {int l, r, id;}p[N][5];

bool operator < (node a, node b)
{
	if(a.l != b.l) return a.l < b.l;
	if(a.r != b.r) return a.r < b.r;
	return a.id < b.id; 
}

#define Auto set<node>::iterator
set<node> s[N];

bool solve(set<node> *s)
{
	int n = s[0].size();
	if(n <= 1) return 1;
	set<node> t[4];
	Auto it[4];
	int mx[5];
	For(i, 0, 3) it[i] = s[i].begin(), mx[i] = -oo;
	For(i, 1, n - 1)
	{
		For(j, 0, 3) mx[j] = max(mx[j], (it[j] ++) -> r);
		For(j, 0, 3)
		{
			if(mx[j] <= it[j] -> l)
			{
				Auto It = s[j].begin();
				For(k, 1, i)
				{
					int u = (It ++) -> id;
					For(l, 0, 3)
					t[l].insert(p[u][l]), s[l].erase(p[u][l]);
				}
				return solve(s) && solve(t);
			}
		}
	}
	return 0;
}

bool ENDPOS = 0;
int main()
{
	in(n);
	For(i, 1, n)
	{
		int xl, yl, xr, yr;
		in(xl); in(yl); in(xr); in(yr);
		s[0].insert(p[i][0] = {xl, xr, i});
		s[1].insert(p[i][1] = {yl, yr, i});
		s[2].insert(p[i][2] = {-xr, -xl, i});
		s[3].insert(p[i][3] = {-yr, -yl, i});
	}
	puts(solve(s) ? "YES" : "NO");
	return 0;
}