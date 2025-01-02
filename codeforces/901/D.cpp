#include <bits/stdc++.h>

using namespace std;

#define int long long

using ll = long long;

const int N = 2e5+10;

int n,m,c[N],f[N],vl[N];
vector<pair<int,int> > g[N];

int ff(int x){
	return x==f[x]?x:f[x]=ff(f[x]);
}

void merge(int x,int y){
	x=ff(x);
	y=ff(y);
	if (x!=y){
		f[x]=y;
	}
}

struct node {
	int x,y,z;
} p[N];

int cnt;
ll F[N][20],dep[N],ans[N];

void dfs(int u,int fa){
	F[u][0]=fa;
	for (int i=1; i<20; i++){
		F[u][i]=F[F[u][i-1]][i-1];
	}
	dep[u]=dep[fa]+1;
	for (auto p : g[u]){
		int v=p.first,w=p.second;
		if (v^fa){
			dfs(v,u);
			ans[w]=vl[v];
			vl[u]-=vl[v];
			vl[v]=0;
		}
	}
}

int lca(int u,int v){
	if (dep[u]<dep[v]){
		swap(u,v);
	}
	int dif=dep[u]-dep[v];
	for (int i=0; i<20; i++){
		if (dif>>i&1){
			u=F[u][i];
		}
	}
	if (u==v){
		return u;
	}
	for (int i=19; i>=0; i--){
		if (F[u][i]!=F[v][i]){
			u=F[u][i],v=F[v][i];
		}
	}
	return F[u][0];
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>m;
	for (int i=1; i<=n; i++){
		f[i]=i;
		cin>>c[i];
		vl[i]=c[i];
	}
	for (int i=1; i<=m; i++){
		int u,v,w;
		cin>>u>>v;
		w=i;
		int fu=ff(u);
		int fv=ff(v);
		if (fu==fv){
			p[++cnt]={u,v,w};
			continue;
		} 
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		f[fu]=fv;
	}
	dfs(1,0);
	if (abs(vl[1])&1){
		return cout<<"NO\n",0;
	}
	if (vl[1]==0){
		cout<<"YES\n";
		for (int i=1; i<=m; i++){
			cout<<ans[i]<<"\n";
		}
		return 0;
	}
	for (int i=1; i<=cnt; i++){
		int u=p[i].x,v=p[i].y,w=p[i].z;
		int lc=lca(u,v);
		ll val=dep[u]+dep[v]-2*dep[lc]+1;
		if (val%2!=0){
			ll it=vl[1]/2;
			for (int j=1; j<=n; j++){
				vl[j]=c[j];
			}
			for (int j=1; j<=m; j++){
				ans[j]=0;
			}
			vl[u]-=it,vl[v]-=it,ans[w]=it;
			dfs(1,0);
			if (vl[1]!=0){
				for (int j=1; j<=n; j++){
					vl[j]=c[j];
				}
				for (int j=1; j<=m; j++){
					ans[j]=0;
				}
				vl[u]+=it,vl[v]+=it,ans[w]=-it;
				dfs(1,0);
			}
			cout<<"YES\n";
			for (int j=1; j<=m; j++){
				cout<<ans[j]<<"\n";
			}
			return 0;
		} 
	}
	cout<<"NO\n";
	return 0;
}
