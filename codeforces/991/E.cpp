#include <bits/stdc++.h>
using namespace std;
using LL = long long;

map<LL,int> mp[20];

void solve() {

	LL n;
	cin >> n;

	LL n_ = n , B = 0;
	vector<int> d(10);
	while (n_) {
		B += 1;
		d[n_ % 10] += 1;
		n_ /= 10;
	}
	
	vector<LL> fac(20);
	fac[0] = 1;
	for (int i = 1 ; i <= 19 ; ++i) {
		fac[i] = fac[i - 1] * i; 
	}
	for (int i = 2 ; i <= 19 ; ++i) {
		LL x = fac[i];
		for (LL j = 2 ; j * j <= x ; ++j) {
			if (x % j == 0) {
				int cnt = 0;
				while (x % j == 0) {
					x /= j;
					++cnt;
				}
				mp[i][j] = cnt;
			}
		}
		if (x != 1) {
			mp[i][x] = 1;
		}
	}
	
	LL ans = 0;
	vector<int> num(10);
	auto func = [&] (vector<int>& num) -> LL {
		int S = 0;
		for (int i = 0 ; i <= 9 ; ++i) {
			S += num[i];
		}
		auto P = mp[S];
		for (int i = 0 ; i <= 9 ; ++i) {
			if (num[i] != 0 && num[i] != 1) {
				for (auto [x , y] : mp[num[i]]) {
					P[x] -= y;
				}
			}
		}
		LL ans = 1;
		for (auto [x , y] : P) {
			for (int i = 1 ; i <= y ; ++i) {
				ans = ans * x;
			}
		}
		return ans;
	};

	function<void(int)> dfs = [&] (int u) {
		if (u == 10) {
			// cout << "#" << "\n";
			// for (int i = 0 ; i <= 9 ; ++i) {
			// 	cout << i << " " << num[i] << "\n";
			// }
			ans += func(num);
			if (num[0]) {
				auto tmp = num;
				tmp[0] -= 1;
				ans -= func(tmp);
			}
			return;
		}
		if (!d[u]) dfs(u + 1);
		for (int i = 1 ; i <= d[u] ; ++i) {
			num[u] = i;
			dfs(u + 1);
			num[u] = 0;
		}
	};
	dfs(0);

	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
	// cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}