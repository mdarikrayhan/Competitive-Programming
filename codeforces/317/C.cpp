#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
//	freopen("date.in.txt","r",stdin);
//    freopen("date.out.txt","w",stdout);
//clock_t start, stop;
//	start = clock();
//	stop = clock();
//	double time = (double(stop - start) / CLK_TCK);
//	cout << fixed << setprecision(6) << time << "\n";
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
constexpr ll LNF = 0x3f3f3f3f3f3f3f3f;						
constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int maxn = 500 + 10, P = 13331;

int p[maxn];
int find(int x) {
	if(x == p[x]) return x;
	else return p[x] = find(p[x]);
}
void add(int a, int b) {
	p[find(a)] = find(b);
}

int cur, cap;
int a[maxn], b[maxn], deg[maxn], done[maxn];
vector<int> g[maxn], q;
vector<array<int,3>> ans;

//1 + 2 + 3 + ... + n - 1 = O(n * (n - 1) / 2)
 
void dfs(int v, int p, int push)
{
	for(auto u : g[v])
	{
		if(u == p || done[u]) continue;
		dfs(u, v, push);
		
//		v --------------------> u
		if(push)
		{
			int f = cap - a[u];		// u ÄÜ¹»½ÓÊÜ¶àÉÙ 
			int hv = (v == cur) ? a[v] - b[v] : a[v]; // ÎÒ v ÄÜÌá¹©¶àÉÙ 
			int tk = min(f, hv);
			ans.pb({v, u, tk});
			a[u] += tk;
			a[v] -= tk;
		}
		else 
		{
			int f = a[u];	// u ÄÜÌá¹©¶àÉÙ 
			int nd = (v == cur) ? b[v] - a[v] : cap - a[v]; // ÎÒ v ÐèÒª¶àÉÙ 
			int tk = min(f, nd);
			ans.pb({u, v, tk});
			a[u] -= tk;
			a[v] += tk;
		}
	}
}

void solve()
{
	int n, m;
	cin >> n >> cap >> m;
//	init:
	for(int i = 0; i < n; i ++) p[i] = i;
	
	for(int i = 0; i < n; i ++) cin >> a[i];
	for(int i = 0; i < n; i ++) cin >> b[i];
	for(int i = 0; i < m; i ++)
	{
		int u, v;
		cin >> u >> v;
		-- u; -- v;
		if(find(u) != find(v))
		{
			g[u].pb(v);
			g[v].pb(u);
			deg[u] ++;
			deg[v] ++;
			add(u, v);
		}
	}
	
	for(int i = 0; i < n; i ++) if(deg[i] == 1) q.pb(i);
	
	while(!q.empty())
	{
		int v = q.back();
		q.pop_back();
		if(deg[v] != 1) continue;
		cur = v;
		
		if(a[v] > b[v]) dfs(v, v, 1);
		else if(a[v] < b[v]) dfs(v, v, 0);
		done[v] = 1;
		
		for(auto u : g[v]) if(done[u] == 0) {
			deg[u] --;
			if(deg[u] == 1) q.pb(u);
		}
	}
	
	for(int i = 0; i < n ;i ++) if(a[i] != b[i]) {
		cout << "NO\n";
		return;
	}
	assert(ans.size() <= n * (n - 1) / 2);
	cout << ans.size() << "\n";
	for(auto it : ans) cout << it[0] + 1 << " " << it[1] + 1 << " " << it[2] << "\n";
}	


int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	
	int T = 1;
// 	cin >> T;
	while(T --)
	{
		solve();
	}
	
	return 0;
}