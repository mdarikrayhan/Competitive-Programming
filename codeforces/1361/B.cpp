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
constexpr int MOD = 1e9 + 7;
void solve() {
	//ifstream cin("nazwa.in");
	//ofstream cout("nazwa.out");
	int n, p;
	cin >> n >> p;
	vi tab(n);
	int mx = 0;
	for(auto &x : tab) {
		cin >> x;
		mx = max(mx, x);
	}
	if(p == 1) {
		cout << (n & 1) << '\n';
		return;
	}
	auto pot = [&](ll a, ll b) {
		ll res = 1;
		while(b > 0) {
			if(b & 1) {
				res = (res * a) % MOD;
			}
			a = (a * a) % MOD;
			b /= 2;
		}
		return res;
	};
	sort(all(tab), greater<int>());
	ll cnt = 0;
	ll akt = mx;
	bool czy = 0;
	debug(tab);
	for(int i = 0; i < n; i++) {
		int x = tab[i];
		if(!cnt) {
			akt = x;
		}
		while(x < akt) {
			cnt *= p;
			akt--;
			if(n - i < cnt) {
				czy = 1;
				break;
			}
		}
		debug(x, akt, cnt);
		if(czy == 1) {
			for(int j = i; j < n; j++) {
				cnt = (cnt * pot(p, akt - tab[j])) % MOD;
				akt = tab[j];
				cnt = (cnt - 1 + MOD) % MOD;
			}
			break;
		}
		else {
			if(cnt > 0) {
				cnt--;
			}
			else {
				cnt++;
			}
		}
	}
	cnt = (cnt * pot(p, akt)) % MOD;
	cout << cnt << '\n';
}
int main() {
	fastio();
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
		//debug(t);
	}
}
