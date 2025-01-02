// LUOGU_RID: 160437521
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;
int n,k;
int fact[N],infact[N];
int f[N],p[N];
int qmi(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int C(int x,int y){
	if(x<y)return 0;
	return fact[x]*infact[y]%mod*infact[x-y]%mod;
}
void init(){
	fact[0]=1;
	for(int i=1;i<N;i++)fact[i]=fact[i-1]*i%mod;
	infact[N-1]=qmi(fact[N-1],mod-2);
	for(int i=N-2;i>=0;i--)infact[i]=infact[i+1]*(i+1)%mod;
}
void solve(){
	cin>>n>>k;
	f[0]=p[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=fact[i]*C(n-(i-1)*(k-1),i)%mod;
		p[i]=p[i-1]*f[i]%mod*qmi(f[i-1]*(n-i+1)%mod,mod-2)%mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=f[i-1]*(n-i+1)%mod;
		ans=(ans+(p[i-1]*(sum-f[i]+mod)%mod)%mod*qmi(sum,mod-2)%mod*i%mod)%mod;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	int Case;
	cin>>Case;
	while(Case--)solve();
}