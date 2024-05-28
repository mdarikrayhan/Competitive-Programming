// LUOGU_RID: 146879915
#include<bits/stdc++.h>
using namespace std;
int n,k,p,ans,dep[100005];
vector<int>e[100005];
void dfs(int cur,int fa){
	dep[cur]=dep[fa]+1;
	for(int x:e[cur])
		if(x!=fa)
			dfs(x,cur);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cin>>n>>k>>p;
	for(int i=1,u,v;i<n;i++)
		cin>>u>>v,e[u].emplace_back(v),e[v].emplace_back(u);
	dfs(1,0),sort(dep+1,dep+n+1);
	for(int l=2,r=2,c=0;l<n&&r<n;){
		r++;
		if(dep[r]!=dep[r-1])
			c+=r-l;
		while(c>p||r-l+1>k)
			c-=dep[r]-dep[l],l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}