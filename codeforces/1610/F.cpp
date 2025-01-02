// LUOGU_RID: 158569093
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MAXN=300001;
int n,m,k;
int x[MAXN],y[MAXN];
int a[MAXN],b[MAXN];
vector<pii> g[MAXN*2];
bool vis[MAXN*2];
int s[MAXN*2];
void dfs(int u){
	vis[u]=1;
	while(g[u].size()){
		pii x=g[u].back();
		g[u].pop_back();
		int v=x.first,d=x.second;
		if(s[d])continue;
		s[d]=u;
		dfs(v);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int w;
		cin>>x[i]>>y[i]>>w;
		if(w==1){
			a[x[i]]++,a[y[i]]++;
			g[x[i]].emplace_back(y[i],i);
			g[y[i]].emplace_back(x[i],i);
		}
		else{
			b[x[i]]++,b[y[i]]++;
			g[x[i]+n].emplace_back(y[i]+n,i);
			g[y[i]+n].emplace_back(x[i]+n,i);
		}
	}
	k=m;
	int ans=0;
	for(int i=1;i<=n;i++){
		if((a[i]&1)&&(b[i]&1)){
			g[i].emplace_back(i+n,++k);
			g[i+n].emplace_back(i,k);
			ans++;
		}
		else if(a[i]&1){
			g[i].emplace_back(n+n+1,++k);
			g[n+n+1].emplace_back(i,k);
			ans++;
		}
		else if(b[i]&1){
			g[i+n].emplace_back(n+n+1,++k);
			g[n+n+1].emplace_back(i+n,k);
		}
	}
	for(int i=1;i<=2*n+1;i++)if(!vis[i])dfs(i);
	cout<<ans<<'\n';
	for(int i=1;i<=m;i++)cout<<(s[i]==x[i]||s[i]==x[i]+n?1:2);
	return 0;
}