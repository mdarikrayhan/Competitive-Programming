#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lson (u<<1)
#define rson (u<<1|1)
const ll N=100007,MOD=1e9+7;
struct edge{
	ll to,nxt;
}e[N<<1];
ll n,m,q,hd[N],nE,a[N],prime[N],nP,tI[N],tO[N],timer,_[N],ok[N],tag[N<<2];
bitset<1000> val[N<<2],I;
void add(ll u,ll v){e[++nE]=(edge){v,hd[u]};hd[u]=nE;}
void dfs(ll u,ll fa){
	a[tI[u]=++timer]=_[u]%m;
	for (int i=hd[u],v;i;i=e[i].nxt) if ((v=e[i].to)!=fa) dfs(v,u);
	tO[u]=timer;
}
void pushdown(ll u){
	if (!tag[u]) return;
	val[lson]=(val[lson]>>m-tag[u])|(val[lson]<<tag[u]);
	(tag[lson]+=tag[u])%=m;
	val[rson]=(val[rson]>>m-tag[u])|(val[rson]<<tag[u]);
	(tag[rson]+=tag[u])%=m;
	tag[u]=0;
}
#define pushup(u) val[u]=val[u<<1]|val[u<<1|1]
void build(ll u,ll l,ll r){
	if (l==r){
		val[u].set(a[l]);return;
	}
	ll mid=l+r>>1;
	build(lson,l,mid);build(rson,mid+1,r);
	pushup(u);
}
void upd(ll u,ll l,ll r,ll L,ll R,ll v){
	if (L<=l&&r<=R){
		val[u]=(val[u]>>m-v)|(val[u]<<v);
		(tag[u]+=v)%=m;
		return;
	}
	pushdown(u);
	ll mid=l+r>>1;
	if (L<=mid) upd(lson,l,mid,L,R,v);
	if (R>mid) upd(rson,mid+1,r,L,R,v);
	pushup(u);
}
bitset<1000> query(ll u,ll l,ll r,ll L,ll R){
	if (L<=l&&r<=R) return val[u];
	if (L>r||l>R) return I;
	pushdown(u);
	ll mid=l+r>>1;
	return query(lson,l,mid,L,R)|query(rson,mid+1,r,L,R);
}
int main(){
	cin>>n>>m;
	for (int i=2;i<m;++i) if (!ok[i]){
		prime[++nP]=i;
		for (int j=i<<1;j<m;j+=i) ok[j]=1;
	}
	for (int i=1;i<=n;++i) cin>>_[i];
	for (int i=1,u,v;i<n;++i){
		cin>>u>>v;add(u,v);add(v,u);
	}
	dfs(1,0);build(1,1,n);
	cin>>q;
	ll op,x,y;
	while(q--){
		cin>>op>>x;
		if (op==1){
			cin>>y;y%=m;
			upd(1,1,n,tI[x],tO[x],y);
		}
		else{
			auto bs=query(1,1,n,tI[x],tO[x]);
			ll ans=0;
			for (int i=1;i<=nP;++i) ans+=bs[prime[i]];
			cout<<ans<<endl;
		}
	}
	return 0;
}