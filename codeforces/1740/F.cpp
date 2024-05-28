#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,cnt[2005],sum[2005];
ll dp[2005][2005],sumdp[2005][2005],ans;
const ll mod = 998244353;
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)scanf("%d",&a),sum[++cnt[a]]++;
	n++;
	for(int i = 1;i <= n;i++)sum[i] += sum[i - 1];
	for(int i = 0;i <= sum[1];i++)sumdp[i][i] = dp[i][i] = 1;
	for(int i = 2;i <= n;i++)
	{
		for(int k = 1;k <= sum[i];k++)
			for(int j = 0;j <= k / i;j++)
				if(!j)dp[j][k] = sumdp[(k - j) / (i - 1)][k - j] % mod;
				else dp[j][k] = (mod + sumdp[(k - j) / (i - 1)][k - j] - sumdp[j - 1][k - j]) % mod;
		for(int k = 1;k <= sum[i];k++)
			for(int j = 0;j <= k / i;j++)
				if(!j)sumdp[j][k] = dp[j][k];
				else sumdp[j][k] = (sumdp[j - 1][k] + dp[j][k]) % mod;
	}
	printf("%lld",dp[0][n - 1]);
}
				    		  	 	 			 	 	    			