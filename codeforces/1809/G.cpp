// LUOGU_RID: 160041525
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int mod=998244353;
int n,k,a[N],f[N],dp[N],qz[N];
int qpow(int a,int b)
{
	int s=1,base=a;
	while(b!=0)
	{
		if(b&1==1)
		{
			s*=base;
			s%=mod;
		}
		base*=base;
		base%=mod;
		b>>=1;
	}
	return s;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[n]-a[n-1]<=k)
	{
		cout<<0<<'\n';
		return 0; 
	}
	qz[0]=1;
	for(int i=1;i<=n;i++)
	{
		qz[i]=qz[i-1]*i;
		qz[i]%=mod;
	}
//	f[0]=qz[n-1];
	for(int i=1,j=0;i<=n;i++)
	{
		while(a[i]-a[j+1]>k)
		j++;
		dp[i]=qz[n-1]+f[j];
		dp[i]%=mod;
		dp[i]*=qpow(qz[n-j-1],mod-2);
		dp[i]%=mod;
		f[i]=f[i-1]+dp[i]*qz[n-j-2];
		f[i]%=mod;
	}
	cout<<dp[n]<<'\n';
	return 0;
}