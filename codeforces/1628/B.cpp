// ▄︻┻═┳一⸔Aηkiт⸕

 




#include<bits/stdc++.h>
/* 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
*/
using namespace std;
/*
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
*/
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define int long long
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
// #define endl "\n"
#define pb push_back
#define ppb pop_back
#define mkp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define er cout<<endl; return
#define ec cout<<endl; continue
#define eb cout<<endl; break
void pyes(){cout<<"YES ";}
void pno(){cout<<"NO ";}
void pzero(){cout<<"0 ";}
void pone(){cout<<"1 ";}
void pnegone(){cout<<"-1 ";}
void here(long long n){cout<<"here "<<n<<"\n"; return;}
 
 
#define ld long double
#define pll pair<ll,ll>
// #define lcm(a,b) (a*1LL*(b/__gcd(a,b)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define rep(i,j,k) for(ll i=j;i<=k;i++)
#define rrep(i,j,k) for(ll i=j;i>=k;i--)
 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
typedef pair<int, int> pii;
// typedef pair<long long int, long long int> pall;
typedef vector<int> vi;
typedef vector<long long> vll;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#define debug2(x, y)cerr<<#x<<"="<<x<<", "<<#y<<"="<<y<<endl;
#define debug3(x, y, z)cerr<<#x<<"=" <<x<<", "<<#y<<"="<<y<<", \
"<<#z<<"="<<z<<endl;
#define debug4(a, b, c, d)cerr<<#a<<"="<<a<<", "<<#b<<"="<<b<<", \
"<<#c<<"="<<c<<", "<<#d<<"="<<d<<" "<<endl;
#define debug5(a, b, c, d, e)cerr<<#a<<"="<<a<<", "<<#b<<"="<<b<<", \
"<<#c<<"="<<c<<", "<<#d<<"="<<d<<", "<<#e<< "="<<e<<endl;
#define debug6(a, b, c, d, e, f)cerr<<#a<<"="<<a<<", "<<#b<<"="<<b<<", "<<#c<<"="<< c<<", \
"<<#d<<"="<<d<<", "<<#e<< "="<<e<<", "<<#f<<"="<<f<<endl;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(a, b, c, d)
#define debug5(a, b, c, d, e)
#define debug6(a, b, c, d, e, f)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(multimap <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(multimap <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue <T> v) {cerr << "[ "; int f = 0; while (!v.empty())cerr << (f++ ? ", " : ""), _print(v.front()), v.pop(); cerr << " ]";}
template <class T> void _print(stack <T> v) {cerr << "[ "; int f = 0; while (!v.empty())cerr << (f++ ? ", " : ""), _print(v.front()), v.pop(); cerr << " ]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; int f = 0; while (!v.empty())cerr << (f++ ? ", " : ""), _print(v.front()), v.pop(); cerr << " ]";}
// https://codeforces.com/blog/entry/125435
 
 
template<typename T> void Unique(T &a) {a.erase(unique(a.begin(), a.end()), a.end());}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
 
/* 
template <class T> using oset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <class T> using roset = tree<T, null_type,greater<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
template <class T> void _print(oset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(roset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
*/
 
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll expo(ll a, ll b, ll mod) {a %= mod; ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll inv(ll a, ll b) {return expo(a, b - 2, b);}
ll nCr(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
ll add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mul(a, inv(b, m), m) + m) % m;}  //only for prime m
 
// big prime nos :- 694202137 1000004119 1000001269   1000001969  1000003769  1000004569  1000006967
// use 61 & 1000004119
 
 
 
//-------------------------------------------꧁START꧂------------------------------------------------



void BELLA_CIAO(){
// i confirm
ll n; cin>>n;
vector<string> vs(n); cin>>vs;

map<string,int> mp;
//  rev str, freq

map<string,int> mp23;
//  rev for 2,3 req

rep(i,0,n-1){
    string s = vs[i];
    if(s.size()==1){pyes(); er;}
    mp[s]++;
    string s1 = "";
    if(s.size()==3){
        s1.pb(s[1]); s1.pb(s[2]);
        mp23[s1]++;
        if(s[0]==s[2]){pyes(); er;}
    }
    else{
        if(s[0]==s[1]){pyes(); er;}
    }
}
debug(mp23)
rep(i,0,n-1){
    string s = vs[i]; debug(s)
    mp[s]--;
    if(s.size()==2){
        reverse(all(s));
        if(mp[s]>0 || mp23[s]>0){pyes(); er;}
    }
    else{
        reverse(all(s));
        string s1 = "";
        s1.pb(s[1]); s1.pb(s[0]); debug(s1)
        mp23[s1]--; debug(mp23)
        s1[0]=s[1]; s1[1]=s[2]; debug(s1)
        if(mp[s]>0 || mp[s1]>0){pyes(); er;}
    }
}
cout<<"NO"; er;









// // for 2 size
// // debug(vst[2]); er;
// debug(mp32)
// for(auto &pr : vst[2]){
//     string s = pr.ff; int freq = pr.ss;
//     if(freq>=2){pyes(); er;}
//     reverse(all(s));
//     if(mp32[s]>=1){pyes(); er;}
//     if(mp1[s[0]]>=1 || mp1[s[1]]>=1){pyes(); er;}
// }

// // 3,1+2 check
// for(auto &pr : vst[3]){
//     string s = pr.ff;
//     char c = s[2];
//     string s1 = "";
//     s1.pb(s[1]); s1.pb(s[0]);
//     if(mp1[c]>=1 && vst[2][s1]>=1){cout<<"Yes"; er;}
// }
// pno(); er;




return;
}
//--------------------------------------------꧁END꧂--------------------------------------------------
 
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
fastio();  // interactive    
int t;
t=1;
cin>>t; //                                 /
int _t=t;
int ____test_case____=_t-t+1;


// timelimit();


while(t--){ ____test_case____=_t-t; debug(____test_case____)
// WA ON TESTCASE 2
//  if(____test_case____==926){
// string s; cin>>s;
// ll n; cin>>n;
// vll v(n); cin>>v;
// string s="";
// s+=(to_string(n));
// s.pb('_');
// s.pb('_');
// // s+=(to_string(k));
// // s.pb('_');
// rep(i,0,n-1){
//     s+=(to_string(v[i]));
//     s.pb('_');
// }
// cout<<s<<endl; return 0;

// }
 
   BELLA_CIAO();
}
 
cout<<fixed<<setprecision(10);
cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
 
return 0;
}