// LUOGU_RID: 160272256
#include<bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using db = double;		// 有时会卡精度，视情况使用。
#define sz(vec) ((ll)vec.size())
#define all(vec) vec.begin(),vec.end()
#define Emu Smile

const ll inf = 1e18;
const int P = 1e9+7;

int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << std::fixed << std::setprecision(1);

//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	int OuO = 1;
//	std::cin >> OuO;

	std::mt19937_64 rnd(std::random_device{}());

	const int N = 1e6+5;
	std::basic_string<bool> is_prime(N,true);
	std::vector<int> prime; prime.reserve(5e4);
	for (int i = 2; i < N; ++i) {
		if (is_prime[i]) {
			prime.emplace_back(i);
		}
		for (auto j : prime) {
			if (1ll * i * j > N) break;
			is_prime[i * j] = false;
			if (i % j == 0) break;
		}
	}

	for (int piastic = 0; piastic < OuO; ++piastic) {
		int n; std::cin >> n;
		std::vector<ll> a(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		std::shuffle(all(a),rnd);
		std::vector<ll> p;
		auto getprime = [&](ll u) {
			if (!u) return;
			for (auto x : prime) {
				if (u % x == 0) p.emplace_back(x);
				while (u % x == 0) u /= x;
			}
			if (u > 1) p.emplace_back(u);
		};
		for (int i = 0; i < std::min(n,50); ++i) {
			for (int j = -1; j < 2; ++j) {
				getprime(a[i]+j);
			}
		}
		std::sort(all(p));
		p.erase(std::unique(all(p)),p.end());
		ll ret = n;
		for (auto x : p) {
			ll res = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] < x) res += x - a[i];
				else res += std::min(a[i] % x, x - (a[i] % x));
			}
			ret = std::min(ret,res);
		}
		std::cout << ret << '\n';
	}

	return 0;
}