// LUOGU_RID: 160092236
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int p=1e9+7;
struct node{
	int to,nxt;
}edge[N*2]; int head[N],cnt;
void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void adde(int u,int v){
	add(u,v); add(v,u);
}

int qpow(int a,int index){
	int ans=1;
	while(index){
		if(index&1) ans=ans*a%p;
		a=a*a%p; index>>=1;
	}
	return ans;
}

int fac[N],ifac[N];
void init(int n){
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%p;
	ifac[n]=qpow(fac[n],p-2);
	for(int i=n-1;i>=1;i--) ifac[i]=ifac[i+1]*(i+1)%p;
}

int C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return fac[n]*ifac[n-m]%p*ifac[m]%p;
	
}
int n,k; 
int _minus(int a,int b){
	return ((a-b)%p+p)%p;
}

int siz[N],sum[N],ans=0; int tot=0;
void dfs(int u,int f){
	siz[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to; if(v==f) continue;
		dfs(v,u); siz[u]+=siz[v];
		sum[u]=(sum[u]+C(siz[v],k))%p;
	}
	ans=(ans+siz[u]*(((C(siz[u],k)-sum[u])%p+p)%p)%p)%p;
}

void dfs2(int u,int f){
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to; if(v==f) continue;
		
		int tmp=ans;
		ans=_minus(ans,siz[u]*(((C(siz[u],k)-sum[u])%p+p)%p)%p);
		ans=_minus(ans,siz[v]*(((C(siz[v],k)-sum[v])%p+p)%p)%p);
		int tsumu=sum[u],tsumv=sum[v];
		int tsizu=siz[u],tsizv=siz[v];
		sum[u]=_minus(sum[u],C(siz[v],k));
		siz[u]-=siz[v];
		siz[v]+=siz[u];
		sum[v]=(sum[v]+C(siz[u],k))%p;
		ans=(ans+siz[u]*(((C(siz[u],k)-sum[u])%p+p)%p)%p)%p;
		ans=(ans+siz[v]*(((C(siz[v],k)-sum[v])%p+p)%p)%p)%p;
		tot=(tot+ans)%p;
		dfs2(v,u);
		
		ans=tmp;
		sum[u]=tsumu; sum[v]=tsumv;
		siz[u]=tsizu; siz[v]=tsizv;
	}
}

inline void fake_main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		adde(u,v);
	}
	dfs(1,0); tot+=ans;
	dfs2(1,0);
	cout<<tot<<"\n";
}

signed main(){
	init(N-10);
	ios::sync_with_stdio(false);
	int t; t=1;
	while(t--) fake_main();
}
