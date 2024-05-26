// LUOGU_RID: 160305284
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=1000005;
const int mod=1e9+7;
int n,head[N],tot=0;
int dp[N],ans[N];
vector<ll>f1[N],f2[N];
struct edge{int to,next;}e[N];
inline void add(int from,int to){
	e[++tot]={to,head[from]};
	head[from]=tot;
}
inline void dfs1(int u,int fa){
	dp[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v!=fa)dfs1(v,u),dp[u]=dp[u]*(dp[v]+1)%mod;
	}
	return;
}
inline void dfs2(int x,int fa){
	ans[x]=1;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		ans[x]=ans[x]*(dp[v]+1)%mod;
		if(v!=fa)f1[x].push_back(dp[v]+1),f2[x].push_back(dp[v]+1);
	}
	for(int i=1;i<f1[x].size();i++)f1[x][i]=f1[x][i]*f1[x][i-1]%mod;
	for(int i=f2[x].size()-2;i>=0;i--)f2[x][i]=f2[x][i]*f2[x][i+1]%mod;
	int cnt=0;
	for(int i=head[x];i;i=e[i].next){
		int v=e[i].to;
		if(v==fa)continue;
		dp[x]=(fa?dp[fa]+1:1);
		if(cnt>0)dp[x]=dp[x]*f1[x][cnt-1]%mod;
		if(cnt<f2[x].size()-1)dp[x]=dp[x]*f2[x][cnt+1]%mod;
		dfs2(v,x);++cnt;
	}
	return;
}
signed main(){
	cin>>n;
	for(int i=2,x;i<=n;i++)cin>>x,add(x,i),add(i,x);
	dfs1(1,0);dfs2(1,0);
	for(int i=1;i<=n;i++)cout<<ans[i]%mod<<" ";
}