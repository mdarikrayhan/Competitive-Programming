#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll N=2e5+2,M=(1<<19)+2;
ll n,m,q;
multiset<pii>s;
namespace BIT{
	ll a[N];
	void add(ll x,ll y){for(;x<=n;x+=x&-x)a[x]+=y;}
	ll sum(ll x,ll y=0){for(;x;x-=x&-x)y+=a[x];return y;}
	ll qry(ll L,ll R){return sum(R)-sum(L-1);}
}
namespace Tree{
	ll k,h[N],dfn[N],dfm[N],c[N][20];
	vector<ll>e[N];
	void dfs(ll x,ll y){
		dfn[x]=++k,h[x]=h[y]+1,c[x][0]=y;
		for(ll i=1;i<20;i++)
			c[x][i]=c[c[x][i-1]][i-1];
		for(ll i:e[x])
			if(i!=y)dfs(i,x);
		dfm[x]=k;
	}
	ll kfa(ll x,ll y){
		for(ll i=19;~i;i--)
			if(y>=(1<<i))y-=(1<<i),x=c[x][i];
		return max(x,1ll);
	}
	ll lca(ll x,ll y){
		if(h[x]<h[y])swap(x,y);
		for(ll i=19;~i;i--)
			if(h[c[x][i]]>=h[y])x=c[x][i];
		for(ll i=19;~i;i--)
			if(c[x][i]!=c[y][i])x=c[x][i],y=c[y][i];
		if(x!=y)x=c[x][0];
		return x;
	}
	void add(ll x,ll y){e[x].pb(y),e[y].pb(x);}
	void mdf(ll x,ll c){BIT::add(dfn[x],c);}
	ll qry(ll x){return BIT::qry(dfn[x],dfm[x]);}
	ll dis(ll x,ll y){return h[x]+h[y]-2*h[lca(x,y)];}
}
namespace dia{
	pii a[M];ll b[N];
	pii operator+(pii x,pii y){
		if(!x.fi)return y;
		if(!y.fi)return x;
		pii ans={0,0};
		ll d=-1,a[]={x.fi,x.se,y.fi,y.se};
		for(ll i=0;i<4;i++)
			for(ll j=i+1;j<4;j++){
				ll x=Tree::dis(a[i],a[j]);
				if(x>d)d=x,ans={a[i],a[j]};
			}
		return ans;
	}
	void opt(ll p,pii c,ll x=1,ll l=1,ll r=n){
		if(p<l||p>r)return;
		if(l==r)return a[x]=c,[]{}();
		opt(p,c,x<<1,l,l+r>>1);
		opt(p,c,x<<1|1,l+r+2>>1,r);
		a[x]=a[x<<1]+a[x<<1|1];
	}
	pii qry(ll L,ll R,ll x=1,ll l=1,ll r=n){
		if(l>R||L>r||L>R||l>r)return{0,0};
		if(L<=l&&r<=R)return a[x];
		pii s=qry(L,R,x<<1,l,l+r>>1);
		s=s+qry(L,R,x<<1|1,l+r+2>>1,r);
		return s;
	}
	void mdf(ll x,ll t){
		b[x]+=t,opt(Tree::dfn[x],{(b[x]>0)*x,(b[x]>0)*x});
	}
	ll dia(ll x,ll y){
		pii p=qry(Tree::dfn[x],Tree::dfm[x]);
		return max(Tree::dis(p.fi,y),Tree::dis(p.se,y));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(ll i=1,x,y;i<n;i++)
		cin>>x>>y,Tree::add(x,y);
	Tree::dfs(1,0);
	while(q--){
		ll t,x,y,z;cin>>t;
		if(t<3){
			cin>>x>>y,t=3-2*t,z=Tree::lca(x,y);
			Tree::mdf(x,t),Tree::mdf(y,t);
			Tree::mdf(z,-t),dia::mdf(z,t);
			if(t>0)s.insert({-Tree::h[z],z});
			else s.erase(s.find({-Tree::h[z],z}));
		}
		else cin>>m,x=Tree::kfa(s.begin()->se,m),y=Tree::kfa(x,m),
			cout<<(Tree::qry(y)<s.size()||dia::dia(y,x)>m?"No\n":"Yes\n");
	}
	return 0;
}