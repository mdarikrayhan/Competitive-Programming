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

ct int N=100500;
int n,m,cnt[N],b[N];
char s[N],t[N];
int main(){
#ifdef LOCAL
	freopen("1090J.in","r",stdin);
//	freopen(".out","w",stdout);
#endif
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for(int i=2,j=0;i<=m;++i){
		while(j&&t[j+1]!=t[i])j=b[j];
		b[i]=(j+=(t[j+1]==t[i]));
	}
	for(int i=2,j=0;i<=n;++i){
		while(j&&t[j+1]!=s[i])j=b[j];
		++cnt[j+=(t[j+1]==s[i])],(j==m?j=b[j]:0);
	}
	G(i,m,1)cnt[b[i]]+=cnt[i];
	ll ans=0;
	F(i,1,m)ans+=n-(b[i]?cnt[i-b[i]]:0);
	printf("%lld\n",ans);
}

