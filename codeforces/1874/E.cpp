// LUOGU_RID: 159209515
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=205,MOD=1e9+7,MAXM=21005;
ll ksm(ll a,ll b=MOD-2,ll p=MOD) {
	ll ret=1;
	for(;b;a=a*a%p,b>>=1) if(b&1) ret=ret*a%p;
	return ret;
}
namespace FastMod {
typedef unsigned long long ull;
typedef __uint128_t uLL;
ull b,m;
inline void init(ull B) { b=B,m=ull((uLL(1)<<64)/B); }
inline ull mod(ull a) {
	ull q=((uLL(m)*a)>>64),r=a-q*b;
	return r>=b?r-b:r;
}
};
#define o(x) FastMod::mod(x)
ll C[MAXN][MAXN],f[MAXN],val[MAXM],p[MAXM],fac[MAXM],ifac[MAXM];
signed main() {
	FastMod::init(MOD);
	int n,k;
	scanf("%d%d",&n,&k);
	int m=n*(n+1)/2+1;
	if(k>=m) return puts("0"),0;
	for(int i=fac[0]=ifac[0]=1;i<=m;++i) ifac[i]=ksm(fac[i]=fac[i-1]*i%MOD);
	for(int i=0;i<=n;++i) for(int j=C[i][0]=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	for(int x=1;x<=m;++x) {
		memset(f,0,sizeof(f)),f[0]=1;
		ll pw=1;
		for(int i=1;i<=n;++i) {
			for(int j=1;j<=i;++j) f[i]=o(f[i]+C[i-1][j-1]*o(f[j-1]*f[i-j]));
			pw=o(pw*x),f[i]=o(f[i]*pw);
		}
		val[x]=f[n];
	}
	p[0]=1;
	for(int i=1;i<=m;++i) {
		for(int j=i;~j;--j) p[j]=o((j?p[j-1]:0)+(MOD-i)*p[j]);
	}
	ll ans=0;
	for(int i=1;i<=m;++i) {
		ll t=0,s=0;
		for(int j=m-1;j>=k;--j) t=o(p[j+1]+t*i),s+=t;
		ll c=o(ifac[i-1]*ifac[m-i]);
		if((m-i)&1) c=MOD-c;
		c=o(c*val[i]),s=o(s),ans=o(ans+c*s);
	}
	printf("%lld\n",ans);
	return 0;
}