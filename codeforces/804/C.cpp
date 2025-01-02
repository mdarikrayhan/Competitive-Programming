#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

const int MX = 3e5 + 10;

int N, M, col[MX], ex[MX];
vector<int> s[MX], adj[MX];

void dfs(int u, int v){

	for(int x : s[u]) ex[col[x]] = true;

	int idx = 1;
	for(int x : s[u]){
		if(col[x] == 0){
			while(ex[idx]) idx++;
			col[x] = idx; ex[idx] = true;
		}
	}

	for(int x : s[u]) ex[col[x]] = false;

	for(int nxt : adj[u]){
		if(nxt == v) continue;
		dfs(nxt, u);
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		int t; cin >> t;
		for(int j = 1; j <= t; j++){
			int x; cin >> x;
			s[i].push_back(x);
		}
		sort(s[i].begin(), s[i].end());
	}

	for(int i = 1; i < N; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	for(int i = 1; i <= M; i++){
		if(col[i] == 0) col[i] = 1;
	}

	int mx = 0;
	for(int i = 1; i <= M; i++) mx = max(mx, col[i]);

	cout << mx << '\n';
	for(int i = 1; i <= M; i++) cout << col[i] << " ";
	cout << '\n';
}