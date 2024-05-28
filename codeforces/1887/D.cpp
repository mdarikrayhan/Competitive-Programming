//Never compromise. Not even in the face of Armageddon.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

//pragmas
#pragma GCC optimize("03")
#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("01, 02, 03, 0fast, unroll-loops")              //Retard mode
//#pragma GCC optimize("Ofast,unroll-loops,omit-frame-pointer,inline")     //Optimization flags
//#pragma GCC option("arch=native,tune=native,no-zero-upper")              //Enable AVX

//types
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define TYPE long long
#define ppair pair<TYPE, TYPE>
#define vecvec(a, T, i, j, x) vector<vector<T>> a (i, vector<T> (j, x))
#define vecvecvec(a, T, i, j, k, x) vector<vector<vector<T>>> a (i + 1, vector<vector<T>>(j + 1, vector<T>(k + 1, x)))

using namespace std;
using namespace __gnu_pbds;

//random stuff
#define all(a) a.begin(),a.end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define sz(x) (long long int)x.size()
#define F first
#define S second
#define sp " " 
const ll inf = 0x3f3f3f3f, INF = 1e18;
const int MOD = 1e9 + 7;
const ll BIG_MOD = 489133282872437279; //use to decrease hash collision probability

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;             //for multiset, use less_equal and erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define safe_map unordered_map<long long, int, custom_hash>
#define hashmap gp_hash_table<int, int, custom_hash>


//debug
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
#define debug(x...) {cerr << "[" << #x << "] = ["; _print(x);}
#define reach cerr<<"reached"<<endl
#else
#define debug(x...)
#define reach 
#endif


/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
ll ceil_div(ll x, ll y){return (x + y - 1) / y;}
unsigned long long power(unsigned long long x,ll y, ll p){unsigned long long res = 1;x = x % p; while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
unsigned long long modInverse(unsigned long long n,int p){return power(n, p - 2, p);}
ll nCr(ll n,ll r, ll p){if (n < r)return 0;if (r == 0)return 1;unsigned long long fac[n + 1];fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;}
ll accumulate(const vector<long long int> &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

//#define int int64_t

const int MAXN = 3e5+5;
const int R = 1800;


struct Block
{
    int mn, mx;
    int p[MAXN];
};
Block block[MAXN/R + 10];

int n, q;
int a[MAXN];
int pre[MAXN], suf[MAXN];
int bpre[MAXN/R + 10], bsuf[MAXN/R + 10];

//code starts
int32_t main()
{
    fastio();

    cin >> n;
    for(int i = 1; i <= n; i ++)    cin >> a[i];

    for(int b = 1; b <= ceil_div(n, R); b ++)
    {
        int s = (b - 1) * R + 1, e = min(n, b * R);

        pre[s - 1] = 0, suf[e + 1] = n + 1;

        for(int i = s; i <= e; i ++)    pre[i] = max(pre[i - 1], a[i]);
        for(int i = e; i >= s; i --)    suf[i] = min(suf[i + 1], a[i]);
        block[b].mn = suf[s], block[b].mx = pre[e];

        for(int i = s - 1; i <= e; i ++)
            for(int j = pre[i]; j < suf[i + 1]; j ++)
                block[b].p[j] = 1;
        
        for(int i = 1; i < MAXN; i ++)  block[b].p[i] += block[b].p[i - 1];
    }

    auto query = [&](int b, int l, int r) -> bool
    {
        if(r < l)   return false;
        return (block[b].p[r] - block[b].p[l - 1]) > 0;
    };

    cin >> q;
    for(int qq = 1; qq <= q; qq ++)
    {
        int l, r;
        cin >> l >> r;
        int B1 = ceil_div(l, R), B2 = ceil_div(r, R);

        bool can = false;
        if(B2 - B1 <= 2)
        {
            pre[l - 1] = 0;
            suf[r + 1] = n + 1;
            
            for(int i = l; i <= r; i ++)    pre[i] = max(pre[i - 1], a[i]);
            for(int i = r; i >= l; i --)    suf[i] = min(suf[i + 1], a[i]);

            for(int i = l; i < r; i ++)
                if(pre[i] < suf[i + 1])
                    can = true;
        }
        else
        {
            int l1 = l, r1 = B1 * R;

            pre[l1 - 1] = 0;
            suf[r1 + 1] = n + 1;

            for(int i = l1; i <= r1; i ++)      pre[i] = max(pre[i - 1], a[i]);
            for(int i = r1; i >= l1; i --)      suf[i] = min(suf[i + 1], a[i]);

            int l2 = (B2 - 1) * R + 1, r2 = min(r, B2 * R);
            
            pre[l2 - 1] = 0;
            suf[r2 + 1] = n + 1;

            for(int i = l2; i <= r2; i ++)      pre[i] = max(pre[i - 1], a[i]);
            for(int i = r2; i >= l2; i --)      suf[i] = min(suf[i + 1], a[i]);

            bpre[B1 - 1] = 0;
            bsuf[B2 + 1] = n + 1;
            bpre[B1] = pre[r1];
            bsuf[B2] = suf[l2];

            for(int i = B1 + 1; i < B2; i ++)   bpre[i] = max(bpre[i - 1], block[i].mx);
            for(int i = B2 - 1; i > B1; i --)   bsuf[i] = min(bsuf[i + 1], block[i].mn);

            bpre[B2] = max(bpre[B2 - 1], pre[r2]);
            bsuf[B1] = min(bsuf[B1 + 1], suf[l1]);

            for(int i = l1; i < r1; i ++)
                if(pre[i] < min(suf[i + 1], bsuf[B1 + 1]))
                    can = true;
            for(int i = r2; i > l2; i --)
                if(suf[i] > max(pre[i - 1], bpre[B2 - 1]))
                    can = true;

            for(int i = B1 + 1; i < B2; i ++)
                if(query(i, bpre[i - 1], bsuf[i + 1] - 1))
                    can = true;
        }

        cout << (can ? "Yes" : "No") << endl;
    }
}





// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.