#include <bits/stdc++.h>
#define ll long long
#define tt int tc;cin>>tc;while(tc--){
#define all(v) (v).begin(),(v).end()
#define nn cout<<"\n"
using namespace std;

void Ahmed_Sayed(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
const ll N=1e5;
vector<ll>adj[N+1];
ll dp[N+1];

ll dfs(ll node){
    ll &ret=dp[node],mx=0;
    if(~ret)return ret;

    ret=1;
    for(auto i:adj[node]){
        if(i<node)mx=max(mx,dfs(i));
    }
    return ret+=mx;
}


int main()
{
Ahmed_Sayed();
ll n,m;cin>>n>>m;
memset(dp,-1,sizeof dp);
while(m--){
    ll a,b;cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
}

ll ans=0;
for(int i=1;i<=n;i++)
    dfs(i),ans=max(ans,(ll)adj[i].size()*dp[i]);

cout<<ans;
}
//
	  			    	   					 	   		  	 	