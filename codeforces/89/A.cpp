#include<bits/stdc++.h>
using namespace std;
long long a[10010],n,m,ans,mn=1e9,k,s;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(mn>a[i]&&i%2==1)
		  mn=a[i];
	}
	s=n/2+1;
	if(n%2==1&&s<=m)
	{
		ans=m/s*k;
		ans=min(mn,ans);
	}
	cout<<ans;
	return 0;
}