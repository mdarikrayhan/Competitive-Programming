// LUOGU_RID: 159981304
#include <bits/stdc++.h>
using namespace std;
long long n,a[20010],ys[500],cnt,ans=-0x3f3f3f3f,sum;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			ys[++cnt]=i;
			if(i*i!=n)ys[++cnt]=n/i;
		}
	}
	sort(ys+1,ys+1+cnt);
	for(long long i=1;i<=cnt;i++)
	{
		if(ys[i]>=3)
		{
			for(long long j=1;j<=n/ys[i];j++)
			{
				sum=0;
				for(long long k=j;k<=n;k+=n/ys[i])
				{
					sum+=a[k];
				}
				ans=max(ans,sum);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}//