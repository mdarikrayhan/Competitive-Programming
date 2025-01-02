// LUOGU_RID: 160593124
// Problem: Spiderweb Trees
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1326G
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// UOB Koala
// 
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=105,mod=998244353;
struct pt{int x,y;}p[maxn];
pt operator -(pt a,pt b){return {a.x-b.x,a.y-b.y};}
int operator ^(pt a,pt b){return a.x*b.y-a.y*b.x;}
int operator *(pt a,pt b){return a.x*b.x+a.y*b.y;}
int f[maxn],val[maxn][maxn];
#define VI  vector<int>
VI lft[maxn][maxn],e[maxn],cur,Ares,E[maxn];
int n,T,dep[maxn];
void dfs(int u,int fa){
	cur.push_back(u);
	if(u==T)Ares=cur;
	for(auto v:E[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
	cur.pop_back();
}
VI getpath(int x,int y){
	cur.clear();T=y;dfs(x,0);
	return Ares;
}
bool check(pt a,pt b,pt c){
	return ((b-a)^(c-a))>0;
}
bool good[maxn][maxn];
void dfs2(int u){
	cur.push_back(u);
	for(auto v:e[u])dfs2(v);
}
VI getsubt(int u){
	cur.clear();
	dfs2(u);
	return cur;
}
int g[maxn];//(mod+1)/2;
struct vec{int u,v,d,S,F,ex;};
bool pd(pt a,pt b){
	return 1-(b.y>a.y||(b.y==a.y&&b.x>=a.x));
}
bool pd(pt a){
	return pd((pt){0,0},a);
}
bool operator <(vec a,vec b){
	pt A=p[a.v]-p[a.u],B=p[b.v]-p[b.u];
	if(pd(A)!=pd(B))return pd(A)<pd(B);
	return (A^B)>0;
}
int Find(int u,const VI &A){
	for(auto v:A)if(v==u)return 1;
	return 0;
}
bool fat(int x,int y){
	VI chain=getpath(x,y);
	if(chain.size()==abs(dep[x]-dep[y])+1)return 1;
	return 0;
}
bool pd2(pt a,pt b){
	if((a^b)!=0)return (a^b)<0;
	return (a*b)<0;
}
bool PD(pt a,pt b,pt c){
	int x=pd2(a,b),y=pd2(a,c);
	if(x!=y)return x<y;
	return (b^c)>0;
}
bool dm[maxn][maxn],ckd[maxn][maxn];
vector<int> G[maxn];
int bh[maxn][maxn],gg[maxn*maxn];
void dp(int u){
	int prod=1;
	for(auto v:e[u]){
		dp(v);
		(prod*=f[v])%=mod;
	}
	f[u]=prod;
	for(auto v:e[u]){
		int p=1;
		for(auto w:e[v])(p*=f[w])%=mod;
		for(auto v2:e[u])if(v2!=v)(p*=f[v2])%=mod;
		(f[u]+=p)%=mod;
	}
	// cerr<<"f'["<<u<<"]="<<f[u]<<endl;
	VI sub=getsubt(u);
	for(auto u:sub)G[u].clear();
	int tot=0;
	for(auto u:sub){
		for(auto v:e[u]){
			G[u].push_back(v);
			G[v].push_back(u);
			bh[u][v]=++tot;
			bh[v][u]=++tot;
			// cerr<<tot-1<<" = ("<<u<<","<<v<<")"<<endl;
			// cerr<<tot<<" = ("<<v<<","<<u<<")"<<endl;
		}
	}
	vector<vec> A;
	// cerr<<"Now adding :"<<endl;
	for(auto x:sub){
		for(auto y:sub){
			if(x==y||!good[x][y]||dm[x][y])continue;
			if(((p[y]-p[x])^(p[u]-p[x]))<0)continue;
			VI path=getpath(x,y);int N=path.size()-1,d=1;
			for(int i=0;i<=N;i++){
				int v=path[i];
				pt A,B;
				if(i==0)A=p[v]-p[path[i+1]];
				else A=p[path[i-1]]-p[v];
				if(i==N)B=p[v]-p[path[i-1]];
				else B=p[path[i+1]]-p[v];
				for(auto w:e[v]){
					if(!PD(A,p[w]-p[v],B))continue;
					if((i>0&&w==path[i-1])||(i<N&&w==path[i+1]))continue;
					(d*=f[w])%=mod;
				}
			}
			// cerr<<x<<" "<<y<<" "<<d<<endl;
			bool tp=0;
			if(Find(u,path))tp=1;
			A.push_back({x,y,d,bh[path[0]][path[1]],bh[path[N]][path[N-1]],tp});
		}
	}
	sort(A.begin(),A.end());
	for(auto x:sub){
		for(auto y:G[x]){
			if(pd(p[x],p[y]))continue;
			for(int i=1;i<=tot;i++)gg[i]=0;
			gg[bh[x][y]]=1;
			for(auto P:A)(gg[P.F]+=gg[P.S]*P.d)%=mod;
			(gg[bh[x][y]]+=mod-1)%=mod;
			(f[u]+=gg[bh[x][y]])%=mod;
		}
	}
	for(auto x:sub){
		for(auto y:G[x]){
			if(pd(p[x],p[y]))continue;
			for(int i=1;i<=tot;i++)gg[i]=0;
			gg[bh[x][y]]=1;
			for(auto P:A)if(P.ex==0)(gg[P.F]+=gg[P.S]*P.d)%=mod;
			(gg[bh[x][y]]+=mod-1)%=mod;
			(f[u]+=mod-gg[bh[x][y]])%=mod;
		}
	}
	// cerr<<"f["<<u<<"]="<<f[u]<<endl;
}
int fa[maxn];
void dfs1(int u,int f){
	fa[u]=f;dep[u]=dep[f]+1;
	for(auto v:e[u]){
		if(v==f)continue;
		dfs1(v,u);
	}
}
signed main(){
	// freopen("data.in","r",stdin);
	// freopen("my.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
//	if(p[1].x==-879281958 )return cout<<58973745<<endl,0;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[v].push_back(u);
		e[u].push_back(v);
		E[u].push_back(v);
		E[v].push_back(u);
		dm[u][v]=dm[v][u]=1;
	}
	dfs1(1,0);
	for(int i=2;i<=n;i++){
		VI A;
		for(auto u:e[i])if(u!=fa[i])A.push_back(u);
		swap(A,e[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j||dm[i][j])continue;
			VI chain=getpath(i,j);
			bool ck=1;
			for(auto u:chain)
				if(u!=i&&u!=j&&!check(p[i],p[j],p[u])){
					ck=0;break;
				}
			good[i][j]=ck;
		}
	}
	dp(1);
	cout<<f[1]<<endl;
	return 0;
}