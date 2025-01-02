// LUOGU_RID: 160055717
#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int range=2e5+10;
int L,w;
int a[range];
int sum[range];
bool check(int mid)
{
	for(int i=L;i<=w-1;i++)
	{		
		if(sum[i]-sum[i-L]>=mid)continue;
		else return 0;
	}
	return 1;
}
void solve()
{
	cin>>w>>L;
	int maxn=0;
	for(int i=1;i<=w-1;i++)
	{
		cin>>a[i];
		maxn+=a[i];	
	}
	//cout<<maxn<<endl;
	for(int i=1;i<=w-1;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
//	cout<<maxn<<endl;
	int ans=0;
	int l=0;
	int r=maxn;
	
	while(l<=r)
	{
		int mid=(l+r)>>1;
	//	cout<<mid<<endl;
		if(check(mid))
		{
			ans=max(mid,ans);
			l=mid+1;
		}
		else  r=mid-1;		
	}
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
	
	
} 