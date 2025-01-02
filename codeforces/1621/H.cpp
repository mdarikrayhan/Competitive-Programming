// LUOGU_RID: 157645293
// ubsan: undefined
// accoders
// clang-format off
#include<bits/stdc++.h>
#define pb push_back
#define P make_pair
#define st first
#define nd second
#define bit(s,x) (((s)>>(x))&1)
#define ctz(s) __builtin_popcount(s)
using namespace std;
typedef long long ll; 
typedef unsigned long long ull; 
//typedef __int128 i128; 
typedef long double ld;
typedef pair<int,int> pii; typedef pair<ll,int> pli; typedef pair<ll,ll> pll; typedef pair<int,ll> pil;
inline ll read(){
	ll x=0,f=1,c=getchar();
	while(c<'0'||c>'9')f=(c=='-'?-1:1),c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
const int mod=998244353;
inline int fp(int x,ll p=mod-2,int m=mod,int res=1){
	for(;p;p>>=1){if(p&1)res=1ll*res*x%m;x=1ll*x*x%m;}
	return res;
}
const int N=2e5+3;
const int INF=0x3fffffff;
// clang-format on
int n,m,a[N];
int sg[N],top[N];
ll dis[N],T,w[26],f[26];
vector<pil>G[N];
inline void dfs(int u,int fa){
	static vector<ll>vec;
	ll s=0;
	vector<ll>pst;pst.pb(0),pst.pb(1),pst.pb(T);
	for(int i=vec.size()-1;~i;--i){
		s+=vec[i];
		pst.pb((s+T-1)/T*T-s+1);
	}
	sort(pst.begin(),pst.end());
	ll tmp=dis[u]%T;
	for(int i=0;i<pst.size()-1;++i)if(tmp>=pst[i] && tmp<pst[i+1]){sg[u]=1<<i;break;}
	for(auto [v,w]:G[u])if(v!=fa){
		if(a[u]==a[v]){
			top[v]=top[u],dis[v]=dis[u]+w,dfs(v,u),sg[u]|=sg[v];
		}
		else{
			top[v]=u,dis[v]=w;
			if(dis[u])vec.pb(dis[u]);
			dfs(v,u);
			if(dis[u])vec.pop_back();
		}
	}
}
inline ll solve(int u){
	static ll t[26];memset(t,0,sizeof t);
	auto calc = [](int x){
		if(!t[x] || w[x]/t[x] >= f[x])return t[x]*f[x];
		return w[x];
	};
	vector<pli>vec;
	for(int x=top[u];x;x=top[x])if(dis[x])vec.pb(P(dis[x],a[x]));
	vector<pli>pst;pst.pb(P(0,-1)),pst.pb(P(1,-1)),pst.pb(P(T,-1));
	ll s=0;
	for(int i=0;i<vec.size();++i){
		int c=vec[i].nd;
		ll l=(s+T-1)/T,r=(s+vec[i].st+T-1)/T;
		t[c] += r-l;
	   	s += vec[i].st;pst.pb(P((s+T-1)/T*T-s+1,i));
	}
	sort(pst.begin(),pst.end());
	ll ans=2e14,res=0;
	for(int i=0;i<26;++i)res += calc(i);
	if(bit(sg[u],0))ans=min(ans,res);
	if(dis[top[u]]){
		int c=a[top[u]];res -= calc(c),--t[c],res += calc(c);
	}
	for(int i=1;i<pst.size()-1;++i){
		if(~pst[i].nd){
			int c=vec[pst[i].nd].nd;
			res -= calc(c);++t[c];res += calc(c);
			if(pst[i].nd+1<vec.size()){
				c=vec[pst[i].nd+1].nd;
				res -= calc(c);--t[c];res += calc(c);
			}
		}
		if(bit(sg[u],i))ans=min(ans,res);
	}
	return ans;
}
int main() {
    //freopen("data.in", "r", stdin);
     //freopen("AE86.in","r",stdin);
    // freopen("AE86.out","w",stdout);
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read(),w=read();
		G[u].pb(P(v,w)),G[v].pb(P(u,w));
	}
	m=read();
	auto re = [](){
		int c=getchar();
		while(c<'A'||c>'Z')c=getchar();
		return c-'A';
	};
	for(int i=1;i<=n;++i) a[i]=re();
	for(int i=0;i<m;++i)w[i]=read();
	for(int i=0;i<m;++i)f[i]=read();
	T=read();int Q=read();
	dfs(1,0);
	//for(int i=1;i<=n;++i)assert(sg[i]>0);
	for(int i=1;i<=Q;++i){
		int op=read();
		if(op==1){int x=re();w[x]=read();}
		if(op==2){int x=re();f[x]=read();}
		if(op==3)printf("%lld\n",solve(read()));
	}
    return 0;
}
