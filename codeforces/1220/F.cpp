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
#define ll long long int
#define TYPE long long int
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


struct node_small
{
    pair<int, int> get;
    node_small() : get(mp(inf, inf)) {};
};
struct SegTree
{
    ll N;
    vector<node_small> st;
    void init(ll n)
    {
        N=n;
        st.resize(4*N+5);
    }
    void merge(node_small &cur,node_small &l,node_small &r) 
    {
        cur.get = min(l.get, r.get);
    }

    node_small Query(ll ver,ll L,ll R,ll i,ll j)
    {
        if(j<L || i>R)return node_small();
        if(i<=L && R<=j)return st[ver];
        ll M=(L+R)/2;
        node_small left=Query(ver*2,L,M,i,j),right=Query(ver*2+1,M+1,R,i,j),cur;
        merge(cur,left,right);
        return cur;
    }
    void pUpdate(ll ver,ll L,ll R,ll pos,ll val)
    {
        if(L==R)
        {
            st[ver].get = mp(val, L);
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate(ver*2,L,M,pos,val);
        else pUpdate(ver*2+1,M+1,R,pos,val);

        // if(cLazy[ver*2])  propagate(ver*2, L, M);
        // if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }
   
    node_small query(ll l, ll r)
    {
        return Query(1, 1, N, l, r);
    }
    void update(ll pos, ll val)
    {
        pUpdate(1, 1, N, pos, val);
    }
}rq;

struct node
{
    ll mx=-INF, val = 0;
    bool on = 0;
    node() : mx(-INF), on(0), val(0) {};
};
struct Segtree2
{
    ll N;
    vector<node> st;
    vector<bool> cLazy;
    vector<ll> lazy;
    void init(ll n)
    {
        N=n;
        st.clear();
        st.resize(4*N+5);
        cLazy.assign(4*N+5,false);
        lazy.assign(4*N+5,0);
    }
    void merge(node &cur,node &l,node &r) 
    {
        cur.mx=max(l.mx, r.mx);
        cur.val=l.val+r.val; // this is the normal function which you want to do for parents using left and right child
    }

    // be careful about that one lifting case
    void propagate(ll ver,ll L,ll R)
    {
        if(L!=R)		//passing on lazy shit to children
        {
            cLazy[ver*2]=cLazy[ver*2+1]=1;
            lazy[ver*2]+=lazy[ver],lazy[ver*2+1]+=lazy[ver]; 
        }

        if(st[ver].mx != -INF)  st[ver].mx += lazy[ver];
        st[ver].val += lazy[ver];

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
    void pUpdate(ll ver,ll L,ll R,ll pos,ll val)
    {
        if(cLazy[ver])propagate(ver,L,R);
        if(L==R)
        {
            st[ver].val = val;
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate(ver*2,L,M,pos,val);
        else pUpdate(ver*2+1,M+1,R,pos,val);

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }

    void pUpdate2(ll ver,ll L,ll R,ll pos)
    {
        if(cLazy[ver])propagate(ver,L,R);
        if(L==R)
        {
            st[ver].mx = st[ver].val;
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate2(ver*2,L,M,pos);
        else pUpdate2(ver*2+1,M+1,R,pos);

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }

    ll get(ll v, ll lv, ll rv, ll l, ll r, ll x)       //get index of latest element in [l, r] >= x variant   
    {
        if(cLazy[v])
            propagate(v, lv, rv);

        if(lv > r || rv < l) return -1;
        if(l <= lv && rv <= r)
        {
            if(st[v].mx + lazy[v] < x) return -1;
            while(lv != rv)
            {
                if(cLazy[v])    propagate(v, lv, rv);
                ll mid = lv + (rv-lv)/2;
                if(st[v*2 + 1].mx + lazy[v*2 + 1]>= x)  v = v*2 + 1, lv = mid+1;
                else    v = v*2, rv = mid;
            }
            return lv;
        }
        ll mid = lv + (rv-lv)/2;
        
        ll rs = get(2*v+1, mid+1, rv, l ,r, x);
        if(rs != -1) return rs;
        return get(2*v, lv, mid, l, r, x);
    }

    node query(ll l, ll r)
    {
        return Query(1, 1, N, l, r);
    }
    void update(ll pos, ll val)
    {
        pUpdate(1, 1, N, pos, val);
    }
    void update(ll l, ll r, ll val)
    {
        Update(1, 1, N, l, r, val);
    }
    void toggle(ll pos)
    {
        pUpdate2(1, 1, N, pos);
    }
    ll findLatest(ll l, ll r, ll minimum)     //return last element in [l, r] >= minimum, just modify the fn body to convert it into finding the first element, finding element <= or < or > x etc etc
    {
        return get(1, 1, N, l, r, minimum);
    }
}euler;

const int MAXN = 2e5+5;
int n;
deque<int> p;
vector<int> l(MAXN, -1), r(MAXN, -1), tin(MAXN), tout(MAXN);

vector<int> ans(MAXN, 0);

void build(int x, int lb, int rb)       //pos
{
    if(x != lb)
    {
        int child = rq.query(lb, x - 1).get.second;
        l[x] = child;
        build(child, lb, x - 1);
    }
    if(x != rb)
    {
        int child = rq.query(x + 1, rb).get.second;
        r[x] = child;
        build(child, x + 1, rb);
    }
}

//code starts
int main()
{
    fastio();
    cin >> n;

    if(n == 1)
    {
        cout << 1 << sp <<  0 << endl;
        exit(0);
    }

    for(int i = 1, x; i <= n; i ++)
    {
        cin >> x;
        p.push_back(x);
    }
    
    int shift = 0;
    while(p.front() != 1)
    {
        ++ shift;
        p.push_back(p.front());
        p.pop_front();
    }

    int s;
    rq.init(n);
    for(int i = 1; i < n; i ++) rq.update(i, p[i]), s = (p[i] == 2 ? i : s);

    build(s, 1, n - 1);

    int timer = 0;
    function<void(int)> dfs = [&](int u)
    {
        tin[u] = ++timer;
        if(l[u] != -1)  dfs(l[u]);
        if(r[u] != -1)  dfs(r[u]);
        tout[u] = timer;
    };
    dfs(s);

    euler.init(n);

    for(int i = 1; i < n; i ++)
    {
        euler.update(tin[i], tout[i], 1);
        euler.toggle(tin[i]);
        ans[i] = max((ll)ans[i], 1LL + euler.query(1, n).mx);
    }

    euler.init(n);

    for(int i = n - 1; i; i --)
    {
        euler.update(tin[i], tout[i], 1);
        euler.toggle(tin[i]);
        ans[i - 1] = max((ll)ans[i - 1], 1LL + euler.query(1, n).mx);
    }

    pair<int, int> opt = mp(inf, inf);
    for(int i = 0; i < n; i ++) opt = min(opt, mp(ans[i], i));

    cout << opt.first << sp << mod_add(shift, 1 + opt.second, n);
}

/*
key observation:

consider construction of the tree from a subarray in which you keep adding one element to one end of the subarray.

it's easy to show that added element will have atmost 1 child c, and it is inserted such that its parent p was the parent 
of c before insertion of current element

this implies that as more elements are added, for any element v in tree, its set of parents either remains the same or gets new parents (no parent is ever removed from set of parents)

now obviously, each element's depth is its number of parents, and since all A -> B (parent -> child) relations hold across all updates, we can simply use subtree add methods
to do shit (simple segtree on euler tour)
*/



// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.