// LUOGU_RID: 160105156
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n , a[N] , fa[N] , f[N];
int son[N] , sz[N] , deg[N];
vector<int>tr[N];
set<int>st[N];
void Dfs(int u)
{
	deg[u] = tr[u].size() - (u > 1);
	sz[u] = !deg[u];
	for(int v : tr[u])
	{
		if(v == fa[u])continue ;
		a[v] ^= a[u];
		fa[v] = u , Dfs(v);
		sz[u] += sz[v];
		if(!son[u] || sz[v] > sz[son[u]])
			son[u] = v;
	}
}
void Dp(int u)
{
	f[u] = 0;
	if(!deg[u])
	{
		st[u].insert(a[u]);
		return ;
	}
	for(int v : tr[u])
	{
		if(v == fa[u])continue ;
		Dp(v) , f[u] += f[v];
	}
	int mx = 1; map<int , int>mp , vis;
	swap(st[u] , st[son[u]]);
	for(int v : tr[u])
	{
		if(v == fa[u] || v == son[u])continue ;
		for(int x : st[v])
		{
			if(st[u].count(x) && !vis[x])
				mp[x]++ , vis[x] = 1;
			mx = max(mx , ++mp[x]);
		}
	}
	f[u] = f[u] + deg[u] - mx;
	if(mx != 1)
	{
		st[u].clear();
		for(auto [v , c] : mp)
			if(c == mx)st[u].insert(v);
	}
	else
	{
		for(int v : tr[u])if(v != fa[u] && v != son[u])
			for(int x : st[v])st[u].insert(x);
	}
	for(int v : tr[u])if(v != fa[u])
		st[v].clear();
	// cerr << u << " " << f[u] << "," << deg[u] << '-' << mx << ":";
	// for(int x : st[u])cerr << x << " ";
	// cerr << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 1 ; i < n ; i++)
	{
		int u , v; cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	Dfs(1) , Dp(1);
	cout << f[1] + !st[1].count(0) << "\n";
	return 0;
}