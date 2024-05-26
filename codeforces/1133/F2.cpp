//#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <string>
#include <cassert>
#include <limits>
#include <climits>
#include <cstring>
#include <numeric>
#include <utility>
#include <tuple>
#include <type_traits>
#include <cmath>
#include <regex>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
//#include <bit>
using namespace std;

#define loop(x, i) for (int i = 0; i < (x); i++)
//#define int long long
#define INF (4e18 + 1)
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define existsIn(x,l) (count(ALL(l), x) > 0)
#define removeIn(x,l) l.erase(find(ALL(l), x))
#define pb push_back
#define sz(x) (int) (x).size()
#define F first
#define S second
#define var const auto&
#define foreach(l) for (var e in l)
#define get(a,b) get<a>(b)

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef set<int> si;
typedef set<ii> sii;
typedef vector<si> vsi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vi::iterator viit;
typedef si::iterator siit;

constexpr bool disableDebug = false;

template <typename... T>
void DBG(T&&... args)
{
	if (disableDebug) return;
	cerr << "\x1b[90m"; // standard error, gray color
	((cerr << args << ' '), ...);
	cerr << "\x1b[0m\n";
}

#pragma warning(disable:6031)
void setIO(string name = "")
{
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name))
	{
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi component;
vvi adj;

signed main()
{
	setIO();
	int n, m, D;
	cin >> n >> m >> D;
	component.resize(n);
	adj.resize(n);
	int connected = 0;
	loop(m, i)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (adj[0].size() < D)
	{
		cout << "NO" << endl;
		return 0;
	}
	component[0] = INT_MAX;
	si neighbourcomponents;
	for (int start : adj[0])
	{
		if (component[start] != 0) continue;
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			auto i = q.front(); q.pop();
			component[i] = start;
			for (int j : adj[i])
			{
				if (component[j] == start) continue;
				else if (component[j] == INT_MAX) continue;
				else if (component[j] > 0)
				{
					throw;
				}
				component[j] = start;
				q.push(j);
			}
		}
		neighbourcomponents.insert(start);
	}
	if (neighbourcomponents.size() > D)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	vb vis(n);
	vis[0] = 1;
	queue<ii> q;
	for (int start : neighbourcomponents)
	{
		q.push({ 0, start });
	}
	int count = D - neighbourcomponents.size();
	for (int start : adj[0])
	{
		if (count == 0) break;
		if (neighbourcomponents.count(start)) continue;
		q.push({ 0, start });
		count--;
	}
	if (count > 0) throw;
	while (!q.empty())
	{
		auto [prev, i] = q.front(); q.pop();
		if (vis[i]) continue;
		cout << prev + 1 << ' ' << i + 1 << endl;
		vis[i] = 1;
		for (int j : adj[i])
		{
			if (vis[j]) continue;
			q.push({ i, j });
		}
	}
}