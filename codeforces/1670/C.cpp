//            ॐ卐
#include <bits/stdc++.h>
using namespace std;
 
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long 

void dfs(vector<int>* adj, int node, int parent, vector<int>& vis, int &cnt) {
	if(node == parent) {
		vis[node] = 1;
		//cout << node << " ----> " << parent << "\n";
		cnt++;
		return;
	}
	if(vis[node] != -1) {
		return;
	}
	vis[node] = 1;
	for(int i = 0; i < adj[node].size(); i++) {
		// if(vis[adj[node][i]] == -1)
		dfs(adj, adj[node][i], parent, vis, cnt);
	}
}

void solve(int tt) {
	const int mod = 1e9 + 7;
	int n;
	cin >> n;
	vector<int> a(n), b(n), d(n);
	for(int i =0 ; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	vector<int> adj[n + 1];
	for(int i = 0; i < n; i++) {
		if(d[i] == 0) {
			//cout << a[i] << " " << b[i] << "\n";
			//if(a[i] != b[i])
			adj[a[i]].push_back(b[i]);
			//adj[b[i]].push_back(a[i]);
		}
	}
	int ans = 0;
	vector<int> vis(n + 1, -1);
	for(int i = 0; i < n; i++) {
		if(d[i] == 0) {
			if(vis[b[i]] == -1 && a[i] != b[i]) {
				//cout << a[i] << " \n";
				dfs(adj, b[i], a[i], vis, ans);
			}
		}
	}
	//cout << ans << "\n";
	int aa = 1;
	for(int i = 0; i < ans; i++) {
		aa = (int)((2LL * aa) % mod);
	}
	cout << aa << "\n";
}	
 
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	// q = 1;
	for(int i = 1; i <= q; i++) {
		solve(0);
	}
	return 0;
}