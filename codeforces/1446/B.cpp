// LUOGU_RID: 160138028
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
char a[N],b[N];
int f[N][N];
int n,m;
signed main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1])-1;
			if (a[i]==b[j])f[i][j]=f[i-1][j-1]+2;
			f[i][j]=max(f[i][j],1ll*0);
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}