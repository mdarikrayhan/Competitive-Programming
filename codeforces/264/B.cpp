#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvl;
#define all(x) (x).begin(), (x).end()
#define vi vector<int> 
#define vll vector<long long>
typedef long double lld;
 
int mod = 998244353;
int mod1 = 1e9 +7;
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
 
void print(vector <int> v){int s=v.size();for (int i=0;i<s;i++){cout<<v[i]<<' ';}cout<<"\n";}
 
void map_p(map<int,int>m){for(const auto& pair : m) {int key=pair.first;int value=pair.second;
        cout<<key<<":"<<value<<' ';}cout<<endl;}
 
vector <int> pre_sum(vector<int>v){vector <int>ans={};for (int i=0;i<v.size();i++)
    {if (i==0){ans.push_back(v[0]);}
    else {ans.push_back(ans[i-1] + v[i]);}}return ans;}
 
vector<int> suf_sum(vector<int>v){int cnt=-2; vector<int>ans={};
    for (int i=v.size()-1;i>=0;i--){cnt++;
        if (i== v.size()-1){ans.push_back(v[i]);}else{ans.push_back(v[i]+ans[cnt]);}}return ans;}
 
ll nc2(int n){return n*(n-1)/2;}
int nCr(int n, int r) {
    if (r > n) return 0;if (r == 0 || n == r) return 1;double res = 0;
    for (int i = 0; i < r; i++) {res += log(n-i) - log(i+1);}return (int)round(exp(res));}
 
int fibonacci(int n){
    int a=0,b=1,c,i;if(n==0){return a;}for (i=2;i<=n;i++){c=a+b;a=b;b=c;}return b;}
 
bool isPerfectSquare(ll n){return sqrtl(n)== (ll)sqrtl(n);}
 
vector<int> solve_quad(int a,int b, int c){
    vector<int>ans; vector<int>temp={};
    ll d=b*b; ll e= 4*a*c;
    if (isPerfectSquare((ll) d-e)){
        ans.pb((-b + (ll)sqrtl(d-e))/2);
        ans.pb((-b - (ll)sqrtl(d-e))/2);
    }
    if (ans[0]+ans[1] == -b/a && ans[0]*ans[1]==c/a){return ans;}
    else {return temp;}
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

bool is_prime(int n){for (int i=2;i*i<=n;i++){if (n%i ==0 ) return false;}return true;}
 
vi sieve(int lim) {
    vector<int> pr;
    vector<bool> isPrime(lim + 1, true);
    for (int p = 2; p * p <= lim; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= lim; i += p)
                isPrime[i] = false;
        }
    }
    for (int p = 2; p <= lim; ++p) {
        if (isPrime[p])
            pr.pb(p);
    } return pr;
}
 
int gcd(int a, int b) {while (b != 0) {int temp = b;b = a % b;a = temp;}return a;}
int vectorGCD(vector<ll> ms) {
    int rs = ms[0];for (int i = 1; i < ms.size(); ++i) {rs = gcd(rs, ms[i]);}return rs;}
 
void get(vector<int>&v,int n){for (int i=0;i<n;i++){if (v.size()==i){int a; cin>>a; v.pb(a);}else{cin>>v[i];}}}
 
//****************************************************************************************************************//
 
string to_binary(int n,int len){string binary;for (unsigned i=(1 << len-1);i>0;i=i/2){
        binary += (n & i) ? "1" : "0";}return binary;}
 
int bits_count(int a){int n=a;int cnt=0;
    while (n!=0){n=(n>>1);cnt++;}return cnt;}
 
int flipped (int n, int k){return (n ^ (1 << (k-1)));}  // 1 indexed from right
 
//****************************************************************************************************************//
 
#define debug(x) cout << #x <<" "; _print(x); cout << endl;            // comment this line before submitting
//#define debug(a)                                                    // uncomment this before submitting
 
template <typename T>
void _print(T t) {cout << t;}
 
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(vector <T> v);
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(set <T> v);
template <class T> void _print(vector<vector<T>> v);
 
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(vector<vector<T>> v){cout<<"[ ";for(const auto &iv:v) {_print(iv);cout << " ";}cout << "]";}
//****************************************************************************************************************//



int main() {

    int lim = 100005;
    vector<int>small_div(lim);
    for (int i=1;i<lim;i++){
        small_div[i] = i;
    }
    small_div[1] = 1;
    for (int i=2;i*i<=lim;i++){
        for (int j=i;j<lim;j+=i){
            if (small_div[j]==j) small_div[j] = i;
        }
    }
    vi primes = sieve(lim-1);
    vvi prime_fac(lim);
    for (int p:primes){
        for (int i=p;i<=lim-1;i+=p){
            prime_fac[i].pb(p);
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; //cin>>t;

    while (t--){
        int n; cin>>n;
        vi v; get(v,n);
    
        vi dp(n+1);
        dp[0] = 1;
        map<int,int>m;
        m[small_div[v[0]]] = 1;
        for (int pf:prime_fac[v[0]]){
            m[pf] = 1;
        }
        for (int i=1;i<n;i++){
            bool x = false;
            for (int pf: prime_fac[v[i]]){
                if (m[pf]>0) x = true;
            }
            if (x) {
                int mx=0;
                for (int pf:prime_fac[v[i]]){
                    mx = max(mx,m[pf]);
                    
                }
                dp[i] = mx+1;
                for (int pf:prime_fac[v[i]]){
                    m[pf] = dp[i];
                    
                }
            }
            else {
                dp[i] = 1;
                for (int pf:prime_fac[v[i]]){
                    m[pf] = 1;
                }
            }
        }
        int ret = 0;
        for (int i=0;i<n;i++){
            ret = max(ret, dp[i]);
        }
        cout<<ret<<endl;
    }
}







// Solution (fut ref)
