#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int N = 1e6+10,INF = 2e9,M = 1e6+1;

int n,m,p;
int b[N],cb[N];
int w[N];

struct moster
{
	int x,y,z;
	bool operator<(const moster& W)const
	{
		return x<W.x;
	}
};

struct Node
{
	int l,r;
	int tmax,add;
}tr[N*4];
vector<PII> weapon;
vector<moster> mon;

void pushup(int u)
{
	tr[u].tmax=max(tr[u<<1].tmax,tr[u<<1|1].tmax);
}
void pushdown(int u)
{
	if(tr[u].add)
	{
		tr[u<<1].add+=tr[u].add;
		tr[u<<1|1].add+=tr[u].add;
		tr[u<<1].tmax+=tr[u].add;
		tr[u<<1|1].tmax+=tr[u].add;
		tr[u].add=0;
	}
}
void build(int u,int l,int r)
{
	if(l==r) tr[u]={l,r,w[l],0};
	else
	{
		tr[u]={l,r};
		int mid=l+r>>1;
		build(u<<1,l,mid);
		build(u<<1|1,mid+1,r);
		pushup(u);
	}
}
void modify(int u,int l,int r,int d)
{
	if(tr[u].l>=l && tr[u].r<=r)
	{
		tr[u].tmax+=d;
		tr[u].add+=d;
	}
	else
	{
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		if(l<=mid) modify(u<<1,l,r,d);
		if(r>mid) modify(u<<1|1,l,r,d);
		pushup(u);
	}
}
int query(int u,int l,int r)
{
	if(tr[u].l>=l && tr[u].r<=r) return tr[u].tmax;
	else
	{
		pushdown(u);
		int mid=tr[u].l+tr[u].r>>1;
		int res=-2e9;
		if(l<=mid) res=query(u<<1,l,r);
		if(r>mid) res=max(res,query(u<<1|1,l,r));
		
		return res;
	}
}
void solve()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++) 
	{
		int x,y;
		scanf("%d%d",&x,&y);
		weapon.push_back({x,y});
	}
	
	for(int i=1;i<=M;i++) w[i]=-INF;
	
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		w[x]=max(w[x],-y);
	}
	
	build(1,1,M);
	for(int i=1;i<=p;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		mon.push_back({x,y,z});
	}
	sort(weapon.begin(),weapon.end());
	sort(mon.begin(),mon.end());
	
	int cur=0,ans=-2e9;
	for(int i=0;i<weapon.size();i++)
	{
		while(cur<p && mon[cur].x<weapon[i].first)
		{
			modify(1,mon[cur].y+1,M,mon[cur].z);
			cur++;
		}
		ans=max(ans,-weapon[i].second+query(1,1,M));
	}
	printf("%d\n",ans);
}
int main()
{
	solve();
	return 0;
}