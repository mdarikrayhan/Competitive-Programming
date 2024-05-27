// LUOGU_RID: 160490963
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NN=3004,dx[5]={0,1,1,-1,-1},dy[5]={0,1,-1,1,-1};
ll f[NN][NN][5];
int a[NN],b[NN];
void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<=n;i++)
	{
		f[i][0][0]=0;
		for(int j=1;j<=4;j++)
			f[i][0][j]=-1e18;
		for(int j=1;j<=min(i,m);j++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j-1][0]+abs(a[i]-b[i])*2ll);
			for(int k=1;k<=4;k++)
			{
				f[i][j][k]=max(f[i-1][j-1][k],f[i-1][j-1][0]+dx[k]*a[i]+dy[k]*b[i]);
				f[i][j][0]=max(f[i][j][0],f[i-1][j-1][k]-dx[k]*a[i]-dy[k]*b[i]);
			}
		}
	}
	printf("%lld\n",f[n][m][0]);
}
int main()
{
	for(int i=0;i<NN;i++)
		for(int j=0;j<NN;j++)
			for(int k=0;k<5;k++)
				f[i][j][k]=-1e18;
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}