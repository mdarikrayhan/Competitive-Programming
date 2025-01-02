// LUOGU_RID: 160587958
#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=3e5+10;
int n,u,v,m,f[N][32],dep[N],logn,dp[N];
vector<int> e[N],g[N];
vector<pair<int,int>> all;
void dfs(int u,int fa){
	f[u][0]=fa,dep[u]=dep[fa]+1;
	for(int i=1;i<=logn;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(int v:e[u])if(v!=fa)dfs(v,u);
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int len=dep[u]-dep[v];
	for(int i=logn;i>=0;i--)if(len>=(1<<i))len-=1<<i,u=f[u][i];
	if(u==v)return u;
	for(int i=logn;i>=0;i--)if(f[u][i]!=f[v][i])u=f[u][i],v=f[v][i];
	return f[u][0];
}
int get(int u,int v){
	for(int i=logn;i>=0;i--)if(dep[f[u][i]]>dep[v])u=f[u][i];
	return u;
}
void dfs1(int u,int fa){
	for(int v:e[u])if(v!=fa)dfs1(v,u),dp[u]+=dp[v];
	for(int v:g[u])dp[u]=max(dp[u],dp[v]+1);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;logn=__lg(n);
	for(int i=2;i<=n;i++)cin>>u,e[i].push_back(u),e[u].push_back(i);
	dfs(1,0);
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		if(dep[u]>dep[v])swap(u,v);
		if(f[v][0]==u)cout<<-1,exit(0);
		int lca=LCA(u,v);
		if(lca==u){
			int k=get(v,u);
			g[k].push_back(v);
		}else all.push_back({u,v});
	}
	dfs1(1,0);
	int ans=dp[1];
	for(auto i:all)ans=max(ans,dp[i.first]+dp[i.second]+1);
	cout<<ans;
}
		 		 			 			 	 	 		  							 	