// LUOGU_RID: 160375238
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
const ll N=2024,M=1e5+2;
ll n,m,k,h,ans,f[N],g[N],L[N],R[N];
struct node{ll x,y,z;}b[N],c[N];
namespace net{
	const ll P=1e14;
	ll k=1,z,c[M],d[N],f[N],g[N];
	vector<pii>e[N];
	void add(ll x,ll y,ll z=P){
		e[x].pb({y,++k}),c[k]+=z,e[y].pb({x,++k});
	}
	void clear(){
		k=1;
		memset(c,0,sizeof(c));
		for(ll i=0;i<N;i++)
			f[i]=0,e[i].clear();
	}
	ll dfs(ll x,ll y){
		if(x==z)return y;
		ll r,p=0;
		while(g[x]<e[x].size()&&y){
			pii i=e[x][g[x]];
			if(d[i.fi]==d[x]+1&&c[i.se])
				r=dfs(i.fi,min(y,c[i.se])),
				c[i.se]-=r,c[i.se^1]+=r,y-=r,p+=r;
			if(y)g[x]++;
		}
		return p;
	}
	ll flow(ll s,ll t){
		ll ans=0;z=t;
		do{
			queue<ll>q;
			memset(d,0,sizeof(d));
			memset(g,0,sizeof(g));
			q.push(s),d[s]=1;
			while(q.size()){
				ll x=q.front();q.pop();
				for(pii i:e[x])
					if(!d[i.fi]&&c[i.se])
						d[i.fi]=d[x]+1,q.push(i.fi);
			}
			ans+=dfs(s,P);
		}while(d[t]);
		return ans;
	}
	void construct(ll x){
		if(f[x])return;
		f[x]=1;
		for(pii i:e[x])
			if(c[i.se])construct(i.fi);
	}
}
void init(){
	net::clear();
	ll p=0,q=0;
	for(ll i=1;i<=n;i++)
		if(!f[i]){
			if(!p)p=i;
			else q=i;
		}
	if(p&&q){
		for(ll i=1;i<=m;i++)
			net::add(c[i].x,c[i].y,c[i].z),
			net::add(c[i].y,c[i].x,c[i].z);
		ll d=net::flow(p,q);
		ans+=d,b[++h]={p,q,d};
		net::construct(p),d=++k;
		for(ll i=1;i<=n;i++)
			if(!f[i]&&net::f[i])f[i]=d;
		init();
		for(ll i=1;i<=n;i++)
			if(f[i]==d)f[i]=0;
			else if(!f[i])f[i]=d;
		init();
		for(ll i=1;i<=n;i++)
			if(f[i]==d)f[i]=0;
	}
}
ll find(ll x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(ll x,ll y){
	x=find(x),y=find(y);
	g[R[x]]=L[y];
	L[y]=L[x],f[x]=y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1,x,y,z;i<=m;i++)
		cin>>x>>y>>z,c[i]={x,y,z};
	init();
	cout<<ans<<'\n';
	for(ll i=1;i<=n;i++)f[i]=L[i]=R[i]=i;
	sort(b+1,b+n,[](node x,node y){return x.z>y.z;});
	for(ll i=1;i<n;i++)merge(b[i].x,b[i].y);
	ll x=L[find(1)];
	while(x)cout<<x<<' ',x=g[x];
	return 0;
}