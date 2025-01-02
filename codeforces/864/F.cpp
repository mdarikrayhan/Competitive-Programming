// LUOGU_RID: 157285690
#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> qry[3005][3005];
int ans[400005];
vector<int> vc[3005];
bool ins[3005],vis[3005];
int rem[3005],dep[3005],len,incyc,delcyc,tmp;
void dfs(int now,int len){
	dep[now]=len,ins[now]=1,vis[now]=1;
	rem[len]=now;
	if(!incyc){
		for(auto v:qry[tmp][now]) if(v.first<=len) ans[v.second]=rem[v.first];
	}
	for(auto v:vc[now]){
		if(!vis[v]){
			dfs(v,len+1);
		}
		else if(ins[v]){
			if(!incyc){
				incyc=1;
				delcyc=v;
			}
			else{
				if(dep[v]<dep[delcyc]) delcyc=v;
			}
		}
	}
	ins[now]=0;
	if(delcyc==now){
		incyc=0;
		delcyc=0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,q; cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int u,v; cin>>u>>v;
		vc[u].push_back(v);
	}
	for(int i=1;i<=n;i++) sort(vc[i].begin(),vc[i].end());
	for(int i=1;i<=q;i++){
		int s,t,k; cin>>s>>t>>k;
		qry[s][t].push_back(make_pair(k,i));
		ans[i]=-1;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		tmp=i;
		incyc=0,delcyc=0;
		dfs(i,1);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}