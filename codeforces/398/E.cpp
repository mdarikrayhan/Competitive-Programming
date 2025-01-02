// LUOGU_RID: 122084875
#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int N=1e6+5,M=15,p=1e9+7;
int n,k,a[N],jc[N]={1},ny[N];
int S=1,sz[M],cnt,s,s2[M],ans;
int tn[N],tn2[N],mx,g[N],bz[N],deg[N];
vector<int>f[N];
inline int ksm(ri x,ri y){
	ri sm=1;
	for(;y;y>>=1,x=1ll*x*x%p)
	if(y&1)sm=1ll*sm*x%p;
	return sm;
}
inline void dfs2(ri x){
	if(x>k){
		ri mx2=0,sm=1;
		for(ri i=1;i<=cnt;i++){
			++tn2[sz[i]];
			sm=1ll*sm*jc[s2[i]-1];
			mx2=max(mx2,sz[i]);
		}
		if(mx<3&&mx2<3){
			(ans+=1)%=p;
			for(ri i=1;i<=cnt;i++)
			--tn2[sz[i]];
			return;
		}
		for(ri i=1;i<=cnt;i++){
			if(tn2[sz[i]]<=tn[sz[i]])continue;
			sm=1ll*sm*f[sz[i]][tn2[sz[i]]]%p*ny[sz[i]]%p;
			tn2[sz[i]]=tn[sz[i]];
		}
		(ans+=1ll*S*sm%p)%=p;
		return;
	}
	s2[++cnt]=1;
	sz[cnt]=g[x];
	dfs2(x+1);--cnt;
	for(ri i=1;i<=cnt;i++){
		++s2[i];sz[i]+=g[x];
		dfs2(x+1);
		--s2[i];sz[i]-=g[x];
	}
}
inline void dfs(ri x){
	if(bz[x])return;
	bz[x]=1;++s;
	if(a[x])dfs(a[x]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<=n;i++){
		scanf("%d",&a[i]);
		++deg[a[i]];
		jc[i]=1ll*jc[i-1]*i%p;
	}
	for(ri i=1;i<=n;i++){
		ri ln=n/i+1;
		f[i].resize(ln);
		f[i][0]=1;f[i][1]=i;
		for(ri j=2;j<ln;j++)
		f[i][j]=(1ll*f[i][j-1]*i%p
		+1ll*f[i][j-2]*i%p*(j-1)%p)%p;
	}
	for(ri i=1;i<=n;i++){
		if(deg[i])continue;
		s=0;dfs(i);
		g[++g[0]]=s;
	}
	for(ri i=1;i<=n;i++){
		if(bz[i])continue;
		s=0;dfs(i);
		++tn[s];++tn2[s];
		mx=max(mx,s);
	}
	for(ri i=1;i<=n;i++)
	S=1ll*S*f[i][tn[i]]%p,
	ny[i]=ksm(f[i][tn[i]],p-2);
	dfs2(1);printf("%d",ans);
}