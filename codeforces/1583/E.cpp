#include<bits/stdc++.h> 
using namespace std;
const int MAXN=3e5+1;
vector <int> G[MAXN],T[MAXN]; 
bool vis[MAXN];
int dep[MAXN],fa[MAXN],deg[MAXN];
inline void dfs(int p) {
	vis[p]=true;
	for(int v:G[p]) {
		if(!vis[v]) {
			dep[v]=dep[p]+1,fa[v]=p;
			T[p].push_back(v);
			dfs(v);
		}
	}
}
inline int LCA(int u,int v) {
	if(u==v) return u;
	return dep[u]>dep[v]?LCA(fa[u],v):LCA(u,fa[v]);
}
inline vector<int> path(int u,int v) {
	int x=LCA(u,v);
	vector <int> c1,c2,pt;
	for(int p=u;p!=x;p=fa[p]) c1.push_back(p);
	for(int p=v;p!=x;p=fa[p]) c2.push_back(p);
	reverse(c2.begin(),c2.end());
	for(int i:c1) pt.push_back(i);
	pt.push_back(x);
	for(int i:c2) pt.push_back(i);
	return pt;
}
int st[MAXN],ed[MAXN];
signed main() {
	int n,m,q,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	scanf("%d",&q);
	for(int i=1;i<=q;++i) {
		scanf("%d%d",&st[i],&ed[i]);
		++deg[st[i]],++deg[ed[i]];
	}
	for(int i=1;i<=n;++i) if(deg[i]%2!=0) ++cnt;
	if(cnt>0) printf("NO\n%d\n",cnt/2);
	else {
		puts("YES");
		for(int i=1;i<=q;++i) {
			vector <int> ans=path(st[i],ed[i]);
			printf("%d\n",(int)ans.size());
			for(int j:ans) printf("%d ",j);
			puts("");
		}
	}
	return 0;
}
