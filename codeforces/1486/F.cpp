//Never compromise, not even in the face of Armageddon.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

//pragmas
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("01, 02, 03, 0fast, unroll-loops")              //Retard mode
//#pragma GCC optimize("Ofast,unroll-loops,omit-frame-pointer,inline")     //Optimization flags
//#pragma GCC option("arch=native,tune=native,no-zero-upper")              //Enable AVX

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
ll ceil_div(ll x, ll y){return (x + y - 1) / y;}
unsigned long long power(unsigned long long x,ll y, ll p){unsigned long long res = 1;x = x % p; while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
unsigned long long modInverse(unsigned long long n,int p){return power(n, p - 2, p);}
ll nCr(ll n,ll r, ll p){if (n < r)return 0;if (r == 0)return 1;unsigned long long fac[n + 1];fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;}
ll accumulate(const vector<long long int> &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

const ll MAXN = 3e5+5;
int n, m;
set<int> ep[MAXN];
vector<pair<int, int>> path;
vector<ll> point(MAXN, 0);
vector<int> x(MAXN, 0), y(MAXN, 0);
vector<int> adj[MAXN], high[MAXN];


struct LCA
{
    int n, L, timer;

    // vector<int> adj[MAXN];       //just keep this outside

    vector<int> tin, tout;
    vector<int> dep;
    vector<vector<int>> up;         //up[v][i] stores (2^i) ancestor of v

    void init(int x)
    {
        n = x;
        L = ceil(log2(n));
        tin.resize(n + 1, 0), tout.resize(n + 1, 0);
        dep.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(L + 1));
    }

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
 
        up[v][0] = p;
 
        for (int i = 1; i <= L; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
 
        for (int u : adj[v])
            if (u != p)
                dep[u] = dep[v] + 1, dfs(u, v);

        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    void preprocess(int root) 
    {
        timer = 0;
        dep[root] = 0;
        dfs(root, root);
    }

    ll get(int v, int k)            //get kth ancestor of v
    {
        if(k == 0)  return v;

        for(int i = L; i >= 0; i --)
        {
            if(v == 0) break;

            if((1 << i) <= k)
            {
                k -= (1 << i);
                v = up[v][i];
            }
        }
        // now v is the kth parent, and sum stores the path required path aggregate
        return v;
    }

    ll get2(int v, int a)           //given that a is ancestor of v, find which ancestor it is/anc just below it
    {
        if(a == v)  return v;

        int dis = 0;

        for(int i = L; i >= 0; i --)
        {
            if(dep[v] - (1 << i) > dep[a] and  !is_ancestor(up[v][i], a))
            {
                v = up[v][i];
                dis += (1 << i);
            }
        }
        return v;
    }

    int lca(int u, int v)           //lca of u and v
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
 
        for (int i = L; i >= 0; --i) 
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
 
        return up[u][0];
    }
}lca;

//code starts
int main()
{
    fastio();
    cin >> n;
    for(int i = 1, u, v; i < n; i ++)   cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    lca.init(n);
    lca.preprocess(1);


    cin >> m;
    for(int i = 0, u, v; i < m; i ++)
    {
        cin >> u >> v;
        
        
        if(u == v)  ++ point[u];
        else
        {
            path.pb(mp(u, v));
            int l = lca.lca(u, v);
            high[l].pb(i), ep[u].insert(i), ep[v].insert(i);
            x[i] = u, y[i] = v;
            if(x[i] != l)   x[i] = lca.get2(x[i], l);
            if(y[i] != l)   y[i] = lca.get2(y[i], l);
        }
    }

    ll ans = 0;

    vector<int> cnt(n + 1, 0);      //used in the type 2. situation
    vector<int> nbcnt(n + 1, 0), bcnt(n + 1, 0);        //used in the nobend and nobend situation resp

    function<void(int, int)> dfs = [&](int u, int p)
    {
        for(auto v : adj[u])
            if(v != p)
                dfs(v, u);
        for(auto h : high[u])   ep[u].erase(h);
        ll old = (int)ep[u].size();

        {
            ans += (ll)high[u].size() * old;
            ans += point[u] * old;
        }
        {
            for(auto v : adj[u])    
            {
                if(v != p)
                {
                    cnt[v] = (int)ep[v].size();
                    if((int)ep[v].size() > (int)ep[u].size())   swap(ep[u], ep[v]);
                    for(auto x : ep[v]) ep[u].insert(x);
                }
            }
            for(auto h : high[u])
            {
                ep[u].erase(h);
                if(x[h] != u)   -- cnt[x[h]];
                if(y[h] != u)   -- cnt[y[h]];
            }

            ll total = (int)ep[u].size() - old;

            for(auto h : high[u])
            {
                ans += total;
                if(x[h] != u)  ans -= cnt[x[h]];
                if(y[h] != u)  ans -= cnt[y[h]];
            }
            ans += point[u] * total;
        }
        {
            map<pair<int, int>, int> db;

            // seperate this shite into bend paths and no bend paths
            vector<int> bend, nobend;
            for(auto h : high[u])
            {
                if(x[h] == u or y[h] == u)
                {
                    nobend.pb(h);
                    if(x[h] != u)   ++ nbcnt[x[h]];
                    else    ++ nbcnt[y[h]];
                }
                else
                {
                    bend.pb(h);
                    ++ bcnt[x[h]], ++ bcnt[y[h]];
                    ++ db[mp(min(x[h], y[h]), max(x[h], y[h]))];
                }
            }
            // nb with nb
            {
                ll total = (int)nobend.size(), here = 0;
                for(auto v : adj[u])
                    if(v != p)
                        here += (total - nbcnt[v]) * nbcnt[v];
                ans += here/2; 
            }
            
            // nb with b
            {
                ll total = (int)bend.size(), here = 0;
                for(auto v : adj[u])
                    if(v != p)
                        here += nbcnt[v] * (total - bcnt[v]);
                ans += here;
            }
            // b with b
            {
                ll total = (int)bend.size(), here = 0;
                for(auto b : bend)  here += total - (bcnt[x[b]] + bcnt[y[b]] - db[mp(min(x[b], y[b]), max(x[b], y[b]))]);
                ans += here/2;
            }

            ans += point[u] * ((ll)nobend.size());
            ans += point[u] * ((ll)bend.size());
        }
        {
            ans += ((point[u]) * (point[u] - 1))/2;
        }
    };
    dfs(1, 0);

    cout << ans << endl;
}


/*
ok, so let us root the tree at 1.

Now consider when two paths intersect at only one point. It HAS to be highest point in path for atleast one of the two paths.

Now let's say we are at some node v. How to get the number of intersecting paths?

Consider set of paths which have v as highest point S.

Let cross[c] be number of paths which come through child c, double[c1][c2] be number going through both of them

so for ith path in S, first remove its contribution from all cross and double, number of paths it intersects with at only one point will basically be 

all the rest - (number it intersects with at > 1 point)
all the rest - (cross[c1 for path i] + cross[c2 for path i] - double[c1][c2])

for convenience, calculate both seperately alright yeah, so we have 3 kinds of paths at each v

1) paths which have v as their highest point
2) paths which go up 
*/



// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.