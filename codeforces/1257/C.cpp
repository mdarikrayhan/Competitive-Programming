#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector <int> v(n);
		vector<vector<int>>idx(n+1);
		for (int i=0;i<n;i++)
		{
			cin >> v[i];
			idx[v[i]].push_back(i);
		}
		int ans = 999999;
		for (int i = 1; i <= n; i++)
		{
			if (idx[i].size() < 2)
			{
				continue;
			}
			for (int j = 1; j < idx[i].size(); j++)
			{
				ans = min(ans, idx[i][j] - idx[i][j - 1] + 1);
			}
		}
		if (ans == 999999)
		{
			ans = -1;
		}

		cout << ans <<'\n';
	}
}