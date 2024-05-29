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

#define int int64_t

template<typename Node>
struct SparseTable {
	vector<vector<Node>> table;
	int n;
	int maxLog;
	vector<int> a;
	SparseTable(int n1, vector<int> &arr) 
    {
		n = n1;
		a = arr;
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
	ll val, mn, mx; // store more info if required
	Node1() 
    { // Identity Element
		val = 0;
		mn = 0;
		mx = 0;
	}
	Node1(ll v) 
    {
		val = v;
		mn = v;
		mx = v;
	}
	void merge(Node1 &l, Node1 &r) 
    {
		val = l.val + r.val;
		mn = min(l.mn, r.mn);
		mx = max(l.mx, r.mx);
	}
};

struct node
{
    ll val=0;
    node() : val(0) {};
};
struct SegTree
{
    ll N;
    vector<node> st;
    vector<bool> cLazy;
    vector<ll> lazy;
    void init(ll n)
    {
        N=n;
        st.resize(4*N+5);
        cLazy.assign(4*N+5,false);
        lazy.assign(4*N+5,0);
    }
    void merge(node &cur,node &l,node &r) 
    {
        cur.val=l.val+r.val; // this is the normal function which you want to do for parents using left and right child
    }

    void propagate(ll ver,ll L,ll R)
    {
        if(L!=R)		//passing on lazy shit to children
        {
            cLazy[ver*2]=cLazy[ver*2+1]=1;
            lazy[ver*2]+=lazy[ver],lazy[ver*2+1]+=lazy[ver]; 
        }
        st[ver].val+= (R - L + 1) * lazy[ver]; // during lazy propagation you have to chg this line according to the condition
        cLazy[ver]=lazy[ver]=0;
    }
    node Query(ll ver,ll L,ll R,ll i,ll j)
    {
        if(cLazy[ver])propagate(ver, L, R);
        if(j<L || i>R)return node();
        if(i<=L && R<=j)return st[ver];
        ll M=(L+R)/2;
        node left=Query(ver*2,L,M,i,j),right=Query(ver*2+1,M+1,R,i,j),cur;
        merge(cur,left,right);
        return cur;
    }
    void Update(ll ver,ll L,ll R,ll i,ll j,ll val)
    {
        if(cLazy[ver])propagate(ver,L,R);
        if(j<L||i>R)return;
        if(i<=L && R<=j)
        {
            cLazy[ver]=1,lazy[ver]+=val;
            propagate(ver,L,R);
            return;
        }
        ll M=(L+R)/2;
        Update(ver*2,L,M,i,j,val),Update(ver*2+1,M+1,R,i,j,val);

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }
    node query(ll l, ll r)
    {
        return Query(1, 1, N, l, r);
    }
    void update(ll l, ll r, ll val)
    {
        Update(1, 1, N, l, r, val);
    }
    void show(int n)
    {
        for(int i = 1; i <= n; i ++)    cerr << query(i, i).val << sp;
        cerr << endl;
    }
};

const int MAXN = 2e5+5, MAXQ = 1e6+5;

int n, q;

vector<int> f[MAXN];

vector<int> p(MAXN), ans(MAXQ), pos(MAXN);
vector<pair<int, int>> qr[MAXN];

vector<array<int, 4>> segment;                  //{in time, out time, l, r}
vector<int> add[MAXN], rem[MAXN];               //add updates, remove updates

vector<pair<int, int>> fix(vector<pair<int, int>> a)
{
    if(a.empty())   return a;

    int n = a.size();
    sort(all(a), [&](pair<int, int> a, pair<int, int> b){if(a.first == b.first) return a.second > b.second;    return a.first < b.first;});
    vector<bool> pres(n, true);

    set<pair<int, int>> in;     //rb, index

    for(int i = 0; i < n; i ++)
    {
        int r = a[i].second;
        auto it = in.lower_bound(mp(r, 0));
        vector<pair<int, int>> rem;

        while(it != in.end())
        {
            rem.pb(*it);
            it ++;
        }

        for(auto x : rem)
        {
            pres[x.second] = false;
            in.erase(x);
        }

        in.insert(mp(r, i));
    }

    vector<pair<int, int>> fin;
    for(int i = 0; i < n; i ++)
        if(pres[i])
            fin.pb(a[i]);
    return fin;
}


//code starts
int32_t main()
{
    fastio();
    cin >> n >> q;
    for(int i = 1; i <= n; i ++)    cin >> p[i], pos[p[i]] = i;

    SparseTable<Node1> spt(n + 1, p);
    SegTree done, inc, con;
    done.init(n + 1), inc.init(n + 1), con.init(n + 1);

    for(int i = 1, l, r; i <= q; i ++)
    {
        cin >> l >> r;
        qr[r].pb(mp(l, i));
    }

    for(int i = 1; i <= n; i ++)
        for(int j = i * i + i; j <= n; j += i)    
            f[j].pb(i);
        
    int t = -1;

    for(int i = 1; i <= n; i ++)
    {
        int l = i, r = i;

        int s = 1, e = i;
        while(s <= e)
        {
            int mid = (s + e) >> 1;
            if(spt.queryIdempotent(mid, i).mx <= p[i])  e = mid - 1, l = mid;
            else    s = mid + 1;
        }

        s = i, e = n, r = i;
        while(s <= e)
        {
            int mid = (s + e) >> 1;
            if(spt.queryIdempotent(i, mid).mx <= p[i])  s = mid + 1, r = mid;
            else    e = mid - 1;
        }
        
        vector<pair<int, int>> here;
        for(auto x : f[p[i]])
        {
            int lh = min(i, min(pos[x], pos[p[i]/x])), rh = max(i, max(pos[x], pos[p[i]/x]));
            if(l <= lh and rh <= r) here.pb(mp(lh, rh));
        }
        here = fix(here);

        if(!here.empty())
        {
            int n = here.size();

            ++ t;
            segment.pb({here[n - 1].second, r, l, here[n - 1].first});
            add[here[n - 1].second].pb(t), rem[r].pb(t);

            for(int i = 0; i < n - 1; i ++)
            {
                ++ t;
                segment.pb({here[i].second, here[i + 1].second - 1, l, here[i].first});
                add[here[i].second].pb(t), rem[here[i + 1].second - 1].pb(t);
            }
        }
    }

    // for(auto s : segment)
    // {
    //     int l1 = s[2], r1 = s[3], l2 = s[0], r2 = s[1];
    //     debug(l1, r1, l2, r2);
    // }

    for(int i = 1; i <= n; i ++)
    {
        for(auto a : add[i])
        {
            int l = segment[a][2], r = segment[a][3];

            inc.update(l, r, 1);
            con.update(l, r, - (i - 1));
        }

        for(auto q : qr[i])
        {
            int l = q.first, idx = q.second;
            ans[idx] = done.query(l, n).val + i * inc.query(l, n).val + con.query(l, n).val;
        }

        for(auto a : rem[i])
        {
            int tin = segment[a][0], tout = segment[a][1], l = segment[a][2], r = segment[a][3];
            inc.update(l, r, -1);
            con.update(l, r, +(tin - 1));
            
            done.update(l, r, tout - tin + 1);
        }
    }

    for(int i = 1; i <= q; i ++)    cout << ans[i] << endl;
}





// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.