#include <bits/stdc++.h>
#define MOD 998244353
static char buf[1000000],*paa=buf,*pd=buf;
static char buf2[1000000],*pp=buf2;
#define getchar() paa==pd&&(pd=(paa=buf)+fread(buf,1,1000000,stdin),paa==pd)?EOF:*paa++
inline void pc(char ch){
  if(pp-buf2==1000000) fwrite(buf2,1,1000000,stdout),pp=buf2;
  *pp++=ch;
}
inline void pcc(){
  fwrite(buf2,1,pp-buf2,stdout);
  pp=buf2;
}
inline int read(void) {
  int w=1;
  register int x(0);register char c(getchar());
  while(c<'0'||c>'9') {if(c=='-') w=-1;c=getchar();}
  while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
  return w*x;
}
void write(int x) {
  if(x<0) pc('-'),x=-x;
  static int sta[20];
  int top=0;
  do {
    sta[top++]=x%10,x/=10;
  } while(x);
  while(top) pc(sta[--top]+48);
}
void we(int x) {
  write(x);
  pc('\n');
}
int N,K,a[300009],la[300009],hd[300009],to[600009],nxt[600009],k,vi[300009],dfn[300009],
pa[300009],kk,dp[300009][2],cc,ti,b[300009],col[300009],siz[300009],cur[300009],
ff[300009];
void l(int u,int v) {
	to[++k]=v;nxt[k]=hd[u];hd[u]=k;
}
std::vector<int> g[300009];
void co(int u,int v) {
	//printf("%d %d\n",u,v);
	g[u].push_back(v);
	g[v].push_back(u);
}
void dfs(int n,int f) {
	dfn[n]=++kk;pa[n]=f;siz[n]=1;
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		dfs(to[i],n);
		siz[n]+=siz[to[i]];
	}
}
void dfs2(int n,int f) {
	vi[n]=ti;
	if(cc&&cc!=a[n]&&a[n]) {
		printf("0");
		exit(0);
	}
	cc=std::max(cc,a[n]);
	for(int i=hd[n];i;i=nxt[i]) {
		int du;
		if(pa[n]==to[i]) du=n;else du=to[i];
		if(to[i]==f||col[du]==0) continue;
		dfs2(to[i],n);
	}
}
void dfs3(int n,int f) {
	int a1=1;
	for(int x=0;x<g[n].size();x++) {
		int i=g[n][x];
		if(i==f) continue;
		dfs3(i,n);
		a1=1ll*a1*(dp[i][0]+dp[i][1])%MOD;
	}
	if(b[n]) {
		dp[n][1]=a1;
	} else {
		dp[n][0]=a1;
		int a1=1;
		for(int x=0;x<g[n].size();x++) {
			int i=g[n][x];
			if(i!=f) 
			a1=1ll*a1*(dp[i][0]+dp[i][1])%MOD;
			ff[x]=a1;
		}
		int ans=0;
		a1=1;
		for(int x=g[n].size()-1;x>=0;x--) {
			int i=g[n][x];
			if(i==f) continue;
			ans=(ans+1ll*a1*dp[i][1]%MOD*(x==0?1:ff[x-1]))%MOD;
			a1=1ll*a1*(dp[i][0]+dp[i][1])%MOD;
		}
		dp[n][1]=ans;
	}
}
signed main(void) {
	N=read();K=read();
	for(int i=1;i<=N;i++) {
		a[i]=read();
		la[a[i]]=i;
		cur[a[i]]=i;
	}
	for(int i=1;i<N;i++) {
		int u=read(),v=read();
///		scanf("%d %d",&u,&v);
		l(u,v),l(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=N;i++) {
		if(la[a[i]]==i||a[i]==0) continue;
		int x=la[a[i]],y=i;
		while(dfn[x]<dfn[y]||dfn[x]>=dfn[y]+siz[y]) {
			if(col[y]) {
				if(col[y]!=a[i]) {
					printf("0");
					return 0;
				}
				break;
			}
			col[y]=a[i];y=pa[y];
		}
		x=cur[a[i]];
		while(dfn[y]<dfn[x]||dfn[y]>=dfn[x]+siz[x]) {
			if(col[x]) {
				printf("0");
				return 0;
			}
			col[x]=a[i];x=pa[x];
		}
		cur[a[i]]=x;
	}
	//if(N>100) return 0;
	for(int i=1;i<=N;i++) {
		if(!vi[i]) {
			ti++;cc=0;
			dfs2(i,0);
			b[ti]=cc;
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=hd[i];j;j=nxt[j]) {
			if(vi[i]!=vi[to[j]]&&i<to[j]) {
				co(vi[i],vi[to[j]]);
			}
		}
	}
	//printf("Y\n");
	dfs3(1,0);
	printf("%d",dp[1][1]);
}