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

const int MAXN = 2e5+5, P = 31, Z = 4.5e5+5;

struct Mint {
    int val;
 
    Mint(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;
        if (v >= MOD)
            v %= MOD;
        val = v;
    }
 
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        } 
        return x < 0 ? x + m : x;
    } 
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
           #if !defined(_WIN32) || defined(_WIN64)
                return x % m;
           #endif
           unsigned x_high = x >> 32, x_low = (unsigned) x;
           unsigned quot, rem;
           asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
           return rem;
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint power(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator << (ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream>>m.val;   
    }
};
Mint ans = 1;

struct FenwickTreeOneBasedIndexing 
{
    vector<int> bit;
    int n;

    FenwickTreeOneBasedIndexing(int n) 
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    // mode 1
    int sum(int idx) 
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret = (ret + bit[idx]) % MOD;
        return ret;
    }

    int sum(int l, int r) 
    {
        return mod_sub(sum(r), sum(l - 1));
    }

    void add(int idx, Mint delta) 
    {
        int del = (int)delta;
        for (++idx; idx < n; idx += idx & -idx) bit[idx] = (bit[idx] + del) % MOD;
    }
};


int n, m, D;
bool done = 0;
vector<Mint> qans;
vector<int> tin(MAXN), tout(MAXN), l(MAXN), r(MAXN), dep(MAXN), adj[MAXN];

Mint __pw[(int)2e6];

Mint &pw(int i)
{
    return __pw[Z + i];
}

void pre()
{
    Mint score = 1;

    for(int i = 0; i < 2*MAXN; i ++)
        pw(-i) = score, score /= P;
    
    
    score = 1;

    for(int i = 0; i < 2*MAXN; i ++)
        pw(i) = score, score *= P;
}

template<typename Node>
struct SparseTable {
    vector<vector<Node>> table;
    vector<int> logValues;
    int n;
    int maxLog;
    vector<int> a;
    SparseTable(int n1, vector<int> &arr) {
        n = n1;
        a = arr;
        table.resize(n);
        logValues.resize(n + 1);
        maxLog = log2(n);
        logValues[1] = 0;
        for (int i = 2; i <= n; i++) {
            logValues[i] = logValues[i / 2] + 1;
        }
        for (int i = 0; i < n; i++) {
            table[i].resize(maxLog + 1);
            fill(all(table[i]), Node());
        }
        build();
    }
    void build() {
        for (int i = 0; i < n; i++) {
            table[i][0] = Node(a[i], i);
        }
        for (int i = 1; i <= maxLog; i++) {
            for (int j = 0; (j + (1 << i)) <= n; j++) {
                table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
    Node queryNormal(int left, int right) {
        Node ans = Node();
        for (int j = logValues[right - left + 1]; j >= 0; j--) {
            if ((1 << j) <= right - left + 1) {
                ans.merge(ans, table[left][j]);
                left += (1 << j);
            }
        }
        return ans;
    }
    Node queryIdempotent(int left, int right) {
        int j = logValues[right - left + 1];
        Node ans = Node();
        ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
        return ans;
    }
};
struct Node1 {
    int val; // store more info if required
    int index;
    Node1() { // Identity Element
        val = 1e9;
        index = -1;
    }
    Node1(int v, int ind) {
        val = v;
        index = ind;
    }
    void merge(Node1 &l, Node1 &r) {
        if(l.val < r.val){
            val = l.val;
            index = l.index;
        }else{
            val = r.val;
            index = r.index;
        }
    }
};
struct LCA_O_1{
    int n, L;
    vector<int> eulerTour, index;
    vector<int> node;
    vector<vector<int>> up;
    SparseTable<Node1> SP = SparseTable<Node1>(0, eulerTour);
    void init(int n1, vector<int>* edges, int root){
        n = n1;
        L = ceil(log2(n));
        up.assign(n + 1, vector<int>(L + 1));
        index.resize(n);
        dfs(root, edges, 0, 0);
        SP = SparseTable<Node1>(sz(eulerTour), eulerTour);
    }
    void dfs(int root, vector<int>* edges, int parent, int height){
        eulerTour.pb(height);
        node.pb(root);
        index[root] = sz(eulerTour) - 1;

        up[root][0] = parent;
        for (int i = 1; i <= L; ++i)
            up[root][i] = up[up[root][i-1]][i-1];
        
        for(auto i : edges[root]){
            if(i != parent){
                dfs(i, edges, root, height + 1);
                eulerTour.pb(height);
                node.pb(root);
            }
        }
    }
    inline int query(int a, int b){
        return node[SP.queryIdempotent(min(index[a], index[b]), max(index[a], index[b])).index];
    }
    inline int getDepth(int a){
        return eulerTour[index[a]];
    }
    inline int dis(int a, int b){
        return dep[a] + dep[b] - (dep[query(a, b)] * 2);
    }

    inline int anc(int v, int k)
    {
        if(k == 0)  return v;
        else
        {
            for(int i = L; i >= 0; i --)
            {
                if(v == 0) break;

                if((1 << i) <= k)
                {
                    k -= (1 << i);
                    v = up[v][i];
                }
            }
        }
        return v;
    }
}lca;

struct DSU
{
    vector<int> par;
    vector<Mint> val;
    vector<vector<int>> keep;
    vector<int> mx_l, mn_r;
    void init(int n)
    {
        par.resize(n + 1);
        keep.resize(n + 1);
        val.resize(n + 1);
        mx_l.resize(n + 1);
        mn_r.resize(n + 1);
        for(int i = 1; i <= n; i ++)    par[i] = i, mx_l[i] = l[i], mn_r[i] = r[i], val[i] = r[i] - l[i] + 1, keep[i].pb(i);
    }
    
    int get(int x)  {return par[x];}

    void unite(int x, int y, FenwickTreeOneBasedIndexing &up, FenwickTreeOneBasedIndexing &dn)
    {
        x = get(x), y = get(y);

        if(x == y)  return;

        // fix answer
        ans /= (mn_r[x] - mx_l[x] + 1);
        
        if(ans == 0)    return;

        ans /= (mn_r[y] - mx_l[y] + 1);

        int l_now = max(mx_l[x], mx_l[y]), r_now = min(mn_r[x], mn_r[y]);

        if(ans == 0 or l_now > r_now)
        {
            done = 1;
            ans = 0;
            return;
        }

        mx_l[x] = mx_l[y] = l_now;
        mn_r[x] = mn_r[y] = r_now;
        ans *= (r_now - l_now + 1);

        int set;
        if(sz(keep[x]) > sz(keep[y]))
        {
            set = x;

            while(!keep[y].empty())
            {
                int b = keep[y].back();
                Mint val1 = (- y + x) * pw(D - dep[b]), val2 = (- y + x) * pw(dep[b]);

                up.add(tin[b], -val1);
                dn.add(tin[b], val2);

                up.add(tout[b], val1);
                dn.add(tout[b], -val2);

                par[b] = x, keep[x].pb(b), keep[y].pop_back();
            }
        }
        else
        {
            set = y;
            while(!keep[x].empty())
            {
                int b = keep[x].back();

                Mint val1 = (- x + y) * pw(D - dep[b]), val2 = (- x + y) * pw(dep[b]);

                up.add(tin[b], -val1);
                dn.add(tin[b], val2);

                up.add(tout[b], val1);
                dn.add(tout[b], -val2);

                par[b] = y, keep[y].pb(b), keep[x].pop_back();
            }
        }
    }
}dsu;

int path_hash (int a, int b, int l, int dis, FenwickTreeOneBasedIndexing &up, FenwickTreeOneBasedIndexing &dn)            // a to b, at "dis" distance from a, whats the prefix hash
{
    int upward = min(dis, dep[a] - dep[l]), dnward = max(0, dis - (dep[a] - dep[l]));

    int f = lca.anc(a, upward);

    Mint ans = 0;

    ans += up.sum(tout[a], tout[f]) * pw(-(D - dep[a]));

    if(dnward > 0)
    {
        f = lca.anc(b, (dep[b] - dep[l]) - dnward);

        Mint here = dn.sum(tin[l] + 1, tin[f]);

        here *= pw(-(dep[l] + 1) + (dep[a] - dep[l] + 1));
        
        ans += here;         //dont want to include lca here
    }

    return (int)ans;
}
int get(int a, int b, int l, int dis)
{
    int upward = dep[a] - dep[l];

    if(dis <= upward)
        return lca.anc(a, dis);

    return lca.anc(b, (dep[b] - dep[l]) - (dis - (dep[a] - dep[l])));
}

//code starts
int32_t main()
{
    fastio();
    pre();
    cin >> n;

    for(int i = 2, p; i <= n; i ++) cin >> p, adj[p].pb(i);
    for(int i = 1; i <= n; i ++)    cin >> l[i] >> r[i], ans *= (r[i] - l[i] + 1);

    int timer = 0;
    function<void(int)> dfs = [&](int u)
    {
        D = max(D, dep[u]);
        tin[u] = ++timer;
        for(auto v : adj[u])
            dep[v] = dep[u] + 1, dfs(v);
        tout[u] = ++timer;
    };
    D = dep[1] = 0;
    dfs(1);

    FenwickTreeOneBasedIndexing up(2*MAXN+5), dn(2*MAXN+5);

    for(int u = 1; u <= n; u ++)
    {
        Mint val1 = u * pw(D - dep[u]), val2 = u * pw(dep[u]);

        up.add(tin[u], -val1);
        dn.add(tin[u], val2);

        up.add(tout[u], val1);
        dn.add(tout[u], -val2);
    }

    lca.init(n + 1, adj, 1);
    dsu.init(n + 1);


    cin >> m;
    for(int i = 1, a, b, c, d; i <= m; i ++)
    {
        cin >> a >> b >> c >> d;

        int l1 = lca.query(a, b), l2 = lca.query(c, d), dis = lca.dis(a, b);

        while(!done and path_hash(a, b, l1, dis, up, dn) != path_hash(c, d, l2, dis, up, dn))
        {
            int s = 0, e = dis, fix = -1;

            while(s <= e)
            {
                int mid = (s + e) >> 1;
                if(path_hash(a, b, l1, mid, up, dn) == path_hash(c, d, l2, mid, up, dn))    s = mid + 1, fix = mid;
                else    e = mid - 1;
            }

            ++ fix;
            // now, at fix distance, we have to unite the two nodes
            int u = get(a, b, l1, fix), v = get(c, d, l2, fix);
            dsu.unite(u, v, up, dn);
        }
        if((int)ans == 0)   break;

        qans.pb(ans);
    }
    while((int)qans.size() < m) qans.pb((Mint)0);

    for(auto ans : qans)  cout << ans << endl;
}






// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.