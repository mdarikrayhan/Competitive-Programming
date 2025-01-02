#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=19;
int n,a[N],b[N],pct[1<<N];
ll fc[N],F[1<<N],f[1<<N],G[1<<N],g[1<<N][N],v[N][1<<N],ff[1<<N];
string s[N];
vector<int>c[N];
void fwt(ll*a,int op){for(int i=1;i<1<<n;i<<=1)for(int j=0;j<1<<n;j+=i<<1)for(int k=0;k<i;k++)a[i+j+k]+=op*a[j+k];}
void Add(int x,int ns,int p,ll v) {
	if(x==n)return F[ns-(1<<n-1)]+=v,void();
	if(n-x>p)Add(x+1,ns|1<<x,p,v);
	for(int i=2;i<=p;i++)if(b[i])b[i]--,Add(x+i,ns|1<<x+i-1,p-i,v),b[i]++;
} 
void calc(int m,int now) {
	for(int i=0;i<1<<n;i++)ff[i]=f[i];fwt(ff,-1);
	ll vv=0;for(int i:c[now])vv+=ff[i];
	for(int i=0;i<=n;i++)b[i]=0; 
	for(int i=1;i<=m;i++)b[a[i]]++;
	if(vv)Add(0,0,now,vv*fc[n-now]);
}
int ct=0;
void dfs(int x,int s) {
	calc(x-1,s);
	for(int o=max(a[x-1],2);o<=n-s;o++) {
		vector<ll>lf(f,f+(1<<n));
		for(int i=0;i<1<<n;i++)f[i]*=v[o][i];
		a[x]=o,dfs(x+1,s+o);
		for(int i=0;i<1<<n;i++)f[i]=lf[i];
	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n,fc[0]=1,g[0][0]=f[0]=1;
	for(int i=0;i<n;i++)cin>>s[i],fc[i+1]=fc[i]*(i+1);
	for(int i=0;i<1<<n;i++)pct[i]=__builtin_popcount(i),c[pct[i]].push_back(i);
	for(int i=0;i<n;i++)g[1<<i][i]=1;
	for(int i=1;i<1<<n;i++)for(int j=0;j<n;j++)if(g[i][j])
		for(int k=0;k<n;k++)if((i>>k&1^1)&&s[j][k]=='0')g[i|1<<k][k]+=g[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<1<<n;j++)G[j]+=g[j][i];
	for(int i=0;i<1<<n;i++)v[pct[i]][i]=G[i];
	for(int i=0;i<=n;i++)fwt(v[i],1);
	memcpy(f,v[0],sizeof(f)),dfs(1,0);
	for(int i=0;i<n-1;i++)for(int j=0;j<1<<n-1;j++)if(j>>i&1)F[j]-=F[j^(1<<i)];
	for(int i=0;i<1<<n-1;i++)cout<<F[i]<<' ';
	return 0;
}