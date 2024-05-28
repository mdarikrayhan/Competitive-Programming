// LUOGU_RID: 160572683
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define PII pair<int,int>
#define PLI pair<ll,int>
#define PLL pair<ll,ll>
#define iter vector<Node>::iterator
using namespace std;
const int N=605;
int n,m,Mod,a[N][N],f[N][N],in[N],out[N],Sta[N],top,id[N],cnt,cnt2;
vector<int>G[N];
int Det(int A[N][N],int n)
{
	int sum=1;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
	{
		while(A[i][i])
		{
			int k=(ll)(Mod-1)*(A[j][i]/A[i][i])%Mod;
			for(int p=i;p<=n;p++)(A[j][p]+=(ll)k*A[i][p]%Mod)%=Mod;
			swap(A[i],A[j]);
			sum=Mod-sum;
		}
		swap(A[i],A[j]);
		sum=Mod-sum;
	}
	for(int i=1;i<=n;i++)sum=(ll)sum*A[i][i]%Mod;
	return sum;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif

	scanf("%d%d%d",&n,&m,&Mod);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		++in[y],++out[x];
	}
	for(int i=1;i<=n;i++)if(!in[i])id[Sta[++top]=i]=++cnt,f[i][cnt]=1
	// ,printf("%d %d\n",i,cnt)
	;
	while(top)
	{
		int x=Sta[top--];
		for(int y:G[x])
		{
			if(!--in[y])Sta[++top]=y;
			for(int i=1;i<=cnt;i++)(f[y][i]+=f[x][i])%=Mod;
		}
	}
	// for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=cnt;j++)printf("%d ",f[i][j]);
	for(int i=1;i<=n;i++)if(!out[i])
	{
		++cnt2;
		// printf("%d %d\n",i,cnt2);
		for(int j=1;j<=cnt;j++)a[j][cnt2]=f[i][j];
	}
	// for(int i=1;i<=cnt;i++,puts(""))for(int j=1;j<=cnt;j++)printf("%d ",a[i][j]);
	printf("%d",Det(a,cnt));

	cerr<<1.0*clock()/CLOCKS_PER_SEC;
}