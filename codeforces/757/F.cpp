#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5, M = 3e5 + 5;
int n, m, s, pre[N], sz[N];
vector <pair <int, int>> G[N];
long long dis[N];
typedef pair <long long, int> P;
priority_queue <P, vector <P>, greater <P>> q;

int main() {
	mem(dis, 63); 
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m >> s;
	int u, v, w;
	while(m--) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].pb({v, w}), G[v].pb({u, w});
	}
	dis[s] = 0, q.push({0, s});
	while(!q.empty()) {
		auto [d, u] = q.top(); q.pop();
		for(auto [v, w] : G[u]) if(d + w == dis[v] && pre[v] ^ pre[u]) pre[v] = v;
		else if(d + w < dis[v]) pre[v] = u ^ s ? pre[u] : v, dis[v] = d + w, q.push({d + w, v});
	}
	int as = 0;
	rep(i, 1, n) if(pre[i]) as = max(as, ++sz[pre[i]]);
	cout << as;
	return 0;
}
  	 	  	 		    			 	 	  			  	