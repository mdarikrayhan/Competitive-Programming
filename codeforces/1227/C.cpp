#include <iostream>
#include <vector>
#include <chrono>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <iomanip>
using namespace std;
using namespace chrono;

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
#else
#define debug(x...)
#endif

typedef long long ll;
#define int long long
#define mod 1000000007
#define mod2 998244353
#define INF 2000000000000000000
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pi pair<int,int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define forn(i, n) for(int i=0;i<n;i++)
#define all(x) begin(x), end(x)
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define gcd(x, y) __gcd(x, y)
#define setbits(x) __builtin_popcountll(x)
#define f first
#define s second

int power(int a, int x, int m){
    a=a%m;
    int ans=1;
    while(x){
        if(x&1)ans=(ans*a)%m;
        x=x>>1;
        a=(a*a)%m;
    }
    return ans;
}

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string tar;
    for (int i = 0; i < n/2; i++) {
        tar += "()";
    }
    bool ok = true;
    vi blocks;
    int score = 0;
    int len = 0;
    vpi ops;
    for (int i = 0; i < n; i++) {
        if (s[i] != tar[i]) {
            int j = i+1;
            while (s[j] != tar[i]) j++;
            ops.push_back({i, j});
            reverse(s.begin()+i, s.begin()+j+1);
        }
    }
    int xd = n/2;
    int a = 1, b = 2;
    while (xd > k) {
        ops.push_back({a, b});
        a = b+1;
        b = a+1;
        xd--;
    }
    cout << sz(ops) << "\n";
    for (auto &x: ops) {
        cout << x.f+1 << " " << x.s+1 << "\n";
    }
}

void precompute(){
    // Precomputation can be done here

}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin.tie(0),cout.tie(0);
    ios_base::sync_with_stdio(false);

    int t=1;
    cin>>t;
    precompute();
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}
