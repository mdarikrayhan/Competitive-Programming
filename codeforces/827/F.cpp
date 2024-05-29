// LUOGU_RID: 160556826
// 2024 HOPE IN VALUABLE
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
const int inf=1000000005;
int n,m,dis[N][2];
struct Trans{ int v,r; }; vector<Trans>e[N][2];
struct State{
	int u,v,l,r,o;
	bool operator < (const State &a) const { return l>a.l; }
};priority_queue<State>q;
inline void solve(int u,int v,int l,int r){
	int o=l&1;
	if(dis[u][o]>=l){
		if(v==n){ cout<<l+1<<'\n'; exit(0); }
		if(dis[v][o^1]<r+1){
			dis[v][o^1]=r+1;
			for(int i=0;i<e[v][o^1].size();i++) q.emplace(State{v,e[v][o^1][i].v,l+1,e[v][o^1][i].r,0});
			e[v][o^1].clear();
		}
	}else e[u][o].emplace_back(Trans{v,r});
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	if(n==1) return cout<<"0\n",0;
	for(int i=1;i<=m;i++){
		int u,v,l,r; cin>>u>>v>>l>>r;
		q.emplace(State{u,v,l,r-1-(r-l+1&1),1});
		q.emplace(State{u,v,l+1,r-1-(r-l&1),1});
	}
	for(int i=1;i<=n;i++) dis[i][0]=dis[i][1]=-1; dis[1][0]=0;
	while(!q.empty()){
		int u=q.top().u,v=q.top().v,l=q.top().l,r=q.top().r,o=q.top().o; q.pop();
		if(l>r) continue;
		solve(u,v,l,r);
		if(o) solve(v,u,l,r);
	}
	cout<<"-1\n";
	return 0;
}