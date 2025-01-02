#include<bits/stdc++.h>
using namespace std;
int const M=1000100,mod=(1e9)+7; 
int i,n,v,x,ans,a[M],fac[M],tr[M];
void add(int x){for (;x<=n;x+=x&-x) tr[x]++;}
int sum(int x){int s=0;for (;x;x-=x&-x) s+=tr[x];return s;}
main() {
	scanf("%d",&n);
	for (fac[0]=i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	for (i=1;i<=n;i++) a[i]=(1ll*a[i-1]*i%mod+1ll*i*(i-1)/2%mod*fac[i-1]%mod)%mod;
	for (i=1;i<=n;v=(v+x)%mod,i++){
		scanf("%d",&x);add(x);x-=sum(x);
		ans=(ans+1ll*a[n-i]*x%mod)%mod;
		ans=(ans+1ll*fac[n-i]*x%mod*v%mod)%mod;
		ans=(ans+1ll*x*(x-1)/2%mod*fac[n-i]%mod)%mod;
	}
	printf("%d\n",(ans+v)%mod);
	return 0;
}