#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
map<int,map<int,int>> col;
int id[N];
int deg[N];
vector<int> G[N];

struct Edge{
	int u,v;
}edges[N];
int n,m,t,k;

void colored(int u,int f,int c1,int c2){
	for(int v:G[u]){
		if(v==f) continue;
		if(col[u][v]==c2){
			col[u][v]=col[v][u]=c1;
			colored(v,u,c2,c1);
			break;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k>>t;
	int tot=n+m;
	for(int i=1;i<=n+m;i++) id[i]=i;
	for(int i=1;i<=k;i++){
		int u,v;
		cin>>u>>v;
		v+=n;
		deg[u]++,deg[v]++;
		if(deg[u]>t) id[u]=++tot,deg[u]-=t;
		if(deg[v]>t) id[v]=++tot,deg[v]-=t;
		
		int c1=0,c2=0;
		u=id[u],v=id[v];
		vector<int> tmp;
		tmp.push_back(0);
		tmp.push_back(t+1);
		for(int s:G[u]) tmp.push_back(col[u][s]);
		sort(tmp.begin(),tmp.end());
		for(int i=0;i<tmp.size()-1;i++){
			if(tmp[i]+1!=tmp[i+1]){
				c1=tmp[i]+1;
				break;
			}
		}
		tmp.clear();
		tmp.push_back(0);
		tmp.push_back(t+1);
		for(int s:G[v]) tmp.push_back(col[v][s]);
		sort(tmp.begin(),tmp.end());
		for(int i=0;i<tmp.size()-1;i++){
			if(tmp[i]+1!=tmp[i+1]){
				c2=tmp[i]+1;
				break;
			}
		}
		if(c1==c2){
			col[u][v]=col[v][u]=c1;
		}else{
			col[u][v]=col[v][u]=c1;
			colored(v,u,c2,c1);
		}
		G[u].push_back(v);
		G[v].push_back(u);
		edges[i]={u,v};
	}
	int res=0;
	for(int i=1;i<=n+m;i++){
		if(deg[i]%t!=0) res++;
	}
	cout<<res<<"\n";
	for(int i=1;i<=k;i++){
		cout<<col[edges[i].u][edges[i].v]<<" ";
	}
}