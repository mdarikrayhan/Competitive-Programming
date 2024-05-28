// LUOGU_RID: 158969570
#include<bits/stdc++.h>
using namespace std;

#define ONLINE
#ifndef ONLINE
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) ;
#endif

using LL=long long;
using PII=pair<int,int>;

template<typename T>
inline T READ(){
	T x=0; bool f=0; char c=getchar();
	while(c<'0' || c>'9') f|=(c=='-'),c=getchar();
	while(c>='0' && c<='9') x=x*10+c-'0',c=getchar();
	return f?-x:x;
}
inline int read(){return READ<int>();}
inline LL readLL(){return READ<LL>();}
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int mod=1e9+7;
LL ksm2(LL b){
	LL a=2,ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	int n=read(),root=1;
	vector<vector<int>>e(n+1);
	unordered_set<LL>key;
	auto get=[&](const int& u,const int& v)->int{
		return 1ll*u*(n+1)+v;
	};
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
		if(read()){
			key.insert(get(v,u));
		}
	}
	vector<int>dep(n+1),fa(n+1),siz(n+1),son(n+1);
	auto dfs1=[&](auto self,int u,int pre)->void{
		dep[u]=dep[pre]+1,fa[u]=pre,siz[u]=1;
		for(int v:e[u]){
			if(v==pre) continue;
			self(self,v,u);
			siz[u]+=siz[v];
			if(siz[v]>siz[son[u]]) son[u]=v;
		}
	};
	dfs1(dfs1,root,0);
	vector<int>id(n+1),nw(n+1),top(n+1);
	int timStamp=0;
	auto dfs2=[&](auto self,int u,int t)->void{
		id[u]=++timStamp,nw[timStamp]=u,top[u]=t;
		if(!son[u]) return;
		self(self,son[u],t);
		for(int v:e[u]){
			if(v==fa[u] || v==son[u]) continue;
			self(self,v,v);
		}
	};
	dfs2(dfs2,root,root);
	auto LCA=[&](int u,int v)->int{
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u=fa[top[u]];
		}
		return dep[u]<dep[v]?u:v;
	};
	vector<int>a(n+1),b(n+1);//a:up b:down
	for(int T=read(),last=1,nw;T--;){
		nw=read();
		int lca=LCA(nw,last);
		a[last]++,a[lca]--;
		b[nw]++,b[lca]--;
		last=nw;
	}
	LL ans=0;
	auto dfs=[&](auto self,int u)->PII{
		int A=a[u],B=b[u];
		for(int v:e[u]){
			if(v==fa[u]) continue;
			auto [add_a,add_b]=self(self,v);
			A+=add_a,B+=add_b;
			if(key.count(get(v,u))){//a
				ans=(ans+ksm2(add_a)+mod-1)%mod;
			}
			if(key.count(get(u,v))){//b
				ans=(ans+ksm2(add_b)+mod-1)%mod;
			}
		}
		debug("u=%d A=%d B=%d\n",u,A,B);
		return {A,B};
	};
	dfs(dfs,root);
	printf("%lld\n",ans);
	return 0;
}

/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
*/