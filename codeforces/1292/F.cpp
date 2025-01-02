// LUOGU_RID: 160040397
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=65,mod=1e9+7;
int n,m,a[N],fa[N],v[N];
ll ans=1,f[N][1<<11],s[1<<11],fc[N],inv[N];
bool ok[N];
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
ll qp(ll a,int b){ll ans=1;for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;return ans;}
void Add(ll&x,ll y){x=(x+y)%mod;}
void init(int n) {
	fc[0]=1;for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
	inv[n]=qp(fc[n],mod-2);
	for(int i=n-1;~i;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n,iota(fa+1,fa+n+1,1),init(n);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&a[i]%a[j]==0)fa[gf(i)]=gf(j),ok[i]=1;
	for(int o=1;o<=n;o++)if(gf(o)==o) {
		vector<int>c,d;
		for(int i=1;i<=n;i++)if(gf(i)==o)c.push_back(i);
		if(c.size()==1)continue;
		for(int i:c)if(!ok[i])d.push_back(i);
		int k=d.size(),vv=c.size()-k-1;
		for(int i=0;i<1<<k;s[i]=0,i++)for(int j=0;j<=vv;j++)f[j][i]=0;
		for(int i:c)for(int j=0;j<k;j++)if(a[i]%a[d[j]]==0)v[i]|=1<<j;
		for(int i:c)if(ok[i])f[0][v[i]]++,s[v[i]]++;
		for(int i=0;i<k;i++)for(int j=0;j<1<<k;j++)if(j>>i&1)s[j]+=s[j^(1<<i)];
		for(int i=0;i<vv;i++)for(int j=0;j<1<<k;j++)if(f[i][j]) {
			if(i+1<s[j])Add(f[i+1][j],f[i][j]*(s[j]-i-1));
			for(int l:c)if(ok[l]&&(v[l]&j)&&(v[l]|j)>j)Add(f[i+1][j|v[l]],f[i][j]);
		}
		m+=vv,ans=ans*inv[vv]%mod*f[vv][(1<<k)-1]%mod;
	}cout<<ans*fc[m]%mod<<'\n';
	return 0;
}