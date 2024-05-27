#include<bits/stdc++.h>
using namespace std;
long long a[500],b[500],cx[500];
long long dp[500],tdp[500],inf=1000000000000000000LL;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	long long n,k,i,t,c,ca,cb,xa,xb,ta,tb,vl,ans;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
		cx[i]=(a[i]+b[i])%k;
	}
	for(i=0;i<k;i++)
	{
		dp[i]=-inf;
		tdp[i]=-inf;
	}
	dp[0]=0;
	c=0;
	for(t=0;t<n;t++)
	{
		for(i=0;i<k;i++)
		{
			ca=i;
			cb=c+k-i;
			if(cb>=k)cb-=k;
			for(xa=0;xa<k&&xa<=a[t];xa++)
			{
				xb=cx[t]+k-xa;
				if(xb>=k)xb-=k;
				if(xb>b[t])continue;
				vl=dp[i];
				ta=ca+xa;
				tb=cb+xb;
				if(ta>=k)
				{
					vl++;
					ta-=k;
				}
				if(tb>=k)
				{
					vl++;
					tb-=k;
				}
				vl+=(a[t]+b[t]-xa-xb)/k;
				tdp[ta]=max(tdp[ta],vl);
			}
		}
		c=(c+a[t]+b[t])%k;
		for(i=0;i<k;i++)
		{
			dp[i]=tdp[i];
			tdp[i]=-inf;
		}
	}
	ans=0;
	for(i=0;i<k;i++)ans=max(ans,dp[i]);
	cout<<ans<<'\n';
	return 0;
}