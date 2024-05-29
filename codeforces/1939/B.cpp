#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,g,w[N],u[N],v[N],ind[N];
vector<int> e[N],p[N];
set<array<int,2>> s[N];
void add(int x,int y){
	p[x].push_back(y);
	ind[y]++;
}
void dfs(int x,int l){
	int d=e[x].size();
	vector<int> id(d);
	for(int y:e[x]) if(y!=l){
		dfs(u[y]^v[y]^x,y);
		auto it=s[x].lower_bound({w[y],0});
		if(it==end(s[x])) cout<<"No",exit(0);
		id[(*it)[1]]=y;
		s[x].erase(it);
	}
	if(l){
		auto t=*begin(s[x]);
		id[t[1]]=l;w[l]-=t[0];
	}
	for(int i=1;i<d;i++) add(id[i],id[i-1]);
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>g;
	for(int i=1;i<n;i++) cin>>u[i]>>v[i]>>w[i],e[u[i]].push_back(i),e[v[i]].push_back(i);
	for(int i=1;i<=n;i++) for(int j=0,x;j<(int)e[i].size();j++) cin>>x,s[i].insert({x,j});
	dfs(1,0);
	cout<<"Yes\n";
	queue<int> q;
	for(int i=1;i<n;i++) if(!ind[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		cout<<x<<" ";
		for(int y:p[x]) if(!--ind[y]) q.push(y);
	}
	return 0;
}