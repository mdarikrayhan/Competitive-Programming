#include<bits/stdc++.h>
using namespace std;

const int N=1e5+6;

int n,cnt[N],vis[N],col[N],fa[N];
vector<int>g[N];

inline void dfs(int u,int faa){
	fa[u]=faa;
	for(int v:g[u])if(v^faa)col[v]=col[u]^1,dfs(v,u);
	return;
}

inline int jump(int u){

while(!vis[u]){
		vis[u]=1,cnt[u]++;
		u=fa[u],cnt[u]++;
	}
	return u;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	if(n%2==0||g[n].size()<=1){
		printf("%d",n);
		return 0;
	}
	vis[n]=1,dfs(n,0);
	for(int i=n;i;i--){
		if(g[i].size()<=1||col[i]){
			printf("%d",i);
			break;
		}
		int u=jump(i);
		if(cnt[u]>2&&!col[u]){
			printf("%d",i);
			break;
		}
	}
	return 0; 
}