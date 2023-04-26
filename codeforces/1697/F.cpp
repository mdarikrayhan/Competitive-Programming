#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define N 500010
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<48){if(c=='-')f=0;c=getchar();}
	while(c>=48) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
int n,m,k,tot,idx,top,cnt;
int s[N],low[N],dfn[N],in[N],bel[N];
vector<int> g[N];
void init(){
	idx=top=cnt=0;
	for(int i=0;i<tot;i++) g[i].clear(),dfn[i]=0,s[i]=-1;
}
void dfs(int u){
	in[u]=1;s[++top]=u;
	low[u]=dfn[u]=++idx;
	for(auto v:g[u]){
		if(!dfn[v]) dfs(v);
		if(in[v]) low[u]=min(low[u],low[v]);
	}
	if(low[u]==dfn[u]){
		cnt++;
		while(s[top+1]!=u){
			bel[s[top]]=cnt;
			in[s[top--]]=0;
		}
	}
}
void tarjan(){
	for(int i=0;i<tot;i++)
		if(!dfn[i]) dfs(i);
}
int id(int x,int val,int c){
	return 2*(val*n+x-1)+c;
}
void link(int u,int v){
	g[u^1].push_back(v);
	g[v^1].push_back(u);
}
void solve(){
	n=read();m=read();k=read();
	tot=n*(k+2)*2;init(); 
	for(int i=1;i<=n;i++){
		link(id(i,1,1),id(i,1,1));
		link(id(i,k+1,0),id(i,k+1,0));
		for(int j=1;j<=k;j++) link(id(i,j,1),id(i,j+1,0));
		if(i<n) for(int j=1;j<=k+1;j++) link(id(i,j,0),id(i+1,j,1));
	}
	while(m--){
		int op=read();
		if(op==1){
			int i=read(),x=read();
			link(id(i,x,0),id(i,x+1,1));
		}else if(op==2){
			int i=read(),j=read(),x=read();
			for(int y=1;y<=k+1;y++)
				if(x-y+1>=1&&x-y+1<=k+1){
					link(id(i,y,0),id(j,x-y+1,0));
				}
		}else{
			int i=read(),j=read(),x=read();
			for(int y=1;y<=k+1;y++)
				if(x-y+1>=1&&x-y+1<=k+1){
					link(id(i,y,1),id(j,x-y+1,1));
				} 
		}
	}
	tarjan();
	for(int i=0;i<tot;i++)
		if(bel[i]==bel[i^1]){
			printf("-1\n");
			return;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k+1;j++)
			if(bel[id(i,j,0)]<bel[id(i,j,1)]){
				printf("%d ",j-1);
				break;
			}
	printf("\n");
}
signed main(){
	int T=read();
	while(T--) solve();
	return 0;
}