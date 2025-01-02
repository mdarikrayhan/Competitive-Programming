// #ifndef _DEBUG
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // codeforces
// #endif

#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Query
{
	int type;
	int time;
	int index;

	Query(int a, int b, int c)
	{
		type = a;
		time = b;
		index = c;
	}
};

vector<int> answer;

signed main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m, g;
	cin >> n >> m >> g;

	vector<vector<int>> b(n + 1, vector<int>(m + 1));

	auto fenwget = [&](int k, int l)
	{
		int sum = 0;
		for (int i = k; i > 0; i -= i & -i)
			for (int j = l; j > 0; j -= j & -j)
				sum += b[i][j];
		return sum;
	};

	auto fenwinc = [&](int k, int l, int x)
	{
		for (int i = k + 1; i < b.size(); i += i & -i)
			for (int j = l + 1; j < b[0].size(); j += j & -j)
				b[i][j] += x;
	};

	vector<vector<tuple<int, int, int>>> garlands(g);
	vector<bool> garland_active(g);

	vector<bool> must_toggle(g);

	for (auto& garland : garlands) {
		int x;
		cin >> x;

		garland.resize(x);

		for (auto& [x, y, h] : garland) {
			cin >> x >> y >> h;
			x--, y--;
		}
	}

	auto toggle_garland = [&](int g)
	{
		int multiplier = garland_active[g] ? -1 : 1;
		garland_active[g] = !garland_active[g];
		for (auto &[x, y, h] : garlands[g])
			fenwinc(x, y, h * multiplier);
	};

	for (int i = 0; i < g; i++)
		toggle_garland(i);

	int q;
	cin >> q;

	while (q--) {
		string type;
		cin >> type;

		if (type == "SWITCH") {
			int i;
			cin >> i;

			i--;

			must_toggle[i] = !must_toggle[i];
		} else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			x1--, x2--, y1--, y2--;

			for (int i = 0; i < g; i++) {
				if (must_toggle[i]) {
					must_toggle[i] = false;
					toggle_garland(i);
				}
			}

			int sum = 0;

			sum += fenwget(x2 + 1, y2 + 1);
			sum -= fenwget(x1, y2 + 1);
			sum -= fenwget(x2 + 1, y1);
			sum += fenwget(x1, y1);

			cout << sum << "\n";
		}
	}
}