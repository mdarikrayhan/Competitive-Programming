#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
char ans[N+5];
int n,now,sz[N+5];
bool del[N+5],vs[N+5];
vector <int> g[N+5];
void dfs(int i, int p){
	++now;
	sz[i]=1;
	vs[i]=true;
	for (int j : g[i])
		if (j!=p && !del[j]){
			dfs(j,i);
			sz[i]+=sz[j];
		}
}
int centroid(int i, int p){
	for (int j : g[i])
		if (j!=p && !del[j])
			if (sz[j]>now/2) return centroid(j,i);
	return i;
}
void Solve(){
	cin>>n;
	for (int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int k=1;
	while (true){
		bool ok=false;
		for (int i=1;i<=n;i++)
			if (!del[i]){
				ok=true;
				vs[i]=false;
		}
		if (!ok) break;
		for (int i=1;i<=n;i++)
			if (!vs[i]){
				now=0;
				dfs(i,0);
				int idx=centroid(i,0);
				del[idx]=true;
				ans[idx]=k;
			}
		++k;
	}
	for (int i=1;i<=n;i++) cout<<char(ans[i]+'A'-1)<<' ';
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	// cin>>t;
	while (t--) Solve();
}
    	     	     		      			