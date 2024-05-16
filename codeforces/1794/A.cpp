#include <bits/stdc++.h>

using namespace std;

/// PRAGMAs
#pragma GCC optimize ("Ofast") //Basic
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX

/// SOME PRIMES
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;

/// ORDER STATISTICS TEMPLATE
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/// DEBUG
#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
// #define cerr cout
namespace __DEBUG_UTIL__
{
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) {}
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(_Bit_reference x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename... T>
    void print(vector<vector<T...>> &&mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename... T>
    void print(stack<T...> st);
    template <typename... T>
    void print(queue<T...> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cerr << '{';
        for (auto &&i : x)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename... T>
    void print(vector<vector<T...>> &&mat)
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            cerr << ",", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t)
    {
        cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cerr << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename... T>
    void print(stack<T...> st)
    {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename... T>
    void print(queue<T...> q)
    {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions */
    template <typename T>
    void printer(const char *name, T &&head)
    {
        /* Base condition */
        cerr << name << " = ";
        print(head);
        cerr << "]\n";
    }
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        cerr << " ||";
        printer(names + i + 1, tail...);
    }
    /* PrinterArr */
    template <typename T>
    void printerArr(const char *name, T arr[], int N)
    {
        /* Printing decayed and runtime arrays */
        cerr << name << " = {";
        for (size_t i = 0; i < N; i++)
            cerr << (i ? "," : ""), print(arr[i]);
        cerr << "}";
        cerr << "]\n";
    }
}
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(arr, n) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#arr, arr, n)
#else
#define debug(...)
#define debugArr(arr, n)
#endif
#endif

#define db(x) cerr<<"\n"<<#x<<": "<<(x)<<"\n";
#define asd cerr<<"\n---------------------------------------\n";
#define WA {cout<<"2+2=5";return 0;}
#define RTE cout<<1/0;
#define TLE while(1);

/// #DEFINEs
#define int long long
#define f first
#define s second
#define lb lower_bound
#define up upper_bound
#define pb push_back
#define pf push_front
#define sz size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
#define rep(i,n) for(int i=0;i<n;i++)
#define lgx(x,b) (log(x)/log(b))
#define lg2(x) 31-__builtin_clz(x)
#define sp " "
#define fl "\n"
#define YN(x) cout<<((x)?("YES"):("NO"))<<fl;
#define Yn(x) cout<<((x)?("Yes"):("No"))<<fl;
#define yn(x) cout<<((x)?("yes"):("no"))<<fl;
#define TEST            \
    int testcases;      \
    cin>>testcases;     \
    while(testcases--)

/// TYPEDEFs
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vi> mat;
typedef vector<bool> vb;

/// CONSTANTS
const int inf=INT_MAX;
const int oo=1e9+5;
const ll OO=(ll)1e18+5;
const ld pi=acos(-1.0);
const int ALPHABET_SIZE=30;
const char dch[4]= {'U','R','D','L'};
const int dr4[4]= {-1,0,1,0};
const int dc4[4]= {0,1,0,-1};
const int dr8[8]= {-1,-1,0,1,1,1,0,-1};
const int dc8[8]= {0,1,1,1,0,-1,-1,-1};
const int drknight[8]= {-2,-1,1,2,2,1,-1,-2};
const int dcknight[8]= {1,2,2,1,-1,-2,-2,-1};

/// FUNCTIONS
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }

vi iota(int n){
    vi a(n);
    return iota(a.begin(),a.end(),0),a;
}

ll rnd(ll l,ll r){
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l,r-1)(gen);
}
ll rnd(ll n){return rnd(0,n);}

int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}

int modpow(int a,int b,int m){
    int res=1;
    while(b){
        if(b&1)res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}

/// CONSTRAINTS
const int maxn=2e5+5;
const int maxlog=log2(maxn)+2;
const int mod=1e9+7;
const ld eps=1e-9;

/// +--------------------------------------+ CODE +--------------------------------------+

void solve(){
    int n;
    cin>>n;
    string s,a,b;
    for(int i=0;i<2*n-2;i++){
        cin>>s;
        if(s.sz==n-1){
            if(a=="")a=s;
            else b=s;
        }
    }
    REV(a);
    YN(a==b)
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
//    freopen(".in","r",stdin);
//    freopen(".out","w",stdout);
    #endif
//    cout.precision(1);
//    cout<<fixed;
//    srand(time(0));

    int testcases=1;
    cin>>testcases;
    while(testcases--){
        solve();
    }
}
