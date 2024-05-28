// LUOGU_RID: 160201677
#include<bits/stdc++.h>
#define fo(i,l,r) for(int i=(l);i<=(r);++i)
#define fd(i,l,r) for(int i=(l);i>=(r);--i)
#define fu(i,l,r) for(int i=(l);i<(r);++i)
using namespace std;
const int N=1e5+3,inf=1e8;
int n,l,r,f[N];
int dfn[N],top[N],cnt,son[N],maxd[N],dep[N];
vector<int>h[N];
int lz[N],tmp,L,R;
struct node{
	int s,x;
	bool operator<(const node &t)const{return s<t.s;}
	node operator+(int t)const{return (node){s+t,x};}
}t[N<<2],g[N];
int tot,to[N<<1],head[N],nx[N<<1],w[N<<1],sonw[N];
void add(int x,int y,int z){to[++tot]=y;nx[tot]=head[x];head[x]=tot;w[tot]=z;}
template<typename T>
void Max(T &x,T y){if(x<y)x=y;}
void dfs(int x,int y)
{
	maxd[x]=dep[x];
	for(int i=head[x],j;i;i=nx[i])
	{
		j=to[i];if(j==y) continue;
		dep[j]=dep[x]+1;f[j]=x;dfs(j,x);
		if(maxd[j]>maxd[x]) son[x]=j,sonw[x]=w[i],maxd[x]=maxd[j];
	}
}
void dfs2(int x,int y)
{
	top[x]=y;dfn[x]=++cnt;h[y].push_back(x);
	if(son[x]) dfs2(son[x],y);
	for(int i=head[x],j;i;i=nx[i])
		if((j=to[i])!=f[x]&&j!=son[x]) dfs2(j,j);
}
void upd(int l,int r,int o,int x,node y)
{
	Max(t[o],y);
	if(l==r) return;
	int mid=l+r>>1;
	if(x<=mid) upd(l,mid,o+o,x,y);
	else upd(mid+1,r,o+o+1,x,y);
}
void upd(int x,node y)
{
	y.s-=lz[top[x]];
	if(g[x].s<y.s) g[x]=y,upd(1,n,1,dfn[x],y);
}
node qry(int l,int r,int o,int x,int y)
{
	if(x>y||r<x||y<l) return (node){-inf,0};
	if(x<=l&&r<=y) return t[o];
	int mid=l+r>>1;
	return max(qry(l,mid,o+o,x,y),qry(mid+1,r,o+o+1,x,y));
}
int gt(int x,int y)
{
	return h[top[x]][min(y+dep[x]-dep[top[x]],(int)h[top[x]].size()-1)];
}
node qry(int x,int l,int r)
{
	if(dep[x]+l>maxd[x]) return (node){-inf,0};
	return qry(1,n,1,dfn[gt(x,l)],dfn[gt(x,r)])+lz[top[x]];
}
bool gans(int x)
{
	if(!son[x]){upd(x,(node){0,x});return 0;}
	for(int i=head[x],j;i;i=nx[i])
	{
		j=to[i];if(j==f[x]) continue;
		if(gans(j)) return 1;
	}
	lz[top[x]]+=sonw[x]>=tmp?1:-1;
	upd(x,(node){0,x});
	node z=qry(x,l,r);
	if(z.s>=0) return L=x,R=z.x,1;
	for(int i=head[x],j;i;i=nx[i])
	{
		j=to[i];if(j==f[x]||j==son[x]) continue;
		int o=j,s=0,t=x;
		while(o)
		{
			node t=g[o]+lz[j]+(w[i]>=tmp?1:-1);s++;
			if(s<=r&&t.s+(z=qry(x,max(l-s,0),r-s)).s>=0) return L=t.x,R=z.x,1;
			o=son[o];
		}
		s=0;o=j;
		while(o) t=son[t],upd(t,g[o]+lz[j]+(w[i]>=tmp?1:-1)),o=son[o];
	}
	return 0;
}
bool check(int x)
{
	fo(i,1,n) g[i].s=-inf,lz[i]=0;
	fo(i,1,n<<2) t[i].s=-inf;
	tmp=x;
	return gans(1);
}
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1,x,y,z;i<n;++i) scanf("%d%d%d",&x,&y,&z),add(x,y,z),add(y,x,z);
	dep[1]=1;dfs(1,0);dfs2(1,1);
	int l=0,r=1e9;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d %d",L,R);
}