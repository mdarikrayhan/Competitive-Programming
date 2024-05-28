#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fi first
#define se second
#define pir pair<ll,ll>
#define mkp make_pair
#define pb push_back
using namespace std;
const ll maxn=1e6+10;
ll n, m, a[maxn], d[maxn];
char op[2];
ll ch[maxn][2], dfn[maxn], out[maxn], tim, cnt, ti[maxn];
struct oper {ll typ, x, y;} q[maxn];
ll find(ll x) {return d[x]==x? x:d[x]=find(d[x]);}
void dfs(ll u){
	dfn[u]=tim+1;
	if(u<=n) {
		out[u]=++tim;
		return;
	}
	dfs(ch[u][0]), dfs(ch[u][1]);
	out[u]=tim;
}
struct SGT{
	ll tag[maxn<<2];
	void addtag(ll p,ll v) {tag[p]=v;}
	void pushdown(ll p){
		if(!tag[p]) return;
		addtag(p<<1,tag[p]);
		addtag(p<<1|1,tag[p]);
		tag[p]=0;
	}
	void modify(ll p,ll l,ll r,ll ql,ll qr,ll v){
		if(ql<=l&&r<=qr){
			addtag(p,v); return;
		}
		ll mid=l+r>>1; pushdown(p);
		if(ql<=mid) modify(p<<1,l,mid,ql,qr,v);
		if(mid<qr) modify(p<<1|1,mid+1,r,ql,qr,v);
	}
	ll query(ll p,ll l,ll r,ll x){
		if(l==r) return tag[p];
		ll mid=l+r>>1; pushdown(p);
		if(x<=mid) return query(p<<1,l,mid,x);
		else return query(p<<1|1,mid+1,r,x);
	}
} T;
ll tree[maxn];
void add(ll x,ll v){
	while(x<=n){
		tree[x]+=v; x+=x&-x;
	}
}
ll ask(ll x){
	ll v=0;
	while(x){
		v+=tree[x]; x-=x&-x;
	} return v;
}
vector<ll> vec[maxn];
ll ans[maxn], qid;
int main(){
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;i++){
		scanf("%s",op);
		if(op[0]=='U'){
			scanf("%lld%lld",&q[i].x,&q[i].y);
			q[i].typ=1;
		} else if(op[0]=='M'){
			scanf("%lld%lld",&q[i].x,&q[i].y);
			q[i].typ=2;
		} else if(op[0]=='A'){
			scanf("%lld",&q[i].x);
			q[i].typ=3;
		} else if(op[0]=='Z'){
			scanf("%lld",&q[i].x);
			q[i].typ=4;
		} else {
			scanf("%lld",&q[i].x);
			q[i].typ=5, q[i].y=++qid;
		}
	} cnt=n;
	for(ll i=1;i<=n;i++) d[i]=i;
	for(ll i=1;i<=m;i++) 
		if(q[i].typ==2){
			ll u=find(q[i].x), v=find(q[i].y);
			++cnt, ch[cnt][0]=u, ch[cnt][1]=v;
			d[u]=d[v]=d[cnt]=cnt;
		}
	for(ll i=cnt;i;i--)
		if(!dfn[i]) dfs(i);
	cnt=n;
	for(ll i=1;i<=n;i++) d[i]=i;
	for(ll i=1;i<=m;i++)
		if(q[i].typ==2){
			ll u=find(q[i].x), v=find(q[i].y);
			++cnt, d[u]=d[v]=d[cnt]=cnt;
		} else if(q[i].typ==4){
			ll u=find(q[i].x);
			T.modify(1,1,n,dfn[u],out[u],i);
		} else if(q[i].typ==5){
			ll t=T.query(1,1,n,dfn[q[i].x]);
			vec[t].pb(i);
		}
	cnt=n;
	for(ll i=1;i<=n;i++) d[i]=i;
	for(ll i=1;i<=m;i++)
		if(q[i].typ==1){
			ll u=find(q[i].x), v=find(q[i].y);
			++cnt, ch[cnt][0]=u, ch[cnt][1]=v;
			d[u]=d[v]=d[cnt]=cnt;
		}
	memset(dfn,0,sizeof dfn);
	tim=0;
	for(ll i=cnt;i;i--)
		if(!dfn[i]) dfs(i);
	for(ll i=1;i<=n;i++) d[i]=i, vec[ti[i]].pb(i);
	cnt=n;
	for(ll i=1;i<=m;i++){
		if(q[i].typ==1){
			ll u=find(q[i].x), v=find(q[i].y);
			++cnt, d[u]=d[v]=d[cnt]=cnt;
		} else if(q[i].typ==3){
			ll u=find(q[i].x);
			add(dfn[u],out[u]-dfn[u]+1);
			add(out[u]+1,-out[u]+dfn[u]-1);
		} else if(q[i].typ==5) {
			ans[q[i].y]+=ask(dfn[q[i].x]);
		}
		for(ll j:vec[i])
			ans[q[j].y]-=ask(dfn[q[j].x]);
	}
	for(ll i=1;i<=qid;i++) printf("%lld\n",ans[i]);
	return 0;
}