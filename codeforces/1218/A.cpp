// LUOGU_RID: 156814817
#pragma GCC optimize(2,3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
#define lowbit(i) (i&(-i))
#define add(i,j) ((i+j>=mod)?i+j-mod:i+j)
using namespace std;
vector<int> vc[20005];
int u[20005],v[20005],deg[20005],ok[20005];
vector<int> cyc;
void findcyc(int now){
	ok[now]=0;
	cyc.push_back(now);
	for(auto v:vc[now]){
		if(ok[v]) findcyc(v);
	}
}
int dp[20005],siz[20005],n,udp[20005];
void dfs(int now,int fa){
	// cout<<now<<" "<<fa<<"\n";
	siz[now]=1;
	for(auto v:vc[now]){
		if(!ok[v]&&v!=fa){
			dfs(v,now);
			siz[now]+=siz[v];
			dp[now]+=dp[v];
		}
	}
	udp[now]=dp[now]+n-siz[now]+1;
	for(auto v:vc[now]){
		if(!ok[v]&&v!=fa){
			udp[now]=max(udp[now],dp[now]-dp[v]+udp[v]+n-siz[v]);
		}
	}
	dp[now]+=siz[now];
}
int f[30005],g[30005],p[30005];
int pre[30005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i];
		u[i]++,v[i]++;
		vc[u[i]].push_back(v[i]);
		vc[v[i]].push_back(u[i]);
		deg[u[i]]++,deg[v[i]]++;
	}
	for(int i=1;i<=n;i++) ok[i]=1;
	queue<int> q; for(int i=1;i<=n;i++) if(deg[i]==1) q.push(i);
	while(!q.empty()){
		int f=q.front(); q.pop();
		ok[f]=0;
		for(auto v:vc[f]){
			deg[v]--;
			if(deg[v]==1) q.push(v);
		}
	}
	for(int i=1;i<=n;i++) if(ok[i]) findcyc(i);
	for(auto v:cyc) ok[v]=1;
	for(auto v:cyc){
		dfs(v,0);
		dp[v]-=siz[v];
		// cout<<v<<" "<<dp[v]<<" "<<udp[v]<<"\n";
	}
	int len=cyc.size()*2;
	for(int i=0;i<len;i++) p[i]=cyc[i%cyc.size()];
	pre[0]=siz[p[0]];
	for(int i=1;i<len;i++) pre[i]=pre[i-1]+siz[p[i]];
	for(int i=cyc.size();i>=2;i--){
		for(int l=0,r=i-2;r<len;l++,r++) g[l]=0;
		for(int l=0,r=i-1;r<len;l++,r++){
			if(l!=0) g[l]=max(g[l],f[l]+dp[p[r]]+n-(pre[r-1]-pre[l-1]));
			else g[l]=max(g[l],f[l]+dp[p[r]]+n-(pre[r-1]));
			g[l+1]=max(g[l+1],f[l]+dp[p[l]]+n-(pre[r]-pre[l]));
		}
		for(int l=0,r=i-2;r<len;l++,r++) f[l]=g[l];//cout<<f[l]<<" "; cout<<"\n";
	}
	int ans=0;
	for(int i=0;i<len/2;i++){
		// cout<<max(f[i],f[i+len])<<" ";
		ans=max(ans,max(f[i],f[i+len/2])+udp[p[i]]);
	}
	cout<<ans;
	return 0;
}