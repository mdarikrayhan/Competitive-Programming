// LUOGU_RID: 157910291
#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
constexpr int n_MAX=600000+5;
long long mul(const int x,const int y){return ((long long)x*y);}
int n,m,q,a[n_MAX]; array<int,3> op[n_MAX];
long long ans[n_MAX];
vector<int> L[n_MAX],R[n_MAX];
int Fa[n_MAX],prec[n_MAX],succ[n_MAX],w[n_MAX];
long long cur[n_MAX],path[n_MAX]; int t[n_MAX];
void find(const int u)
{
	if(Fa[u]==u) return;
	find(Fa[u]),path[u]+=path[Fa[u]],Fa[u]=Fa[Fa[u]];
}
struct compare
{
	inline bool operator () (const int u,const int v)
		{return (w[u]>w[v]);}
};
set<int,compare> S;
void link(const int u,const int v){succ[u]=v,prec[v]=u;}
void isolate(const int u){succ[u]=prec[u]=0;}
void merge(const int u,const int v,const int i)
{
	++m,Fa[m]=m,w[m]=w[u],t[m]=i;
	Fa[u]=m,path[u]=(cur[u]+mul(t[u]-i,w[u])),t[u]=cur[u]=0;
	Fa[v]=m,path[v]=(cur[v]+mul(t[v]-i,w[v])),t[v]=cur[v]=0;
	link(prec[u],m),link(m,succ[v]),isolate(u),isolate(v);
	S.erase(u),S.erase(v),S.insert(m);
}
void Insert(const int r)
{
	for(const int i:R[r])
	{
		const int k=op[i][2];
		Fa[i]=i,w[i]=k,t[i]=(r+1);
		const int u=(*(--S.upper_bound(i)));
		const int v=succ[u];
		link(u,i),link(i,v);
		if(k==w[u]) merge(u,i,r); else S.insert(i);
	}
}
void Take_average(const int i)
{
	for(int u=succ[0];u&&(w[u]>=a[i]);u=succ[u])
	{
		const int v=succ[u];
		if(((w[u]+a[i])>>1)==((w[v]+a[i])>>1)) merge(u,v,i),u=m;
	}
	for(int u=succ[0];u&&(w[u]>=a[i]);u=succ[u])
	{
		if(t[u]>=(i+1)) cur[u]+=mul(t[u]-i,w[u]),t[u]=i;
		w[u]=((w[u]+a[i])>>1);
	}
}
void Delete(const int l)
{
	for(const int i:L[l])
	{
		const int r=op[i][1],k=op[i][2];
		find(i),ans[i]=(mul(r+1,k)-(path[i]+(cur[Fa[i]]+mul(t[Fa[i]],w[Fa[i]]))));
	}
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	For(i,1,n) cin>>a[i];
	cin>>q,m=q;
	For(i,1,q)
	{
		int l,r,k; cin>>l>>r>>k,op[i]={l,r,k};
		L[l].push_back(i),R[r].push_back(i);
	}
	w[0]=(1<<30),S.insert(0);
	For_down(i,n,1)
	{
		Insert(i);
		Take_average(i);
		Delete(i);
	}
	For(i,1,q) cout<<ans[i]<<'\n'; return 0;
}