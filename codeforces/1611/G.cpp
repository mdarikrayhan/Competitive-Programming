#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <cassert>
#include <climits> //!
#include <cfloat>
#include <random>
#include <chrono>
#include <cstring> //!
#include <functional>

using namespace std;

//#define int long long
#define all(v) begin(v), end(v)
//#define pb push_back
#define rep(C, n) for(int C = 0; C < (n); C++)

using ll = long long;
using ull = unsigned long long;

template<class T>
using ve = vector<T>;
using vi = ve<int>;

using pii = pair<int, int>;

const long double pi = atanl(1) * 4;

void fast() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed; cout.precision(6);
}

void precalc() {}

void solve() {
	int n, m;
	cin >> n >> m;
	ve<string> s(n);
	ve<ve<set<int>>> v(2, ve<set<int>>(m));
	for (auto& i : s) {
		cin >> i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') {
				v[(i + j) % 2][j].insert(i);
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < m; j++) {
		for (int k = 0; k < 2; k++) {
			if (v[k][j].size()) {
				ans++;
				v[k][j].insert(INT_MIN);
				v[k][j].insert(INT_MAX);
				vi temp(all(v[k][j]));
				queue<pair<int, pii>> q;
				for (int i = 0; i + 1 < temp.size(); i++) {
					q.push({ j, {temp[i], temp[i + 1]} });
				}
				while (q.size()) {
					auto [j, p] = q.front(); q.pop();
					//cout << j << " " << p.first << " " << p.second << "\n";
					v[k][j].erase(p.first);
					v[k][j].erase(p.second);
					j++;
					p.first++;
					p.second--;
					if (j >= m || p.first > p.second || p.second < 0 || p.first > n)
						continue;
					auto it = v[k][j].lower_bound(p.first);
					int pr = p.first;
					while (it != v[k][j].end() && *it <= p.second) {
						q.push({ j, { pr, *it } });
						pr = *it;
						it++;
					}
					q.push({ j, {pr, p.second} });
				}
				//cout << "\n";
			}
		}
	}
	cout << ans << "\n";
}

signed main() {
#ifdef LOCAL
	freopen("local.in", "r", stdin);
	freopen("local.out", "w", stdout);
	using clock = chrono::system_clock;
	auto start_time = clock::now();
#endif // LOCAL
	fast();
	precalc();
	int T = 1;
	cin >> T;
	while (T--)
		solve();
#ifdef LOCAL
	auto end_time = clock::now();
	cerr << "time: " << chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count() << "ms\n";
#endif // LOCAL
	return 0;
}