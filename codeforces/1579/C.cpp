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

int get_len (int i, int j, vector<string> &arr) {
    int n = sz(arr);
    int m = sz(arr[0]);
    int st = 0;
    int ni = i, nj1 = j, nj2 = j;
    while (ni - 1 >= 0 and nj1 - 1 >= 0 and nj2 + 1 < m and arr[ni-1][nj1-1] == '*' and arr[ni-1][nj2+1] == '*') {
        st++;
        ni--;
        nj1--;
        nj2++;
    }
    return st;
}

void fill_k(int i, int j, vector<string> &arr, vvi &check) {
    int ni = i, nj1 = j, nj2 = j;
    check[ni][nj1] = 1;
    int n = sz(arr);
    int m = sz(arr[0]);
    while (ni - 1 >= 0 and nj1 - 1 >= 0 and nj2 + 1 < m and arr[ni-1][nj1-1] == '*' and arr[ni-1][nj2+1] == '*') {
        ni--;
        nj1--;
        nj2++;
        check[ni][nj1] = 1;
        check[ni][nj2] = 1;
    }
    return;
}

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<string> arr(n);
    forn(i, n) {
        cin >> arr[i];
    }
    vvi check(n, vi(m));
    for (int i = 0; i < n; i++) {
        forn (j, m) {
            if (arr[i][j] == '*') {
                int ln = get_len(i, j, arr);
                if (ln >= k) {
                    fill_k(i, j, arr, check);
                }
            }
        }
    }
    forn (i, n) {
        forn (j, m) {
            if (arr[i][j] == '*' and check[i][j] == 0) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";

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
