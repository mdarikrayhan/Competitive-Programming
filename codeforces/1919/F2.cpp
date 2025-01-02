#include <cstdio>
#include <algorithm>
#define N 500005
using namespace std;

int n, q, a[N], b[N];
long long c[N];

long long read ()
{
	long long x = 0; char c = getchar ();
	for (; c < '0' || c > '9'; c = getchar ());
	for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar ());
	return x;
}

void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar ('0' + x % 10);
	return ;
}

namespace segment_tree
{
	struct dat
	{
		long long res, rest, incw, incf;
		void modify (int x, int y, long long z)
		{
			res = min (x, y), rest = min (x - res, z);
			incw = y - res, incf = z - rest;
			return ;
		}
		friend dat operator + (dat x, dat y)
		{
			long long Incw = min (x.rest, y.incw);
			long long Incf = min (max (x.rest - y.incw, 0ll), y.incf);
			long long Restw = min (y.incw - Incw, x.incf);
			dat z; z.res = x.res + y.res + Incw, z.rest = Incf + y.rest;
			z.incw = x.incw + Restw;
			z.incf = min (x.incf - Restw, y.incf - Incf);
			return z;
		}
	};
	
	struct st
	{
		int l, r; dat c;
		#define l(p) tr[p].l
		#define r(p) tr[p].r
		#define c(p) tr[p].c
	} tr[N * 4];
	
	void build (int p, int l, int r)
	{
		l (p) = l, r (p) = r, c (p).modify (a[l], b[l], c[l]);
		if (l == r) return ;
		int mid = l + r >> 1;
		build (p * 2, l, mid), build (p * 2 + 1, mid + 1, r);
		c (p) = c (p * 2) + c (p * 2 + 1);
		return ;
	}
	
	void change (int p, int x)
	{
		if (l (p) == r (p)) {c (p).modify (a[x], b[x], c[x]); return ;}
		change (p * 2 + (x > r (p * 2)), x);
		c (p) = c (p * 2) + c (p * 2 + 1);
		return ;
	}
	
	long long ask () {return c (1).res;}
}
using namespace segment_tree;

int main ()
{
	scanf ("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++) a[i] = read ();
	for (int i = 1; i <= n; i ++) b[i] = read ();
	for (int i = 1; i < n; i ++) c[i] = read ();
	build (1, 1, n);
	for (int i = 1, x; i <= q; i ++)
	{
		x = read (), a[x] = read (), b[x] = read (), c[x] = read ();
		change (1, x), write (ask ()), putchar ('\n');
	}
	return 0;
}
		 	  	  				 			 		   	  	 	 	