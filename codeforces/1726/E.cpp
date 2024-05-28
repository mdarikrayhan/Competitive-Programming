// LUOGU_RID: 160389989
#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=3e5+5,M=N-5,mod=998244353;
int T,n,f[N],jc[N],inv[N];
inline int ksm(int x,int p){int s=1;for(;p;(p&1)&&(s=1ll*s*x%mod),x=1ll*x*x%mod,p>>=1);return s;}
inline int C(int n,int m){return n<m?0:1ll*jc[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>T;
	jc[0]=1;for(int i=1;i<=M;i++) jc[i]=1ll*jc[i-1]*i%mod;
	inv[M]=ksm(jc[M],mod-2);for(int i=M-1;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	f[0]=f[1]=1;for(int i=2;i<=M;i++) f[i]=(f[i-1]+1ll*(i-1)*f[i-2])%mod;
	while(T--)
	{
		cin>>n;int ans=0;
		for(int i=0;i<=n/4;i++) ans=(ans+1ll*C(n-2*i,2*i)*C(2*i,i)%mod*jc[i]%mod*f[n-4*i])%mod;
		cout<<ans<<"\n";
	}
	return 0;
}