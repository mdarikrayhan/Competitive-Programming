// LUOGU_RID: 157410808
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=4e5+10;
const int K=20+10;
const int inf=1e9+10;
const int mod=1e18+7;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0'; ch=getchar();}
	return s*w;
}
int n,m,s,t,ds,dt,dd,cnt,ac,tot,ans[N][2],id[N],rs[N],rt[N];
bool ttf=false;
vector <int> edge[N],dg;
void dfs(int u)
{
	for(int v:edge[u]) if(!id[v]) id[v]=id[u],ans[++ac][0]=u,ans[ac][1]=v,dfs(v);
}
struct edg
{
	int u,v;
}e[N],ex[N];
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read();
	s=read(),t=read(),ds=read(),dt=read();
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v;
		if(u==s||v==s||u==t||v==t) ex[++cnt]=e[i];
		else edge[u].push_back(v),edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++) if(!id[i]&&i!=s&&i!=t) id[i]=++tot,dfs(i);
	for(int i=1;i<=cnt;i++)
	{
		int u=ex[i].u,v=ex[i].v;
		if(v==s) swap(v,u);
		if(u==s&&v==t)
		{
			ttf=true;
			continue;
		}
		if(v==t) swap(u,v);
		int tid=id[v];
		if(u==s) rs[tid]=v;
		else rt[tid]=v;
	}
	for(int i=1;i<=tot;i++)
	{
		if(rs[i]&&!rt[i]) ds--,ans[++ac][0]=s,ans[ac][1]=rs[i];
		else if(rt[i]&&!rs[i]) dt--,ans[++ac][0]=t,ans[ac][1]=rt[i];
		else dd++,dg.push_back(i);
	}
	ds--,dt--;
	if(!dd) ans[++ac][0]=s,ans[ac][1]=t;
	else
	{
		int k=dg[dd-1];
		ans[++ac][0]=s,ans[ac][1]=rs[k];
		ans[++ac][0]=t,ans[ac][1]=rt[k];
		dg.pop_back(),dd--;
	}
	if(ds<0||dt<0||ds+dt<dd)
	{
		cout<<"No";
		return 0;
	}
	for(int k:dg)
	{
		if(ds>dt) ds--,ans[++ac][0]=rs[k],ans[ac][1]=s;
		else dt--,ans[++ac][0]=rt[k],ans[ac][1]=t;
	}  
	cout<<"Yes"<<"\n";
	for(int i=1;i<=ac;i++) cout<<ans[i][0]<<' '<<ans[i][1]<<"\n";
	return 0;
}