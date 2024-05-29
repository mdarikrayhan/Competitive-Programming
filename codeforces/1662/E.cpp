// LUOGU_RID: 157930401
#include<cstdio>
using namespace std;
struct SegmentTree
{
	struct nd
	{
		int l,r,sum;
	}t[1200000];
	void build(int l,int r,int k=1)
	{
		int mid=(l+r)>>1;t[k].l=l,t[k].r=r,t[k].sum=0;if(l==r)return;
		build(l,mid,k<<1),build(mid+1,r,k<<1|1);
	}
	void update(int k){t[k].sum=t[k<<1].sum+t[k<<1|1].sum;}
	void add(int pos,int val,int k=1)
	{
		t[k].sum+=val;if(t[k].l==t[k].r)return;
		int mid=(t[k].l+t[k].r)>>1;if(pos<=mid)add(pos,val,k<<1);else add(pos,val,k<<1|1);
	}
	int query(int l,int r,int k=1)
	{
		if(l>t[k].r||r<t[k].l)return 0;
		if(l<=t[k].l&&t[k].r<=r){return t[k].sum;}
		return query(l,r,k<<1)+query(l,r,k<<1|1);
	}
}T;
int n;
int query(int l,int r)
{
	if(l<r)return T.query(l,r);return T.query(l,n)+T.query(1,r);
}
int p[300000],f[300000];
int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		scanf("%d",&n);for(int i=1;i<=n;i++){scanf("%d",&p[i]);f[p[i]]=i;}
		T.build(1,n);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i>=3)ans+=(long long)(query(f[i-1],f[i])-1)*(n-i+1);
			T.add(f[i],1);
			
		}
		printf("%lld\n",ans);
	}
}