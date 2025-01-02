#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<pair<string, string>, int>> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;
	multiset<pair<string, string>> s;
	set<pair<string, string>> ans;
	vector<pair<string, string>> ve;
	for (int l = 0, r = 0; r < n; r++)
	{
		if (r > 0 && v[r].second != v[r - 1].second)
		{
			for (auto x : ve) s.insert(x);
			ve.clear();
		}
		while (v[r].second - v[l].second > m)
		{
			s.erase(s.find(v[l].first));
			l++;
		}
		swap(v[r].first.first, v[r].first.second);
		if (s.find(v[r].first) != s.end())
		{
			string q = v[r].first.first, w = v[r].first.second;
			if (q > w) swap(q, w);
			ans.insert({ q,w });
		}
		swap(v[r].first.first, v[r].first.second);
		ve.push_back(v[r].first);
	}
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x.first << ' ' << x.second << '\n';
	return 0;
}