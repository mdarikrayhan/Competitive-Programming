#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 10;
int n;
int h[N], d[N];
int ma[N][N];

int32_t main() { 
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> h[i];
  
  for (int i = 1; i <= n; ++i) d[i] = d[i - 1] + h[i];

	int answer = 0;
	vector<pair<int, int>> value;
	for (int j = 1; j <= n; ++j) { 
		value.clear();
		for (int i = j; i <= n; ++i) { 
			int ret = 1'000'000'000;
			ma[i][j] = max(ma[i][j], ma[i - 1][j]);
			if (!ma[i][j] && j > 1) continue;
			answer = n - j;
			ret = min(ret, d[i] - d[ma[i][j]]);
			pair<int, int> push = {ret + d[i], i};
			while (value.size() && value.end()[-1] >= push) value.pop_back();
			value.push_back({ret + d[i], i});
		}
		int it = 1;
		for (const auto& [val, i] : value) { 
			while (it <= n && d[it] < val) it += 1;
			ma[it][j + 1] = i;
		}
	}
  
  cout << answer << "\n";
}