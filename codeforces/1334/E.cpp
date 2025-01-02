// LUOGU_RID: 159819484
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int mod=998244353;
ll d,u,v,g,p[30],cnt[30],fac[55],inv[55];
int q,tot;
int Pow(int x,int y){
	int res=1;
	for(;y;y>>=1,x=1ll*x*x%mod)
		if(y&1)
			res=1ll*res*x%mod;
	return res;
}
ll getp(ll v){
	ll res,ret=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=tot;i++)
		while(!(v%p[i]))
			v/=p[i],cnt[i]++,ret++;
	res=fac[ret];
//	cout<<ret<<' '<<res<<'\n';
	for(int i=1;i<=tot;i++)
		res=res*inv[cnt[i]]%mod;
	return res;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>d>>q,fac[0]=inv[0]=1;
	for(int i=1;i<50;i++) fac[i]=fac[i-1]*i%mod;
//	cout<<fac[6]<<endl;
	inv[49]=Pow(fac[49],mod-2);
	for(int i=48;i;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	for(ll i=2;i*i<=d;i++)
		if(!(d%i)){
			p[++tot]=i;
			while(!(d%i)) d/=i;
		}
	if(d>1) p[++tot]=d;
//	cout<<tot<<'\n';
	while(q--)
		cin>>u>>v,g=__gcd(u,v),cout<<getp(u/g)*getp(v/g)%mod<<'\n';
	return 0;
}
