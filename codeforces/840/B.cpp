// LUOGU_RID: 159131142
// Problem: Leha and another game about graph
// URL: https://www.luogu.com.cn/problem/CF840B
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// Author: Nityacke
// Time: 2024-05-16 10:01:39

#include<iostream>
#include<vector>
using namespace std;
const int N=3e5+5;
int n,m,d[N],fl1,fl2,vis[N],tvis[N];
int h[N],nxt[N<<1],to[N<<1],tot=1;
inline void add(int u,int v){to[++tot]=v,nxt[tot]=h[u],h[u]=tot;}
inline bool dfs(int x,int In){
	tvis[x]=1;
	int now=0;
	for(int i=h[x];i;i=nxt[i])
		if(!tvis[to[i]]) now^=dfs(to[i],i);
	// cerr<<x<<" "<<now<<"\n";
	if(d[x]!=-1&&d[x]!=now) return vis[In>>1]=1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>d[i],fl1^=d[i],fl2|=(d[i]==-1);
	if(!fl2&&fl1) return cout<<"-1\n",0;
	for(int u,v,i=1;i<=m;++i)
		cin>>u>>v,add(u,v),add(v,u);
	for(int i=1;i<=n;++i)
		if(d[i]==-1){
			dfs(i,0);
			int ans=0;
			for(int j=1;j<=m;++j)
				if(vis[j]) ++ans;
			cout<<ans<<"\n";
			for(int j=1;j<=m;++j)
				if(vis[j]) cout<<j<<"\n";
			return 0;
		}
	dfs(1,0);
	int ans=0;
	for(int j=1;j<=m;++j)
		if(vis[j]) ++ans;
	cout<<ans<<"\n";
	for(int j=1;j<=m;++j)
		if(vis[j]) cout<<j<<"\n";
	
	
}