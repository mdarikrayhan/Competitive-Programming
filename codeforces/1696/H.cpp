#include <bits/stdc++.h>
using namespace std;
#define N 605
#define MOD 1000000007
int n,m,t,ans,a[N],a1[N],a2[N],b1[N],b2[N],dp1[N],pw[N*2],dp[N][2],tmp[N][2];
bool cmp(int x,int y) {return x>y;}
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
int main()
{
	scanf("%d %d",&n,&m);pw[0]=1;
	for(int i=1;i<=n*2;++i) pw[i]=add(pw[i-1],pw[i-1]);
	for(int i=1,x;i<=n;++i)
	{scanf("%d",&x);if(x<0) a2[++a2[0]]=-x;else a1[++a1[0]]=x;}
	sort(a1+1,a1+a1[0]+1,cmp);sort(a2+1,a2+a2[0]+1,cmp);t=1;
	for(int i=1;i<=a1[0];++i)
	{
		while(t<=a2[0] && a1[i]<a2[t]) a[b2[t]=++a[0]]=MOD-a2[t],++t;
		a[b1[i]=++a[0]]=a1[i];
	}while(t<=a2[0]) a[b2[t]=++a[0]]=MOD-a2[t],++t;dp1[0]=1;
	for(int i=1;i<=n;++i)
	{
		W(dp1[m],dp1[m]);
		for(int j=min(m,i-1);j>=0;--j) W(dp1[j+1],1ll*dp1[j]*a[i]%MOD);
	}ans=dp1[m];
	if(m&1)
	{
		for(int i=0;i<=m;++i) dp1[i]=0;dp1[0]=1;
		for(int i=1;i<=a2[0];++i)
		{
			W(dp1[m],dp1[m]);
			for(int j=min(m,i)-1;j>=0;--j) W(dp1[j+1],1ll*dp1[j]*a2[i]%MOD);
		}W(ans,dp1[m]);for(int i=0;i<=m;++i) dp1[i]=0;dp1[0]=1;
		for(int i=a2[0];i;--i)
		{
			W(dp1[m],dp1[m]);
			for(int j=min(m,a2[0]-i+1)-1;j>=0;--j) W(dp1[j+1],1ll*dp1[j]*a2[i]%MOD);
		}W(ans,MOD-dp1[m]);for(int i=0;i<=m;++i) dp1[i]=0;dp1[0]=1;t=0;
		for(int i=1,w;i<=a2[0];++i)
		{
			w=dp1[m-1];while(t<=a1[0] && b1[t]<=b2[i]) ++t;
			if(w) for(int j=t;j<=a1[0];++j)
				W(ans,1ll*(a1[j]+a2[i])*w%MOD*pw[a1[0]+a2[0]-i-j]%MOD);
			for(int j=min(m,i)-1;j>=0;--j) W(dp1[j+1],1ll*dp1[j]*a2[i]%MOD);
		}
	}dp[0][0]=1;
	if(m>1) for(int i=1,t1,t2,w;i<=a1[0];++i)
	{
		for(int j=0;j<=min(m,i-1);++j)
			tmp[j][0]=dp[j][0],tmp[j][1]=dp[j][1];t1=t2=0;
		for(int j=1;j<=a2[0];++j)
		{
			w=dp[m-2][0];
			if(w)
			{
				while(t1<=a1[0] && b1[t1]<=max(b1[i],b2[j])) ++t1;
				while(t2<=a2[0] && b2[t2]<=max(b1[i],b2[j])) ++t2;t=t2;
				for(int k=t1;k<=a1[0];++k)
				{
					while(t<=a2[0] && 1ll*a1[i]*a1[k]<1ll*a2[j]*a2[t]) ++t;
					W(ans,1ll*a1[i]*(a1[k]+a2[j])%MOD*w%MOD*pw[a1[0]+a2[0]-k-t+1]%MOD);
				}t=t1;
				for(int k=t2;k<=a2[0];++k)
				{
					while(t<=a1[0] && 1ll*a1[i]*a1[t]>=1ll*a2[j]*a2[k]) ++t;
					W(ans,1ll*a2[j]*(a1[i]+a2[k])%MOD*w%MOD*pw[a1[0]+a2[0]-k-t+1]%MOD);
				}
			}
			for(int k=min(m,i+j-1)-1;k>=0;--k)
			{
				W(dp[k+1][1],1ll*dp[k][0]*a2[j]%MOD);
				W(dp[k+1][0],1ll*dp[k][1]*a2[j]%MOD);
			}
		}for(int j=0;j<=m;++j) dp[j][0]=tmp[j][0],dp[j][1]=tmp[j][1];
		for(int j=min(m,i)-1;j>=0;--j)
			W(dp[j+1][0],1ll*dp[j][0]*a1[i]%MOD),W(dp[j+1][1],1ll*dp[j][1]*a1[i]%MOD);
	}printf("%d\n",ans);return 0;
}