// LUOGU_RID: 160425050
#include <bits/stdc++.h>
#define ls tree[i].lson
#define rs tree[i].rson
using namespace std;
const int V=1e9;
inline int read(){
	int ans=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+ch-'0';
		ch=getchar();
	}
	return w*ans;
} 
int n,rt,m;
int a[100005];
int belong[100005];
struct node{
	int x,id,d;
}p[100005];
bool cmp(node a,node b){
	return a.id<b.id;
}
struct edge{
	int to;
	int next;
}ed[200005];
int cnt;
int h[100005];
void add(int x,int y){
	ed[++cnt]={y,h[x]};
	h[x]=cnt;
}
int dfn[100005],sz[100005],dep[100005],den[100005],tim;
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	dfn[x]=++tim;
	den[tim]=dep[x];
	sz[x]=1;
	for(int i=h[x];i;i=ed[i].next){
		int v=ed[i].to;
		if(v==fa)continue;
		dfs(v,x);
		sz[x]+=sz[v];
	}
}
int Root[100005];
struct persistent_segment_tree{
	struct tree{
		int lson;
		int rson;
		int val;
	}tree[5000005];
	int cnt=0;
	void add(int &b,int i,int l,int r,int pos,int val){
		b=++cnt;
		tree[b]=tree[i];
		tree[b].val=min(tree[b].val,val);
		if(l==r)return;
		int mid=l+r>>1;
		if(mid>=pos) add(tree[b].lson,ls,l,mid,pos,val);
		else add(tree[b].rson,rs,mid+1,r,pos,val);
	}
	int ask(int i,int l,int r,int L,int R){
		if(l>R||r<L)return 1e9;
		if(l>=L&&r<=R)return tree[i].val;
		int mid=l+r>>1;
		return min(ask(ls,l,mid,L,R),ask(rs,mid+1,r,L,R));
	}
}T;

struct lisan{
	int x,id;
	bool operator<(const lisan &a)const{return x<a.x;}
}li[100005];
int lcnt;
int main(){
	n=read(),rt=read();
	T.tree[0].val=1e9;
	for(int i=1;i<=n;i++)a[i]=read();
//	sort(li+1,li+1+n);
//	li[0].x=-1;
//	for(int i=1;i<=n;i++){
//		if(li[i].x>li[i-1].x)++lcnt;
//		a[li[i].id]=lcnt;
//	}
//	for(int i=1;i<=n;i++)belong[a[i]]=i;
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	dfs(rt,0);
	for(int i=1;i<=n;i++){
		p[i]={a[i],dep[i],dfn[i]};
	}
	sort(p+1,p+1+n,cmp);
	m=read();
	int maxx=0;
	for(int i=1;i<=n;i++){
		T.add(Root[p[i].id],Root[p[i-1].id],1,n,p[i].d,p[i].x);
		maxx=max(maxx,p[i].id);
	}
	int lans=0;
	while(m--){
		int x=(read()+lans)%n+1,k=(read()+lans)%n;
		cout<<(lans=T.ask(Root[min(dep[x]+k,maxx)],1,n,dfn[x],dfn[x]+sz[x]-1))<<'\n';
	}
}