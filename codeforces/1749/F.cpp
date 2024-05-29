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
#define vecvecvec(a, i, j, k, x) vector<vector<vector<TYPE>>> dp (i + 1, vector<vector<TYPE>>(j + 1, vector<TYPE>(k + 1, x)))

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

const int MAXN = 2e5+25, MAXD = 22;

int n, q;
int timer = 0;
vector<int> adj[MAXN];

#define int int64_t

vector<bool> heavy(MAXN, 0);
vector<int> sub(MAXN, 0), par(MAXN, 0), head(MAXN, 0), sid(MAXN, 0);
vector<vector<int>> val(MAXN, vector<int> (MAXD, 0)), edge(MAXN, vector<int> (MAXD, 0));

struct FenwickTreeOneBasedIndexing 
{
    vector<int> A, B1, B2;
    int n;

    void init(int n) 
    {
        this->n = n + 10;
        A.assign(n + 10, 0), B1.assign(n + 10, 0), B2.assign(n + 10, 0);
    }

    void upd(vector<int> &B, int x, int v) 
    {
        for(int i = x ; i <= n ; i += (i & (-i))) B[i] += v;
    }

    int sum(vector<int> &B, int x) 
    {
        int ans = 0;
        for(int i = x ; i > 0 ; i -= (i & (-i))) ans += B[i];
        return ans;
    }
    void update(int l, int r, int v) 
    {
        upd(B1, r + 1, -v); upd(B1, l, v);
        upd(B2, r + 1, -(r + 1) * v); upd(B2, l, l * v);
    }

    int query(int l, int r) 
    {
        return ((r + 1) * sum(B1, r) - sum(B2, r)) - (l * sum(B1, l - 1) - sum(B2, l - 1));
    }
};

struct LCA
{
    int n, L, timer;

    // vector<int> adj[MAXN];       //just keep this outside

    vector<int> tin, tout;
    vector<vector<int>> up;         //up[v][i] stores (2^i) ancestor of v

    // w[] is basically "cost"

    void init(int x)
    {
        n = x;
        L = ceil(log2(n));
        tin.resize(n + 1, 0), tout.resize(n + 1, 0);
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
                dfs(u, v);

        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    void preprocess(int root) 
    {
        timer = 0;
        dfs(root, root);
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

struct HLD
{
    int n;

    // vector<int> adj[MAXN];           //-> just keep this outside
    // vector<int> sub, par;

    // for light nodes
    vector<int> val;       //value of the light node

    // for heavy paths
    // vector<bool> heavy;
    // vector<int> head, sid;      //head of heavy path, segment tree index
    FenwickTreeOneBasedIndexing fen;

    void init(int N)
    {
        n = N;
        val.assign(MAXN, 0);
        fen.init(n);
        val.assign(n + 5, 0);
    }
    
    
    // have lca structure and (range query-range update structure) ready before calling update and query
    void update(int u, int v, int x)
    {
        int l = lca.lca(u, v);
        vector<int> b = {u, v};

        for(auto w : b)
        {
            while(w != par[l])
            {
                if(heavy[w])
                {
                    if(lca.is_ancestor(head[w], l)) 
                        fen.update(sid[l], sid[w], x), w = par[l];
                    else    
                        fen.update(sid[head[w]], sid[w], x), w = par[head[w]];
                }
                else
                {
                    val[w] += x;
                    w = par[w];
                }
            }
        }    

        // l recieved update twice, fix
        if(heavy[l])
            fen.update(sid[l], sid[l], -x);
        else
            val[l] -= x;
    }

    int query(int u, int v)
    {
        int l = lca.lca(u, v);
        vector<int> b = {u, v};

        int ans = 0;
        for(auto w : b)
        {
            while(w != par[l])
            {
                if(heavy[w])
                {
                    if(lca.is_ancestor(head[w], l))
                        ans += fen.query(sid[l], sid[w]), w = par[l];
                    else
                        ans += fen.query(sid[head[w]], sid[w]), w = par[head[w]];
                }
                else
                {
                    ans += val[w];
                    w = par[w];
                }
            }
        }

        if(heavy[l])
            ans -= fen.query(sid[l], sid[l]);
        else
            ans -= val[l];

        return ans;
    }
}hld[MAXD];


void hld_build(int root)
{
    function<void(int)> structure = [&](int u)
    {
        sub[u] = 1;

        pair<int, int> heavy_child = mp(0, -1);
        
        for(auto v : adj[u])
            if(v != par[u])
                par[v] = u, structure(v), sub[u] += sub[v], heavy_child = max(heavy_child, mp(sub[v], (int64_t)v));
        
        if(heavy_child.second != -1)    heavy[heavy_child.second] = 1;
    };
    structure(root);

    function<void(int, int)> decompose = [&](int u, int h)
    {
        pair<int, int> heavy_child = mp(0, -1);

        head[u] = h, sid[u] = ++ timer;
        for(auto v : adj[u])    
            if(v != par[u]) 
                heavy_child = max(heavy_child, mp(sub[v], (int64_t)v));

        if(heavy_child.second != -1)    decompose(heavy_child.second, h);
    };
    for(int h = 1; h <= n; h ++)    
        if(heavy[h] and !heavy[par[h]])
            decompose(h, h);
}

//code starts
int32_t main()
{
    fastio();
    cin >> n;
    for(int i = 1, u, v; i < n; i ++)   cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    lca.init(n);
    lca.preprocess(1);

    hld_build(1);

    for(int d = 0; d <= 20; d ++)   hld[d].init(n);

    // chain above
    for(int i = n + 2; i <= n + 20; i ++)
        adj[i].pb(i - 1), adj[i - 1].pb(i);
    adj[1].pb(n + 1), adj[n + 1].pb(1);

    vector<int> p(MAXN);
    function<void(int)> dfs = [&](int u)
    {
        for(auto v : adj[u])
            if(v != p[u])
                p[v] = u, dfs(v);
    };
    int root = n + 20;
    dfs(root);

    cin >> q;

    for(int i = 1, t, u, v, k, d; i <= q; i ++)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> v;

            int ans = 0;

            for(int d = 0; d <= 20; d ++)
            {
                ans += val[v][d] + val[v][d + 1];
                ans += hld[d].query(v, v);
                ans += edge[v][d];
                v = p[v];
            }
            cout << ans << endl;
        }
        else
        {
            int u, v, k, d;
            cin >> u >> v >> k >> d;

            hld[d].update(u, v, k);
            
            int l = lca.lca(u, v);
            
            if(d != 0)  edge[l][d - 1] += k;
            -- d;
            for(; d >= 0;)
            {
                l = p[l];
                val[l][d] += k;
                -- d;
            }
        }
    }

    
}



// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.