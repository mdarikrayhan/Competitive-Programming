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
const int N = 1e5 + 15;
int up[N][20],ST[N],dep[N];
int dfs_time=0;
ll sum[N];
vector<pll>adj[N];
inline void DFS(int node, int par) {
	up[node][0]=par;
	ST[node]=dfs_time++;
	for(int i = 1;i < 20;i++) up[node][i]=up[up[node][i-1]][i-1];
	for(auto& [i, w] : adj[node]) {
		if(i != par) {
			sum[i] = sum[node] + w;
			dep[i]=dep[node]+1;
			DFS(i,node);
		}
	}
}
struct cmp {
	bool operator()(const int& a, const int& b) const {
		return ST[a] < ST[b];
	}
};

inline int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a,b);
	int k = dep[a]-dep[b];
	for(int i = 19;i >= 0;i--) {
		if(k >> i & 1) {
			a=up[a][i];
		}
	}
	if(a == b) return a;
	for(int i = 19;i >= 0;i--) {
		if(up[a][i] != up[b][i]) {
			a=up[a][i];
			b=up[b][i];
		}
	}
	return up[a][0];
}
int n;
set<int,cmp>st;
inline ll dist(ll a, ll b) {
	if(a == n) a = *(----st.end());
	if(b == n) b=*(----st.end());
	if(a==n+1)a=*(++st.begin());
	if(b == n+1) b=*(++st.begin());
	//debug()<<imie(a)imie(b);
	return sum[a] + sum[b] - 2 * sum[lca(a,b)];
}
inline void solve_test() {
	cin >> n;
	ll ans = 0;
	for(int i = 1, a, b, c;i < n;i++) {
		cin >> a >> b >> c;
		--a;--b;
		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}
	DFS(0,0);
	ST[n]=-inf;
	ST[n+1]=inf;
	st.insert(n);
	st.insert(n+1);
	int q;
	cin >> q;
	while(q--) {
		char c;
		cin >> c;
		if(c == '?') {
			cout << ans / 2 << '\n';
		}
		else if(c == '+') {
			int x;
			cin >> x;
			--x;
			st.insert(x);
			if(st.size() == 3) continue;
			auto it = st.find(x);
			auto it2 = it;
			--it;
			++it2;
			ans -= dist(*it,*it2);
			ans += dist(*it,x);
			ans += dist(x,*it2);
			//debug()<<imie(st)imie(*it)imie(*it2);
		}
		else {
			int x;
			cin >> x;
			--x;
			if(st.size() == 3) {
				st.erase(x);
				continue;
			}
			auto it = st.find(x);
			auto it2 = it;
			--it;
			++it2;
			ans += dist(*it,*it2);
			ans -= dist(*it,x);
			ans -= dist(x,*it2);
			st.erase(x);
		}
	}
}

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
    //cin >> tt;
    while(tt--) {
		++tc;
        solve_test();
    }
}
