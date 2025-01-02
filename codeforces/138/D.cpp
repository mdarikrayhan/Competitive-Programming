// LUOGU_RID: 159936817
#include<bits/stdc++.h>
using namespace std;
const int N=25;
char G[N][N];
int id[N][N];
int col[N][N],row[N][N];
int g[2][N][N];
int H[2],W[2];
int f[2][N][N][N][N];
int n,m;

int solve(int t,int l1,int r1,int l2,int r2)
{
	if(l1>r1||l2>r2) return 0;
	int &v=f[t][l1][r1][l2][r2];
	if(~v) return v;
	bool vis[N*N];
	memset(vis,0,sizeof vis);
	for(int i=l1;i<=r1;i++)
	{
		for(int j=l2;j<=r2;j++)
		{
			if(!g[t][i][j]) continue;
			else if(g[t][i][j]=='R')
				vis[solve(t,l1,i-1,l2,r2)^solve(t,i+1,r1,l2,r2)]=true;
			else if(g[t][i][j]=='L')
				vis[solve(t,l1,r1,l2,j-1)^solve(t,l1,r1,j+1,r2)]=true;
			else if(g[t][i][j]=='X')
				vis[solve(t,l1,i-1,l2,j-1)^solve(t,i+1,r1,l2,j-1)^solve(t,l1,i-1,j+1,r2)^solve(t,i+1,r1,j+1,r2)]=true;
		}
	}
	v=0;
	while(vis[v]) v++;
	return v;
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>G[i][j];

	int k=0;
	for(int j=m;j>=1;j--)
	{	
		k+=(((j+1)&1)==((m+1)&1));
		for(int x=1,y=j;x<=n&&y<=m;x++,y++) row[x][y]=k;
	}
	
	for(int i=2;i<=n;i++)
	{
		k+=(((i+1)&1)==((m+1)&1));
		for(int y=1,x=i;y<=m&&x<=n;x++,y++) row[x][y]=k;
	}
	
	k=0;
	for(int j=1;j<=m;j++)
	{
		k+=(((j+1)&1)==((1+1)&1));
		for(int x=1,y=j;x<=n&&y>=1;x++,y--) col[x][y]=k;
	} 
	
	for(int i=2;i<=n;i++)
	{
		k+=(((i+m)&1)==((1+1)&1));
		for(int y=m,x=i;x<=n&&y>=1;x++,y--) col[x][y]=k;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int t=(i+j)&1,x=row[i][j],y=col[i][j];
			g[t][x][y]=G[i][j];
			H[t]=max(H[t],row[i][j]);
			W[t]=max(W[t],col[i][j]);
		}
	}
	
	memset(f,-1,sizeof f);
	int res=solve(0,1,H[0],1,W[0])^solve(1,1,H[1],1,W[1]);
	if(res) cout<<"WIN\n";
	else cout<<"LOSE\n";
	
	return 0;
}