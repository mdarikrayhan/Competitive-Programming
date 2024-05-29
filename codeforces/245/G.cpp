#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

const int MAXN = 10000 + 10;

map <string, int> vertices;
int n, m, mark[MAXN], ans[MAXN];
vector <int> g[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin >> m;
	for (int i = 1 ; i <= m ; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (!vertices[s1])
			vertices[s1] = ++n;
		if (!vertices[s2])
			vertices[s2] = ++n;
		int u = vertices[s1];
		int v = vertices[s2];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1 ; i <= n ; i++)
	{
		int count = 0;
		memset(mark, 0, sizeof(mark));
		for (int j = 0 ; j < (int)g[i].size() ; j++)
			mark[g[i][j]] = 1;
		for (int j = 1 ; j <= n ; j++)
			if (i != j && !mark[j])
			{
				int temp = 0;
				for (int k = 0 ; k < (int)g[j].size() ; k++)
					temp += mark[g[j][k]];
				if (temp > ans[i])
				{
					ans[i] = temp;
					count = 1;
				}
				else if (temp == ans[i])
					count++;
			}
		ans[i] = count;
	}
	cout << n << endl;
	for (map<string, int>::iterator it = vertices.begin() ; it != vertices.end() ; it++)
		cout << it->first << " " << ans[it->second] << endl;
	return 0;
}