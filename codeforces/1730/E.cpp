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

const int MAXN = 5e5+5, MAXX = 1e6+5;

// declared like SparseTable<node1> name (n, array), all queries are 0 indexed
template<typename Node>
struct SparseTable {
	vector<vector<Node>> table;
	int n;
	int maxLog;
	vector<int> a;
	SparseTable(int n1, int *arr) 
    {
		n = n1;
        a.resize(n);
        for(int i = 0; i < n; i ++) a[i] = arr[i];
		table.resize(n);
		maxLog = log2_floor(n);
		for (int i = 0; i < n; i++) {
			table[i].resize(maxLog + 1);
			fill(all(table[i]), Node());
		}
		build();
	}
	void build() 
    {
		for (int i = 0; i < n; i++) {
			table[i][0] = Node(a[i]);
		}
		for (int i = 1; i <= maxLog; i++) {
			for (int j = 0; (j + (1 << i)) <= n; j++) {
				table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
			}
		}
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
	int mn, mx; // store more info if required
	Node1() 
    { // Identity Element
		mn = 0;
		mx = 0;
	}
	Node1(ll v) 
    {
		mn = v;
		mx = v;
	}
	void merge(Node1 &l, Node1 &r) 
    {
		mn = min(l.mn, r.mn);
		mx = max(l.mx, r.mx);
	}
};

vector<int> fac[MAXX], occ[MAXX];
int pnt[MAXX];
int a[MAXN], l_mx[MAXN], r_mx[MAXN], l_mn[MAXN], r_mn[MAXN];

//code starts
int32_t main()
{
    fastio();

    for(int i = 1; i < MAXX; i ++)
        for(int j = 2*i; j < MAXX; j += i)
            fac[j].pb(i);

    int tt;
    cin >> tt;
    while(tt--)
    {
        memset(a, 0, sizeof(a));
        memset(pnt, 0, sizeof(pnt));
        for(int i = 1; i < MAXX; i ++)  occ[i].clear();

        int n;
        cin >> n;

        for(int i = 1; i < MAXX; i ++)  occ[i].pb(0);
        for(int i = 1; i <= n; i ++)    cin >> a[i], occ[a[i]].pb(i);
        for(int i = 1; i < MAXX; i ++)  occ[i].pb(n + 1);

        l_mn[n + 1] = l_mx[n + 1] = r_mn[n + 1] = r_mx[n + 1] = n + 1;

        SparseTable<Node1> rq(n + 1, a);
        rq.build();


        for(int i = 1; i <= n; i ++)
        {
            int x = a[i];
            l_mn[i] = l_mx[i] = r_mn[i] = r_mx[i] = i;

            int s = 1, e = i;
            while(s <= e)
            {
                int mid = (s + e) >> 1;
                if(rq.queryIdempotent(mid, e).mn >= x)
                    e = mid - 1, l_mn[i] = mid;
                else
                    s = mid + 1;
            }

            s = 1, e = i;
            while(s <= e)
            {
                int mid = (s + e) >> 1;
                if(rq.queryIdempotent(mid, e).mx <= x)
                    e = mid - 1, l_mx[i] = mid;
                else
                    s = mid + 1;
            }

            s = i, e = n;
            while(s <= e)
            {
                int mid = (s + e) >> 1;
                if(rq.queryIdempotent(s, mid).mn >= x)
                    s = mid + 1, r_mn[i] = mid;
                else
                    e = mid - 1;
            }

            s = i + 1, e = n;
            while(s <= e)
            {
                int mid = (s + e) >> 1;
                if(rq.queryIdempotent(s, mid).mx < x)
                    s = mid + 1, r_mx[i] = mid;
                else
                    e = mid - 1;
            }
        }

        int64_t ans = 0;

        for(int i = 1; i <= n; i ++)
        {
            int x = a[i], l = l_mx[i], r = r_mx[i];

            for(auto f : fac[x])
            {
                int lst = occ[f][pnt[f]], nxt = occ[f][pnt[f] + 1];

                if(lst >= l and nxt <= r)
                {
                    if(l_mn[lst] == l_mn[nxt])      //both intersect
                    {
                        int L = max(l_mn[lst], l), R = min(r_mn[nxt], r);

                        ans += ((int64_t)(nxt - i)) * (lst - L + 1) + ((int64_t)(i - lst)) * (R - nxt + 1) + (int64_t(lst - L + 1)) * (R - nxt + 1);
                    }
                    else if(r_mn[lst] >= i)
                    {
                        int L = max(l_mn[lst], l), R = min(r_mn[lst], r);

                        ans += ((int64_t)(R - i + 1)) * (lst - L + 1);
                    }
                    else if(l_mn[nxt] <= i)
                    {
                        int L = max(l_mn[nxt], l), R = min(r_mn[nxt], r);

                        ans += ((int64_t)(R - nxt + 1)) * (i - L + 1);
                    }
                }
                else if(lst >= l)
                {
                    if(r_mn[lst] >= i)
                    {
                        int L = max(l_mn[lst], l), R = min(r_mn[lst], r);

                        ans += (int64_t)(lst - L + 1) * (R - i + 1);
                    }
                }
                else if(nxt <= r)
                {
                    if(l_mn[nxt] <= i)
                    {
                        int L = max(l_mn[nxt], l), R = min(r_mn[nxt], r);

                        ans += ((int64_t)(R - nxt + 1)) * (i - L + 1);
                    }
                }
            }

            ans += (i - max(l_mx[i], l_mn[i]) + 1);   //own self

            ++ pnt[x];
        }

        cout << ans << endl;
    }
}





// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.