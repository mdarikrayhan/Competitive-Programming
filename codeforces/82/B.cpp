#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
//using lll = __int128_t;
template<typename T> using two = pair<T, T>;
#define all(X...) (X).begin(), (X).end()
#define all_r(X...) (X).rbegin(), (X).rend()
using _ntests_t = unsigned;
#define ntests _ntests_t _nt; cin >> _nt; [[maybe_unused]] NEXT_TEST: while (_nt --)
#define next_test goto NEXT_TEST
#define line "\n"
constexpr int mod  [[maybe_unused]] = 998244353;
constexpr int mod1 [[maybe_unused]] = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//srand(time(NULL));

	int n;
	cin >> n;
	if (n == 2) {
		int k;
		cin >> k;
		vector<int> a(k);
		for (auto &i : a) {
			cin >> i;
		}

		cout << "1 " << a[0] << line << k - 1 << " ";
		for (int i = 1; i < k; i ++) cout << a[i] << " ";
		cout << line;
		return 0;
	}
	int nn = n * (n - 1) / 2;
	vector<vector<int>> a(nn);
	for (auto &i : a) {
		int k; cin >> k;
		i.assign(k, 0);
		for (auto &j : i) {
			cin >> j;
		}
	}
	map<int, vector<int>> s;
	for (int i = 0; i < nn; i ++) {
		for (int j : a[i]) {
			s[j].push_back(i);
		}
	}
	map<vector<int>, vector<int>> r;
	for (auto &i : s) {
		r[i.second].push_back(i.first);
	}
	for (auto &i : r) {
		cout << i.second.size() << """"""" """"""";
		for (auto j : i.second) cout << j << """"" """"";
		cout << "" line "";
	}
}
