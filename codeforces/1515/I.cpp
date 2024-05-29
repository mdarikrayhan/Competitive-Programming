#include <bits/stdc++.h>

#define N 200005
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f3f3f3f3fll

typedef long long ll;

using namespace std;

int mp[N];
struct node
{
	ll x,w,v;int id;
}a[N];
struct segtree
{
	int d;
	ll tr[N*4],sm[N*4],s2[N*4];
	void up(int rt)
	{
		sm[rt]=sm[rt<<1]+sm[rt<<1|1];
		s2[rt]=s2[rt<<1]+s2[rt<<1|1];
		tr[rt]=min(tr[rt<<1],sm[rt<<1]+tr[rt<<1|1]);
	}
	void updt(int p,int l,int r,int rt)
	{
		if(l==r)
		{
			if(a[r].w>=(1<<d)){tr[rt]=a[r].x?a[r].w:inf;sm[rt]=s2[rt]=0;}
			else{tr[rt]=inf;sm[rt]=1ll*a[r].x*a[r].w;s2[rt]=1ll*a[r].x*a[r].v;}
			return;
		}
		int m=(l+r)>>1;
		if(p<=m)updt(p,lson);
		else updt(p,rson);
		up(rt);
	}
}A[20];

ll ans;
void que(ll& w,int l,int r,int rt)
{
	if(w==0)return;
	if(l==r)
	{
		ll k=min(1ll*a[r].x,w/a[r].w);
		w-=k*a[r].w;ans+=k*a[r].v;
		return;
	}
	int m=(l+r)>>1;
	if(__lg(w)>=20)
	{
		if(w>=A[19].sm[rt]){w-=A[19].sm[rt];ans+=A[19].s2[rt];}
		else{que(w,lson);que(w,rson);}
		return;
	}
	if(A[__lg(w)].sm[rt]<=w&&w<A[__lg(w)].tr[rt]){ans+=A[__lg(w)].s2[rt];w-=A[__lg(w)].sm[rt];return;}
	que(w,lson);que(w,rson);
}

int main()
{
	int i,j,n,T,ty;
	scanf("%d %d",&n,&T);
	for(i=1;i<=n;++i){scanf("%lld %lld %lld",&a[i].x,&a[i].w,&a[i].v);a[i].id=i;}
	sort(a+1,a+n+1,[](node a,node b){return a.v!=b.v?a.v>b.v:a.w<b.w;});
	for(i=0;i<20;++i){A[i].d=i;for(j=1;j<=n;++j)A[i].updt(j,1,n,1);}
	for(i=1;i<=n;++i)mp[a[i].id]=i;
	while(T--)
	{
		int x,y;
		scanf("%d",&ty);
		if(ty==1||ty==2)
		{
			scanf("%d %d",&y,&x);
			if(ty==1)a[mp[x]].x+=y;else a[mp[x]].x-=y;
			for(i=0;i<20;++i)A[i].updt(mp[x],1,n,1);
		}
		else
		{
			ll w;scanf("%lld",&w);
			ans=0;que(w,1,n,1);printf("%lld\n",ans);
		}
	}
	return 0;
}
