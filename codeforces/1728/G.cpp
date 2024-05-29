// LUOGU_RID: 160523667
#include<bits/stdc++.h>
using namespace std;
int d,n,m,x,num[300005],a[20],val1[20][300005],val2[20][300005],val[300005];
int c[20],pre[20],suf[20],sum[20][20],q;
const int mod=998244353;
void Add(int &x,int y){x=(x+y>=mod?x+y-mod:x+y);}
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;y/=2;
	}
	return res;
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>d>>n>>m;
	for(int i=1;i<=n;i++)cin>>x,num[x]++;
	for(int i=0;i<m;i++)cin>>a[i];
	sort(a,a+m);
	for(int i=0;i<m;i++)
	{
		val1[i][a[i]]=1;
		for(int j=a[i]+1;j<=d;j++)val1[i][j]=1ll*val1[i][j-1]*qpow(j-a[i],num[j])%mod;
		val2[i][a[i]]=1;
		for(int j=a[i]-1;j>=1;j--)val2[i][j]=1ll*val2[i][j+1]*qpow(a[i]-j,num[j])%mod;
	}
	int res=0;
	for(int s=0;s<(1<<m);s++)
	{
		if(!s){val[s]=qpow(d+1,n);Add(res,val[s]);continue;}
		int tot=0;
		for(int j=0;j<m;j++)if((s>>j)&1)c[++tot]=j;
		val[s]=1;
		for(int j=1;j<=tot;j++)if(num[a[c[j]]])val[s]=0;
		val[s]=1ll*val[s]*val2[c[1]][1]%mod;
		for(int j=1;j<tot;j++)
		{
			int mid=(a[c[j]]+a[c[j+1]])>>1;
			val[s]=1ll*val[s]*val1[c[j]][mid]%mod;
			val[s]=1ll*val[s]*val2[c[j+1]][mid+1]%mod;
		}
		val[s]=1ll*val[s]*val1[c[tot]][d]%mod;
		if(__builtin_popcount(s)&1)val[s]=mod-val[s];
		Add(res,val[s]);
		Add(pre[c[1]],val[s]);Add(suf[c[tot]],val[s]);
		for(int j=1;j<tot;j++)Add(sum[c[j]][c[j+1]],val[s]);
	}
	cin>>q;
	while(q--)
	{
		cin>>x;
		int ans=qpow(d+1,n+1);
		if(num[x]){cout<<1ll*res*(n+1)%mod<<'\n';continue;}
		for(int i=0;i<m;i++)if(a[i]>x)Add(ans,1ll*pre[i]*(a[i]-x)%mod);
		for(int i=0;i<m;i++)if(x>a[i])Add(ans,1ll*suf[i]*(x-a[i])%mod);
		for(int i=0;i<m;i++)
		{
			for(int j=i+1;j<m;j++)
			{
				if(a[i]<x&&x<a[j])Add(ans,1ll*sum[i][j]*min(x-a[i],a[j]-x)%mod);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
