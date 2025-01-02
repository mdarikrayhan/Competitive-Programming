// LUOGU_RID: 156980433
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1 << 18 | 5, P = 998244353, G = 3;

namespace Poly{
	inline LL ksm(LL a, LL n)
	{
		LL res = 1;
		while(n)
		{
			if(n & 1) res = res * a % P;
			a = a * a % P;
			n >>= 1;
		}
		return res;
	}
	inline void NTT(LL a[], int n, int ty)
	{
		for(int i = 0, j = 0; i < n; i ++ )
		{
			if(i < j) a[i] ^= a[j] ^= a[i] ^= a[j];
			for(int k = (n >> 1); (j ^= k) < k; k >>= 1) ;
		}
		static LL w[N];
		w[0] = 1;
		for(int i = 1; i < n; i <<= 1)
		{
			LL wi = ksm(G, P - 1 + ty * (P - 1) / (i << 1));
			for(int j = i - 2; j >= 0; j -= 2)
			{
				w[j] = w[j >> 1];
				w[j | 1] = w[j] * wi % P;
			}
			for(int j = 0; j < n; j += (i << 1))
			{
				for(int k = j; k < j + i; k ++ )
				{
					LL t0 = a[k], t1 = a[k + i] * w[k - j] % P;
					(a[k] = t0 + t1) >= P && (a[k] -= P), (a[k + i] = t0 - t1 + P) >= P && (a[k + i] -= P);
				}
			}
		}
		if(ty == -1)
		{
			LL inv = ksm(n, P - 2);
			for(int i = 0; i < n; i ++ ) a[i] = a[i] * inv % P;
		}
	}
	inline void Mul(LL f[], LL g[], LL h[], int n, int m)
	{
		static LL a[N], b[N];
		int k = 0;
		while((1 << k) < n + m) k ++ ;
		for(int i = 0; i < 1 << k; i ++ ) a[i] = b[i] = 0;
		for(int i = 0; i < n; i ++ ) a[i] = f[i];
		for(int i = 0; i < m; i ++ ) b[i] = g[i];
		NTT(a, 1 << k, 1), NTT(b, 1 << k, 1);
		for(int i = 0; i < (1 << k); i ++ ) h[i] = a[i] * b[i] % P;
		NTT(h, 1 << k, -1);
	}
}
using namespace Poly;

int n, m, deg[N], p[N];
LL buf[N << 6], *tt = buf;
LL fact[N];

inline LL* Solve(int l, int r)
{
	if(l == r)
	{
		LL *g = tt;
		tt += 2;
		g[0] = 1, g[1] = p[l];
		return g;
	}
	int mid = l + r >> 1;
	LL *L = Solve(l, mid), *R = Solve(mid + 1, r);
	LL *g = tt;
	tt += r - l + 2;
	Mul(L, R, g, mid - l + 2, r - mid + 1);
	return g;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i ++ )
	{
		int a, b;
		scanf("%d%d", &a, &b);
		deg[a] ++ , deg[b] ++ ;
	}
	for(int i = 1; i <= n; i ++ )
	{
		deg[i] -= (i > 1);
		if(deg[i]) p[m ++ ] = P - deg[i];
	}
	LL *g = Solve(0, m - 1);
	LL res = 0;
	fact[0] = 1;
	for(int i = 1; i <= n; i ++ ) fact[i] = fact[i - 1] * i % P;
	for(int i = 0; i <= n; i ++ ) res = (res + g[i] * fact[n - i]) % P;
	printf("%lld\n", res);
	return 0;
}