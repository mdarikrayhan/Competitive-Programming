// LUOGU_RID: 160472129
bool M1;
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<iomanip>
#include<cassert>
#include<random>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
#define fi first
#define se second
#define ll long long
#define Vector Point
#define I128 __int128
#define LD long double
#define ull unsigned ll
#define pii pair<int,int>
#define pb(x) push_back(x)
#define syt cerr<<"sytakioi\n"
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024<<'\n'
#define rd_i(l,r) uniform_int_distribution<int>(l,r)(rd)
#define rd_r(l,r) uniform_real_distribution<double>(l,r)(rd)
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
using namespace std;
//using namespace __gnu_cxx;
mt19937 rd(time(0));
const int N=1005;
int n,rt,mn;
vector<int> e[N];
int siz[N];
inline void dfs(int u,int fa){
	int mx=0;
	siz[u]=1;
	for(int v:e[u]) if(v^fa) dfs(v,u),siz[u]+=siz[v],mx=max(mx,siz[v]);
	mx=max(mx,n-siz[u]);
	if(mx<mn) mn=mx,rt=u;
}
vector<int> v1,v2;
int fa[N],dep[N];
inline void solve(){
	for(int i=1;i<=v1.size();++i){
		dep[v1[i-1]]=i;
		cout<<v1[i-1]<<' '<<fa[v1[i-1]]<<' '<<i-dep[fa[v1[i-1]]]<<'\n';
		for(int v:e[v1[i-1]]) if(v^fa[v1[i-1]]) fa[v]=v1[i-1],v1.emplace_back(v);
	}
	int m=v1.size();
	for(int i=1;i<=v2.size();++i){
		dep[v2[i-1]]=i*(m+1);
		cout<<v2[i-1]<<' '<<fa[v2[i-1]]<<' '<<i*(m+1)-dep[fa[v2[i-1]]]<<'\n';
		for(int v:e[v2[i-1]]) if(v^fa[v2[i-1]]) fa[v]=v2[i-1],v2.emplace_back(v);
	}
	assert(v1.size()+v2.size()+1==n);
//	assert((v2.size()+1)*m>=2*n*n/9);
	exit(0);
}
bool M2;
int main(){
	int Time=clock();
	look_memory;
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n;mn=n;
	F(i,1,n-1){
		int u,v;cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1,0);
	int u=rt,sum=0;
	for(int v:e[u]) fa[v]=u;
	F(i,0,int(e[u].size())-1){
		int v=e[u][i];
		dfs(v,u);
		if(siz[v]*3>=n){
			v1={v};
			for(int x:e[u]) if(x^v) v2.emplace_back(x);
			solve();
		}
		sum+=siz[v];
		v1.emplace_back(v);
		if(sum*3>=n){
			F(j,i+1,int(e[u].size())-1) v2.emplace_back(e[u][j]);
			solve();
		}
	}
	look_time;
	return 0;
}