// LUOGU_RID: 160430876
#include <iostream>
#define ll long long
#define ls(p) p<<1
#define rs(p) p<<1|1
using namespace std;
int read(){
	int re=0,c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') re=(re<<3)+(re<<1)+(c^48),c=getchar();
	return re;
}
const int maxn=3e5+5,maxp=1.2e6;
struct V{
	int v,c;
}vs[maxp],z;
int n,pl,a[maxn],la[maxn],lt[maxp],st[maxn],hd;
ll ans;
V mg(V vl,V vr){
	if(vl.v>vr.v) return vr;
	if(vr.v>vl.v) return vl;
	return (V){vl.v,vl.c+vr.c};
}
void pd(int l,int r,int p)
{
	if(!lt[p]) return;
	int mid=(l+r)>>1;
	lt[ls(p)]=lt[p],vs[ls(p)]=(V){lt[p]+l,1};
	lt[rs(p)]=lt[p],vs[rs(p)]=(V){lt[p]+mid+1,1};
	lt[p]=0;
}
void upd(int l,int r,int p,int cl,int cr,int v)
{
	if(cl<=l&&cr>=r) return lt[p]=v,vs[p]=(V){v+l,1},void();
	pd(l,r,p);
	int mid=(l+r)>>1;
	if(cl<=mid) upd(l,mid,ls(p),cl,cr,v);
	if(cr>mid) upd(mid+1,r,rs(p),cl,cr,v);
	vs[p]=mg(vs[ls(p)],vs[rs(p)]);
}
V qr(int l,int r,int p,int cl,int cr)
{
	if(cl<=l&&cr>=r) return vs[p];
	pd(l,r,p);
	int mid=(l+r)>>1;
	V rl=cl<=mid?qr(l,mid,ls(p),cl,cr):z,rr=cr>mid?qr(mid+1,r,rs(p),cl,cr):z;
	return mg(rl,rr);
}
int main()
{
	n=read();
	z=(V){maxp,0};
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),pl=max(pl,la[a[i]]+1),la[a[i]]=i;
		while(hd&&a[st[hd]]<a[i]) upd(1,n,1,st[hd-1]+1,st[hd],a[i]),hd--;
		st[++hd]=i,upd(1,n,1,i,i,a[i]);
		V tp=qr(1,n,1,pl,i);
		if(tp.v==i+1) ans+=tp.c;
	}
	cout<<ans<<endl;return 0;
}