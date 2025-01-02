// LUOGU_RID: 160006667
#include<bits/stdc++.h>
using namespace std;
const int N=1003;
const int M=50;
const int MOD=1e9+7;

int f[N][M][N];
int fac[N<<1],invfac[N<<1];

int powM(int a,int b=MOD-2,int mod=MOD){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}

void ini(){
	int n=1000;
	int lim=2*n;
	fac[0]=1;
	for(int i=1;i<=lim;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	invfac[lim]=powM(fac[lim]);
	for(int i=lim-1;i>=0;--i)invfac[i]=1ll*invfac[i+1]*(i+1)%MOD;
	f[0][0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;1ll*j*(j+1)/2<=n;++j){
			for(int k=j*(j+1)/2;k<=n;++k){
				f[i][j][k]=f[i-1][j][k];
				if(j-1>=0&&k-i>=0)f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k-i])%MOD;
			}
		}
	}
}

void llz(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	if(1ll*k*(k+1)/2>n){
		cout<<0<<"\n";
		return;
	}
	for(int i=k*(k+1)/2;i<=n;++i){
		ans=(ans+1ll*f[n][k][i]*fac[n-i+k]%MOD*invfac[n-i]%MOD)%MOD;
	}
	cout<<ans<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>T;
	ini();
	while(T--)llz();
	return 0;
}