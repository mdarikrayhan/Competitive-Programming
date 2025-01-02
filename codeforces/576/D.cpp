// LUOGU_RID: 160226925
#include <iostream>
#include <algorithm>
#include <bitset>
#include <queue>
using namespace std;
const int maxn=155;
struct M{
	bool v[maxn][maxn];
}co,fac,z;
struct V{
	bool v[maxn];
}val,vz;
struct L{
	int u,v,w;
}li[maxn];
int n,m,ans=2e9,dis[maxn],vis[maxn];
bitset<maxn> bl[maxn],br[maxn];
queue<int> q;
bool cmp(L x,L y){return x.w<y.w;}
V muv(V vl,M vr)
{
	V re=vz;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if(vl.v[j]&&vr.v[j][i]) re.v[i]=1;
	return re;
}
M mul(M vl,M vr)
{
	M re=z;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) bl[i][j]=vl.v[i][j],br[j][i]=vr.v[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if((bl[i]&br[j]).count()) re.v[i][j]=1;
	return re;
}
int solve()
{
	for (int i=1;i<=n;i++)
	{
		dis[i]=vis[i]=0;
		if(val.v[i]) vis[i]=1,q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=1;i<=n;i++)
			if(co.v[u][i]&&!vis[i]) vis[i]=1,dis[i]=dis[u]+1,q.push(i);
	}
	return vis[n]?dis[n]:-1;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>li[i].u>>li[i].v>>li[i].w;
	sort(li+1,li+m+1,cmp);
	val.v[1]=1;
	for (int i=1;i<=m;i++)
	{
		int dt=li[i].w-li[i-1].w;
		fac=co;
		while(dt){
			if(dt&1) val=muv(val,fac);
			fac=mul(fac,fac),dt>>=1;
		}
		co.v[li[i].u][li[i].v]=1;
		int mi=solve();
		if(mi>=0) ans=min(ans,mi+li[i].w);
	}
	if(ans==2e9) cout<<"Impossible"<<endl;
	else cout<<ans<<endl;
	return 0;
}