#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace Fastio{
	#define read Fastio::readin
	#define getchar() (_S==_T&&(_T=(_S=_B)+fread(_B,1,1<<20,stdin),_S==_T)?EOF:*_S++)
	char _B[1<<20],*_S=_B,*_T=_B;
	inline int readin(){
		int ret=0,flg=1;char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-') flg=-1;ch=getchar();}
		while(ch>='0'&&ch<='9'){ret=(ret<<1)+(ret<<3)+ch-'0';ch=getchar();}
		return ret*flg;
	}
}
const int N=300100;
int n,m,hd[N],tot,val[N],deg[N];
bool vis[N];
struct node{int u,v;}inp[N];
struct edge{int to,nxt,val;}a[N<<1];
void add(int u,int v,int w){a[++tot]=(edge){v,hd[u],w};hd[u]=tot;}
vector<int>point,chg;
void dfs(int u){
	vis[u]=1;point.push_back(u);
	for(int i=hd[u];i;i=a[i].nxt){
		int to=a[i].to;
		if(vis[to]){
			if(val[to]^val[u]^a[i].val){puts("NO");exit(0);}
			continue;
		}
		val[to]=val[u]^a[i].val;
		dfs(to);
	}
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<n;i++) inp[i].u=read(),inp[i].v=read(),deg[inp[i].u]++,deg[inp[i].v]++;
	for(int i=1,u,v,w;i<=m;i++) u=read(),v=read(),w=read(),add(u,v,w),add(v,u,w);
	int ans=0;;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			point.clear();dfs(i);int fg=0;
			for(int j:point) fg^=(deg[j]&1);
			if(fg&&(!chg.size()))for(int j:point) chg.push_back(j);
			for(int j:point) if(deg[j]&1)ans^=val[j];
		}
	}
	if(chg.size())for(int i:chg)val[i]^=ans;
	puts("Yes");
	for(int i=1;i<n;i++) printf("%d ",val[inp[i].u]^val[inp[i].v]);
	return 0;
}

