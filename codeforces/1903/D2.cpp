#include <bits/stdc++.h>
using namespace std;
long long a[1000000],dp[1<<20];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	long long n,q,i,j,k,s=0,lst,c,x,l,r,mid;
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	for(i=0;i<n;i++)
	{
		lst=-1;
		c=0;
		for(j=19;j>-1;j--)
		{
			if(a[i]>>j&1)
			{
				c+=(1LL<<j);
				x=(1LL<<j)-(a[i]&((1LL<<j)-1));
				dp[c]+=x;
				if(lst!=-1)dp[lst]-=x;
				lst=c;
			}
		}
	}
	for(j=0;j<20;j++)
	{
		for(i=0;i<(1<<20);i++)
		{
			if(i>>j&1)dp[i-(1<<j)]+=dp[i];
		}
	}
	dp[0]=0;
	for(i=1;i<(1<<20);i++)dp[i]+=dp[i-1];
	for(i=0;i<(1<<20);i++)dp[i]=n*i-dp[i];
	for(i=(1<<20)-2;i>-1;i--)dp[i]=min(dp[i],dp[i+1]);
	for(;q>0;q--)
	{
		cin>>k;
		if(s+k>=n*1000000)
		{
			cout<<(s+k)/n<<'\n';
			continue;
		}
		l=0;
		r=(1<<20);
		while(r-l>1)
		{
			mid=(l+r)/2;
			if(dp[mid]>k)r=mid;
			else l=mid;
		}
		cout<<l<<'\n';
	}
	return 0;
}