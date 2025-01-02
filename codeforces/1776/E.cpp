#include<bits/stdc++.h>
#define Gc() getchar() 
#define Me(x,y) memset(x,y,sizeof(x))
#define Mc(x,y) memcpy(x,y,sizeof(x))
#define d(x,y) ((m)*(x-1)+(y))
#define R(n) (rnd()%(n)+1)
#define Pc(x) putchar(x)
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define fi first
#define se second
using ll=long long;using db=double;using lb=long db;using ui=unsigned;using ull=unsigned long long;
using namespace std;const int N=500+5,M=N*N*4+5,K=39916800,mod=1e9+7,Mod=mod-1;const db eps=1e-9;const int INF=1e9+7;mt19937 rnd(time(0));
int n,m,r,f[M],g[M];ll v,s,a,b;vector<pair<ll,ll> > S[N];
pair<int,ll> A[N*3];int Ah;
struct Line{
	ll k,b;
	ll calc(int x){return x*k+b;}
}B[M];int Bh;
struct Node{
	ll x,y,id,op;
}C[M];
int Init(Line x,int y){
	ll p=x.calc(y);if(p<0||p>s) return 1;
	auto i=LB(S[y].begin(),S[y].end(),make_pair(p,0ll));
	if(i==S[y].begin()) return 0;
	i--;return i->fi<p&&p<i->se;
}
namespace BIT{
	ll f[12];
	void Cl(){Me(f,0x3f);}
	void Add(ll x,int y){if(y<=m+1) f[y]=min(f[y],x);}
	int Qry(ll x){for(int i=0;i<=m+1;i++) if(f[i]<=x) return i;return INF;}
}
int main(){
	int i,j;scanf("%d%d%lld%lld",&n,&m,&s,&v);s*=K;v*=K;s-=(m+1)*v;
	for(i=1;i<=n;i++) scanf("%lld%lld%d",&a,&b,&r),a*=K,b*=K,a-=r*v,b-=r*v,A[++Ah]={r,a},A[++Ah]={r,b},S[r].PB({a,b});
	for(i=0;i<=m+1;i++) A[++Ah]={i,0},A[++Ah]={i,s};
	for(i=1;i<=m;i++){
		sort(S[i].begin(),S[i].end());
		vector<pair<ll,ll> > g;
		for(auto j:S[i]) {
			if(g.empty()||j.fi>g.back().se) g.PB(j);
			else if(j.se>g.back().se) g.back().se=j.se;
		}
		S[i]=g;
	}
	for(i=1;i<=Ah;i++) for(j=1;j<=Ah;j++) if(A[i].fi<A[j].fi&&A[i].se<=A[j].se){
		B[++Bh].k=(A[j].se-A[i].se)/(A[j].fi-A[i].fi);B[Bh].b=A[i].se-A[i].fi*B[Bh].k;
	}
	Me(f,0x3f);
	for(i=1;i<=Bh;i++) if(!Init(B[i],0)&&!Init(B[i],1)) f[i]=0;
	for(i=2;i<=m+1;i++){
		Mc(g,f);Me(f,0x3f);
		for(j=1;j<=Bh;j++) if(!Init(B[j],i)){
			f[j]=g[j];C[j]={B[j].calc(i),B[j].calc(i-1),j,1};
		}else C[j]={B[j].calc(i),B[j].calc(i-1),j,0};
		sort(C+1,C+Bh+1,[](Node x,Node y){return x.x^y.x?x.x<y.x:x.y>y.y;});
		BIT::Cl();
		for(j=1;j<=Bh;j++) {
			if(C[j].op) f[C[j].id]=min(f[C[j].id],BIT::Qry(-C[j].y));
			BIT::Add(-C[j].y,g[C[j].id]+1);
		}
		BIT::Cl();
		for(j=Bh;j;j--) {
			if(C[j].op) f[C[j].id]=min(f[C[j].id],BIT::Qry(C[j].y));
			BIT::Add(C[j].y,g[C[j].id]+1);
		}}
	int ans=INF;for(i=1;i<=Bh;i++) ans=min(ans,f[i]);printf("%d\n",ans>m+1?-1:ans);
}