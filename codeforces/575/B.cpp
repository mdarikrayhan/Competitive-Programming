#include<bits/stdc++.h>
#define ll long long
#define ri register
#define all(x) (x).begin(),(x).end()
using namespace std;
template<typename T_>void operator+=(vector<T_>&x,const T_&y){x.emplace_back(y);}
const int N=1e5+7,p=1e9+7;
inline int qp(int a,int o){
	int res=1;
	while(o){
		if(o&1)res=1ll*res*a%p;
		a=1ll*a*a%p,o>>=1;
	}
	return res;
}
ll ans;
int n,m,dep[N],fa[N],tp[N],son[N],sz[N],U[N],D[N];
vector<vector<pair<int,int>>>e;
vector<int>s(1,1);
inline void dfs1(int u,int rt){
	sz[u]=1,fa[u]=rt,dep[u]=dep[rt]+1;
	for(auto[v,w]:e[u])if(v^rt){
		dfs1(v,u),sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
inline void dfs2(int u,int t){
	tp[u]=t;
	if(!son[u])return;
	dfs2(son[u],t);
	for(auto[v,w]:e[u])if(v^fa[u]&&v^son[u])
		dfs2(v,v);
}
inline void dfs3(int u){
	for(auto[v,w]:e[u])if(v^fa[u])
		dfs3(v),U[u]+=U[v],D[u]+=D[v]; 
}
inline int lca(int x,int y){
	int fx=tp[x],fy=tp[y];
	while(fx!=fy){
		if(dep[fx]<dep[fy])swap(fx,fy),swap(x,y);
		x=fa[tp[x]],fx=tp[x];
	}
	return dep[x]>dep[y]?y:x;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n,e.resize(n+1);
	for(int i=1,x,y,z;i<n;i++){
		cin>>x>>y>>z;
		if(!z)e[x]+={y,0},e[y]+={x,0};
		else e[x]+={y,0},e[y]+={x,1};
	}
	dfs1(1,0),dfs2(1,1);
	cin>>m;
	for(int i=1,x;i<=m;i++)cin>>x,s+=x;
	for(int i=1,lc;i<=m;i++){
		lc=lca(s[i-1],s[i]);
		U[s[i-1]]++,U[lc]--,D[s[i]]++,D[lc]--;
	}
	dfs3(1);
	for(int u=1;u<=n;u++)
		for(auto[v,w]:e[u]){
			if(w&&dep[u]>dep[v])
				(ans+=qp(2,U[u])+p-1)%=p;
			else if(w)
				(ans+=qp(2,D[v])+p-1)%=p;
		}
	cout<<ans<<'\n';
	return 0;
}