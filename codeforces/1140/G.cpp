// LUOGU_RID: 160445895
// LUOGU_RID: 160440435
#include <bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
int N,hd[300009],pa[300009],dep[300009],to[600009],nxt[600009],val1[600009],val2[600009],
w[300009],Q,k,anc[300009][19];
void l(int u,int v,int w1,int w2) {
	to[++k]=v;nxt[k]=hd[u];val1[k]=w1;val2[k]=w2;hd[u]=k;
}
struct dijsktra {
	struct hn{
		int d,u;
		bool operator<(const hn& rhs) const{return d>rhs.d;}
	};	
	#define MaxN 300001
	#define MaxM 900000
	int N,k=0,hd[MaxN+10],to[MaxM+10],nxt[MaxM+10],val[MaxM+10],d[MaxN+10];
	bool vis[MaxN+10];
	inline void link(int u,int v,int w) {nxt[++k]=hd[u],to[k]=v,val[k]=w,hd[u]=k;}
	void clear(void) {
		for(int i=1;i<=N;i++) hd[i]=0;
		k=0;
	}
	void dij(int s) {
		std::priority_queue<hn> Q;
		memset(d,0x3f,sizeof(d[0])*(N+5));
		memset(vis,0,sizeof(vis[0])*(N+5));
		d[s]=0;
		Q.push((hn){0,s});
		while(!Q.empty()) {
			hn x=Q.top();Q.pop();
			int u=x.u;
			if(vis[u]) continue;
			vis[u]=1;
			for(int i=hd[u];i;i=nxt[i]) {
				if(d[to[i]]>d[u]+val[i]) {
					d[to[i]]=d[u]+val[i];
					Q.push((hn){d[to[i]],to[i]});
				} 
			}
		}
	}
} dij;
struct matr{
	int a00,a01,a10,a11;
	matr operator*(matr b) {
		return (matr){std::min(a00+b.a00,a01+b.a10),std::min(a00+b.a01,a01+b.a11),
		std::min(a10+b.a00,a11+b.a10),std::min(a10+b.a01,a11+b.a11)};
	}
} up[300009],aup[300009][19];
void dfs(int n,int f) {
	dep[n]=dep[f]+1;
	pa[n]=f;
	for(int i=hd[n];i;i=nxt[i]) {
		if(to[i]==f) continue;
		dfs(to[i],n);
		up[to[i]].a00=val1[i];
		up[to[i]].a11=val2[i];
		up[to[i]].a01=val1[i]+w[n];
		up[to[i]].a10=val2[i]+w[n];
		anc[to[i]][0]=n;
		aup[to[i]][0]=up[to[i]];
	}
}
int lca(int a,int b) {
	if(dep[a]<dep[b]) std::swap(a,b);
	for(int i=18;i>=0;i--) {
		if((dep[a]-dep[b])>=(1<<i)) a=anc[a][i];
	}
	if(a==b) return a;
	for(int i=18;i>=0;i--) {
		if(anc[a][i]!=anc[b][i]) a=anc[a][i],b=anc[b][i];
	}
	return anc[a][0];
}
signed main(void) {
    //duibuqi!!!
	scanf("%lld",&N);
	dij.N=N+1;
	for(int i=1;i<=N;i++) {
		scanf("%lld",&w[i]);
		dij.link(N+1,i,w[i]);
	}
	for(int i=1;i<N;i++) {
		int u,v,a,b;
		scanf("%lld %lld %lld %lld",&u,&v,&a,&b);
		dij.link(u,v,a+b);
		dij.link(v,u,a+b);
		l(u,v,a,b),l(v,u,a,b);
	}
	dij.dij(N+1);
	for(int i=1;i<=N;i++) {
		w[i]=dij.d[i];
	}
	dfs(1,0);
	for(int i=1;i<=18;i++) {
		for(int j=1;j<=N;j++) {
			anc[j][i]=anc[anc[j][i-1]][i-1];
			aup[j][i]=aup[j][i-1]*aup[anc[j][i-1]][i-1];
		}
	}
	scanf("%lld",&Q);
	while(Q--) {
		int a,b;
		scanf("%lld %lld",&a,&b);
		std::vector<int> x,y;
		int ta=(a+1)/2,tb=(b+1)/2;
		int tp=lca(ta,tb);
		int a0=0,a1=0;
		if(a%2==1) a1=w[(a+1)/2];else a0=w[(a+1)/2];
		for(int i=18;i>=0;i--) {
			if(dep[ta]-dep[tp]>=(1<<i)) {
				int a2=std::min(a0+aup[ta][i].a00,a1+aup[ta][i].a10);
				a1=std::min(a0+aup[ta][i].a01,a1+aup[ta][i].a11);
				a0=a2;
				ta=anc[ta][i];
			}
		}
		int b0=0,b1=0;
		if(b%2==1) b1=w[(b+1)/2];else b0=w[(b+1)/2];
		for(int i=18;i>=0;i--) {
			if(dep[tb]-dep[tp]>=(1<<i)) {
				int b2=std::min(b0+aup[tb][i].a00,b1+aup[tb][i].a10);
				b1=std::min(b0+aup[tb][i].a01,b1+aup[tb][i].a11);
				b0=b2;
				tb=anc[tb][i];
			}
		}
		printf("%lld\n",std::min(b0+a0,b1+a1));
	}
}