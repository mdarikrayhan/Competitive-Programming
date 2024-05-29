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

#define int ll

struct FenwickTreeOneBasedIndexing 
{
    vector<int> bit;
    int n;

    void init(int n) 
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    
    int sum(int idx) 
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) 
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) 
    {
        for (++idx; idx < n; idx += idx & -idx) bit[idx] += delta;
    }
}fen;


template<typename Node>
struct SparseTable 
{
	vector<vector<Node>> table;
	int n;
	int maxLog;
	vector<ll> a;
	SparseTable(int n1, vector<int> &arr) 
    {
		n = n1;
		a = arr;
		table.resize(n);
		maxLog = log2_floor(n);
		for (int i = 0; i < n; i++) 
        {
			table[i].resize(maxLog + 1);
			fill(all(table[i]), Node());
		}
		build();
	}
	void build() 
    {
		for (int i = 0; i < n; i++) table[i][0] = Node(a[i]);

		for (int i = 1; i <= maxLog; i++) 
			for (int j = 0; (j + (1 << i)) <= n; j++)
				table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
	}
	Node queryNormal(int left, int right) 
    {
		Node ans = Node();
		for (int j = log2_floor(right - left + 1); j >= 0; j--) 
        {
			if ((1 << j) <= right - left + 1) 
            {
				ans.merge(ans, table[left][j]);
				left += (1 << j);
			}
		}
		return ans;
	}
	Node queryIdempotent(int left, int right) 
    {
		int j = log2_floor(right - left + 1);
		Node ans = Node();
		ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
		return ans;
	}
};
struct Node1 {
	ll mn; // store more info if required
	Node1() 
    { // Identity Element
		mn = 0;
	}
	Node1(ll v) 
    {
		mn = v;
	}
	void merge(Node1 &l, Node1 &r) 
    {
		mn = min(l.mn, r.mn);
	}
};

const int MAXN = 4e5+25;
int n, q, k;
vector<int> a(MAXN);
vector<int> adj[MAXN];
vector<array<int, 3>> qr[MAXN];
vector<int> ans(MAXN), p(MAXN), block(MAXN, 0), val(MAXN, 0);


vector<int> tin, tout;
struct LCA
{
    int n, L, timer;

    // vector<int> adj[MAXN];       //just keep this outside

    vector<vector<int>> up;         //up[v][i] stores (2^i) ancestor of v

    // w[] is basically "cost" for a node

    void init(int x)
    {
        n = x;
        L = ceil(log2(n));
        tin.resize(n + 1, 0), tout.resize(n + 1, 0);
        up.assign(n + 1, vector<int>(L + 1, n + 1));
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

    ll get(int v, int x)       //get highest ancestor which is < x
    {
        for(int i = L; i >= 0; i --)
            if(up[v][i] <= x)
                v = up[v][i];
        return v;
    }
}lca;

//code starts
int32_t main()
{
    fastio();

    cin >> n >> q >> k;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    for(int i = 1, l, r; i <= q; i ++)  cin >> l >> r, qr[l % k].pb({l, r, i});

    a[n + 1] = 0;
    SparseTable<Node1> rq(n + 10, a);
    rq.build();

    for(int i = 1; i <= n; i ++)
    {
        int s = i, e = n + 1, ans = i;
        while(s <= e)
        {
            int mid = (s + e) >> 1;
            if(rq.queryIdempotent(i, mid).mn < a[i])    e = mid - 1, ans = mid;
            else    s = mid + 1;
        }
        
        p[i] = ans;
        adj[p[i]].pb(i);
    }

    lca.init(n + 1);
    lca.preprocess(n + 1);

    fen.init(3*MAXN);

    for(int i = 1; i <= n; i ++)    block[i] = ceil_div(i, k);
    
    auto put = [&](int i, int x)
    {
        fen.add(tin[i], +x), fen.add(tout[i] + 1, -x);
    };

    for(int i = 1; i <= n; i ++)
    {
        val[i] = a[i] * (block[p[i]] - block[i] - (p[i] % k == 1) + (i % k == 1));
        if(p[i] == n + 1)   val[i] = 0;
        put(i, val[i]);
    }

    for(int m = 1; m < k; m ++)
    {
        // queries
        for(auto q : qr[m])
        {
            int l = q[0], r = q[1], i = q[2];

            if(block[l] == block[r])
            {
                ans[i] += a[l];
                continue;
            }

            int w = lca.get(l, r);

            if(w % k == m)
                ans[i] += (fen.sum(1, tin[l]) - fen.sum(1, tin[w])) + a[w] * (block[r] - block[w] + 1);
            else
                ans[i] += (fen.sum(1, tin[l]) - fen.sum(1, tin[w])) + a[w] * (block[r] - block[w]);
        }

        // updates
        for(int i = m; i <= n; i += k)
        {
            put(i, -val[i]);
            -- block[i];
            
            val[i] = a[i] * (block[p[i]] - block[i] - (p[i] % k == (m + 1) % k) + (i % k == (m + 1) % k));
            if(p[i] == n + 1)   val[i] = 0;

            put(i, val[i]);
            for(auto j : adj[i])
            {
                put(j, -val[j]);

                val[j] = a[j] * (block[i] - block[j] - (p[j] % k == (m + 1) % k) + (j % k == (m + 1) % k));
                if(p[j] == n + 1)   val[j] = 0;

                put(j, val[j]);                    
            }
        }

        for(int i = m + 1; i <= n; i += k)
        {
            put(i, -val[i]);
            val[i] = a[i] * (block[p[i]] - block[i] - (p[i] % k == (m + 1) % k) + (i % k == (m + 1) % k));
            if(p[i] == n + 1)   val[i] = 0;
            put(i, val[i]);

            for(auto j : adj[i])
            {
                put(j, -val[j]);

                val[j] = a[j] * (block[i] - block[j] - (p[j] % k == (m + 1) % k) + (j % k == (m + 1) % k));
                if(p[j] == n + 1)   val[j] = 0;

                put(j, val[j]);
            }
        }
    }
    
    int m = 0;
    for(auto q : qr[m])
        {
            int l = q[0], r = q[1], i = q[2];

            if(block[l] == block[r])
            {
                ans[i] += a[l];
                continue;
            }

            int w = lca.get(l, r);

            if(w % k == m)      //front element
                ans[i] += (fen.sum(1, tin[l]) - fen.sum(1, tin[w])) + a[w] * (block[r] - block[w] + 1);
            else
                ans[i] += (fen.sum(1, tin[l]) - fen.sum(1, tin[w])) + a[w] * (block[r] - block[w]);
        }

    for(int i = 1; i <= q; i ++)    cout << ans[i] << endl;
}



// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.