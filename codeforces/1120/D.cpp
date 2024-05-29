// LUOGU_RID: 160442472
// Problem: Power Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1120D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Written by yhm.
// Start codeing:2024-05-27 14:27:35
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
#define mod 998244353ll
#define pii pair<int,int>
#define fi first
#define se second
#define mems(x,y) memset(x,y,sizeof(x))
using namespace std;
const int maxn=200010;
const int inf=1e18;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-48);ch=getchar();}
	return x*f;
}
bool Mbe;

int n,a[maxn];
int head[maxn],tot;
struct nd{
	int nxt,to;
}e[maxn<<1];
void add(int u,int v){e[++tot]={head[u],v};head[u]=tot;}
int l[maxn],r[maxn],idx;
void dfs(int u,int fa){
	if(u!=1&&!e[head[u]].nxt){
		l[u]=r[u]=++idx;
		return ;
	}
	l[u]=idx+1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
	}
	r[u]=idx;
}
struct edge{
	int u,v,w,id;
}g[maxn];
int f[maxn],res;
int fd(int x){
	if(x==f[x])return x;
	return f[x]=fd(f[x]);
}
vector<int> ans;
void work(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)g[i]={l[i],r[i]+1,a[i],i};
	idx++;for(int i=1;i<=idx;i++)f[i]=i;
	sort(g+1,g+n+1,[&](edge u,edge v){return u.w<v.w;});
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&g[i].w==g[j].w){
			if(fd(g[j].u)!=fd(g[j].v))ans.push_back(g[j].id);
			j++;
		}
		if(fd(g[i].u)!=fd(g[i].v)){
			f[fd(g[i].u)]=fd(g[i].v);
			idx--;res+=g[i].w;
			if(idx==1)break;
		}
	}
	printf("%lld %lld\n",res,(int)ans.size());
	sort(ans.begin(),ans.end());
	for(int i:ans)printf("%lld ",i);
}

// \
444

bool Med;
int T;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	
//	cerr<<(&Mbe-&Med)/1048576.0<<" MB\n";
	
	T=1;
	while(T--)work();
}
