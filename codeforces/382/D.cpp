#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[2005];
int d[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
string t = "><^v";
int mx, mx2;
int cnt = 0;

void recalc(int cur)
{
	if (cur > mx)
	{
		mx2 = mx;
		mx = cur;
	}
	else mx2 = max(mx2, cur);
}

int dfs(int x, int y)
{
	//cout << x << " " << y << '\n';
	cnt++;
	
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		int x2 = x + d[i][0], y2 = y + d[i][1];
		if (x2 < 0 || y2 < 0 || x2 >= n || y2 >= m) continue;
		if (s[x2][y2] != t[i]) continue;
		
		if (s[x][y] == '#') recalc(dfs(x2, y2));
		else ans = max(ans, dfs(x2, y2));
	}
	
	return ans + 1;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> s[i];
		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '#') dfs(i, j);
	
	//cout << cnt << '\n';
	if (cnt < n * m) 
	{
		cout << -1;
		return 0;
	}
	
	if (mx == mx2) cout << mx * 2;
	else cout << mx * 2 - 1;
}
