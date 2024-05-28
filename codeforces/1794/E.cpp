#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],b[N],u,v,res[N],Hash[N],tar;
vector<int>edge[N];
map<int,int>table;
void getHash(int u,int fa,const int base,const int mod){
	Hash[u]=0;
	for(auto v:edge[u]){
		if(v==fa)continue;
		getHash(v,u,base,mod);
		Hash[u]+=Hash[v]*base;
		Hash[u]%=mod;
	}
	Hash[u]=(Hash[u]+1)%mod;
}
void dfs(int u,int fa,const int base,const int mod){
	Hash[u]=(Hash[u]+Hash[fa]*base)%mod;
	if(table[(Hash[u]-tar+mod)%mod])res[u]++;
	for(auto v:edge[u]){
		if(v==fa)continue;
		Hash[u]=(Hash[u]-Hash[v]*base%mod+mod)%mod;
		dfs(v,u,base,mod);
		Hash[u]=(Hash[u]+Hash[v]*base%mod)%mod;
	}
	Hash[u]=(Hash[u]-Hash[fa]*base%mod+mod)%mod;
}
void solve(const int mod,const int base){
	tar=0;
	for(int i=0;i<n;i++)b[i]=0;
	for(int i=1;i<n;i++)b[a[i]]++;
	table.clear();
	int now=1;
	for(int i=0;i<n;i++){
		table[now]=1;
		tar=(tar+b[i]*now)%mod;
		now*=base;
		now%=mod;
	}
	getHash(1,0,base,mod);
	dfs(1,0,base,mod);
}
mt19937 rnd(time(0));
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)cin>>a[i];
	for(int i=1;i<n;i++)cin>>u>>v,edge[u].push_back(v),edge[v].push_back(u);
	solve(998244353,n+rnd()%n);
	solve(1000000007,n+rnd()%n);
	solve(1000000009,n+rnd()%n);
	vector<int>ans;
	for(int i=1;i<=n;i++)if(res[i]==3)ans.push_back(i);
	cout<<ans.size()<<"\n";
	for(auto now:ans)cout<<now<<" ";
	return 0;
}