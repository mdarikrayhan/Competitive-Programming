#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(time(NULL));

const int INF = 1e9;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<pair<int, int>> b(m);
	vector<vector<int>> lf(n), rg(n);
	for (int i = 0; i < m; ++i) {
		cin >> b[i].first >> b[i].second;
		--b[i].first;
		--b[i].second;
		lf[b[i].second].push_back(b[i].first);
		rg[b[i].first].push_back(b[i].second);
		}
	
	vector<int> ansv(n, -INF);
	
	vector<int> add(n + 1 , 0);
	int mn = a[0];
	
	for (int i = 0; i < n; ++i) {
		ansv[i] = max(ansv[i], a[i] - mn);
		for (auto l : lf[i]) {
			for (int j = l; j <= i; ++j) {
				--add[j];
				mn = min(mn, a[j] + add[j]);
			}
		}
		mn = min(mn, a[i] + add[i]);
	}
	
	add = vector<int>(n + 1, 0);
	mn = a[n - 1];
	
	for (int i = n - 1; i >= 0; --i) {
		ansv[i] = max(ansv[i], a[i] - mn);
		for (auto r : rg[i]) {
			for (int j = i; j <= r; ++j) {
				--add[j];
				mn = min(mn, a[j] + add[j]);
			}
		}
		mn = min(mn, a[i] + add[i]);
	}
	
	int ans = *max_element(ansv.begin(), ansv.end());
	vector<int> res;
	
	for (int i = 0; i < n; ++i) {
		if (ansv[i] == ans) {
			for (int j = 0; j < m; ++j) {
				if (!(b[j].first <= i && i <= b[j].second)) {
					res.push_back(j);
				}
			}
			break;
		}
	}
	
	cout << ans << endl << res.size() << endl;
	shuffle(res.begin(), res.end(), rnd);
	for (auto it : res) cout << it + 1 << " ";
	cout << endl;
	
	return 0;
}