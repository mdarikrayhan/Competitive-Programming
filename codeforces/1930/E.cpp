// LUOGU_RID: 160424513
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int MOD=998244353;

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
	return fac[n]*invfac[n-m]%mod*invfac[m]%mod;
}

void llz(){
	int n;
	cin>>n;
	for(int k=1;k<=(n-1)/2;++k){
		int ans=1;
		for(int x=1;2*k*x<=n;++x){
			ans=(ans+C(n,2*k*x)-C(n-2*k*(x-1)-1,2*k-1))%MOD;
		}
		if(ans<0)ans+=MOD;
		cout<<ans<<" ";
	}
	cout<<"\n";
}

signed main(){
	iostream::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	ini();
	cin>>T;
	while(T--)llz();
	return 0;
}