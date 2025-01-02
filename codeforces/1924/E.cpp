#include <bits/stdc++.h>
#define ll long long
#define N 2000011
using namespace std;
int n,m,nn,deno,t,fac[N],ifac[N],F[N],sF[N],R[N];ll k;const int p=1e9+7;
inline int qpow(int bs,int ex){int ans=1;while(ex){if(ex&1)ans=1ll*ans*bs%p;ex>>=1;bs=1ll*bs*bs%p;}return ans;}
int f(int x,int y)
{
	if(x==n&&y==m)return 1;
	if(y==m)return (qpow((1-1ll*(n-x)*deno)%p,p-2)-qpow((1-1ll*((n-x)-1)*deno)%p,p-2))%p;
	if(x==n)return (qpow((1-1ll*(m-y)*deno)%p,p-2)-qpow((1-1ll*((m-y)-1)*deno)%p,p-2))%p;
	return (0ll+qpow((1-1ll*((n-x)+(m-y))*deno)%p,p-2)-2*qpow((1-1ll*((n-x)+(m-y)-1)*deno)%p,p-2)+qpow((1-1ll*((n-x)+(m-y)-2)*deno)%p,p-2))%p;
}
int main()
{
	fac[0]=1;for(int i=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%p;
	ifac[N-1]=qpow(fac[N-1],p-2);for(int i=N-2;~i;--i)ifac[i]=1ll*ifac[i+1]*(i+1)%p;
	scanf("%d",&t);while(t--)
	{
		scanf("%d%d%lld",&n,&m,&k);--k;
		deno=qpow(n+m-2,p-2);nn=n+m;
		for(int i=2;i<=n+m-2;++i)
		{
			F[i]=(0ll+qpow((1-1ll*(nn-i)*deno)%p,p-2)-2ll*qpow((1-1ll*(nn-i-1)*deno)%p,p-2)+qpow((1-1ll*(nn-i-2)*deno)%p,p-2))%p;
		}
		sF[0]=sF[1]=0;
		for(int i=2;i<=n+m;++i)sF[i]=(sF[i-1]+F[i])%p;
		int ans=0;
		R[m]=0;
		int up=min(k/m,(ll)n)+1;
		for(int j=up;j<=n;++j)R[m]=(0ll+R[m]+f(j,m))%p;
		// for(int i=1;i<=n;++i)
		// {
		// 	for(int j=1;j<=m;++j)printf("%d ",f(i,j));putchar(10);
		// }
		for(int i=m-1;i;--i)
		{
			int up=min(k/i,(ll)n)+1,tup=min(up,n);
			// printf("i:%d up:%d tup:%d\n",i,up,tup);
			// printf("f(%d,%d):%d interval [%d,%d]\n",n,i,f(n,i),i+tup,n-1+i);
			R[i]=(0ll+R[i+1]+sF[n-1+i]-sF[i+tup-1]+(up<=n?f(n,i):0))%p;
		}
		for(int i=1;i<m;++i)ans=(ans+1ll*deno*R[i+1])%p;
		// printf("R:");for(int i=1;i<=m;++i)printf("%d ",R[i]);putchar(10);
		R[n]=0;
		up=min(k/n,(ll)m)+1;
		for(int j=up;j<=m;++j)R[n]=(0ll+R[n]+f(n,j))%p;
		for(int i=n-1;i;--i)
		{
			int up=min(k/i,(ll)m)+1,tup=min(up,m);
			R[i]=(0ll+R[i+1]+sF[m-1+i]-sF[i+tup-1]+(up<=m?f(i,m):0))%p;
		}
		for(int i=1;i<n;++i)ans=(ans+1ll*deno*R[i+1])%p;
		printf("%d\n",(ans%p+p)%p);
	}
	fclose(stdin);fclose(stdout);return 0;
}