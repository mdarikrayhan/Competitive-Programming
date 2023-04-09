#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int S=200002,T=3.7e7;
int lc[T],rc[T],lz[T],pc,top[S],dfn[S],idfn[S],f[S],rt[S],n,m,p[S],sz[S],son[S],tim;
int fir[S],l[S<<1],to[S<<1],w[S<<1],ec,te[S],ordr[S];
void link(int a,int b,int e){l[++ec]=fir[a];fir[a]=ec;to[ec]=b;w[ec]=e;}
ll sum[T],e[S],sdep[S],ans,dep[S];
void dfs(int p,int fa){
	sz[p]=1; dep[p]=dep[fa]+te[p]; f[p]=fa;
	for(int i=fir[p];i;i=l[i])if(to[i]!=fa)te[to[i]]=w[i],dfs(to[i],p),sz[p]+=sz[to[i]],son[p]=sz[to[i]]>sz[son[p]]?to[i]:son[p];
}
void DFS(int p,int tp){
	top[p]=tp; dfn[p]=++tim; idfn[tim]=p;
	if(son[p])DFS(son[p],tp);
	for(int i=fir[p];i;i=l[i])if(!dfn[to[i]])DFS(to[i],to[i]);
}
#define md (L+R>>1)
ll ask(int p,int l,int r,int L=1,int R=n){
	if(l<=L&&R<=r)return sum[p];
	ll tot=lz[p]*(e[min(R,r)]-e[max(L,l)-1]);
	if(l<=md)tot+=ask(lc[p],l,r,L,md);
	if(r>md)tot+=ask(rc[p],l,r,md+1,R);
	return tot;
}
void add(int P,int&p,int c,int l,int r,int L=1,int R=n){
	if(p<=P)p=++pc;lz[p]=lz[c];sum[p]=sum[c];lc[p]=lc[c];rc[p]=rc[c];
	if(l<=L&&R<=r){lz[p]++;sum[p]+=e[R]-e[L-1];return;}
	if(l<=md)add(P,lc[p],lc[c],l,r,L,md);
	if(r>md)add(P,rc[p],rc[c],l,r,md+1,R);
	sum[p]=sum[lc[p]]+sum[rc[p]]+lz[p]*(e[R]-e[L-1]);
}
void upd(int _,int p,int x){while(x)add(_,rt[p],rt[p],dfn[top[x]],dfn[x]),x=f[top[x]];}
ll Ask(int p,int x,ll a=0){while(x)a+=ask(rt[p],dfn[top[x]],dfn[x]),x=f[top[x]];return a;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]);
	for(int i=1,a,b,e;i<n;++i)scanf("%d%d%d",&a,&b,&e),link(a,b,e),link(b,a,e);
	dfs(1,0);DFS(1,1);
	for(int i=1;i<=n;++i)e[i]=te[idfn[i]]+e[i-1],sdep[i]=sdep[i-1]+dep[p[i]];
	for(int i=1;i<=n;++i)rt[i]=rt[i-1],upd(pc,i,p[i]);
	for(int i=1,o,l,r,x;i<=m;++i){
		scanf("%d%d",&o,&l);l^=ans;
		if(o==1)scanf("%d%d",&r,&x),r^=ans,x^=ans,l--,printf("%lld\n",ans=sdep[r]-sdep[l]+(r-l)*1ll*dep[x]-2*(Ask(r,x)-Ask(l,x)));
		else swap(p[l],p[l+1]),sdep[l]=sdep[l-1]+dep[p[l]],rt[l]=rt[l-1],upd(pc,l,p[l]);
		if(pc>36000000){for(int i=1;i<=pc;++i)lc[i]=rc[i]=lz[i]=sum[i]=0;pc=0;for(int i=1;i<=n;++i)rt[i]=rt[i-1],upd(pc,i,p[i]);}
		ans&=(1<<30)-1;
	}
}
		 			   	  		   														