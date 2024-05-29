// LUOGU_RID: 160314849
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+9;
const ll M=1e7+9;
const ll INF=1e18+9;
const ll lim=1e14+9;
const ll w=100;
ll n,m,s,t,a[N],b[N],c[N],l[N],r[N],id[59][209],cnt;
inline ll calc(ll x,ll i){
	return a[i]*x*x+b[i]*x+c[i];
}
struct Dinic{
    struct Edge{ll u,v,nxt;} Eg[M];
    ll hd[N],tot=1;
    void add(ll x,ll y,ll z){
	    tot++; Eg[tot]=(Edge){y,z,hd[x]}; hd[x]=tot;
        tot++; Eg[tot]=(Edge){x,0,hd[y]}; hd[y]=tot;
    }
    ll d[N];
    queue<ll> q;
    bool bfs(){
	    for(ll i=1;i<=cnt;i++) d[i]=0;
	    while(!q.empty()) q.pop();
	    q.push(s); d[s]=1;
	    while(!q.empty()){
		    ll pre=q.front(); q.pop();
		    for(ll i=hd[pre],u;i;i=Eg[i].nxt)
		        if(Eg[i].v && !d[u=Eg[i].u]){
		    	    q.push(u); d[u]=d[pre]+1;
		    	    if(u==t) return true;
			    }
	    }
	return false;
    }
    ll dfs(ll x,ll flow){
	    if(x==t) return flow;
	    ll rest=flow;
	    for(ll i=hd[x],u;i && rest;i=Eg[i].nxt)
	        if(Eg[i].v && d[u=Eg[i].u]==d[x]+1 && d[x]!=0){
	    	    ll k=dfs(u,min(rest,Eg[i].v));
	    	    if(!k) d[u]=-INF;
			    Eg[i].v-=k;
			    Eg[i^1].v+=k;
			    rest-=k;
		    }
	    return flow-rest;
    }
    ll dinic(){
        ll ans=0;
	    while(bfs()){
		    ll cnt=0;
		    while(1){
			    cnt=dfs(s,INF);
			    if(cnt==0) break;
		        ans+=cnt;
		    }
	    }
        return ans;
    }
} T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);

    cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    for(ll i=1;i<=n;i++) cin>>l[i]>>r[i];

    s=++cnt,t=++cnt;
    for(ll i=1;i<=n;i++)
        for(ll j=l[i]+w;j<=r[i]+w+1;j++) id[i][j]=++cnt;
    for(ll i=1;i<=n;i++) T.add(s,id[i][l[i]+w],INF);
	for(ll i=1;i<=n;i++) T.add(id[i][r[i]+w+1],t,INF);
    for(ll i=1;i<=n;i++)
		for(ll j=l[i]+w+1;j<=r[i]+w+1;j++)
			T.add(id[i][j-1],id[i][j],lim-calc(j-w-1,i));
	for(ll i=1;i<=m;i++){
		ll u,v,d; cin>>u>>v>>d;
		for(int j=l[u];j<=r[u]+1;j++){
			if(l[v]<=j-d && j-d<=r[v]+1) T.add(id[u][j+w],id[v][j-d+w],INF);
		}
	}
	cout<<n*lim-T.dinic();
	return 0;
}
