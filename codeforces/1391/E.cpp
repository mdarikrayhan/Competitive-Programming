// LUOGU_RID: 160403006
#include <bits/stdc++.h>
using namespace std;
#define For(Ti,Ta,Tb) for(auto Ti=(Ta);Ti<=(Tb);++Ti)
#define Dec(Ti,Ta,Tb) for(auto Ti=(Ta);Ti>=(Tb);--Ti)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
using ll=long long;
const int N=5e5+5;
int T,n,m,dep[N],fa[N];
vector<int> g[N];
void dfs(int u){
	for(int v:g[u]){
		if(!~dep[v]){
			dep[v]=dep[u]+1;
			fa[v]=u;
			dfs(v);
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m;
		For(i,1,m){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		fill(dep+1,dep+n+1,-1);
		fill(fa+1,fa+n+1,0);
		dep[1]=1;
		dfs(1);
		int u=max_element(dep+1,dep+n+1)-dep;
		if(dep[u]>=(n+1)/2){
			cout<<"PATH\n"<<dep[u]<<'\n';
			for(;u;u=fa[u]){
				cout<<u<<' ';
			}
			cout<<'\n';
		}else{
			cout<<"PAIRING\n";
			vector<pair<int,int>> vec,ans;
			For(u,1,n){
				vec.emplace_back(dep[u],u);
			}
			sort(range(vec));
			while(vec.size()>1){
				auto [_1,u]=vec.back();
				vec.pop_back();
				auto [_2,v]=vec.back();
				if(dep[u]!=dep[v]){
					continue;
				}
				vec.pop_back();
				ans.emplace_back(u,v);
			}
			cout<<ans.size()<<'\n';
			for(auto [u,v]:ans){
				cout<<u<<' '<<v<<'\n';
			}
		}
		For(i,1,n){
			g[i].clear();
		}
	}
	return 0;
}