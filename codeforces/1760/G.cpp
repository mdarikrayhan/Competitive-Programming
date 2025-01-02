#include <bits/stdc++.h>
using namespace std;
 
int S, T;
map<int, vector<pair<int, int>>> to;
set<int>g;
 
void dfs1(int u, int f, int x) {
	g.insert(x);
	for (auto [w, z]: to[u]) 
		if (w != f & w != T) dfs1(w, u, x ^ z);
}
 
int dfs2(int u, int f, int x) {
	for (auto [w, z] : to[u]) 
		if (w != f && (g.count(x ^ z) || dfs2(w, u, x^z)))
			return 1;
	return 0;
}
 
int main() {
	int t,u,v,w,n;
	cin>>t;
	while (t--) {
	    cin>>n>>S>>T;
	    g.clear(),to.clear();
		for (int i=1;i<n;i++) {
		    cin>>u>>v>>w;
			to[u].push_back({v,w}), to[v].push_back({u,w});
		}
		dfs1(S,0,0);
		puts(dfs2(T,0,0) ? "YES" : "NO");
}}