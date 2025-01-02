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
const ll INF = 9223372036854775807, MOD = 1e9 + 7;

typedef tree<long long int, null_type, less_equal<long long int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;             //for multiset, use less_equal and erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))
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
int ceil_div(int x, int y){return (x + y - 1) / y;}
unsigned long long power(unsigned long long x,ll y, ll p){unsigned long long res = 1;x = x % p; while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
unsigned long long modInverse(unsigned long long n,int p){return power(n, p - 2, p);}
ll nCr(ll n,ll r, ll p){if (n < r)return 0;if (r == 0)return 1;unsigned long long fac[n + 1];fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;}
ll accumulate(const vector<long long int> &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

const ll MAXN = 2e5+5, MAXD = 1e5+1000;

const ll inf = 9e18;

struct node
{
    ll mn=inf,mx=-inf,val=0;
    node() : mn(inf), mx(-inf), val(0) {};
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
        cur.mn=min(l.mn,r.mn);
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
        st[ver].val += (R - L + 1) * lazy[ver];
        cLazy[ver]=lazy[ver]=0;
    }
    void build(ll ver,ll L,ll R,vector<ll>& a)
    {
        if(L > R)return;
        if(L==R)
        {
            st[ver].mn=a[L-1],st[ver].mx=a[L-1],st[ver].val=a[L-1];
            return;
        }
        ll M=(L+R)/2;
        build(ver*2,L,M,a),build(ver*2+1,M+1,R,a);
        merge(st[ver],st[ver*2],st[ver*2+1]);
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
    node pQuery(ll ver,ll L,ll R,ll pos)
    {
        if(cLazy[ver])propagate(ver,L,R);
        if(L==R)return st[ver];
        ll M=(L+R)/2;
        if(pos<=M)return pQuery(ver*2,L,M,pos);
        else return pQuery(ver*2+1,M+1,R,pos);
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

        // if(cLazy[ver*2])  propagate(ver*2, L, M);
        // if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);
        
        merge(st[ver],st[ver*2],st[ver*2+1]);
    }
    void pUpdate(ll ver,ll L,ll R,ll pos,ll val)
    {
        if(cLazy[ver])propagate(ver,L,R);
        if(L==R)
        {
            st[ver].mn+=val,st[ver].mx+=val,st[ver].val+=val;
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate(ver*2,L,M,pos,val);
        else pUpdate(ver*2+1,M+1,R,pos,val);

        // if(cLazy[ver*2])  propagate(ver*2, L, M);
        // if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }

    ll get(ll x)
    {
        int v = 1, lv = 1, rv = N;
        if(cLazy[v])
            propagate(v, lv, rv);
        if(st[v].val < x)   return -1;

        ll sum = 0;

        while (lv != rv)
        {
            ll mid = (lv + rv)/2;

            if(cLazy[v*2])  propagate(v*2, lv, mid);

            if(st[v*2].val + sum >= x)
            {
                rv = mid;
                v = v * 2;
            }
            else
            {
                sum += st[v*2].val;
                if(cLazy[v*2+1])    propagate(v*2 + 1, mid + 1, rv);
                lv = mid + 1;
                v = v * 2 + 1;
            }
        }
        return lv;
    }

    node query(ll pos)
    {
        return pQuery(1, 1, N, pos);
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

    void show(int n)
    {
        for(int i = 1; i <= n; i ++)    cerr << query(i).val << sp;
        cerr << endl;
    }
}rq;

int n, k;

//code starts
int main()
{
    fastio();    
    cin >> n >> k;

    vector<int> l(n);
    for(int i = 0; i < n; i ++)    cin >> l[i];
    sort(l.rbegin(), l.rend());

    int i = 0;
    ll ans = 1e9;
    rq.init(MAXD);

    for(int d = 0; d < MAXD and i < n; d ++)
    {
        int x = (d ? rq.query(d).val : 1);

        for(int j = 1; i < n and j <= x; i ++, j ++)
        {
            if(d)   rq.update(d, -1);
            -- l[i];
            rq.update(d + 2, min(d + 1 + l[i]/2, (int)MAXD), +1);
            rq.update(d + 2, min((int)MAXD, d + 1 + ceil_div(l[i], 2)), +1);

            int best = rq.get(k);
            if(best != -1)  ans = min((int)ans, best);
        }

        if(d)   rq.update(d, -rq.query(d).val);
    }
    cout << (ans < 1e9 ? ans : -1) << endl;
}


/*
1) claims always more optimal to place longer chain at less distance than vice versa: proof by contradiction, swap
2) never optimal to place some chain at some position if there exist position at lesser distance which never gets marked: again proof by contradiction
3) hang by centre always best, obviously because maximum is minimised, that all that matters

obs: answer is never too high, since you require O(n) clears anyway. ok, so simulation confirms that maximum depth is 100020 anyways (in worst case when 2e5 chains of 2e5 length)

*/


// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.