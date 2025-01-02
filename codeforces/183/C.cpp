#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,cnt,ans,opt,sum,x,y,mx,q,f,pos,l,r,mid;
int vis[100007],a[100007];
vector<pair<int,int> >v[100007];
void dfs(int x,int cnt){
	if(vis[x]){
		ans=__gcd(ans,a[x]-cnt);return;
	}
	vis[x]=1,a[x]=cnt;
	for(auto i:v[x])dfs(i.first,cnt+i.second);
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>x>>y,v[x].push_back({y,1}),v[y].push_back({x,-1});
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
	if(ans)cout<<abs(ans);
	else cout<<n;
	return 0;
}
	 			  	  	    		  				  	   	