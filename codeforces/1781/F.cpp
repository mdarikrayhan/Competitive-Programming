#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll p,dp[505][505],g[505][505],ans,f[505] = {1},inv[10005] = {1,1},invf[505] = {1};
const ll mod = 998244353;
inline ll C(ll n,ll m)
{
	if(n < 0||m < 0||n < m)return 0;
	return f[n] * invf[m] % mod * invf[n - m] % mod;
}
int main()
{
	for(int i = 2;i <= 10000;i = -~i)
		inv[i] = inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 1;i <= 505;i = -~i)
		f[i] = f[i - 1] * i % mod,
		invf[i] = invf[i - 1] * inv[i] % mod;
	scanf("%d %lld",&n,&p);
	(p *= inv[10000]) %= mod;
	for(int i = 0;i <= n;i = -~i)dp[0][i] = g[0][i] = 1;
	for(int i = 1;i <= n;i = -~i)
	{
		for(int k = 0;k < i;k = -~k)
			(dp[i][0] += p * dp[k][1] % mod * C(i - 1,k) % mod * g[i - 1 - k][0]) %= mod;
		for(int j = 1;j <= n;j = -~j)
			for(int k = 0;k < i;k = -~k)
				(dp[i][j] += (p * dp[k][j + 1] + (998244354 - p) * dp[k][j - 1]) % mod * C(i - 1,k) % mod * g[i - 1 - k][j]) %= mod;
		for(int j = 0;j <= n;j = -~j)
			for(int k = 0;k <= i;k = -~k)
				(g[i][j] += C(i,k) * dp[k][j] % mod * dp[i - k][j]) %= mod;
	}
	ans = dp[n][0];
	for(int i = 1;i <= 2 * n;i += 2)(ans *= inv[i]) %= mod;
	printf("%lld",ans);
}
 	 	 		  		  			 		 			 				 	