#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
#define int                     long long
#define ull                     unsigned long long
#define endl                    "\n"
#define vi                      vector<int>
#define vvi                     vector<vector<int>>
#define vb                      vector<bool>
#define pii                     pair<int,int>
#define vp                      vector<pii>
#define fr(i,a,b)               for(int i = a;i<b;i++)
#define fl(i,a,b)               for(int i = b-1;i>=a;i--)
#define inpt(a)                 fr(i,0,a.size()) cin>>a[i];
#define prints(v)               fr(i,0,v.size()){cout<<v[i]<<" ";}cout<<endl;
#define printp(v)               go(e,v){cout<<e.F<<" "<<e.S<<endl;}
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(),x.end()
#define rall(x)                 x.rbegin(),x.rend()
#define go(a,x)                 for(auto &a:x)
#define yn(a)                   cout<<((a)?"YES\n":"NO\n")
#define ld                      long double 
#define M1                      1000000007
#define M2                      998244353
#define N                       1000000009
#define PI                      3.141592653589793238462
#define inf                     LONG_LONG_MAX
#define yes                     cout<<"YES"<<endl
#define no                      cout<<"NO"<<endl
#define gcd                     __gcd
#define mii                     map<int,int>
#define si                      set<int>
#define madd(a,b,m)             (a%m+b%m)%m
#define msub(a,b,m)             (a%m-b%m+m)%m
#define mmul(a,b,m)             (a%m*b%m)%m
/*****************************************************************************************************************************/
#ifndef ONLINE_JUDGE
    #define dbg(x) cerr<<#x<<" "; _print(x);cerr<<endl; 
    #else
    #define dbg(x)
#endif
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*****************************************************************************************************************************/
bool cmp(pair<int,int> a,pair<int,int> b){if(a.S==b.S){return a.F<b.F;}return a.S<b.S;}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size 3
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
/*****************************************************************************************************************************/
void solve(){
    int n;
    cin >> n;
    
    vi a(n), b(n);
    inpt(a);
    inpt(b);
    
    vi s(n+1,0);
    fr(i,0,n) {
        s[i+1] = s[i]+b[i];
    }
    
    vi d(n);
    vi ans(n);
    fr(i,0,n){
        int j = lower_bound(s.begin()+i,s.end(),a[i]+s[i])-s.begin()-1;
        if(j>i){
            d[i]++;
            if(j<n){
                d[j]--;
            }
        }
        if(j<n){
            ans[j] += a[i]-(s[j]-s[i]);
        }
    }
    
    fr(i,1,n){
        d[i] += d[i-1];
    }
    fr(i,0,n){
        ans[i] += d[i]*b[i];
    }
    prints(ans);
}
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w",stderr);
    #endif
    clock_t time_req=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int _; cin>>_;while(_--) solve();
    #ifndef ONLINE_JUDGE
        cout<<"Time : "<<fixed<<setprecision(6)<<((double)(clock()-time_req))/CLOCKS_PER_SEC;
    #endif
        return 0;
}