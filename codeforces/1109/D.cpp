// LUOGU_RID: 159488373
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int MOD=1e9+7;

int fac[N],invfac[N];

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
	fac[0]=1;
	for(int i=1;i<N;++i)fac[i]=1ll*fac[i-1]*i%MOD;
	invfac[N-1]=powM(fac[N-1]);
	for(int i=N-2;i>=0;--i)invfac[i]=1ll*invfac[i+1]*(i+1)%MOD;
}

int C(int n,int m,int mod=MOD){
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}

int A(int n,int m,int mod=MOD){
	if(n<0||m<0||n<m)return 0;
	return 1ll*fac[n]*invfac[n-m]%mod;
}

int pn[N],pm[N];

void llz(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	pn[0]=pm[0]=1;
	for(int i=1;i<=n;++i)pn[i]=pn[i-1]*n%MOD,pm[i]=1ll*pm[i-1]*m%MOD;
	int ans=0;
	for(int i=1;i<n;++i){
		if(i==n-1)ans=(ans+1ll*C(m-1,i-1)*fac[n-2]%MOD)%MOD;
		else ans=(ans+1ll*A(n-2,i-1)*C(m-1,i-1)%MOD*(i+1)%MOD*pn[n-i-2]%MOD*pm[n-1-i]%MOD)%MOD;
	}
	cout<<ans<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ini();
	int T=1;
	while(T--)llz();
	return 0;
}