#include <iomanip>
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
using namespace std::chrono;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...) 
#endif

int setbit(int x) {return __builtin_popcount(x);}
int setbit(long long x) {return __builtin_popcountll(x);}
int highbit(int x) {return (x==0?-1:31-__builtin_clz(x));}
int highbit(long long x) {return (x==0?-1:63-__builtin_clzll(x));}
int lowbit(int x) {return (x==0?-1:__builtin_ctz(x));}
int lowbit(long long x) {return (x==0?-1:__builtin_ctzll(x));}
#define ll long long
#define int ll
#define inf (int)1e9 + 5
#define inf_long_long 9223372036854775807/4
#define endl "\n"
#define mod 1000000007
#define fastinput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define umap unordered_map
#define pii pair<int,int>
#define ppiii pair<pii, int>
#define pipii pair<int, pii>
#define sz(x) ((int) x.size())
#define forn(i,a,b) for(int i=a;i<=b;i++)
#define for0(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<pii> vp;
typedef tuple<int,int,int> tiii;
typedef __int128 i128;
template<typename T,typename U>
T ceil(T x, U y) {return (x>0?(x+y-1)/y:x/y);}
vector<int> factorials;
vector<int> invf;
int bpm(int a, int b) {if (b==0) {return 1;} int ret = bpm(a, b/2); ret = (1LL * ret * ret) % mod; if (b%2==1) {ret = (1LL * ret * a) % mod;} return ret;}
int gcd(int a, int b) {if (a==0) {return b;} if (b==0) {return a;}return gcd(b%a, a);}
int lcm(int a, int b) {return a/gcd(a,b)*b;}
int inv(int a) {return bpm(a, mod-2);}
void calcfacmod(int n) {factorials.resize(n+1);factorials[0] = 1;for (int i = 1; i <= n; i++) {factorials[i] = factorials[i-1]*i;factorials[i]%=mod;}}
mt19937_64 rngg(chrono::steady_clock::now().time_since_epoch().count());
int RNG() {return rngg()%inf_long_long;}
void calcfac(int n) {calcfacmod(n);}

template<typename T>
void modpos(T &a) {T amt = (-a)/mod;amt++; amt = max(T(0), amt); a += amt*mod; a%=mod;}

int chs(int a, int b) {if (a<b || b < 0) {return 0;}if (b==a || b==0) {return 1;}return (((factorials[a]*invf[b])%mod)*invf[a-b])%mod;}
void calcinvfac(int n) {invf.resize(n);for (int i = 0; i < n; i++) {invf[i] = inv(factorials[i]);}}
// int paths(int a, int b) {return choose(a+b, a);}
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// template<typename T> 
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // remove #define int ll before use

signed main() {
	int n, m;
	cin >> n >> m;
	int mx = max(n, m);
	vector<vector<double> > dp(mx + 1, vector<double>(mx + 1, 0.0));
	for (int i = 0; i <= mx; i++) {
		dp[i][0] = 1.0;
	}
	for (int i = 0; i <= mx; i++) {
		dp[0][i] = 1.0 / (1.0 + (double)i);
	}
	for (int tmp = 1; tmp <= 2 * mx; tmp++) {
		for (int j = 1; j < tmp; j++) {
			int i = tmp - j;
			if (i > mx || j > mx) {
				continue;
			}
			double rb = 1.0;
			if (i == 1 && j == 3) {
				debug(dp[i][j - 1]);
			}
			double rn = 1.0 - dp[i][j - 1];
			double fb = (1.0 * i) / (1.0 * (i + 1.0)) * (1.0 - dp[i - 1][j]);
			double fn = fb + 1.0 / (1.0 + i);
			debug(i, j, fb, fn, rb, rn);
			double div = rn - rb + fb - fn;
			double pb1 = (rn - rb) / div;
			double pb2 = (rn - fn) / div;
			dp[j][i] = (1 - pb1) * pb2 * rb + (1 - pb1) * (1 - pb2) * rn + pb1 * pb2 * fb + pb1 * (1 - pb2) * fn;
		}
	}
	debug(dp);
	cout << setprecision(10);
	cout << dp[n][m] << " " << 1.0 - dp[n][m] << endl;
}