// LUOGU_RID: 157399490
#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7;
#define mid ((l+r)>>1)
#define lson l,mid,now<<1
#define rson mid+1,r,now<<1|1
int dep[N],f[N],sz[N],son[N],id[N],tim=0,first[N],sum=0,tp[N],ans[N],n,m,x,Ans;
struct Road {int u,v,w;};
Road RD(int x,int y,int z){Road r; r.u=x; r.v=y; r.w=z; return r;}
vector<Road> v[N];
struct Node{int h,l;}tr[N<<2];
struct Dat{int next,fr,to;}a[N<<1];
void pl(int x,int y){sum++; a[sum].next=first[x]; first[x]=sum; a[sum].fr=x; a[sum].to=y; return;}

void pushup(int now)
{
	tr[now].h=tr[now<<1].h+tr[now<<1|1].h;
	tr[now].l=tr[now<<1].l+tr[now<<1|1].l;
	return;
}
void bdtr(int l,int r,int now)
{
	if(l==r) {tr[now].h=tr[now].l=0; return;}
	bdtr(lson); bdtr(rson);
	pushup(now);
}
void xgtr(int l,int r,int now,int x,int y,int z)
{
	if(l==r){tr[now].h+=y; tr[now].l+=z; return;}
	if(x<=mid) xgtr(lson,x,y,z);
	else xgtr(rson,x,y,z);
	pushup(now);
}
int fdtr(int l,int r,int now,int x,int y,int H,int L)
{
	if(x>y) return 0;
	if(x<=l&&r<=y){return tr[now].h*H+tr[now].l*L;}
	if(y<=mid) return fdtr(lson,x,y,H,L);
	if(x>mid) return fdtr(rson,x,y,H,L);
	return fdtr(lson,x,y,H,L)+fdtr(rson,x,y,H,L);
}

void dfs1(int now,int fa)
{
	dep[now]=dep[fa]+1; f[now]=fa;
	sz[now]=1; son[now]=0;
	for(int i=first[now];i!=-1;i=a[i].next)
	{
		dfs1(a[i].to,now);
		sz[now]+=sz[a[i].to];
		if(sz[a[i].to]>sz[son[now]]) son[now]=a[i].to;
	}
	return;
}
void dfs2(int now,int st)
{
	id[now]=++tim; tp[now]=st;
	if(!son[now]) return;
	else dfs2(son[now],st);
	for(int i=first[now];i!=-1;i=a[i].next)
	{
		if(a[i].to==son[now]) continue;
		dfs2(a[i].to,a[i].to);
	}
	return;
}
int lca(int x,int y)
{
	while(tp[x]!=tp[y]){if(dep[tp[x]]<dep[tp[y]]) swap(x,y); x=f[tp[x]];}
	return dep[x]<dep[y]?x:y;
}
int fd(int x,int y)
{
	int res=0,xx=x,yy=y; 
	int l=lca(x,y);
	if(dep[x]<dep[y]) swap(x,y);
	res+=ans[son[x]]+ans[son[y]];
	while(tp[x]!=tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]]) swap(x,y);
		res+=fdtr(1,n,1,id[tp[x]],id[x],0,1);
	//	cout<<tp[x]<<" "<<x<<" "<<0<<" "<<1<<" "<<fdtr(1,n,1,id[tp[x]],id[x],0,1)<<" "<<ans[x]<<endl;
		res-=ans[tp[x]];
//		cout<<ans[tp[x]]<<endl;
		x=f[tp[x]];
		res+=fdtr(1,n,1,id[x],id[x],1,0);
//		cout<<x<<" "<<fdtr(1,n,1,id[x],id[x],1,0)<<endl;
	}
//	cout<<res<<endl;
	if(dep[x]>dep[y]) swap(x,y);
	res-=ans[son[x]];
	res+=fdtr(1,n,1,id[x],id[y],0,1);
	return res;
}

void dfs(int now,int fa)
{
	for(int i=first[now];i!=-1;i=a[i].next)
		dfs(a[i].to,now),ans[now]+=ans[a[i].to];
	int res=0;
	for(int i=0;i<v[now].size();i++)
	{
		Road p=v[now][i];
		ans[now]=max(ans[now],fd(p.u,p.v)+p.w);
	//	cout<<now<<"!"<<p.u<<" "<<fd(p.u,p.v)<<" "<<p.v<<" "<<p.w<<endl;
	}
//	cout<<now<<" "<<ans[now]<<endl;
	if(son[fa]==now) xgtr(1,n,1,id[fa],ans[now],0);
	else xgtr(1,n,1,id[fa],0,ans[now]);
	Ans=max(Ans,ans[now]);
	return;
}

int main()
{
	memset(first,-1,sizeof(first));
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
		scanf("%d",&x),pl(x,i);
	dfs1(1,0); dfs2(1,1); bdtr(1,n,1);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		int l=lca(x,y); v[l].push_back(RD(x,y,z));
	}
	dfs(1,0);
	printf("%d\n",Ans);
	return 0;
}