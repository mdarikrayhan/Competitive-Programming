#include<bits/stdc++.h>
using namespace std;const int N=3e5+5,M=N<<2;
int n,m,q,p[N],tot,dfn[N],low[N],st[N],num,bl[N],fa[N],d[N],son[N],hs[N],top[N],R,rk[N],cnt,Bl[N];bool vi[N];
vector<pair<int,int>>v[N],g[N];vector<int>e[N];bool cmp(int x,int y){return rk[x]<rk[y];}
void tj(int u,int lst){int to;dfn[u]=low[u]=++tot,st[++st[0]]=u;
	for(auto i:v[u])if(to=i.first,i.second!=lst){
			if(!dfn[to])tj(to,i.second),low[u]=min(low[u],low[to]);else low[u]=min(low[u],dfn[to]);
		}
	if(low[u]==dfn[u]){num++;int to=0;while(to!=u)bl[to=st[st[0]--]]=num;}
}
void Tj(int u,int lst){int to;dfn[u]=low[u]=++tot,st[++st[0]]=u;
	for(auto i:g[u])if(to=i.first,i.second!=lst){
			if(!dfn[to])Tj(to,i.second),low[u]=min(low[u],low[to]);else low[u]=min(low[u],dfn[to]);
		}
	if(low[u]==dfn[u]){num++;int to=0;while(to!=u)Bl[to=st[st[0]--]]=num;}
}
void dfs1(int u){son[u]=1;
	for(auto i:e[u])if(i!=fa[u])d[i]=d[u]+1,fa[i]=u,dfs1(i),son[u]+=son[i],(hs[u]==-1||son[i]>son[hs[u]])&&(hs[u]=i);
}
void dfs2(int u,int T){rk[u]=++cnt,top[u]=T;for(auto i:e[u])if(i!=fa[u])dfs2(i,i==hs[u]?T:i);}
int lca(int x,int y){while(top[x]!=top[y])d[top[x]]<d[top[y]]&&(swap(x,y),0),x=fa[top[x]];return d[x]<d[y]?x:y;}
int rotate(int element){element=(element+R)%n;if(element==0)element=n;return element;}
bool sol(){int nn,mm;vector<int>tmp;cin>>nn>>mm;for(int i=1;i<=nn;i++)cin>>p[i],p[i]=bl[rotate(p[i])],tmp.push_back(p[i]);
	for(int x,y,i=1;i<=mm;i++){cin>>x>>y,x=bl[rotate(x)],y=bl[rotate(y)],g[x].push_back({y,i}),g[y].push_back({x,i});
		if(!vi[x])tmp.push_back(x),vi[x]=1;if(!vi[y])tmp.push_back(y),vi[y]=1;
	}
	sort(tmp.begin(),tmp.end(),cmp);
	int siz=tmp.size();for(int x,i=1;i<siz;i++)x=lca(tmp[i-1],tmp[i]),!vi[x]&&(tmp.push_back(x),vi[x]=1);
	sort(tmp.begin(),tmp.end(),cmp);
	for(int x,i=1;i<tmp.size();i++)x=lca(tmp[i-1],tmp[i]),x&&(g[x].push_back({tmp[i],i+mm}),g[tmp[i]].push_back({x,i+mm}),0);
	tot=num=0;for(auto i:tmp)if(!dfn[i])Tj(i,0);
	bool asw=1;for(int i=2;i<=nn;i++)if(Bl[p[i]]!=Bl[p[1]])asw=0;for(auto i:tmp)vi[i]=dfn[i]=Bl[i]=0,g[i].clear();
	return asw;
}
int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>q,memset(hs,-1,sizeof(hs));
	for(int x,y,i=1;i<=m;i++)cin>>x>>y,v[x].push_back({y,i}),v[y].push_back({x,i});
	for(int i=1;i<=n;i++)if(!dfn[i])tj(i,0),e[0].push_back(bl[i]);
	for(int to,u=1;u<=n;u++)for(auto i:v[u])if(bl[u]!=bl[to=i.first])e[bl[u]].push_back(bl[to]);
	dfs1(0),dfs2(0,0),vi[0]=1,memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=q;i++)cout<<(sol()?(R=(R+i)%n,"YES\n"):"NO\n");
}