#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using u64=unsigned long long;
using lf=long double;
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

ct ll N=200500,M=1e6,K=15;
int n,m,na,nb;
ll X,Y,Z,p[K];
struct D{int S;ll x;}a[N],b[N];
ll calc(D*a,int n1,D*b,int n2){
//	CUT;
//	F(i,1,n1)dbg("%d ",a[i].S);
//	dbg("\n");
//	F(i,1,n2)dbg("%d ",b[i].S);
//	dbg("\n");
//	CUT;
	ll s[(1<<K)|50]{},ret=0;
	F(i,1,n1)++s[a[i].S];
	F(i,0,m-1)F(j,0,(1<<i)-1)F(k,0,(1<<(m-i-1))-1){
		int x=j|(k<<(i+1));s[x|(1<<i)]+=s[x];
	}
	F(i,1,n2)ret+=s[((1<<m)-1)^b[i].S];
	return ret;
}
D f(ll x){
	int S=0;
	F(i,0,m-1)S|=(x%p[i]==0)<<i;
	return D{S,__gcd(x,Z)};
}
int main(){
#ifdef LOCAL
	freopen("1016G.in","r",stdin);
//	freopen(".out","w",stdout);
#endif
	rd(n),rd(X),rd(Y);
	if(Y%X)puts("0"),exit(0);
	Z=Y/X;
	F(i,2,M)if(Z%i==0){
		p[m++]=i;
		while(Z%i==0)Z/=i;
	}
	while(n--){
		ll v;rd(v);
		if(v%X==0)a[++na]=f(v/X);
		if(Y%v==0)b[++nb]=f(Y/v);
	}
	sort(a+1,a+na+1,[&](D x,D y){return x.x<y.x;});
	sort(b+1,b+nb+1,[&](D x,D y){return x.x<y.x;});
	ll ans=0;
	for(int l1=1,r1;l1<=na;l1=r1){
		for(r1=l1;r1<=na&&a[r1].x==a[l1].x;++r1);
		for(int l2=1,r2;l2<=nb;l2=r2){
			for(r2=l2;r2<=nb&&b[r2].x==b[l2].x;++r2);
			if(__gcd(a[l1].x,b[l2].x)==1)
				ans+=calc(a+l1-1,r1-l1,b+l2-1,r2-l2);
		}
	}
	printf("%lld\n",ans);
}

