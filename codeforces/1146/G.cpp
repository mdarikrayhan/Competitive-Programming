// LUOGU_RID: 160086629
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MA 10000
int H,M,N,S,T,l[59],r[59],x[59],c[59],hd[2700],to[20000],nxt[20000],val[20000],k=1,d[2700],cur[2700];
void ll(int u,int v,int w) {
	to[++k]=v;nxt[k]=hd[u];val[k]=w;hd[u]=k;
}
void co(int u,int v,int w) {
	ll(u,v,w),ll(v,u,0);
}
bool bfs() {
	std::queue<int> q;
	for(int i=1;i<=T;i++) d[i]=-1;
	q.push(S);d[S]=0;
	while(!q.empty()) {
		int a=q.front();q.pop();
		for(int i=hd[a];i;i=nxt[i]) {
			if(d[to[i]]==-1&&val[i]) {
				d[to[i]]=d[a]+1;q.push(to[i]);
			}
		}
	}
	return (d[T]!=-1);
}
int dfs(int n,int v) {
	//printf("%d %d\n",n,v);
	if(n==T||v==0) {
		return v;
	}
	int tp,flow=0;
	for(int& i=cur[n];i;i=nxt[i]) {
		if(d[to[i]]==d[n]+1&&(tp=dfs(to[i],std::min(v,val[i])))) {
			val[i^1]+=tp;val[i]-=tp;flow+=tp;v-=tp;
		}
	}
	return flow;
}
void set() {
	for(int i=1;i<=T;i++) cur[i]=hd[i];
}
#define f(a,b) ((a)*(H+2)+(b)-H)
signed main(void) {
	scanf("%d %d %d",&N,&H,&M);
	S=1;T=M+2+N*(H+2);
	for(int i=1;i<=M;i++) {
		scanf("%d %d %d %d",&l[i],&r[i],&x[i],&c[i]);
	}
	k=1;
	for(int i=1;i<=N;i++) {
		co(S,f(i,0),INF);
		co(f(i,H+1),T,INF);
		for(int j=1;j<=H+1;j++) {
			co(f(i,j-1),f(i,j),MA-(j-1)*(j-1));
		}
	}
	for(int i=1;i<=M;i++) {
		for(int j=l[i];j<=r[i];j++) {
			co(f(j,x[i]+1),i+N*(H+2)+1,INF);
		}
		co(i+N*(H+2)+1,T,c[i]);
	}
	int ans=0;
	while(bfs()) {
		set();ans+=dfs(S,INF);
	}
	ans-=N*MA;
	ans=-ans;
	printf("%d",ans);	
}