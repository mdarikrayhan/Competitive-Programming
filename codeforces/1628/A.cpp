// जय बजरंग बली
///░░░░░░░░░░░░░▄░░░░░░░░░░░░░░░░░░░░░
///░░░░░░░░░░░▄▐░▄▄█████▄▄░░░░░░░░░░░░░░
///░░░░░░░░░▄█████████████▄▀▄▄░▄▄▄░░░░░░░
///░░░░░░░░█████████████████▄██████░░░░░░░
///░░░░░░░████▐█████▌████████▌█████▌░░░░░░░
///░░░░░░████▌█████▌█░████████▐▀██▀░░░░░░░
///░░░░▄█████░█████▌░█░▀██████▌█▄▄▀▄░░░░░░░
///░░░░▌███▌█░▐███▌▌░░▄▄░▌█▌███▐███░▀░░░░░░░
///░░░▐░▐██░░▄▄▐▀█░░░▐▄█▀▌█▐███▐█░░░░░░░░░░░
///░░░░░███░▌▄█▌░░▀░░▀██░░▀██████▌░░░░░░░
///░░░░░░▀█▌▀██▀░▄░░░░░░░░░███▐███░░░░░░░░░
///░░░░░░░██▌░░░░░░░░░░░░░▐███████▌░░░░░░░░
///░░░░░░░███░░░░░▀█▀░░░░░▐██▐███▀▌░░░░░░░░
///░░░░░░░▌█▌█▄░░░░░░░░░▄▄████▀░▀░░░░░░░
///░░░░░░░░░█▀██▄▄▄░▄▄▀▀▒█▀█░▀░░░░░░░
///░░░░░░░░░░░░▀░▀█▀▌▒▒▒░▐▄▄░░░░░░░
///░░░░░░░░░░░▄▄▀▀▄░░░░░░▄▀░▀▀▄▄░░░░░░░
///░░░░░░░░░▄▀░▄▀▄░▌░░░▄▀░░░░░░▄▀▀▄░░░░░░░
///░░░░░░░░▐▒▄▀▄▀░▌▀▄▄▀░░░░░░▄▀▒▒▒▐░░░░░░░
///░░░░░░░▐▒▒▌▀▄░░░░░▌░░░░▄▄▀▒▐▒▒▒▒▌░░░░░░░
///░░░░░░▐▒▒▐░▌░▀▄░░▄▀▀▄▀▀▒▌▒▐▒▒▒▒▐▐░░░░░░░░
///░░░░░░▌▄▀░░░▄▀░█▀▒▒▒▒▀▄▒▌▐▒▒▒▒▒▌▌░░░░░░░
///░░░░░▄▀▒▐░▄▀░░░▌▒▐▒▐▒▒▒▌▀▒▒▒▒▒▐▒▌░░░░░░
#include <bits/stdc++.h>
using namespace std;

 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;     
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef priority_queue<int, vector<int>, greater<int>>  min_heap32;
typedef priority_queue<ll, vector<ll>, greater<ll>>     min_heap64;
typedef priority_queue<int>   max_heap32;
typedef priority_queue<ll>   max_heap64;
typedef unordered_map<int, int> umap32;
typedef unordered_map<ll, ll>   umap64;

#define MOD1 998244353
#define MOD 1000000007
#define PI 3.141592653589793238462
#define INF 1e18
#define endl '\n'
#define int long long
#define ld long double
#define sp(x, y) fixed << setprecision(y) << x;
#define pb push_back
#define ppb pop_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define f(i,x,y) for(int i=x;i<y;i++)
#define fr(i, s, e) for (int i = (s); i >= (e); i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define fv(i,x,y,v) for(int i=x;i<y;i++) cout << v[i] << " ";
#define eb emplace_back
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define start_zero __builtin_clz
#define end_zero __builtin_ctz
#define eo_one __builtin_parity
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937     rng(chrono::steady_clock::now().time_since_epoch().count());
#define w(x)            int x; cin>>x; while(x--)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) { out << "[ "; for (const auto &x : v) out << x << ' '; out << "] "; return out; }
template <typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in; }
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
ll expo(ll a, ll b, ll mod){ll r=1;while(b){if(b&1)r=(r*a)%mod;a=(a*a)%mod;b=b>>1;}return r;}//iterative(binary bits b are only multiplied)
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
float log_a_to_base_b(ll a, ll b) {return (float)log(a) / (float)log(b);}
int isPrime(int N){if(N<2 || (!(N&1) && N!=2))return 0;for(int i=3; i*i<=N; i+=2){if(!(N%i))return 0;}return 1;}
 
vector<ll> primeFactors(ll n){vector<ll>factors;while(n%2==0){factors.push_back(2);n=n/2;}for(int i=3;i<=sqrt(n);i=i+2){while(n%i==0){factors.push_back(i);n=n/i;}}if(n>2)factors.push_back(n);return factors;}
vector<ll> allFactors(ll n)/*unsorted*/{vector<ll> factors;for(int i=1;i<=sqrt(n);i++){if(n%i==0){factors.push_back(i);if(n/i!=i)factors.push_back(n/i);}}return factors;} 
void printBinary(int num){for(int i=25;i>=0;--i){cout<<((num>>i)&1);}cout<<endl;}
double sqf(double n){
     double l = 1, h = n, mid, ans;
     f(i,0,63){
        mid = (l+h)/2;
        if(mid*mid <= n){
            ans = mid;
            l = mid;
        }
        else{
            h = mid;
        }
     }
     return ans;
}


// Power under mod (a ^ b) % mod
int modpow(int a, int b, int m = MOD) {
    a = a & m; 
    int ans = 1;
    while (b) {
        if (b & 1) { 
            ans = (ans * a) % m; 
        }
        b = b >> 1; 
        a = (a * a) % m;
    }
    return ans;
}

// Inverse Mod (1 / a) % mod  
int modinv(int a, int m = MOD) { 
    return modpow(a, m - 2); 
}

const int N = 2e5 + 7;
vector<int> fac;

void fact() {
    fac.resize(N);
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
}

// // nCr % m
int nCr(int n, int r, int m = MOD) {
    if(n < r) {
        return 0;
    }
    if(r == 0) {
        return 1;
    }
    int num = (fac[n] * modinv(fac[r], m)) % m;
    int den = modinv(fac[n - r], m) % m;
    return (num * den) % m;
}
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// a+b=a|b + a&b
// a+b=a^b + 2(a&b)
// a|b=a^b + a&b
// bitset<10000001> vis;
// set difference (a&(~b)) -> a and b are sets
//  x ^ ( x & (x-1)) : Returns the rightmost 1 in binary representation of x.
// accumulate
// vector<vector<int>> v( n , vector<int> (m, 0)); 
// set<int, decltype(cmp)*> s(cmp);
// priority_queue<T, vector<T>, decltype(&cmp)> pq(cmp);
// auto lmb = [&](){};
// n ≤ 10 O ( n!)
// n ≤ 20 O (2n )
// n ≤ 500 O ( n3 )
// n ≤ 5000 O ( n2 )
// n ≤ 1e6 O ( n log n) or O ( n)
// n is large O (1) or O (log n)

 
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
A -> 5min, B -> 10 min, C -> 15min
STL, Greedy, BS, Prefix/Difference, Math he h...
Don't Stick on one approach
Reading >> (Implementation + Code) ABC m
*/

void solve(){
   //BKL Proof karke Submit karna 
   int n;
   cin >> n;
   vector<int> v(n, 0);
   map<int, int> unseen, seen;
   f(i,0,n){
    cin >> v[i];
    unseen[v[i]]++;
   }
   vi ans;
   int mex = 0;
   f(i,0,n){
     seen[v[i]]++;
     unseen[v[i]]--;
    
     while(seen[mex] > 0){
        mex += 1;
     }

     if(!unseen[mex]){
        ans.pb(mex);
        mex = 0;
        seen.clear();
     }
   }

   cout << sz(ans) << endl;
   fv(i,0,sz(ans),ans)
   cout << endl;
}

signed main() {
    FIO;    
    w(t){
      solve();
    }
    return 0;
} 






 