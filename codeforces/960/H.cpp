#include <iostream>
#include <vector>
#include <iomanip>
#define mid ((l+r)>>1)
using namespace std;

const int maxm=9000005;
const int maxn=50005;
int n,m,q,op,x,y,c[maxn],fa[maxn],dfn[maxn],top[maxn],w[maxn],siz[maxn],mxson[maxn],cnt;
int ls[maxm],rs[maxm],tag[maxm],rt[maxn],tot;
long long sq[maxm],sum[maxm];
long long C,ans1,ans2;
long double ans;
vector<int>G[maxn];

void dfs1(int u)
{
	int sz=G[u].size();siz[u]=1;
	for (int i=0;i<sz;i++)
	{
		int v=G[u][i];dfs1(v);siz[u]+=siz[v];
		if (siz[v]>siz[mxson[u]]){mxson[u]=v;}
	}
}

void dfs2(int u,int tp)
{
	top[u]=tp;dfn[u]=++cnt;
	if (mxson[u])
	{
		dfs2(mxson[u],tp);
	}
	int sz=G[u].size();
	for (int i=0;i<sz;i++)
	{
		int v=G[u][i];
		if (v!=mxson[u])
		{
			dfs2(v,v);
		}
	}
}

void pushup(int id)
{
	sq[id]=sq[ls[id]]+sq[rs[id]];sum[id]=sum[ls[id]]+sum[rs[id]];
}
void modify(int id,int l,int r,int val)
{
	long long len=r-l+1;
	sq[id]+=len*val*val+sum[id]*val*2;
	sum[id]+=len*val;
	tag[id]+=val;
}
void pushdown(int id,int l,int r)
{
	if (!ls[id]){ls[id]=++tot;}
	if (!rs[id]){rs[id]=++tot;}
	modify(ls[id],l,mid,tag[id]);modify(rs[id],mid+1,r,tag[id]);
	tag[id]=0;
}
void update(int &id,int l,int r,int ql,int qr,int val)
{
	if (l>qr||r<ql){return;}
	if (!id){id=++tot;}
	if (l>=ql&&r<=qr)
	{
		modify(id,l,r,val);return;
	}
	pushdown(id,l,r);
	update(ls[id],l,mid,ql,qr,val);update(rs[id],mid+1,r,ql,qr,val);
	pushup(id);
}
void add(int x,int y,int val)
{
	while (x)
	{
		int l=dfn[top[x]],r=dfn[x];
		update(rt[y],1,n,l,r,val);
		x=fa[top[x]];
	}
}
int main()
{
	cin>>n>>m>>q>>C;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for (int i=2;i<=n;i++)
	{
		cin>>fa[i];G[fa[i]].push_back(i);
	}
	for (int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	dfs1(1);dfs2(1,1);
	for (int i=1;i<=n;i++)
	{
		add(i,c[i],1);
	} 
	for (int i=1;i<=q;i++)
	{
		cin>>op;
		if (op==1)
		{
			cin>>x>>y;
			if (c[x]!=y)
			{
				add(x,c[x],-1);
				add(x,y,1); 
				c[x]=y;
			}
		}
		else
		{
			cin>>x;
			ans1=sq[rt[x]]*w[x]*w[x];ans2=sum[rt[x]]*w[x];
			ans=ans1-ans2*C*2+C*C*n;
			cout<<fixed<<setprecision(7)<<ans/n<<endl;
		}
	}
}