// LUOGU_RID: 160014702
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Max=105,Mod=1e9+7;
int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%Mod;
		a=(a*a)%Mod;
		b>>=1;
	}
	return ans;
}
struct mat{
	int n[Max][Max],r,c;
	mat(int rr,int cc)
	{
		r=rr;
		c=cc;
		for(int i=0;i<=r;i++)
			for(int j=0;j<=c;j++)
				n[i][j]=0;
	}
	mat operator * (mat b)
	{
		mat ans(r,c);
		for(int i=0;i<=r;i++)
			for(int j=0;j<=c;j++)
				for(int k=0;k<=c;k++)
					ans.n[i][j]=(ans.n[i][j]+n[i][k]*b.n[k][j])%Mod;
		return ans;
	}
};
int n,k,m,cnt;
int num[Max];
signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		m+=num[i];
	}
	for(int i=1;i<=n-m;i++)
	{
		if(num[i])
			cnt++;
	}
	mat ans(0,m),po(m,m);
	ans.n[0][cnt]++;
	int tot=n*(n-1)/2;
	tot=qpow(tot,Mod-2);
	for(int i=0;i<=m;i++)
	{
		for(int j=max(i-1,0ll);j<=i+1;j++)
		{
			if(i==j-1)
				po.n[j][i]=((j*j)*tot)%Mod;
			else if(i==j+1)
				po.n[j][i]=(((n-m-j)*(m-j))%Mod*tot)%Mod;
			else
				po.n[j][i]=((n*(n-1)/2-((j*j)+((n-m-j)*(m-j))))%Mod*tot)%Mod;
		}
	}
	while(k)
	{
		if(k&1)
			ans=ans*po;
		po=po*po;
		k>>=1;
	}
	printf("%lld",ans.n[0][0]);
}