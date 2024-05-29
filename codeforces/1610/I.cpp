#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mod = 998244353;
// cope counter = 2254

const int N = 3e5 + 1;
vector<int> adj[N];
int par[N], sg[N], vis[N];

int dfs(int i, int p) {
	par[i] = p, sg[i] = 0;
	for(int j : adj[i]) {
		if(j != p) sg[i] ^= dfs(j, i) + 1;
	}
	return sg[i];
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int u, v;
	for(int i = 1; i < n; i++) {
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0, 0);
	int ans = sg[0], cur, cnt;
	cout << 2 - min(1, ans) << "";
	vis[0] = 1;
	for(int i = 1; i < n; i++) {
		if(vis[i]) {
			cout << 2 - min(1, ans) << "";
			continue;
		}
		cur = i, cnt = 0;
		while(1) {
			cnt++;
			vis[cur] = 1;
			for(int j : adj[cur]) {
				if(j != par[cur] && !vis[j]) ans ^= (sg[j] + 1);
			}
			if(vis[par[cur]]) break;
			cur = par[cur];
		}
		ans ^= (sg[cur] + 1) ^ (cnt % 2);
		cout << 2 - min(1, ans) << "";
	}
	cout << "\n";
}