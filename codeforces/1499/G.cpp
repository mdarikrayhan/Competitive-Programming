#include<bits/stdc++.h>
using namespace std;
#define ll int
const ll N=400007,MOD=998244353;
ll n1,n2,n,m,q,fa[N],to[N],sum[N][2],bit[N],ans;
bool rev[N];
ll getfa(ll x){
	if (fa[x]==x) return x;
	if (fa[fa[x]]==fa[x]) return fa[x];
	ll tmp=getfa(fa[x]);
	rev[x]^=rev[fa[x]];
	return fa[x]=tmp;
}
bool getrev(ll x){
	if (fa[x]==x) return rev[x];
	ll f=getfa(x);
	return rev[x]^rev[f];
}
void merge(ll x,ll y){
	x=getfa(x);y=getfa(y);
	if (x==y) return;
	(ans+=MOD-sum[x][rev[x]])%=MOD;
	(ans+=MOD-sum[y][rev[y]])%=MOD;
	rev[x]^=rev[y];
	fa[x]=y;
	(sum[y][0]+=sum[x][rev[x]])%=MOD;
	(sum[y][1]+=sum[x][rev[x]^1])%=MOD;
	(ans+=sum[y][rev[y]])%=MOD;
}
void reverse(ll x){
	x=getfa(x);
	(ans+=MOD-sum[x][rev[x]])%=MOD;
	rev[x]^=1;
	(ans+=sum[x][rev[x]])%=MOD;
}
void link(ll x,ll y,ll id){
	sum[id][1]=bit[id]=(bit[id-1]<<1)%MOD;
	fa[id]=id;
	if (!to[x]&&!to[y]){
		reverse(id);to[x]=to[y]=id;
		return;
	}
	if (!to[x]) swap(x,y);
	if (!to[y]){
		if (!getrev(to[x])) reverse(id);
		merge(to[x],id);
		to[x]=0;to[y]=id;return;
	}
	if (getrev(to[x])!=getrev(to[y])) reverse(to[x]);
	if (!getrev(to[x])) reverse(id);
	merge(to[x],id);merge(to[y],id);
	to[x]=to[y]=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n1>>n2>>m;n=n1+n2;
	bit[0]=1;
	for (int i=1,x,y;i<=m;++i){
		cin>>x>>y;
		link(x,y+n1,i);
	}
	cin>>q;
	ll op,x,y;
	while(q--){
		cin>>op;
		if (op==1){
			cin>>x>>y;
			link(x,y+n1,++m);
			cout<<ans<<'\n';
		}
		else{
			ll cnt=0;
			for (int j=1;j<=m;++j) cnt+=getrev(j);
			cout<<cnt<<'\n';
			for (int j=1;j<=m;++j) if (getrev(j)) cout<<j<<' ';cout<<'\n';
		}
	}
	return 0;
}