// LUOGU_RID: 160445805
#include <bits/stdc++.h>
#define MOD 998244353
int N,k,p[500009],siz[500009],dp[500009][2],ans,hd[500009],to[1000009],
nxt[1000009];
void l(int u,int v) {
	to[++k]=v;nxt[k]=hd[u];hd[u]=k;
}
void dfs(int n,int f) {
	int f0=1,f1=0;siz[n]=1;
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		dfs(to[i],n);siz[n]+=siz[to[i]];
		int x=dp[to[i]][1],y=(1ll*dp[to[i]][1]+2ll*dp[to[i]][0])%MOD;
		f1=(1ll*f1*(x+y)+1ll*f0*x)%MOD;
		f0=1ll*f0*y%MOD;
	}
	ans=(ans+2ll*f1*p[N-siz[n]])%MOD;
	dp[n][1]=f0;dp[n][0]=f1;
}
signed main(void) {
	scanf("%d",&N);p[0]=1;
	for(int i=1;i<N;i++) {
		p[i]=p[i-1]*2%MOD;
		int u,v;
		scanf("%d %d",&u,&v);
		l(u,v),l(v,u);
	}
	dfs(1,0);
	printf("%d",ans);
}