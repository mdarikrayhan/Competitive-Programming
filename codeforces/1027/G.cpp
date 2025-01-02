// LUOGU_RID: 159485047
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using u64=unsigned long long;
using lf=long double;
using lll=__int128;
#define F(i,l,r) for(int i=l;i<=r;++i)
#define G(i,r,l) for(int i=r;i>=l;--i)
#define ct const
#define il inline
#define pb push_back
#define fi first
#define se second
#define mkr make_pair
template<class T>
il void tomn(T&x,T ct&y){y<x?x=y,0:0;}
template<class T>
il void tomx(T&x,T ct&y){x<y?x=y,0:0;}
#define DEBUG(x) cerr<<"line:"<<__LINE__<<" "#x"="<<x<<endl
#define CUT cerr<<"**********\n"
#define dbg(...) fprintf(stderr,__VA_ARGS__)
ct lf EPS=1e-10L;
il int dcmp(lf x){return fabs(x)<=EPS?0:(x<0?-1:1);}
ct ll INF=4e18L;
//ct int INF=1.02e9;
il void rd(int&x){scanf("%d",&x);}
il void rd(ll&x){scanf("%lld",&x);}

il u64 mul(u64 x,u64 y,u64 z){
//	u64 d=1.L*x*y/z,r=x*y-d*z;
//	r=(r+z)%z;
//	return r;
	return (lll)x*y%z;
}
il ll qpow(ll x,ll y,ll n){
	ll r=1;
	for(;y;y>>=1)y&1?(r=mul(r,x,n),0):0,x=mul(x,x,n);
	return r;
}
ll calc(ll n,ll p,ll m){
	ll phi=n/p*(p-1);
	m%=n;
	auto ck=[&](ll pw,ll p){
		pw=phi/pw;
		ll i=qpow(m,pw,n),r=1;
		while(i!=1)i=qpow(i,p,n),r*=p;
		return r;
	};
	ll x=phi,ret=1;
	for(ll y=2;y*y<=x;++y)if(x%y==0){
		ll pw=1;
		while(x%y==0)x/=y,pw*=y;
		ret*=ck(pw,y);
	}
	if(x!=1)ret*=ck(x,x);
	return phi/ret;
}
il ll lcm(ll x,ll y){return x/__gcd(x,y)*y;}
ll n,m,ans;
struct D{ll p,q,r;};vector<D>d;
il ll sol2(ll n,ll m){
	m%=n;
	if(n==1)return 1;
	if(m==1)return 1;
	if(m==n-1)return 2;
	m=(m+1)/4,m=(m&-m);
	return n/(4*m);
}
void dfs(int i,ll l,ll phi){
	if(i==(int)d.size())return ans+=phi/l,void();
	D x=d[i];ll p=x.p,q=x.q,r=x.r;
	for(ll j=0,k=1;j<=q;++j,k*=(j<=q?p:1)){
		if(p==2){
			ll tmp=(k==1?k:k/2);
			dfs(i+1,lcm(l,sol2(k,m)),phi*tmp);
		}else{
			ll tmp=(k==1?k:k/p*(p-1));
			dfs(i+1,lcm(l,tmp/__gcd(tmp,r)),phi*tmp);
		}
	}
}
int main(){
#ifdef LOCAL
	freopen("1027G.in","r",stdin);
//	freopen(".out","w",stdout);
#endif
	rd(n),rd(m);
	ll x=n;
	for(ll y=2;y*y<=x;++y)if(x%y==0){
		ll pw=1,cnt=0;
		while(x%y==0)x/=y,pw*=y,++cnt;
		d.pb(D{y,cnt,calc(pw,y,m)});
	}
	if(x!=1)d.pb(D{x,1,calc(x,x,m)});
	dfs(0,1,1),printf("%lld\n",ans);
}
