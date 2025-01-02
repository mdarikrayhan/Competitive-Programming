#include <bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
// template<class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// template<class T>
// using ordered_multiset = tree<pair<T, T>, null_type, less<pair<T, T>>, rb_tree_tag, tree_order_statistics_node_update>;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int  long long
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
//void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <typename T1, typename T2>std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) { return out << '(' << pair.first << ", " << pair.second << ')';}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m


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
// Now, we can simply define our unordered_map
// or our gp_hash_table as follows:

//=============================Calculation of nCr==============================================================================================================================//

ll combination(ll n, ll r) {
    if(r==0)
        return 1;
    else {
        ll num = n * combination(n - 1, r - 1);
        return num/r;
    }
}
//============================================================================================================================================================================//

//=============================Binary Exponentiation==========================================================================================================================//
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
//============================================================================================================================================================================//

//===============================Printing Stuff==============================================================================================================================//
#define prt(x) for(auto y:x) cout<<y<<" "; cout<<endl;
#define prp(x) for(auto i:x) cout<<i.first<<" "<<i.second<<endl;
#define py cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define pry cout<<"yes"<<endl;
#define prn cout<<"no"<<endl;
#define pm cout<<-1<<endl;
#define pz cout<<0<<endl;
//============================================================================================================================================================================//

// unordered_map<long long, int, custom_hash> mp;
const int N=2e5+5;



void solve(ll tests,ll test){
     ll n; cin>>n;
     string s;cin>>s;
     ll plus=0,minus=0;
     rep(i,0,n)if(s[i]=='+') plus++;
     else minus++;

     ll q; cin>>q;
     rep(i,0,q){
        ll a,b; cin>>a>>b;
        ll num1=min(a,b)*max(plus,minus);
        ll num2=max(a,b)*min(plus,minus);
        ll diff=num2-num1;
        if(plus==minus){py continue;}
        else{
            if(min(a,b)*max(plus,minus)==max(a,b)*min(plus,minus)){py}
            else if(diff>0 && (diff%(abs(a-b))==0)) {py}
                else {pn}
            
        }
     }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    // cout<<setprecision(9);
    // cout<<fixed;
    
    int tests = 1;
    //cin >> tests;
    for(int t = 1; t <= tests; t++) solve(tests, t);
    return 0;

}
