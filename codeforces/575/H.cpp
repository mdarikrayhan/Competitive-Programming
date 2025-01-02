// LUOGU_RID: 160415925
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll n,ans,fac[2000005]; 
template<typename T>
ll qpow(T a,int b){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll C(int n,int k){
	ll res=fac[n]*qpow(fac[n-k],mod-2)%mod;
	res=res*qpow(fac[k],mod-2)%mod;
	return res;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=2000000;i++)fac[i]=fac[i-1]*i%mod;
	cin>>n;
	ans=(qpow(2ll,2*n+1)-1+mod)%mod;
	for(int i=n+1;i<=2*n;i++)
		ans=(ans-C(i-1,n)*(qpow(2ll,2*n-i+1)-1+mod)*2%mod+mod)%mod;
	cout<<ans;
	return 0;
}