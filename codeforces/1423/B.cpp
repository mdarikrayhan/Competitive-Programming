// LUOGU_RID: 160107369
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int n,m,u,v,d,l,r,mid;
struct edge{int to,val;};
vector<edge>e[maxn];
vector<int>w;
int match[2][maxn],val[maxn];bool vis[maxn];
void init(){
	for(int i=1;i<=n;i++)vis[i]=false;
}
bool dfs(int u,int x){
	for(edge v:e[u])if(!vis[v.to]&&v.val<=x){
		vis[v.to]=true;
		if(!match[1][v.to]||dfs(match[1][v.to],x)){
			match[0][u]=v.to;
			match[1][v.to]=u;
			val[u]=v.val;
			return true;
		}
	}
	return false;
}
bool judge(int x){
	for(int i=1;i<=n;i++)if(val[i]>x){
		init();match[1][match[0][i]]=0;
		if(!dfs(i,x)){
			match[1][match[0][i]]=i;
			return false;
		}
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&d);
		e[u].push_back({v,d});
		w.push_back(d);
	}
	sort(w.begin(),w.end());
	w.erase(unique(w.begin(),w.end()),w.end());
	r=w.size()-1;
	for(int i=1;i<=n;i++){
		init();if(!dfs(i,w[r])){
			printf("-1");return 0;
		}
	}
	while(l!=r){
		mid=l+(r-l)/2;
		if(judge(w[mid]))r=mid;
		else l=mid+1;
	}
	printf("%d",w[l]);
	return 0;
}