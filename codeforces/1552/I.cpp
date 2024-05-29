#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=998244353;
#define Term puts("0"),exit(0)
#define Ins(a,b) (a).insert((a).end(),(b).begin(),(b).end())
#define R(a) reverse((a).begin(),(a).end())
#define pb push_back
int p[N],c[N],fac[N],n,m,ans=1,tot,l,x;
vector<int> G[N];
void dfs1(int u){
	if (u<=n) return;
	int v0=0,v2=0;
	for (int v:G[u]) dfs1(v),c[v]==1?(c[u]=1):(c[v]==0?v0=1:v2=1);
	if (!c[u]) c[u]=(v0 && v2)?1:(v0?0:2);
}
void dfs2(int u, int k){
	if (c[u]!=1) return;
	vector<int> a[3],T;
	for (int v:G[u]) a[c[v]].pb(v);
	if ((k==0 && a[1].size()>2) || (k!=0 && a[1].size()>1)) Term;
	if (!k && a[1].size()+a[2].size()<=1){
		for (int v:G[u]) if (c[v]) dfs2(v,0);
		return;
	}
	if (p[u]==0){
		int x=-1;
		if (a[2].size()>1) G[x=++tot]=a[2];
		else if (a[2].size()==1) x=a[2][0];
		
		if (a[1].size()>0) dfs2(a[1][0],2),Ins(T,G[a[1][0]]);
		if (x!=-1) T.pb(x);
		if (a[1].size()>1) dfs2(a[1][1],1),Ins(T,G[a[1][1]]);
		
		if (!a[0].size()){ if (k==1) R(T); p[u]=1,G[u]=T; }
		else if (k){
			x=a[0][0],G[u].clear(),p[u]=1;
			if (a[0].size()>1) G[x=++tot]=a[0];
			G[u].pb(x),Ins(G[u],T);
			if (k==1) R(G[u]);
		} else {
			x=T[0];
			if (T.size()>1) p[x=++tot]=1,G[x]=T;
			G[u]=a[0],G[u].pb(x);
		} 
	} else {
		if (c[G[u][0]]==2 || c[G[u].back()]==0) R(G[u]);
		int D=0;
		for (int v:G[u])
			if (c[v]==0) D=D==1?2:D,T.pb(v);
			else if (D==2) Term;
			else if (c[v]==2) T.pb(v),D=1;
			else dfs2(v,2-D),D++,Ins(T,G[v]);
		if (k && D==2) Term;
		if (k==1) R(T);
		G[u]=T;
	}
}
void dfs(int u){
	if (u<=n) return;
	ans=1ll*ans*(p[u]==1?2:fac[G[u].size()])%M;
	for (int v:G[u]) dfs(v);
}
int main(){
	cin>>n>>m; tot=n+1; fac[0]=1;
	for (int i=1; i<=n; i++) G[tot].pb(i);
	for (int i=1; i<=m; i++){
		scanf("%d",&l);
		for (int j=1; j<=l; j++) scanf("%d",&x),c[x]=2;
		dfs1(n+1),dfs2(n+1,0);
		for (int j=1; j<=tot; j++) c[j]=0;
	}
	for (int i=1; i<=n; i++) fac[i]=1ll*fac[i-1]*i%M;
	dfs(n+1),printf("%d\n",ans);
	return 0;
}