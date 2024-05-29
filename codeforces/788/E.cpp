#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int n,a[N],m,c[N],cl[N],cr[N],pp[N],len[N],ty,p,q;
VI v,pos[N];
ll ans;
int query(int x) {
	int s=0; for (;x;x-=x&-x) s+=c[x];
	return s;
}
void modify(int x,int s) {
	for (;x<=m;x+=x&-x) c[x]+=s;
}
struct node {
	ll sm,sz,sl,sl2,sr,sr2;
	int vl,vr;
	node *l,*r;
}pool[4*N],*cur=pool,*rt[N];
void upd(node *p) {
	p->sl=p->l->sl+p->r->sl; if (p->sl>=mod) p->sl-=mod;
	p->sr=p->l->sr+p->r->sr; if (p->sr>=mod) p->sr-=mod;
	p->sz=p->l->sz+p->r->sz;
	p->sl2=(p->l->sl2+p->r->sl2+p->l->sl*p->r->sz)%mod;
	p->sr2=(p->l->sr2+p->r->sr2+p->r->sr*p->l->sz)%mod;
	p->sm=(p->l->sm+p->r->sm+p->l->sl2*p->r->sr+p->l->sl*p->r->sr2)%mod;
}
node *build(int l,int r) {
	node *p=cur++;
	if (l==r) {
		p->sz=1; p->sl=p->vl=cl[v[l]]; p->sr=p->vr=cr[v[l]];
	} else {
		int md=(l+r)>>1;
		p->l=build(l,md);
		p->r=build(md+1,r);
		upd(p);
	}
	return p;
}
void modify(node *p,int l,int r,int x,int v) {
	if (l==r) {
		if (v==1) {
			p->sz=1; p->sl=p->vl; p->sr=p->vr;
		} else {
			p->sz=0; p->sl=0; p->sr=0;
		}
	} else {
		int md=(l+r)>>1;
		if (x<=md) modify(p->l,l,md,x,v);
		else modify(p->r,md+1,r,x,v);
		upd(p);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i),v.pb(a[i]);
	sort(all(v)); v.erase(unique(all(v)),v.end());
	m=SZ(v);
	rep(i,1,n+1) a[i]=lower_bound(all(v),a[i])-v.begin()+1;
	rep(i,1,m+1) c[i]=0;
	rep(i,1,n+1) {
		cl[i]=query(a[i]);
		modify(a[i],1);
	}
	rep(i,1,m+1) c[i]=0;
	per(i,1,n+1) {
		cr[i]=query(a[i]);
		modify(a[i],1);
	}
	rep(i,1,n+1) {
		pp[i]=SZ(pos[a[i]]);
		pos[a[i]].pb(i);
	}
	rep(i,1,m+1) {
		v=pos[i];
		len[i]=SZ(pos[i])-1;
		rt[i]=build(0,len[i]);
		ans=(ans+rt[i]->sm)%mod;
	}
	scanf("%d",&q);
	rep(i,0,q) {
		scanf("%d%d",&ty,&p);
		ans-=rt[a[p]]->sm;
		modify(rt[a[p]],0,len[a[p]],pp[p],ty-1);
		ans+=rt[a[p]]->sm;
		ans%=mod; if (ans<0) ans+=mod;
		printf("%lld\n",ans);
	}
}
