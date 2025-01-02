// LUOGU_RID: 158586643
#include<bits/stdc++.h>
using namespace std;
const int NN=3e5+4;
struct node
{
	int l,r,p;
	node()
	{
		l=r=p=0;
	}
	node(int _l,int _r,int _p)
	{
		l=_l,r=_r,p=_p;
	}
	bool operator<(const node&it)const
	{
		if(l!=it.l)
			return l<it.l;
		if(r!=it.r)
			return r<it.r;
		return p<it.p;
	}
}a[NN];
struct segment_tree
{
	int ls,rs,l,r,val;
}tr[NN*80];
int idx=0,root[NN];
void pushup(int u)
{
	tr[u].val=max(tr[tr[u].ls].val,tr[tr[u].rs].val);
}
int build(int l,int r)
{
	int u=++idx;
	tr[u]={0,0,l,r,(int)2e9};
	if(l==r)
		return u;
	int mid=l+(r-l)/2;
	tr[u].ls=build(l,mid);
	tr[u].rs=build(mid+1,r);
	return u;
}
int modify(int u,int x,int v)
{
	int p=++idx;
	tr[p]=tr[u];
	if(tr[u].l==tr[u].r)
	{
		tr[p].val=min(tr[p].val,v);
		return p;
	}
	int mid=tr[u].l+(tr[u].r-tr[u].l)/2;
	if(x<=mid)
		tr[p].ls=modify(tr[u].ls,x,v);
	else
		tr[p].rs=modify(tr[u].rs,x,v);
	pushup(p);
	return p;
}
int query(int u,int l,int r)
{
	if(tr[u].l>=l&&tr[u].r<=r)
		return tr[u].val;
	int mid=tr[u].l+(tr[u].r-tr[u].l)/2,res=0;
	if(l<=mid)
		res=max(res,query(tr[u].ls,l,r));
	if(r>mid)
		res=max(res,query(tr[u].rs,l,r));
	return res;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].p);
	sort(a+1,a+1+k);
	root[k+1]=build(1,n);
	for(int i=k;i;i--)
		root[i]=modify(root[i+1],a[i].p,a[i].r);
	while(m--)
	{
		int l,r,x,y;
		scanf("%d%d%d%d",&l,&r,&x,&y);
		puts(query(root[lower_bound(a+1,a+1+k,node(x,0,0))-a],l,r)>y?"no":"yes");
		fflush(stdout);
	}
	return 0;
}