#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>
#include <cassert>
#include <random>
//#include <valarray>
//#include <fstream>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define next next239
#define prev prev239
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define ba back()
#define popcount __builtin_popcountll
#define firstbit(x) (63 - __builtin_clzll(x))
#define fastIO() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

#ifdef LOCAL_BOBER
bool local = true;
//#define deb(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl
#define debn(x, n) { cout << __LINE__ << ": " << #x << "(" << n << ") = " << \
	"{"; int _f_ = 1; rep(_i_, n) {if (!_f_) cout << "|"; cout << x[_i_]; _f_= 0;} cout << "}" << endl;}
#define deba(x) { cout << __LINE__ << ": " << #x << " (size: " << sz(x) << ") = " << \
	"{"; int _f_ = 1; for (auto o : x) {if (!_f_) cout << "|"; cout << o; _f_ = 0;} cout << "}" << endl;}

#define _name(name, _1, _2, _3, _4, _5, N, ...) name ## N
#define _dbg(x) cout << #x << " = " << x << "   "
#define _dbg1(x) _dbg(x)
#define _dbg2(x, ...) _dbg(x); _dbg1(__VA_ARGS__)
#define _dbg3(x, ...) _dbg(x); _dbg2(__VA_ARGS__)
#define _dbg4(x, ...) _dbg(x); _dbg3(__VA_ARGS__)
#define _dbg5(x, ...) _dbg(x); _dbg4(__VA_ARGS__)
#define deb(...) do { cout << __LINE__ << ": "; _name(_dbg, __VA_ARGS__, 5, 4, 3, 2, 1, 0)(__VA_ARGS__); cout << endl;} while (0)

#else
bool local = false;
#define deb(...) ;
#define debn(x, n) ;
#define deba(x) ;
#define endl "\n"
#endif

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef pair<double, double> pdd;
typedef long double LD;
typedef double D;

template<class T> void print(T v) { cout << sz(v) << endl; for (auto x : v) cout << x << ' '; cout << endl; };
template<class T> void print1(T v) { cout << sz(v) << endl; for (auto x : v) cout << x + 1 << ' '; cout << endl; };
template<class T1, class T2> ostream& operator << (ostream &o, pair<T1, T2> x) {re o << x.fi << ' ' << x.se;}
template<class T1, class T2> istream& operator >> (istream &o, pair<T1, T2> &x) {re o >> x.fi >> x.se;}
template<class T> ostream& operator << (ostream &o, vector<T> &x) {for (auto &el : x) o << el << ' '; re o;}
template<class T> istream& operator >> (istream &o, vector<T> &x) {for (auto &el : x) o >> el; re o;}
template<class T1, class T2> pair<T1, T2> operator + (pair<T1, T2> a, pair<T1, T2> b) {a.fi += b.fi; a.se += b.se; re a;}
template<class T1, class T2> pair<T1, T2> operator - (pair<T1, T2> a, pair<T1, T2> b) {a.fi -= b.fi; a.se -= b.se; re a;}
template<class T1, class T2> void operator += (pair<T1, T2> &a, pair<T1, T2> b) {a.fi += b.fi; a.se += b.se;}
template<class T1, class T2> void operator -= (pair<T1, T2> &a, pair<T1, T2> b) {a.fi -= b.fi; a.se -= b.se;}

int nint() {int x; cin >> x; re x;}
double getTime() { re clock() / (double) CLOCKS_PER_SEC;};

mt19937 rnd(0);
int rand(int n) { re rnd() % n; }
int rand(int l, int r) { re rnd() % (r - l + 1) + l; }

//const int mod = 998244353;

void initIO() {
	if (local) {
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
		srand((int)time(0));
		rnd.seed((int)time(0));
	}
	else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
		fastIO();
	}
}

void solve();
void precalc();

int TID;

signed main() {
	initIO();

	int tc = 1;
//	cin >> tc;

	precalc();
	rep(tt, tc) {
		TID = tt;
//		cout << "Case #" << tt + 1 << ": ";
		solve();
	}

	if (local)
		cout << endl << "time = " << getTime() << endl;
}

void precalc() {

}

/* ================ actual code starts here ================ */


int n;
int m;

vvi a, b;

void up(vvi &a) {
	vvi u(n + m);
	rep(i, n) rep(j, m)
		u[i + j].pb(a[i][j]);
	for (auto &v : u)
		sort(all(v));
	a = u;
}

void solve() {
	cin >> n >> m;
	a.resize(n, vi(m));
	b.resize(n, vi(m));
	rep(i, n) rep(j, m)
		cin >> a[i][j];
	rep(i, n) rep(j, m)
		cin >> b[i][j];

	up(a);
	up(b);

	if (a == b)
		cout << "YES";
	else
		cout << "NO";
}









