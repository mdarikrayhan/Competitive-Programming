#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7;

int n,m,fa[N][20],sz[N],dep[N],dfn[N],times;
vector<int>e[N];
int b[N][21],c[21][N];

void add(int c[],int x,int v){
	for(;x<=n;x+=x&-x)c[x]+=v;
}
int query(int c[],int x,int res=0){
	for(;x;x-=x&-x)res+=c[x];
	return res;
}

void dfs(int u,int p){
	fa[u][0]=p,dep[u]=dep[p]+1,sz[u]=1,dfn[u]=++times;
	for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u]){
		if(v==p)continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}

int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	for(int i=19;i>=0;i--)if(dep[fa[a][i]]>=dep[b])a=fa[a][i];
	if(a==b)return a;
	for(int i=19;i>=0;i--)if(fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1,0);
	scanf("%d",&m);
	while(m--){
		int op,u,v,k,d;
		scanf("%d",&op);
		if(op==1){
			int x;
			scanf("%d",&x);
			int p=x,ans=0;
			for(int i=0;p&&i<=20;i++,p=fa[p][0]){
				ans+=b[p][i];
				ans+=query(c[i],dfn[p]+sz[p]-1)-query(c[i],dfn[p]-1);
			}
			printf("%d\n",ans);
		}else{
			scanf("%d%d%d%d",&u,&v,&k,&d);
			int x=lca(u,v);
			int p=x;
			for(int i=0;i<=d;i++){
				b[p][d-i]+=k;
				if(d-i)b[p][d-i-1]+=k;
				if(p==1)++i;
				else p=fa[p][0];
			}
			add(c[d],dfn[u],k);
			add(c[d],dfn[v],k);
			add(c[d],dfn[x],(-2)*k);
		}
	}
	return 0;
}