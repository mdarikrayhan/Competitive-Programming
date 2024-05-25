#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,mod=1e9+7;
int n,m,q;
int f[N][N],cnt[N];
int a[N];
int ans;
int ksm(int base,int zhi){
	int res=1;
	while(zhi){
		if(zhi&1) res = (res*base)%mod;
		base = (base*base)%mod;
		zhi>>=1;
	}
	return res;
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		f[i][0] = 1;
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			f[i][j] = (f[i-1][j-1]+f[i+1][j-1])%mod;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			cnt[i] += f[i][j] * f[i][m-j] %mod;
			cnt[i] %= mod;
		}
		ans += cnt[i]*a[i]%mod;
		ans %= mod;
	}
	while(q--){
		int p,x;
		scanf("%lld%lld",&p,&x);
		ans += cnt[p]*((x-a[p]+mod)%mod)%mod;
		ans %= mod;
		printf("%lld\n",ans);
		a[p] = x;
	}
	return 0;
}