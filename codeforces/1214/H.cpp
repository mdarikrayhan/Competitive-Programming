// LUOGU_RID: 160579288
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
#include<array>
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
const int N=2e5+5;
int n,k,x,y;
int col[N];
vector<int> e[N];
int fa[N],dep[N];
inline void dfs(int u,int fath){
	fa[u]=fath;
	dep[u]=dep[fath]+1;
	for(int v:e[u]) if(v^fath) dfs(v,u);
}
inline void dfs1(int u,int fa,int rt){
//	cerr<<u<<' '<<fa<<' '<<rt<<'\n';
	if(dep[u]>=k&&dep[y]+dep[u]-2*dep[rt]+1>=k) cout<<"No\n",exit(0);
	if(dep[rt]<dep[y]-dep[rt]+1) col[u]=(col[rt]-1+dep[u]-dep[rt])%k+1;
	else col[u]=(col[rt]-1-(dep[u]-dep[rt])%k+k)%k+1;
	for(int v:e[u]) if(v^fa) dfs1(v,u,rt);
}
bool M2;
int main(){
	int Time=clock();
	look_memory;
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>k;
	F(i,1,n-1){
		int u,v;cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1,0);
	if(k==2){
		cout<<"Yes\n";
		F(i,1,n) cout<<(dep[i]&1)+1<<' ';cout<<'\n';
		return 0;
	}
	F(i,1,n) if(dep[i]>dep[x]) x=i;
	dfs(x,0);
	F(i,1,n) if(dep[i]>dep[y]) y=i;
//	cerr<<x<<' '<<y<<'\n';
	vector<int> v;
	for(int i=y;i;i=fa[i]) v.emplace_back(i);
	F(i,0,int(v.size())-1) col[v[i]]=i%k+1;
	F(i,0,int(v.size())-1) for(int x:e[v[i]]) if(!col[x]) dfs1(x,v[i],v[i]);
	cout<<"Yes\n";
	F(i,1,n) cout<<col[i]<<' ';cout<<'\n';
	look_time;
	return 0;
}
