#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <sstream>
#include <utility>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define MOD2 100000000
#define INF 1e18
#define INF1 1000000000
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define printd(x, y) cout << fixed << setprecision(y) << x << endl;
#define debug(x) cout << #x << " " << x << endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
bool isprime(ll n){if (n <= 1){return false;}if (n <= 3) {return true;}if (n % 2 == 0) {return false;} for (ll i = 5; i * i <= n; i += 6){if (n % i == 0 || n % (i + 2) == 0){return false;}}return true;}
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll xgcd(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; } ll x1, y1; ll d = xgcd(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return d; }
ll mminv(ll a, ll b) {ll x,y; xgcd(a, b, x, y); return x;} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
// ll ncr(ll n, ll r) { ll res = 1; r = std::min(r, n - r); for (ll i = 0; i < r; ++i) res = res * (n - i) / (i + 1); return res; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;} 
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} // to get random number between l and r
ll modinv(ll a, ll m) { ll x, y, g = xgcd(a, m, x, y); return (g != 1) ? -1 : (x % m + m) % m; }
ll findMex(vector<ll> &a) {vector<bool> f(a.size() + 1, 0);for (int i : a) if (i <= (int) a.size()) f[i] = 1;ll mex = 0;while (f[mex]) ++mex;return mex;}
vector<ll> findDivisors(ll n){vector<ll> s;for(ll i=1;i<=sqrt(n);i++){if(n%i == 0){ if(n/i == i){s.pb(i);}else{s.pb(i);s.pb(n/i);}}}return s;}

/*--------------------------------------------------------------------------------------------------------------------------*/
ll find(vector<ll>& x, ll y){
    ll mini = INF, idx = -1;
    rep(i, 0, x.size()){
        if(abs(x[i] - y) < mini){
            mini = abs(x[i] - y);
            idx = i;
        }
    }
    return idx;
}

void solve(){
    ll n;cin>>n;
    vector<ll> a(n), b(n);
    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];

    ll ans = INF;
    vector<ll> mp1 = {0, find(b, a[0]), n-1};
    vector<ll> mp2 = {0, find(b, a[n-1]), n-1};
    
    rep(i, 0, 3){
        rep(j, 0, 3){
            ll curr_ans = abs(a[0] - b[mp1[i]]) + abs(a[n-1] - b[mp2[j]]);
            
            if(mp1[i] > 0 && mp2[j] > 0){
                curr_ans += abs(b[0] - a[find(a, b[0])]);
            }
            if(mp1[i] < n-1 && mp2[j] < n-1){
                curr_ans += abs(b[n-1] - a[find(a, b[n-1])]);
            }

            ans = min(ans, curr_ans);
        }
    }
    cout<<ans<<endl;
} 
 

int main()
{
    // fastio();
    auto start1 = high_resolution_clock::now();
    int t = 1; 
    cin>>t;
    while(t--){
        // debug(t)
        solve();

    }
    
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop1 - start1);
    cerr << "Time: " << duration . count() << " s" <<endl;

    return 0;
} 