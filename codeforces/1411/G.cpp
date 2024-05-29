// LUOGU_RID: 156925677
// 2024 HOPE IN VALUABLE
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int M=1024;
const int mod=998244353;
inline int qpow(int x,int y=mod-2){
	int r=1; while(y){
		if(y&1) r=1ll*r*x%mod;
		x=1ll*x*x%mod; y>>=1;
	}	return r;
}
int n,m,nn,ans,deg[N],vis[N],sg[N],cnt[N],f[M][M],g[M]; vector<int>e[N],rev[N]; queue<int>q;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){ int u,v; cin>>u>>v; e[u].emplace_back(v); rev[v].emplace_back(u); deg[u]++; }
	for(int i=1;i<=n;i++) if(!deg[i]) q.emplace(i);
	while(!q.empty()){
		int u=q.front(); q.pop(); sg[u]=0;
		for(int v:e[u]) vis[sg[v]]=u;
		while(vis[sg[u]]==u) sg[u]++;
		for(int v:rev[u]) if(!--deg[v]) q.emplace(v);
	}
	for(int i=1;i<=n;i++) cnt[sg[i]]++,nn=max(nn,sg[i]); nn++; while(__builtin_popcount(nn)!=1) nn++; nn--;
	for(int i=0;i<=nn;i++) f[0][i]=1; g[0]=1;
	for(int i=1,inv=qpow(n+1);i<=nn;i++){
		for(int j=0;j<=nn;j++) f[i][j]=mod-1ll*cnt[i^j]*inv%mod;
		f[i][i]++;
	}
	for(int i=0;i<=nn;i++){
		if(!f[i][i]){
			int ok=0;
			for(int j=i+1;j<=nn;j++)
				if(f[j][i]){
					for(int k=i;k<=nn;k++) swap(f[i][k],f[j][k]);
					ok=1;
					break;
				}
		}
		for(int j=i+1,inv=qpow(f[i][i]);j<=nn;j++){
			int delta=1ll*f[j][i]*inv%mod;
			for(int k=i;k<=nn;k++) f[j][k]=(f[j][k]-1ll*delta*f[i][k]%mod+mod)%mod;
			g[j]=(g[j]-1ll*delta*g[i]%mod+mod)%mod;
		}
	}
	for(int i=nn;~i;i--){
		for(int j=i+1;j<=nn;j++) g[i]=(g[i]-1ll*f[i][j]*g[j]%mod+mod)%mod;
		g[i]=1ll*g[i]*qpow(f[i][i])%mod;
	}
	ans=(1-g[0]+mod)%mod;
	cout<<ans<<'\n';
	return 0;
}