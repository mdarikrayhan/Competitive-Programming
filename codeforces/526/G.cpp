// LUOGU_RID: 158696263
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read(){
	char ch=getchar();
	while(!isdigit(ch) && ch!='-') ch=getchar();
	int x=0,ff=1; if(ch=='-') ff=-1,ch=getchar();
	while(isdigit(ch)) x=(x<<3) + (x<<1) + (ch^48),ch=getchar();
	return x*ff;
}
const int N=1e5+5;
int n,Q; vector<pair<int,int>> e[N];
struct Tree{
	int fd[N],mxd[N],fa[N],ffa[N][19],son[N],rT,p[N],m,c[N],ans[N],col[N];
	void dfs0(int u,int Fa,int d){ if(!Fa) rT=0;
		ffa[u][0]=fa[u]=Fa; for(int i=1;i<=18;i++) ffa[u][i]=ffa[ffa[u][i-1]][i-1];
		fd[u]=mxd[u]=d; son[u]=0; if(d>fd[rT]) rT=u;
		for(auto [v,w]:e[u]) if(v!=Fa){
			dfs0(v,u,d+w);
			if(mxd[v]>mxd[u]) mxd[u]=mxd[v],son[u]=v;
		}
	}
	void dfs1(int u,int tpp){
		if(u==tpp) p[++m]=u;
		if(!son[u]) return ;
		dfs1(son[u],tpp); for(auto [v,w]:e[u]) if(v!=fa[u] && v!=son[u]) dfs1(v,v);
	}
	int init(int u0){
		dfs0(u0,0,0); int rt=rT; dfs0(rt,0,0); dfs1(rt,rt);
		sort(p+1,p+m+1,[&](int x,int y){return mxd[x]-fd[fa[x]]>mxd[y]-fd[fa[y]];});
		for(int i=1;i<=m;i++){
			int x=p[i]; ans[i]=ans[i-1]+mxd[x]-fd[fa[x]];
			while(x) col[x]=i,x=son[x];
		}
		return rt;
	}
	int Q1(int x,int y,int *a){
		int u=x; for(int i=18;i>=0;i--) if(col[ffa[u][i]]>y) u=ffa[u][i];
		u=fa[u]; return ans[y]+mxd[x]-a[u];
	}
	int Qry(int x,int y){
		y=2*y-1; if(y>=col[x]) return ans[min(m,y)];
		return max(Q1(x,y-1,fd),Q1(x,y,mxd));
	}
} T1,T2;
int main(){
	n=read(); Q=read();
	for(int i=1;i<n;i++) {
		int u=read(),v=read(),w=read();
		e[u].push_back({v,w}); e[v].push_back({u,w});
	} T2.init(T1.init(1)); int las=0;
	while(Q--){
		int x=(read()+las-1)%n+1,y=(read()+las-1)%n+1; 
		printf("%d\n",las=max(T1.Qry(x,y),T2.Qry(x,y)));
	}
	return 0;
}//eweeeeewree