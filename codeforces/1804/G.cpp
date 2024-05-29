// LUOGU_RID: 113126013
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,b,tg[N<<2];
ll ans;
struct node{
	ll mx,mn,ct,sum;
}tr[N<<2],O;
struct qry{
	int l,x,v;
	bool operator <(const qry a)const{return l<a.l;}
}q[N<<1];
#define L k<<1
#define R k<<1|1
#define mn(k) tr[k].mn
#define mx(k) tr[k].mx
#define ct(k) tr[k].ct
#define sum(k) tr[k].sum
inline node operator +(node a,node b){
	node c;
	c.mn=min(a.mn,b.mn);
	c.mx=max(a.mx,b.mx);
	c.ct=a.ct+b.ct;
	c.sum=a.sum+b.sum;
	return c;
}
inline bool operator ==(node a,node b){
	return a.mn==b.mn&&a.mx==b.mx&&a.sum==b.sum&&a.ct==b.ct;
}
void pushtg(int k,int v){
	mn(k)+=v,mx(k)+=v,tg[k]+=v;
	sum(k)+=ct(k)*v;
}
void pushdown(int k){
	if(tg[k]){
		pushtg(L,tg[k]);
		pushtg(R,tg[k]);
		tg[k]=0;
	}
}
void pushup(int k){
	tr[k]=tr[L]+tr[R];
}
void ins(int k,int l,int r,int x,int v){
	if(l==r){
		if(v)tr[k]={v,v,1,v};
		else tr[k]=O;
		return;
	}
	int mid=l+r>>1;
	pushdown(k);
	if(x<=mid)ins(L,l,mid,x,v);
	else ins(R,mid+1,r,x,v);
	pushup(k);
}
void div(int k){
	if(!ct(k))return;
	if((mx(k)+1>>1)==(mn(k)+1>>1))return pushtg(k,-(mx(k)+1>>1));
	pushdown(k);
	div(L),div(R);
	pushup(k);
}
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1,l,r,v;i<=n;++i){
		scanf("%d%d%d",&l,&r,&v);
		q[++m]={l,i,v};
		q[++m]={r+1,i,0};
	}
	O.mx=-1e18,O.mn=1e18;
	for(int i=1;i<n<<2;++i)tr[i]=O;
	sort(q+1,q+m+1);
	for(int i=1,nw=0;i<=m;++i){
		node lv=O;int lp=-1;ll la=-1;
		while(nw<q[i].l){
			node v=tr[1];
			if(!v.ct){
				nw=q[i].l;
				break;
			}
			if(v==lv){
				int t=(q[i].l-nw)/(nw-lp);
				nw+=(nw-lp)*t;
				ans+=(ans-la)*t;
			}
			lv=v,lp=nw,la=ans;
			int t=max(0ll,min((b-v.sum+v.ct)/v.ct,(ll)q[i].l-nw));
			nw+=t;
			ans+=1ll*v.sum*t+1ll*v.ct*t*(t-1)/2;
			pushtg(1,t);
			if(nw==q[i].l)break;
			++nw,div(1);
		}
		ins(1,1,n,q[i].x,q[i].v);
	}
	printf("%lld\n",ans);
	return 0;
}