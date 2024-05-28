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
const ll inf = 0x3f3f3f3f, INF = 2e9;
const int MOD = 1e9 + 7;
const ll BIG_MOD = 489133282872437279; //use to decrease hash collision probability

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;             //for multiset, use less_equal and erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))
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

//#define int int64_t;

struct node
{
    int mx, lazy;
    bool cLazy;
    node* left, *right;

    node(int r) : mx(r), cLazy(false), lazy(0), left(NULL), right(NULL) {};
    
    void extend(int L, int R)
    {
        if(left == NULL)    left = new node((L + R) >> 1);
        if(right == NULL)   right = new node(R);
    }
};
struct SegTree
{
    ll N;

    node* nil = new node(-1);
    node *root;

    void init(ll n)
    {
        N=n;
        root = new node(n);
        if(n != 1)  root->extend(0, n);
    }
    void merge(node *cur,node *l,node *r) 
    {
        cur->mx = max(l->mx, r->mx);
    }

    // be careful about that one lifting case in range add, range max qr for ex
    void propagate(node *cur,ll L,ll R)
    {
        if(L!=R)		//passing on lazy shit to children
        {
            cur->extend(L, R);
            cur->left->cLazy = cur->right->cLazy = 1;
            cur->left->lazy += cur->lazy, cur->right->lazy += cur->lazy;
        }
        cur->mx += cur->lazy;
        cur->cLazy = cur->lazy = 0;
    }

    // ok, yeah, so we just need like point queries right

    node* Query(node *cur,ll L,ll R,ll i,ll j)
    {
        if(L != R)  cur->extend(L, R);
        if(cur->cLazy)propagate(cur, L, R);
        
        if(j<L || i>R)return nil;
        if(i<=L && R<=j)return cur;
        ll M=(L+R)/2;
        node *left=Query(cur->left,L,M,i,j),*right=Query(cur->right,M+1,R,i,j),*mer;
        merge(cur,left,right);
        return cur;
    }
    node* pQuery(node* cur,ll L,ll R,ll pos)
    {
        if(L != R)  cur->extend(L, R);
        if(cur->cLazy)propagate(cur,L,R);

        if(L==R)return cur;
        ll M=(L+R)/2;
        if(pos<=M)return pQuery(cur->left,L,M,pos);
        else return pQuery(cur->right,M+1,R,pos);
    }	
    void Update(node* cur,ll L,ll R,ll i,ll j,ll val)
    {
        if(L != R)  cur->extend(L, R);
        if(cur->cLazy)propagate(cur,L,R);

        if(j<L||i>R)return;
        if(i<=L && R<=j)
        {
            cur->cLazy=1,cur->lazy+=val;
            propagate(cur,L,R);
            return;
        }
        ll M=(L+R)/2;
        Update(cur->left,L,M,i,j,val),Update(cur->right,M+1,R,i,j,val);

        if(cur->left->cLazy)  propagate(cur->left, L, M);
        if(cur->right->cLazy)    propagate(cur->right, M + 1, R);
        
        merge(cur,cur->left,cur->right);
    }
   
    ll get(node* v, ll lv, ll rv, ll l, ll r, ll x)       //get index of first element in [l, r] >= x variant   
    {
        if(lv != rv)    v->extend(lv, rv);
        
        if(v->cLazy)    propagate(v, lv, rv);

        if(lv > r || rv < l) return -1;
        if(l <= lv && rv <= r)
        {
            if(v->mx + v->lazy < x) return -1;
            while(lv != rv)
            {
                if(lv != rv)    v->extend(lv, rv);
                if(v->cLazy)    propagate(v, lv, rv);
                ll mid = lv + (rv-lv)/2;
                
                if(v->left->mx + v->left->lazy >= x)   v = v->left, rv = mid;
                else v = v->right, lv = mid + 1;
            }
            return lv;
        }
        ll mid = lv + (rv-lv)/2;
        
        ll rs = get(v->left, lv, mid, l, r, x);
        if(rs != -1) return rs;
        return get(v->right, mid+1, rv, l ,r, x);
    }

    node* query(ll pos)
    {
        return pQuery(root, 1, N, pos);
    }
    node* query(ll l, ll r)
    {
        return Query(root, 1, N, l, r);
    }
    void update(ll l, ll r, ll val)
    {
        if(l > r)   return;
        Update(root, 1, N, l, r, val);
    }
    ll findFirst(ll l, ll r, ll minimum)     //return last element in [l, r] >= minimum, just modify the fn body to convert it into finding the first element, finding element <= or < or > x etc etc
    {
        return get(root, 1, N, l, r, minimum);
    }
}rq;

const int T = 1e9;
int n;

int get_temp(int t)
{
    return rq.query(t)->mx;
}

//code starts
int32_t main()
{
    fastio();
    cin >> n;

    rq.init(T);
    int lastans = 0;

    for(int i = 1, t, k; i <= n; i ++)
    {
        cin >> t;
        
        // update

        int lb = get_temp(0), rb = get_temp(1e9);
        if(lb > t)  rq.update(1, T, -1);
        else if(rb < t) rq.update(1, T, 1);
        else
        {
            int l = rq.findFirst(0, T, t), r = rq.findFirst(0, T, t + 1);

            // just update the two segments now
            if(l != 0)  rq.update(0, l - 1, +1);
            if(r != -1) rq.update(r, T, -1);
        }

        // queries
        cin >> k;
        while(k --)
        {
            int x;
            cin >> x;
            x = (x + lastans) % ((int)(1e9) + 1);
            lastans = get_temp(x);

            cout << lastans << endl;
        }
    }
}

/*
ok, so we basically have an array which always remains increasing
we wanna perform +1 updates on some prefix, 0 on some middle segment, -1 on some suffix (it will always remain sorted)
so can be easily done in n log^2 time and memory

but sets and binsearch

how can we get current temperature of some initial temperature a at some point in time t?

yeah we'll need dsu too 

let p be parent temperature of the a's dsu set at time t 

so we just need to find temperature of its parent element

its nothing but: number of events behind it - number of events after

yeah just use ordered set and cheese this shit

also gotta take care of edge cases in which days temperature doesnt lie in the complete segment
*/



// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.