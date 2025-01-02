// LUOGU_RID: 160497100
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define B 1300
int N,K,st[100009],q,dp[100009],hd[100009],to[200009],nxt[200009],k,mx[100009],as[100009];
void l(int u,int v) {
	to[++k]=v;nxt[k]=hd[u];hd[u]=k;
}
void dfs(int n,int f) {
	st[++q]=n;
	int la=0;
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) {
			if(la) nxt[la]=nxt[i];
			else hd[n]=nxt[i];continue;
		}
		la=i;
		dfs(to[i],n);
	}
}
void dd() {
	for(int p=N;p>=1;p--) {
		int n=st[p],a1=0,a2=0;
		dp[n]=mx[n]=0;
		for(int i=hd[n];i;i=nxt[i]) {
			if(a1<mx[to[i]]) {
				a2=a1;a1=mx[to[i]];
			} else a2=std::max(a2,mx[to[i]]);
			dp[n]+=dp[to[i]];
		}
		if(a1+a2>=K-1) {
			dp[n]++;
		} else {
			mx[n]=a1+1;
		}
	}
}
int tr(int i) {
	K=i;
	dd();
	return dp[1];
}
signed main(void) {
	scanf("%d",&N);
	for(int i=1;i<N;i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		l(u,v),l(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=B&&i<=N;i++) { 
		as[i]=tr(i);
	}
	int la=N;
	for(int i=0;i<=N/B&&B<la;i++) {
		int l=B+1,r=la+1,md;
		while(l<r) {
			md=(l+r)>>1;
			if(tr(md)>i) l=md+1;else r=md;
		}
		for(int j=l;j<=la;j++) as[j]=i;
		la=l-1;
	}
	for(int i=1;i<=N;i++) printf("%d\n",as[i]);
}