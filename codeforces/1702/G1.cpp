#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
map<int,bool> a;
bool ok;
bool dfs(int c,int p){
	int cnt=0;
	if (p!=-1) cnt++;
	for (int x : g[c])if(x!=p)if(dfs(x,c))cnt++;
	if (cnt>2){
		ok=0;
	}
	if (cnt==2||a[c])return 1;
	else return 0;
}
int main(){
	int n;
	cin>>n;
	g.resize(n+1);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		a.clear();
		ok=1;
		int f;
		for(int i=0;i<k;i++){
			int x;
			cin>>x;
			a[x]=1;
			f=x;
		}
		dfs(f,-1);
		cout<<(ok?"YES\n":"NO\n");
	}
}