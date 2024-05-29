// LUOGU_RID: 159846986
#include <bits/stdc++.h>
using namespace std;

const int N = 20, mod = 998244353;
int g[N][N], bit[1 << N], f[1 << N], ok[1 << N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++ ) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = g[b][a] = 1;
	}
	vector<int> v;
	for (int i = 1; i < (1 << n); i ++ ) {
		for (int j = 0; j < n; j ++ )
			if (i >> j & 1)
				bit[i] ++ ;
		ok[i] = 1;
		for (int j = 0; j < n; j ++ )
			if (i >> j & 1)
				for (int k = j + 1; k < n; k ++ )
					if ((i >> k & 1) && g[j + 1][k + 1])
						ok[i] = 0;
	}
	f[0] = 1;
	for (int i = 1; i < (1 << n); i ++ )
		for (int j = i; j; j = (j - 1) & i)
			if (ok[j])
				f[i] = (f[i] + ((bit[j] & 1) ? f[i ^ j] : 1ll * (mod - 1) * f[i ^ j] % mod)) % mod;
	printf("%d\n", 1ll * f[(1 << n) - 1] * m % mod * (mod + 1 >> 1) % mod);
	return 0;
}
