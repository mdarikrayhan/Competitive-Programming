// LUOGU_RID: 159745719
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
const int N=2007;
std::vector<int> to[N],L[N];
int dg[N],fs[N],dfn[N],rk[N],low[N],dc;
inline void eadd(int u,int v){to[u].push_back(v),to[v].push_back(u);}
void tarjan(int i,int l)
{
//	printf("tarj %d\n",i);
	fs[rk[dfn[i]=low[i]=++dc]=i]=l;
	for(int v:to[i])if(v!=l)
		if(!dfn[v])tarjan(v,i),low[i]=std::min(low[i],low[v]);
		else low[i]=std::min(low[i],dfn[v]);
}
std::queue<int> que;int tim[N],tc;
void dfs4(int i){tim[i]=++tc;for(int v:L[i])if(!tim[v])dfs4(v);}
int main()
{
	int T,n,m;scanf("%d",&T);
	while(T--)
	{
		int eu,ev,na,nb;scanf("%d%d%d",&na,&nb,&m);
		n=na+nb;memset(dfn+1,dc=0,n<<2);
		for(int i=1;i<=n;++i)to[i].clear(),L[i].clear();
		for(int i=1;i<=m;++i)scanf("%d%d",&eu,&ev),eadd(eu,ev);
		tarjan(1,0);memset(dg+1,0,n<<2);
		for(int i=1;i<=n;++i)++dg[fs[i]];
		for(int i=1;i<=n;++i)if(!dg[i])que.push(i);
		while(!que.empty())
		{
			int i=que.front();que.pop();
			L[fs[i]].push_back(i);L[rk[low[i]]].push_back(i);
			if(!--dg[fs[i]])que.push(fs[i]);
		}
		memset(tim+1,tc=0,n<<2);dfs4(1);
//		for(int i=1;i<=n;++i)printf("%d ",tim[i]);puts("]");
		for(int i=1;i<=n;++i)if(tim[i]<=na)printf("%d ",i);puts("");
		for(int i=1;i<=n;++i)if(tim[i]>na)printf("%d ",i);puts("");
	}
	return 0;
}