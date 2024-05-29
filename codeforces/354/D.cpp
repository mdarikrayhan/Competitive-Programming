// LUOGU_RID: 158715144
#include<bits/stdc++.h>
using namespace std;
const int S=100005,MS=785;
int n,m,lim;
vector<int> pos[S];
int dp[2][MS];
int main()
{
	scanf("%d%d",&n,&m);
	lim=min(n,MS-3);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		pos[y].push_back(n-x+1);
	}
	for(int i=1;i<=n;i++) sort(pos[i].begin(),pos[i].end());
	memset(dp,127,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int u=i&1,v=i-1&1;
		memset(dp[u],127,sizeof(dp[u]));
		int k=0,siz=pos[i].size();
		dp[u][0]=dp[v][0]+(siz-k)*3;
		for(int j=0,k=0;j+1<=lim&&j<=n-i+1;j++)
		{
			while(k<pos[i].size()&&pos[i][k]<=j) k++;
			dp[u][j]=min(dp[u][j],dp[v][j+1]+(siz-k)*3);
		}
		k=0;
		int mn=min(dp[v][0],dp[v][1]);
		for(int j=1;j<=lim&&j<=n-i+1;j++)
		{
			while(k<pos[i].size()&&pos[i][k]<=j) k++;
			if(j+1<=lim) mn=min(mn,dp[v][j+1]);
			dp[u][j]=min(dp[u][j],mn+j*(j+1)/2+2+(siz-k)*3);
		}
	}
	printf("%d\n",min(dp[n&1][0],dp[n&1][1]));
	return 0;
}