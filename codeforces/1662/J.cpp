#include<bits/stdc++.h>
using namespace std;
int n,S,T;
int hd[100005],nxt[300005],c[300005],dy[300005],tot=1;
int cur[100005],l[100005];
void addedge(int u,int v,int w){
	nxt[++tot]=hd[u],hd[u]=tot;
	c[tot]=w,dy[tot]=v;
}
bool getc(){
	for(int i=1;i<=n;++i)l[i]=1e9,cur[i]=hd[i];
	l[S]=0;
	queue<int>q;
	q.emplace(S);
	while(q.size()){
		int x=q.front();
		q.pop();
		for(int i=hd[x];i;i=nxt[i]){
			if(!c[i])continue;
			int cu=dy[i];
			if(l[cu]>l[x]+1){
				l[cu]=l[x]+1;
				q.emplace(cu);
			}
		}
	}
	return l[T]<1e9;
}
long long ans;
int dinic(int x,int rl){
	if(x==T){
		ans+=rl;
		return rl;
	}
	int rr=rl;
	for(int i=cur[x];i;i=nxt[i]){
		cur[x]=i;
		if(!c[i])continue;
		int cu=dy[i];
		if(l[cu]!=l[x]+1)continue;
		int zz=dinic(cu,min(rr,c[i]));
		c[i]-=zz,c[i^1]+=zz;
		rr-=zz;
		if(!rr)break;
	}
	return rl-rr;
}
int a[155][155],aa[155];
#define mk(x,y) (((x)-1)*N+(y))
int main(){
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)
		scanf("%d",&a[i][j]);
	n=1+2*N*N+1,S=n-1,T=n;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j)aa[a[i][j]]=j;
		for(int j=1;j<N;++j){
			int X=aa[j],Y=aa[j+1];
			int z1=mk(i,X),z2=mk(i,Y);
			addedge(z1+N*N,z2,1e9);addedge(z2,z1+N*N,0);
			addedge(z1,z2,1e9);addedge(z2,z1,0);
			addedge(z1+N*N,z2+N*N,1e9);addedge(z2+N*N,z1+N*N,0);
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j)aa[a[j][i]]=j;
		for(int j=1;j<N;++j){
			int X=aa[j],Y=aa[j+1];
			int z1=mk(X,i),z2=mk(Y,i);
			addedge(z1+N*N,z2,1e9);addedge(z2,z1+N*N,0);
			addedge(z1,z2,1e9);addedge(z2,z1,0);
			addedge(z1+N*N,z2+N*N,1e9);addedge(z2+N*N,z1+N*N,0);
		}
	}
	long long he=0;
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
		int c;
		scanf("%d",&c);c+=N;he+=c;
		int w=mk(i,j);
		addedge(S,w+N*N,c);addedge(w+N*N,S,0);
		addedge(w,T,c);addedge(T,w,0);
	}
	while(getc())dinic(S,INT_MAX);
	printf("%lld\n",he-ans-N*N);
	return 0;
}