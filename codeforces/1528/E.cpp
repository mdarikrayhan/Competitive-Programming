#include <bits/stdc++.h>

#define N 1000005
#define mod 998244353

typedef long long ll;

using namespace std;

ll f[N],sf[N],inv[N];

int main()
{
	int i,n;
	ll ans=0;
	inv[1]=1;for(i=2;i<N;++i)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	scanf("%d",&n);f[0]=sf[0]=1;
	for(i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		if(i>=2)(f[i]+=f[i-1]*sf[i-2])%=mod;
		(f[i]+=f[i-1]*(f[i-1]+1)/2)%=mod;
		sf[i]=(sf[i-1]+f[i])%mod;
	}

	for(i=1;i<n;++i)(ans+=(f[i]-f[i-1])*f[n-1])%=mod;
	if(n>=2)(ans+=f[n-1]*(f[n-1]+1)/2%mod*sf[n-2])%=mod;
	(ans+=f[n-1]*(f[n-1]-1)%mod*(f[n-1]-2)%mod*inv[6]+f[n-1]*(f[n-1]-1)+f[n-1])%=mod;
	ans=ans*2%mod;

	(ans+=f[n]+f[n]-f[n-1])%=mod;
	for(i=1;i<n;++i)(ans+=(f[n-i]-f[n-i-1])*f[i-1])%=mod;

	printf("%lld\n",(ans+mod)%mod);
	return 0;
}
