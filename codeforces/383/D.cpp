#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e4,mod=1e9+7;
int n;
int a[N];
int f[N][M*2],g[N][M*2+5];
int ans;
int ksm(int base,int zhi){
	int res=1;
	while(zhi){
		if(zhi&1) res = (1ll*res*base)%mod;
		base = (1ll*base*base)%mod;
		zhi>>=1;
	}return res;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i-1][M]++;
		for(int j=-M;j<=M;j++){
			if(j+a[i]<=M) f[i][j+a[i]+M] = (f[i][j+a[i]+M]+f[i-1][j+M])%mod;
			if(j-a[i]>=-M) f[i][j-a[i]+M] = (f[i][j-a[i]+M]+f[i-1][j+M])%mod;
		}
		ans = (ans+f[i][M])%mod;
	}
	printf("%d\n",ans);
	return 0;
}