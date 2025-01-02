#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define nl '\n'
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)((x).size())
#define pb push_back
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define uniq(v) {v.erase(unique(all(v)), (v).end());}
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define present(val, ds) ((ds).find(val) != (ds).end())
constexpr long long SZ = 2e5 + 7;
constexpr long long INF = 1e18;
constexpr long long MOD = 1e9 + 7;
constexpr long long MOD1 = 998244353;
constexpr long double PI = 3.141592653589793238462;
#define min_el(a) (*min_element(all(a)))
#define max_el(a) (*max_element(all(a)))

using ll = long long;
using in = long long int;
using ull = unsigned long long;
using lld = long double;

typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vipi;
typedef vector<vector<ll>> vvi;

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define dbg(x)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template<class T>using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

template<typename T, typename T1>T cmax(T &a, T1 b) {if (b > a) a = b; return a;}
template<typename T, typename T1>T cmin(T &a, T1 b) {if (b < a) a = b; return a;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template <typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template <typename T> istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}
template <typename T1, typename T2>ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template <typename T> ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template <typename T>void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>void print(T &&t, Args &&... args) {cout << t << " "; print(forward<Args>(args)...);}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll lcm(ll a, ll b) {return ((a * b) / gcd(a, b));}
ll expo(ll a, ll b, ll mod = MOD) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll inverse(ll a, ll m = MOD) {return expo(a, m - 2, m);}
// ll comb(ll n, ll k) {if (k > n)return 0; ll ans = F[n]; ans = mod_mul(ans, inverse(F[k])); ans = mod_mul(ans, inverse(F[n - k])); return ans;}
bool prime(ll n) {if (n < 2) return 0; for (ll x = 2; x * x <= n; x++)if (n % x == 0)return 0; return 1;}
vector<bool> sieveprime(int n) {vector<bool>v(n + 1); for (int x = 2; x <= n; x++) {if (v[x])continue; for (int y = 2 * x; y <= n; y += x)v[y] = 1;} return v;}
vi sieve(ll n) {ll*arr = new ll[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vi prime_factor(ll n) {vector<ll>v; for (int x = 2; x * x <= n; x++) {while (n % x == 0) {v.pb(x); n /= x;}} if (n > 1)v.pb(n); return v;}
vi primefactorsieve(ll n) {vi ans(n + 1, -1); for (int x = 2; x <= n; x++) {if (ans[x] == -1) { ans[x] = x; for (int y = x * x; y <= n; y += x) {if (ans[y] == -1) {ans[y] = x;}}}} vi ar; while (n > 1) {ar.pb(ans[n]); n /= ans[n];} return ar;}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
vi getDivisor(ll n) {vi v; for (int i(2); i * i <= n; i++) {if (n % i == 0) {v.pb(i); if (n / i != i) v.pb(n / i);}} sort(all(v)); return v;}
/*----------------------------------------------------------------------------------------------------------------------------*/



void solve() {
    ll n;
    cin >> n;
    vi ans(n);
    ans[0] = 2;
    ans[n - 1] = 3;
    ans[n / 2] = 1;
    ll x = 4;
    for (ll i = 0; i < n; i++) {
        if (!ans[i]) {
            ans[i] = x++;
        }
    }
    print(ans);
}



signed main() {

#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto start1 = high_resolution_clock::now();

    cout << setprecision(12) << fixed;
    int test_cases;
    test_cases = 1;
    cin >> test_cases;
    for (int i = 1; i <= test_cases; i++) {
        solve();
    }

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << lld(duration.count() / 1000.0) << '\n';
#endif
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;

    return 0;
}