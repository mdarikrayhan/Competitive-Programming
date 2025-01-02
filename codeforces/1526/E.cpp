// LUOGU_RID: 160049618
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
const int mod=998244353;
int n,m;
int sa[N],rk[N];
int fact[N],infact[N];
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
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>sa[i],sa[i]++,rk[sa[i]]=i;
	int cnt=0;
	for(int i=1;i<n;i++)cnt+=(rk[sa[i]+1]<rk[sa[i+1]+1]);
	int ans=0;
	for(int i=0;i<=cnt;i++)ans=(ans+C(cnt,i)*C(m,n-i)%mod)%mod;
	cout<<ans<<'\n';
}