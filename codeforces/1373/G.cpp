#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#include<boost/algorithm/string.hpp>

//pragmas
#pragma GCC optimize("O3")

//types
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define JaiShreeBateman int
#define ull unsigned long long int
#define vec vector<long long int>
#define pall pair<long long int, long long int>
#define vecpair vector<pair<long long int,long long int>>
#define vecvec(a, i, j) vector<vector<long long int>> a (i, vec (j, 0))
#define vecvecvec(a, i, j, k) vector<vector<vector<long long int>>> dp (i + 1, vector<vector<long long int>>(j + 1, vector<long long int>(k + 1, 0)))

using namespace std;
using namespace __gnu_pbds;

//random stuff
#define all(a) a.begin(),a.end()
#define read(a) for (auto &x : a) cin >> x
#define endl "\n"
#define pb push_back
#define print(a) for(auto x : a) cout << x << " "; cout << endl
#define sz(x) x.size()
#define F first
#define S second
#define sp " " 
const ll INF = 9223372036854775807, MOD = 1e9 + 7;
typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;             //less_equal for multiset
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
ll mod_add(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = 1000000007) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
ll ceil_div(ll x, ll y){return (x + y - 1) / y;}
unsigned long long power(unsigned long long x,ll y, ll p){unsigned long long res = 1;x = x % p; while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
unsigned long long modInverse(unsigned long long n,int p){return power(n, p - 2, p);}
ll nCr(ll n,ll r, ll p){if (n < r)return 0;if (r == 0)return 1;unsigned long long fac[n + 1];fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;}
ll accumulate(const vec &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

const ll MAXN = 6e5+5, inf = 9e18;

struct BinSegTree
{
    ll N;
    vector<bool> val, one, zer;
    void init(ll n)
    {
        N=n;
        val.assign(4*N+5, 0), one.assign(4*N+5, 0), zer.assign(4*N+5, 1);
    }
    void pUpdate(ll ver,ll L,ll R,ll pos,ll put)
    {
        if(L==R)
        {
            val[ver] = put, one[ver] = (put == 1), zer[ver] = (put == 0);
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate(ver*2,L,M,pos,put);
        else pUpdate(ver*2+1,M+1,R,pos,put);
        zer[ver] = (zer[ver*2] or zer[ver*2 + 1]);
        one[ver] = (one[ver*2] or one[ver*2 + 1]);
    }

    ll get1(ll v, ll lv, ll rv, ll l, ll r)       //first = 0   
    {
        if(lv > r || rv < l) return -1;
        if(l <= lv && rv <= r)
        {
            if(!zer[v]) return -1;
            while(lv != rv)
            {
                ll mid = lv + (rv-lv)/2;
                if(zer[v*2])  v = v*2, rv = mid;
                else v = v*2 + 1, lv = mid+1;
            }
            return lv;
        }
        ll mid = lv + (rv-lv)/2;
        ll rs = get1(2*v, lv, mid, l, r);
        if(rs != -1) return rs;
        return get1(2*v+1, mid+1, rv, l ,r);
    }

    ll get2(ll v, ll lv, ll rv, ll l, ll r)       //last = 1   
    {
        if(lv > r || rv < l) return -1;
        if(l <= lv && rv <= r)
        {
            if(!one[v]) return -1;
            while(lv != rv)
            {
                ll mid = lv + (rv-lv)/2;
                if(one[v*2 + 1])    v = v*2 + 1, lv = mid + 1;
                else    v = v*2, rv = mid; 
            }
            return lv;
        }
        ll mid = lv + (rv-lv)/2;
        ll rs = get2(2*v+1, mid+1, rv, l ,r);
        if(rs != -1) return rs;
        return get2(2*v, lv, mid, l, r);
    }
    void update(ll pos, ll val)
    {
        pUpdate(1, 1, N, pos, val);
    }
    ll findFirst0(ll l, ll r)     //return last element in [l, r] >= minimum, just modify the fn body to convert it into finding the first element, finding element <= or < or > x etc etc
    {
        return get1(1, 1, N, l, r);
    }
    ll findLast1(ll l, ll r)
    {
        return get2(1, 1, N, l, r);
    }
}
is;
struct node
{
    int l=0,d=0;                 //left bound, displacement
    node() : l(0), d(0) {};
};
struct SegTree
{
    ll N;
    vector<node> st;vector<bool> cLazy;vector<ll> lazy;
    void init(ll n)
    {
        N=n;
        st.resize(4*N+5);
        cLazy.assign(4*N+5,false);
        lazy.assign(4*N+5,0);
    }
    void merge(node &cur,node &l,node &r) 
    {
        cur.d = min(l.d, r.d);
    }
    void propagate(ll ver,ll L,ll R)
    {
        if(L!=R)		//passing on lazy shit to children
        {
            cLazy[ver*2]=cLazy[ver*2+1]=1;
            lazy[ver*2]+=lazy[ver],lazy[ver*2+1]+=lazy[ver]; 
        }
        st[ver].l += lazy[ver], st[ver].d += lazy[ver];
        cLazy[ver]=lazy[ver]=0;
    }
    void build(ll ver,ll L,ll R)
    {
        if(L > R)return;
        if(L==R)
        {
            st[ver].l = L, st[ver].d = 0;
            return;
        }
        ll M=(L+R)/2;
        build(ver*2,L,M),build(ver*2+1,M+1,R);
        merge(st[ver],st[ver*2],st[ver*2+1]);
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
        merge(st[ver],st[ver*2],st[ver*2+1]);
    }

    ll get1(ll v, ll lv, ll rv, ll l, ll r, ll x)       //get index of latest element in [l, r] <= x variant   
    {
        if(cLazy[v])
            propagate(v, lv, rv);

        if(lv > r || rv < l) return -1;
        if(l <= lv && rv <= r)
        {
            if(st[v].d + lazy[v] > x) return -1;
            while(lv != rv)
            {
                if(cLazy[v])    propagate(v, lv, rv);
                ll mid = lv + (rv-lv)/2;
                if(st[v*2 + 1].d + lazy[v*2 + 1] <= x)  v = v*2 + 1, lv = mid+1;
                else    v = v*2, rv = mid;
            }
            return lv;
        }
        ll mid = lv + (rv-lv)/2;
        
        ll rs = get1(2*v+1, mid+1, rv, l ,r, x);
        if(rs != -1) return rs;
        return get1(2*v, lv, mid, l, r, x);
    }
    ll get2(ll v, ll lv, ll rv, ll l, ll r)       //ind of first = 0 in given range   
    {
        if(cLazy[v])
            propagate(v, lv, rv);

        if(lv > r || rv < l) return -1;
        if(l <= lv && rv <= r)
        {
            if(st[v].d + lazy[v] > 0) return -1;
            while(lv != rv)
            {
                if(cLazy[v])    propagate(v, lv, rv);
                ll mid = lv + (rv-lv)/2;
                if(st[v*2].d + lazy[v*2] == 0)  v = v*2, rv = mid;
                else v = v*2 + 1, lv = mid + 1;
            }
            return lv;
        }
        ll mid = lv + (rv-lv)/2;
        
        ll rs = get2(2*v, lv, mid, l, r);
        if(rs != -1) return rs;
        return get2(2*v+1, mid+1, rv, l ,r);
    }

    node query(ll pos)
    {
        return pQuery(1, 1, N, pos);
    }
    void update(ll l, ll r, ll val)
    {
        Update(1, 1, N, l, r, val);
    }
    ll findLatestLessThanEqual(ll l, ll r, ll minimum)     //return last element in [l, r] >= minimum, just modify the fn body to convert it into finding the first element, finding element <= or < or > x etc etc
    {
        return get1(1, 1, N, l, r, minimum);
    }
    ll findFirst0(ll l, ll r)
    {
        return get2(1, 1, N, l, r);
    }
}
lb;
int n, k, m;
set<pair<int, int>> pawn;
hashmap cnt;

int get(int x, int y)
{
    return y + abs(x - k);
}

//code starts
JaiShreeBateman main()
{
    fastio();
    is.init(MAXN), lb.init(MAXN), lb.build(1, 1, MAXN);
    cin >> n >> k >> m;
    for(int i = 1, x, y, p; i <= m; i ++)
    {
        cin >> x >> y, p = get(x, y);
        if(pawn.count({x, y}))
        {
            int first0 = lb.findFirst0(p + 1, MAXN);
            first0 --;
            int set = lb.query(first0).l + cnt[first0] - 1;
            is.update(set, 0);
            lb.update(p + 1, first0, -1);

            pawn.erase({x, y});
            cnt[p] --;
        }
        else
        {
            int place = is.findFirst0(p, MAXN);
            is.update(place, 1);

            int last = lb.findLatestLessThanEqual(p + 1, place, place);
            if(last != -1 and p + 1 <= last)
                lb.update(p + 1, last, +1);

            pawn.insert({x, y});
            cnt[p] ++;
        }
        cout << max(0LL, is.findLast1(1, MAXN) - n) << endl;
    }
}




// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.