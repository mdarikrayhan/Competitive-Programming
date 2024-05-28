#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define all(v) v.begin(), v.end()
#define logg(x) (31 - __builtin_clz(x))
#define llogg(x) (63 - __builtin_clzll(x))
#define mini(v) min_element(v.begin(), v.end())
#define maxi(v) max_element(v.begin(), v.end())
#define TIME cerr << double(clock() - st) / (double)CLOCKS_PER_SEC
#define sq(a) ((a)*(a))
#ifdef hocln
#include "deb.h"
#else
#define imie(...) ""
#define debug() cerr
#endif
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef tuple<ll, ll, ll> triple;
typedef tuple<ll, ll, ll, ll, ll> five;
typedef unsigned long long ull;
const long long INF = 4e18;
const int inf = 2e9;
const int MN = 3e5 + 15;
const int MX = 2e6 + 15;
const long long MOD = 1e9 + 7;
//const long long MOD = 998244353;
const long double PI = 3.141592653589793238462643383279502884197;
template<typename T, typename T2> bool chmax(T& a, const T2& b) { return a < b ? a = b, 1 : 0; }
template<typename T, typename T2> bool chmin(T& a, const T2& b) { return a > b ? a = b, 1 : 0; }
template<typename T> using vector2 = vector<vector<T>>;
const int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dy[] = { 1, -1, 0, 0 , 1, -1, 1, -1};
std::random_device rd;
std::mt19937 gen(rd());
ll random(ll low, ll high) { uniform_int_distribution<> dist(low, high); return dist(gen); }
template<typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first;
    return is >> p.second;
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    for (auto &i: v) os << i << ' ';
    return os;
}
int tc = 0;

inline void solve_test() {
	int n;
	cin >> n;
	vector<ll>v(n);
	for(auto& i : v) cin >> i;
	vector<pii>ans;
	auto c = v;
	int mn = mini(c)-c.begin(),mx=maxi(c)-c.begin();
	while(ans.size()<=32&&c[mx]+c[mn]<0)c[mx]*=2,ans.emplace_back(mx,mx);
	for(int i = 0;i < n;i++) {
		if(c[i] < 0) {
			ans.emplace_back(i,mx);
		}
	}
	if(ans.size()+n-1 <= 31) {
		for(int i = 1;i < n;i++) ans.emplace_back(i,i-1);
		cout << ans.size() << '\n';
		for(auto& i : ans) cout << 1+i.first << ' ' << 1+i.second << '\n';
		return;
	}
	ans.clear();
	while(ans.size() <= 10 && v[mx]+v[mn]>0) v[mn] *= 2,ans.emplace_back(mn,mn);
	for(int i = 0;i < n;i++) {
		if(v[i] > 0) ans.emplace_back(i,mn);
	}
	for(int i = n - 2;i >= 0;i--) {
		ans.emplace_back(i,i+1);
	}
	cout << ans.size() << '\n';
	for(auto& i : ans) cout << 1+i.first << ' ' << 1+i.second << '\n';
	//for(int i = n - 1;i >= 1;i--) cout << i << ' ' << i + 1 << '\n';
}
// 5 1 2 3 4
int main()
{
    //srand(chrono::steady_clock::now().time_since_epoch().count());
    //freopen("convention2.in", "r", stdin);
    //freopen("convention2.out", "w", stdout);
	//cout << "Case #" << tc << ": " << ans << '\n';
	//cout << fixed << setprecision(15);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
		++tc;
        solve_test();
    }
}
