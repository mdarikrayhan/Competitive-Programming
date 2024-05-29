// LUOGU_RID: 159076906
#include <bits/stdc++.h>
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mp_ make_pair
#define pb_ push_back
#define pob_ pop_back
#define fst first
#define snd second
#define debug cout<<"********\n";
#define reset(x,y) memset(x,y,sizeof(x))
#define fi(x) freopen(x,"r",stdin)
#define fo(x) freopen(x,"w",stdout)
#define iosf ios::sync_with_stdio(0);cin.tie(0);
#define prec(x) cout<<setprecision(x);
#define prec0(x) cout<<fixed<<setprecision(x);
#define s(x,y) x[y-1]
#define Misaka16172 sb
#define kamisako femboy

using ll = long long;
using ld = long double;
using db = double;
using ull = unsigned long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ull mod1 = 1e9+7,mod9 = 998244353;

using namespace std;

template <class T>
inline void read(T &x){
	x = 0;T w = 1;
	char c = 0;
	while(c<'0' || c>'9'){
		if(c=='-')	w = -1;
		c = getchar();
	}
	while(c>='0' && c<='9'){
		x = ((x<<3)+(x<<1))+c-'0';
		c = getchar();
	}
	x = x*w;
}

template <class T>
inline string bin(T x){
	string res = "";
	if(x>>1)	res = bin(x>>1);
	res+=(x&1)+'0';
	return res;
}

constexpr int N = 2e5+5,LOG_N = 20,M = 1e6+5,_inf = 1000000000;

struct DSU{
	int par[N];
	void init(int n){for(int i=1;i<=n;i++)	par[i] = i;}
	int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
	void merge(int x,int y){par[find(x)] = find(y);}
}dsu;

struct edge{
	int u,v,w,id;
	inline bool operator <(const edge &e)const{return w<e.w;}
}E[M];

int n,m;
bool in_mst[M];
vector<edge> mst;

void kruskal(){
	sort(E+1,E+1+m);
	dsu.init(n);
	for(int i=1;i<=m;i++){
		if(dsu.find(E[i].u)==dsu.find(E[i].v))	continue;
		dsu.merge(E[i].u,E[i].v);
		mst.pb_(E[i]);in_mst[i] = 1;
	}
}

int log_2[N],fa[N][LOG_N],maxd[N][LOG_N],dep[N];
int ans[M],val[N];
vector<pii> tr[N];

void dfs(int u){
	dep[u] = dep[fa[u][0]]+1;
	for(int i=1;i<=log_2[dep[u]];i++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
		maxd[u][i] = max(maxd[u][i-1],maxd[fa[u][i-1]][i-1]);
		// cout<<u<<" "<<i<<" "<<fa[u][i]<<" "<<maxd[u][i]<<"\n";
	}
	for(pii e:tr[u]){
		if(e.fst==fa[u][0])	continue;
		fa[e.fst][0] = u,maxd[e.fst][0] = e.snd;
		dfs(e.fst);
	}
}

int getmax(int x,int y){
	if(dep[x]<dep[y])	swap(x,y);
	int res = 0;
	while(dep[x]!=dep[y]){
		res = max(res,maxd[x][log_2[dep[x]-dep[y]]]);
		x = fa[x][log_2[dep[x]-dep[y]]];
	}
	if(x==y)	return res;
	for(int i=log_2[dep[x]];i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			res = max(res,max(maxd[x][i],maxd[y][i]));
			x = fa[x][i],y = fa[y][i];
		}
	}
	res = max(res,max(maxd[x][0],maxd[y][0]));
	return res;
}

int lca(int x,int y){
	if(dep[x]<dep[y])	swap(x,y);
	while(dep[x]!=dep[y]){
		x = fa[x][log_2[dep[x]-dep[y]]];
	}
	if(x==y)	return x;
	for(int i=log_2[dep[x]];i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x = fa[x][i],y = fa[y][i];
		}
	}
	return fa[x][0];
}

void solve(){
	read(n);read(m);
	log_2[1] = 0;for(int i=2;i<=n;i++)	log_2[i] = log_2[i>>1]+1;
	for(int i=1;i<=m;i++){
		read(E[i].u);read(E[i].v);read(E[i].w);
		E[i].id = i;
	}
	kruskal();
	for(edge e:mst){tr[e.u].pb_((pii){e.v,e.w});tr[e.v].pb_((pii){e.u,e.w});}
	fa[1][0] = 1,dep[1] = -1;dfs(1);
	reset(ans,-1);
	dsu.init(n);
	for(int i=1;i<=n;i++)	val[i] = _inf;
	for(int i=1;i<=m;i++){
		if(in_mst[i])	continue;
		ans[E[i].id] = getmax(E[i].u,E[i].v);
		int anc = lca(E[i].u,E[i].v);
		int fu = dsu.find(E[i].u),fv = dsu.find(E[i].v);
		while(dep[fu]>dep[anc]){
			val[fu] = E[i].w;
			dsu.merge(fu,fa[fu][0]);
			fu = dsu.find(E[i].u);
		}
		while(dep[fv]>dep[anc]){
			val[fv] = E[i].w;
			dsu.merge(fv,fa[fv][0]);
			fv = dsu.find(E[i].v);
		}
	}
	for(int i=1;i<=m;i++){
		if(!in_mst[i])	continue;
		if(dep[E[i].u]<dep[E[i].v])	swap(E[i].u,E[i].v);
		ans[E[i].id] = val[E[i].u];
	}
	for(int i=1;i<=m;i++)	cout<<ans[i]<<"\n";
}

int main(){
	int t = 1;
//	read(t);
	for(int tt=1;tt<=t;tt++){
		solve();
	}
    return 0;
}