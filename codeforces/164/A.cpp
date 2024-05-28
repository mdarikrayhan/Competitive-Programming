// LUOGU_RID: 158638102
// Problem: A. Variable, or There and Back Again
// Contest: Codeforces - VK Cup 2012 Round 3
// URL: https://codeforces.com/problemset/problem/164/A
// Date: 2024-05-10 15:50:27
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Programmed by ThySecret

#include <bits/stdc++.h>

using namespace std;

// #define int long long
#define DEBUG
#define x first
#define y second
#define File(a) freopen(a".in", "r", stdin); freopen(a".out", "w", stdout)

typedef long long ll;
typedef pair<int, int> PII;

const int N = 100010, M = 4 * N;
const int INF = 0x3f3f3f3f;

int n, m;
int rh[N], h[N], e[M], ne[M], idx;
int f[N];
bitset<N> vis[3];

inline void add(int h[], int a, int b)
{
	e[++ idx] = b, ne[idx] = h[a], h[a] = idx;
}

void bfs(int st)
{
	queue<int> q;
	
	for (int i = 1; i <= n; i ++)
		if (f[i] == st) q.push(i), vis[st][i] = true;
	
	while (!q.empty())
	{
		int ver = q.front(); q.pop();
		
		for (int i = (st == 1 ? h[ver] : rh[ver]); ~i; i = ne[i])
		{
			int j = e[i];
			if (!vis[st][j])
			{
				vis[st][j] = true;
				if (f[j] != 1) q.push(j);
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	memset(h, -1, sizeof h);
	memset(rh, -1, sizeof rh);
	
	cin >> n >> m;
	for (int i = 1 ; i <= n; i ++)	
		cin >> f[i];
	while (m --)
	{
		int a, b; cin >> a >> b;
		add(h, a, b), add(rh, b, a);
	}
	
	bfs(1); bfs(2);
	/*
	for (int i = 1; i <= n; i ++)
		cout << vis[1][i] << ' ';
	cout << '\n';
	for (int i = 1; i <= n; i ++)
		cout << vis[2][i] << ' ';
	cout << '\n';
	*/
	for (int i = 1; i <= n; i ++)
		cout << (vis[1][i] && vis[2][i]) << '\n';
	
	return 0;
}