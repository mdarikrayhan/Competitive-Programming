#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 205, M = 3005, mod = 1e9 + 7;
int n, l, cnt, ans, a[N], b[N], c[N], dp[M][N];
signed main(){
	scanf("%lld%lld", &n, &l);
	for(int i = 1; i <= n; i++){
		c[++cnt] = i;
		scanf("%lld%lld", &a[cnt], &b[cnt]);
		if(a[cnt] != b[cnt]){
			c[++cnt] = i;
			a[cnt] = b[cnt - 1];
			b[cnt] = a[cnt - 1];
		}
	}
	for(int i = 1; i <= l; i++){
		for(int j = 1; j <= cnt; j++){
			for(int k = 0; k <= cnt; k++){
				if(c[j] == c[k])	continue;
				if(a[j] == i && !k)	dp[i][j]++;
				else if(a[j] == b[k] && i > a[j])	dp[i][j] = (dp[i][j] + dp[i - a[j]][k]) % mod;
			}
		}
	}
	for(int i = 1; i <= cnt; i++)	ans = (ans + dp[l][i]) % mod;
	printf("%lld", ans);
	return 0;
}