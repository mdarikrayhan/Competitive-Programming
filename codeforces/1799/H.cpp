// Problem: H. Tree Cutting
// Contest: Codeforces - Codeforces Round 854 by cybercats (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1799/H
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

// 私は猫です

#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define inf 1e9
#define infll 1e18
#define pii pair<int,int>
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
#define wh(lzm) while(lzm--)
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
#define HH printf("\n")
#define eb emplace_back
using namespace std;
ll read(){
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int mod=998244353,maxn=5005;
int qpow(int x,ll y){
	int rt=1;
	for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) rt=1ll*rt*x%mod;
	return rt;
}
void inc(int &x,int y){ x=(x+y>=mod)?(x+y-mod):(x+y); }
void dec(int &x,int y){ x=(x>=y)?(x-y):(x+mod-y); }
void mul(int &x,int y){ x=1ll*x*y%mod; }
int add(int x,int y){ return (x+y>=mod)?(x+y-mod):(x+y); }
int sub(int x,int y){ return (x>=y)?(x-y):(x+mod-y); }
int prod(int x,int y){ return 1ll*x*y%mod; }
void chkmax(int &x,int y){ x=max(x,y); }
void chkmin(int &x,int y){ x=min(x,y); }
vector<int>g[maxn];
int highbit(int x){ return 31-__builtin_clz(x); }
int n,k,a[10],d[10],mx,ans[maxn],siz[maxn],sum[132];
namespace Subset_convolution_but_bruteforce{
	struct node{
		int a[132];
		void R(){ F(i,0,mx) a[i]=0; }
		int &operator[](int x){ return a[x]; }
	};
	node f[maxn],res;
	node merge(node x,node y){
		res.R();
		F(s,0,mx) for(int t=s;;t=(t-1)&s){
			inc(res[s],1ll*x[s^t]*y[t]%mod);
			if(!t) break;
		}
		return res;
	}
	void conv(node &x,node y){
		res.R();
		F(s,0,mx) for(int t=s;;t=(t-1)&s){
			inc(res[s],1ll*x[s^t]*y[t]%mod);
			if(!t) break;
		}
		x=res;
	}
	void insert(node &x,int val){
		res=x;
		F(s,0,mx) if(sum[s]==val) inc(res[s],x[s^(1<<highbit(s))]);
		x=res;
	}
}
using namespace Subset_convolution_but_bruteforce;
void dfs0(int u,int fa=0){
	f[u].R();
	siz[u]=1,f[u][0]=1;
	for(int v:g[u]) if(v^fa) dfs0(v,u),siz[u]+=siz[v],conv(f[u],f[v]);
	insert(f[u],siz[u]);
}
node dp[maxn],pre[maxn],suf[maxn],final_dp[maxn];
// f[u] : son(u), dp[u]: U\subtree(u) 
void dfs1(int u,int fa=0){
	vector<int>vec;
	for(int v:g[u]) if(v^fa) vec.push_back(v);
	g[u].swap(vec),vec.clear(),vec.shrink_to_fit();
	int len=g[u].size();
	F(i,0,len-1) {
		pre[i]=f[g[u][i]];
		if(i) conv(pre[i],pre[i-1]);
	}
	dF(i,len-1,0){
		suf[i]=f[g[u][i]];
		if(i<len-1) conv(suf[i],suf[i+1]);
	}
	final_dp[u]=dp[u];
	if(len) conv(final_dp[u],suf[0]);
	F(i,0,len-1){
		const int v=g[u][i];
		dp[v]=dp[u];
		if(i>0) conv(dp[v],pre[i-1]);
		if(i<len-1) conv(dp[v],suf[i+1]);
		insert(dp[v],n-siz[v]);
	}
	for(int v:g[u]) dfs1(v,u);
}
void solve(){
	n=read();
	F(i,1,n-1){
		int u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}
	k=read(),mx=(1<<k)-1;
	F(i,0,k-1) a[i]=read(),d[i]=((i==0)?n:a[i-1])-a[i];
	F(s,0,mx) F(i,0,k-1) if((s>>i)&1) sum[s]+=d[i];
	dfs0(1),dp[1][0]=1,dfs1(1);
	int ans=0;
	F(i,1,n) inc(ans,final_dp[i][mx]);
	mul(ans,qpow(a[k-1],mod-2));
	printf("%d",ans);
}
signed main(){
	int sjy=1;
	cmh(sjy) solve();
}