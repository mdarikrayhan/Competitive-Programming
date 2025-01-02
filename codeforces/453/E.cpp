//Never compromise, not even in the face of Armageddon.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

//pragmas
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("01, 02, 03, 0fast, unroll-loops")              //Retard mode
#pragma GCC optimize("Ofast,unroll-loops,omit-frame-pointer,inline")     //Optimization flags
#pragma GCC option("arch=native,tune=native,no-zero-upper")              //Enable AVX

//types
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define TYPE long long int
#define ppair pair<TYPE, TYPE>
#define vecvec(a, i, j, x) vector<vector<TYPE>> a (i, vector<TYPE> (j, x))
#define vecvecvec(a, i, j, k, x) vector<vector<vector<TYPE>>> dp (i + 1, vector<vector<TYPE>>(j + 1, vector<TYPE>(k + 1, x)))

using namespace std;
using namespace __gnu_pbds;

//random stuff
#define all(a) a.begin(),a.end()
#define read(a) for (int i = 1; i < a.size(); i ++) cin >> a[i]
#define endl "\n"
#define pb push_back
#define mp make_pair
#define print(a) for(auto x : a) cout << x << " "; cout << endl
#define sz(x) (long long int)x.size()
#define F first
#define S second
#define sp " " 
const int inf = 0x3f3f3f3f;
const ll INF = 9223372036854775807, MOD = 1e9 + 7;

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
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
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
int ceil_div(int x, int y){return (x + y - 1) / y;}
unsigned long long power(unsigned long long x,ll y, ll p){unsigned long long res = 1;x = x % p; while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
unsigned long long modInverse(unsigned long long n,int p){return power(n, p - 2, p);}
ll nCr(ll n,ll r, ll p){if (n < r)return 0;if (r == 0)return 1;unsigned long long fac[n + 1];fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;}
ll accumulate(const vector<long long int> &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

const int MAXN = 1e5 + 5, T = 1e5, R = 600;

int n, m;
ll si[MAXN], mi[MAXN], ri[MAXN];
vector<int> out[MAXN];

int reset[MAXN];
struct Block
{
    int l = 0, r = 0, reset = 0;
    bool same = false;
};
vector<Block> block(169);

//code starts
int main()
{
    fastio();
    cin >> n;
    for(int i = 1; i <= n; i ++)
    {
        cin >> si[i] >> mi[i] >> ri[i];
        if(mi[i] == 0)  ri[i] = 0;
    }
    ll get[169][MAXN];
    for(int b = 1; b <= ceil_div(n, R); b ++)
    {
        block[b].l = (b - 1) * R + 1, block[b].r = min(n, b * R);
        block[b].reset = 0, block[b].same = true;
        ll sum = 0;

        for(int i = block[b].l; i <= block[b].r; i ++)
            if(ri[i])
                out[ceil_div(mi[i], ri[i])].pb(i), sum += ri[i];

        get[b][0] = 0;
        for(int t = 1; t <= T; t ++)
        {
            for(auto i : out[t])
            {
                get[b][t] += mi[i] - (t - 1) * ri[i];
                sum -= ri[i];
            }
            get[b][t] += get[b][t - 1] + sum;
            out[t].clear();
        }
    }
    for(auto &x : out)  x.clear();

    set<int> first;
    for(int i = 1; i <= n; i ++)    first.insert(i), reset[i] = 0;

    cin >> m;

    while(m --)
    {
        int t, l, r;
        cin >> t >> l >> r;

        ll mana = 0;

        if(ceil_div(l, R) == ceil_div(r, R))
        {
            int b = ceil_div(l, R);

            for(auto it = first.lower_bound(l); it != first.end() and *it <= r; it ++)  out[b].pb(*it);

            if(block[b].same)
                for(int i = block[b].l; i <= block[b].r; i ++)
                    reset[i] = block[b].reset;

            // double
            for(auto i : out[b])
            {
                first.erase(i);
                mana += min(mi[i], si[i] + t * ri[i]) - min(mi[i], t * ri[i]);
            }
            out[b].clear();

            for(int i = l; i <= r; i ++)
                mana += min(mi[i], (t - reset[i]) * ri[i]), reset[i] = t;

            block[b].same = (l == block[b].l and r == block[b].r);
            block[b].reset = t;
        }
        else
        {
            int bl = ceil_div(l, R), br = ceil_div(r, R);

            for(auto it = first.lower_bound(l); it != first.end() and *it <= r; it ++) out[ceil_div(*it, R)].pb(*it);
            // l
            if(block[bl].same)
                for(int i = block[bl].l; i <= block[bl].r; i ++)
                    reset[i] = block[bl].reset;
            
            // remove double
            for(auto i : out[bl])
            {
                first.erase(i);
                mana += min(mi[i], t * ri[i] + si[i]) - min(mi[i], t * ri[i]);
            }
            out[bl].clear();

            for(int i = l; i <= block[bl].r; i ++)
                mana += min(mi[i], (t - reset[i]) * ri[i]), reset[i] = t;
            
            block[bl].same = (l == block[bl].l and r >= block[br].r);
            block[bl].reset = t;

            // r
            if(block[br].same)
                for(int i = block[br].l; i <= block[br].r; i ++)
                    reset[i] = block[br].reset;

            // remove double 
            for(auto i : out[br])
            {
                first.erase(i);
                mana += min(mi[i], t * ri[i] + si[i]) - min(mi[i], t * ri[i]);
            }
            out[br].clear();

            for(int i = block[br].l; i <= r; i ++)  
                mana += min(mi[i], (t - reset[i]) * ri[i]), reset[i] = t;

            block[br].same = (l <= block[br].l and r == block[br].r);
            block[br].reset = t;


            for(int b = bl + 1; b < br; b ++)
            {
                if(block[b].same)
                {
                    for(auto i : out[b])
                    {
                        first.erase(i);
                        mana += min(mi[i], t * ri[i] + si[i]) - min(mi[i], t * ri[i]);
                    }
                    out[b].clear();

                    mana += get[b][min(T, t - block[b].reset)], block[b].reset = t;
                    continue;
                }

                // remove double
                for(auto i : out[b])
                {
                    first.erase(i);
                    mana += min(mi[i], t * ri[i] + si[i]) - min(mi[i], t * ri[i]);
                }
                out[b].clear();

                for(int i = block[b].l; i <= block[b].r; i ++)
                    mana += min(mi[i], (t - reset[i]) * ri[i]);
                
                block[b].same = true, block[b].reset = t;
            }
        }
        cout << mana << endl;
    }
}






// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.