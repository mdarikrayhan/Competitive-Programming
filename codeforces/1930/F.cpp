// LUOGU_RID: 160260187
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
	std::cin >> OuO;
	for (int piastic = 0; piastic < OuO; ++piastic) {
		int n,Q; std::cin >> n >> Q;
		const int N = std::__lg(n) + 1;
		const int xn = (1ll << N) - 1;
		ll ans = 0;
		auto insert = [&](auto &self,std::basic_string<bool> &vis,ll x) {
			if (vis[x]) return;
			vis[x] = 1;
			for (int i = 0; i < N; ++i) {
				if ((1ll << i) & x) {
					self(self,vis,x-(1ll<<i));
				}
			}
		};
		auto query = [&](const std::basic_string<bool> &vis, ll x) -> ll {
			ll ret = 0;
			for (int i = N-1; i >= 0; --i) {
				int id = (x >> i) & 1;
				if (id) {
					if (vis[ret + (1ll << i)]) {
						ret += 1ll << i;
					}
				}
			}
			return ret;
		};
		std::basic_string<bool> vis(xn+1,false),evis(xn+1,false);
		for (int i = 0, x; i < Q; ++i) {
			std::cin >> x;
			x = (x + ans) % n;
			insert(insert,vis,x), insert(insert,evis,(~x)&xn);
			ans = std::max({ans, query(vis,(~x)&xn), query(evis,x)});
			std::cout << ans << " \n"[i == Q-1];
		}
	}

	return 0;
}