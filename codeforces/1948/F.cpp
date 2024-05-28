// LUOGU_RID: 160498528
#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	register int x = 0, f = 1;
	register char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c <= '9' && c >= '0')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

inline void write(int x)
{
	if(!x)return;
	write(x / 10);
	putchar(x % 10 + '0');
	return;
}

const int mod = 998244353;

int n, q;

int a[3000010], b[3000010], c, suma[3000010], sum[3000010], sumc[3000010], f[3000010], g[3000010], cc[3000010];

int inv(int x)
{
	int ans = 1, res = x, b = mod - 2;
	while(b)
	{
		if(b & 1)
		{
			ans *= res;
			ans %= mod;
		}
		res *= res;
		res %= mod;
		b /= 2;
	}
	return ans;
}

int ksm(int a, int b)
{
	int ans = 1, res = a;
	while(b)
	{
		if(b & 1)
		{
			ans *= res;
			ans %= mod;
		}
		res *= res;
		res %= mod;
		b /= 2;
	}
	return ans;
}

void C()
{
	f[0] = 1;
	f[1] = 1;
	for(int i = 2;i <= c;i++)
	{
		f[i] = f[i - 1] * i;
		f[i] %= mod;
	}
	g[0] = 1;
	g[1] = 1;
	for(int i = 2;i <= c;i++)
	{
		g[i] = g[i - 1] * inv(i);
		g[i] %= mod;
	}
	cc[0] = 1;
	sumc[0] = 1;
	for(int i = 1;i <= c;i++)//求Cic 
	{
		cc[i] = ((f[c] * g[c - i]) % mod) * g[i];
		cc[i] %= mod;
		sumc[i] = sumc[i - 1] + cc[i];
		sumc[i] %= mod;
//		cout << sumc[i] <<" ";
	}
//	cout << "\n";
	return;
}

signed main()
{
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		sum[i] %= mod;
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> b[i];
		c += b[i];
		c %= mod;
		suma[i] = suma[i - 1] + b[i];
		suma[i] %= mod;
//		cout << suma[i] << " ";
	}
//	cout << "\n";
	C();
//	for(int i = 1;i <= n;i++)
//	{
//		cout << sum[i] << " ";
//	}
//	cout << "\n";
//	for(int i = 1;i <= n;i++)
//	{
//		cout << suma[i] << " ";
//	}
//	cout << "\n";
//	for(int i = 1;i <= c;i++)
//	{
//		cout << cc[i] << " ";
//	}
//	cout << "\n";
//	for(int i = 1;i <= c;i++)
//	{
//		cout << sumc[i] << " ";
//	}
//	cout << "\n";
//	cout << ksm(2, c) << " " << inv(ksm(2, c)) << "\n";
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		if(sum[r] - sum[l - 1] + suma[r] - suma[l - 1] <= (sum[n] - sum[r] + sum[l - 1]))
		{
			cout << 0 << " ";
			continue;
		}
		cout << (inv(ksm(2, c)) * (sumc[c] - sumc[sum[n] - 2 * (sum[r] - sum[l - 1]) + (suma[n] - (suma[r] - suma[l - 1]))] + mod)) % mod << " ";
	}
	return 0;
}
