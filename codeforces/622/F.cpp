// LUOGU_RID: 160271211
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+7;
#define int long long
int a[maxn];
const int mod=1e9+7;
int qbow(int x,int k){
	int ans=1;
	while(k){
		if(k&1)ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
int fac[maxn],inv[maxn];
signed main(){
	int n,k,ans=0,p=1;
	cin>>n>>k;fac[0]=1;
	if(n<=k+2){
		int ans=0;
		for(int i=1;i<=n;i++)ans=(ans+qbow(i,k))%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k+2;i++)a[i]=(a[i-1]+qbow(i,k))%mod;
	for(int i=1;i<=k+2;i++)fac[i]=fac[i-1]*i%mod;
	fac[k+2]=qbow(fac[k+2],mod-2);
	for(int i=k+1;i>=1;i--)fac[i]=fac[i+1]*(i+1)%mod;
	for(int i=1;i<=k+2;i++)p=p*(n%mod-i+mod)%mod,inv[i]=qbow((n%mod-i+mod)%mod,mod-2);
	//int ans=0;
	//cout<<p<<endl;
	for(int i=1,f;i<=k+2;i++){
		if((k+2-i)&1)f=-1;
		else f=1;
		//cout<<a[i]<<" "<<f<<" "<<endl;
		ans=(ans+a[i]*inv[i]%mod*f%mod*fac[i-1]%mod*fac[k+2-i]%mod+mod)%mod;
		//cout<<ans<<endl;
	}
	cout<<ans*p%mod;
	return 0;
}