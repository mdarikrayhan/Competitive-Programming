//Never compromise. Not even in the face of Armageddon.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

//pragmas
// #pragma GCC optimize("03")
// #pragma GCC target("avx,avx2,fma")
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
const ll inf = 1e16, INF = 1e18;
const int MOD = 1e9 + 7;

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

const int MAXN = 2e5+5, MAXX = 1e6+5, last = 1e6;


struct node2
{
    pair<ll, int> mn = mp(inf, 0);
    node2() : mn(mp(inf, 0)) {};
};
struct SegTree2
{
    ll N;
    vector<node2> st;
    vector<bool> cLazy;
    vector<int> lazy;
    void init(ll n)
    {
        N=n;
        st.resize(4*N+5);
        cLazy.assign(4*N+5,false);
        lazy.assign(4*N+5,0);
    }
    void merge(node2 &cur,node2 &l,node2 &r) 
    {
        cur.mn=min(l.mn,r.mn);
    }

    // be careful about that one lifting case
    void propagate(ll ver,ll L,ll R)
    {
        if(L!=R)		//passing on lazy shit to children
        {
            cLazy[ver*2]=cLazy[ver*2+1]=1;
            lazy[ver*2]+=lazy[ver],lazy[ver*2+1]+=lazy[ver]; 
        }
        st[ver].mn.first+=lazy[ver]; // during lazy propagation you have to chg this line according to the condition
        cLazy[ver]=lazy[ver]=0;
    }
    node2 Query(ll ver,ll L,ll R,ll i,ll j)
    {
        if(cLazy[ver])propagate(ver, L, R);
        if(j<L || i>R)return node2();
        if(i<=L && R<=j)return st[ver];
        ll M=(L+R)/2;
        node2 left=Query(ver*2,L,M,i,j),right=Query(ver*2+1,M+1,R,i,j),cur;
        
        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

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
            st[ver].mn=mp(val, L);
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate(ver*2,L,M,pos,val);
        else pUpdate(ver*2+1,M+1,R,pos,val);

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }

    node2 query(ll l, ll r)
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
};

struct node3
{
    pair<ll, int> mx = mp(-inf, 0);
    node3() : mx(mp(-inf, 0)) {};
};
struct SegTree3
{
    ll N;
    vector<node3> st;
    vector<bool> cLazy;
    vector<int> lazy;
    void init(ll n)
    {
        N=n;
        st.resize(4*N+5);
        cLazy.assign(4*N+5,false);
        lazy.assign(4*N+5,0);
    }
    void merge(node3 &cur,node3 &l,node3 &r) 
    {
        cur.mx=max(l.mx,r.mx);
    }

    // be careful about that one lifting case
    void propagate(ll ver,ll L,ll R)
    {
        if(L!=R)		//passing on lazy shit to children
        {
            cLazy[ver*2]=cLazy[ver*2+1]=1;
            lazy[ver*2]+=lazy[ver],lazy[ver*2+1]+=lazy[ver]; 
        }
        st[ver].mx.first+=lazy[ver]; // during lazy propagation you have to chg this line according to the condition
        cLazy[ver]=lazy[ver]=0;
    }
    node3 Query(ll ver,ll L,ll R,ll i,ll j)
    {
        if(cLazy[ver])propagate(ver, L, R);
        if(j<L || i>R)return node3();
        if(i<=L && R<=j)return st[ver];
        ll M=(L+R)/2;
        node3 left=Query(ver*2,L,M,i,j),right=Query(ver*2+1,M+1,R,i,j),cur;

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

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
            st[ver].mx=mp(val, L);
            return;
        }
        ll M=(L+R)/2;
        if(pos<=M)pUpdate(ver*2,L,M,pos,val);
        else pUpdate(ver*2+1,M+1,R,pos,val);

        if(cLazy[ver*2])  propagate(ver*2, L, M);
        if(cLazy[ver*2 + 1])    propagate(ver*2 + 1, M + 1, R);

        merge(st[ver],st[ver*2],st[ver*2+1]);
    }

    node3 query(ll l, ll r)
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
        for(int i = 1; i <= n; i ++)    if(query(i, i).mx.first > -300) cerr << "[" << query(i, i).mx.first << ", " << i << "] ";
        cerr << endl;
    }
};

int n, qq, s, d;
set<int> rq;        //check presence
SegTree2 r;         //expanding range, max = 0 used to check intersection in l, min = 0 used to check intersection in r 
SegTree3 l;

vector<int> a(MAXN);
vector<bool> ans(MAXN, 0);
vector<pair<int, int>> qr[MAXX];

//code starts
int main()
{
    fastio();
    cin >> n >> qq >> s >> d;
    
    l.init(last), r.init(last);

    for(int i = 1; i <= last; i ++)     l.update(i, -inf), r.update(i, inf);
    for(int i = 1; i <= n; i ++)    cin >> a[i], rq.insert(a[i]), l.update(a[i], a[i]), r.update(a[i], a[i]);

    for(int i = 1, x, k; i <= qq; i ++)  cin >> x >> k, qr[k].pb(mp(i, x));

    set<int> rch;

    queue<int> q;
    q.push(a[s]);
    rq.erase(a[s]);

    set<int> left_expand;       //l_expand stores location + insert_time
    set<int> right_expand;      //r_expand stores location - insert_time

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        rch.insert(x);
        l.update(x, -inf);
        r.update(x, inf);
        
        // check left reachable neighbourhood
        if(x - d > 0)
        {
            if(rq.count(x - d))
            {
                q.push(x - d);
                rq.erase(x - d);
            }
        }

        // check right reachable neighbourhood
        if(x + d <= last)
        {
            if(rq.count(x + d))
            {
                q.push(x + d);
                rq.erase(x + d);
            }
        }

        // fix l segment tree, how?
        int k = 0;
        set<int> l_here = {x - (d + 0), x + (d - 0)}, r_here = {x - (d - 0), x + (d + 0)};

        for(auto lp : l_here)
        {
            if(left_expand.count(lp + k))   continue;

            if(left_expand.empty())
            {
                l.update(1, min(lp, last), - lp);
                left_expand.insert(lp);
                continue;
            }

            int till = 1, next = 0;
            auto it = left_expand.lower_bound(lp);
            if(it != left_expand.end())     next = *it - k; 
            if(it != left_expand.begin())   -- it, till = *it + 1 - k;

            l.update(max(1, till), min(lp, last), - lp + next);

            left_expand.insert(lp + k);
        }

        for(auto rp : r_here)
        {
            if(right_expand.count(rp - k))  continue;

            if(right_expand.empty())
            {
                r.update(max(1, rp), last, - rp);
                right_expand.insert(rp);
                continue;
            }

            int till = last, back = 0;
            auto it = right_expand.upper_bound(rp);
            if(it != right_expand.end())    till = *it + k - 1;
            if(it != right_expand.begin())   -- it, back = *it + k;
            
            r.update(max(1, rp), min(last, till), - rp + back);
            right_expand.insert(rp - k);
        }
    }

    for(int k = 1; k <= last; k ++)
    {
        // expand left borders
        int bound = *left_expand.rbegin() - k;      //rightmost
        if(bound > 0)
        {
            int lb = 1, rb = min(last, bound);
            l.update(lb, rb, +1);

            auto f = l.query(lb, rb).mx;
            while(f.first == 0)
            {
                q.push(f.second);
                rq.erase(f.second);
                l.update(f.second, -inf);
                r.update(f.second, inf);
                f = l.query(lb, rb).mx;
            }
        }
        
        // expand right borders
        bound = *right_expand.begin() + k;          //leftmost

        if(bound < last)
        {
            int lb = max(1, bound), rb = last;
            r.update(lb, rb, -1);

            auto f = r.query(lb, rb).mn;
            while(f.first == 0)
            {
                q.push(f.second);
                rq.erase(f.second);
                l.update(f.second, -inf);
                r.update(f.second, inf);
                f = r.query(lb, rb).mn;
            }
        }

        // check the full ranges of all the things you got from there, and also new things you keep getting, also fix the l and r segment tree at each step 
        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            rch.insert(x);
            l.update(x, -inf);
            r.update(x, inf);

            if(x - (d - k) > 0)
            {
                int lb = max(1, x - (d + k)), rb = x - (d - k);
                
                vector<int> rem;
                for(auto it = rq.lower_bound(lb); it != rq.end() and *it <= rb; it ++)
                {
                    int f = *it;
                    q.push(f);
                    rem.pb(f);
                    l.update(x, -inf);
                    r.update(x, inf);
                }
                for(auto f : rem)   rq.erase(f);
            }

            if(x + (d - k) < last)
            {
                int lb = x + (d - k), rb = min(last, x + (d + k));
                vector<int> rem;
                
                for(auto it = rq.lower_bound(lb); it != rq.end() and *it <= rb; it ++)
                {
                    int f = *it;
                    q.push(f);
                    rem.pb(f);
                    l.update(x, -inf);
                    r.update(x, inf);
                }

                for(auto f : rem)   rq.erase(f);
            }

            // now add x - (d + k) and x + (d - k) to the left expansion
            set<int> l_here = {x - (d + k), x + (d - k)}, r_here = {x - (d - k), x + (d + k)};

            for(auto lp : l_here)
            {
                if(left_expand.count(lp + k))   continue;
                
                int till = 1, next = 0;
                auto it = left_expand.lower_bound(lp + k);
                if(it != left_expand.end())     next = *it - k; 
                if(it != left_expand.begin())   -- it, till = *it + 1 - k;

                l.update(max(1, till), min(lp, last), - lp + next);

                left_expand.insert(lp + k);
            }

            for(auto rp : r_here)
            {
                if(right_expand.count(rp - k))  continue;

                int till = last, back = 0;
                auto it = right_expand.upper_bound(rp - k);
                if(it != right_expand.end())    till = *it + k - 1;
                if(it != right_expand.begin())   -- it, back = *it + k;
                
                r.update(max(1, rp), min(till, last), - rp + back);

                right_expand.insert(rp - k);
            }
        }
        
        for(auto ix : qr[k])    ans[ix.first] = rch.count(a[ix.second]);
    }

    for(int i = 1; i <= qq; i ++)    cout << (ans[i] ? "Yes" : "No") << endl;
}





// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.