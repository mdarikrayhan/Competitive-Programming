#include<bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
#define int long long
#define double long double
#define input(a) for(auto &x:a) cin>>x
#define all(x) x.begin(),x.end()
#define rsort(c) sort(all(c)); reverse(all(c))
#define print(a) for(auto x:a) cout<<x<<" "; cout<<endl
#define print1(a) for(auto x:a) cout<<x.first<<" "<<x.second<<endl 
#define printall(a) for(auto x:a){print(x);} cout<<endl
#define fil(ar,val) memset(ar,val,szof(ar))
#define mpp make_pair
#define pb push_back
#define fi first
#define se second
// const int MOD=998244353;
const int MOD=1e9+7;
 
typedef vector<int>vi;
typedef vector<vector<int>>vvi;
typedef pair<int,int>pi;
typedef vector<pair<int,int>> vpi;
typedef vector<bool>vb;
typedef pair<int, int> pi;
 
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
 
// typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;
// order_of_key: The number of items in a set that are strictly smaller than k

struct mi {
    int v; explicit operator int() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) { 
    if ((a.v += b.v) >= MOD) a.v -= MOD; 
    return a;
}
mi& operator-=(mi& a, mi b) { 
    if ((a.v -= b.v) < 0) a.v += MOD; 
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long) a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) { assert(a.v != 0); return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }
bool operator==(mi a, int b){ return a.v == b; }
ostream& operator<<(ostream& os, const mi& val){ os << (int) val; return os; }
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else 
#define debug(x)
#endif
 
void _print(int a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr<<a;}
void _print(pair<int,int>a){cerr<<'['<<a.first<<" "<<a.second<<']';}
 
template<class T> void _print(vector<T> v1){
    cerr<<"[ ";
    for(T i:v1){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}
 
template<class T> void _print(set<T> s){
    cerr<<"[ ";
    for(T i:s){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}

template<class T> void _print(multiset<T> s){
    cerr<<"[ ";
    for(T i:s){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}
 
int digitsum(int n){int ret=0;while(n){ret+=n%10;n/=10;}return ret;}
 
int power(int x,int n){
    if(n==0)    return 1;
    int a=power(x,n/2);
    if(n%2==0)  return (a*a);
    else    return (a*(a*x));
}
 
int isPerfectSquare(int x) {
    int s = (int) sqrtl(x);
    while (s * s < x) s++;
    while (s * s > x) s--;
    return s*s==x;
}
 
int binpow(int base, int expo){
    int res=1;
 
    while(expo){
        if(expo%2==0){
            expo=expo/2;
            base=(base*base)%MOD;
        }
 
        else{
            expo--;
            res=(res*base)%MOD;
        }
    }
 
    return res%MOD;
}
 
int inv(int x){
    return binpow(x,MOD-2)%MOD;
}

void solve(){
    int n;
    cin>>n;

    vi l(n);
    vi r(n);

    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }

    sort(all(l));
    sort(all(r));

    int ans=0;
    for(int i=n-1;i>=0;i--){
        ans+=max(l[i],r[i]);
    }

    cout<<ans+n<<"\n";
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    t=1;

    while(t--){
        solve();
    }
    return 0;
}