#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;cin>>n;
	vector<vi> adj(n);
	rep(i,0,n-1){
		int u,v;cin>>u>>v;u--;v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	vector<pii> x(n);
	function<void (int, int, int, int&)> dfs = [&] (int u, int p, int l, int& r) {
		r+=sz(adj[u])-(p!=-1);
		x[u]={l,r};
		int ll = r;
		r++;
		for(int v : adj[u]){
			if(v==p)continue;
			ll--;
			dfs(v,u,ll,r);
		}
	};
	int r=2;
	dfs(0,-1,1,r);
	rep(i,0,n){
		cout<<x[i].F<<" "<<x[i].S<<"\n";
	}
}