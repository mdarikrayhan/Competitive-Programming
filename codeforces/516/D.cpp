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
#define ll long long
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

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;             //less_equal for multiset
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
#define hashmap gp_hash_table<int, ll, custom_hash>


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
ll accumulate(const vector<long long> &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

const ll MAXN = 1e5+5, MAXQ = 55;
int n, qq;
map<int, ll> w[MAXN];
vector<pair<int, ll>> adj[MAXN];
int ans[MAXQ];
ll far[MAXN], query[MAXQ];
ll nx[MAXN], bk[MAXN];

vector<int> diameter()
{
    int l, r;
    vector<ll> d(n + 1);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        for(auto v : adj[u])
            if(v.F != p)
                d[v.F] = d[u] + v.S, dfs(v.F, u);
    };
    d[1] = 0;
    dfs(1, 0);
    pair<ll, int> end = mp(-1, -1);
    for(int i = 1; i <= n; i ++)    end = max(end, mp(d[i], i));
    l = end.second;

    d.assign(n + 1, 0);
    dfs(l, 0);
    end = mp(-1, -1);
    for(int i = 1; i <= n; i ++)    end = max(end, mp(d[i], i));
    r = end.second;

    vector<int> path;

    bool found = 0;
    function<void(int, int)> find = [&](int u, int p)
    {
        if(found)   return;
        path.pb(u);
        if(u == r)
        {
            found = 1;
            return;
        }
        for(auto v : adj[u])
            if(v.F != p)
                find(v.F, u);
        if(found)   return;
        path.pop_back();
    };
    find(l, 0);
    return path;
}

//code starts
int32_t main()
{
    fastio();
    cin >> n;
    for(int i = 1, u, v, wg; i < n; i ++)   cin >> u >> v >> wg, adj[u].pb(mp(v, wg)), adj[v].pb(mp(u, wg)), w[u][v] = w[v][u] = wg;

    vector<int> dia = diameter();

    vector<ll> ld(MAXN, 0), rd(MAXN, 0);
    for(int i = 1; i < dia.size(); i ++)    ld[dia[i]] = ld[dia[i - 1]] + w[dia[i]][dia[i - 1]];
    for(int i = dia.size() - 2; i >= 0; i --)   rd[dia[i]] = rd[dia[i + 1]] + w[dia[i]][dia[i + 1]];
    for(int i = 0; i < dia.size(); i ++)    far[dia[i]] = max(ld[dia[i]], rd[dia[i]]);

    int drop = -1;
    for(int i = 0; i < dia.size() - 1 and drop == -1; i ++)    if(far[dia[i]] <= far[dia[i + 1]])   drop = i;
    
    vector<bool> ban(n + 1, 0);
    for(auto d : dia)    ban[d] = 1;

    cin >> qq;
    for(int q = 1; q <= qq; q ++)
    {
        ll l;
        cin >> l;
        query[q] = l;
        ans[q] = 0;
    }

    indexed_set keep[n + 1];
    for(int i = 0; i < dia.size(); i ++)
    {
        int root = dia[i];

        function<void(int, int)> dfs = [&](int u, int p)
        {
            for(auto v : adj[u])
            {
                if(v.F != p and !ban[v.F])
                {
                    far[v.F] = far[u] + v.S;
                    
                    dfs(v.F, u);

                    if((int)keep[u].size() < keep[v.F].size())    swap(keep[u], keep[v.F]);
                    for(auto x : keep[v.F])   keep[u].insert(x);
                }
            }
            keep[u].insert(far[u]);

            for(int q = 1; q <= qq; q ++)
                ans[q] = max(ans[q], (int)keep[u].order_of_key(far[u] + query[q] + 1));
        };
        dfs(root, 0);
    }

    indexed_set all, left, right;
    for(int i = 0; i < dia.size(); i ++)
    {
        for(auto x : keep[dia[i]])
        {
            if(i <= drop)   left.insert(x);
            else    right.insert(x);
            all.insert(x);
        }
    }

    for(int q = 1; q <= qq; q ++)   ans[q] = max(ans[q], (int)all.order_of_key(far[dia[drop]] + query[q] + 1));

    for(int rb = drop; rb >= 0; rb --)
    {
        for(int q = 1; q <= qq; q ++)
            ans[q] = max(ans[q], (int)left.order_of_key(far[dia[rb]] + query[q] + 1));
        for(auto x : keep[dia[rb]])  left.erase(left.find_by_order(left.order_of_key(x)));
    }
    for(int lb = drop + 1; lb < dia.size(); lb ++)
    {
        for(int q = 1; q <= qq; q ++)
            ans[q] = max(ans[q], (int)right.order_of_key(far[dia[lb]] + query[q] + 1));
        for(auto x : keep[dia[lb]])  right.erase(right.find_by_order(right.order_of_key(x)));
    }
    for(int q = 1; q <= qq; q ++)   cout << ans[q] << endl;
}






// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.