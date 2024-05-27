#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class A, class B>
ostream& operator<<(ostream& o, const pair<A, B>& p) {return o << '(' << p.first << ", " << p.second << ')';}
template<size_t Index = 0, typename... Types>
ostream& printTupleElements(ostream& o, const tuple<Types...>& t) {if constexpr (Index < sizeof...(Types)){if(Index > 0){o << ", ";}o << get<Index>(t);printTupleElements<Index + 1>(o, t);}return o;}
template<typename... Types>
ostream& operator<<(ostream& o, const tuple<Types...>& t){o << "(";printTupleElements(o, t);return o << ")";}
template<class T>
auto operator<<(ostream& o, const T& x) -> decltype(x.end(), o){o << '{';bool first = true;for (const auto& e : x){if (!first){o << ", ";}o << e;first = false;} return o << '}';}
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}
size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
//#define DEBUG
#ifdef DEBUG
#define fastio()
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define debug(...)
#endif
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define pi pair<int, int>
#define pll pair<ll, ll>
#define st first
#define nd second
#define vi vector<int>
#define vll vector<ll>
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
void solve() {
	//ifstream cin("nazwa.in");
	//ofstream cout("nazwa.out");
	int n;
	cin >> n;
	vi tab(n + 1);
	int bit = 0;
	for(int i = 1; i <= n; i++) {
		cin >> tab[i];
		while((1 << (bit + 1)) <= tab[i]) {
			bit++;
		}
	}
	vector<vi>pref(bit + 2, vi(n + 1, 0));
	for(int i = 1; i <= n; i++) {
		int x = 0;
		for(int j = bit; j >= 0; j--) {
			x = (x + (tab[i] & (1 << j)));
			pref[j][i] = x;
		}
		for(int j = bit; j >= 0; j--) {
			pref[j][i] >>= j;
		}
	}
	int ans = 0;
	for(int i = 0; i <= bit; i++) {
		vi xors(n + 1, 0);
		int dl = (bit - i);
		vector<vi>ktp((1 << dl)), ktnp(1 << dl);
		ktp[xors[0]].eb(0);
		int lst = 1;
		debug(i + 1, (1 << dl));
		for(int j = 1; j <= n; j++) {
			if(!(tab[j] & (1 << i))) {
				lst = j + 1;
			}
			debug(pref[i + 1][j]);
			xors[j] = xors[j - 1] ^ pref[i + 1][j];
			debug(xors[j]);
			if(j & 1) {
				auto it = lower_bound(all(ktnp[xors[j]]), lst - 1);
				if(it != ktnp[xors[j]].end()) {
					ans = max(ans, j - *it);
				}
				ktnp[xors[j]].eb(j);
			}
			else {
				auto it = lower_bound(all(ktp[xors[j]]), lst - 1);
				if(it != ktp[xors[j]].end()) {
					ans = max(ans, j - *it);
				}
				ktp[xors[j]].eb(j);
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	fastio();
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
}
