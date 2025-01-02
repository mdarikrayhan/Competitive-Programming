// LUOGU_RID: 158544463
#include<bits/stdc++.h>
#define ll long long
#define mxn 16384
#define md 998244353
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define rept(i,a,b) for(int i=a;i<b;++i)
#define drep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
ll power(ll x,int y){
	ll ans=1;
	for(;y;y>>=1){
		if(y&1)ans=ans*x%md;
		x=x*x%md;
	}
	return ans;
}
int n,a,b,k,s,sm,rev[mxn];
ll ans,f[mxn],g[mxn],f1[mxn],fac[200003],ifac[200003];
void ntt(ll *a,int n,int flag){
	rept(i,0,n)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int h=1;h<n;h<<=1){
		ll x,y,s=power(3,499122176/h);
		for(int j=0;j<n;j+=h<<1){
			ll w=1;
			for(int k=j;k<j+h;++k){
				x=a[k],y=w*a[k+h]%md;
				a[k]=(x+y)%md;
				a[k+h]=(x-y+md)%md;
				w=w*s%md;
			}
		}
	}
	if(flag==-1){
		ll p=power(n,md-2);
		reverse(a+1,a+n);
		rept(i,0,n)a[i]=a[i]*p%md;
	}
}
void init(int n){
	fac[0]=1;
	rep(i,1,n)fac[i]=fac[i-1]*i%md;
	ifac[n]=power(fac[n],md-2);
	drep(i,n,1)ifac[i-1]=ifac[i]*i%md; 
}
ll C(int n,int m){
	if(m<0||m>n)return 0;
	return fac[n]*ifac[m]%md*ifac[n-m]%md;
}
signed main(){
	init(2e5); 
	cin>>n;
	sm=1,f[1]=1;
	while(n--){
		cin>>a>>b;
		for(k=0,s=1;s<sm+(sm+a-b)+sm;s<<=1,++k);
		rept(i,0,s)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
		rept(i,0,s)g[i]=0;
		rep(k,1-sm,sm+a-b-1){
			g[k+sm]=C(a+b,b+k);
		}
		ntt(g,s,1);
		ntt(f,s,1);
		rept(i,0,s)f1[i]=f[i]*g[i]%md;
		ntt(f1,s,-1);
		f[0]=0;
		rep(i,1,sm+a-b)f[i]=f1[i+sm];
		rept(i,sm+a-b+1,s)f[i]=0;
		sm+=a-b;
	}
	rep(i,1,sm)ans=(ans+f[i])%md;
	cout<<ans;
	return 0;
}