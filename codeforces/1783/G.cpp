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

const int MAXN = 2e5+5;

int n, q;
int a[MAXN];
vector<int> adj[MAXN];


template<typename Node>
struct SparseTable
{
    vector<vector<Node>> table;
    vector<int> logValues;

    int n, maxLog;
    vector<int> a;

    SparseTable(int n1, vector<int> &arr)
    {
        n = n1, a = arr, table.resize(n), logValues.resize(n + 1), maxLog = log2(n);
        logValues[1] = 0;

        for(int i = 2; i <= n; i ++)    logValues[i] = logValues[i/2] + 1;
        for(int i = 0; i < n; i ++)
        {
            table[i].resize(maxLog + 1);
            fill(all(table[i]), Node());
        }

        build();
    }

    void build()
    {
        for(int i = 0; i < n; i ++)
            table[i][0] = Node(a[i], i);
        
        for(int i = 1; i <= maxLog; i ++)
            for(int j = 0; (j + (1 << i)) <= n; j ++)
                table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
    }

    Node queryNormal(int left, int right)
    {
        Node ans = Node();
        for(int j = logValues[right - left + 1]; j >= 0; j --)
            if((1 << j) <= right - left + 1)
            {
                ans.merge(ans, table[left][j]);
                left += (1 << j);
            }
        return ans;
    }
    Node queryIdempotent(int left, int right)
    {
        int j = logValues[right - left + 1];
        Node ans = Node();
        ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
        return ans;
    }
};
struct Node1
{
    int val, index;
    Node1()
    {
        val = 1e9;
        index = -1;
    }
    Node1(int v, int ind)
    {
        val = v;
        index = ind;
    }
    void merge(Node1 &l, Node1 &r)
    {
        if(l.val < r.val)
        {
            val = l.val;
            index = l.index;
        }
        else
        {
            val = r.val;
            index = r.index;
        }
    }
};

struct LCA_O_1
{
    int n;
    vector<int> eulerTour, index, node;
    SparseTable<Node1> spt = SparseTable<Node1>(0, eulerTour);
    inline void init(int n1, vector<int> *edges, int root)
    {
        n = n1;
        index.resize(n);
        dfs(root, edges, -1, 0);
        spt = SparseTable<Node1>((int)eulerTour.size(), eulerTour);
    }
    void dfs(int root, vector<int> *edges, int parent, int height)
    {
        eulerTour.pb(height);
        node.pb(root);
        index[root] = (int)eulerTour.size() - 1;
        for(auto i : edges[root])
        {
            if(i != parent)
            {
                dfs(i, edges, root, height + 1);
                eulerTour.pb(height);
                node.pb(root);
            }
        }
    }

    inline int lca(int a, int b)
    {
        return node[spt.queryIdempotent(min(index[a], index[b]), max(index[a], index[b])).index];
    }
    inline int getDepth(int a)
    {
        return eulerTour[index[a]];
    }
    inline bool is_ancestor(int p, int c)
    {
        return (lca(p, c) == p);
    }
    inline int dis(int a, int b)
    {
        return getDepth(a) + getDepth(b) - 2 * getDepth(lca(a, b));
    }
}lca;


struct node
{
    pair<int, int> val = mp(0, 0);
    node() : val(mp(0, 0)) {};
};
struct SegTree
{
    ll N;
    vector<node> st;
    void init(ll n)
    {
        N=n;
        st.resize(4*N+5);
    }
    void merge(node &cur,node &l,node &r) 
    {
        cur.val = max(l.val, r.val);
    }

    node Query(ll ver,ll L,ll R,ll i,ll j)
    {
        if(j<L || i>R)return node();
        if(i<=L && R<=j)return st[ver];
        ll M=(L+R)/2;
        node left=Query(ver*2,L,M,i,j),right=Query(ver*2+1,M+1,R,i,j),cur;
        merge(cur,left,right);
        return cur;
    }	
    void pUpdate(ll ver,ll L,ll R,ll pos,ll val,ll ind)
    {
        if(L==R)
        {
            st[ver].val = mp(val, ind);
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate(ver*2,L,M,pos,val, ind);
        else pUpdate(ver*2+1,M+1,R,pos,val, ind);
        merge(st[ver],st[ver*2],st[ver*2+1]);
    }

    node query(ll l, ll r)
    {
        return Query(1, 1, N, l, r);
    }
    void update(ll pos, ll val, ll ind)
    {
        pUpdate(1, 1, N, pos, val, ind);
    }
}rq;

struct Centroid
{
    int n;              //number of node
 
    // for building
    int root;
    vector<int> sub, par;
    vector<int> dep;
    vector<bool> mark;

    // vector<int> adj[MAXN]        (just keep this outside)
    int id[30][MAXN];
    vector<int> l, r;
    vector<int> cadj[MAXN];
 
    // for query, update... stores subtree answer in most problems
    vector<int> ans;       // ans[u] stores optimal answer (among all paths in orig tree from u to some node in centroid tree) 
 
    // should have lca structure ready
    void init(int x)       //1 indexed
    {
        n = x;
        mark.assign(n + 1, 0), sub.assign(n + 1, 0), par.assign(n + 1, -1);
        dep.assign(n + 1, 0);
        ans.assign(n + 1, inf);
        l.assign(n + 1, 0), r.assign(n + 1, 0);
    }
 
    int find_centroid(int r)
    {
        function<void(int, int)> ss = [&](int u, int p)
        {
            sub[u] = 1;
            for(auto v : adj[u])
                if(v != p and !mark[v])
                    ss(v, u), sub[u] += sub[v];
        };
        ss(r, 0);
 
        int cen = 0, s = sub[r];
        function<void(int, int)> dfs = [&](int u, int p)
        {
            if(cen)    return;
 
            bool now = (sub[r] - sub[u] <= sub[r]/2);
 
            for(auto v : adj[u])
                if(v != p and !mark[v] and cen == 0)
                    now = (now and sub[v] <= sub[r]/2);
            
            if(now)    {cen = u; return;}
 
            for(auto v : adj[u])
                if(v != p and !mark[v] and cen == 0)
                    dfs(v, u);
        };
        dfs(r, 0);
        mark[cen] = 1;
        return cen;
    };
 
    void build()
    {
        int cen = find_centroid(1);     //note
        root = cen;

        vector<int> store[30];
        vector<int> sub[MAXN];

        function<void(int, int)> dfs = [&](int u, int p)
        {
            sub[u].pb(u);
            store[dep[u]].pb(u);
            for(auto v : adj[u])
            {
                if(!mark[v])
                {
                    int cen2 = find_centroid(v);
                    par[cen2] = u;
                    cadj[u].pb(cen2);
                    dep[cen2] = dep[u] + 1;
                    
                    dfs(cen2, u);

                    for(auto x : sub[cen2])
                        sub[u].pb(x);
                }
            }
        };
        dep[root] = 0;
        dfs(root, 0);

        int timer = 0;
        for(int d = 0; d < 30; d ++)
        {
            for(auto u : store[d])
            {
                for(auto v : cadj[u])
                {
                    for(auto x : sub[v])
                        id[d][x] = ++timer;

                    if(!sub[v].empty())
                        l[v] = id[d][sub[v].front()], r[v] = id[d][sub[v].back()];
                }

                cadj[u].pb(u);
                id[d][u] = ++timer;
            }
        }
    }
 
    void update(int u, int x)
    {
        int v = u;
        while(v != -1)
        {
            // update value of ans[u] if required
            rq.update(id[dep[v]][u], x + lca.dis(u, v), u);
            v = par[v];
        }
    }

    pair<int, int> query(int u)        //finding farthest leaf node from leaf node of u
    {
        int v = u, last = u;
        pair<int, int> ans = mp(a[u], u);

        while(v != -1)
        {
            if(v == u)
            {
                if(cadj[u].size() > 1)
                {
                    auto qr = rq.query(l[cadj[u].front()], id[dep[u]][u] - 1).val;
                    ans = max(ans, mp(a[u] + qr.first, qr.second));
                }
            }
            else
            {
                int dis = a[u] + lca.dis(u, v);

                if(last != cadj[v].front())
                {
                    auto qr = rq.query(l[cadj[v].front()], l[last] - 1).val;
                    ans = max(ans, mp(dis + qr.first, qr.second));
                }

                auto qr = rq.query(r[last] + 1, id[dep[v]][v]).val;
                ans = max(ans, mp(dis + qr.first, qr.second));
            }
            last = v;
            v = par[v];
        }
        return ans;
    }
}centroid;

//code starts
int32_t main()
{
    fastio();
    cin >> n;
    for(int i = 1; i <= n; i ++)    cin >> a[i];
    for(int i = 1, u, v; i < n; i ++)   cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    rq.init(17 * MAXN);
    lca.init(n + 1, adj, 1);

    centroid.init(n);
    centroid.build();
    for(int i = 1; i <= n; i ++)    centroid.update(i, a[i]);

    cin >> q;
    while(q --)
    {
        int v, x;
        cin >> v >> x;
        
        a[v] = x;
        centroid.update(v, x);

        auto qr1 = centroid.query(1);
        auto qr2 = centroid.query(qr1.second);

        int d1 = qr1.second, d2 = qr2.second, dia = qr2.first;

        int mx = (a[d1] > a[d2] ? d1 : d2);

        if(2 * a[mx] >= dia)
            cout << a[mx] << endl;
        else
            cout << ceil_div(dia, 2) << endl;
    }
}





// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.