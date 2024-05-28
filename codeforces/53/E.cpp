// LUOGU_RID: 160148718
#include<iostream>
#define int long long
using namespace std;
const int N=10;
int n,m,k,ans,tot,f[1<<N][1<<N],g[N][N];
inline int count(int x){return __builtin_popcount(x);}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k,tot=(1<<n)-1;
	for(int i=1,u,v;i<=m;++i)
		cin>>u>>v,--u,--v,g[u][v]=g[v][u]=1,f[(1<<u)|(1<<v)][(1<<u)|(1<<v)]=2;
	for(int S=1;S<=tot;++S)
		for(int T=S;T;T=(T-1)&S){
			f[S][T]/=count(T);
			for(int i=0;i<n;++i)
				if(S>>i&1){
					int t=T&(tot^(1<<i));
					for(int j=0;j<n;++j)
						if(!(S>>j&1)&&g[i][j]) f[S|1<<j][t|1<<j]+=f[S][T];
				}
		}
	for(int S=1;S<=tot;++S) ans+=f[tot][S]*(count(S)==k);
	cout<<ans<<"\n";
}