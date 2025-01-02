// LUOGU_RID: 160497769
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=209;
int col[N],f[N][N],n,m;
void dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(abs(f[x][i])==1)
		{
			if(~col[i])
			{
				if(col[i]==col[x])
				{
					cout<<"NO\n";
					exit(0);
				}
			}
			else
			{
				col[i]=col[x]^1;
				dfs(i);
			}
		}
	}
}
signed main()
{
	memset(f,0x3f,sizeof(f));
	cin>>n>>m;
	memset(col,-1,sizeof(col));
	for(int i=1;i<=n;i++)
	f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int l,r,v;
		cin>>l>>r>>v;
		if(v)
		f[l][r]=1,f[r][l]=-1;
		else
		f[l][r]=f[r][l]=1;
	}
	col[1]=0;
	dfs(1);
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int ans=-n-1,ST=0;
	for(int i=1;i<=n;i++)
	{
		if(f[i][i]<0)
		{
			cout<<"NO\n";
			return 0;
		}
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]>=ans)
			{
				ans=f[i][j];
				ST=i;
			}
		}
	}
	cout<<"YES\n"<<ans<<'\n';
	for(int i=1;i<=n;i++)
	cout<<f[ST][i]+50000<<" \n"[i==n];
	return 0;
}