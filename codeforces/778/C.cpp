#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=int(a);i<int(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define fore(e,c) for(const auto &e : (c))
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define sz(v) (int(v.size()))
#define all(v) begin(v), end(v)
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
using ll = long long;
using ull = unsigned ll;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using veci = vector<int>;
using vecll = vector<ll>;
using vecb = vector<bool>;
using vecveci = vector<veci>;
template<class T>ostream&operator<<(ostream&o,vector<T>const&v){o<<"[ ";for(auto const&x:v)o<<x<<" ";return o<<"]";}
template<class T,class U>ostream&operator<<(ostream&o,pair<T,U>const&p){return o<<"("<<p.fst<<", "<<p.snd<<")";}
template<class T>void maxa(T&x,T const&y){  x=max(x,y);  }
template<class T>void mina(T&x,T const&y){  x=min(x,y);  }
template<class T>void sort2(T&x,T&y){  if(y<x)swap(x,y);  }
template<class T>void sort3(T&x,T&y,T&z){  sort2(x,y);sort2(y,z);sort2(x,y);  }

/* MODULAR ARITHMETIC 
int const mod = 1000000007; // NTT: 998244353
int add(int x, int y) { int z = x + y; return x - (x>=mod)*mod; }
int sub(int x, int y) { return add(x, mod-y); }
int mul(int x, int y) { return ll(x) * y % mod; }
int pot(int x, int y) { int z = 1; while (y) { if (y%2) z = mul(z, x); x = mul(x, x); y /= 2; } return z; }
int inv(int x) { return pot(x, mod-2); }
// */

void solve();
void global_init();

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	global_init();
	forn(_,t) solve();
}

const ll MAXN = 300100;
const ll INF = 1e18+100;
const ld EPS = 1e-9;
const ld PI = acosl(-1);

void global_init() {

}

int dep[MAXN];
vector<int> by_dep[MAXN];
vector<pair<int, char>> g[MAXN];

/*
   1
   |c
   2
 /a  \t
3     5
|t
4
*/

void dfs(int u) {
	by_dep[dep[u]].pb(u);
	for (auto [v, _] : g[u]) {
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

int merge(veci us) {
	if (sz(us) < 2) return 0;
	int ans = sz(us) - 1;
	map<char, veci> cnd;
	for (int u : us) {
		for (auto [v, c] : g[u]) {
			cnd[c].pb(v);
		}
	}
	for (auto& [c, vs] : cnd) {
		ans += merge(move(vs));
	}
	return ans;
}

void solve() {

	int n;

	cin >> n;

	forn(i, n-1) {
		int x, y; char t;
		cin >> x >> y >> t;
		--x; --y;
		g[x].pb({y, t});
	}

	dep[0] = 0;
	dfs(0);

	pii ans = {INT_MIN, INT_MIN};
	forn(i, n) {
		if (by_dep[i].empty()) break;

		int curr = 0;
		for (int u : by_dep[i]) {
			if (not g[u].empty()) curr++;
			veci vs;
			for (auto [v, c] : g[u]) {
				vs.pb(v);
			}
			curr += merge(move(vs));
		}

		maxa(ans, {curr, -i});
	}

	cout << n - ans.fst << "\n";
	cout << -ans.snd + 1 << "\n";
}
