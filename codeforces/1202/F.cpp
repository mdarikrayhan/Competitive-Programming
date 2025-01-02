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

ll a,b,n,ans;
int main(){
#ifdef LOCAL
	freopen("1202F.in","r",stdin);
//	freopen(".out","w",stdout);
#endif
	rd(a),rd(b),n=a+b;
	if(!a||!b)puts("1"),exit(0);
	for(ll l=1,r,m;l<=n;l=r+1){
		m=n/l,r=n/m;
		ll i,s,p,q;
		s=a/m,i=a-s*m;
		if(s-i<0)continue;
		q=(n-i)/m;
		if(s-i>(m+1)*q-n)continue;
		s=(a+m)/(m+1),i=a-s*m,p=(s-i+n+m)/(m+1);
		ans+=max(0ll,min(r,q)-max(l,p)+1);
	}
	printf("%lld\n",ans);
}

