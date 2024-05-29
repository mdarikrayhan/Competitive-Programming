#include <bits/stdc++.h>
const int inf=2e9;
typedef long long ll;
using namespace std;
struct vec{
	int x,y;
	vec operator +(vec b){
		return {x+b.x,y+b.y};
	}
	vec operator -(vec b){
		return {x-b.x,y-b.y};
	}
	ll operator *(vec b){
		return 1ll*x*b.y-1ll*y*b.x;
	}
	ll operator ^(vec b){
		return 1ll*x*b.x+1ll*y*b.y;
	}
	ll len(){
		return 1ll*x*x+1ll*y*y;
	}
}a[610],b[310],c[310];
int n,m,w,mn=inf,mx=-inf,r[310],in[310],out[310];
int S,T,cnt,head[610],o=1,dep[610],cur[610];
struct edge{
	int to,link,w;
}e[400000];
void add_edge(int u,int v,int w){
	e[++o]={v,head[u],w},head[u]=o;
	e[++o]={u,head[v],0},head[v]=o;
}
queue<int>q;
bool bfs(){
	for(int i=1;i<=cnt;i++) cur[i]=head[i],dep[i]=0;
	dep[S]=1,q.push(S);
	while(q.size()){
		int u=q.front();q.pop();
		for(int i=head[u],v;i;i=e[i].link) if(e[i].w&&!dep[v=e[i].to]) dep[v]=dep[u]+1,q.push(v);
	}
	return dep[T];
}
int dfs(int u,int in){
	if(u==T) return in;
	int out=0;
	for(int &i=cur[u],v;i;i=e[i].link) if(e[i].w&&dep[v=e[i].to]==dep[u]+1){
		int res=dfs(v,min(in,e[i].w));
		e[i].w-=res,e[i^1].w+=res;
		in-=res,out+=res;
		if(!in) break;
	}
	if(!out) dep[u]=0;
	return out;
}
void re(vec *a){
	int p=0;
	for(int i=0;i<n;i++) if(a[p].x>a[i].x||(a[p].x==a[i].x&&a[i].y<a[p].y)) p=i;
	vec tp[310];
	for(int i=0;i<n;i++) tp[i]=a[i];
	for(int i=0;i<n;i++) a[i]=tp[(i+p)%n];
}
void mge(vec *a,vec *b){
	vec A[310],B[310];
	re(a),re(b);
	for(int i=0;i<n;i++) A[i]=a[(i+1)%n]-a[i],B[i]=b[(i+1)%n]-b[i];
	a[0]=a[0]+b[0];
	int k=0,j=0;
	for(int i=0;i<n;i++){
		for(;j<n&&B[j]*A[i]>=0;j++) ++k,a[k]=a[k-1]+B[j];
		++k,a[k]=a[k-1]+A[i];
	}
	for(;j<n;j++) ++k,a[k]=a[k-1]+B[j];
}
int chk(vec c,int r){
	for(int i=0;i<2*n;i++) if((a[i]-c).len()<1ll*r*r) return 2;
	bool in=1;
	for(int i=0;i<2*n;i++){
		vec u=a[i],v=a[(i+1)%(2*n)];
		if((c-u)*(v-u)==0&&((c-u)^(c-v))<=0) return 3;
		if(((c-u)^(v-u))>0&&((c-v)^(u-v))>0){
			ll s=(v-u)*(c-u);
			if(s*s<(v-u).len()*r*r) return 4;
		}
		in&=(u-c)*(v-u)>=0;
	}
	return in;
}
int main(){
	cin>>n>>w;
	for(int i=0,x,y;i<n;i++) cin>>x>>y,mn=min(x,mn),mx=max(x,mx),a[i]={x,y},b[i]={-x,-y};
	S=1,T=cnt=2;
	mge(a,b);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>c[i].x>>c[i].y>>r[i],in[i]=++cnt,out[i]=++cnt;
		add_edge(in[i],out[i],1);
		if(mx-mn>c[i].x-r[i]) add_edge(S,in[i],inf);
		if(mx-mn>w-c[i].x-r[i]) add_edge(out[i],T,inf);
	}
	for(int i=1;i<m;i++) for(int j=i+1;j<=m;j++) if(chk(c[i]-c[j],r[i]+r[j])){
		add_edge(out[i],in[j],inf);
		add_edge(out[j],in[i],inf);
	}
	int ans=0;
	while(bfs()) ans+=dfs(S,inf);
	cout<<ans<<"\n";
}