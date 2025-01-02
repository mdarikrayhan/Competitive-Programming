// LUOGU_RID: 160468396
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,mod=1e9+7;
int n,k,dep[N],f[N][205],s[N][205],g[205],res[205],st[205][205],sz[N];
vector<int>e[N];
void dfs(int x,int prt)
{
	dep[x]=dep[prt]+1,sz[x]=1;
	for(auto y:e[x]) if(y!=prt)
	{
		dfs(y,x);
		for(int i=k;i>=1;i--) f[y][i]=(f[y][i]+f[y][i-1])%mod;
		for(int i=0;i<=k;i++) g[i]=f[x][i];
		for(int i=0;i<=min(k,sz[x]);i++)
			for(int j=0;j<=min(k-i,sz[y]);j++)
				g[i+j]=(g[i+j]+1ll*f[x][i]*f[y][j]+2ll*s[x][i]*f[y][j])%mod;
		for(int i=0;i<=k;i++) s[x][i]=(s[x][i]+f[y][i])%mod,f[x][i]=g[i];
		sz[x]+=sz[y];
	}
	f[x][0]=(f[x][0]+1)%mod;
	for(int i=0;i<=k;i++) res[i]=(res[i]+1ll*f[x][i]+s[x][i])%mod;
	for(int i=0;i<=k;i++) f[x][i]=(f[x][i]+2ll*s[x][i])%mod;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++) cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
	st[0][0]=1;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++) st[i][j]=(st[i-1][j-1]+1ll*st[i-1][j]*j)%mod;
	dfs(1,0);
	int ans=0,fac=1;
	for(int i=0;i<=k;i++,fac=1ll*fac*i%mod) ans=(ans+1ll*st[k][i]*res[i]%mod*fac)%mod;
	cout<<ans;
	return 0;
}