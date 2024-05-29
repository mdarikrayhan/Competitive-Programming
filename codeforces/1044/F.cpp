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

ct int N=200500;
class Seg{
	int d[4*N],tg[4*N],n;
#define L (p<<1)
#define R (L|1)
	void upd(int p,int x){
		tg[p]+=x,d[p]=tg[p]?0:(p<n?d[L]+d[R]:1);
	}
	void up(int p){d[p]=tg[p]?0:d[L]+d[R];}
	int LCA(int u,int v){return u>>(1+__lg(u^v));}
public:
	void build(int n_){
		n=1<<__lg(2*n_+3);
		F(i,0,n-1)tg[n+i]=1,d[n+i]=0;
		F(i,1,n_)tg[n+i]=0,d[n+i]=1;
		G(i,n-1,1)up(i);
	}
	void upd(int l,int r,int x){
		int p=LCA(l+=n-1,r+=n+1);
		for(;(l>>1)!=p;up(l>>=1))if(!(l&1))upd(l^1,x);
		for(;(r>>1)!=p;up(r>>=1))if(  r&1 )upd(r^1,x);
		for(;p;p>>=1)up(p);
	}
	int qry(){return d[1];}
};
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
struct HshF{
	size_t operator()(pair<int,int>p)ct{
		u64 x=(u64)p.fi<<32ull^(u64)p.se;
		return 
			((x*519783756475618931ull+456782316483241983ull)>>16ull)
			^((x*167349281546781927ull+681673154976281349ull)<<16ull);
	}
};
template<class A,class B>
using Hmp=gp_hash_table<A,B,HshF>;
//using Hmp=map<A,B>;
int n,m,l[N],r[N],tim;
Hmp<pair<int,int>,bool>mp;
vector<int>t[N];
vector<pair<int,int>>ch[N];
Seg seg;
void dfs(int u,int fa){
	l[u]=++tim;
	for(int v:t[u])if(v!=fa)
		dfs(v,u),ch[u].pb(mkr(r[v],v));
	r[u]=tim;
}
void upd(int u,int v,int x){
	if(l[u]>l[v])swap(u,v);
	if(r[u]<r[v]){
		seg.upd(1,l[u]-1,x);
		seg.upd(r[u]+1,l[v]-1,x);
		seg.upd(r[v]+1,n,x);
	}else{
		int p=lower_bound(ch[u].begin(),ch[u].end(),mkr(l[v],0))->se;
		seg.upd(l[p],l[v]-1,x);
		seg.upd(r[v]+1,r[p],x);
	}
}
int main(){
#ifdef LOCAL
	freopen("1044F.in","r",stdin);
//	freopen(".out","w",stdout);
#endif
	rd(n),rd(m);
	F(i,2,n){
		int u,v;rd(u),rd(v);
		t[u].pb(v),t[v].pb(u);
	}
	dfs(1,0),seg.build(n);
	while(m--){
		int u,v;rd(u),rd(v);
		if(u>v)swap(u,v);
		auto&p=mp[mkr(u,v)];
		upd(u,v,p?-1:1),p^=1,printf("%d\n",seg.qry());
	}
}

