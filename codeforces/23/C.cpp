#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int m = n * 2 - 1;
		vector<tuple<int, int, int>> v;
		int sumo = 0;
		for (int i = 0; i < m; i++)
		{
			int a, o;
			cin >> a >> o;
			sumo += o;
			v.emplace_back(a, o, i + 1);
		}
		sort(all(v));
		cout << "YES\n";
		int odd = 0;
		for (int i = 0; i < m; i += 2) 
		{
			auto [a, o, j] = v[i];
			odd += o;
		}
		if (odd * 2 >= sumo)
		{
			for (int i = 0; i < m; i += 2) 
			{
				auto [a, o, j] = v[i];
				cout << j << ' ';
			}
			cout << '\n';
		}
		else
		{
			for (int i = 1; i < m; i += 2) 
			{
				auto [a, o, j] = v[i];
				cout << j << ' ';
			}
			cout << get<2>(v[m - 1]);
			cout << '\n';
		}
	}
	return 0;
}