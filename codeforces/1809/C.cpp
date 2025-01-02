#include <bits/stdc++.h>
using namespace std;
#define Buildup() ios::sync_with_stdio(false),cin.tie(nullptr)

#define make_unique(x) (x).resize(unique(all((x)))-(x).begin())
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define ceil(x,y) (x+y-1)/(y)
#define sz(x) (int)(x).size()
#define PI 3.141592653589793238 
#define ld long double
#define ull unsigned long long
#define ll long long
#define nl '\n'
#define ff first
#define ss second
#define IM INT_MAX
#define IN INT_MIN
#define LN LLONG_MIN
#define LM LLONG_MAX
#define pb push_back
#define pp pop_back
#define ins insert
#define lb lower_bound
#define ub upper_bound

#define Nl '\n'
#define itn int

// const int M = 998244353;
// const int M = 1e9+7;
// const int N = 2e5+5;
// const int N = 1e6+5;
 
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << #x << " : ["; _print(x)
#else
#define dbg(x...)
#endif

void __print(int x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(ull x) {cerr << x;}
void __print(ld x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.ff); cerr << ','; __print(x.ss); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i);}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}


/* .....!! Start by doing what's necessary; then do what's possible;
                            and suddenly you are doing impossible !!..... */

int main(){
    #ifndef ONLINE_JUDGE
        freopen("errorf.in", "w", stderr);
    #endif
 
    Buildup();
 
        int __ = 1;
        cin >> __;

        while(__--){

            itn n,k;
            cin>>n>>k;

            vector<itn> ans(n,-1000);
            for(int i=1; i<=n; i++){
                if(i*(i+1)>2*k){
                    k -= i*(i-1)/2;
                    ans[i-1] = (k<<1)-((i<<1)-1);
                    break;
                }
                ans[i-1] = 2;
            }

            for(int i=0; i<n; i++){
                cout<<ans[i]<<" \n"[i==n-1];
            }

        }

}