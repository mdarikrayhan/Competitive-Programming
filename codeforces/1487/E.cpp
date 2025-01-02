#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

// using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define ll long long
#define imax INT_MAX
#define llmax LLONG_MAX
#define precise_cout(a,b) cout<<fixed<<setprecision(b)<<a<<"\n";
#define f(i,a,b) for(int i=a;i<=(int)b;i++)
#define fn(i,b,a) for(int i=b;i>=(int)a;i--)
#define debug(x) cerr << #x<<" : "; _print(x); cerr << endl;
#define vi vector<int>
#define vll vector<ll>
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
// #endif

typedef unsigned long long ull;
typedef long double lld;

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(ll t) {cerr << t;}

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

/*---------------------------------------------------------------------------------------------------------------------------*/
// ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
// void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
// int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
// void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
// int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
// int mminvprime(int a, int b) {return expo(a, b - 2, b);}
// int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((0ll + a + b) % m) + m) % m;}
// int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((1ll * a * b) % m) + m) % m;}
// int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
// int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m

// Fenwick tree
const int N=2e5+10; 
//struct BIT {
// ll c[N];
// void add(ll x, ll v, ll n) {
//   while(x <= n) c[x] += v, x += x & -x;
// }
// ll query(ll x) {
//   ll s = 0;
//   while(x) s += c[x], x -= x & -x;
//   return s;
// }
// ll search(ll prefSum, ll n){  // using Binary lifting, search lower_bound for prefSum in O(logn) 
//   ll num = 0;
//   ll sum = 0;
//   for(int i = 21; i>=0 ; --i){
//       if((num + (1<<i) <= n) && (sum + c[num + (1<<i)] <= prefSum)){
//           num += (1<<i);
//           sum += c[num];
//   }
// }
// return num + 1;
// }
//} tr;
// binary exponentiation
// ll bexp(ll a, ll b) { ll res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
 
// binary exponentiation modulo mod
// ll bexpM(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
 
// sieve of eratosthenes for primes
// const int P = 10000000;
// int prime[P + 1];
// void sieve() { prime[0] = 0; prime[1] = 0; for (int i = 2; i <= P; i++) { prime[i] = 1; } for (int i = 2; i * i <= P; i++) { if (prime[i] == 1) { for (int j = i * i; j <= P; j += i) { prime[j] = 0; } } } }
 
// sieve of eratosthenes for 'prime' factorization, O(n(log(log(n)))) for precomputation of spf, O(log(n)) thereafter to factorize each n
// ll spf[P + 1];
// vector<ll> primefactorize(ll n) { vector<ll> f; while(n>1){ f.pb(spf[n]); n/=spf[n]; } return f; }
// void sieve_spf() { spf[0] = 0; spf[1] = 0; for (int i = 2; i <= P; i++) { spf[i] = -1; } for (int i = 2; i <= P; i++) { if (spf[i] == -1) { for (int j = i; j <= P; j += i) { if (spf[j] == -1) { spf[j] = i; } } } } }
 
// extended euclid algorithm
// ll extendedgcd(ll a, ll b, ll &x, ll &y) { if (b == 0) { x = 1; y = 0; return a; } ll x1, y1; ll d = extendedgcd(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return d; }
 
// modulo multiplicative inverse
// ll modInverse(ll a, ll m) { ll x, y; ll g = extendedgcd(a, m, x, y); ll res = (x % m + m) % m; return res; }
 
// ncr using precomputed factorials and modInverse
// vector<ll> fact(3e5+10,0);
// void all_factorial_mod(int md) { fact[0]=1; for(int i=1; i<=300010; i++) fact[i]=(fact[i-1]*i)%md; }
// ll ncrMOD(ll n,ll r, ll md) { return ((fact[n]*modInverse(fact[r],md)%md)*modInverse(fact[n-r],md))%md; }
 
// vector<ll> phi(1e6,0); 
// phi function O(nlog(log(n)))
// void compute_phi() {int n=1e6; phi[0]=0; phi[1]=0; for(int i=2;i<=n;i++) phi[i]=i; for(int i=2;i<=n;i++) {if(phi[i]==i){for(int j=i;j<=n;j+=i)	phi[j]-=phi[j]/i;}}}
 
// phi function(1) O(sqrt(n)log(n))
// ll phi1(ll n) { ll result = n; for (ll i = 2; i * i <= n; i++) { if (n % i == 0) { while (n % i == 0) n /= i; result -= result / i; } } if (n > 1) result -= result / n; return result; }
 
// nCr (O(n))
// ll ncr(ll n, ll k) { ll res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) { res *= (n - i); res /= (i + 1); } return res; }

// nCr with modulo (O(rlogn))
// ll fact[N], inv[N];
// void pre(ll mod){fact[0]=inv[0]=1;f(i,1,N){fact[i]=(fact[i-1]*i)%mod;inv[i]=bexpM(fact[i], mod-2,mod);}}
// ll ncrMOD(ll n, ll k, ll mod) { ll res = 1; if (k > n - k) k = n - k; for (int i = 0; i < k; ++i) { res = (res * (n - i)) % mod; res = (res * modInverse(i + 1, mod)) % mod; } return res % mod; }
 
// nCr with modulo (O(1) after O(n) precomputation)
// ll ncrMOD(ll n, ll r, ll mod) { if(r>n || n<0) return 0; if(r==0 || n==r) return 1; return (((fact[n] * inv[r]) % mod) * inv[n-r]) % mod;}
 
// factorial without modulo 
// ll factorial(ll n) { ll res = 1; for (int i = 2; i <= n; i++) res = res * i; return res; }
 
// factorial with modulo 
// ll factorialMOD(ll n, ll m) { ll res = 1; for (int i = 2; i <= n; i++) res = ((res % m) * (i % m)) % m; return res % m; }
 
// Check if a number is a Perfect square
// bool checkperfectsquare(ll n) { if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) { return true; } else { return false; } }
 
// Divisors of a number in O(sqrt N) -> including 1 and n
// vector<ll> factorize(ll n) { vector<ll> v; v.push_back(1); for(int i=2;i<sqrt(n);i++) { if (n % i == 0) { v.push_back(i); v.push_back(n / i); } } if (checkperfectsquare(n) == 1) { v.push_back(sqrt(n)); } if (n != 1) { v.pb(n); } return v; }
 
// calculate mex of a set
// ll calculateMex(vector<ll> A) { set<int> Set(A.begin(), A.end()); ll Mex = 0; while (Set.find(Mex) != Set.end()) Mex++; return (Mex); }
 
// count number of set bits in a number
// ll countSetBits(ll n) { if (n == 0) return 0; return (n & 1) + countSetBits(n >> 1); }

// This section if not commented will take almost 117 mb, so wherever memory limit is low say 64 mb or tighter, make sure that not this entire section is uncommented.
// use (a+b-1)/b instead of ceil(a*1.0/b), as it does not suffer from floating point imprecision

// BEFORE SUBMISSION, 
// 1. check for uninitialised variables, 
// 2. check for possible int overflow, 
// 3. check for precision issues, 
// 4. check for invalid index access 

// Don't get stuck on one approach, incorrect approach causes more WA than incorrect implementation.
/*--------------------------------------------------------------------------------------------------------------------------*/
// Time complexity : O((n+m)logn)

void solve(){
    vector<vll> a(4);
    vll len(4);
    f(i,0,3) cin>>len[i];
    f(i,0,3){
        f(j,0,len[i]-1){
            ll x;
            cin>>x;
            a[i].pb(x);
        }
    }
    vector<vector<vll>> bad(3);
    vll m(3);
    f(i,0,2){
        cin>>m[i];
        bad[i].resize(len[i+1]);
        f(j,0,m[i]-1){
            ll x,y;
            cin>>x>>y;
            x--, y--;
            bad[i][y].pb(x);
        }
    }
    vll dp[4];
    dp[0]=a[0];
    f(i,1,3){
        multiset<ll> ms;
        f(j,0,len[i-1]-1) ms.insert(dp[i-1][j]);
        dp[i].resize(len[i]);
        f(j,0,len[i]-1){
            for(auto x:bad[i-1][j])
            ms.erase(ms.find(dp[i-1][x]));
            if(ms.empty()) dp[i][j]=INF;
            else dp[i][j]= *ms.begin()+a[i][j];
            for(auto x:bad[i-1][j])
            ms.insert(dp[i-1][x]);
        }
    }
    ll ans=*min_element(all(dp[3]));
    if(ans>(4e8+10)) cout<<"-1\n";
    else cout<<ans<<"\n";
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}