#include <bits/stdc++.h> // Include every standard library
// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef pair<char,char> pcc;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<pll> vll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll,pll> ppll;

double EPS = 1e-9;
int INF = 2000000005;
long long INFF = 4000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define FOR(a, b, c) for (ll(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (ll(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (ll(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (ll(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define repn(i, n) FORN(i, 1, n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define RESET(a, b) memset(a, b, sizeof(a))
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
// #define pf push_front
#define eb emplace_back
#define ef emplace_front
#define tiii tuple<int,int,int>
#define mt make_tuple
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define MAX 10000100
// #define mo 998244353
#define mo 1000000007
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>


// Begin DEBUG //
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
        class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
os << '[';
for (auto it = c.begin(); it != c.end(); ++it)
    os << &", "[2 * (it == c.begin())] << *it;
return os << ']';
}

//support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
_NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
(MACRO, ##__VA_ARGS__)
//Change output format here
#define out(x) #x " = " << x << "; "
#define debug(...)                                                              \
cout << "Line " << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"

// End DEBUG //

ll add(ll a, ll b, ll c = mo) {ll res=(a+b)%c; return res;}
ll mod_neg(ll a, ll b, ll c = mo) {ll res=(a-b+c)%c; return res;} 
ll mul(ll a, ll b, ll c = mo) {ll res=(a*b)%c; res=(res+c)%c; return res;}

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
        
        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
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

int MOD = 1000000007;
struct mi {
    int v;
    explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a;
}
mi &operator-=(mi &a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }
mi &operator/=(mi &a, mi b) { return a = a/b; }


typedef vector<mi> vm;
typedef vector<vm> vvm;
typedef vector<vvm> vvvm;

// Clear the stringstream
// ss.str("");
// ss.clear(); // Clear the stringstream state
// ss.str(str2);

///////////////////////////////////////////
/* Main starts here -> Mukund Krishnatrey*/
///////////////////////////////////////////

bool isValid(ll n, ll m, ll r, ll c){
    if(r>=0 && r<n && c>=0 && c<m) return true;
    else return false;
}

bool compf(pll p1, pll p2)
{
    if(p1.ff!=p2.ff) return p1.ff>p2.ff;
    else return p1.ss<p2.ss;
}

bool comps(pll p1, pll p2)
{
    if(p1.ss!=p2.ss) return p1.ss<p2.ss;
    else return p1.ff<p2.ff;
}

bool comp_len(pll p1, pll p2)
{
    if((p1.ss-p1.ff)!=(p2.ss-p2.ff)) return ((p1.ss-p1.ff)<(p2.ss-p2.ff));
    else return (p1.ff<p2.ff);
}

bool comp_custom(pair<pair<pll,ll>,ll> &p1, pair<pair<pll,ll>,ll> &p2){
    if(p1.ff.ff.ss!=p2.ff.ff.ss) return p1.ff.ff.ss<p2.ff.ff.ss;
    else return p1.ff.ff.ff<p2.ff.ff.ff;
}

struct scomps2
{
    bool operator()(const pll &p1, const pll &p2) const{
        if(p1.ss!=p2.ss) return (p1.ss<p2.ss);
        else return (p1.ff<p2.ff);
    }
};


struct scomps
{
    bool operator()(const pll &p1, const pll &p2) const{
        if(p1.ss!=p2.ss) return (p1.ss<p2.ss);
        else return (p1.ff<p2.ff);
    }
};

struct scomp_cur
{
    bool operator()(pair<pll,ll> p1,pair<pll,ll> p2) const{
        if(p1.ff.ff!=p2.ff.ff) return p1.ff.ff<p2.ff.ff;
        else return p1.ss<p2.ss;
    }
};


const ll mod[2] = {(ll)1e9+7, 998244353};
vvl pw;

void fill_pow(){
    pw.clear(); pw.resize(2, vl(5000));
    pw[0][0] = pw[1][0] = 1;
    ll p=61;
    rep(i,2){
        FORN(j,1,pw[i].size()-1){
            pw[i][j] = mul(pw[i][j-1], p, mod[i]);
            // if(j<=10) debug(i,j,pw[i][j]);
        }
    }
}

class Shash{
    public:
    vvl hash;
    ll len;
    Shash(string &s){
        len = s.length();
        hash.resize(2, vl(s.length()+2,0));
        rep(i,2){
            rep(j,s.length()){
                hash[i][j+1] = add(hash[i][j], mul(s[j]-'a'+1, pw[i][j], mod[i]), mod[i]);
            }
        }
        // if(len==6) debug(s, hash);
    }   

    ll get_hash(int l, int r){
        ll ans;
        ans= (hash[0][r+1]+mod[0]-hash[0][l]) % mod[0];
        ans= mul(ans, pw[0][len-1-l], mod[0]);    
        return ans;
    }
};

ll q;

ll query(ll l, ll r){
    cout<<"? "<<l<<" "<<r<<endl;
    
    cin>>q;
    
    return q;
}

void print_ans(ll i, ll j, ll k){
    cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
}

pll get_ans(ll a, ll b, ll c){
    ll cn=(b*b)-(4*a*c);
    ll k=sqrt(cn);
    ll x,y;
    x=-(b)+k;
    y=-(b)-k;
    a*=2;
    ll l,r; l=r=-1;
    if(x%a==0 && x>0) l=x/a;
    if(y%a==0 && y>0) r=y/a;
    return {l,r};
}

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (fopen("exercise.in", "r")) {
        freopen("exercise.in", "r", stdin);
        freopen("exercise.out", "w", stdout);
    }
    cout<<fixed<<setprecision(10);
    ll t_t; cin>>t_t;
    while(t_t--){
        ll n; cin>>n;
        ll st,end,mid; st=1; end=n;
        ll i,k,tot;
        i=1;k=n;
        q=query(1,n); tot=q;
        while(st<=end){
            mid=st+(end-st)/2;
            q=query(1,mid);
            if(q==tot) k=mid;
            if(q>0) end=mid-1;
            else{
                i=mid;
                st=mid+1;
            }
        }
        ll tot2 = query(i+1,n);
        k=tot-tot2;
        k+=1;
        ll x=k;
        ll a,b,c; a=1; b=-1; c=(x*x-x-2*tot);
        pll py=get_ans(a,b,c);
        ll v1,v2,y;
        v1=v2=y=-1;
        if(py.ff!=-1) v1=query(i,i+x+py.ff-1);
        if(py.ss!=-1) v2=query(i,i+x+py.ss-1);
        if(v1==tot) y=py.ff;
        else y=py.ss;
        print_ans(i, i+x, i+x+y-1);
        // auto p=get_ans(1,-1,-6);
        // debug(p);
    }
    return 0; 
} 



// <------ Approaches to keep in mind during problems ------> 

// ** If binary search applicable note it down.

// ** DP

// ** Stack on 2d graphs



// <------ For random mistakes during problems ------> 

// ** Never use break condition before any input is finished, can cause wrong inputs.

// ** Priority queue gives maxima, need to do greater <ll> to get minima.

// ** To check for overflow in a*b, do (a>(INFF/b)) then overflow.

// ** Don't use bitwise operators in conditional true and false checks.

// ** Always assert for sanity checks if value should be in a certain range.

// ** In getting n^p, power p shouldn't be reduced by mod. So when obtaining the value of p, don't use any mod operations.

// ** Instead of -1, INT_MIN, etc. use INFF and -INFF if long long values are allowed.
// Consider possible values if >INT_MAX ( or < INT_MIN) don't use it.

// Take care that when erasing values from vector/array/related containers, that the iterator position is gone after that. And even in map/set/multiset, that iterator has to be replaced, can't do it-- or it++ after erase.

// When comparing values, for eg:-, two vectors of equal size, if every value is equal, return false or return v[0]<v[1]. If you return true, then you get segmentation fault.

// Multiset value erase will remove all instances of that value, better to use a map

// Try to divide problem into subcases, and deal with them independently.

// If lexicographical, then definitely don't do any swaps in your code, as it will change the order

// Please read constraints carefully, you might end up overcomplicating the question if not.

// Always verify your solution with atleast the given examples, and some extra edge cases you can think of, before you start coding it

// Have a pseduo structure of code written down, (or in your mand), before writing the same

// Write code in batches, keep testing every independent function, before writing next part

// Check for long long, too many mods

// Always take a look at the examples if stuck, or can't come with a solution for a while, normally examples contain a hint.


// <------ For finding solution to adhoc problem ------> 

// ** Draw lots of small cases to gain a better understanding of the problem. If you're having trouble debugging, draw more cases. If you don't know how to start with a problem, draw more cases. Whenever you don't know how to further approach a problem, you're probably massing an important observation, so draw more cases and make observations about properties of the problem.

// ** Whenever you find an observation that seems useful, write it down! Writing down ideas lets you easily come back to them later, and makes sure you don't forget about ideas that could potentially be the solution.

// ** Don't get stuck on any specific idea, unless you see an entire solution.

// ** Try to approach the problem from a lot of different perspectives. Try to mess around with formulas or draw a visual depiction of the problem. One of the most helpful things you can do when solving ad hoc problems is to keep trying ideas until you make progress. This is something you get better at as you do more problems.


// g++ -static-libgcc -static-libstdc++ -g test_compare.cpp -o test_compare.exe