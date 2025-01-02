#include<bits/stdc++.h>
using namespace std;typedef long long ll;const ll INF=1e12,N=4e5+7;
struct Edge{int u,v,w;}E[N];
struct MergeHeap{
	int ls[N],rs[N],val[N],d[N],tag[N];
	void push(int rt,int t){if(rt)tag[rt]+=t,val[rt]+=t;}
	void pushdown(int rt){
		if(!tag[rt])return;
		push(ls[rt],tag[rt]);push(rs[rt],tag[rt]);
		tag[rt]=0;
	}
	int merge(int x,int y){
		if(!x||!y)return x+y;if(val[x]>val[y])swap(x,y);
		pushdown(x);rs[x]=merge(rs[x],y);
		if(d[ls[x]]<d[rs[x]])swap(ls[x],rs[x]);
		d[x]=d[rs[x]]+1;return x;
	}
}H;
int fa[N],dfn[N],idfn[N],sz[N],son[N],top[N],stk[N],col[N],ffa[N],rt[N],tot;
char op[5];ll wei[N];vector<int>G[N];
struct node{
	int c;ll s;
	node operator+(const node&a)const{
		node ans;ans.s=0;
		ans.c=min(c,a.c);
		if(c==ans.c)ans.s+=s;
		if(a.c==ans.c)ans.s+=a.s;
		return ans;
	}
};
struct Seg{
	int tag[N<<2];node val[N<<2];
	void build(int rt,int l,int r){
		if(l==r)return val[rt].s=wei[idfn[l]],void();
		int mid=l+r>>1;build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
		val[rt]=val[rt<<1]+val[rt<<1|1];
	}
	void push(int rt,int t){tag[rt]+=t;val[rt].c+=t;}
	void pushdown(int rt){
		if(!tag[rt])return;
		push(rt<<1,tag[rt]);push(rt<<1|1,tag[rt]);
		tag[rt]=0;
	}
	void update(int rt,int l,int r,int x,int y,int z){
		if(l>y||r<x)return;
		if(x<=l&&r<=y)return push(rt,z);
		pushdown(rt);int mid=l+r>>1;
		update(rt<<1,l,mid,x,y,z);update(rt<<1|1,mid+1,r,x,y,z);val[rt]=val[rt<<1]+val[rt<<1|1];
	}
}S;
int getF(int x){return ffa[x]==x?x:ffa[x]=getF(ffa[x]);}
void dfs1(int u){
	sz[u]=1;for(auto v:G[u]){
		dfs1(v);sz[u]+=sz[v];if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void dfs2(int u){
	dfn[u]=++tot;idfn[tot]=u;
	if(u==son[fa[u]])top[u]=top[fa[u]];else top[u]=u;
	if(son[u])dfs2(son[u]);
	for(int v:G[u])if(v!=son[u])dfs2(v);
}
int main(){
	int n,m,q,x,cnt;scanf("%d%d%d",&n,&m,&q);cnt=n;
	for(int i=1;i<=m;++i)
	scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w),H.val[i]=E[i].w,rt[E[i].u]=H.merge(rt[E[i].u],i);
	iota(ffa+1,ffa+n+1,1);for(int i=1;i<=n;++i)if(!col[i]){
		int tp=0;stk[++tp]=i;
		while(1){
			int u=stk[tp],v=getF(E[rt[u]].v);
			col[u]=i;wei[u]=H.val[rt[u]];
			if(!rt[u]){wei[u]=INF;break;}
			if(!col[v]){stk[++tp]=v;continue;}
			if(col[v]!=i)break;
			cnt++;ffa[cnt]=cnt;
			int w;do{
				w=stk[tp--];
				H.push(rt[w],-H.val[rt[w]]);H.pushdown(rt[w]);
				rt[w]=H.merge(H.ls[rt[w]],H.rs[rt[w]]);
				fa[w]=ffa[w]=cnt;
				rt[cnt]=H.merge(rt[cnt],rt[w]);
			}while(w!=v);stk[++tp]=cnt;
		}
	}
	n=cnt;for(int i=1;i<=n;++i)if(fa[i])G[fa[i]].push_back(i);
	for(int i=1;i<=n;++i)if(!fa[i])dfs1(i),dfs2(i);
	S.build(1,1,n);while(q--){
		scanf("%s%d",op,&x);
		while(x)S.update(1,1,n,dfn[top[x]],dfn[x],op[0]=='+'?1:-1),x=fa[top[x]];
		node t=S.val[1];
		if(t.c)puts("0");else if(t.s<INF)printf("%lld\n",t.s);else puts("-1");
	}
}