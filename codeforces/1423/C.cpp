#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,k,siz[N],vis[N],cut[N];
vector<pair<int,int>> ans;
vector<int> e[N],a,tmp; 
void find_root(int x,int sqr){
	vis[x]=1;
	for(int v:e[x]){
		if(!vis[v]&&!cut[v]){
			find_root(v,sqr);
			siz[x]+=siz[v];
		}
	}
	if(siz[x]>=sqr){
		cut[x]=1,siz[x]=0;
		a.push_back(x); 
	}
}
void find_son(int u){
	tmp.push_back(u);
	vis[u]=1;
	for(int v:e[u])if(!vis[v]&&!cut[v])find_son(v);
}
void solve(int x){
	tmp.clear();
	find_son(x);
	int size=(int)tmp.size(),sqr=floor(sqrt(size));
	for(auto u:tmp)vis[u]=0,siz[u]=1;
	a.clear();
	find_root(x,sqr);
	for(auto u:tmp)vis[u]=0;
	for(auto u:a)for(int v:a)if(u<v)ans.push_back(make_pair(u,v));
	vector<int> t=tmp;
	for(auto u:a){
		tmp.clear();
		find_son(u);
		for(auto v:tmp)if(u!=v)ans.push_back(make_pair(u,v)),vis[v]=0;
	}
	for(auto u:t) if(!cut[u]) solve(u);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	solve(1);
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d %d\n",x.first,x.second);
	return 0;
}