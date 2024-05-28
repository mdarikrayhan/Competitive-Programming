#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
const int N=100100,M=1010;
int f1[M],a[N],n,k,cnt,f[N][M],g[M][M],cet[M][M];
vector<int>b[N],vec,d[M],p[M];
inline void dfs(int x,int fa){
	for(auto v:b[x]){
		if(v==fa) continue;
		dfs(v,x);memset(f1,0x3f,sizeof(int)*(vec.size()));
		for(int i=0;i<vec.size();++i) for(int j=0;j<vec.size();++j) f1[g[i][j]]=min(f1[g[i][j]],f[x][i]+f[v][j]);
		for(int i=0;i<vec.size();++i)f[x][i]=f1[i];
	}
	if(x!=1){
		for(int i=vec.size()-1;~i;--i) for(int j=i+1;j<vec.size();++j) if(cet[i][j])f[x][j]=min(f[x][j],f[x][i]+cet[i][j]);
	}
}
inline void solve(){
	cin>>n>>k;--k;int u,v;vec.clear();
	for(int i=1;i<=n;++i)cin>>a[i],a[i]=__gcd(a[i],a[1]),b[i].clear();
	for(int i=1;i<n;++i)cin>>u>>v,b[u].push_back(v),b[v].push_back(u);
	if(k<0)return cout<<a[1]<<'\n',void();
	for(int i=1;i<=a[1];++i) if(a[1]%i==0) vec.push_back(i);
	for(int i=0;i<vec.size();++i) for(int j=0;j<vec.size();++j) g[i][j]=lower_bound(all(vec),__gcd(vec[i],vec[j]))-vec.begin();
	for(int i=0;i<vec.size();++i){
		d[i].clear();p[i].clear();int y=vec[i];
		for(int j=2;j*j<=y;++j){
			if(y%j==0)d[i].push_back(j),p[i].push_back(0);
			while(y%j==0)y/=j,++p[i][d[i].size()-1];
		}
		if(y^1)d[i].push_back(y),p[i].push_back(0),++p[i][d[i].size()-1];
	}
	for(int i=0;i<vec.size();++i){
		for(int j=i+1;j<vec.size();++j){
			if(d[i]==d[j]){
				int Max=1;
				for(int k=0;k<d[i].size();++k) Max=max(Max,(p[j][k]-p[i][k]+p[i][k]-1)/p[i][k]);
				if(Max>1)cet[i][j]=0;
				else cet[i][j]=Max;
			}
			else cet[i][j]=0;
		}
	}
	for(int i=1;i<=n;++i){
		memset(f[i],0x3f,sizeof(int)*(vec.size()));
		a[i]=lower_bound(all(vec),a[i])-vec.begin();
		f[i][a[i]]=0;
	}
	dfs(1,0);
	for(int i=a[1];i;--i)if(f[1][i]<=k)return cout<<vec[a[1]]*vec[i]<<'\n',void();
	return cout<<vec[a[1]]<<'\n',void();
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}