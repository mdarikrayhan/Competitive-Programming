#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int N=500010,M=1000010,mod=998244353;
inline ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
struct edge{int v,d,nex;}e[M*2];
bool bridge[M*2];
int fir[N],ent=1;
inline void add(int u,int v,int d)
{
	e[++ent]={v,d,fir[u]};
	fir[u]=ent;
	return;
}
//怎么找环啊……
//这是个仙人掌，我们可以找桥然后BFS……
int dfn[N],low[N],tot;
void dfs(int u,int f)
{
	tot++;
	low[u]=dfn[u]=tot;
	for(int i=fir[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(i==(f^1))continue;
		if(dfn[v])low[u]=min(low[u],dfn[v]);
		else dfs(v,i),low[u]=min(low[u],low[v]),bridge[i]|=(low[v]>dfn[u]),bridge[i^1]|=(low[v]>dfn[u]);
	}
	return;
}
bool vis[N];
queue<int>q;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n%2!=m%2){printf("0");return 0;}
	for(int i=1;i<=m;i++)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		add(a,b,d),add(b,a,d);
	}
	dfs(1,0);
	ll ans=1;
	int cnt=0;
	ll cnt_bridge=0,cnt_point=0;
	for(int i=2;i<=ent;i+=2)cnt_bridge+=bridge[i]*(e[i].d+1),cnt_point+=bridge[i]*e[i].d;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		ll len=0;
		q.push(i);
		vis[i]=true;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			bool ad=true;//环要找对，不要漏一条边！
			for(int i=fir[u];i;i=e[i].nex)
			{
				int v=e[i].v;
				if(bridge[i]||vis[v])continue;
				len+=e[i].d+1;
				if(ad)vis[v]=true,q.push(v),ad=false;
			}
		}
		if(!len){cnt_point++;continue;}
		cnt++;
		ll ret=qpow(2,len);
		if(len&1)ret=(ret-2+mod)%mod;
		else ret=(ret+2)%mod;
		// fprintf(stderr,"%lld %lld\n",len,ret);
		(ans*=ret)%=mod;
	}
	// fprintf(stderr,"%lld %lld %d %lld",ans,cnt_bridge,cnt,cnt_point);
	printf("%lld",ans*qpow(2,cnt)%mod*qpow(qpow(3,mod-2)*2%mod,cnt_bridge)%mod*qpow(3,cnt_point)%mod);
	return 0;
}
		  				  	    	 	     				 	 	