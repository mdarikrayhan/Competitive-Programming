#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
int n;
long long ans;
vector<vector<int>> to;
int dfs(int x,int fa){
	int re=1;
	for(int y:to[x])if(y!=fa)
		re=max(re,dfs(y,x)+1);
	ans+=re;
	return re;
}
 
int main()
{
	int T;cin>>T;while(T--){
		cin>>n;ans=0;
		to.resize(n+1);
		for(int i=1;i<=n;i++)
			to[i].clear();
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			to[x].push_back(y);
			to[y].push_back(x);
		}
		dfs(1,0);
		for(int i=1;i<n;i++)
			ans=2ll*ans%mod;
		cout<<ans<<'\n';
	}
}