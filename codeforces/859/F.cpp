#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=5e5+5;
int n,c,a[INF],b[INF],b2[INF];
struct Segment{
	#define ll tl[id]
	#define rr tr[id]
	#define ls(x) x<<1
	#define rs(x) x<<1|1
	int tl[INF<<2],tr[INF<<2],lazy[INF<<2],sum[INF<<2];
	void push_up(int id) {sum[id]=max(sum[ls(id)],sum[rs(id)]);}
	void push_down(int id) {
		if (!lazy[id]) return ;
		int rt=ls(id);
		sum[rt]+=lazy[id];
		lazy[rt]+=lazy[id];

		rt=rs(id);
		sum[rt]+=lazy[id];
		lazy[rt]+=lazy[id];
		
		lazy[id]=0;
	}
	void build(int l,int r,int id) {
		ll=l;rr=r;
		if (ll==rr) {sum[id]=-a[l*2-2];return ;}
		int Mid=(l+r)>>1;
		build(ll,Mid,ls(id));
		build(Mid+1,rr,rs(id));
		push_up(id);
	}
	void add(int l,int r,int x,int id) {
		if (l<=ll && rr<=r) {
			sum[id]+=x;
			lazy[id]+=x;
			return ;
		}
		push_down(id);
		int Mid=(ll+rr)>>1;
		if (l<=Mid) add(l,r,x,ls(id));
		if (Mid<r) add(l,r,x,rs(id));
		push_up(id);
	} 
	int query(int l,int r,int id) {
		if (l<=ll && rr<=r) return sum[id];
		int Mid=(ll+rr)>>1;push_down(id);
		if (l>Mid) return query(l,r,rs(id));
		else if (r<=Mid) return query(l,r,ls(id));
		else return max(query(l,r,ls(id)),query(l,r,rs(id)));
	}
	#undef ll
	#undef rr
	#undef ls
	#undef rs
}T1;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>c;
	for (int i=1;i<=n*2-1;i++) cin>>a[i],a[i]+=a[i-1];
	T1.build(1,n,1);
	for (int r=1;r<=n;r++) {
		
		int ll=1,rr=r,ans=-1;
		while (ll<=rr) {
			int Mid=(ll+rr)>>1;
			if (a[r*2-1]-a[(Mid)*2-2]<=c) rr=(ans=Mid)-1;
			else ll=Mid+1;
		}
		if (ans==-1) {b[r]=c;b2[r]=b2[r-1]+b[r];continue;}
		int Max=0;
		if (ans*2-4>=0) {
			// if (r==2) cerr<<ans<<" qwejweroijwaer\n";
			int xx=a[r*2-1]-a[ans*2-4];
			xx=min(xx,c);
			if (ans-2<=r-1) xx-=b2[r-1]-b2[ans-2];
			Max=max(Max,xx);
		}
		Max=max(Max,T1.query(ans,r,1)+a[r*2-1]);
		T1.add(1,r,-Max,1);
		b2[r]=b2[r-1]+Max;
		b[r]=Max;

		/*
		int sum6=0,Max=0;
		for (int l=r;l;l--) {
			sum6+=b[l];
			int i=2*r-1,j=2*l-1;
			int xx=a[i]-a[j-1];
			xx=min(xx,c);
			Max=max(Max,xx-sum6);
		}
		b[r]=Max;
		ans+=Max;
		*/
	}
	cout<<b2[n]<<"\n";
	return 0;
}