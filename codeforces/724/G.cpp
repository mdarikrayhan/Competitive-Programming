// LUOGU_RID: 160085759
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

struct HBasis{

	std::vector<ll> v;int n;
	HBasis(int n):v(n),n(n){}
	int insert(ll x){
		for (int i = n - 1; i >= 0; --i){
			//写int biti = 1 << i的人有难了，大数据会教他做人
			ll biti = 1ll << i;
			if (!(x & biti))continue;
			if (!v[i]) { v[i] = x;return 1; }
			x ^= v[i];
		}
		return 0;
	}
	int query(ll x){
		for (int i = n - 1; i >= 0; --i){
			//写int biti = 1 << i的人有难了，大数据会教他做人
			ll biti = 1ll << i;
			if (!(x & biti)) continue;
			if (!v[i]){ return 1; }
			x ^= v[i];
		}
		return 0;
	}
	void independ(){        //使每个基互相独立
		for (int i = 0; i < n; ++i){
			if (!v[i]) continue;
			for (int j = i - 1; j >= 0; --j){
				ll biti = 1ll << j;
				if (!(v[i] & biti) || !v[j])continue;
				v[i] ^= v[j];
			}
		}
	}
};

int main(){

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << std::fixed << std::setprecision(1);

//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	int OuO = 1;
//	std::cin >> OuO;

	const int N = 60;

	for (int piastic = 0; piastic < OuO; ++piastic) {
		int n,m; std::cin >> n >> m;
		std::vector<ll> p2(n+1); p2[0] = 1;
		for (int i = 0; i < n; ++i) {
			p2[i+1] = p2[i] * 2 % P;
		}
		std::vector eg(n,std::vector<std::pair<ll,ll>>());
		{
			int x,y; ll w;
			for (int i = 0; i < m; ++i) {
				std::cin >> x >> y >> w; x--, y--;
				eg[x].emplace_back(y,w), eg[y].emplace_back(x,w);
			}
		}
		std::vector<ll> val(n,-1);
		ll ret = 0;
		{
			for (int i = 0; i < n; ++i) {
				if (val[i] == -1) {
					HBasis hb(N);
					std::vector<std::array<ll,2>> b(N,{0,0});
					val[i] = 0;
					ll cnt1 = 0, cnt2 = 0;
					auto dfs = [&](auto &self,int u,int fa) -> void {
						for (int i = 0; i < N; ++i) {
							b[i][!!((1ll << i) & val[u])] ++;
						}
						cnt1 ++;
						for (auto [v,w] : eg[u]) {
							if (fa == v) continue;
							if (val[v] == -1) {
								val[v] = val[u] ^ w;
								self(self,v,u);
							} else {
								hb.insert(val[u] ^ w ^ val[v]);
							}
						}
					};
					dfs(dfs,i,-1);
					std::vector<ll> can(N);
					for (auto x : hb.v) {
						if (x) cnt2 ++;
						for (int j = 0; j < N; ++j) {
							can[j] |= (x >> j) & 1;
						}
					}
					for (int j = 0; j < N; ++j) {
						if (can[j]) {
							ret = (ret + (cnt1 * (cnt1-1) / 2) % P * p2[cnt2-1] % P * p2[j] % P) % P;
						} else {
							ret = (ret + b[j][0] * b[j][1] % P * p2[cnt2] % P * p2[j] % P) % P;
						}
					}
				}
			}
		}
		std::cout << ret << '\n';

	}

	return 0;
}