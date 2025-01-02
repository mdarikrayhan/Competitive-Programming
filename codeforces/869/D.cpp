#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=1000000007;
int n,m,x,y,ans;
map<int,int>sz,vis;
map<int,vector<int> >e;
void add(int x){
	for(;x;x>>=1)
		sz[x]=0;
}
int calc(int x){
	int res=0;
	for(int i=1;x<=n;i<<=1,x<<=1)
		res+=min(x+i,n+1)-x;
	return res;
}
int dfs(int x){
	int res=sz[x];
	vis[x]=1;
	for(int y:e[x])
		if(!vis[y])
			res=(res+dfs(y))%MOD;
	return vis[x]=0,res;
}
signed main(){
	for(cin>>n>>m,add(1);m--;){
		cin>>x>>y;
		e[x].push_back(y),e[y].push_back(x);
		add(x),add(y);
	}
	for(auto i:sz){
		int x=i.first,fa=x>>1,s=calc(x);
		sz[x]+=s;
		if(x>1)
			sz[fa]-=s,e[x].push_back(fa),e[fa].push_back(x);
	}
	for(auto i:sz)
		ans=(ans+i.second*dfs(i.first))%MOD;
	cout<<ans<<"\n";
}