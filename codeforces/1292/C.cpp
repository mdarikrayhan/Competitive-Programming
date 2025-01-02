// LUOGU_RID: 158954080
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3005;

int h[N],nex[N<<1],to[N<<1],tot;

void add(int u,int v){
	to[tot]=v;
	nex[tot]=h[u];
	h[u]=tot++;
}

int siz[N][N],fa[N][N];

void ini(int u,int f,int r){
	siz[r][u]=1;
	fa[r][u]=f;
	for(int i=h[u];~i;i=nex[i]){
		int v=to[i];
		if(v==f)continue;
		ini(v,u,r);
		siz[r][u]+=siz[r][v];
	}
}

int f[N][N];

int dfs(int u,int v){
	if(u==v)return 0;
	if(f[u][v])return f[u][v];
	return f[u][v]=max(dfs(fa[v][u],v),dfs(u,fa[u][v]))+siz[u][v]*siz[v][u];
}

void llz(){
	int n;
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;++i)ini(i,0,i);
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)ans=max(ans,dfs(i,j));
	}
	cout<<ans<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	while(T--)llz();
	return 0;
}