#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2e5+5;
int n,now,pre;
queue<int>q[2];
vector<int>ans;
struct Tree{
	int siz[N],dep[N],son[N],dfn[N],cnt,top[N],del[N],fa[N],p[N],op;
	vector<int>E[N],t[N<<2];
	void dfs(int u,int f){
		fa[u]=f;siz[u]=1;dep[u]=dep[f]+1;
		for(int v:E[u]){
			if(v==f)continue;
			dfs(v,u);siz[u]+=siz[v];
			if(siz[v]>siz[son[u]])son[u]=v;
		}
	}
	void dfs2(int u,int tp){
		dfn[u]=++cnt;top[u]=tp;
		if(son[u])dfs2(son[u],tp);
		for(int v:E[u]){
			if(v==son[u]||v==fa[u])continue;
			dfs2(v,v);
		}
	}
	int get(int w){return dep[p[w]]<dep[w]?w:p[w];}
	void init(){
		for(int i=2;i<=n;i++){
			scanf("%d",&p[i]);
			E[i].pb(p[i]);E[p[i]].pb(i);
		}dfs(1,0);dfs2(1,1);
	}
	void change(int x,int l,int r,int L,int R,int w){
		if(l>=L&&r<=R){t[x].pb(w);return;}
		int mid=(l+r)>>1;
		if(mid>=L)change(x<<1,l,mid,L,R,w);
		if(mid+1<=R)change(x<<1|1,mid+1,r,L,R,w);
	}
	void add(int u,int v,int id){
		while(top[u]^top[v]){
			if(dep[top[u]]<dep[top[v]])swap(u,v);
			change(1,1,n,dfn[top[u]],dfn[u],id);
			u=fa[top[u]];
		}if(dep[u]<dep[v])swap(u,v);
		if(u^v)change(1,1,n,dfn[v]+1,dfn[u],id);
	}
	void ask(int x,int l,int r,int p){
		for(auto w:t[x])if(!del[w])q[pre].push(w),del[w]=1;
		t[x].clear();if(l==r)return;
		int mid=(l+r)>>1;
		if(mid>=p)ask(x<<1,l,mid,p);
		else ask(x<<1|1,mid+1,r,p);
	}
}T[2];
int main(){
	scanf("%d",&n);
	T[0].init();T[1].init();
	T[0].op=0;T[1].op=1;
	for(int i=2;i<=n;i++){
		T[0].add(T[1].p[i],i,i);
		T[1].add(T[0].p[i],i,i);
	}int x;scanf("%d",&x);x++;
	T[1].del[x]=1;now=0,pre=1;q[0].push(x);
	while(1){
		ans.clear();
		while(!q[now].empty())ans.pb(q[now].front()),q[now].pop();
		if(!ans.size())break;
		sort(ans.begin(),ans.end());
		puts(!now?"Blue":"Red");
		for(auto w:ans){
			printf("%d ",w-1);
			T[now].ask(1,1,n,T[now].dfn[T[now].get(w)]);
		}puts("");now^=1;pre^=1;
	}
}