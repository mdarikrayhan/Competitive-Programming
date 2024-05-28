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
#define vecvec(a, i, j, x) vector<vector<TYPE>> a (i, vector<TYPE> (j, x))
#define vecvecvec(a, i, j, k, x) vector<vector<vector<TYPE>>> a (i + 1, vector<vector<TYPE>>(j + 1, vector<TYPE>(k + 1, x)))

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

const int MAXN = 2e5+5;

int n, m;
vector<int> p(MAXN);
map<pair<int, int>, int> swp;

vector<int> par(MAXN), tin(MAXN), tout(MAXN);
vector<bool> vis(MAXN);
vector<int> adj[MAXN];
set<pair<int, int>> child[MAXN];        //{tin_i, i}

bool is_true_ancestor(int p, int v)
{
    return (tin[p] <= tin[v] and tout[v] <= tout[p]);
}
bool is_ancestor(int p, int v)
{
    return ((tout[p] < tin[v]) or (tout[v] < tin[p]) or (tin[p] < tin[v] and tout[v] < tout[p]));
}

//code starts
int32_t main()
{
    fastio();
    cin >> n >> m;

    for(int i = 1; i <= n; i ++)    cin >> p[i];
    for(int i = 1, x, y; i <= m; i ++)  cin >> x >> y, adj[x].pb(y), adj[y].pb(x), swp[mp(x, y)] = swp[mp(y, x)] = i;

    vector<int> order;

    for(int r = 1; r <= n; r ++)    if(!vis[r])
    {
        function<void(int)> mark = [&](int u)
        {
            vis[u] = true;
            for(auto v : adj[u])
                if(!vis[v])
                    mark(v);
        };
        mark(r);

        set<pair<int, int>> ready;
        auto now = [&](int u, int v) -> bool
        {
            if(u == v)  return false;

            if(is_true_ancestor(v, p[u]) and is_ancestor(p[v], v))
            {
                ready.insert(mp(u, v));
                return true;
            }
            return false;
        };

        int timer = 0;
        function<void(int)> build = [&](int u)
        {
            tin[u] = ++timer;
            
            for(auto v : adj[u])
                if(v != par[u])
                    par[v] = u, build(v);

            tout[u] = ++timer;

            for(auto v : adj[u])
                if(v != par[u])
                    child[u].insert(mp(tin[v], v));
        };
        par[r] = 0;
        build(r);

        function<void(int)> get = [&](int u)
        {
            for(auto v : adj[u])
                if(v != par[u])
                    get(v);
            
            if(is_true_ancestor(u, p[u]))
            {
                auto it = child[u].upper_bound(mp(tin[p[u]], inf));
                if(it != child[u].begin())
                {
                    -- it;
                    int v = (*it).second;
                    now(u, v);
                }
            }
        };
        get(r);

        while(!ready.empty())
        {
            auto c = *ready.begin();

            bool cur = (c == mp(4, 13));

            ready.erase(c);
            order.pb(swp[c]);

            int u = c.first, v = c.second;
            if(u != par[v])   swap(u, v);

            swap(p[u], p[v]);

            if(u != p[u])
                if(par[u] != 0)
                    now(par[u], u);
            
            if(u != p[u])
            {
                auto it = child[u].upper_bound(mp(tin[p[u]], inf));
                if(it != child[u].begin())
                {
                    -- it;
                    int v = (*it).second;
                    now(u, v);
                }
            }
            
            if(v != p[v])
            {
                auto it = child[v].upper_bound(mp(tin[p[v]], inf));
                if(it != child[v].begin())
                {
                    -- it;
                    int cv = (*it).second;
                    now(v, cv);
                }
            }
        }
    }

    for(auto i : order) cout << i << sp;
    cout << endl;
}





// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.