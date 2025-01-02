#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=114;
const int MOD=998244353;

int l[N],r[N],f[N][N],g[N],inv[N];
vector<int> ord;

int powM(int a,int b=MOD-2,int mod=MOD){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}

void llz(){
	int n;
	cin>>n;
	int mul=1;
	for(int i=1;i<=n;++i){
		cin>>l[i]>>r[i];
		mul=1ll*mul*(r[i]-l[i]+1)%MOD;
		ord.push_back(l[i]),ord.push_back(++r[i]);
	}
	sort(ord.begin(),ord.end());
	ord.erase(unique(ord.begin(),ord.end()),ord.end());
	int tot=ord.size();
	for(int i=1;i<=n;++i){
		l[i]=lower_bound(ord.begin(),ord.end(),l[i])-ord.begin()+1;
		r[i]=lower_bound(ord.begin(),ord.end(),r[i])-ord.begin()+1;
	}
	for(int i=1;i<=tot;++i)f[0][i]=1;
	for(int i=1;i<=n;++i){
		for(int j=l[i];j<r[i];++j){
			int len=ord[j]-ord[j-1];
			g[0]=1;
			for(int x=1;x<=n;++x)g[x]=1ll*g[x-1]*(x+len-1)%MOD*inv[x]%MOD;
			for(int k=i-1;k>=0;--k){
				f[i][j]=(f[i][j]+1ll*f[k][j+1]*g[i-k]%MOD)%MOD;
				if(j<l[k]||j>=r[k])break;
			}
		}
		for(int j=tot-1;j>=1;--j)f[i][j]=(f[i][j]+f[i][j+1])%MOD;
	}
	int ans=f[n][1];
	cout<<1ll*ans*powM(mul)%MOD<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	inv[1]=1;
	for(int i=2;i<N;++i)inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	int T=1;
	while(T--)llz();
	return 0;
}