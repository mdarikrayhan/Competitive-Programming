// LUOGU_RID: 159967139
#include <bits/stdc++.h>
using namespace std;
#define For(Ti,Ta,Tb) for(auto Ti=(Ta);Ti<=(Tb);++Ti)
#define Dec(Ti,Ta,Tb) for(auto Ti=(Ta);Ti>=(Tb);--Ti)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
using ll=long long;
const int N=2e5+5;
int T,n,m,f[N];
vector<int> g[N];
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m;
		For(i,1,m){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
		}
		vector<int> ans;
		For(u,1,n){
			if(f[u]>=2){
				ans.push_back(u);
				f[u]=-1;
			}
			for(int v:g[u]){
				f[v]=max(f[v],f[u]+1);
			}
		}
		cout<<ans.size()<<'\n';
		for(int x:ans){
			cout<<x<<' ';
		}
		cout<<'\n';
		fill(f+1,f+n+1,0);
		For(i,1,n){
			g[i].clear();
		}
	}
	return 0;
}